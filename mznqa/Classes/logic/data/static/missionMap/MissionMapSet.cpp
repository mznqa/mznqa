/*!
 * \file	Classes\logic\data\static\missionMap\MissionMapSet.cpp
 *
 * \brief	∂®“Â¿‡ MissionMapSet
 */

#pragma execution_character_set("utf-8")

#include "logic/data/static/missionMap/MissionMapSet.h"

MissionMapSet* MissionMapSet::Instance()
{
	static MissionMapSet instance;
	return &instance;
}

void MissionMapSet::loadMapMain(MissionMapIDMain id, const GameMap &gameMap)
{
	if (mainSet.empty() == false && mainSet.find(id) != mainSet.cend())
		return;
	else
		mainSet.insert(std::pair<MissionMapIDMain, GameMap>(id, gameMap));
}

void MissionMapSet::loadMapSecondary(MissionMapIDSecondary id, const GameMap &gameMap)
{
	if (secondarySet.empty() == false && secondarySet.find(id) != secondarySet.cend())
		return;
	else
		secondarySet.insert(std::pair<MissionMapIDSecondary, GameMap>(id, gameMap));
}