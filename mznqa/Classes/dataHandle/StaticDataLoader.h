/*!
 * \file	Classes\dataHandle\StaticDataLoader.h
 *
 * \brief	定义类 StaticDataLoader
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_DATAHANDLE_STATICDATALOADER_H_
#define MZNQA_CLASSES_DATAHANDLE_STATICDATALOADER_H_

/*!
 * \class	StaticDataLoader
 *
 * \brief	用于载入静态文件数据
 *
 */
class StaticDataLoader
{
private:

	/*!
	 * \fn	StaticDataLoader::StaticDataLoader()
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	StaticDataLoader(){}
public:

	/*!
	 * \fn	StaticDataLoader::~StaticDataLoader()
	 *
	 * \brief	析构函数
	 *
	 */
	~StaticDataLoader(){}

	/*!
	 * \fn	static void StaticDataLoader::loadStaticDataCardRoadSet();
	 *
	 * \brief	载入静态数据：地形卡集合
	 *
	 */
	static void loadStaticDataCardRoadSet();

	/*!
	 * \fn	static void StaticDataLoader::loadStaticDataCardSkillSet();
	 *
	 * \brief	载入静态数据：技能卡集合
	 *
	 */
	static void loadStaticDataCardSkillSet();
};

#endif