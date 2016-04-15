/*!
 * \file	Classes\map\MapController.cpp
 *
 * \brief	∂®“Â¿‡ MapController
 */

#pragma execution_character_set("utf-8")

#include "map/MapController.h"

#include "map/MapNode.h"
#include "map/MapView.h"

MapController* MapController::Instance()
{
	static MapController instance;
	return &instance;
}

MapController::MapController()
{
	mapView = new MapView(MapView::hDeltaMin, MapView::vDeltaMin);
}

MapController::~MapController()
{
	delete mapView;
}

void MapController::loadMapNode(std::vector<MapNode> &mapNodeSet)
{
	this->mapNodeSet.swap(mapNodeSet);
}