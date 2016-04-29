/*!
 * \file	Classes\map\MapController.cpp
 *
 * \brief	定义类 MapController
 */

#pragma execution_character_set("utf-8")

#include "map/MapController.h"

#include <cstdlib>
#include <ctime>
#include <memory>

#include "map/MapNode.h"
#include "map/MapView.h"
#include "map/MissionMap.h"
#include "tools/GPointSet.h"
#include "message/LogicMessagePQ.h"
#include "define/GlobalDefine.h"

// 地形卡对应的地形组 //////////////////////////////////////////////////////////////////////////
static const MapNode::NodeType mapGroupRoadTypeNone[3][3]
{
	{ MapNode::NodeType_None, MapNode::NodeType_None, MapNode::NodeType_None },
	{ MapNode::NodeType_None, MapNode::NodeType_None, MapNode::NodeType_None },
	{ MapNode::NodeType_None, MapNode::NodeType_None, MapNode::NodeType_None }
};
static const MapNode::NodeType mapGroupRoadTypeURDL[3][3] =
{
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_None },
	{ MapNode::NodeType_Road, MapNode::NodeType_Road, MapNode::NodeType_Road },
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_None }
};
static const MapNode::NodeType mapGroupRoadTypeRDL[3][3] =
{
	{ MapNode::NodeType_None, MapNode::NodeType_None, MapNode::NodeType_None },
	{ MapNode::NodeType_Road, MapNode::NodeType_Road, MapNode::NodeType_Road },
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_None }
};
static const MapNode::NodeType mapGroupRoadTypeUDL[3][3] =
{
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_None },
	{ MapNode::NodeType_Road, MapNode::NodeType_Road, MapNode::NodeType_None },
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_None }
};
static const MapNode::NodeType mapGroupRoadTypeURL[3][3] =
{
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_None },
	{ MapNode::NodeType_Road, MapNode::NodeType_Road, MapNode::NodeType_Road },
	{ MapNode::NodeType_None, MapNode::NodeType_None, MapNode::NodeType_None }
};
static const MapNode::NodeType mapGroupRoadTypeURD[3][3] =
{
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_None },
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_Road },
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_None }
};
static const MapNode::NodeType mapGroupRoadTypeDL[3][3] =
{
	{ MapNode::NodeType_None, MapNode::NodeType_None, MapNode::NodeType_None },
	{ MapNode::NodeType_Road, MapNode::NodeType_Road, MapNode::NodeType_None },
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_None }
};
static const MapNode::NodeType mapGroupRoadTypeUL[3][3] =
{
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_None },
	{ MapNode::NodeType_Road, MapNode::NodeType_Road, MapNode::NodeType_None },
	{ MapNode::NodeType_None, MapNode::NodeType_None, MapNode::NodeType_None }
};
static const MapNode::NodeType mapGroupRoadTypeUR[3][3] =
{
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_None },
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_Road },
	{ MapNode::NodeType_None, MapNode::NodeType_None, MapNode::NodeType_None }
};
static const MapNode::NodeType mapGroupRoadTypeRL[3][3] =
{
	{ MapNode::NodeType_None, MapNode::NodeType_None, MapNode::NodeType_None },
	{ MapNode::NodeType_Road, MapNode::NodeType_Road, MapNode::NodeType_Road },
	{ MapNode::NodeType_None, MapNode::NodeType_None, MapNode::NodeType_None }
};
static const MapNode::NodeType mapGroupRoadTypeUD[3][3] =
{
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_None },
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_None },
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_None }
};
static const MapNode::NodeType mapGroupRoadTypeRD[3][3] =
{
	{ MapNode::NodeType_None, MapNode::NodeType_None, MapNode::NodeType_None },
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_Road },
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_None }
};
static const MapNode::NodeType mapGroupRoadTypeU[3][3] =
{
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_None },
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_None },
	{ MapNode::NodeType_None, MapNode::NodeType_None, MapNode::NodeType_None }
};
static const MapNode::NodeType mapGroupRoadTypeR[3][3] =
{
	{ MapNode::NodeType_None, MapNode::NodeType_None, MapNode::NodeType_None },
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_Road },
	{ MapNode::NodeType_None, MapNode::NodeType_None, MapNode::NodeType_None }
};
static const MapNode::NodeType mapGroupRoadTypeD[3][3] =
{
	{ MapNode::NodeType_None, MapNode::NodeType_None, MapNode::NodeType_None },
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_None },
	{ MapNode::NodeType_None, MapNode::NodeType_Road, MapNode::NodeType_None }
};
static const MapNode::NodeType mapGroupRoadTypeL[3][3] =
{
	{ MapNode::NodeType_None, MapNode::NodeType_None, MapNode::NodeType_None },
	{ MapNode::NodeType_Road, MapNode::NodeType_Road, MapNode::NodeType_None },
	{ MapNode::NodeType_None, MapNode::NodeType_None, MapNode::NodeType_None }
};
//////////////////////////////////////////////////////////////////////////

MapController* MapController::Instance()
{
	static MapController instance;
	return &instance;
}

MapController::MapController()
{
	if (cocos2d::Director::getInstance()->getVisibleSize().width == cocos2d::Director::getInstance()->getWinSize().width)
		MapView::Instance()->initialize(0, 0, 30, int(SCREENSIZE_HEIGHT / (MAP_CELL_SIZE*SCREENSIZE_WIDTH / DESIGNRESOLUTIONSIZE_WIDTH)) / 3 * 3);
	else if (cocos2d::Director::getInstance()->getVisibleSize().height == cocos2d::Director::getInstance()->getWinSize().height)
		MapView::Instance()->initialize(0, 0, int(SCREENSIZE_WIDTH / (MAP_CELL_SIZE*SCREENSIZE_HEIGHT / DESIGNRESOLUTIONSIZE_HEIGHT)) / 3 * 3, 15);
	else
		MapView::Instance()->initialize(0, 0, int(SCREENSIZE_WIDTH / (MAP_CELL_SIZE*SCREENSIZE_HEIGHT / DESIGNRESOLUTIONSIZE_HEIGHT)) / 3 * 3, 15);
}

MapController::~MapController()
{
}

void MapController::setEmptyMap()
{
	mapNodeSet.clear();
	mapNodeSet = std::vector<std::vector<MapNode>>(mapNodecountVertical, std::vector<MapNode>(mapNodecountHorizontal));
	for (int y = 0; y < mapNodecountVertical; ++y)
		for (int x = 0; x < mapNodecountHorizontal; ++x)
		{
			mapNodeSet.at(y).at(x) = MapNode(
				MapNode::getIndexByXY(x, y),
				x,
				y,
				false,
				MapNode::NodeType_Wall,
				CardBase::invalidID
				);
		}
}

void MapController::loadMapNode(const MissionMap &missionMap)
{
	int w = missionMap.getWidth();
	int h = missionMap.getHeight();

	if (w <= 0 || h <= 0)
		return;

	if (w > mapNodecountHorizontal || h > mapNodecountVertical)
		return;

	srand((unsigned)time(NULL));

	int startX = (rand() % ((int)(mapNodecountHorizontal - w) / 3)) * 3;
	int startY = (rand() % ((int)(mapNodecountVertical - h) / 3)) * 3;

	int endX = startX + w;
	int endY = startY + h;

	const std::vector<std::vector<MapNode>>& mns = missionMap.getMapNodeSet();

	for (int y = startY; y < endY; ++y)
		for (int x = startX; x < endX; ++x)
		{
			this->mapNodeSet.at(y).at(x) = mns.at(y - startY).at(x - startX);
		}
}

bool MapController::putCardRoad(const CardRoad &cardRoad, const GRect &rect)
{
	if (rect.leftTopGX % 3 != 0 || rect.leftTopGY % 3 != 0)
		return false;
	if (checkX(rect.leftTopGX) == false)
		return false;
	if (checkX(rect.rightBottomGX) == false)
		return false;
	if (rect.leftTopGX > rect.rightBottomGX)
		return false;
	if (checkY(rect.leftTopGY) == false)
		return false;
	if (checkY(rect.rightBottomGY) == false)
		return false;
	if (rect.leftTopGY > rect.rightBottomGY)
		return false;

	const MapNode::NodeType(*mNS)[3];
	switch (cardRoad.getRoadType())
	{
	case CardRoad::RoadType_None:
		mNS = mapGroupRoadTypeNone;
		break;
	case CardRoad::RoadType_URDL:
		mNS = mapGroupRoadTypeURDL;
		break;
	case CardRoad::RoadType_RDL:
		mNS = mapGroupRoadTypeRDL;
		break;
	case CardRoad::RoadType_UDL:
		mNS = mapGroupRoadTypeUDL;
		break;
	case CardRoad::RoadType_URL:
		mNS = mapGroupRoadTypeURL;
		break;
	case CardRoad::RoadType_URD:
		mNS = mapGroupRoadTypeURD;
		break;
	case CardRoad::RoadType_DL:
		mNS = mapGroupRoadTypeDL;
		break;
	case CardRoad::RoadType_UL:
		mNS = mapGroupRoadTypeUL;
		break;
	case CardRoad::RoadType_UR:
		mNS = mapGroupRoadTypeUR;
		break;
	case CardRoad::RoadType_RL:
		mNS = mapGroupRoadTypeRL;
		break;
	case CardRoad::RoadType_UD:
		mNS = mapGroupRoadTypeUD;
		break;
	case CardRoad::RoadType_RD:
		mNS = mapGroupRoadTypeRD;
		break;
	case CardRoad::RoadType_U:
		mNS = mapGroupRoadTypeU;
		break;
	case CardRoad::RoadType_R:
		mNS = mapGroupRoadTypeR;
		break;
	case CardRoad::RoadType_D:
		mNS = mapGroupRoadTypeD;
		break;
	case CardRoad::RoadType_L:
		mNS = mapGroupRoadTypeL;
		break;
	default:
		return false;
	}

	GPointSet *gPointSet = new GPointSet();
	int yEnd = rect.leftTopGY + mapGroupSize;
	int xEnd = rect.leftTopGX + mapGroupSize;
	for (int y = rect.leftTopGY, iy = 0; y < yEnd && iy < mapGroupSize; ++y, ++iy)
		for (int x = rect.leftTopGX, ix = 0; x < xEnd && ix < mapGroupSize; ++x, ++ix)
		{
			if (mNS[iy][ix] == MapNode::NodeType_None)
				continue;
			this->mapNodeSet.at(y).at(x).nodeType = mNS[iy][ix];
			gPointSet->insert(x, y);
		}

	LogicMessagePQ::Instance()->pushMessage(Message<LogicMessagePQ::LMessage>(
		LogicMessagePQ::LMessage_RefreshMapCellSpriteByGPointSet_TGPointSetT,
		gPointSet
		));

	return true;
}