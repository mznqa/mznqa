/*!
 * \file	Classes\logic\data\static\missionMap\MissionMapSet.h
 *
 * \brief	������ MissionMapSet
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_DATA_STATIC_MISSIONMAP_MISSIONMAPSET_H_
#define MZNQA_CLASSES_LOGIC_DATA_STATIC_MISSIONMAP_MISSIONMAPSET_H_

#include <map>

#include "logic/gameObject/map/GameMap.h"

/*!
 * \class	MissionMapSet
 *
 * \brief	[����]��������ͼ
 *
 */
class MissionMapSet
{
public:

	/*!
	 * \fn	MissionMapSet::~MissionMapSet()
	 *
	 * \brief	��������
	 *
	 */
	~MissionMapSet()
	{
	}

	/*!
	 * \fn	static MissionMapSet* MissionMapSet::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 */
	static MissionMapSet* Instance();

	/*!
	 * \enum	MissionMapIDMain
	 *
	 * \brief	ö����������ͼID
	 */
	enum MissionMapIDMain
	{
		MissionMapIDMain_0
	};

	/*!
	 * \enum	MissionMapIDSecondary
	 *
	 * \brief	ö��֧������ͼID
	 */
	enum MissionMapIDSecondary
	{
	};

	/*!
	 * \fn	void MissionMapSet::loadMapMain(MissionMapIDMain id, const GameMap &gameMap);
	 *
	 * \brief	�������ߵ�ͼ
	 *
	 * \param	id	   	ָ�����ߵ�ͼID
	 * \param	gameMap	ָ�����ߵ�ͼ
	 */
	void loadMapMain(MissionMapIDMain id, const GameMap &gameMap);

	/*!
	 * \fn	void MissionMapSet::loadMapSecondary(MissionMapIDSecondary id, const GameMap &gameMap);
	 *
	 * \brief	����֧�ߵ�ͼ
	 *
	 * \param	id	   	ָ��֧�ߵ�ͼID
	 * \param	gameMap	ָ��ֱ�ߵ�ͼ
	 */
	void loadMapSecondary(MissionMapIDSecondary id, const GameMap &gameMap);

	/*!
	 * \fn	const GameMap *const MissionMapSet::getMapMain(MissionMapIDMain id)const;
	 *
	 * \brief	����ID��ȡ��������ͼ
	 *
	 * \param	id	ָ����������ͼID
	 *
	 */
	const GameMap *const getMapMain(MissionMapIDMain id)const;

	/*!
	 * \fn	const GameMap *const MissionMapSet::getMapSecondary(MissionMapIDSecondary id)const;
	 *
	 * \brief	����ID��ȡ֧������ͼ
	 *
	 * \param	id	ָ��֧������ͼID
	 *
	 */
	const GameMap *const getMapSecondary(MissionMapIDSecondary id)const;
private:

	/*!
	 * \fn	MissionMapSet::MissionMapSet()
	 *
	 * \brief	���ص�Ĭ�Ϲ��캯��
	 *
	 */
	MissionMapSet()
	{
	}

	/*!
	 * \fn	MissionMapSet::MissionMapSet(const MissionMapSet &missionMapSet);
	 *
	 * \brief	���صĿ������캯��
	 *
	 */
	MissionMapSet(const MissionMapSet &missionMapSet);

	/*!
	 * \fn	MissionMapSet& MissionMapSet::operator=(const MissionMapSet &missionMapSet);
	 *
	 * \brief	���صĿ������������
	 *
	 */
	MissionMapSet& operator=(const MissionMapSet &missionMapSet);

	/*! \brief	�ڽ����������ͼ���� */
	std::map<MissionMapIDMain, GameMap> mainSet;
	/*! \brief	�ڽ�֧�������ͼ���� */
	std::map<MissionMapIDSecondary, GameMap> secondarySet;
};

#endif
