/*!
 * \file	Classes\map\MissionMap.h
 *
 * \brief	定义类 MissionMap
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MAP_MISSIONMAP_H_
#define MZNQA_CLASSES_MAP_MISSIONMAP_H_

#include <vector>

#include "map/MapNode.h"

/*!
 * \class	MissionMap
 *
 * \brief	任务地图
 *
 */
class MissionMap
{
public:
	/*! \brief	定义无效任务地图索引值 */
	static const int invalidIndex = -1;

	/*!
	 * \enum	MapType
	 *
	 * \brief	定义任务地图的类型
	 */
	enum MapType
	{
		MapType_MainMission = 0,	///< 主线任务图
		MapType_SideMission = 1		///< 支线任务图
	};

	/*!
	 * \fn	MissionMap::MissionMap()
	 *
	 * \brief	构造函数
	 *
	 */
	MissionMap() :
		index(invalidIndex),
		mapType(MapType_MainMission)
	{}

	/*!
	 * \fn	MissionMap::MissionMap(int index, MapType mapType, int width, int height, const std::vector<MapNode> mapNodeSet);
	 *
	 * \brief	构造函数
	 *
	 * \param	index	  	指定任务地图的索引
	 * \param	mapType   	指定任务地图的类型
	 * \param	width	  	指定任务地图的宽度
	 * \param	height	  	指定任务地图的高度
	 * \param	mapNodeSet	指定用于载入任务地图节点的地图节点集合
	 */
	MissionMap(int index, MapType mapType, int width, int height, const std::vector<MapNode> mapNodeSet);

	/*!
	 * \fn	MissionMap::~MissionMap();
	 *
	 * \brief	析构函数
	 *
	 */
	~MissionMap();

	/*!
	 * \fn	MapType MissionMap::getMapType()
	 *
	 * \brief	获取任务的地图的类型
	 *
	 * \return	返回任务地图的类型
	 */
	MapType getMapType()const
	{
		return mapType;
	}

	/*!
	 * \fn	int MissionMap::getWidth()const
	 *
	 * \brief	获取任务地图的宽度
	 *
	 * \return	返回任务地图的宽度
	 */
	int getWidth()const
	{
		if (mapNodeSet.empty() == false)
			return mapNodeSet.at(0).size();
		else
			return 0;
	}

	/*!
	 * \fn	int MissionMap::getHeight()const
	 *
	 * \brief	获取任务地图的高度
	 *
	 * \return	获取任务地图的高度
	 */
	int getHeight()const
	{
		if (mapNodeSet.empty() == false)
			return mapNodeSet.size();
		else
			return 0;
	}

	/*!
	 * \fn	const std::vector<std::vector<MapNode> >& MissionMap::getMapNodeSet()const
	 *
	 * \brief	获取任务地图的地图节点集合
	 *
	 * \return	返回任务地图的地图节点集合
	 */
	const std::vector<std::vector<MapNode> >& getMapNodeSet()const
	{
		return mapNodeSet;
	}

private:

	/*! \brief	任务地图的索引 */
	int index;

	/*! \brief	任务地图的类型 */
	MapType mapType;

	/*! \brief	任务地图的节点集合 */
	std::vector<std::vector<MapNode>> mapNodeSet;
};

#endif
