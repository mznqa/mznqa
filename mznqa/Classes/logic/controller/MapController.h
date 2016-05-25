/*!
 * \file	Classes\logic\controller\MapController.h
 *
 * \brief	������ MapController
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
 * \brief	[����]���ڿ��Ƶ�ͼ
 *
 */
class MapController
{
private:

	/*!
	 * \fn	MapController::MapController()
	 *
	 * \brief	���صĹ��캯��
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
	 * \brief	���صĿ������캯��
	 *
	 */
	MapController(const MapController &mapController);

	/*!
	 * \fn	MapController& MapController::operator=(const MapController &mapController);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	MapController& operator=(const MapController &mapController);

	/*! \brief	�ڽ���ͼ */
	GameMap gameMap;
	/*! \brief	��ͼ��Ұ */
	MapView mapView;

	/*! \brief	��Ұ���Ͻ��������ĺ�����ֵ */
	ArKCa::Range<int> xRange;
	/*! \brief	��Ұ���Ͻ���������������ֵ */
	ArKCa::Range<int> yRange;
public:

	/*!
	 * \fn	MapController::~MapController()
	 *
	 * \brief	��������
	 *
	 */
	~MapController()
	{
	}

	/*!
	 * \fn	static MapController* MapController::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 */
	static MapController* Instance();

	/*!
	 * \fn	void MapController::build(MissionMapSet::MissionMapIDMain id);
	 *
	 * \brief	������ͼ
	 *
	 * \param	id	ָ�����ߵ�ͼID
	 */
	void build(MissionMapSet::MissionMapIDMain id);

	/*!
	 * \fn	void MapController::setMapView(const ArKCa::Size<int> &size, const ArKCa::Vector2<int> &originPosition)
	 *
	 * \brief	���õ�ͼ��Ұ
	 *
	 * \param	size		   	ָ����ͼ��Ұ�ĳߴ�
	 * \param	originPosition	ָ����ͼ��Ұ
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
	 * \brief	��ȡ��ͼ
	 *
	 */
	GameMap& getMap()
	{
		return gameMap;
	}

	/*!
	 * \fn	const MapView& MapController::getMapView()
	 *
	 * \brief	��ȡ��ͼ��Ұ
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
	 * \brief	������Ұ
	 *
	 * \param	step	ָ���ƶ�����, Ĭ��Ϊ 1
	 *
	 * \return	�����Ƿ��ƶ��ɹ�
	 */
	bool viewMoveUp(int step = 1);

	/*!
	 * \fn	bool MapController::viewMoveRight(int step = 1);
	 *
	 * \brief	������Ұ
	 *
	 * \param	step	ָ���ƶ�����, Ĭ��Ϊ 1
	 *
	 * \return	�����Ƿ��ƶ��ɹ�
	 */
	bool viewMoveRight(int step = 1);

	/*!
	 * \fn	bool MapController::viewMoveDown(int step = 1);
	 *
	 * \brief	������Ұ
	 *
	 * \param	step	ָ���ƶ�����, Ĭ��Ϊ 1
	 *
	 * \return	�����Ƿ��ƶ��ɹ�
	 */
	bool viewMoveDown(int step = 1);

	/*!
	 * \fn	bool MapController::viewMoveLeft(int step = 1);
	 *
	 * \brief	������Ұ
	 *
	 * \param	step	ָ���ƶ�����, Ĭ��Ϊ 1
	 *
	 * \return	�����Ƿ��ƶ��ɹ�
	 */
	bool viewMoveLeft(int step = 1);

	/*!
	 * \fn	void MapController::updateMapViewMoveRange();
	 *
	 * \brief	���µ�ͼ��Ұ���ƶ���Χ
	 *
	 */
	void updateMapViewMoveRange();
};

#endif
