#pragma execution_character_set("utf-8")

#include "combatSystem/CombatSystemInterface.h"

CombatSystemInterface* CombatSystemInterface::Instance()
{
	static CombatSystemInterface csinterface;
	return &csinterface;
}

int CombatSystemInterface::getRoleBlood()
{
	return Role::Instance()->getBloodValue();
}

int CombatSystemInterface::getRoleArmor()
{
	return Role::Instance()->getArmorValue();
}

int CombatSystemInterface::getRoleBloodMax()
{
	return Role::Instance()->getBloodValueMax();
}

int CombatSystemInterface::getRoleHandCount()
{
	return Role::Instance()->getHandCardCount();
}

void CombatSystemInterface::updateRoleHandCount(int delta)
{
	Role::Instance()->updateHandCount(delta);
	return;
}

void CombatSystemInterface::setRoleDiscountCount(int delta)
{
	Role::Instance()->setDiscardCount(delta);
	return;
}

void CombatSystemInterface::updateRoleDrawCardCount(int delta)
{
	Role::Instance()->updateDrawCardCount(delta);
	return;
}

void CombatSystemInterface::updateRoleBlood(int delta)
{
	Role::Instance()->updateBloodValue(delta);
	return;
}

void CombatSystemInterface::updateRoleArmor(int delta)
{
	Role::Instance()->updateArmorValue(delta);
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

void CombatSystemInterface::setCurrentRoundMonsterDeltaTable(int round)
{
	deltaMonster = dtHistory.getCurrentRoundMonsterTable(round);
	return;
}

const std::vector<DeltaTable>& CombatSystemInterface::getRoundRoleDeltaTable(int round, DeltaTable::RoundLevel index)
{
	return dtHistory.getRoundRoleTable(round, index);
}

const std::vector<DeltaTable>& CombatSystemInterface::getRoundMonsterDeltaTable(int round, DeltaTable::RoundLevel index)
{
	return dtHistory.getRoundMonsterTable(round, index);
}

EffectPQ& CombatSystemInterface::getEffectPQ()
{
	return CombatSystem::getEffectPQ();
}

void CombatSystemInterface::setCurentRoundRoleDeltaTable(int round)
{
	deltaRole = dtHistory.getCurrentRoundRoleTable(round);
	return;
}
