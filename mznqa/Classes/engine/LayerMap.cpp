#pragma execution_character_set("utf-8")

#include "engine/LayerMap.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "filePath/SceneFilePath.h"

#include "map/MapController.h"
#include "staticData/MissionMapSet.h"

USING_NS_CC;
using namespace cocostudio::timeline;

const float LayerMap::mapCellSize = 64.0;
const float LayerMap::mapGroupSize = 192.0;

const float LayerMap::globalMoveDuration = 1.0;

bool LayerMap::init()
{
	if (!Layer::init())
	{
		return false;
	}

	MapController::Instance()->setEmptyMap();
	MapController::Instance()->loadMapNode(MissionMapSet::Instance()->getMainMissionMapByIndex(0));

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
			(*it2)->setPosition(Vec2(x*mapCellSize, -y*mapCellSize));

			addChild(*it2);
			++it2;
			++x;
		}
		++it1;
		++y;
	}

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(LayerMap::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(LayerMap::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(LayerMap::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

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
	//Vec2 delta = touch->getDelta();

	//this->setPosition(Vec2(
	//	this->getPosition().x + delta.x,
	//	this->getPosition().y + delta.y
	//	));
}

void LayerMap::onTouchEnded(Touch *touch, Event *unused_event)
{
	cocos2d::log("[warning] LayerMap::onTouchEnded()");
	Vec2 delta = touch->getLocation() - mapGlobalCenterPoint;

	cocos2d::log("delta:%f,%f", delta.x, delta.y);

	float speed = 1.0;

	if ((abs(delta.x) - abs(delta.y)) < mapCellSize || abs(delta.x) > abs(delta.y))
	{
		if (delta.x > 0)
		{
			//moveRight();
			moveLeft();
			//speed = 1.0 - delta.x / (1920.0 / 2.0);
		}
		else if (delta.x < 0)
		{
			//moveLeft();
			moveRight();
			//speed = 1.0 - (-delta.x) / (1920.0 / 2.0);
		}
	}
	if ((abs(delta.x) - abs(delta.y)) < mapCellSize || abs(delta.x) < abs(delta.y))
	{
		if (delta.y > 0)
		{
			//moveUp();
			moveDown();
			//speed = 1.0 - delta.y / (1080.0 / 2.0);
		}
		else if (delta.y < 0)
		{
			//moveDown();
			moveUp();
			//speed = 1.0 - (-delta.y) / (1080.0 / 2.0);
		}
	}
	speed = 0.3;
	speed = (speed >= 1.0 || speed <= 0.0) ? (1.0) : (speed);
	this->stopActionsByFlags(1);
	auto ac = MoveTo::create(globalMoveDuration*speed, Vec2(0.0 - leftTopGX*mapCellSize, 1080.0 + leftTopGY*mapCellSize));
	ac->setFlags(1);
	this->runAction(ac);
}

bool LayerMap::judgeMoveUp()
{
	return !(leftTopGY + 3 >= MapController::mapNodecountVertical);
}

bool LayerMap::judgeMoveDown()
{
	return !(leftTopGY - 3 < 0);
}

bool LayerMap::judgeMoveLeft()
{
	return !(leftTopGX + 3 >= MapController::mapNodecountHorizontal);
}

bool LayerMap::judgeMoveRight()
{
	return !(leftTopGX - 3 < 0);
}

void LayerMap::moveUp()
{
	if (judgeMoveUp() == false)
		return;

	leftTopGY += 3;

	//this->stopActionsByFlags(1);
	//auto ac = MoveTo::create(globalMoveDuration*speed, Vec2(0.0 - leftTopGX*mapCellSize, 1080.0 + leftTopGY*mapCellSize));
	//ac->setFlags(1);
	//this->runAction(ac);
}

void LayerMap::moveDown()
{
	if (judgeMoveDown() == false)
		return;

	leftTopGY -= 3;

	//this->stopActionsByFlags(1);
	//auto ac = MoveTo::create(globalMoveDuration*speed, Vec2(0.0 - leftTopGX*mapCellSize, 1080.0 + leftTopGY*mapCellSize));
	//ac->setFlags(1);
	//this->runAction(ac);
}

void LayerMap::moveLeft()
{
	if (judgeMoveLeft() == false)
		return;

	leftTopGX += 3;

	//this->stopActionsByFlags(1);
	//auto ac = MoveTo::create(globalMoveDuration*speed, Vec2(0.0 - leftTopGX*mapCellSize, 1080.0 + leftTopGY*mapCellSize));
	//ac->setFlags(1);
	//this->runAction(ac);
}

void LayerMap::moveRight()
{
	if (judgeMoveRight() == false)
		return;

	leftTopGX -= 3;

	//this->stopActionsByFlags(1);
	//auto ac = MoveTo::create(globalMoveDuration*speed, Vec2(0.0 - leftTopGX*mapCellSize, 1080.0 + leftTopGY*mapCellSize));
	//ac->setFlags(1);
	//this->runAction(ac);
}