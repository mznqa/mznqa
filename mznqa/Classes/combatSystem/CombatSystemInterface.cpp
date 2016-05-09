#pragma execution_character_set("utf-8")

#include "combatSystem/CombatSystemInterface.h"

CombatSystemInterface* CombatSystemInterface::Instance()
{
	static CombatSystemInterface csinterface;
	return &csinterface;
}

int CombatSystemInterface::getBloodRole()
{
	return role->getBloodValue();
}

int CombatSystemInterface::getArmorRole()
{
	return role->getArmorValue();
}

int CombatSystemInterface::getBloodMaxRole()
{
	return role->getBloodValueMax();
}

int CombatSystemInterface::getHandCountRole()
{
	return role->getHandCardCount();
}

void CombatSystemInterface::updateHandCountRole(int delta)
{
	role->updateHandCount(delta);
	return;
}

void CombatSystemInterface::setDiscountCountRole(int delta)
{
	role->setDiscardCount(delta);
	return;
}

void CombatSystemInterface::updateDrawCardCountRole(int delta)
{
	role->updateDrawCardCount(delta);
	return;
}

void CombatSystemInterface::updateBloodRole(int delta)
{
	role->updateBloodValue(delta);
	return;
}

void CombatSystemInterface::updateArmorRole(int delta)
{
	role->updateArmorValue(delta);
	return;
}

int CombatSystemInterface::getBloodMonster()
{
	return monster.getBloodValue();
}

int CombatSystemInterface::getArmorMonster()
{
	return monster.getArmorValue();
}

int CombatSystemInterface::getBloodMaxMonster()
{
	return monster.getBloodValueMax();
}

void CombatSystemInterface::updateBloodMonster(int delta)
{
	monster.updateBloodValue(delta);
	return;
}

void CombatSystemInterface::updateArmorMonster(int delta)
{
	monster.updateArmorValue(delta);
	return;
}

const EffectAffixes& CombatSystemInterface::getCurrentEffectAffixes()
{
	return CombatSystem::getCurrentEffectAffixes();
}

EffectPQ& CombatSystemInterface::getEffectPQ()
{
	return CombatSystem::getEffectPQ();
}
