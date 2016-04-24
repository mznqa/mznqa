/*!
 * \file	Classes\dataHandle\ParserMapMissionMain.h
 *
 * \brief	定义类 ParserMapMissionMain
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_DATAHANDLE_PARSERMAPMISSIONMAIN_H_
#define MZNQA_CLASSES_DATAHANDLE_PARSERMAPMISSIONMAIN_H_

#include <vector>

#include "map/MissionMap.h"

/*!
 * \class	ParserMapMissionMain
 *
 * \brief	用于解析主线任务地图集合
 *
 */
class ParserMapMissionMain
{
private:
public:

	/*!
	 * \fn	ParserMapMissionMain::ParserMapMissionMain()
	 *
	 * \brief	构造函数
	 *
	 */
	ParserMapMissionMain()
	{
	}

	/*!
	 * \fn	ParserMapMissionMain::~ParserMapMissionMain()
	 *
	 * \brief	析构函数
	 *
	 */
	~ParserMapMissionMain()
	{
	}

	/*!
	 * \fn	void ParserMapMissionMain::parse();
	 *
	 * \brief	解析
	 *
	 */
	void parse();

	/*! \brief	用于临时存放的主线任务地图集合 */
	static std::vector<MissionMap> mainMissionMapSetTemp;
};

#endif
