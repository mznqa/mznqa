#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MAP_MISSIONMAP_H_
#define MZNQA_CLASSES_MAP_MISSIONMAP_H_

#include <vector>

#include "map/MapNode.h"

class MissionMap
{
public:
	enum MapType
	{
		MapType_MainMission = 0,	///< 主线任务图
		MapType_SideMission = 1		///< 支线任务图
	};

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

	std::vector<std::vector<MapNode>> mapNodeSet;
private:

	int index;

	MapType mapType;
};

#endif
