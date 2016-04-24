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
			EngineMessagePQ::Instance()->pushMessage(Message<EngineMessagePQ::EMessage>(EngineMessagePQ::Instance()->EMessage_MapMoveLeft));
		}
		else if (delta.x < 0)
		{
			EngineMessagePQ::Instance()->pushMessage(Message<EngineMessagePQ::EMessage>(EngineMessagePQ::Instance()->EMessage_MapMoveRight));
		}
	}
	else
	{
		if (delta.y > 0)
		{
			EngineMessagePQ::Instance()->pushMessage(Message<EngineMessagePQ::EMessage>(EngineMessagePQ::Instance()->EMessage_MapMoveDown));
		}
		else if (delta.y < 0)
		{
			EngineMessagePQ::Instance()->pushMessage(Message<EngineMessagePQ::EMessage>(EngineMessagePQ::Instance()->EMessage_MapMoveUp));
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
				*it2 = Sprite::create("test_map_cell/map_cell_none_64.png");
			else if (nt == MapNode::NodeType_Wall)
				*it2 = Sprite::create("test_map_cell/map_cell_wall_64.png");
			else if (nt == MapNode::NodeType_Road)
				*it2 = Sprite::create("test_map_cell/map_cell_road_64.png");
			else if (nt == MapNode::NodeType_Door)
				*it2 = Sprite::create("test_map_cell/map_cell_door_64.png");
			else if (nt == MapNode::NodeType_Fence)
				*it2 = Sprite::create("test_map_cell/map_cell_fence_64.png");

			(*it2)->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
			(*it2)->setPosition(Vec2(gX2CartesianX(x), gY2CartesianY(y)));

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
		-MapView::Instance()->getLeftTopGX()*MAP_CELL_SIZE,
		MapView::Instance()->getLeftTopGY()*MAP_CELL_SIZE
		)
		);
	action->setFlags(ActionFlags_LayerMove);
	this->runAction(action);
}