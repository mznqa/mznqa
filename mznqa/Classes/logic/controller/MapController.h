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
	 * \fn	GameMap& MapController::getMap()
	 *
	 * \brief	获取地图
	 *
	 */
	GameMap& getMap()
	{
		return gameMap;
	}

	/*!
	 * \fn	const MapView& MapController::getMapView()
	 *
	 * \brief	获取地图视野
	 *
	 * \author	Yeshiyong
	 * \date	2016/5/22
	 *
	 * \return	The map view.
	 */

	const MapView& getMapView()
	{
		return mapView;
	}

	/*!
	 * \fn	bool MapController::viewMoveUp(int step = 1);
	 *
	 * \brief	上移视野
	 *
	 * \param	step	指定移动格数, 默认为 1
	 *
	 * \return	返回是否移动成功
	 */
	bool viewMoveUp(int step = 1);

	/*!
	 * \fn	bool MapController::viewMoveRight(int step = 1);
	 *
	 * \brief	右移视野
	 *
	 * \param	step	指定移动格数, 默认为 1
	 *
	 * \return	返回是否移动成功
	 */
	bool viewMoveRight(int step = 1);

	/*!
	 * \fn	bool MapController::viewMoveDown(int step = 1);
	 *
	 * \brief	下移视野
	 *
	 * \param	step	指定移动格数, 默认为 1
	 *
	 * \return	返回是否移动成功
	 */
	bool viewMoveDown(int step = 1);

	/*!
	 * \fn	bool MapController::viewMoveLeft(int step = 1);
	 *
	 * \brief	左移视野
	 *
	 * \param	step	指定移动格数, 默认为 1
	 *
	 * \return	返回是否移动成功
	 */
	bool viewMoveLeft(int step = 1);

	/*!
	 * \fn	void MapController::updateMapViewMoveRange();
	 *
	 * \brief	更新地图视野的移动范围
	 *
	 */
	void updateMapViewMoveRange();
};

#endif
