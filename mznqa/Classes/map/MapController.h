#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MAP_MAPCONTROLLER_H_
#define MZNQA_CLASSES_MAP_MAPCONTROLLER_H_

#include <vector>

#include "map/MapNode.h"

// 地图控制器，保存实时的全局地图
class MapController
{
private:
	MapController(){}
	MapController(const MapController &mapController);
	MapController& operator=(const MapController &mapController);

	// 地图节点集合
	std::vector<MapNode> mapNodeSet;
public:
	static MapController* Instance();
	~MapController();

	// 载入地图节点集合
	void loadMapNode(std::vector<MapNode> &mapNodeSet);
};

#endif
