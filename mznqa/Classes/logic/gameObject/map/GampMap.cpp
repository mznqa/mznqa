/*!
 * \file	Classes\logic\gameObject\map\GampMap.cpp
 *
 * \brief	∂®“Â¿‡ GameMap
 */

#pragma execution_character_set("utf-8")

#include "logic/gameObject/map/GameMap.h"

GameMap::GameMap(std::map<int, MapNode> &mapNodeSet)
{
	nodeSet.clear();
	nodeSet.swap(mapNodeSet);
}

GameMap::GameMap(const GameMap &gameMap) :
nodeSet(gameMap.getMapNodeSet())
{
}

GameMap& GameMap::operator=(const GameMap &gameMap)
{
	this->nodeSet.clear();
	auto it = gameMap.getMapNodeSet().cbegin();
	auto itEnd = gameMap.getMapNodeSet().cend();
	while (it != itEnd)
	{
		this->nodeSet.insert(*it);
		++it;
	}
	return *this;
}

void GameMap::loadMapNode(std::map<int, MapNode> &mapNodeSet)
{
	nodeSet.clear();
	nodeSet.swap(mapNodeSet);
}

const std::map<int, MapNode>& GameMap::getMapNodeSet()const
{
	return nodeSet;
}