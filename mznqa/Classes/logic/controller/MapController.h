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
		gameMap(nullptr)
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
	GameMap *gameMap;
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
	 * \fn	void MapController::build( const std::vector<MissionMapSet::MissionMapIDMain> &mainIDSet, const std::vector<MissionMapSet::MissionMapIDSecondary> &secondaryIDSet );
	 *
	 * \brief	������ͼ
	 *
	 * \param	mainIDSet	  	ָ�����ߵ�ͼID����
	 * \param	secondaryIDSet	ָ��֧�ߵ�ͼID����
	 */
	void build(
		const std::vector<MissionMapSet::MissionMapIDMain> &mainIDSet,
		const std::vector<MissionMapSet::MissionMapIDSecondary> &secondaryIDSet
		);
};

#endif
