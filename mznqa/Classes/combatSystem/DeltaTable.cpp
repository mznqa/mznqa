#pragma execution_character_set("utf-8")

#include "DeltaTable.h"
#include "CombatSystemInterface.h"

void DeltaTable::setEffectHistoryInfo(const EffectAffixes& ea)
{
	this->ID = ea.cardId;
	this->releaser = ea.releaser;
	this->receiver = ea.receiver;
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
		switch (releaser)
		{
		case Effect::Releaser::Releaser_Role:
			if (releaser == receiver)
				this->effectTable[0][0] = deltaBlood;
			else
				this->effectTable[0][1] = deltaBlood;
			break;
		case Effect::Releaser::Releaser_Monster:
			if (releaser == receiver)
				this->effectTable[0][1] = deltaBlood;
			else
				this->effectTable[0][0] = deltaBlood;
			break;
		}
		CombatSystemInterface::Instance()->getDeltaTableHistory().addTableRoleHistory(*this);
}
