/*!
 * \file	Classes\interactive\assets\layer\LayerMap.cpp
 *
 * \brief	������ LayerMap
 */

#pragma execution_character_set("utf-8")

#include "interactive/assets/layer/LayerMap.h"

#include "interactive/manager/SizeDefine.h"

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
				BridgeInstance->pushMessage2Logic(InteractiveMessagePQ::InteractiveMessageID_OP_DragMap_Right);
			}
			else if (delta.x < 0)
			{
				// left
				BridgeInstance->pushMessage2Logic(InteractiveMessagePQ::InteractiveMessageID_OP_DragMap_Left);
			}
		}
		else
		{
			if (delta.y > 0)
			{
				// up
				BridgeInstance->pushMessage2Logic(InteractiveMessagePQ::InteractiveMessageID_OP_DragMap_Up);
			}
			else if (delta.y < 0)
			{
				// down
				BridgeInstance->pushMessage2Logic(InteractiveMessagePQ::InteractiveMessageID_OP_DragMap_Down);
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
	// TODO �ļ�·��
	switch (nodeType)
	{
	case MapNode::NodeType_None:
	case MapNode::NodeType_None_Const:
		return nullptr;
		break;
	case MapNode::NodeType_Road:
	case MapNode::NodeType_Road_Const:
		return Sprite::createWithSpriteFrameName("map_cell/map_cell_road_64.png");
		break;
	case MapNode::NodeType_Wall:
	case MapNode::NodeType_Wall_Const:
		return Sprite::createWithSpriteFrameName("map_cell/map_cell_wall_64.png");
		break;
	case MapNode::NodeType_Border_Const:
		return Sprite::createWithSpriteFrameName("map_cell/map_cell_fence_64.png");
		break;
	default:
		return nullptr;
		break;
	}
}

Sprite* LayerMap::createExtraByExtraType(MapNode::ExtraType extraType)
{
	// TODO �ļ�·��
	switch (extraType)
	{
	case MapNode::ExtraType_None:
		return nullptr;
		break;
	case MapNode::ExtraType_Door_Mission_Main:
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

	auto mapSize = MapControllerInstance->getMapSize();
	auto map = MapControllerInstance->getMapNodeSet();
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
	auto origin = MapControllerInstance->getViewOrigin();
	auto mVO = getMapViewOrigin();
	this->setPosition(Vec2(
		mVO.x - origin.x * MAPCELL_SIZE,
		mVO.y + origin.y * MAPCELL_SIZE
		));
}

const ArKCa::Vector2<float> LayerMap::getMapViewOrigin()const
{
	// TODO ���Ż����㣬�˴�Ӧ��ʵ����Ļ��Ȳ��� MAPCELL_SIZE �����������������ͼ��ĺ���ƫ������ʹ��ͼ������Ļ����
	return ArKCa::Vector2<float>(
		TargetInfoInstance->getScreenLeftTopOrigin().x + (
		TargetInfoInstance->getScreenSize().width -
		MapControllerInstance->getViewSize().width * MAPCELL_SIZE
		) / 2.0,
		TargetInfoInstance->getScreenLeftTopOrigin().y
		);
}

const ArKCa::Size<float> LayerMap::getMapViewSize()const
{
	return ArKCa::Size<float>(
		MapControllerInstance->getViewSize().width * MAPCELL_SIZE,
		MapControllerInstance->getViewSize().height * MAPCELL_SIZE
		);
}