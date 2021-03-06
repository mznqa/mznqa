/*!
 * \file	Classes\logic\controller\MapController.cpp
 *
 * \brief	������ MapController
 */

#pragma execution_character_set("utf-8")

#include "logic/controller/MapController.h"

MapController* MapController::Instance()
{
	static MapController instance;
	return &instance;
}

void MapController::build(MissionMapSet::MissionMapIDMain id)
{
	auto missionMap = MissionMapSet::Instance()->getMapMain(id);

	if (missionMap == nullptr)
		return;

	gameMap.clear();

	ArKCa::Size<int> mapSize(64, 48);
	std::vector<std::vector<MapNode>> mapNodeSet;
	for (int y = 0; y < mapSize.height; ++y)
		mapNodeSet.push_back(std::vector<MapNode>(mapSize.width, MapNode()));
	for (int y = 0; y < mapSize.height; ++y)
		for (int x = 0; x < mapSize.width; ++x)
		{
			mapNodeSet[y][x] = MapNode(
				ArKCa::Vector2<int>(x, y),
				MapNode::NodeType_Wall,
				MapNode::ExtraType_None,
				true,
				true,
				(y == 0) ? (MapNode::invalidPosition) : (ArKCa::Vector2<int>(x, y - 1)),
				(x == mapSize.width - 1) ? (MapNode::invalidPosition) : (ArKCa::Vector2<int>(x + 1, y)),
				(y == mapSize.height - 1) ? (MapNode::invalidPosition) : (ArKCa::Vector2<int>(x, y + 1)),
				(x == 0) ? (MapNode::invalidPosition) : (ArKCa::Vector2<int>(x - 1, y))
				);
		}

	ArKCa::Vector2<int> missionMapOrigin(0, 0);
	auto missionMapSet = missionMap->getSize();
	auto missionMapNodeSet = missionMap->getMapNodeSet();
	ArKCa::Vector2<int> vec(0, 0);
	for (vec.y = 0; vec.y < missionMapSet.height; ++vec.y)
	{
		for (vec.x = 0; vec.x < missionMapSet.width; ++vec.x)
		{
			mapNodeSet[vec.y + missionMapOrigin.y][vec.x + missionMapOrigin.x].nodeType =
				missionMapNodeSet[vec.y][vec.x].nodeType;
			mapNodeSet[vec.y + missionMapOrigin.y][vec.x + missionMapOrigin.x].extraType =
				missionMapNodeSet[vec.y][vec.x].extraType;
			mapNodeSet[vec.y + missionMapOrigin.y][vec.x + missionMapOrigin.x].nodeVisible =
				missionMapNodeSet[vec.y][vec.x].nodeVisible;
			mapNodeSet[vec.y + missionMapOrigin.y][vec.x + missionMapOrigin.x].extraVisible =
				missionMapNodeSet[vec.y][vec.x].nodeVisible;
		}
	}

	gameMap.loadMapNode(mapSize, mapNodeSet);

	xRange.set(0, gameMap.getSize().width - mapView.getViewSize().width);
	yRange.set(0, gameMap.getSize().height - mapView.getViewSize().height);
}

void MapController::viewMoveUp(int step)
{
	if (step <= 0)
		return;

	auto curOrigin = mapView.getViewOrigin();
	ArKCa::Vector2<int> newOrigin(curOrigin);
	if (yRange.within(curOrigin.y - step))
		newOrigin.y -= step;
	else
		newOrigin.y = yRange.min;
	mapView.setViewOrigin(newOrigin);
}

void MapController::viewMoveRight(int step)
{
	if (step <= 0)
		return;

	auto curOrigin = mapView.getViewOrigin();
	ArKCa::Vector2<int> newOrigin(curOrigin);
	if (xRange.within(curOrigin.x + step))
		newOrigin.x += step;
	else
		newOrigin.x = xRange.max;
	mapView.setViewOrigin(newOrigin);
}

void MapController::viewMoveDown(int step)
{
	if (step <= 0)
		return;

	auto curOrigin = mapView.getViewOrigin();
	ArKCa::Vector2<int> newOrigin(curOrigin);
	if (yRange.within(curOrigin.y + step))
		newOrigin.y += step;
	else
		newOrigin.y = yRange.max;
	mapView.setViewOrigin(newOrigin);
}

void MapController::viewMoveLeft(int step)
{
	if (step <= 0)
		return;

	auto curOrigin = mapView.getViewOrigin();
	ArKCa::Vector2<int> newOrigin(curOrigin);
	if (xRange.within(curOrigin.x - step))
		newOrigin.x -= step;
	else
		newOrigin.x = xRange.min;
	mapView.setViewOrigin(newOrigin);
}