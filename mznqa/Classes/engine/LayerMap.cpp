#pragma execution_character_set("utf-8")

#include "engine/LayerMap.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "filePath/SceneFilePath.h"

#include "map/MapController.h"
#include "staticData/MissionMapSet.h"

USING_NS_CC;
using namespace cocostudio::timeline;

bool LayerMap::init()
{
	if (!Layer::init())
	{
		return false;
	}

	MapController::Instance()->loadMapNode(MissionMapSet::Instance()->getMainMissionMapByIndex(0));

	auto it1 = mapCellSet.begin();
	auto itEnd1 = mapCellSet.end();
	int y = 0;
	while (it1 != itEnd1)
	{
		auto it2 = it1->begin();
		auto itEnd2 = it1->end();
		int x = 0;
		while (it2 != itEnd2)
		{
			MapNode::NodeType nt = MapController::Instance()->getMapNodeSet().at(y).at(x).nodeType;
			if (nt == MapNode::NodeType_None)
				*it2 = Sprite::create("test_map_cell/map_cell_none.png");
			else if (nt == MapNode::NodeType_Wall)
				*it2 = Sprite::create("test_map_cell/map_cell_wall.png");
			else if (nt == MapNode::NodeType_Road)
				*it2 = Sprite::create("test_map_cell/map_cell_road.png");
			else if (nt == MapNode::NodeType_Door)
				*it2 = Sprite::create("test_map_cell/map_cell_door.png");

			(*it2)->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
			(*it2)->setPosition(Vec2(x*128.0, -y*128.0));

			addChild(*it2);
			++it2;
			++x;
		}
		++it1;
		++y;
	}

	return true;
}