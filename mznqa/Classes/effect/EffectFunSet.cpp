/*!
 * \file	Classes\effect\EffectFunSet.cpp
 *
 * \brief	������ EffectFunSet
 */

#pragma execution_character_set("utf-8")

#include "effect/EffectFunSet.h"
#include "cocos2d.h"

const std::function<bool(const std::vector<int>&)> EffectFunSet::nullFun = EffectFunSet::effectNullFun;

const std::map<int, std::function<bool(const std::vector<int>&)>> EffectFunSet::funSet = {
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

bool EffectFunSet::effectBase0(const std::vector<int> &args)
{
	cocos2d::log("[information] ʹ��Ч����%d Ѫ",args.at(2));
	return true;
}

bool EffectFunSet::effectBase1(const std::vector<int> &args)
{
	cocos2d::log("[information] ʹ��Ч����%d ��",args.at(2));
	return true;
}

bool EffectFunSet::effectBase2(const std::vector<int> &args)
{
	cocos2d::log("[information] ʹ��Ч���� %d ����",args.at(2));
	return true;
}

bool EffectFunSet::effectBase3(const std::vector<int> &args)
{
	cocos2d::log("[information] ʹ��Ч����effectBase3");
	return true;
}

bool EffectFunSet::effectBase4(const std::vector<int> &args)
{
	cocos2d::log("[information] ʹ��Ч������ %d ����",args.at(2));
	return true;
}

bool EffectFunSet::effectSpecial0(const std::vector<int> &args)
{
	cocos2d::log("[information] ʹ��Ч���� ������Ч");
	return true;
}

bool EffectFunSet::effectSpecial1(const std::vector<int> &args)
{
	cocos2d::log("[information] ʹ��Ч������Ѫ��Ч");
	return true;
}

bool EffectFunSet::effectSpecial2(const std::vector<int> &args)
{
	cocos2d::log("[information] ʹ��Ч�����ؼ���Ч");
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
	
	cocos2d::log("[information] ʹ��Ч��������з�Ѫ����[%d, ������]",args.at(2));
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
	cocos2d::log("[information] ʹ��Ч�������Ѫ����[%d,%d]֮��", args.at(2),args.at(3));
	return true;
}

bool EffectFunSet::effectCondition13(const std::vector<int> &args)
{
	cocos2d::log("[information] ʹ��Ч�����������Ѫ������ || Ѫ����һ����[�����0]֮��");
	return true;
}