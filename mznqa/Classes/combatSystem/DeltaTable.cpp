#pragma execution_character_set("utf-8")

#include "DeltaTable.h"
#include "CombatSystemInterface.h"

void DeltaTable::setEffectHistoryInfo(const EffectAffixes& ea)
{
	this->ID = ea.cardId;
	this->releaser = ea.releaser;
	this->receiver = ea.receiver;
	this->roundNumber = ea.efRound;
	switch (ea.excuteStyle)
	{
	case Effect::ExcuteStyle::ExcuteStyle_Before:
		this->roundLevel = DeltaTable::RoundLevel::RoundLevel_Before;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_In:
		this->roundLevel = DeltaTable::RoundLevel::RoundLevel_In;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_After:
		this->roundLevel = DeltaTable::RoundLevel::RoundLevel_After;
		break;
	}
}

void DeltaTable::setEffectTableBlood(const int deltaBlood)
{
	if (releaser == receiver)
		this->effectTable[0][0] = deltaBlood;
	else
		this->effectTable[0][1] = deltaBlood;
	addHistoryEffect();
}

void DeltaTable::setEffectTableArmor(const int deltaArmor)
{
	if (releaser == receiver)
		this->effectTable[1][0] = deltaArmor;
	else
		this->effectTable[1][1] = deltaArmor;
	addHistoryEffect();
}

void DeltaTable::setEffectTableHandCardCount(const int deltaHandCardCount)
{
	this->effectTable[2][0] = deltaHandCardCount;
	addHistoryEffect();
}

void DeltaTable::setEffectTableDrawCardCount(const int deltaDrawCardCount)
{
	this->effectTable[3][0] = deltaDrawCardCount;
	addHistoryEffect();
}

void DeltaTable::setEffectTableDiscardCount(const int deltaDiscardCount)
{
	this->effectTable[4][0] = deltaDiscardCount;
	addHistoryEffect();
}

void DeltaTable::addHistoryEffect()
{
	switch (releaser)
	{
	case Effect::Releaser::Releaser_Role:
		CombatSystemInterface::Instance()->getDeltaTableHistory().addTableRoleHistory(*this);
		break;
	case Effect::Releaser::Releaser_Monster:
		CombatSystemInterface::Instance()->getDeltaTableHistory().addTableMonsterHistory(*this);
		break;
	}
}
