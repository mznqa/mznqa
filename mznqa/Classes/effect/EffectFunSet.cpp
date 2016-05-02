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

const std::function<bool(EffectFunInterface*/*std::vector<int>&*/)> EffectFunSet::nullFun = EffectFunSet::effectNullFun;

const std::map<int, std::function<bool(EffectFunInterface*/*const std::vector<int>&*/)>> EffectFunSet::funSet = {
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

bool EffectFunSet::effectBase0(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果：%d 血", efi->getEffectArgs().at(2));

	DeltaTable dtTemp;
	dtTemp.ID = efi->getEffectAffixes().cardId;
	dtTemp.roundNumber = efi->getEffectAffixes().efRound;
	switch (efi->getEffectAffixes().excuteStyle)
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
	int deltaBlood = efi->getEffectArgs().at(2);
	switch (efi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		switch (efi->getEffectAffixes().receiver)
		{
		case Effect::Receiver::Receiver_Self:
			dtTemp.effectTable[0][0] = deltaBlood;
			//efi->updateRoleBlood(deltaBlood);
			break;
		case Effect::Receiver::Receiver_Other:
			dtTemp.effectTable[0][1] = deltaBlood;
			//efi->updateMonsterBlood(deltaBlood);
			break;
		}
		efi->getDeltaTableHistory().addTableRoleHistory(dtTemp);
		break;
	case Effect::Releaser::Releaser_Monster:
		switch (efi->getEffectAffixes().receiver)
		{
		case Effect::Receiver::Receiver_Self:
			dtTemp.effectTable[0][1] = deltaBlood;
			//efi->updateMonsterBlood(deltaBlood);
			break;
		case Effect::Receiver::Receiver_Other:
			dtTemp.effectTable[0][0] = deltaBlood;
			//efi->updateRoleBlood(deltaBlood);
			break;
		}		
		efi->getDeltaTableHistory().addTableMonsterHistory(dtTemp);
		break;
	}
	return true;
}

bool EffectFunSet::effectBase1(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果：%d 甲", efi->getEffectArgs().at(2));

	DeltaTable dtTemp;
	dtTemp.ID = efi->getEffectAffixes().cardId;
	dtTemp.roundNumber = efi->getEffectAffixes().efRound;
	switch (efi->getEffectAffixes().excuteStyle)
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
	int deltaArmor = efi->getEffectArgs().at(2);
	switch (efi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		switch (efi->getEffectAffixes().receiver)
		{
		case Effect::Receiver::Receiver_Self:
			dtTemp.effectTable[1][0] = deltaArmor;
			//efi->updateRoleArmor(deltaArmor);
			break;
		case Effect::Receiver::Receiver_Other:
			dtTemp.effectTable[1][1] = deltaArmor;
			//efi->updateMonsterArmor(deltaArmor);
			break;
		}
		efi->getDeltaTableHistory().addTableRoleHistory(dtTemp);
		break;
	case Effect::Releaser::Releaser_Monster:
		switch (efi->getEffectAffixes().receiver)
		{
		case Effect::Receiver::Receiver_Self:
			dtTemp.effectTable[1][1] = deltaArmor;
			//efi->updateMonsterArmor(deltaArmor);
			break;
		case Effect::Receiver::Receiver_Other:
			dtTemp.effectTable[1][0] = deltaArmor;
			//efi->updateRoleArmor(deltaArmor);
			break;
		}
		efi->getDeltaTableHistory().addTableMonsterHistory(dtTemp);
		break;
	}
	return true;
}

bool EffectFunSet::effectBase2(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果： %d 手牌", efi->getEffectArgs().at(2));
	
	DeltaTable dtTemp;
	int deltaHandCount = efi->getEffectArgs().at(2);
	dtTemp.effectTable[2][0] = deltaHandCount;
	//efi->updateRoleHandCount(deltaHandCount);
	dtTemp.ID = efi->getEffectAffixes().cardId;
	dtTemp.roundNumber = efi->getEffectAffixes().efRound;
	switch (efi->getEffectAffixes().excuteStyle)
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
	switch (efi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		efi->getDeltaTableHistory().addTableRoleHistory(dtTemp);
		break;
	case Effect::Releaser::Releaser_Monster:
		efi->getDeltaTableHistory().addTableMonsterHistory(dtTemp);
		break;
	}

	return true;
}

bool EffectFunSet::effectBase3(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果：抽 %d 张牌",efi->getEffectArgs().at(2));

	DeltaTable dtTemp;
	int deltaDrawCardCount = efi->getEffectArgs().at(2);
	dtTemp.effectTable[3][0] = deltaDrawCardCount;
	//efi->updateRoleDrawCardCount(deltaDrawCardCount);
	dtTemp.ID = efi->getEffectAffixes().cardId;
	dtTemp.roundNumber = efi->getEffectAffixes().efRound;
	switch (efi->getEffectAffixes().excuteStyle)
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
	switch (efi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		efi->getDeltaTableHistory().addTableRoleHistory(dtTemp);
		break;
	case Effect::Releaser::Releaser_Monster:
		efi->getDeltaTableHistory().addTableMonsterHistory(dtTemp);
		break;
	}

	return true;
}

bool EffectFunSet::effectBase4(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果：出 %d 张牌", efi->getEffectArgs().at(2));

	DeltaTable dtTemp;
	int deltaDiscardCount = efi->getEffectArgs().at(2);
	dtTemp.effectTable[4][0] = deltaDiscardCount;
	//efi->setRoleDiscountCount(deltaDiscardCount);
	dtTemp.ID = efi->getEffectAffixes().cardId;
	dtTemp.roundNumber = efi->getEffectAffixes().efRound;
	switch (efi->getEffectAffixes().excuteStyle)
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
	switch (efi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		efi->getDeltaTableHistory().addTableRoleHistory(dtTemp);
		break;
	case Effect::Releaser::Releaser_Monster:
		efi->getDeltaTableHistory().addTableMonsterHistory(dtTemp);
		break;
	}

	return true;
}

bool EffectFunSet::effectBase5(EffectFunInterface* efi)
{
	DeltaTable dtTemp;
	dtTemp.ID = efi->getEffectAffixes().cardId;
	dtTemp.roundNumber = efi->getEffectAffixes().efRound;
	switch (efi->getEffectAffixes().excuteStyle)
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
	switch (efi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:		
		dtTemp.effectTable[0][0] = efi->getRoleBloodMax();
		//efi->updateRoleBlood(efi->getRoleBloodMax());		
		efi->getDeltaTableHistory().addTableRoleHistory(dtTemp);
		break;
	case Effect::Releaser::Releaser_Monster:
		dtTemp.effectTable[1][1] = efi->getMonsterBloodMax();
		//efi->updateMonsterBlood(efi->getMonsterBloodMax());
		efi->getDeltaTableHistory().addTableMonsterHistory(dtTemp);
		break;
	}
	return true;
}

bool EffectFunSet::effectSpecial0(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果： 攻击无效");

	DeltaTable dtTemp;
	int roundTemp = efi->getEffectAffixes().efRound;
	dtTemp.ID = efi->getEffectAffixes().cardId;
	dtTemp.roundNumber = roundTemp;
	switch (efi->getEffectAffixes().excuteStyle)
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
	efi->setCurentRoundRoleDeltaTable(roundTemp + 1);
	auto itRoleBegin = efi->getRoundRoleDeltaTable().begin();
	auto itRoleEnd = efi->getRoundRoleDeltaTable().end();
	efi->setCurrentRoundMonsterDeltaTable(roundTemp + 1);
	auto itMonsterBegin = efi->getRoundMonsterDeltaTable().begin();
	auto itMonsterEnd = efi->getRoundMonsterDeltaTable().end();
	switch (efi->getEffectAffixes().releaser)
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
		//efi->updateRoleBlood(-deltaBlood);
		}		
		efi->getDeltaTableHistory().addTableRoleHistory(dtTemp);
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
			//efi->updateMonsterBlood(-deltaBlood);
		}
		efi->getDeltaTableHistory().addTableMonsterHistory(dtTemp);
		break;
	}

	return true;
}

bool EffectFunSet::effectSpecial1(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果：回血无效");

	DeltaTable dtTemp;
	int roundTemp = efi->getEffectAffixes().efRound;
	dtTemp.ID = efi->getEffectAffixes().cardId;
	dtTemp.roundNumber = roundTemp;
	switch (efi->getEffectAffixes().excuteStyle)
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
	efi->setCurentRoundRoleDeltaTable(roundTemp + 1);
	auto itRoleBegin = efi->getRoundRoleDeltaTable().begin();
	auto itRoleEnd = efi->getRoundRoleDeltaTable().end();
	efi->setCurrentRoundMonsterDeltaTable(roundTemp + 1);
	auto itMonsterBegin = efi->getRoundMonsterDeltaTable().begin();
	auto itMonsterEnd = efi->getRoundMonsterDeltaTable().end();
	switch (efi->getEffectAffixes().releaser)
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
			//efi->updateRoleBlood(-deltaBlood);
		}
		efi->getDeltaTableHistory().addTableRoleHistory(dtTemp);
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
			//efi->updateMonsterBlood(-deltaBlood);
		}
		efi->getDeltaTableHistory().addTableMonsterHistory(dtTemp);
		break;
	}
	return true;
}

bool EffectFunSet::effectSpecial2(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果：回甲无效");

	DeltaTable dtTemp;
	int roundTemp = efi->getEffectAffixes().efRound;
	dtTemp.ID = efi->getEffectAffixes().cardId;
	dtTemp.roundNumber = roundTemp;
	switch (efi->getEffectAffixes().excuteStyle)
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
	efi->setCurentRoundRoleDeltaTable(roundTemp + 1);
	auto itRoleBegin = efi->getRoundRoleDeltaTable().begin();
	auto itRoleEnd = efi->getRoundRoleDeltaTable().end();
	efi->setCurrentRoundMonsterDeltaTable(roundTemp + 1);
	auto itMonsterBegin = efi->getRoundMonsterDeltaTable().begin();
	auto itMonsterEnd = efi->getRoundMonsterDeltaTable().end();
	switch (efi->getEffectAffixes().releaser)
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
			//efi->updateRoleArmor(-deltaArmor);
		}
		efi->getDeltaTableHistory().addTableRoleHistory(dtTemp);
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
			//efi->updateMonsterArmor(-deltaArmor);
		}
		efi->getDeltaTableHistory().addTableMonsterHistory(dtTemp);
		break;
	}
	return true;
}

bool EffectFunSet::effectCondition0(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果：当前的血量处于[%d,%d]之间", efi->getEffectArgs().at(2),efi->getEffectArgs().at(3));
	int bloodTemp = 0;
	int leftBlood = efi->getEffectArgs().at(2);
	int rightBlood = efi->getEffectArgs().at(3);

	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = efi->getEffectAffixes().efRound;
	temp.cardId = efi->getEffectAffixes().cardId;

	switch (efi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		bloodTemp = efi->getRoleBlood();
		if (bloodTemp >= leftBlood && bloodTemp <= rightBlood)
		{
		/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.level = efi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			efi->getEffectPQ().pushRoleEffectAffixes(temp);
			return true;
		}
		break;
	case Effect::Releaser::Releaser_Monster:
		bloodTemp = efi->getMonsterBlood();
		if (bloodTemp >= leftBlood && bloodTemp <= rightBlood)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = efi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			efi->getEffectPQ().pushMonsterEffectAffixes(temp);
			return true;
		}
		break;
	}
	return false;
}

bool EffectFunSet::effectCondition1(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果：当前的血量处于[1,%d]之间", efi->getEffectArgs().at(2));

	int bloodTemp = 0;
	int rightBlood = efi->getEffectArgs().at(2);

	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = efi->getEffectAffixes().efRound;
	temp.cardId = efi->getEffectAffixes().cardId;

	switch (efi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		bloodTemp = efi->getRoleBlood();
		if (bloodTemp >= 1 && bloodTemp <= rightBlood)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = efi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			efi->getEffectPQ().pushRoleEffectAffixes(temp);
			return true;
		}
		break;
	case Effect::Releaser::Releaser_Monster:
		bloodTemp = efi->getMonsterBlood();
		if (bloodTemp >= 1 && bloodTemp <= rightBlood)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = efi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			efi->getEffectPQ().pushMonsterEffectAffixes(temp);
			return true;
		}
		break;
	}

	return false;
}

bool EffectFunSet::effectCondition2(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果：当前的血量等于[%d]", efi->getEffectArgs().at(2));
	int bloodTemp = 0;
	int equalBlood = efi->getEffectArgs().at(2);

	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = efi->getEffectAffixes().efRound;
	temp.cardId = efi->getEffectAffixes().cardId;

	switch (efi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		bloodTemp = efi->getRoleBlood();
		if (bloodTemp == equalBlood)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = efi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			efi->getEffectPQ().pushRoleEffectAffixes(temp);
			return true;
		}
		break;
	case Effect::Releaser::Releaser_Monster:
		bloodTemp = efi->getMonsterBlood();
		if (bloodTemp == equalBlood)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = efi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			efi->getEffectPQ().pushMonsterEffectAffixes(temp);
			return true;
		}
		break;
	}

	return false;
}

bool EffectFunSet::effectCondition3(EffectFunInterface* efi)
{

	cocos2d::log("[information] 使用效果：如果敌方血量在[%d, 正无穷]", efi->getEffectArgs().at(2));

	int bloodTemp = efi->getRoleBlood();
	int leftBlood = efi->getEffectArgs().at(2);
	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = efi->getEffectAffixes().efRound;
	temp.cardId = efi->getEffectAffixes().cardId;
	switch (efi->getEffectAffixes().releaser)
	{
		bloodTemp = efi->getRoleBlood();
		if (bloodTemp >= leftBlood)
		{	
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = efi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			efi->getEffectPQ().pushRoleEffectAffixes(temp);
			return true;
		}
		break;
	case Effect::Releaser::Releaser_Monster:
		bloodTemp = efi->getMonsterBlood();
		if (bloodTemp >= leftBlood)
		{			
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Other;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = efi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			efi->getEffectPQ().pushMonsterEffectAffixes(temp);
			return true;
		}
		break;

	}
	return false;
}

bool EffectFunSet::effectCondition4(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果：当前的护甲处于[%d,%d]之间", efi->getEffectArgs().at(2), efi->getEffectArgs().at(3));
	int armorTemp = 0;
	int leftArmor = efi->getEffectArgs().at(2);
	int rightArmor = efi->getEffectArgs().at(3);

	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = efi->getEffectAffixes().efRound;
	temp.cardId = efi->getEffectAffixes().cardId;

	switch (efi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		armorTemp = efi->getRoleArmor();
		if (armorTemp >= leftArmor && armorTemp <= rightArmor)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = efi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			efi->getEffectPQ().pushRoleEffectAffixes(temp);
			return true;
		}
		break;
	case Effect::Releaser::Releaser_Monster:
		armorTemp = efi->getMonsterArmor();
		if (armorTemp >= leftArmor && armorTemp <= rightArmor)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = efi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			efi->getEffectPQ().pushMonsterEffectAffixes(temp);
			return true;
		}
		break;
	}
	return false;
}

bool EffectFunSet::effectCondition5(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果：当前的护甲处于[1,%d]之间", efi->getEffectArgs().at(2));

	int armorTemp = 0;
	int rightArmor = efi->getEffectArgs().at(2);

	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = efi->getEffectAffixes().efRound;
	temp.cardId = efi->getEffectAffixes().cardId;

	switch (efi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		armorTemp = efi->getRoleArmor();
		if (armorTemp >= 1 && armorTemp <= rightArmor)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = efi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			efi->getEffectPQ().pushRoleEffectAffixes(temp);
			return true;
		}
		break;
	case Effect::Releaser::Releaser_Monster:
		armorTemp = efi->getMonsterArmor();
		if (armorTemp >= 1 && armorTemp <= rightArmor)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = efi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			efi->getEffectPQ().pushMonsterEffectAffixes(temp);
			return true;
		}
		break;
	}

	return false;
}

bool EffectFunSet::effectCondition6(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果：当前的护甲等于[%d]", efi->getEffectArgs().at(2));
	int armorTemp = 0;
	int equalArmor = efi->getEffectArgs().at(2);

	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = efi->getEffectAffixes().efRound;
	temp.cardId = efi->getEffectAffixes().cardId;

	switch (efi->getEffectAffixes().releaser)
	{
	case Effect::Releaser::Releaser_Role:
		armorTemp = efi->getRoleArmor();
		if (armorTemp == equalArmor)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = efi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			efi->getEffectPQ().pushRoleEffectAffixes(temp);
			return true;
		}
		break;
	case Effect::Releaser::Releaser_Monster:
		armorTemp = efi->getMonsterArmor();
		if (armorTemp == equalArmor)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = efi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			efi->getEffectPQ().pushMonsterEffectAffixes(temp);
			return true;
		}
		break;
	}

	return false;
}

bool EffectFunSet::effectCondition7(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果：如果敌方护甲在[%d, 正无穷]", efi->getEffectArgs().at(2));

	int armorTemp = efi->getRoleBlood();
	int leftArmor = efi->getEffectArgs().at(2);
	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = efi->getEffectAffixes().efRound;
	temp.cardId = efi->getEffectAffixes().cardId;
	switch (efi->getEffectAffixes().releaser)
	{
		armorTemp = efi->getRoleArmor();
		if (armorTemp >= leftArmor)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = efi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			efi->getEffectPQ().pushRoleEffectAffixes(temp);
			return true;
		}
		break;
	case Effect::Releaser::Releaser_Monster:
		armorTemp = efi->getMonsterArmor();
		if (armorTemp >= leftArmor)
		{
			/////////////////////////////待定/////////////////////////////////////////////
			temp.effectIndex = 2;
			temp.releaser = Effect::Releaser::Releaser_Monster;
			temp.receiver = Effect::Receiver::Receiver_Self;
			temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
			temp.level = efi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
			efi->getEffectPQ().pushMonsterEffectAffixes(temp);
			return true;
		}
		break;
	}
	return false;
}

bool EffectFunSet::effectCondition8(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果：当前的手牌数处于[%d,%d]之间", efi->getEffectArgs().at(2), efi->getEffectArgs().at(3));
	int handCardCountTemp = 0;
	int leftHandCardCount = efi->getEffectArgs().at(2);
	int rightHandCardCount = efi->getEffectArgs().at(3);

	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = efi->getEffectAffixes().efRound;
	temp.cardId = efi->getEffectAffixes().cardId;
	handCardCountTemp = efi->getRoleHandCount();
	if (handCardCountTemp >= leftHandCardCount && handCardCountTemp <= rightHandCardCount)
	{
		/////////////////////////////待定/////////////////////////////////////////////
		temp.effectIndex = 2;
		temp.releaser = Effect::Releaser::Releaser_Monster;
		temp.receiver = Effect::Receiver::Receiver_Self;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = efi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
		efi->getEffectPQ().pushRoleEffectAffixes(temp);
		return true;
	}
	return false;
}

bool EffectFunSet::effectCondition9(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果：当前的手牌数处于[1,%d]之间", efi->getEffectArgs().at(2));

	int handCardCountTemp = 0;
	int rightHandCardCount = efi->getEffectArgs().at(2);

	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = efi->getEffectAffixes().efRound;
	temp.cardId = efi->getEffectAffixes().cardId;
	handCardCountTemp = efi->getRoleHandCount();
	if (handCardCountTemp >= 1 && handCardCountTemp <= rightHandCardCount)
	{
		/////////////////////////////待定/////////////////////////////////////////////
		temp.effectIndex = 2;
		temp.releaser = Effect::Releaser::Releaser_Monster;
		temp.receiver = Effect::Receiver::Receiver_Self;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = efi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
		efi->getEffectPQ().pushRoleEffectAffixes(temp);
		return true;
	}
	return false;
}

bool EffectFunSet::effectCondition10(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果：当前的手牌数等于[%d]", efi->getEffectArgs().at(2));

	int handCardCountTemp = 0;
	int equalHandCardCount = efi->getEffectArgs().at(2);
	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = efi->getEffectAffixes().efRound;
	temp.cardId = efi->getEffectAffixes().cardId;
	handCardCountTemp = efi->getRoleHandCount();
	if (handCardCountTemp == equalHandCardCount)
	{
		/////////////////////////////待定/////////////////////////////////////////////
		temp.effectIndex = 2;
		temp.releaser = Effect::Releaser::Releaser_Monster;
		temp.receiver = Effect::Receiver::Receiver_Self;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = efi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
		efi->getEffectPQ().pushRoleEffectAffixes(temp);
		return true;
	}
	return false;
}

bool EffectFunSet::effectCondition11(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果：如果敌方手牌数在[%d, 正无穷]", efi->getEffectArgs().at(2));

	int handCardCountTemp = 0;
	int leftHandCardCount = efi->getEffectArgs().at(2);
	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int roundTemp = efi->getEffectAffixes().efRound;
	temp.cardId = efi->getEffectAffixes().cardId;
	handCardCountTemp = efi->getRoleHandCount();
	if (handCardCountTemp >= leftHandCardCount)
	{
		/////////////////////////////待定/////////////////////////////////////////////
		temp.effectIndex = 2;
		temp.releaser = Effect::Releaser::Releaser_Monster;
		temp.receiver = Effect::Receiver::Receiver_Self;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = efi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
		efi->getEffectPQ().pushRoleEffectAffixes(temp);
		return true;
	}
	return false;
}

bool EffectFunSet::effectCondition12(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果：如果血量在[%d,%d]之间", efi->getEffectArgs().at(2), efi->getEffectArgs().at(3));

	int leftBlood = efi->getEffectArgs().at(2);
	int rightBlood = efi->getEffectArgs().at(3);
	int flag = 0;
	int efRoundTemp = efi->getEffectAffixes().efRound;
	int bloodMax = efi->getMonsterBloodMax();

	int roundTemp = 1;

	int bloodTemp = bloodMax;

	while (efRoundTemp > 1)
	{
		bloodTemp += efi->getRoundMonsterDeltaTable(roundTemp, DeltaTable::RoundLevel::RoundLevel_Total).front().effectTable[0][1] + efi->getRoundRoleDeltaTable(roundTemp, DeltaTable::RoundLevel::RoundLevel_Total).front().effectTable[0][1];

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
		int roundTemp = efi->getEffectAffixes().efRound;
		temp.cardId = efi->getEffectAffixes().cardId;
		temp.effectIndex = 1;
		temp.releaser = Effect::Releaser::Releaser_Monster;
		temp.receiver = Effect::Receiver::Receiver_Self;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = efi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
		efi->getEffectPQ().pushMonsterEffectAffixes(temp);
		return true;
	}
	return false;
}

bool EffectFunSet::effectCondition13(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果：开局起血量第一次处于[负无穷，0]");
	int flag = 0;
	int efRoundTemp = efi->getEffectAffixes().efRound;
	int bloodMax = efi->getMonsterBloodMax();

	int roundTemp = 1;

	int bloodTemp = bloodMax;

	while (efRoundTemp > 1)
	{
		bloodTemp += efi->getRoundMonsterDeltaTable(roundTemp, DeltaTable::RoundLevel::RoundLevel_Total).front().effectTable[0][1] + efi->getRoundRoleDeltaTable(roundTemp, DeltaTable::RoundLevel::RoundLevel_Total).front().effectTable[0][1];

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
	temp.cardId = efi->getEffectAffixes().cardId;
	if (flag == 1)
	{
		temp.effectIndex = 1;
		temp.releaser = Effect::Releaser::Releaser_Monster;
		temp.receiver = Effect::Receiver::Receiver_Other;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = efi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
		efi->getEffectPQ().pushMonsterEffectAffixes(temp);

		return true;
	}
	else if (temp.cardId == 30019)
	{
		temp.effectIndex = 2;
		temp.releaser = Effect::Releaser::Releaser_Monster;
		temp.receiver = Effect::Receiver::Receiver_Self;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = efi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
		efi->getEffectPQ().pushMonsterEffectAffixes(temp);
		return false;
	}
}

bool EffectFunSet::effectCondition14(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果：开局起血量第一次处于[%d，血量上限]",efi->getEffectArgs().at(2));

	int leftBlood = efi->getEffectArgs().at(2);
	int flag = 0;
	int efRoundTemp = efi->getEffectAffixes().efRound;
	int bloodMax = efi->getMonsterBloodMax();

	int roundTemp = 1;

	int bloodTemp = bloodMax;

	while (efRoundTemp > 1)
	{
		bloodTemp += efi->getRoundMonsterDeltaTable(roundTemp, DeltaTable::RoundLevel::RoundLevel_Total).front().effectTable[0][1] + efi->getRoundRoleDeltaTable(roundTemp, DeltaTable::RoundLevel::RoundLevel_Total).front().effectTable[0][1];

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
	temp.cardId = efi->getEffectAffixes().cardId;
	if (flag == 1)
	{
		//////////////////////////待定////////////////////////////////////////////////
		temp.effectIndex = 1;
		temp.releaser = Effect::Releaser::Releaser_Monster;
		temp.receiver = Effect::Receiver::Receiver_Self;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = efi->getEffectPQ().getMonsterEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
		efi->getEffectPQ().pushMonsterEffectAffixes(temp);

		return true;
	}
	return false;
	
}

bool EffectFunSet::effectCondition15(EffectFunInterface* efi)
{
	cocos2d::log("[information] 使用效果：如果自身血量减少 ");

	int roundTemp = efi->getEffectAffixes().efRound;
	int bloodTemp = 0;
	int bloodRet = 0;
	efi->setCurentRoundRoleDeltaTable(roundTemp);
	auto itRoleBegin = efi->getRoundRoleDeltaTable().begin();
	auto itRoleEnd = efi->getRoundRoleDeltaTable().end();
	efi->setCurrentRoundMonsterDeltaTable(roundTemp);
	auto itMonsterBegin = efi->getRoundMonsterDeltaTable().begin();
	auto itMonsterEnd = efi->getRoundMonsterDeltaTable().end();
	
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

		int roundTemp = efi->getEffectAffixes().efRound;
		temp.cardId = efi->getEffectAffixes().cardId;
		temp.effectIndex = 2;
		temp.releaser = Effect::Releaser::Releaser_Role;
		temp.receiver = Effect::Receiver::Receiver_Other;
		temp.excuteStyle = Effect::ExcuteStyle::ExcuteStyle_After;
		temp.level = efi->getEffectPQ().getRoleEPQLevelMaxByRoundAndInterval(0, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
		efi->getEffectPQ().pushRoleEffectAffixes(temp);
		return true;
	}
	return false;
}