/*!
 * \file	Classes\logic\data\static\missionMap\MissionMapSet.h
 *
 * \brief	定义类 MissionMapSet
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_DATA_STATIC_MISSIONMAP_MISSIONMAPSET_H_
#define MZNQA_CLASSES_LOGIC_DATA_STATIC_MISSIONMAP_MISSIONMAPSET_H_

#include <map>

#include "logic/gameObject/map/GameMap.h"

/*!
 * \class	MissionMapSet
 *
 * \brief	[单例]存放任务地图
 *
 */
class MissionMapSet
{
public:

	/*!
	 * \fn	MissionMapSet::~MissionMapSet()
	 *
	 * \brief	析构函数
	 *
	 */
	~MissionMapSet()
	{
	}

	/*!
	 * \fn	static MissionMapSet* MissionMapSet::Instance();
	 *
	 * \brief	获取单例
	 *
	 */
	static MissionMapSet* Instance();

	/*!
	 * \enum	MissionMapIDMain
	 *
	 * \brief	枚举主线任务图ID
	 */
	enum MissionMapIDMain
	{
		MissionMapIDMain_0
	};

	/*!
	 * \enum	MissionMapIDSecondary
	 *
	 * \brief	枚举支线任务图ID
	 */
	enum MissionMapIDSecondary
	{
	};

	/*!
	 * \fn	void MissionMapSet::loadMapMain(MissionMapIDMain id, const GameMap &gameMap);
	 *
	 * \brief	载入主线地图
	 *
	 * \param	id	   	指定主线地图ID
	 * \param	gameMap	指定主线地图
	 */
	void loadMapMain(MissionMapIDMain id, const GameMap &gameMap);

	/*!
	 * \fn	void MissionMapSet::loadMapSecondary(MissionMapIDSecondary id, const GameMap &gameMap);
	 *
	 * \brief	载入支线地图
	 *
	 * \param	id	   	指定支线地图ID
	 * \param	gameMap	指定直线地图
	 */
	void loadMapSecondary(MissionMapIDSecondary id, const GameMap &gameMap);

	/*!
	 * \fn	const GameMap *const MissionMapSet::getMapMain(MissionMapIDMain id)const;
	 *
	 * \brief	根据ID获取主线任务图
	 *
	 * \param	id	指定主线任务图ID
	 *
	 */
	const GameMap *const getMapMain(MissionMapIDMain id)const;

	/*!
	 * \fn	const GameMap *const MissionMapSet::getMapSecondary(MissionMapIDSecondary id)const;
	 *
	 * \brief	根据ID获取支线任务图
	 *
	 * \param	id	指定支线任务图ID
	 *
	 */
	const GameMap *const getMapSecondary(MissionMapIDSecondary id)const;
private:

	/*!
	 * \fn	MissionMapSet::MissionMapSet()
	 *
	 * \brief	隐藏的默认构造函数
	 *
	 */
	MissionMapSet()
	{
	}

	/*!
	 * \fn	MissionMapSet::MissionMapSet(const MissionMapSet &missionMapSet);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 */
	MissionMapSet(const MissionMapSet &missionMapSet);

	/*!
	 * \fn	MissionMapSet& MissionMapSet::operator=(const MissionMapSet &missionMapSet);
	 *
	 * \brief	隐藏的拷贝复制运算符
	 *
	 */
	MissionMapSet& operator=(const MissionMapSet &missionMapSet);

	/*! \brief	内建主线任务地图容器 */
	std::map<MissionMapIDMain, GameMap> mainSet;
	/*! \brief	内建支线任务地图容器 */
	std::map<MissionMapIDSecondary, GameMap> secondarySet;
};

#endif
