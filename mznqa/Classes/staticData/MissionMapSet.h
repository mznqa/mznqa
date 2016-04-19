/*!
 * \file	Classes\staticData\MissionMapSet.h
 *
 * \brief	������ MissionMapSet
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_STATICDATA_MISSIONMAPSET_H_
#define MZNQA_CLASSES_STATICDATA_MISSIONMAPSET_H_

#include <vector>

#include "map/MissionMap.h"

/*!
 * \class	MissionMapSet
 *
 * \brief	���������ڴ�����������ͼ
 *
 */
class MissionMapSet
{
private:

	/*!
	 * \fn	MissionMapSet::MissionMapSet()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	MissionMapSet()
	{}

	/*!
	 * \fn	MissionMapSet::MissionMapSet(const MissionMapSet &missionMapSet);
	 *
	 * \brief	���صĿ������캯��
	 *
	 * \param	missionMapSet	MissionMapSet ʵ��
	 */
	MissionMapSet(const MissionMapSet &missionMapSet);

	/*!
	 * \fn	MissionMapSet& MissionMapSet::operator=(const MissionMapSet &missionMapSet);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 * \param	missionMapSet	MissionMapSet ʵ��
	 *
	 * \return	MissionMapSet ʵ��
	 */
	MissionMapSet& operator=(const MissionMapSet &missionMapSet);

	/*! \brief	�Ӽ��ϣ�����������������ͼ */
	std::vector<MissionMap> mainMissionMapSet;
	/*! \brief	�Ӽ��ϣ��������֧�������ͼ */
	std::vector<MissionMap> sideMissionMapSet;

	/*! \brief	Ԥ����Ŀյ������ͼ */
	static const MissionMap nullMissionMap;

public:

	/*!
	 * \fn	static MissionMapSet* MissionMapSet::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 * \return	���ص���
	 */
	static MissionMapSet* Instance();

	/*!
	 * \fn	MissionMapSet::~MissionMapSet()
	 *
	 * \brief	��������
	 *
	 */
	~MissionMapSet()
	{}

	/*!
	 * \fn	void MissionMapSet::loadMainMissionMapSet(std::vector<MissionMap> &mainMissionMapSet);
	 *
	 * \brief	�������������ͼ����
	 *
	 * \param [in,out]	mainMissionMapSet	ָ������������������ͼ�ļ���
	 */
	void loadMainMissionMapSet(std::vector<MissionMap> &mainMissionMapSet);

	/*!
	 * \fn	void MissionMapSet::loadSideMissionMapSet(std::vector<MissionMap> &sideMissionMapSet);
	 *
	 * \brief	����֧�������ͼ����
	 *
	 * \param [in,out]	sideMissionMapSet	ָ���������֧�������ͼ����
	 */
	void loadSideMissionMapSet(std::vector<MissionMap> &sideMissionMapSet);

	/*!
	 * \fn	const MissionMap& MissionMapSet::getMainMissionMapByIndex(int index)const
	 *
	 * \brief	���ݸ�����������ȡ���������ͼ
	 *
	 * \param	index	ָ�����������ͼ������
	 *
	 * \return	���ظ���������Ӧ�����������ͼ
	 */
	const MissionMap& getMainMissionMapByIndex(int index)const
	{
		if (0 <= index && index < (int)mainMissionMapSet.size())
			return mainMissionMapSet.at(index);
		else
			return nullMissionMap;
	}

	/*!
	 * \fn	const MissionMap& MissionMapSet::getSideMissionMapByIndex(int index)const
	 *
	 * \brief	���ݸ�����������ȡ֧�������ͼ
	 *
	 * \param	index	ָ��֧�������ͼ������
	 *
	 * \return	���ظ���������Ӧ��֧�������ͼ
	 */
	const MissionMap& getSideMissionMapByIndex(int index)const
	{
		if (0 <= index && index < (int)sideMissionMapSet.size())
			return sideMissionMapSet.at(index);
		else
			return nullMissionMap;
	}
};

#endif
