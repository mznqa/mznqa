/*!
 * \file	Classes\common\arkca\stringTable\StringTable.cpp
 *
 * \brief	¶¨ÒåÀà ArKCa::StringTable
 */

#pragma execution_character_set("utf-8")

#include "common/arkca/stringTable/StringTable.h"

ArKCa::StringTable::StringTable(const ArKCa::StringTable &stringTable) :
strTable(stringTable.getIteratorBegin(), stringTable.getIteratorEnd())
{
}

ArKCa::StringTable& ArKCa::StringTable::operator=(const ArKCa::StringTable &stringTable)
{
	this->strTable.clear();
	auto it = stringTable.getIteratorBegin();
	auto itEnd = stringTable.getIteratorEnd();
	while (it != itEnd)
	{
		this->strTable.insert(std::pair<int, std::string>(
			it->first,
			it->second
			));
		++it;
	}
	return *this;
}

void ArKCa::StringTable::insert(int key, const std::string &value)
{
	this->strTable.insert(std::pair<int, std::string>(
		key,
		value
		));
}
const std::string *const ArKCa::StringTable::get(int key)const
{
	if (strTable.find(key) == strTable.end())
		return nullptr;
	else
		return &(strTable.at(key));
}
void ArKCa::StringTable::clear()
{
	strTable.clear();
}
const std::map<int, std::string>::const_iterator ArKCa::StringTable::getIteratorBegin()const
{
	return strTable.cbegin();
}
const std::map<int, std::string>::const_iterator ArKCa::StringTable::getIteratorEnd()const
{
	return strTable.cend();
}
void ArKCa::StringTable::getIterator(
	std::map<int, std::string>::const_iterator &begin,
	std::map<int, std::string>::const_iterator &end
	)const
{
	begin = strTable.cbegin();
	end = strTable.cend();
}