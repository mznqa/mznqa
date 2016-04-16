/*!
 * \file	Classes\map\MapController.h
 *
 * \brief	地图控制器
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MAP_MAPCONTROLLER_H_
#define MZNQA_CLASSES_MAP_MAPCONTROLLER_H_

#include <vector>

struct MapNode;
class MapView;
class MissionMap;

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
	MapController();

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
	std::vector<std::vector<MapNode>> mapNodeSet;
public:

	/*! \brief	地图视图 */
	MapView *mapView = nullptr;

	/*! \brief	地图横向节点总个数 */
	static const int mapNodecountHorizontal = 60;
	/*! \brief	地图纵向节点总个数 */
	static const int mapNodecountVertical = 30;

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
	 * \fn	void MapController::createMap()
	 *
	 * \brief	将当成地图重置为一张空地图
	 *
	 */
	void setEmptyMap();

	/*!
	 * \fn	void MapController::loadMapNode(const MissionMap &missionMap);
	 *
	 * \brief	载入地图节点集合
	 *
	 * \param [in,out]	missionMap	地图节点集合实例
	 */
	void loadMapNode(const MissionMap &missionMap);

	/*!
	 * \fn	const std::vector<std::vector<MapNode> >& MapController::getMapNodeSet()
	 *
	 * \brief	获取地图节点集合
	 *
	 * \return	返回地图节点集合的常量引用
	 */
	const std::vector<std::vector<MapNode> >& getMapNodeSet()
	{
		return mapNodeSet;
	}
};

#endif
