#pragma execution_character_set("utf-8")

#include "map/MissionMap.h"

#include "card/CardBase.h"

MissionMap::MissionMap(int index, MapType mapType, int width, int height, const std::vector<MapNode> mapNodeSet) :
index(index),
mapType(mapType)
{
	if (index < 0)
		return;

	if (width <= 0 || height <= 0)
		return;

	if (width * height != mapNodeSet.size())
		return;

	this->mapNodeSet = std::vector<std::vector<MapNode>>(height, std::vector<MapNode>(width));

	auto it = mapNodeSet.cbegin();
	auto itEnd = mapNodeSet.cend();
	while (it != itEnd)
	{
		this->mapNodeSet.at(it->y).at(it->x) = (*it);
		++it;
	}
}

MissionMap::~MissionMap()
{
}