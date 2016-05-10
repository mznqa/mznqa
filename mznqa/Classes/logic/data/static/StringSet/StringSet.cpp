/*!
 * \file	Classes\logic\data\static\StringSet\StringSet.cpp
 *
 * \brief	∂®“Â¿‡ StringSet
 */

#pragma execution_character_set("utf-8")

#include "logic/data/static/StringSet/StringSet.h"

StringSet* StringSet::Instance()
{
	static StringSet instance;
	return &instance;
}

void StringSet::init(const std::map<int, std::string> &stringSet)
{
	auto it = stringSet.cbegin();
	auto itEnd = stringSet.cend();
	while (it != itEnd)
	{
		stringTable.insert(it->first, it->second);
		++it;
	}
}

void StringSet::clear()
{
	stringTable.clear();
}

const std::string *const StringSet::getString(StringID stringID)
{
	return stringTable.get(stringID);
}