/*!
 * \file	Classes\logic\data\static\effectSet\EffectFunSet.cpp
 *
 * \brief	������ EffectFunSet
 */

#pragma execution_character_set("utf-8")

#include "logic/data/static/effectSet/EffectFunSet.h"

const std::map<int, std::function<bool(const std::vector<int>&)>> EffectFunSet::funSet = {
	{ nullEffectIndex, EffectFunSet::effectNull },
	{ 0, EffectFunSet::effectBase0 },
	{ 1, EffectFunSet::effectBase1 },
	{ 2, EffectFunSet::effectBase2 },
	{ 3, EffectFunSet::effectBase3 },
	{ 4, EffectFunSet::effectBase4 },

	{ 1000, EffectFunSet::effectSpecial0 },
	{ 1001, EffectFunSet::effectSpecial1 },
	{ 1002, EffectFunSet::effectSpecial2 },

	{ 2000, EffectFunSet::effectCondition0 },
	{ 2001, EffectFunSet::effectCondition1 },
	{ 2002, EffectFunSet::effectCondition2 },
	{ 2003, EffectFunSet::effectCondition3 },
	{ 2004, EffectFunSet::effectCondition4 },
	{ 2005, EffectFunSet::effectCondition5 },
	{ 2006, EffectFunSet::effectCondition6 },
	{ 2007, EffectFunSet::effectCondition7 },
	{ 2008, EffectFunSet::effectCondition8 },
	{ 2009, EffectFunSet::effectCondition9 },
	{ 2010, EffectFunSet::effectCondition10 },
	{ 2011, EffectFunSet::effectCondition11 },
	{ 2012, EffectFunSet::effectCondition12 },
	{ 2013, EffectFunSet::effectCondition13 }
};

EffectFunSet::~EffectFunSet()
{
}

bool EffectFunSet::effectNull(const std::vector<int> &args)
{
	// nothing to do
	return true;
}

bool EffectFunSet::effectBase0(const std::vector<int> &args)
{
	return true;
}

bool EffectFunSet::effectBase1(const std::vector<int> &args)
{
	return true;
}

bool EffectFunSet::effectBase2(const std::vector<int> &args)
{
	return true;
}

bool EffectFunSet::effectBase3(const std::vector<int> &args)
{
	return true;
}

bool EffectFunSet::effectBase4(const std::vector<int> &args)
{
	return true;
}

bool EffectFunSet::effectSpecial0(const std::vector<int> &args)
{
	return true;
}

bool EffectFunSet::effectSpecial1(const std::vector<int> &args)
{
	return true;
}

bool EffectFunSet::effectSpecial2(const std::vector<int> &args)
{
	return true;
}

bool EffectFunSet::effectCondition0(const std::vector<int> &args)
{
	return true;
}

bool EffectFunSet::effectCondition1(const std::vector<int> &args)
{
	return true;
}

bool EffectFunSet::effectCondition2(const std::vector<int> &args)
{
	return true;
}

bool EffectFunSet::effectCondition3(const std::vector<int> &args)
{
	return true;
}

bool EffectFunSet::effectCondition4(const std::vector<int> &args)
{
	return true;
}

bool EffectFunSet::effectCondition5(const std::vector<int> &args)
{
	return true;
}

bool EffectFunSet::effectCondition6(const std::vector<int> &args)
{
	return true;
}

bool EffectFunSet::effectCondition7(const std::vector<int> &args)
{
	return true;
}

bool EffectFunSet::effectCondition8(const std::vector<int> &args)
{
	return true;
}

bool EffectFunSet::effectCondition9(const std::vector<int> &args)
{
	return true;
}

bool EffectFunSet::effectCondition10(const std::vector<int> &args)
{
	return true;
}

bool EffectFunSet::effectCondition11(const std::vector<int> &args)
{
	return true;
}

bool EffectFunSet::effectCondition12(const std::vector<int> &args)
{
	return true;
}

bool EffectFunSet::effectCondition13(const std::vector<int> &args)
{
	return true;
}