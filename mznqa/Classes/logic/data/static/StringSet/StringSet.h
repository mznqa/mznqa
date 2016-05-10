/*!
 * \file	Classes\logic\data\static\StringSet\StringSet.h
 *
 * \brief	定义类 StringSet
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_DATA_STATIC_STRINGTABLE_STRINGSET_H_
#define MZNQA_CLASSES_LOGIC_DATA_STATIC_STRINGTABLE_STRINGSET_H_

#include <string>

#include "common/arkca/stringTable/StringTable.h"

/*!
 * \class	StringSet
 *
 * \brief	静态数据，字符串集合
 *
 */
class StringSet
{
public:

	/*!
	 * \fn	StringSet::~StringSet()
	 *
	 * \brief	析构函数
	 *
	 */
	~StringSet()
	{
	}

	/*!
	 * \fn	static StringSet* StringSet::Instance();
	 *
	 * \brief	获取单例
	 *
	 */
	static StringSet* Instance();

	/*!
	 * \enum	StringID
	 *
	 * \brief	枚举指向指定字符串的ID
	 */
	enum StringID
	{
		StringID_Null = 0,		///< 空字符串
		StringID_GameName = 1	///< 游戏名称
	};

	/*!
	 * \fn	void StringSet::init(const std::map<int, std::string> &stringSet);
	 *
	 * \brief	初始化字符表
	 *
	 * \param	stringSet	指定外部字符表以载入
	 */
	void init(const std::map<int, std::string> &stringSet);

	/*!
	 * \fn	void StringSet::clear();
	 *
	 * \brief	清空字符串集合
	 *
	 */
	void clear();

	/*!
	 * \fn	const std::string *const StringSet::getString(StringID stringID);
	 *
	 * \brief	获取指定ID对应的字符串
	 *
	 * \param	stringID	指定字符串ID
	 *
	 */
	const std::string *const getString(StringID stringID);

private:

	/*!
	 * \fn	StringSet::StringSet()
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	StringSet()
	{
	}

	/*!
	 * \fn	StringSet::StringSet(const StringSet &stringSet);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 */
	StringSet(const StringSet &stringSet);

	/*!
	 * \fn	StringSet& StringSet::operator=(const StringSet &stringSet);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 */
	StringSet& operator=(const StringSet &stringSet);

	/*! \brief	内建字符串表 */
	ArKCa::StringTable stringTable;
};

#endif
