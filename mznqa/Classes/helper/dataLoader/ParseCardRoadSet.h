/*!
 * \file	Classes\helper\dataLoader\ParseCardRoadSet.h
 *
 * \brief	定义类 ParseCardRoadSet
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_HELPER_DATALOADER_PARSECARDROADSET_H_
#define MZNQA_CLASSES_HELPER_DATALOADER_PARSECARDROADSET_H_

#include <vector>
#include <map>

#include "logic/gameObject/card/CardRoad.h"

/*!
 * \class	ParseCardRoadSet
 *
 * \brief	用于解析地形卡集合
 *
 */
class ParseCardRoadSet
{
private:

	/*!
	 * \fn	ParseCardRoadSet::ParseCardRoadSet()
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	ParseCardRoadSet()
	{
	}

	/*!
	 * \fn	ParseCardRoadSet::ParseCardRoadSet(const ParseCardRoadSet &parseCardRoadSet);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 */
	ParseCardRoadSet(const ParseCardRoadSet &parseCardRoadSet);

	/*!
	 * \fn	ParseCardRoadSet& ParseCardRoadSet::operator=(const ParseCardRoadSet &parseCardRoadSet);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 */
	ParseCardRoadSet& operator=(const ParseCardRoadSet &parseCardRoadSet);
public:

	/*!
	 * \fn	ParseCardRoadSet::~ParseCardRoadSet()
	 *
	 * \brief	析构函数
	 *
	 */
	~ParseCardRoadSet()
	{
	}

	/*!
	 * \fn	static bool ParseCardRoadSet::parse(const char *const data);
	 *
	 * \brief	执行解析
	 *
	 * \param	data	指定文件数据
	 *
	 * \return	返回解析成功与否
	 */
	static bool parse(const char *const data);

	/*! \brief	缓存解析结果 */
	static std::map<int, CardRoad> bufferCardRoadSet;
};

#endif
