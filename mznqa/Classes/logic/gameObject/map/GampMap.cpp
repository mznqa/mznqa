/*!
 * \file	Classes\logic\gameObject\map\GampMap.cpp
 *
 * \brief	∂®“Â¿‡ GameMap
 */

#pragma execution_character_set("utf-8")

#include "logic/gameObject/map/GameMap.h"

GameMap::GameMap(const ArKCa::Size<int> size, std::map<int, MapNode> &mapNodeSet) :
size(size)
{
	nodeSet.clear();
	nodeSet.swap(mapNodeSet);
}

GameMap::GameMap(const GameMap &gameMap) :
size(gameMap.getSize()),
nodeSet(gameMap.getMapNodeSet())
{
}

GameMap& GameMap::operator=(const GameMap &gameMap)
{
	size = gameMap.getSize();
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

void GameMap::loadMapNode(const ArKCa::Size<int> size, std::map<int, MapNode> &mapNodeSet)
{
	this->size = size;
	nodeSet.clear();
	nodeSet.swap(mapNodeSet);
}

const std::map<int, MapNode>& GameMap::getMapNodeSet()const
{
	return nodeSet;
}

void GameMap::clear()
{
	size.set(0, 0);
	nodeSet.clear();
}

const ArKCa::Size<int>& GameMap::getSize()const
{
	return size;
}