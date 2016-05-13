/*!
 * \file	Classes\logic\data\static\stringSet\StringSet.cpp
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

void StringSet::init(std::map<int, std::string> &stringSet)
{
	stringTable.clear();
	stringTable.swap(stringSet);
}

void StringSet::clear()
{
	stringTable.clear();
}

const std::string *const StringSet::getString(StringID stringID)
{
	return stringTable.get(stringID);
}