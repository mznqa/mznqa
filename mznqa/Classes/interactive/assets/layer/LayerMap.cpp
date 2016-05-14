/*!
 * \file	Classes\interactive\assets\layer\LayerMap.cpp
 *
 * \brief	定义类 LayerMap
 */

#pragma execution_character_set("utf-8")

#include "interactive/assets/layer/LayerMap.h"

USING_NS_CC;

bool LayerMap::init()
{
	if (!Layer::init())
	{
		return false;
	}

	this->setPosition(Vec2(
		TargetInfoInstance->getScreenLeftTopOrigin().x,
		TargetInfoInstance->getScreenLeftTopOrigin().y
		));

	return true;
}

Sprite* LayerMap::createMapNodeByNodeType(MapNode::NodeType nodeType)
{
	// TODO 文件路径
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
	// TODO 文件路径
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
				// TODO 魔数
				mapNodeSet[y][x]->setPosition(Vec2(x*64.0, -y*64.0));
				addChild(mapNodeSet[y][x], mapNodeZOrder, mapNodeFlag);
			}

			extraSet[y][x] = createExtraByExtraType(map[y][x].extraType);
			if (extraSet[y][x] != nullptr)
			{
				extraSet[y][x]->setAnchorPoint(Vec2(0, 1));
				// TODO 魔数
				extraSet[y][x]->setPosition(Vec2(x*64.0, -y*64.0));
				addChild(extraSet[y][x], extraZOrder, extarFlag);
			}
		}
}