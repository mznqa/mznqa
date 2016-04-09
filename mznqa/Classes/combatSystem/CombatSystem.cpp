#pragma execution_character_set("utf-8")

#include "combatSystem/CombatSystem.h"
#include "staticData/CardSet.h"
#include "card/CardSkill.h"
#include "effect/EffectFunSet.h"
#include "cocos2d.h"

int CombatSystem::round = 0;

CombatSystem::CombatSystem()
{

}

CombatSystem::~CombatSystem()
{
	
}


void CombatSystem::executeGlobalEffect()
{
	round++;
	epq.decreaseRoleEffectLevel();
	epq.decreaseMonsterEffectLevel();

}

void CombatSystem::executeRoleBeforeTheCombatEffect()
{
	while (true)
	{

		EffectEntity ee = epq.getRoleNextEffect();
		if (ee.cardId == -1)
		{
			cocos2d::log("[information] 当前回合的角色技能，已经没有可执行的效果了!");
			return;
		}
		EffectFunSet::getFunByIndex(ee.cardId)(CardSet::Instance()->getCardSkillByID(ee.cardId)->getEffectSet().back().getArgs());
	}

}

void CombatSystem::excuteRoleInCombatEffect(int cardId)
{
	const CardSkill *cs = CardSet::Instance()->getCardSkillByID(cardId);
	
	EffectEntity temp(-1,-1,-1);
	int indexTemp = 0;


	int effectSize = cs->getEffectSet().size();
	while (effectSize--)
	{
		int startRound = cs->getEffectSet().back().getArgs().at(0);
		int continueRound = cs->getEffectSet().back().getArgs().at(1);

		temp.cardId = cardId;
		temp.effectIndex = indexTemp++;
		while (--continueRound)
		{
			temp.level = (continueRound + startRound) * 100 + epq.getRoleEPQLevelMaxByRound(continueRound + 1) + 1;
			epq.pushRoleEffect(temp);
		}
		
	}

	while (epq.isRoleEffectPQEmpty() == false)
	{
		EffectEntity ee = epq.getRoleNextEffect();
		if (ee.cardId == -1)
		{
			cocos2d::log("[information] 当前回合的角色技能，已经没有可执行的效果了!");
			return;
		}
		

		
		(EffectFunSet::getFunByIndex(ee.cardId))(

			CardSet::Instance()->getCardSkillByID(ee.cardId)->getEffectSet().back().getArgs()
			);
	}

}

void CombatSystem::excuteRoleAfterCombatEffect()
{
	while (true)
	{
		EffectEntity ee = epq.getRoleNextEffect();
		if (ee.cardId == -1)
		{
			cocos2d::log("[information] 当前回合的角色技能，已经没有可执行的效果了!");
			return;
		}
		EffectFunSet::getFunByIndex(ee.cardId)(CardSet::Instance()->getCardSkillByID(ee.cardId)->getEffectSet().back().getArgs());
		epq.popRoleEffect();
	}
}


void CombatSystem::executeMonsterBeforeTheCombatEffect()
{
	while (true)
	{
		EffectEntity ee = epq.getMonsterNextEffect();
		if (ee.cardId == -1)
		{
			cocos2d::log("[information] 当前回合的怪物技能，已经没有可执行的效果了!");
			return;
		}
		EffectFunSet::getFunByIndex(ee.cardId)(CardSet::Instance()->getCardSkillByID(ee.cardId)->getEffectSet().rbegin()->getArgs());
	}

}

void CombatSystem::excuteMonsterInCombatEffect(int cardId)
{
	const CardSkill *cs = CardSet::Instance()->getCardSkillByID(cardId);

	EffectEntity temp(-1, -1, -1);
	int indexTemp = 0;

	int effectSize = cs->getEffectSet().size();
	while (effectSize--)
	{
		int startRound = cs->getEffectSet().back().getArgs().at(0);
		int continueRound = cs->getEffectSet().back().getArgs().at(1);


		temp.cardId = cardId;
		temp.effectIndex = indexTemp++;
		while (continueRound--)
		{
			temp.level = (continueRound + startRound) * 200 + epq.getMonsterEPQLevelMaxByRound(continueRound + 1) + 1;
			if (cs->getEffectSet().back().getArgs().size() == 2)
			{
				temp.level += 100;
			}
			epq.pushMonsterEffect(temp);
		}

	}

	while (epq.isMonsterEffectPQEmpty() == false)
	{
		EffectEntity ee = epq.getMonsterNextEffect();
		if (ee.cardId == -1)
		{
			cocos2d::log("[information] 当前回合的怪物技能，已经没有可执行的效果了!");
			return;
		}
		EffectFunSet::getFunByIndex(ee.cardId)(CardSet::Instance()->getCardSkillByID(ee.cardId)->getEffectSet().back().getArgs());
	}

}
 
void CombatSystem::excuteMonsterAfterCombatEffect()
{
	while (true)
	{
		EffectEntity ee = epq.getMonsterNextEffect();

		if (ee.cardId == -1)
		{
			cocos2d::log("[information] 当前回合的怪物技能，已经没有可执行的效果了!");
			return;
		}
	EffectFunSet::getFunByIndex(ee.cardId)(CardSet::Instance()->getCardSkillByID(ee.cardId)->getEffectSet().back().getArgs());
		epq.popMonsterEffect();
	}
}

void CombatSystem::excuteCombat(int cardId)
{
	//执行全局效果
	executeGlobalEffect();

	//战斗前执行效果
	executeRoleBeforeTheCombatEffect();
	executeMonsterBeforeTheCombatEffect();
	
	//战斗时执行效果
	excuteRoleInCombatEffect(cardId);
	excuteMonsterInCombatEffect(cardId);
	
	//战斗后执行效果
	excuteRoleAfterCombatEffect();
	excuteMonsterAfterCombatEffect();
}

void CombatSystem::test()
{
	std::vector<int> id = { 1, 2, 3, 4, 5 };
	auto it = id.begin();
	for (it; it != id.end(); ++it)
	{
		excuteCombat(*it);
	}
	while (!id.empty())
	{
		id.pop_back();
	}

}
