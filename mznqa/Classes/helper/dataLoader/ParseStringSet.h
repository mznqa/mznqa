/*!
 * \file	Classes\helper\dataLoader\ParseStringSet.h
 *
 * \brief	定义类 ParseStringSet
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_HELPER_DATALOADER_PARSESTRINGSET_H_
#define MZNQA_CLASSES_HELPER_DATALOADER_PARSESTRINGSET_H_

#include <map>
#include <string>

/*!
 * \class	ParseStringSet
 *
 * \brief	用于解析字符串集合文件
 *
 */
class ParseStringSet
{
private:

	/*!
	 * \fn	ParseStringSet::ParseStringSet()
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	ParseStringSet()
	{
	}

	/*!
	 * \fn	ParseStringSet::ParseStringSet(const ParseStringSet &parseStringSet);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 */
	ParseStringSet(const ParseStringSet &parseStringSet);

	/*!
	 * \fn	ParseStringSet& ParseStringSet::operator=(const ParseStringSet &parseStringSet);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 */
	ParseStringSet& operator=(const ParseStringSet &parseStringSet);
public:

	/*!
	 * \fn	ParseStringSet::~ParseStringSet()
	 *
	 * \brief	析构函数
	 *
	 */
	~ParseStringSet()
	{
	}

	/*!
	 * \fn	static bool ParseStringSet::parse(const char *const data);
	 *
	 * \brief	执行解析
	 *
	 * \param	data	指定文件数据
	 *
	 * \return	返回是否解析成功
	 */
	static bool parse(const char *const data);

	/*! \brief	缓存解析后的数据 */
	static std::map<int, std::string> bufferStringSet;
};
#endif
