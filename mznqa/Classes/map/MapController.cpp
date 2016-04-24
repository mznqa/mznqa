/*!
 * \file	Classes\map\MapController.cpp
 *
 * \brief	∂®“Â¿‡ MapController
 */

#pragma execution_character_set("utf-8")

#include "map/MapController.h"

#include <cstdlib>
#include <ctime>

#include "map/MapNode.h"
#include "map/MapView.h"
#include "map/MissionMap.h"

MapController* MapController::Instance()
{
	static MapController instance;
	return &instance;
}

MapController::MapController()
{
	MapView::Instance()->initialize(0, 0, 30, 15);
}

MapController::~MapController()
{
}

void MapController::setEmptyMap()
{
	mapNodeSet.clear();
	mapNodeSet = std::vector<std::vector<MapNode>>(mapNodecountVertical, std::vector<MapNode>(mapNodecountHorizontal));
	for (int y = 0; y < mapNodecountVertical; ++y)
		for (int x = 0; x < mapNodecountHorizontal; ++x)
		{
			mapNodeSet.at(y).at(x) = MapNode(
				MapNode::getIndexByXY(x, y),
				x,
				y,
				false,
				MapNode::NodeType_Wall,
				CardBase::invalidID
				);
		}
}

void MapController::loadMapNode(const MissionMap &missionMap)
{
	int w = missionMap.getWidth();
	int h = missionMap.getHeight();

	if (w <= 0 || h <= 0)
		return;

	if (w > mapNodecountHorizontal || h > mapNodecountVertical)
		return;

	srand((unsigned)time(NULL));

	int startX = (rand() % ((int)(mapNodecountHorizontal - w) / 3)) * 3;
	int startY = (rand() % ((int)(mapNodecountVertical - h) / 3)) * 3;

	int endX = startX + w;
	int endY = startY + h;

	const std::vector<std::vector<MapNode>>& mns = missionMap.getMapNodeSet();

	for (int y = startY; y < endY; ++y)
		for (int x = startX; x < endX; ++x)
		{
			this->mapNodeSet.at(y).at(x) = mns.at(y - startY).at(x - startX);
		}
}