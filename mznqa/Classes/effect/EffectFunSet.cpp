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

const std::function<bool(CombatSystemInterface*)> EffectFunSet::nullFun = EffectFunSet::effectNullFun;

const std::map<int, std::function<bool(CombatSystemInterface*)>> EffectFunSet::funSet = {
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

EffectFunSet::~EffectFunSet()
{
}

bool EffectFunSet::effectBase0(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果：%d 血", csi->getEffectArgs().at(2));

	DeltaTable dtTemp;
	dtTemp.ID = csi->getEffectAffixes().cardId;
	dtTemp.roundNumber = csi->getEffectAffixes().efRound;
	switch (csi->getEffectAffixes().excuteStyle)
	{
	case Effect::ExcuteStyle::ExcuteStyle_Before:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_Before;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_In:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_In;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_After:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_After;
		break;
	}
	int deltaBlood = csi->getEffectArgs().at(2);
	switch (csi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		switch (csi->getEffectAffixes().receiver)
		{
		case Effect::Receiver::Receiver_Self:
			dtTemp.effectTable[0][0] = deltaBlood;
			//csi->updateRoleBlood(deltaBlood);
			break;
		case Effect::Receiver::Receiver_Other:
			dtTemp.effectTable[0][1] = deltaBlood;
			//csi->updateMonsterBlood(deltaBlood);
			break;
		}
		csi->getDeltaTableHistory().addTableRoleHistory(dtTemp);
		break;
	case Effect::Releaser::Releaser_Monster:
		switch (csi->getEffectAffixes().receiver)
		{
		case Effect::Receiver::Receiver_Self:
			dtTemp.effectTable[0][1] = deltaBlood;
			//csi->updateMonsterBlood(deltaBlood);
			break;
		case Effect::Receiver::Receiver_Other:
			dtTemp.effectTable[0][0] = deltaBlood;
			//csi->updateRoleBlood(deltaBlood);
			break;
		}		
		csi->getDeltaTableHistory().addTableMonsterHistory(dtTemp);
		break;
	}
	return true;
}

bool EffectFunSet::effectBase1(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果：%d 甲", csi->getEffectArgs().at(2));

	DeltaTable dtTemp;
	dtTemp.ID = csi->getEffectAffixes().cardId;
	dtTemp.roundNumber = csi->getEffectAffixes().efRound;
	switch (csi->getEffectAffixes().excuteStyle)
	{
	case Effect::ExcuteStyle::ExcuteStyle_Before:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_Before;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_In:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_In;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_After:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_After;
		break;
	}
	int deltaArmor = csi->getEffectArgs().at(2);
	switch (csi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		switch (csi->getEffectAffixes().receiver)
		{
		case Effect::Receiver::Receiver_Self:
			dtTemp.effectTable[1][0] = deltaArmor;
			//csi->updateRoleArmor(deltaArmor);
			break;
		case Effect::Receiver::Receiver_Other:
			dtTemp.effectTable[1][1] = deltaArmor;
			//csi->updateMonsterArmor(deltaArmor);
			break;
		}
		csi->getDeltaTableHistory().addTableRoleHistory(dtTemp);
		break;
	case Effect::Releaser::Releaser_Monster:
		switch (csi->getEffectAffixes().receiver)
		{
		case Effect::Receiver::Receiver_Self:
			dtTemp.effectTable[1][1] = deltaArmor;
			//csi->updateMonsterArmor(deltaArmor);
			break;
		case Effect::Receiver::Receiver_Other:
			dtTemp.effectTable[1][0] = deltaArmor;
			//csi->updateRoleArmor(deltaArmor);
			break;
		}
		csi->getDeltaTableHistory().addTableMonsterHistory(dtTemp);
		break;
	}
	return true;
}

bool EffectFunSet::effectBase2(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果： %d 手牌", csi->getEffectArgs().at(2));
	
	DeltaTable dtTemp;
	int deltaHandCount = csi->getEffectArgs().at(2);
	dtTemp.effectTable[2][0] = deltaHandCount;
	//csi->updateRoleHandCount(deltaHandCount);
	dtTemp.ID = csi->getEffectAffixes().cardId;
	dtTemp.roundNumber = csi->getEffectAffixes().efRound;
	switch (csi->getEffectAffixes().excuteStyle)
	{
	case Effect::ExcuteStyle::ExcuteStyle_Before:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_Before;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_In:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_In;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_After:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_After;
		break;
	}
	switch (csi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		csi->getDeltaTableHistory().addTableRoleHistory(dtTemp);
		break;
	case Effect::Releaser::Releaser_Monster:
		csi->getDeltaTableHistory().addTableMonsterHistory(dtTemp);
		break;
	}

	return true;
}

bool EffectFunSet::effectBase3(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果：抽 %d 张牌",csi->getEffectArgs().at(2));

	DeltaTable dtTemp;
	int deltaDrawCardCount = csi->getEffectArgs().at(2);
	dtTemp.effectTable[3][0] = deltaDrawCardCount;
	//csi->updateRoleDrawCardCount(deltaDrawCardCount);
	dtTemp.ID = csi->getEffectAffixes().cardId;
	dtTemp.roundNumber = csi->getEffectAffixes().efRound;
	switch (csi->getEffectAffixes().excuteStyle)
	{
	case Effect::ExcuteStyle::ExcuteStyle_Before:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_Before;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_In:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_In;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_After:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_After;
		break;
	}
	switch (csi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		csi->getDeltaTableHistory().addTableRoleHistory(dtTemp);
		break;
	case Effect::Releaser::Releaser_Monster:
		csi->getDeltaTableHistory().addTableMonsterHistory(dtTemp);
		break;
	}

	return true;
}

bool EffectFunSet::effectBase4(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果：出 %d 张牌", csi->getEffectArgs().at(2));

	DeltaTable dtTemp;
	int deltaDiscardCount = csi->getEffectArgs().at(2);
	dtTemp.effectTable[4][0] = deltaDiscardCount;
	//csi->setRoleDiscountCount(deltaDiscardCount);
	dtTemp.ID = csi->getEffectAffixes().cardId;
	dtTemp.roundNumber = csi->getEffectAffixes().efRound;
	switch (csi->getEffectAffixes().excuteStyle)
	{
	case Effect::ExcuteStyle::ExcuteStyle_Before:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_Before;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_In:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_In;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_After:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_After;
		break;
	}
	switch (csi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		csi->getDeltaTableHistory().addTableRoleHistory(dtTemp);
		break;
	case Effect::Releaser::Releaser_Monster:
		csi->getDeltaTableHistory().addTableMonsterHistory(dtTemp);
		break;
	}

	return true;
}

bool EffectFunSet::effectBase5(CombatSystemInterface* csi)
{
	DeltaTable dtTemp;
	dtTemp.ID = csi->getEffectAffixes().cardId;
	dtTemp.roundNumber = csi->getEffectAffixes().efRound;
	switch (csi->getEffectAffixes().excuteStyle)
	{
	case Effect::ExcuteStyle::ExcuteStyle_Before:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_Before;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_In:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_In;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_After:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_After;
		break;
	}
	switch (csi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:		
		dtTemp.effectTable[0][0] = csi->getRoleBloodMax();
		//csi->updateRoleBlood(csi->getRoleBloodMax());		
		csi->getDeltaTableHistory().addTableRoleHistory(dtTemp);
		break;
	case Effect::Releaser::Releaser_Monster:
		dtTemp.effectTable[1][1] = csi->getMonsterBloodMax();
		//csi->updateMonsterBlood(csi->getMonsterBloodMax());
		csi->getDeltaTableHistory().addTableMonsterHistory(dtTemp);
		break;
	}
	return true;
}

bool EffectFunSet::effectSpecial0(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果： 攻击无效");

	DeltaTable dtTemp;
	int roundTemp = csi->getEffectAffixes().efRound;
	dtTemp.ID = csi->getEffectAffixes().cardId;
	dtTemp.roundNumber = roundTemp;
	switch (csi->getEffectAffixes().excuteStyle)
	{
	case Effect::ExcuteStyle::ExcuteStyle_Before:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_Before;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_In:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_In;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_After:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_After;
		break;
	}

	int deltaBlood = 0;
	int bloodTemp = 0;
	csi->setCurentRoundRoleDeltaTable(roundTemp);
	auto itRoleBegin = csi->getRoundRoleDeltaTable().begin();
	auto itRoleEnd = csi->getRoundRoleDeltaTable().end();
	csi->setCurrentRoundMonsterDeltaTable(roundTemp);
	auto itMonsterBegin = csi->getRoundMonsterDeltaTable().begin();
	auto itMonsterEnd = csi->getRoundMonsterDeltaTable().end();
	switch (csi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		for (; itMonsterBegin != itMonsterEnd; ++itMonsterBegin)
		{
			bloodTemp = itMonsterBegin->effectTable[0][0];
			if (bloodTemp < 0)
			{
				//itMonsterBegin->effectTable[0][0] = 0;
				deltaBlood += bloodTemp;
			}
		}
		if (deltaBlood < 0)
		{
			dtTemp.effectTable[0][0] = deltaBlood;
		//csi->updateRoleBlood(-deltaBlood);
		}		
		csi->getDeltaTableHistory().addTableRoleHistory(dtTemp);
		break;
	case Effect::Releaser::Releaser_Monster:
		for (; itRoleBegin != itRoleEnd; ++itRoleBegin)
		{
			bloodTemp = itRoleBegin->effectTable[0][1];
			if (bloodTemp < 0)
			{
				//itRoleBegin->effectTable[0][1] = 0;
				deltaBlood += bloodTemp;
			}
		}
		if (deltaBlood < 0)
		{
			dtTemp.effectTable[0][0] = deltaBlood;
			//csi->updateMonsterBlood(-deltaBlood);
		}
		csi->getDeltaTableHistory().addTableMonsterHistory(dtTemp);
		break;
	}

	return true;
}

bool EffectFunSet::effectSpecial1(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果：回血无效");

	DeltaTable dtTemp;
	int roundTemp = csi->getEffectAffixes().efRound;
	dtTemp.ID = csi->getEffectAffixes().cardId;
	dtTemp.roundNumber = roundTemp;
	switch (csi->getEffectAffixes().excuteStyle)
	{
	case Effect::ExcuteStyle::ExcuteStyle_Before:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_Before;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_In:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_In;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_After:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_After;
		break;
	}

	int deltaBlood = 0;
	int rtnBlood = 0;
	csi->setCurentRoundRoleDeltaTable(roundTemp);
	auto itRoleBegin = csi->getRoundRoleDeltaTable().begin();
	auto itRoleEnd = csi->getRoundRoleDeltaTable().end();
	csi->setCurrentRoundMonsterDeltaTable(roundTemp);
	auto itMonsterBegin = csi->getRoundMonsterDeltaTable().begin();
	auto itMonsterEnd = csi->getRoundMonsterDeltaTable().end();
	switch (csi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		for (; itRoleBegin != itRoleEnd; ++itRoleBegin)
		{
			rtnBlood = itRoleBegin->effectTable[0][1];
			if (rtnBlood > 0)
			{
				//itRoleBegin->effectTable[0][0] = 0;
				deltaBlood += rtnBlood;
			}
		}
		
		for (; itMonsterBegin != itMonsterEnd; ++itMonsterBegin)
		{
			rtnBlood = itMonsterBegin->effectTable[0][1];
			if (rtnBlood > 0)
			{
				//itMonsterBegin->effectTable[0][0] = 0;
				deltaBlood += rtnBlood;
			}
		}
		if (deltaBlood > 0)
		{
			dtTemp.effectTable[0][1] = -deltaBlood;
			//csi->updateRoleBlood(-deltaBlood);
		}
		csi->getDeltaTableHistory().addTableRoleHistory(dtTemp);
		break;
	case Effect::Releaser::Releaser_Monster:
		
		for (; itMonsterBegin != itMonsterEnd; ++itMonsterBegin)
		{
			rtnBlood = itMonsterBegin->effectTable[0][0];
			if (rtnBlood > 0)
			{
				//itMonsterBegin->effectTable[0][1] = 0;
				deltaBlood += rtnBlood;
			}
		}
		
		for (; itRoleBegin != itRoleEnd; ++itRoleBegin)
		{
			rtnBlood = itRoleBegin->effectTable[0][0];
			if (rtnBlood > 0)
			{
				//itRoleBegin->effectTable[0][1] = 0;
				deltaBlood += rtnBlood;
			}
		}
		if (deltaBlood < 0)
		{
			dtTemp.effectTable[0][0] = -deltaBlood;
			//csi->updateMonsterBlood(-deltaBlood);
		}
		csi->getDeltaTableHistory().addTableMonsterHistory(dtTemp);
		break;
	}
	return true;
}

bool EffectFunSet::effectSpecial2(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果：回甲无效");

	DeltaTable dtTemp;
	int roundTemp = csi->getEffectAffixes().efRound;
	dtTemp.ID = csi->getEffectAffixes().cardId;
	dtTemp.roundNumber = roundTemp;
	switch (csi->getEffectAffixes().excuteStyle)
	{
	case Effect::ExcuteStyle::ExcuteStyle_Before:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_Before;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_In:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_In;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_After:
		dtTemp.roundLevel = DeltaTable::RoundLevel::RoundLevel_After;
		break;
	}

	int deltaArmor = 0;
	int rtnArmor = 0;
	csi->setCurentRoundRoleDeltaTable(roundTemp);
	auto itRoleBegin = csi->getRoundRoleDeltaTable().begin();
	auto itRoleEnd = csi->getRoundRoleDeltaTable().end();
	csi->setCurrentRoundMonsterDeltaTable(roundTemp);
	auto itMonsterBegin = csi->getRoundMonsterDeltaTable().begin();
	auto itMonsterEnd = csi->getRoundMonsterDeltaTable().end();
	switch (csi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		for (; itRoleBegin != itRoleEnd; ++itRoleBegin)
		{
			rtnArmor = itRoleBegin->effectTable[1][1];
			if (rtnArmor > 0)
			{
				//itRoleBegin->effectTable[1][0] = 0;
				deltaArmor += rtnArmor;
			}
		}

		for (; itMonsterBegin != itMonsterEnd; ++itMonsterBegin)
		{
			rtnArmor = itMonsterBegin->effectTable[1][1];
			if (rtnArmor > 0)
			{
				//itMonsterBegin->effectTable[1][0] = 0;
				deltaArmor += rtnArmor;
			}
		}
		if (deltaArmor > 0)
		{
			dtTemp.effectTable[1][1] = -deltaArmor;
			//csi->updateRoleArmor(-deltaArmor);
		}
		csi->getDeltaTableHistory().addTableRoleHistory(dtTemp);
		break;
	case Effect::Releaser::Releaser_Monster:

		for (; itMonsterBegin != itMonsterEnd; ++itMonsterBegin)
		{
			rtnArmor = itMonsterBegin->effectTable[1][0];
			if (rtnArmor > 0)
			{
				//itMonsterBegin->effectTable[1][1] = 0;
				deltaArmor += rtnArmor;
			}
		}

		for (; itRoleBegin != itRoleEnd; ++itRoleBegin)
		{
			rtnArmor = itRoleBegin->effectTable[1][0];
			if (rtnArmor > 0)
			{
				//itRoleBegin->effectTable[1][1] = 0;
				deltaArmor += rtnArmor;
			}
		}
		if (deltaArmor > 0)
		{
			dtTemp.effectTable[1][0] = -deltaArmor;
			//csi->updateMonsterArmor(-deltaArmor);
		}
		csi->getDeltaTableHistory().addTableMonsterHistory(dtTemp);
		break;
	}
	return true;
}

bool EffectFunSet::effectCondition0(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果：当前的血量处于[%d,%d]之间", csi->getEffectArgs().at(2),csi->getEffectArgs().at(3));
	int bloodTemp = 0;
	int leftBlood = csi->getEffectArgs().at(2);
	int rightBlood = csi->getEffectArgs().at(3);

	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = csi->getEffectAffixes().efRound;
	temp.cardId = csi->getEffectAffixes().cardId;

	switch (csi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		bloodTemp = csi->getRoleBlood();
		if (bloodTemp >= leftBlood && bloodTemp <= rightBlood)
		{
		/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.level = csi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			csi->getEffectPQ().pushRoleEffectAffixes(temp);
			return true;
		}
		break;
	case Effect::Releaser::Releaser_Monster:
		bloodTemp = csi->getMonsterBlood();
		if (bloodTemp >= leftBlood && bloodTemp <= rightBlood)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = csi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			csi->getEffectPQ().pushMonsterEffectAffixes(temp);
			return true;
		}
		break;
	}
	return false;
}

bool EffectFunSet::effectCondition1(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果：当前的血量处于[1,%d]之间", csi->getEffectArgs().at(2));

	int bloodTemp = 0;
	int rightBlood = csi->getEffectArgs().at(2);

	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = csi->getEffectAffixes().efRound;
	temp.cardId = csi->getEffectAffixes().cardId;

	switch (csi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		bloodTemp = csi->getRoleBlood();
		if (bloodTemp >= 1 && bloodTemp <= rightBlood)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = csi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			csi->getEffectPQ().pushRoleEffectAffixes(temp);
			return true;
		}
		break;
	case Effect::Releaser::Releaser_Monster:
		bloodTemp = csi->getMonsterBlood();
		if (bloodTemp >= 1 && bloodTemp <= rightBlood)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = csi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			csi->getEffectPQ().pushMonsterEffectAffixes(temp);
			return true;
		}
		break;
	}

	return false;
}

bool EffectFunSet::effectCondition2(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果：当前的血量等于[%d]", csi->getEffectArgs().at(2));
	int bloodTemp = 0;
	int equalBlood = csi->getEffectArgs().at(2);

	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = csi->getEffectAffixes().efRound;
	temp.cardId = csi->getEffectAffixes().cardId;

	switch (csi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		bloodTemp = csi->getRoleBlood();
		if (bloodTemp == equalBlood)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = csi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			csi->getEffectPQ().pushRoleEffectAffixes(temp);
			return true;
		}
		break;
	case Effect::Releaser::Releaser_Monster:
		bloodTemp = csi->getMonsterBlood();
		if (bloodTemp == equalBlood)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = csi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			csi->getEffectPQ().pushMonsterEffectAffixes(temp);
			return true;
		}
		break;
	}

	return false;
}

bool EffectFunSet::effectCondition3(CombatSystemInterface* csi)
{

	cocos2d::log("[information] 使用效果：如果敌方血量在[%d, 正无穷]", csi->getEffectArgs().at(2));

	int bloodTemp = csi->getRoleBlood();
	int leftBlood = csi->getEffectArgs().at(2);
	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = csi->getEffectAffixes().efRound;
	temp.cardId = csi->getEffectAffixes().cardId;
	switch (csi->getEffectAffixes().releaser)
	{
		bloodTemp = csi->getRoleBlood();
		if (bloodTemp >= leftBlood)
		{	
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = csi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			csi->getEffectPQ().pushRoleEffectAffixes(temp);
			return true;
		}
		break;
	case Effect::Releaser::Releaser_Monster:
		bloodTemp = csi->getMonsterBlood();
		if (bloodTemp >= leftBlood)
		{			
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Other;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = csi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			csi->getEffectPQ().pushMonsterEffectAffixes(temp);
			return true;
		}
		break;

	}
	return false;
}

bool EffectFunSet::effectCondition4(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果：当前的护甲处于[%d,%d]之间", csi->getEffectArgs().at(2), csi->getEffectArgs().at(3));
	int armorTemp = 0;
	int leftArmor = csi->getEffectArgs().at(2);
	int rightArmor = csi->getEffectArgs().at(3);

	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = csi->getEffectAffixes().efRound;
	temp.cardId = csi->getEffectAffixes().cardId;

	switch (csi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		armorTemp = csi->getRoleArmor();
		if (armorTemp >= leftArmor && armorTemp <= rightArmor)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = csi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			csi->getEffectPQ().pushRoleEffectAffixes(temp);
			return true;
		}
		break;
	case Effect::Releaser::Releaser_Monster:
		armorTemp = csi->getMonsterArmor();
		if (armorTemp >= leftArmor && armorTemp <= rightArmor)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = csi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			csi->getEffectPQ().pushMonsterEffectAffixes(temp);
			return true;
		}
		break;
	}
	return false;
}

bool EffectFunSet::effectCondition5(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果：当前的护甲处于[1,%d]之间", csi->getEffectArgs().at(2));

	int armorTemp = 0;
	int rightArmor = csi->getEffectArgs().at(2);

	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = csi->getEffectAffixes().efRound;
	temp.cardId = csi->getEffectAffixes().cardId;

	switch (csi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		armorTemp = csi->getRoleArmor();
		if (armorTemp >= 1 && armorTemp <= rightArmor)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = csi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			csi->getEffectPQ().pushRoleEffectAffixes(temp);
			return true;
		}
		break;
	case Effect::Releaser::Releaser_Monster:
		armorTemp = csi->getMonsterArmor();
		if (armorTemp >= 1 && armorTemp <= rightArmor)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = csi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			csi->getEffectPQ().pushMonsterEffectAffixes(temp);
			return true;
		}
		break;
	}

	return false;
}

bool EffectFunSet::effectCondition6(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果：当前的护甲等于[%d]", csi->getEffectArgs().at(2));
	int armorTemp = 0;
	int equalArmor = csi->getEffectArgs().at(2);

	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = csi->getEffectAffixes().efRound;
	temp.cardId = csi->getEffectAffixes().cardId;

	switch (csi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		armorTemp = csi->getRoleArmor();
		if (armorTemp == equalArmor)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = csi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			csi->getEffectPQ().pushRoleEffectAffixes(temp);
			return true;
		}
		break;
	case Effect::Releaser::Releaser_Monster:
		armorTemp = csi->getMonsterArmor();
		if (armorTemp == equalArmor)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = csi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			csi->getEffectPQ().pushMonsterEffectAffixes(temp);
			return true;
		}
		break;
	}

	return false;
}

bool EffectFunSet::effectCondition7(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果：如果敌方护甲在[%d, 正无穷]", csi->getEffectArgs().at(2));

	int armorTemp = csi->getRoleBlood();
	int leftArmor = csi->getEffectArgs().at(2);
	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = csi->getEffectAffixes().efRound;
	temp.cardId = csi->getEffectAffixes().cardId;
	switch (csi->getEffectAffixes().releaser)
	{
		armorTemp = csi->getRoleArmor();
		if (armorTemp >= leftArmor)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = csi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			csi->getEffectPQ().pushRoleEffectAffixes(temp);
			return true;
		}
		break;
	case Effect::Releaser::Releaser_Monster:
		armorTemp = csi->getMonsterArmor();
		if (armorTemp >= leftArmor)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = csi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			csi->getEffectPQ().pushMonsterEffectAffixes(temp);
			return true;
		}
		break;
	}
	return false;
}

bool EffectFunSet::effectCondition8(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果：当前的手牌数处于[%d,%d]之间", csi->getEffectArgs().at(2), csi->getEffectArgs().at(3));
	int handCardCountTemp = 0;
	int leftHandCardCount = csi->getEffectArgs().at(2);
	int rightHandCardCount = csi->getEffectArgs().at(3);

	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = csi->getEffectAffixes().efRound;
	temp.cardId = csi->getEffectAffixes().cardId;
	handCardCountTemp = csi->getRoleHandCount();
	if (handCardCountTemp >= leftHandCardCount && handCardCountTemp <= rightHandCardCount)
	{
		/////////////////////////////待定/////////////////////////////////////////////
		temp.effectIndex = 2;
		temp.releaser = Effect::Releaser::Releaser_Monster;
		temp.receiver = Effect::Receiver::Receiver_Self;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = csi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
		csi->getEffectPQ().pushRoleEffectAffixes(temp);
		return true;
	}
	return false;
}

bool EffectFunSet::effectCondition9(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果：当前的手牌数处于[1,%d]之间", csi->getEffectArgs().at(2));

	int handCardCountTemp = 0;
	int rightHandCardCount = csi->getEffectArgs().at(2);

	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = csi->getEffectAffixes().efRound;
	temp.cardId = csi->getEffectAffixes().cardId;
	handCardCountTemp = csi->getRoleHandCount();
	if (handCardCountTemp >= 1 && handCardCountTemp <= rightHandCardCount)
	{
		/////////////////////////////待定/////////////////////////////////////////////
		temp.effectIndex = 2;
		temp.releaser = Effect::Releaser::Releaser_Monster;
		temp.receiver = Effect::Receiver::Receiver_Self;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = csi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
		csi->getEffectPQ().pushRoleEffectAffixes(temp);
		return true;
	}
	return false;
}

bool EffectFunSet::effectCondition10(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果：当前的手牌数等于[%d]", csi->getEffectArgs().at(2));

	int handCardCountTemp = 0;
	int equalHandCardCount = csi->getEffectArgs().at(2);
	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = csi->getEffectAffixes().efRound;
	temp.cardId = csi->getEffectAffixes().cardId;
	handCardCountTemp = csi->getRoleHandCount();
	if (handCardCountTemp == equalHandCardCount)
	{
		/////////////////////////////待定/////////////////////////////////////////////
		temp.effectIndex = 2;
		temp.releaser = Effect::Releaser::Releaser_Monster;
		temp.receiver = Effect::Receiver::Receiver_Self;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = csi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
		csi->getEffectPQ().pushRoleEffectAffixes(temp);
		return true;
	}
	return false;
}

bool EffectFunSet::effectCondition11(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果：如果敌方手牌数在[%d, 正无穷]", csi->getEffectArgs().at(2));

	int handCardCountTemp = 0;
	int leftHandCardCount = csi->getEffectArgs().at(2);
	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = csi->getEffectAffixes().efRound;
	temp.cardId = csi->getEffectAffixes().cardId;
	handCardCountTemp = csi->getRoleHandCount();
	if (handCardCountTemp >= leftHandCardCount)
	{
		/////////////////////////////待定/////////////////////////////////////////////
		temp.effectIndex = 2;
		temp.releaser = Effect::Releaser::Releaser_Monster;
		temp.receiver = Effect::Receiver::Receiver_Self;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = csi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
		csi->getEffectPQ().pushRoleEffectAffixes(temp);
		return true;
	}
	return false;
}

bool EffectFunSet::effectCondition12(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果：如果血量在[%d,%d]之间", csi->getEffectArgs().at(2), csi->getEffectArgs().at(3));

	int leftBlood = csi->getEffectArgs().at(2);
	int rightBlood = csi->getEffectArgs().at(3);
	int flag = 0;
	int efRoundTemp = csi->getEffectAffixes().efRound;
	int bloodMax = csi->getMonsterBloodMax();

	int roundTemp = 1;

	int bloodTemp = bloodMax;

	while (efRoundTemp > 1)
	{
		bloodTemp += csi->getRoundMonsterDeltaTable(roundTemp, DeltaTable::RoundLevel::RoundLevel_Total).front().effectTable[0][1] + csi->getRoundRoleDeltaTable(roundTemp, DeltaTable::RoundLevel::RoundLevel_Total).front().effectTable[0][1];

		if (bloodTemp >= leftBlood && bloodTemp <= rightBlood)
		{
			++flag;
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
		EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
		int roundTemp = csi->getEffectAffixes().efRound;
		temp.cardId = csi->getEffectAffixes().cardId;
		temp.effectIndex = 1;
		temp.releaser = Effect::Releaser::Releaser_Monster;
		temp.receiver = Effect::Receiver::Receiver_Self;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = csi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
		csi->getEffectPQ().pushMonsterEffectAffixes(temp);
		return true;
	}
	return false;
}

bool EffectFunSet::effectCondition13(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果：开局起血量第一次处于[负无穷，0]");
	int flag = 0;
	int efRoundTemp = csi->getEffectAffixes().efRound;
	int bloodMax = csi->getMonsterBloodMax();

	int roundTemp = 1;

	int bloodTemp = bloodMax;

	while (efRoundTemp > 1)
	{
		bloodTemp += csi->getRoundMonsterDeltaTable(roundTemp, DeltaTable::RoundLevel::RoundLevel_Total).front().effectTable[0][1] + csi->getRoundRoleDeltaTable(roundTemp, DeltaTable::RoundLevel::RoundLevel_Total).front().effectTable[0][1];

		if (bloodTemp <= 0)
		{
			++flag;
		}
		if (bloodTemp > bloodMax)
		{
			bloodTemp = bloodMax;
		}
		++roundTemp;
		--efRoundTemp;
	}
	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	temp.cardId = csi->getEffectAffixes().cardId;
	if (flag == 1)
	{
		temp.effectIndex = 1;
		temp.releaser = Effect::Releaser::Releaser_Monster;
		temp.receiver = Effect::Receiver::Receiver_Other;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = csi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
		csi->getEffectPQ().pushMonsterEffectAffixes(temp);

		return true;
	}
	else if (temp.cardId == 30019)
	{
		temp.effectIndex = 2;
		temp.releaser = Effect::Releaser::Releaser_Monster;
		temp.receiver = Effect::Receiver::Receiver_Self;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = csi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
		csi->getEffectPQ().pushMonsterEffectAffixes(temp);
		return false;
	}
}

bool EffectFunSet::effectCondition14(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果：开局起血量第一次处于[%d，血量上限]",csi->getEffectArgs().at(2));

	int leftBlood = csi->getEffectArgs().at(2);
	int flag = 0;
	int efRoundTemp = csi->getEffectAffixes().efRound;
	int bloodMax = csi->getMonsterBloodMax();

	int roundTemp = 1;

	int bloodTemp = bloodMax;

	while (efRoundTemp > 1)
	{
		bloodTemp += csi->getRoundMonsterDeltaTable(roundTemp, DeltaTable::RoundLevel::RoundLevel_Total).front().effectTable[0][1] + csi->getRoundRoleDeltaTable(roundTemp, DeltaTable::RoundLevel::RoundLevel_Total).front().effectTable[0][1];

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
	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	temp.cardId = csi->getEffectAffixes().cardId;
	if (flag == 1)
	{
		//////////////////////////待定////////////////////////////////////////////////
		temp.effectIndex = 1;
		temp.releaser = Effect::Releaser::Releaser_Monster;
		temp.receiver = Effect::Receiver::Receiver_Self;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = csi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
		csi->getEffectPQ().pushMonsterEffectAffixes(temp);

		return true;
	}
	return false;
	
}

bool EffectFunSet::effectCondition15(CombatSystemInterface* csi)
{
	cocos2d::log("[information] 使用效果：如果自身血量减少 ");

	int roundTemp = csi->getEffectAffixes().efRound;
	int bloodTemp = 0;
	int bloodRet = 0;
	csi->setCurentRoundRoleDeltaTable(roundTemp);
	auto itRoleBegin = csi->getRoundRoleDeltaTable().begin();
	auto itRoleEnd = csi->getRoundRoleDeltaTable().end();
	csi->setCurrentRoundMonsterDeltaTable(roundTemp);
	auto itMonsterBegin = csi->getRoundMonsterDeltaTable().begin();
	auto itMonsterEnd = csi->getRoundMonsterDeltaTable().end();
	
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
		EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);

		int roundTemp = csi->getEffectAffixes().efRound;
		temp.cardId = csi->getEffectAffixes().cardId;
		temp.effectIndex = 2;
		temp.releaser = Effect::Releaser::Releaser_Role;
		temp.receiver = Effect::Receiver::Receiver_Other;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = csi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
		csi->getEffectPQ().pushRoleEffectAffixes(temp);
		return true;
	}
	return false;
}