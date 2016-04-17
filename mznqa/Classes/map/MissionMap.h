/*!
 * \file	Classes\map\MissionMap.h
 *
 * \brief	������ MissionMap
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MAP_MISSIONMAP_H_
#define MZNQA_CLASSES_MAP_MISSIONMAP_H_

#include <vector>

#include "map/MapNode.h"

/*!
 * \class	MissionMap
 *
 * \brief	�����ͼ
 *
 */
class MissionMap
{
public:
	/*! \brief	������Ч�����ͼ����ֵ */
	static const int invalidIndex = -1;

	/*!
	 * \enum	MapType
	 *
	 * \brief	���������ͼ������
	 */
	enum MapType
	{
		MapType_MainMission = 0,	///< ��������ͼ
		MapType_SideMission = 1		///< ֧������ͼ
	};

	/*!
	 * \fn	MissionMap::MissionMap()
	 *
	 * \brief	���캯��
	 *
	 */
	MissionMap() :
		index(invalidIndex),
		mapType(MapType_MainMission)
	{}

	/*!
	 * \fn	MissionMap::MissionMap(int index, MapType mapType, int width, int height, const std::vector<MapNode> mapNodeSet);
	 *
	 * \brief	���캯��
	 *
	 * \param	index	  	ָ�������ͼ������
	 * \param	mapType   	ָ�������ͼ������
	 * \param	width	  	ָ�������ͼ�Ŀ��
	 * \param	height	  	ָ�������ͼ�ĸ߶�
	 * \param	mapNodeSet	ָ���������������ͼ�ڵ�ĵ�ͼ�ڵ㼯��
	 */
	MissionMap(int index, MapType mapType, int width, int height, const std::vector<MapNode> mapNodeSet);

	/*!
	 * \fn	MissionMap::~MissionMap();
	 *
	 * \brief	��������
	 *
	 */
	~MissionMap();

	/*!
	 * \fn	MapType MissionMap::getMapType()
	 *
	 * \brief	��ȡ����ĵ�ͼ������
	 *
	 * \return	���������ͼ������
	 */
	MapType getMapType()const
	{
		return mapType;
	}

	/*!
	 * \fn	int MissionMap::getWidth()const
	 *
	 * \brief	��ȡ�����ͼ�Ŀ��
	 *
	 * \return	���������ͼ�Ŀ��
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
	 * \brief	��ȡ�����ͼ�ĸ߶�
	 *
	 * \return	��ȡ�����ͼ�ĸ߶�
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
	 * \brief	��ȡ�����ͼ�ĵ�ͼ�ڵ㼯��
	 *
	 * \return	���������ͼ�ĵ�ͼ�ڵ㼯��
	 */
	const std::vector<std::vector<MapNode> >& getMapNodeSet()const
	{
		return mapNodeSet;
	}

private:

	/*! \brief	�����ͼ������ */
	int index;

	/*! \brief	�����ͼ������ */
	MapType mapType;

	/*! \brief	�����ͼ�Ľڵ㼯�� */
	std::vector<std::vector<MapNode>> mapNodeSet;
};

#endif
