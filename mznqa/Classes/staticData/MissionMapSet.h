/*!
 * \file	Classes\staticData\MissionMapSet.h
 *
 * \brief	定义类 MissionMapSet
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_STATICDATA_MISSIONMAPSET_H_
#define MZNQA_CLASSES_STATICDATA_MISSIONMAPSET_H_

#include <vector>

#include "map/MissionMap.h"

/*!
 * \class	MissionMapSet
 *
 * \brief	单例。用于存放所有任务地图
 *
 */
class MissionMapSet
{
private:

	/*!
	 * \fn	MissionMapSet::MissionMapSet()
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	MissionMapSet()
	{}

	/*!
	 * \fn	MissionMapSet::MissionMapSet(const MissionMapSet &missionMapSet);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 * \param	missionMapSet	MissionMapSet 实例
	 */
	MissionMapSet(const MissionMapSet &missionMapSet);

	/*!
	 * \fn	MissionMapSet& MissionMapSet::operator=(const MissionMapSet &missionMapSet);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 * \param	missionMapSet	MissionMapSet 实例
	 *
	 * \return	MissionMapSet 实例
	 */
	MissionMapSet& operator=(const MissionMapSet &missionMapSet);

	/*! \brief	子集合：存放所有主线任务地图 */
	std::vector<MissionMap> mainMissionMapSet;
	/*! \brief	子集合：存放所有支线任务地图 */
	std::vector<MissionMap> sideMissionMapSet;

	/*! \brief	预定义的空的任务地图 */
	static const MissionMap nullMissionMap;

public:

	/*!
	 * \fn	static MissionMapSet* MissionMapSet::Instance();
	 *
	 * \brief	获取单例
	 *
	 * \return	返回单例
	 */
	static MissionMapSet* Instance();

	/*!
	 * \fn	MissionMapSet::~MissionMapSet()
	 *
	 * \brief	析构函数
	 *
	 */
	~MissionMapSet()
	{}

	/*!
	 * \fn	void MissionMapSet::loadMainMissionMapSet(std::vector<MissionMap> &mainMissionMapSet);
	 *
	 * \brief	载入主线任务地图集合
	 *
	 * \param [in,out]	mainMissionMapSet	指定待载入的主线任务地图的集合
	 */
	void loadMainMissionMapSet(std::vector<MissionMap> &mainMissionMapSet);

	/*!
	 * \fn	void MissionMapSet::loadSideMissionMapSet(std::vector<MissionMap> &sideMissionMapSet);
	 *
	 * \brief	载入支线任务地图集合
	 *
	 * \param [in,out]	sideMissionMapSet	指定待载入的支线任务地图集合
	 */
	void loadSideMissionMapSet(std::vector<MissionMap> &sideMissionMapSet);

	/*!
	 * \fn	const MissionMap& MissionMapSet::getMainMissionMapByIndex(int index)const
	 *
	 * \brief	根据给定的索引获取主线任务地图
	 *
	 * \param	index	指定主线任务地图的索引
	 *
	 * \return	返回给定索引对应的主线任务地图
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
	 * \brief	根据给定的索引获取支线任务地图
	 *
	 * \param	index	指定支线任务地图的索引
	 *
	 * \return	返回给定索引对应的支线任务地图
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
