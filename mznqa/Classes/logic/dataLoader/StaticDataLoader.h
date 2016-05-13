/*!
 * \file	Classes\logic\dataLoader\StaticDataLoader.h
 *
 * \brief	������ StaticDataLoader
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_DATALOADER_STATICDATALOADER_H_
#define MZNQA_CLASSES_DATALOADER_STATICDATALOADER_H_

#include "logic/data/static/missionMap/MissionMapSet.h"

/*!
 * \class	StaticDataLoader
 *
 * \brief	�������뾲̬����
 *
 */
class StaticDataLoader
{
private:

	/*!
	 * \fn	StaticDataLoader::StaticDataLoader()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	StaticDataLoader()
	{
	}

	/*!
	 * \fn	StaticDataLoader::StaticDataLoader(const StaticDataLoader &staticDataLoader);
	 *
	 * \brief	���صĿ������캯��
	 *
	 */
	StaticDataLoader(const StaticDataLoader &staticDataLoader);

	/*!
	 * \fn	StaticDataLoader& StaticDataLoader::operator=(const StaticDataLoader &staticDataLoader);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	StaticDataLoader& operator=(const StaticDataLoader &staticDataLoader);
public:

	/*!
	 * \fn	StaticDataLoader::~StaticDataLoader()
	 *
	 * \brief	��������
	 *
	 */
	~StaticDataLoader()
	{
	}

	/*!
	 * \fn	static bool StaticDataLoader::loadStringSet();
	 *
	 * \brief	���뾲̬����-�ַ�������
	 *
	 * \return	�����Ƿ�����ɹ�
	 */
	static bool loadStringSet();

	/*!
	 * \fn	static bool StaticDataLoader::loadCardRoadSet();
	 *
	 * \brief	���뾲̬����-���ο�����
	 *
	 * \return	�����Ƿ�����ɹ�
	 */
	static bool loadCardRoadSet();

	/*!
	 * \fn	static bool StaticDataLoader::loadMissionMapMain(MissionMapSet::MissionMapIDMain id);
	 *
	 * \brief	���뾲̬����-���ߵ�ͼ
	 *
	 * \return	�����Ƿ�����ɹ�
	 */
	static bool loadMissionMapMain(MissionMapSet::MissionMapIDMain id);

	/*!
	 * \fn	static bool StaticDataLoader::loadMissionMapSecondary(MissionMapSet::MissionMapIDSecondary id);
	 *
	 * \brief	���뾲̬����-֧�ߵ�ͼ
	 *
	 * \return	�����Ƿ�����ɹ�
	 */
	static bool loadMissionMapSecondary(MissionMapSet::MissionMapIDSecondary id);
};

#endif
