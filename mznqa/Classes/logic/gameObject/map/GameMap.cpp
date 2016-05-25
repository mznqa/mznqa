/*!
 * \file	Classes\logic\gameObject\map\GameMap.cpp
 *
 * \brief	������ GameMap
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

std::vector<ArKCa::Vector2<int>> GameMap::getCanThroughNearPosition(const ArKCa::Vector2<int> &position)const
{
	std::vector<ArKCa::Vector2<int>> pointSet;

	if (0 <= position.x && position.x < size.width && 0 <= position.y && position.y < size.height)
	{
		if (0 <= position.y - 1 && nodeSet[position.y - 1][position.x].canThrough())
			pointSet.push_back(position + ArKCa::Vector2<int>(0, -1));
		if (position.x + 1 < size.width && nodeSet[position.y][position.x + 1].canThrough())
			pointSet.push_back(position + ArKCa::Vector2<int>(1, 0));
		if (position.y + 1 < size.height && nodeSet[position.y + 1][position.x].canThrough())
			pointSet.push_back(position + ArKCa::Vector2<int>(0, 1));
		if (0 <= position.x - 1 && nodeSet[position.y][position.x - 1].canThrough())
			pointSet.push_back(position + ArKCa::Vector2<int>(-1, 0));
	}

	return pointSet;
}

bool GameMap::getNeighborCanThrough(const ArKCa::Vector2<int> &position, ArKCa::Direction4 direction)
{
	if (0 <= position.x && position.x < size.width && 0 <= position.y && position.y < size.height)
	{
		switch (direction)
		{
		case ArKCa::Direction4_None:
			return false;
		case ArKCa::Direction4_Up:
			if (0 <= position.y - 1)
				return nodeSet[position.y - 1][position.x].canThrough();
			break;
		case ArKCa::Direction4_Right:
			if (position.x + 1 < size.width)
				return nodeSet[position.y][position.x + 1].canThrough();
			break;
		case ArKCa::Direction4_Down:
			if (position.y + 1 < size.height)
				return nodeSet[position.y + 1][position.x].canThrough();
			break;
		case ArKCa::Direction4_Left:
			if (0 <= position.x - 1)
				return nodeSet[position.y][position.x - 1].canThrough();
			break;
		default:
			return false;
		}
	}
	return false;
}