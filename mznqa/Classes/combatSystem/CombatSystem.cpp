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

void CombatSystem::executeGlobalOperation()
{
	round++;
	epq.decreaseRoleEffectLevel();
	epq.decreaseMonsterEffectLevel();

}

void CombatSystem::executeRoleBeforeTheCombatOperation()
{
	cocos2d::log("[information] 执行 角色战斗前 的操作，当前回合为 %d ", round);
	while (true)
	{
		EffectAffixes ea = epq.getRoleEffectAffixesByInterval(EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log("[information] 角色战斗前，已经没有可执行的效果了！");
			return;
		}
		//若该优先级所属的效果是在角色战斗后执行的，则在角色战斗前跳过该效果的执行
		if (ea.level / EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left == 1)
		{
			break;
		}
		//执行角色战斗前的效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popRoleEffectAffixes();
	}

}

void CombatSystem::excuteRoleInCombatOperation(int cardId)
{
	cocos2d::log("[information] 执行 角色战斗时 的操作，当前回合为 %d ", round);
	const CardSkill *cs = CardSet::Instance()->getCardSkillByID(cardId);
	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int effectSize = cs->getEffectSet().size();
	while (effectSize--)
	{
		int startRound = cs->getEffectSet().at(effectSize).getArgs().at(0);
		int continueRound = cs->getEffectSet().at(effectSize).getArgs().at(1);
		temp.cardId = cardId;
		temp.effectIndex = effectSize;
		while (continueRound--)
		{
			temp.level = (continueRound + startRound) * EffectAffixes::roundEffectLevel;
			//若该效果是属于当前回合内执行
			if (startRound == 0)
			{
				temp.level += epq.getRoleEPQLevelMaxByRoundAndInterval(continueRound, EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Right) + 1;
				//若该效果属于角色战斗后执行
				if (cs->getEffectSet().at(effectSize).getArgs().size() == 2)
				{
					temp.level += EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left - EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Left;
				}
			}
			//若该效果是不属于当前回合执行
			else
			{
				temp.level += epq.getRoleEPQLevelMaxByRoundAndInterval(continueRound, EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Right) + 1;
				//若该效果属于角色战斗后执行
				if (cs->getEffectSet().at(effectSize).getArgs().size() == 2)
				{
					temp.level += EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left - EffectAffixes::EffectLevelInterval_Before_Left;
				}
			}
			epq.pushRoleEffectAffixes(temp);
		}
	}

	while (epq.isRoleEffectPQEmpty() == false)
	{
		EffectAffixes ea = epq.getRoleEffectAffixesByInterval(EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log("[information] 角色战斗时，已经没有可执行的效果了!");
			return;
		}
		//若该优先级所属的效果是在角色战斗后执行的，则在角色战斗时跳过该效果的执行
		if (ea.level / EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left == 1)
		{
			break;
		}
		//执行角色战斗时效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popRoleEffectAffixes();
	}
}

void CombatSystem::excuteRoleAfterCombatOperation()
{
	cocos2d::log("[information] 执行 角色战斗后 的操作，当前回合为 %d ", round);
	while (true)
	{
		EffectAffixes ea = epq.getRoleEffectAffixesByInterval(EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log("[information] 角色战斗后，已经没有可执行的效果了!");
			return;
		}
		//执行角色战斗后效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popRoleEffectAffixes();
	}
}

void CombatSystem::executeMonsterBeforeTheCombatOperator()
{
	cocos2d::log("[information] 执行 怪物战斗前 的操作，当前回合为 %d ", round);
	while (true)
	{
		EffectAffixes ea = epq.getMonsterEffectAffixesByInterval(EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Left,EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log("[information] 怪物战斗前，已经没有可执行的效果了!");
			return;
		}
		//若该优先级所属的效果是在怪物战斗后执行的，则在怪物战斗前跳过该效果的执行
		if (ea.level / EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left == 1)
		{
			break;
		}
		//执行怪物战斗前的效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popMonsterEffectAffixes();
	}

}

void CombatSystem::excuteMonsterInCombatOperator(int cardId)
{
	cocos2d::log("[information] 执行 怪物战斗时 的操作，当前回合为 %d ", round);
	const CardSkill *cs = CardSet::Instance()->getCardSkillByID(cardId);
	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int effectSize = cs->getEffectSet().size();
	while (effectSize--)
	{
		int startRound = cs->getEffectSet().at(effectSize).getArgs().at(0);
		int continueRound = cs->getEffectSet().at(effectSize).getArgs().at(1);
		temp.cardId = cardId;
		temp.effectIndex = effectSize;
		while (continueRound--)
		{
			temp.level = (continueRound + startRound) * EffectAffixes::roundEffectLevel;
			//若该效果是属于当前回合内执行
			if (startRound == 0)
			{
				temp.level += epq.getMonsterEPQLevelMaxByRoundAndInterval(continueRound, EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Right) + 1;
				//若该效果属于怪物战斗后执行
				if (cs->getEffectSet().at(effectSize).getArgs().size() == 2)
				{
					temp.level += EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left - EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Left;
				}
			}
			//若该效果是不属于当前回合执行
			else
			{
				temp.level += epq.getMonsterEPQLevelMaxByRoundAndInterval(continueRound, EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Right) + 1;
				//若该效果属于怪物战斗后执行
				if (cs->getEffectSet().at(effectSize).getArgs().size() == 2)
				{
					temp.level += EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left - EffectAffixes::EffectLevelInterval_Before_Left;
				}
			}
			epq.pushMonsterEffectAffixes(temp);
		}

	}

	while (epq.isMonsterEffectPQEmpty() == false)
	{
		EffectAffixes ea = epq.getMonsterEffectAffixesByInterval(EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log("[information] 怪物战斗时，已经没有可执行的效果了!");
			return;
		}
		//若该优先级所属的效果是在怪物战斗后执行的，则在怪物战斗时跳过该效果的执行
		if (ea.level / EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left == 1)
		{
			break;
		}
		//执行怪物战斗时的效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popMonsterEffectAffixes();
	}

}
 
void CombatSystem::excuteMonsterAfterCombatOperator()
{
	cocos2d::log("[information] 执行 怪物战斗后 的操作，当前回合为 %d ", round);

	while (true)
	{
		EffectAffixes ea = epq.getMonsterEffectAffixesByInterval(EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log("[information] 怪物战斗后，已经没有可执行的效果了!");
			return;
		}
		//执行怪物战斗后的效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popMonsterEffectAffixes();
	}
}

void CombatSystem::excuteCombat()
{
	//全局
	executeGlobalOperation();

	//战斗前
	executeRoleBeforeTheCombatOperation();
	executeMonsterBeforeTheCombatOperator();
	
	//战斗时
	excuteRoleInCombatOperation(roleUseCardId);
	excuteMonsterInCombatOperator(monsterUseCardId);
	
	//战斗后
	excuteRoleAfterCombatOperation();
	excuteMonsterAfterCombatOperator();
}

void CombatSystem::setUseCardId(const int roleUseCardId, const int monsterUseCardId)
{
	this->roleUseCardId = roleUseCardId;
	this->monsterUseCardId = monsterUseCardId;
}



bool CombatSystem::judgeEndToCombat()
{
	return false;
}

void CombatSystem::test()
{
	cocos2d::log("[warning] 注意：即将进入战斗系统！");
	CombatSystem cs;
	for (int i = 0; i < 3;++i)
	{
		cs.setUseCardId(i+30026,i+30004);
		cs.excuteCombat();
		if (judgeEndToCombat())
		{
			break;
		}
	}
	cocos2d::log("[warning] 注意：退出战斗系统！");
}
