/*!
 * \file	Classes\dataHandle\ParserMapArchives.h
 *
 * \brief	定义类 ParserMapArchives
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_DATAHANDLE_PARSERMAPARCHIVES_H_
#define MZNQA_CLASSES_DATAHANDLE_PARSERMAPARCHIVES_H_

#include "map/MapNode.h"

/*!
 * \class	ParserMapArchives
 *
 * \brief	用于解析地图存档数据
 *
 */
class ParserMapArchives
{
private:
public:

	/*!
	 * \fn	ParserMapArchives::ParserMapArchives();
	 *
	 * \brief	构造函数
	 *
	 */
	ParserMapArchives();

	/*!
	 * \fn	ParserMapArchives::~ParserMapArchives();
	 *
	 * \brief	析构函数
	 *
	 */
	~ParserMapArchives();

	/*!
	 * \fn	void ParserMapArchives::parse();
	 *
	 * \brief	解析
	 *
	 */
	void parse();

	/*! \brief	暂存全局地图数据 */
	static std::vector<MapNode> globalMapArchivesTemp;
};

#endif
