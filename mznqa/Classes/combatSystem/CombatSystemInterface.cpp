#pragma execution_character_set("utf-8")

#include "combatSystem/CombatSystemInterface.h"

CombatSystemInterface* CombatSystemInterface::Instance()
{
	static CombatSystemInterface csinterface;
	return &csinterface;
}

int CombatSystemInterface::getRoleBlood()
{
	return role->getBloodValue();
}

int CombatSystemInterface::getRoleArmor()
{
	return role->getArmorValue();
}

int CombatSystemInterface::getRoleBloodMax()
{
	return role->getBloodValueMax();
}

int CombatSystemInterface::getRoleHandCount()
{
	return role->getHandCardCount();
}

void CombatSystemInterface::updateRoleHandCount(int delta)
{
	role->updateHandCount(delta);
	return;
}

void CombatSystemInterface::setRoleDiscountCount(int delta)
{
	role->setDiscardCount(delta);
	return;
}

void CombatSystemInterface::updateRoleDrawCardCount(int delta)
{
	role->updateDrawCardCount(delta);
	return;
}

void CombatSystemInterface::updateRoleBlood(int delta)
{
	role->updateBloodValue(delta);
	return;
}

void CombatSystemInterface::updateRoleArmor(int delta)
{
	role->updateArmorValue(delta);
	return;
}

int CombatSystemInterface::getMonsterBlood()
{
	return monster.getBloodValue();
}

int CombatSystemInterface::getMonsterArmor()
{
	return monster.getArmorValue();
}

int CombatSystemInterface::getMonsterBloodMax()
{
	return monster.getBloodValueMax();
}

void CombatSystemInterface::updateMonsterBlood(int delta)
{
	monster.updateBloodValue(delta);
	return;
}

void CombatSystemInterface::updateMonsterArmor(int delta)
{
	monster.updateArmorValue(delta);
	return;
}


const std::vector<DeltaTable>& CombatSystemInterface::getRoundRoleDeltaTable(int round, DeltaTable::RoundLevel index)
{
	return dtHistory.getRoundRoleTable(round, index);
}

const std::vector<DeltaTable>& CombatSystemInterface::getCurrentRoundRoleDeltaTable(const int round)
{
	return dtHistory.getCurrentRoundRoleTable(round);

}

const std::vector<DeltaTable>& CombatSystemInterface::getRoundMonsterDeltaTable(int round, DeltaTable::RoundLevel index)
{
	return dtHistory.getRoundMonsterTable(round, index);
}

const std::vector<DeltaTable>& CombatSystemInterface::getCurrentRoundMonsterDeltaTable(int round)
{
	return dtHistory.getCurrentRoundMonsterTable(round);
}

const EffectAffixes& CombatSystemInterface::getCurrentEffectAffixes()
{
	return CombatSystem::getEffectAffixes();
}

EffectPQ& CombatSystemInterface::getEffectPQ()
{
	return CombatSystem::getEffectPQ();
}
