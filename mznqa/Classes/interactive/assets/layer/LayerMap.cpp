/*!
 * \file	Classes\interactive\assets\layer\LayerMap.cpp
 *
 * \brief	定义类 LayerMap
 */

#pragma execution_character_set("utf-8")

#include "interactive/assets/layer/LayerMap.h"

#include "interactive/manager/SizeDefine.h"
#include "helper/bridge/Bridge.h"

USING_NS_CC;

bool LayerMap::init()
{
	if (!Layer::init())
	{
		return false;
	}

	updateGlobalMapPosition();

	addGlobalEventListener();

	return true;
}

bool LayerMap::onTouchBegan(Touch *touch, Event *unused_event)
{
	cocos2d::log("[warning] LayerMap::onTouchBegan()");
	touchPoint = touch->getLocation();
	return true;
}

void LayerMap::onTouchMoved(Touch *touch, Event *unused_event)
{
	cocos2d::log("[warning] LayerMap::onTouchMoved()");

	Vec2 delta = touch->getLocation() - touchPoint;
	if (abs(delta.x) < MAPCELL_SIZE && abs(delta.y) < MAPCELL_SIZE)
		return;
	else
	{
		if (abs(delta.x) > abs(delta.y))
		{
			if (delta.x > 0)
			{
				// right
				Bridge::Instance()->pushMessage2Logic(InteractiveMessagePQ::InteractiveMessageID_OP_DragMap_Right);
			}
			else if (delta.x < 0)
			{
				// left
				Bridge::Instance()->pushMessage2Logic(InteractiveMessagePQ::InteractiveMessageID_OP_DragMap_Left);
			}
		}
		else
		{
			if (delta.y > 0)
			{
				// up
				Bridge::Instance()->pushMessage2Logic(InteractiveMessagePQ::InteractiveMessageID_OP_DragMap_Up);
			}
			else if (delta.y < 0)
			{
				// down
				Bridge::Instance()->pushMessage2Logic(InteractiveMessagePQ::InteractiveMessageID_OP_DragMap_Down);
			}
		}
		touchPoint = touch->getLocation();
	}
}

void LayerMap::onTouchEnded(Touch *touch, Event *unused_event)
{
	cocos2d::log("[warning] LayerMap::onTouchEnded()");
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

Sprite* LayerMap::createMapNodeByNodeType(MapNode::NodeType nodeType)
{
	switch (nodeType)
	{
	case MapNode::NodeType_None:
	case MapNode::NodeType_None_Const:
		return nullptr;
		break;
	case MapNode::NodeType_Road:
	case MapNode::NodeType_Road_Const:
		// TODO 待规整的文件路径
		return Sprite::createWithSpriteFrameName("map_cell/map_cell_road_64.png");
		break;
	case MapNode::NodeType_Wall:
	case MapNode::NodeType_Wall_Const:
		// TODO 待规整的文件路径
		return Sprite::createWithSpriteFrameName("map_cell/map_cell_wall_64.png");
		break;
	case MapNode::NodeType_Border_Const:
		// TODO 待规整的文件路径
		return Sprite::createWithSpriteFrameName("map_cell/map_cell_fence_64.png");
		break;
	default:
		return nullptr;
		break;
	}
}

Sprite* LayerMap::createExtraByExtraType(MapNode::ExtraType extraType)
{
	switch (extraType)
	{
	case MapNode::ExtraType_None:
		return nullptr;
		break;
	case MapNode::ExtraType_Door_Mission_Main:
		// TODO 待规整的文件路径
		return Sprite::createWithSpriteFrameName("map_cell/map_cell_door_64.png");
		break;
	case MapNode::ExtraType_Door_Mission_Secondary:
		return nullptr;
		break;
	case MapNode::ExtraType_Door_NextMap:
		return nullptr;
		break;
	default:
		return nullptr;
		break;
	}
}

void LayerMap::loadMap()
{
	removeChildByTag(mapNodeFlag);
	mapNodeSet.clear();

	removeChildByTag(extarFlag);
	extraSet.clear();

	auto mapSize = MapController::Instance()->getMapSize();
	auto map = MapController::Instance()->getMapNodeSet();
	for (int y = 0; y < mapSize.height; ++y)
	{
		mapNodeSet.push_back(std::vector<Sprite*>(mapSize.width, nullptr));
		extraSet.push_back(std::vector<Sprite*>(mapSize.width, nullptr));
	}

	for (int y = 0; y < mapSize.height; ++y)
		for (int x = 0; x < mapSize.width; ++x)
		{
			mapNodeSet[y][x] = createMapNodeByNodeType(map[y][x].nodeType);
			if (mapNodeSet[y][x] != nullptr)
			{
				mapNodeSet[y][x]->setAnchorPoint(Vec2(0, 1));
				mapNodeSet[y][x]->setPosition(Vec2(x*MAPCELL_SIZE, -y*MAPCELL_SIZE));
				addChild(mapNodeSet[y][x], mapNodeZOrder, mapNodeFlag);
			}

			extraSet[y][x] = createExtraByExtraType(map[y][x].extraType);
			if (extraSet[y][x] != nullptr)
			{
				extraSet[y][x]->setAnchorPoint(Vec2(0, 1));
				extraSet[y][x]->setPosition(Vec2(x*MAPCELL_SIZE, -y*MAPCELL_SIZE));
				addChild(extraSet[y][x], extraZOrder, extarFlag);
			}
		}
}

void LayerMap::updateGlobalMapPosition()
{
	auto origin = MapController::Instance()->getViewOrigin();
	auto mVO = getMapViewOrigin();
	this->setPosition(Vec2(
		mVO.x - origin.x * MAPCELL_SIZE,
		mVO.y + origin.y * MAPCELL_SIZE
		));
}

const ArKCa::Vector2<float> LayerMap::getMapViewOrigin()const
{
	// TODO 待优化计算，此处应对实际屏幕宽度不是 MAPCELL_SIZE 的整数倍，而计算地图层的横向偏移量以使地图处于屏幕中心
	return ArKCa::Vector2<float>(
		TargetInfo::Instance()->getScreenLeftTopOrigin().x + (
		TargetInfo::Instance()->getScreenSize().width -
		MapController::Instance()->getViewSize().width * MAPCELL_SIZE
		) / 2.0,
		TargetInfo::Instance()->getScreenLeftTopOrigin().y
		);
}

const ArKCa::Size<float> LayerMap::getMapViewSize()const
{
	return ArKCa::Size<float>(
		MapController::Instance()->getViewSize().width * MAPCELL_SIZE,
		MapController::Instance()->getViewSize().height * MAPCELL_SIZE
		);
}