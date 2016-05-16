/*!
 * \file	Classes\common\arkca\stringTable\StringTable.h
 *
 * \brief	定义类 ArKCa::StringTable
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMMON_ARKCA_STRINGTABLE_STRINGTABLE_H_
#define MZNQA_CLASSES_COMMON_ARKCA_STRINGTABLE_STRINGTABLE_H_

#include <map>
#include <string>

namespace ArKCa
{
	/*!
	 * \class	StringTable
	 *
	 * \brief	ID-字符串键值对表
	 *
	 */
	class StringTable
	{
	private:
		/*! \brief	内建ID-字符串键值对 */
		std::map<int, std::string> strTable;
	public:

		/*!
		 * \fn	StringTable::StringTable()
		 *
		 * \brief	默认构造函数
		 *
		 */
		StringTable()
		{
		}

		/*!
		 * \fn	StringTable::StringTable(const StringTable &stringTable);
		 *
		 * \brief	拷贝构造函数
		 *
		 */
		StringTable(const StringTable &stringTable);

		/*!
		 * \fn	StringTable& StringTable::operator=(const StringTable &stringTable);
		 *
		 * \brief	拷贝赋值运算符
		 *
		 */
		StringTable& operator=(const StringTable &stringTable);

		/*!
		 * \fn	StringTable::~StringTable()
		 *
		 * \brief	析构函数
		 *
		 */
		~StringTable()
		{
		}

		/*!
		 * \fn	void StringTable::swap(std::map<int, std::string> &stringTable)
		 *
		 * \brief	从外部转换字符串表
		 *
		 * \param [in,out]	stringTable	外界ID-字符串键值对表
		 */
		void swap(std::map<int, std::string> &stringTable)
		{
			this->clear();
			this->strTable.swap(stringTable);
		}

		/*!
		 * \fn	void StringTable::insert(int key, const std::string &value);
		 *
		 * \brief	插入字符键值对
		 *
		 * \param	key  	指定键
		 * \param	value	指定值
		 */
		void insert(int key, const std::string &value);

		/*!
		 * \fn	const std::string *const StringTable::get(int key)const;
		 *
		 * \brief	获取指定键对应的值
		 *
		 * \param	key	指定键
		 *
		 * \return	返回对应的值
		 */
		const std::string *const get(int key)const;

		/*!
		 * \fn	void StringTable::clear();
		 *
		 * \brief	清空表
		 *
		 */
		void clear();

		/*!
		 * \fn	const std::map<int, std::string>::const_iterator StringTable::getIteratorBegin()const;
		 *
		 * \brief	获取键值对表的起始迭代器
		 *
		 */
		const std::map<int, std::string>::const_iterator getIteratorBegin()const;

		/*!
		 * \fn	const std::map<std::string, std::string>::const_iterator StringTable::getIteratorEnd()const;
		 *
		 * \brief	获取键值对表的终止迭代器
		 *
		 */
		const std::map<int, std::string>::const_iterator getIteratorEnd()const;

		/*!
		 * \fn	void StringTable::getIterator( std::map<int, std::string>::const_iterator &begin, std::map<int, std::string>::const_iterator &end )const;
		 *
		 * \brief	返回键值对表的起始和终止迭代器
		 *
		 * \param	begin	指定用于接收起始迭代器
		 * \param	end  	指定用于接收终止迭代器
		 */
		void getIterator(
			std::map<int, std::string>::const_iterator &begin,
			std::map<int, std::string>::const_iterator &end
			)const;
	};
}

#endif