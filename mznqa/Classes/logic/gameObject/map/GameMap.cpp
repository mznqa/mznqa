/*!
 * \file	Classes\logic\gameObject\map\GameMap.cpp
 *
 * \brief	∂®“Â¿‡ GameMap
 */

#pragma execution_character_set("utf-8")

#include "logic/gameObject/map/GameMap.h"

GameMap::GameMap(const ArKCa::Size<int> size, std::vector<std::vector<MapNode>> &mapNodeSet) :
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
	this->size = gameMap.getSize();
	this->nodeSet.clear();
	for (int y = 0; y < this->size.height; ++y)
		this->nodeSet.push_back(std::vector<MapNode>(
		this->size.width,
		MapNode()
		));
	for (int y = 0; y < this->size.height; ++y)
		for (int x = 0; x < this->size.width; ++x)
		{
			this->nodeSet[y][x] = gameMap.getMapNodeSet()[y][x];
		}
	return *this;
}

void GameMap::loadMapNode(const ArKCa::Size<int> size, std::vector<std::vector<MapNode>> &mapNodeSet)
{
	this->size = size;
	nodeSet.clear();
	nodeSet.swap(mapNodeSet);
}

const std::vector<std::vector<MapNode>>& GameMap::getMapNodeSet()const
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