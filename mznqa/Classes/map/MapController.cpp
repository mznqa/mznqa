#pragma execution_character_set("utf-8")

#include "map/MapController.h"

MapController* MapController::Instance()
{
	static MapController instance;
	return &instance;
}

MapController::~MapController()
{
}

void MapController::loadMapNode(std::vector<MapNode> &mapNodeSet)
{
	this->mapNodeSet.swap(mapNodeSet);
}