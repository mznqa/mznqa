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
	 * \fn	const ArKCa::Size<int>& MapController::getMapSize()const
	 *
	 * \brief	��ȡ��ͼ�ߴ���Ϣ
	 *
	 */
	const ArKCa::Size<int>& getMapSize()const
	{
		return gameMap.getSize();
	}

	/*!
	 * \fn	const std::vector<std::vector<MapNode> >& MapController::getMapNodeSet()const
	 *
	 * \brief	��ȡ���е�ͼ�ڵ�
	 *
	 */
	const std::vector<std::vector<MapNode> >& getMapNodeSet()const
	{
		return gameMap.getMapNodeSet();
	}

	/*!
	 * \fn	const ArKCa::Vector2<int>& MapController::getViewOrigin()const
	 *
	 * \brief	��ȡ��ͼ��Ұԭ��
	 *
	 */
	const ArKCa::Vector2<int>& getViewOrigin()const
	{
		return mapView.getViewOrigin();
	}

	/*!
	 * \fn	const ArKCa::Size<int>& MapController::getViewSize()const
	 *
	 * \brief	��ȡ��Ұ�ߴ�
	 *
	 */
	const ArKCa::Size<int>& getViewSize()const
	{
		return mapView.getViewSize();
	}

	/*!
	 * \fn	void MapController::viewMoveUp(int step);
	 *
	 * \brief	������Ұ
	 *
	 * \param	step	ָ���ƶ�����
	 */
	void viewMoveUp(int step);

	/*!
	 * \fn	void MapController::viewMoveRight(int step);
	 *
	 * \brief	������Ұ
	 *
	 * \param	step	ָ���ƶ�����
	 */
	void viewMoveRight(int step);

	/*!
	 * \fn	void MapController::viewMoveDown(int step);
	 *
	 * \brief	������Ұ
	 *
	 * \param	step	ָ���ƶ�����
	 */
	void viewMoveDown(int step);

	/*!
	 * \fn	void MapController::viewMoveLeft(int step);
	 *
	 * \brief	������Ұ
	 *
	 * \param	step	ָ���ƶ�����
	 */
	void viewMoveLeft(int step);
};

#endif
