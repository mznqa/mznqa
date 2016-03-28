#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MAP_MAPCONTROLLER_H_
#define MZNQA_CLASSES_MAP_MAPCONTROLLER_H_

#include <vector>

#include "map/MapNode.h"

class MapController
{
private:
	MapController(){}
	MapController(const MapController &mapController);
	MapController& operator=(const MapController &mapController);

	std::vector<MapNode> mapNodeSet;
public:
	static MapController* Instance();
	~MapController();

	void loadMapNode(std::vector<MapNode> &mapNodeSet);
};

#endif
