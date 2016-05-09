#pragma execution_character_set("utf-8")

#include "DeltaTable.h"
#include "combatSystem/CombatSystemInterface.h"

int DeltaTable::roundNumber = EffectAffixes::invalidEffectRoundValue;

int DeltaRound::roundNumber = EffectAffixes::invalidEffectRoundValue;

CombatSystemInterface* const DeltaTable::combatSystemInterface = CombatSystemInterface::Instance();

void DeltaTable::setEffectHistoryInfo(const EffectAffixes& effectAffixes)
{
	this->ID = effectAffixes.cardId;
	this->releaser = effectAffixes.releaser;
	this->receiver = effectAffixes.receiver;
	this->roundNumber = effectAffixes.efRound;
	switch (effectAffixes.excuteStyle)
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
	{
		this->flag = Flag_Blood_Role;
		this->effectTable[0][0] = deltaBlood;
	}
	else
	{
		this->flag = Flag_Blood_Monster;
		this->effectTable[0][1] = deltaBlood;
	}
	
}

void DeltaTable::setEffectTableArmor(const int deltaArmor)
{
	if (releaser == receiver)
	{
		this->flag = Flag_Armor_Role;
		this->effectTable[1][0] = deltaArmor;
	}
	else
	{
		this->flag = Flag_Armor_Monster;
		this->effectTable[1][1] = deltaArmor;
	}
}

void DeltaTable::setEffectTableHandCardCount(const int deltaHandCardCount)
{
	this->effectTable[2][0] = deltaHandCardCount;
	this->flag = Flag_Hand_Role;
}

void DeltaTable::setEffectTableDrawCardCount(const int deltaDrawCardCount)
{
	this->effectTable[3][0] = deltaDrawCardCount;
	this->flag = Flag_Draw_Role;
}

void DeltaTable::setEffectTableDiscardCount(const int deltaDiscardCount)
{
	this->effectTable[4][0] = deltaDiscardCount;
	this->flag = Flag_Discard_Role;
}

void DeltaTable::addHistoryEffect()
{
	switch (releaser)
	{
	case EffectAffixes::Releaser::Releaser_Role:
		combatSystemInterface->getDeltaTableHistory().addTableHistoryRole(*this);
		break;
	case EffectAffixes::Releaser::Releaser_Monster:
		combatSystemInterface->getDeltaTableHistory().addTableHistoryMonster(*this);
		break;
	}
}

