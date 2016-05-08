/*!
 * \file	Classes\effect\EffectFunSet.cpp
 *
 * \brief	定义类 EffectFunSet
 */

#pragma execution_character_set("utf-8")

#include "effect/EffectFunSet.h"
#include "combatSystem/DeltaTable.h"
#include "effect/Effect.h"
#include "cocos2d.h"

const std::function<bool(const std::vector<int> &args)> EffectFunSet::nullFun = EffectFunSet::effectNullFun;

const std::map<int, std::function<bool(const std::vector<int> &args)>> EffectFunSet::funSet = {
	{ 0, EffectFunSet::effectBase0 },
	{ 1, EffectFunSet::effectBase1 },
	{ 2, EffectFunSet::effectBase2 },
	{ 3, EffectFunSet::effectBase3 },
	{ 4, EffectFunSet::effectBase4 },
	{ 5, EffectFunSet::effectBase5 },

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
	{ 2013, EffectFunSet::effectCondition13 },
	{ 2014,	EffectFunSet::effectCondition14 },
	{ 2015,	EffectFunSet::effectCondition15 }
};

CombatSystemInterface* const EffectFunSet::combatSystemInterface = CombatSystemInterface::Instance();

EffectFunSet::~EffectFunSet()
{
}

bool EffectFunSet::effectBase0(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果：%d 血",args.at(2));
	DeltaTable dtTemp;
	dtTemp.setEffectHistoryInfo(combatSystemInterface->getCurrentEffectAffixes());
	dtTemp.setEffectTableBlood(args.at(2));
	dtTemp.addHistoryEffect();
	return true;
}

bool EffectFunSet::effectBase1(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果：%d 甲", args.at(2));
	DeltaTable dtTemp;
	dtTemp.setEffectHistoryInfo(combatSystemInterface->getCurrentEffectAffixes());
	dtTemp.setEffectTableArmor(args.at(2));
	dtTemp.addHistoryEffect();

	return true;
}

bool EffectFunSet::effectBase2(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果： %d 手牌",args.at(2));
	DeltaTable dtTemp;
	dtTemp.setEffectHistoryInfo(combatSystemInterface->getCurrentEffectAffixes());
	dtTemp.setEffectTableHandCardCount(args.at(2));
	dtTemp.addHistoryEffect();

	return true;
}

bool EffectFunSet::effectBase3(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果：抽 %d 张牌",args.at(2));
	DeltaTable dtTemp;
	dtTemp.setEffectHistoryInfo(combatSystemInterface->getCurrentEffectAffixes());
	dtTemp.setEffectTableDrawCardCount(args.at(2));
	dtTemp.addHistoryEffect();

	return true;
}

bool EffectFunSet::effectBase4(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果：出 %d 张牌", args.at(2));
	DeltaTable dtTemp;
	dtTemp.setEffectHistoryInfo(combatSystemInterface->getCurrentEffectAffixes());
	dtTemp.setEffectTableDiscardCount(args.at(2));
	dtTemp.addHistoryEffect();

	return true;
}

bool EffectFunSet::effectBase5(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果：回满血");
	DeltaTable dtTemp;
	dtTemp.setEffectHistoryInfo(combatSystemInterface->getCurrentEffectAffixes());
	dtTemp.setEffectTableBlood(combatSystemInterface->getBloodMaxRole());
	dtTemp.addHistoryEffect();

	return true;
}

bool EffectFunSet::effectSpecial0(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果： 攻击无效");
	DeltaTable dtTemp;
	dtTemp.setEffectHistoryInfo(combatSystemInterface->getCurrentEffectAffixes());

	int roundTemp = combatSystemInterface->getCurrentEffectAffixes().efRound;
	int deltaBlood = 0;
	int bloodTemp = 0;
	auto itMonsterBegin = combatSystemInterface->getDeltaTableMonsterInCurrentRound().begin();
	auto itMonsterEnd = combatSystemInterface->getDeltaTableMonsterInCurrentRound().end();
	switch (combatSystemInterface->getCurrentEffectAffixes().releaser)
	{
	case EffectAffixes::Releaser::Releaser_Role:
		
		for (; itMonsterBegin != itMonsterEnd; ++itMonsterBegin)
		{
			bloodTemp = itMonsterBegin->effectTable[0][0];
			if (bloodTemp < 0)
			{
				deltaBlood += bloodTemp;
			}
		}
		if (deltaBlood < 0)
		{
			dtTemp.effectTable[0][0] = -deltaBlood;
		}
		combatSystemInterface->getDeltaTableHistory().addTableHistoryRole(dtTemp);
		break;
	case EffectAffixes::Releaser::Releaser_Monster:
		auto itRoleBegin = combatSystemInterface->getDeltaTableRoleInCurrentRound().begin();
		auto itRoleEnd = combatSystemInterface->getDeltaTableRoleInCurrentRound().end();
		for (; itRoleBegin != itRoleEnd; ++itRoleBegin)
		{
			bloodTemp = itRoleBegin->effectTable[0][1];
			if (bloodTemp < 0)
			{
				deltaBlood += bloodTemp;
			}
		}
		if (deltaBlood < 0)
		{
			dtTemp.effectTable[0][1] = -deltaBlood;
		}
		combatSystemInterface->getDeltaTableHistory().addTableHistoryMonster(dtTemp);
		break;
	}
	return true;
}

bool EffectFunSet::effectSpecial1(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果：回血无效");

	return true;
}

bool EffectFunSet::effectSpecial2(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果：回甲无效");

	return true;
}

bool EffectFunSet::effectCondition0(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果：当前的血量处于[%d,%d]之间",args.at(2),args.at(3));
	int bloodTemp = 0;
	int leftBlood = args.at(2);
	int rightBlood =args.at(3);

	
	return false;
}

bool EffectFunSet::effectCondition1(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果：当前的血量处于[1,%d]之间",args.at(2));

	int bloodTemp = 0;
	int rightBlood = args.at(2);

	
	return false;
}

bool EffectFunSet::effectCondition2(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果：当前的血量等于[%d]",args.at(2));
	

	return false;
}

bool EffectFunSet::effectCondition3(const std::vector<int> &args)
{

	cocos2d::log("[information] 使用效果：如果敌方血量在[%d, 正无穷]",args.at(2));

	int bloodTemp = combatSystemInterface->getBloodRole();
	int leftBlood = args.at(2);
	EffectAffixes temp;
	int roundTemp = combatSystemInterface->getCurrentEffectAffixes().efRound;
	temp.cardId = combatSystemInterface->getCurrentEffectAffixes().cardId;
	switch (combatSystemInterface->getCurrentEffectAffixes().releaser)
	{
	case EffectAffixes::Releaser::Releaser_Role:
		bloodTemp = combatSystemInterface->getBloodRole();
		if (bloodTemp >= leftBlood)
		{	
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = EffectAffixes::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = combatSystemInterface->getEffectPQ().getEPQLevelMaxMonsterByRoundAndIndex(0, EffectPQ::EffectQueueIndex::EffectQueueIndex_After) + 1;
			combatSystemInterface->getEffectPQ().pushEffectAffixesMonster(temp,0,EffectPQ::EffectQueueIndex::EffectQueueIndex_After);
			return true;
		}
		break;
	case EffectAffixes::Releaser::Releaser_Monster:
		bloodTemp = combatSystemInterface->getBloodMonster();
		if (bloodTemp >= leftBlood)
		{			
			temp.effectIndex = 2;
			temp.releaser = EffectAffixes::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Other;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = combatSystemInterface->getEffectPQ().getEPQLevelMaxMonsterByRoundAndIndex(0, EffectPQ::EffectQueueIndex::EffectQueueIndex_After) + 1;
			combatSystemInterface->getEffectPQ().pushEffectAffixesMonster(temp, 0, EffectPQ::EffectQueueIndex::EffectQueueIndex_After);
			return true;
		}
		break;
	}
	return false;
}

bool EffectFunSet::effectCondition4(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果：当前的护甲处于[%d,%d]之间", args.at(2), args.at(3));
	

	return false;
}

bool EffectFunSet::effectCondition5(const std::vector<int> &args)
{
	return false;
}

bool EffectFunSet::effectCondition6(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果：当前的护甲等于[%d]",args.at(2));
	

	return false;
}

bool EffectFunSet::effectCondition7(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果：如果敌方护甲在[%d, 正无穷]", args.at(2));
		
	return false;
}

bool EffectFunSet::effectCondition8(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果：当前的手牌数处于[%d,%d]之间", args.at(2), args.at(3));
	
	return false;
}

bool EffectFunSet::effectCondition9(const std::vector<int> &args)
{
	return false;
}

bool EffectFunSet::effectCondition10(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果：当前的手牌数等于[%d]", args.at(2));
		
	return false;
}

bool EffectFunSet::effectCondition11(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果：如果敌方手牌数在[%d, 正无穷]", args.at(2));
		
	return false;
}

bool EffectFunSet::effectCondition12(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果：如果血量在[%d,%d]之间", args.at(2), args.at(3));

	int leftBlood = args.at(2);
	int rightBlood = args.at(3);
	int flag = 0;
	int efRoundTemp = combatSystemInterface->getCurrentEffectAffixes().efRound;
	int bloodMax = combatSystemInterface->getBloodMaxMonster();
	int roundTemp = 1;
	int bloodTemp = bloodMax;
	while (efRoundTemp > 1)
	{
		bloodTemp += combatSystemInterface->getRoundMonsterDeltaTable(roundTemp, DeltaTable::RoundLevel::RoundLevel_Total).front().effectTable[0][1] + combatSystemInterface->getRoundRoleDeltaTable(roundTemp, DeltaTable::RoundLevel::RoundLevel_Total).front().effectTable[0][1];

		if (bloodTemp >= leftBlood && bloodTemp <= rightBlood)
		{
			++flag;
			if (flag > 1)
			{
				break;
			}
		}
		if (bloodTemp > bloodMax)
		{
			bloodTemp = bloodMax;
		}
		++roundTemp;
		--efRoundTemp;
	}
	if (flag == 1)
	{
		EffectAffixes temp;
		int roundTemp = combatSystemInterface->getCurrentEffectAffixes().efRound;
		temp.cardId = combatSystemInterface->getCurrentEffectAffixes().cardId;
		temp.effectIndex = 1;
		temp.releaser = EffectAffixes::Releaser::Releaser_Monster;
		temp.receiver = Effect::Receiver::Receiver_Self;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = combatSystemInterface->getEffectPQ().getEPQLevelMaxMonsterByRoundAndIndex(0, EffectPQ::EffectQueueIndex::EffectQueueIndex_After) + 1;
		combatSystemInterface->getEffectPQ().pushEffectAffixesMonster(temp, 0, EffectPQ::EffectQueueIndex::EffectQueueIndex_After);
		return true;
	}
	return false;
}

bool EffectFunSet::effectCondition13(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果：开局起血量第一次处于[负无穷，0]");
	int flag = 0;
	int efRoundTemp = combatSystemInterface->getCurrentEffectAffixes().efRound;
	int bloodMax = combatSystemInterface->getBloodMaxMonster();
	int roundTemp = 1;
	int bloodTemp = bloodMax;
	while (efRoundTemp > 1)
	{
		bloodTemp += combatSystemInterface->getRoundMonsterDeltaTable(roundTemp, DeltaTable::RoundLevel::RoundLevel_Total).front().effectTable[0][1] + combatSystemInterface->getRoundRoleDeltaTable(roundTemp, DeltaTable::RoundLevel::RoundLevel_Total).front().effectTable[0][1];

		if (bloodTemp <= 0)
		{
			++flag;
			if (flag > 1)
			{
				break;
			}
		}
		if (bloodTemp > bloodMax)
		{
			bloodTemp = bloodMax;
		}
		++roundTemp;
		--efRoundTemp;
	}
	EffectAffixes temp;
	temp.cardId = combatSystemInterface->getCurrentEffectAffixes().cardId;
	if (flag == 1)
	{
		temp.effectIndex = 1;
		temp.releaser = EffectAffixes::Releaser::Releaser_Monster;
		temp.receiver = Effect::Receiver::Receiver_Other;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = combatSystemInterface->getEffectPQ().getEPQLevelMaxMonsterByRoundAndIndex(0, EffectPQ::EffectQueueIndex::EffectQueueIndex_After) + 1;
		combatSystemInterface->getEffectPQ().pushEffectAffixesMonster(temp, 0, EffectPQ::EffectQueueIndex::EffectQueueIndex_After);
		return true;
	}
	else if (temp.cardId == 30019)
	{
		temp.effectIndex = 2;
		temp.releaser = EffectAffixes::Releaser::Releaser_Monster;
		temp.receiver = Effect::Receiver::Receiver_Self;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = combatSystemInterface->getEffectPQ().getEPQLevelMaxMonsterByRoundAndIndex(0, EffectPQ::EffectQueueIndex::EffectQueueIndex_After) + 1;
		combatSystemInterface->getEffectPQ().pushEffectAffixesMonster(temp, 0, EffectPQ::EffectQueueIndex::EffectQueueIndex_After);
		return false;
	}
	return false;
}

bool EffectFunSet::effectCondition14(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果：开局起血量第一次处于[%d，血量上限]",args.at(2));

	int leftBlood = args.at(2);
	int flag = 0;
	int efRoundTemp = combatSystemInterface->getCurrentEffectAffixes().efRound;
	int bloodMax = combatSystemInterface->getBloodMaxMonster();

	int roundTemp = 1;

	int bloodTemp = bloodMax;

	while (efRoundTemp > 1)
	{
		bloodTemp += combatSystemInterface->getRoundMonsterDeltaTable(roundTemp, DeltaTable::RoundLevel::RoundLevel_Total).front().effectTable[0][1] + combatSystemInterface->getRoundRoleDeltaTable(roundTemp, DeltaTable::RoundLevel::RoundLevel_Total).front().effectTable[0][1];

		if (bloodTemp > bloodMax)
		{
			bloodTemp = bloodMax;
		}
		if (bloodTemp >= leftBlood)
		{
			++flag;
		}
		
		++roundTemp;
		--efRoundTemp;
	}
	EffectAffixes temp;
	temp.cardId = combatSystemInterface->getCurrentEffectAffixes().cardId;
	if (flag == 1)
	{
		//////////////////////////待定////////////////////////////////////////////////
		temp.effectIndex = 1;
		temp.releaser = EffectAffixes::Releaser::Releaser_Monster;
		temp.receiver = Effect::Receiver::Receiver_Self;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = combatSystemInterface->getEffectPQ().getEPQLevelMaxMonsterByRoundAndIndex(0, EffectPQ::EffectQueueIndex::EffectQueueIndex_After) + 1;
		combatSystemInterface->getEffectPQ().pushEffectAffixesMonster(temp, 0, EffectPQ::EffectQueueIndex::EffectQueueIndex_After);

		return true;
	}
	return false;
	
}

bool EffectFunSet::effectCondition15(const std::vector<int> &args)
{
	cocos2d::log("[information] 使用效果：如果自身血量减少 ");

	int roundTemp = combatSystemInterface->getCurrentEffectAffixes().efRound;
	int bloodTemp = 0;
	int bloodRet = 0;
	;
	auto itRoleBegin = combatSystemInterface->getDeltaTableRoleInCurrentRound().begin();
	auto itRoleEnd = combatSystemInterface->getDeltaTableRoleInCurrentRound().end();
	auto itMonsterBegin = combatSystemInterface->getDeltaTableMonsterInCurrentRound().begin();
	auto itMonsterEnd = combatSystemInterface->getDeltaTableMonsterInCurrentRound().end();
	
	for (; itRoleBegin != itRoleEnd; ++itRoleBegin)
	{
		bloodTemp += itRoleBegin->effectTable[0][0];
	}
	for (; itMonsterBegin != itMonsterEnd; ++itMonsterBegin)
	{
		bloodTemp += itMonsterBegin->effectTable[0][0];
	}
	if (bloodTemp < 0)
	{
		EffectAffixes temp;
		int roundTemp = combatSystemInterface->getCurrentEffectAffixes().efRound;
		temp.cardId = combatSystemInterface->getCurrentEffectAffixes().cardId;
		temp.effectIndex = 2;
		temp.releaser = EffectAffixes::Releaser::Releaser_Role;
		temp.receiver = Effect::Receiver::Receiver_Other;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = combatSystemInterface->getEffectPQ().getEPQLevelMaxRoleByRoundAndIndex(0, EffectPQ::EffectQueueIndex::EffectQueueIndex_After) + 1;
		
		combatSystemInterface->getEffectPQ().pushEffectAffixesRole(temp,0,EffectPQ::EffectQueueIndex::EffectQueueIndex_After);
		return true;
	}
	return false;
}