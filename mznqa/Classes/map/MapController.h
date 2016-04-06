/*!
 * \file	Classes\map\MapController.h
 *
 * \brief	地图控制器
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MAP_MAPCONTROLLER_H_
#define MZNQA_CLASSES_MAP_MAPCONTROLLER_H_

#include <vector>

#include "map/MapNode.h"

/*!
 * \class	MapController
 *
 * \brief	单例。全局地图控制器
 *
 */
class MapController
{
private:

	/*!
	 * \fn	MapController::MapController()
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	MapController(){}

	/*!
	 * \fn	MapController::MapController(const MapController &mapController);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 * \param	mapController	MapController 实例
	 */
	MapController(const MapController &mapController);

	/*!
	 * \fn	MapController& MapController::operator=(const MapController &mapController);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 * \param	mapController	MapController 实例
	 *
	 * \return	MapController 实例
	 */
	MapController& operator=(const MapController &mapController);

	/*! \brief	地图节点集合 */
	std::vector<MapNode> mapNodeSet;
public:

	/*!
	 * \fn	static MapController* MapController::Instance();
	 *
	 * \brief	获取单例
	 *
	 * \return	返回单例
	 */
	static MapController* Instance();

	/*!
	 * \fn	MapController::~MapController();
	 *
	 * \brief	析构函数
	 *
	 */
	~MapController();

	/*!
	 * \fn	void MapController::loadMapNode(std::vector<MapNode> &mapNodeSet);
	 *
	 * \brief	载入地图节点集合
	 *
	 * \param [in,out]	mapNodeSet	地图节点集合实例
	 */
	void loadMapNode(std::vector<MapNode> &mapNodeSet);
};

#endif
