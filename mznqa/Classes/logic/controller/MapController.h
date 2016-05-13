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
		gameMap(nullptr)
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
	GameMap *gameMap;
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
	 * \fn	void MapController::build( const std::vector<MissionMapSet::MissionMapIDMain> &mainIDSet, const std::vector<MissionMapSet::MissionMapIDSecondary> &secondaryIDSet );
	 *
	 * \brief	构建地图
	 *
	 * \param	mainIDSet	  	指定主线地图ID集合
	 * \param	secondaryIDSet	指定支线地图ID集合
	 */
	void build(
		const std::vector<MissionMapSet::MissionMapIDMain> &mainIDSet,
		const std::vector<MissionMapSet::MissionMapIDSecondary> &secondaryIDSet
		);
};

#endif
