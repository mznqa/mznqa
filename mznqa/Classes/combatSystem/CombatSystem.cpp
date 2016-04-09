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
	cocos2d::log("[information] 执行 角色前 的持续效果，当前回合为 %d ", round);
	while (true)
	{
		EffectEntity ee = epq.getRoleNextEffect();
		if (ee.cardId == -1)
		{
			cocos2d::log("[information] 当前回合的角色技能，已经没有可执行的效果了!");
			return;
		}
		//若该效果属于持续后执行，则优先级在增加100
		if (ee.level / 100 == 1)
		{
			break;
		}
		//执行效果
		EffectFunSet::getFunByIndex(ee.effectIndex)(CardSet::Instance()->getCardSkillByID(ee.cardId)->getEffectSet().back().getArgs());
	}

}

void CombatSystem::excuteRoleInCombatEffect(int cardId)
{
	cocos2d::log("[information] 执行 角色中 的效果，当前回合为 %d ", round);
	const CardSkill *cs = CardSet::Instance()->getCardSkillByID(cardId);
	EffectEntity temp(-1,-1,-1);
	int effectSize = cs->getEffectSet().size();
	while (effectSize--)
	{
		int startRound = cs->getEffectSet().at(effectSize).getArgs().at(0);
		int continueRound = cs->getEffectSet().at(effectSize).getArgs().at(1);
		temp.cardId = cardId;
		temp.effectIndex = cs->getEffectSet().at(effectSize).getFunIndex();
		while (continueRound--)
		{
			temp.level = (continueRound + startRound) * 200 + epq.getRoleEPQLevelMaxByRound(continueRound) + 1;
			if (cs->getEffectSet().at(effectSize).getArgs().size() == 2)
			{
				temp.level += 100;
			}
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
		//若该效果属于角色持续后执行，则跳过该效果的执行
		if (ee.level / 100 == 1)
		{
			break;
		}
		EffectFunSet::getFunByIndex(ee.effectIndex)(CardSet::Instance()->getCardSkillByID(ee.cardId)->getEffectSet().back().getArgs()
			);
	}
}

void CombatSystem::excuteRoleAfterCombatEffect()
{
	cocos2d::log("[information] 执行 角色后 的持续效果，当前回合为 %d ", round);

	while (true)
	{
		EffectEntity ee = epq.getRoleNextEffect();
		if (ee.cardId == -1)
		{
			cocos2d::log("[information] 当前回合的角色技能，已经没有可执行的效果了!");
			return;
		}
		EffectFunSet::getFunByIndex(ee.effectIndex)(CardSet::Instance()->getCardSkillByID(ee.cardId)->getEffectSet().back().getArgs());
		epq.popRoleEffect();
	}
}


void CombatSystem::executeMonsterBeforeTheCombatEffect()
{
	cocos2d::log("[information] 执行 怪物前 的持续效果，当前回合为 %d ", round);

	while (true)
	{
		EffectEntity ee = epq.getMonsterNextEffect();
		if (ee.cardId == -1)
		{
			cocos2d::log("[information] 当前回合的怪物技能，已经没有可执行的效果了!");
			return;
		}
		if (ee.level/100 == 1)
		{
			break;
		}
		EffectFunSet::getFunByIndex(ee.effectIndex)(CardSet::Instance()->getCardSkillByID(ee.cardId)->getEffectSet().back().getArgs());
	}

}

void CombatSystem::excuteMonsterInCombatEffect(int cardId)
{
	cocos2d::log("[information] 执行 怪物中 的效果，当前回合为 %d ", round);
	const CardSkill *cs = CardSet::Instance()->getCardSkillByID(cardId);
	EffectEntity temp(-1, -1, -1);
	int effectSize = cs->getEffectSet().size();
	while (effectSize--)
	{
		int startRound = cs->getEffectSet().at(effectSize).getArgs().at(0);
		int continueRound = cs->getEffectSet().at(effectSize).getArgs().at(1);
		temp.cardId = cardId;
		temp.effectIndex = cs->getEffectSet().at(effectSize).getFunIndex();
		while (continueRound--)
		{
			temp.level = (continueRound + startRound) * 200 + epq.getMonsterEPQLevelMaxByRound(continueRound) + 1;
			if (cs->getEffectSet().at(effectSize).getArgs().size() == 2)
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
		if (ee.level/100 == 1)
		{
			break;
		}
		EffectFunSet::getFunByIndex(ee.effectIndex)(CardSet::Instance()->getCardSkillByID(ee.cardId)->getEffectSet().back().getArgs());
	}

}
 
void CombatSystem::excuteMonsterAfterCombatEffect()
{
	cocos2d::log("[information] 执行 怪物后 的持续效果，当前回合为 %d ", round);

	while (true)
	{
		EffectEntity ee = epq.getMonsterNextEffect();

		if (ee.cardId == -1)
		{
			cocos2d::log("[information] 当前回合的怪物技能，已经没有可执行的效果了!");
			return;
		}
	EffectFunSet::getFunByIndex(ee.effectIndex)(CardSet::Instance()->getCardSkillByID(ee.cardId)->getEffectSet().back().getArgs());
		epq.popMonsterEffect();
	}
}

void CombatSystem::excuteCombat(int roleUseCardId,int monsterUseCardId)
{
	//执行全局效果
	executeGlobalEffect();

	//战斗前执行效果
	executeRoleBeforeTheCombatEffect();
	executeMonsterBeforeTheCombatEffect();
	
	//战斗时执行效果
	excuteRoleInCombatEffect(roleUseCardId);
	excuteMonsterInCombatEffect(monsterUseCardId);
	
	//战斗后执行效果
	excuteRoleAfterCombatEffect();
	excuteMonsterAfterCombatEffect();
}

void CombatSystem::pushRoleUseCardId(int useCardId)
{
	roleUseCardId.push(useCardId);
}

void CombatSystem::pushMonsterUseCardId(int useCardId)
{
	monsterUseCardId.push(useCardId);
}

void CombatSystem::popRoleUseCardId()
{
	roleUseCardId.pop();
}

void CombatSystem::popMonsterUseCardId()
{
	monsterUseCardId.pop();
}

void CombatSystem::test()
{
	cocos2d::log("[warning] 注意：即将进入战斗系统！");
	
	for (int i = 0; i < 5;++i)
	{
		pushMonsterUseCardId(i + 30004);
	}
	for (int i = 0; i < 5;++i)
	{
		pushRoleUseCardId(i + 30026);
	}

	while (!roleUseCardId.empty() || !monsterUseCardId.empty())
	{
		excuteCombat(roleUseCardId.front(), monsterUseCardId.front());
		popRoleUseCardId();
		popMonsterUseCardId();
	}
	
	cocos2d::log("[warning] 注意：退出战斗系统！");

}
