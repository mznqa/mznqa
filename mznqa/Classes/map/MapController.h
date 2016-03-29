#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MAP_MAPCONTROLLER_H_
#define MZNQA_CLASSES_MAP_MAPCONTROLLER_H_

#include <vector>

#include "map/MapNode.h"

// ��ͼ������������ʵʱ��ȫ�ֵ�ͼ
class MapController
{
private:
	MapController(){}
	MapController(const MapController &mapController);
	MapController& operator=(const MapController &mapController);

	// ��ͼ�ڵ㼯��
	std::vector<MapNode> mapNodeSet;
public:
	static MapController* Instance();
	~MapController();

	// �����ͼ�ڵ㼯��
	void loadMapNode(std::vector<MapNode> &mapNodeSet);
};

#endif
