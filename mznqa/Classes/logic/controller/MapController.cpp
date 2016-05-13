/*!
 * \file	Classes\logic\controller\MapController.cpp
 *
 * \brief	∂®“Â¿‡ MapController
 */

#pragma execution_character_set("utf-8")

#include "logic/controller/MapController.h"

MapController* MapController::Instance()
{
	static MapController instance;
	return &instance;
}

void MapController::build(
	const std::vector<MissionMapSet::MissionMapIDMain> &mainIDSet,
	const std::vector<MissionMapSet::MissionMapIDSecondary> &secondaryIDSet
	)
{
	gameMap->clear();
}