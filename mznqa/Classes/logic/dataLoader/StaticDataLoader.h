/*!
 * \file	Classes\logic\dataLoader\StaticDataLoader.h
 *
 * \brief	定义类 StaticDataLoader
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_DATALOADER_STATICDATALOADER_H_
#define MZNQA_CLASSES_DATALOADER_STATICDATALOADER_H_

/*!
 * \class	StaticDataLoader
 *
 * \brief	用于载入静态数据
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
	StaticDataLoader()
	{
	}

	/*!
	 * \fn	StaticDataLoader::StaticDataLoader(const StaticDataLoader &staticDataLoader);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 */
	StaticDataLoader(const StaticDataLoader &staticDataLoader);

	/*!
	 * \fn	StaticDataLoader& StaticDataLoader::operator=(const StaticDataLoader &staticDataLoader);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 */
	StaticDataLoader& operator=(const StaticDataLoader &staticDataLoader);
public:

	/*!
	 * \fn	StaticDataLoader::~StaticDataLoader()
	 *
	 * \brief	析构函数
	 *
	 */
	~StaticDataLoader()
	{
	}

	/*!
	 * \fn	static bool StaticDataLoader::loadStringSet();
	 *
	 * \brief	载入静态数据-字符串集合
	 *
	 * \return	返回是否载入成功
	 */
	static bool loadStringSet();
};

#endif
