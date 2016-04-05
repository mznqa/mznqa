/*!
 * \file	Classes\effect\EffectFunSet.cpp
 *
 * \brief	∂®“Â¿‡ EffectFunSet
 */

#pragma execution_character_set("utf-8")

#include "effect/EffectFunSet.h"

#include "cocos2d.h"

const std::array<std::function<bool(const std::vector<int>&)>, EffectFunSet::funCount> EffectFunSet::funSet = {
	EffectFunSet::effectBase0,
	EffectFunSet::effectBase1,
	EffectFunSet::effectBase2,
	EffectFunSet::effectBase3,
	EffectFunSet::effectBase4,

	EffectFunSet::effectSpecial0,
	EffectFunSet::effectSpecial1,
	EffectFunSet::effectSpecial2,

	EffectFunSet::effectCondition0,
	EffectFunSet::effectCondition1,
	EffectFunSet::effectCondition2,
	EffectFunSet::effectCondition3,
	EffectFunSet::effectCondition4,
	EffectFunSet::effectCondition5,
	EffectFunSet::effectCondition6,
	EffectFunSet::effectCondition7,
	EffectFunSet::effectCondition8,
	EffectFunSet::effectCondition9,
	EffectFunSet::effectCondition10,
	EffectFunSet::effectCondition11,
	EffectFunSet::effectCondition12,
	EffectFunSet::effectCondition13
};

EffectFunSet::~EffectFunSet()
{
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