/*!
 * \file	Classes\logic\controller\MapController.h
 *
 * \brief	定义类 MapController
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_CONTROLLER_MAPCONTROLLER_H_
#define MZNQA_CLASSES_LOGIC_CONTROLLER_MAPCONTROLLER_H_

#include <vector>

#include "logic/gameObject/map/GameMap.h"
#include "logic/data/static/missionMap/MissionMapSet.h"
#include "logic/gameObject/map/MapView.h"
#include "common/arkca/Range.h"

/*!
 * \class	MapController
 *
 * \brief	[单例]用于控制地图
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
	MapController() :
		gameMap(),
		mapView(),
		xRange(0, 0),
		yRange(0, 0)
	{
	}

	/*!
	 * \fn	MapController::MapController(const MapController &mapController);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 */
	MapController(const MapController &mapController);

	/*!
	 * \fn	MapController& MapController::operator=(const MapController &mapController);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 */
	MapController& operator=(const MapController &mapController);

	/*! \brief	内建地图 */
	GameMap gameMap;
	/*! \brief	地图视野 */
	MapView mapView;

	/*! \brief	视野左上角起点允许的横坐标值 */
	ArKCa::Range<int> xRange;
	/*! \brief	视野左上角起点允许的纵坐标值 */
	ArKCa::Range<int> yRange;
public:

	/*!
	 * \fn	MapController::~MapController()
	 *
	 * \brief	析构函数
	 *
	 */
	~MapController()
	{
	}

	/*!
	 * \fn	static MapController* MapController::Instance();
	 *
	 * \brief	获取单例
	 *
	 */
	static MapController* Instance();

	/*!
	 * \fn	void MapController::build(MissionMapSet::MissionMapIDMain id);
	 *
	 * \brief	构建地图
	 *
	 * \param	id	指定主线地图ID
	 */
	void build(MissionMapSet::MissionMapIDMain id);

	/*!
	 * \fn	void MapController::setMapView(const ArKCa::Size<int> &size, const ArKCa::Vector2<int> &originPosition)
	 *
	 * \brief	设置地图视野
	 *
	 * \param	size		   	指定地图视野的尺寸
	 * \param	originPosition	指定地图视野
	 */
	void setMapView(const ArKCa::Size<int> &size, const ArKCa::Vector2<int> &originPosition)
	{
		mapView = MapView(size, originPosition);
		xRange.set(0, gameMap.getSize().width - mapView.getViewSize().width);
		yRange.set(0, gameMap.getSize().height - mapView.getViewSize().height);
	}

	/*!
	 * \fn	const ArKCa::Size<int>& MapController::getMapSize()const
	 *
	 * \brief	获取地图尺寸信息
	 *
	 */
	const ArKCa::Size<int>& getMapSize()const
	{
		return gameMap.getSize();
	}

	/*!
	 * \fn	const std::vector<std::vector<MapNode> >& MapController::getMapNodeSet()const
	 *
	 * \brief	获取所有地图节点
	 *
	 */
	const std::vector<std::vector<MapNode> >& getMapNodeSet()const
	{
		return gameMap.getMapNodeSet();
	}

	/*!
	 * \fn	const ArKCa::Vector2<int>& MapController::getViewOrigin()const
	 *
	 * \brief	获取地图视野原点
	 *
	 */
	const ArKCa::Vector2<int>& getViewOrigin()const
	{
		return mapView.getViewOrigin();
	}

	/*!
	 * \fn	const ArKCa::Size<int>& MapController::getViewSize()const
	 *
	 * \brief	获取视野尺寸
	 *
	 */
	const ArKCa::Size<int>& getViewSize()const
	{
		return mapView.getViewSize();
	}

	/*!
	 * \fn	void MapController::viewMoveUp(int step);
	 *
	 * \brief	上移视野
	 *
	 * \param	step	指定移动格数
	 */
	void viewMoveUp(int step);

	/*!
	 * \fn	void MapController::viewMoveRight(int step);
	 *
	 * \brief	右移视野
	 *
	 * \param	step	指定移动格数
	 */
	void viewMoveRight(int step);

	/*!
	 * \fn	void MapController::viewMoveDown(int step);
	 *
	 * \brief	下移视野
	 *
	 * \param	step	指定移动格数
	 */
	void viewMoveDown(int step);

	/*!
	 * \fn	void MapController::viewMoveLeft(int step);
	 *
	 * \brief	左移视野
	 *
	 * \param	step	指定移动格数
	 */
	void viewMoveLeft(int step);
};

#endif
