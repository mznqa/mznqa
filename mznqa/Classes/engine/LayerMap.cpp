/*!
 * \file	Classes\engine\LayerMap.cpp
 *
 * \brief	¶¨ÒåÀà LayerMap
 */

#pragma execution_character_set("utf-8")

#include "engine/LayerMap.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "filePath/SceneFilePath.h"
#include "map/MapController.h"
#include "map/MapNode.h"
#include "message/EngineMessagePQ.h"
#include "engine/GlobalFun.h"
#include "filePath/SpriteFilePath.h"

USING_NS_CC;
using namespace cocostudio::timeline;

bool LayerMap::init()
{
	if (!Layer::init())
	{
		return false;
	}

	loadMapFromMapController();

	addGlobalEventListener();

	return true;
}

bool LayerMap::onTouchBegan(Touch *touch, Event *unused_event)
{
	cocos2d::log("[warning] LayerMap::onTouchBegan()");
	return true;
}

void LayerMap::onTouchMoved(Touch *touch, Event *unused_event)
{
	cocos2d::log("[warning] LayerMap::onTouchMoved()");
}

void LayerMap::onTouchEnded(Touch *touch, Event *unused_event)
{
	cocos2d::log("[warning] LayerMap::onTouchEnded()");
	Vec2 delta = touch->getLocation() - mapViewCenterPoint;

	if (abs(delta.x) > abs(delta.y))
	{
		if (delta.x > 0)
		{
			EngineMessagePQ::Instance()->pushMessage(Message<EngineMessagePQ::EMessage>(EngineMessagePQ::EMessage_MapMoveRight));
		}
		else if (delta.x < 0)
		{
			EngineMessagePQ::Instance()->pushMessage(Message<EngineMessagePQ::EMessage>(EngineMessagePQ::EMessage_MapMoveLeft));
		}
	}
	else
	{
		if (delta.y > 0)
		{
			EngineMessagePQ::Instance()->pushMessage(Message<EngineMessagePQ::EMessage>(EngineMessagePQ::EMessage_MapMoveUp));
		}
		else if (delta.y < 0)
		{
			EngineMessagePQ::Instance()->pushMessage(Message<EngineMessagePQ::EMessage>(EngineMessagePQ::EMessage_MapMoveDown));
		}
	}
}

void LayerMap::addGlobalEventListener()
{
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(LayerMap::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(LayerMap::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(LayerMap::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void LayerMap::loadMapFromMapController()
{
	mapCellSet.clear();
	mapCellSet = std::vector<std::vector<cocos2d::Sprite*>>(MapController::mapNodecountVertical, std::vector<cocos2d::Sprite*>(MapController::mapNodecountHorizontal, nullptr));

	auto it1 = mapCellSet.begin();
	auto itEnd1 = mapCellSet.end();
	int y = 0;
	while (it1 != itEnd1)
	{
		auto it2 = it1->begin();
		auto itEnd2 = it1->end();
		int x = 0;
		while (it2 != itEnd2)
		{
			MapNode::NodeType nt = MapController::Instance()->getMapNodeSet().at(y).at(x).nodeType;
			if (nt == MapNode::NodeType_None)
				*it2 = Sprite::createWithSpriteFrameName(FILE_PATH_MAP_CELL_NONE);
			else if (nt == MapNode::NodeType_Wall)
				*it2 = Sprite::createWithSpriteFrameName(FILE_PATH_MAP_CELL_WALL);
			else if (nt == MapNode::NodeType_Road)
				*it2 = Sprite::createWithSpriteFrameName(FILE_PATH_MAP_CELL_ROAD);
			else if (nt == MapNode::NodeType_Door)
				*it2 = Sprite::createWithSpriteFrameName(FILE_PATH_MAP_CELL_DOOR);
			else if (nt == MapNode::NodeType_Fence)
				*it2 = Sprite::createWithSpriteFrameName(FILE_PATH_MAP_CELL_FENCE);

			(*it2)->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
			(*it2)->setPosition(Vec2(x*MAP_CELL_SIZE, -y*MAP_CELL_SIZE));

			addChild(*it2);
			++it2;
			++x;
		}
		++it1;
		++y;
	}
}

void LayerMap::refreshPosition()
{
	this->stopActionsByFlags(ActionFlags_LayerMove);
	auto action = MoveTo::create(
		TIME_GLOBALMAP_MOVE,
		Vec2(
		gX2CartesianX(0),
		gY2CartesianY(0)
		)
		);
	action->setFlags(ActionFlags_LayerMove);
	this->runAction(action);
}

void LayerMap::initialize()
{
	this->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
	this->setPosition(Vec2(gX2CartesianX(0), gY2CartesianY(0)));
}