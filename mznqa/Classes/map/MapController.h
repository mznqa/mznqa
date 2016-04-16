/*!
 * \file	Classes\map\MapController.h
 *
 * \brief	��ͼ������
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
 * \brief	������ȫ�ֵ�ͼ������
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
	MapController();

	/*!
	 * \fn	MapController::MapController(const MapController &mapController);
	 *
	 * \brief	���صĿ������캯��
	 *
	 * \param	mapController	MapController ʵ��
	 */
	MapController(const MapController &mapController);

	/*!
	 * \fn	MapController& MapController::operator=(const MapController &mapController);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 * \param	mapController	MapController ʵ��
	 *
	 * \return	MapController ʵ��
	 */
	MapController& operator=(const MapController &mapController);

	/*! \brief	��ͼ�ڵ㼯�� */
	std::vector<std::vector<MapNode>> mapNodeSet;
public:

	/*! \brief	��ͼ��ͼ */
	MapView *mapView = nullptr;

	/*! \brief	��ͼ����ڵ��ܸ��� */
	static const int mapNodecountHorizontal = 60;
	/*! \brief	��ͼ����ڵ��ܸ��� */
	static const int mapNodecountVertical = 30;

	/*!
	 * \fn	static MapController* MapController::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 * \return	���ص���
	 */
	static MapController* Instance();

	/*!
	 * \fn	MapController::~MapController();
	 *
	 * \brief	��������
	 *
	 */
	~MapController();

	/*!
	 * \fn	void MapController::createMap()
	 *
	 * \brief	�����ɵ�ͼ����Ϊһ�ſյ�ͼ
	 *
	 */
	void setEmptyMap();

	/*!
	 * \fn	void MapController::loadMapNode(const MissionMap &missionMap);
	 *
	 * \brief	�����ͼ�ڵ㼯��
	 *
	 * \param [in,out]	missionMap	��ͼ�ڵ㼯��ʵ��
	 */
	void loadMapNode(const MissionMap &missionMap);

	/*!
	 * \fn	const std::vector<std::vector<MapNode> >& MapController::getMapNodeSet()
	 *
	 * \brief	��ȡ��ͼ�ڵ㼯��
	 *
	 * \return	���ص�ͼ�ڵ㼯�ϵĳ�������
	 */
	const std::vector<std::vector<MapNode> >& getMapNodeSet()
	{
		return mapNodeSet;
	}
};

#endif
