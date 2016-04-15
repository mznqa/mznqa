#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MAP_MISSIONMAP_H_
#define MZNQA_CLASSES_MAP_MISSIONMAP_H_

#include <vector>

#include "map/MapNode.h"

class MissionMap
{
public:
	static const int invalidIndex = -1;

	enum MapType
	{
		MapType_MainMission = 0,	///< ��������ͼ
		MapType_SideMission = 1		///< ֧������ͼ
	};

	MissionMap() :
		index(invalidIndex),
		mapType(MapType_MainMission)
	{}

	MissionMap(int index, MapType mapType, int width, int height, const std::vector<MapNode> mapNodeSet);

	~MissionMap();

	MapType getMapType()
	{
		return mapType;
	}

	const std::vector<std::vector<MapNode>>& getMapNodeSet()const
	{
		return mapNodeSet;
	}

private:

	int index;

	MapType mapType;

	std::vector<std::vector<MapNode>> mapNodeSet;
};

#endif
