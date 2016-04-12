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
	cocos2d::log("<<<<<<<<<<<<<<<进入全局操作<<<<<<<<<<<<<<<<<");
	round++;
	epq.decreaseRoleEffectLevel();
	epq.decreaseMonsterEffectLevel();
	cocos2d::log(">>>>>>>>>>>>>>>退出全局操作>>>>>>>>>>>>>>>>>");

}

void CombatSystem::executeRoleBeforeTheCombatOperation()
{
	cocos2d::log("<<<<<<<<<<<<<<<进入角色战斗前操作<<<<<<<<<<<<");
	while (true)
	{
		EffectAffixes ea = epq.getRoleEffectAffixesByInterval(EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>退出角色战斗前操作>>>>>>>>>>>>");
			return;
		}
		//若该优先级所属的效果是在角色战斗后执行的，则在角色战斗前跳过该效果的执行
		if (ea.level / EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left == 1)
		{
			break;
		}
		//执行角色战斗前的效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popRoleEffectAffixes(ea);
	}
	cocos2d::log(">>>>>>>>>>>>>>>退出角色战斗前操作>>>>>>>>>>>>");
	return;
}

void CombatSystem::excuteRoleInCombatOperation(int cardId)
{
	cocos2d::log("<<<<<<<<<<<<<<<进入角色战斗时操作<<<<<<<<<<<<");

	const CardSkill *cs = CardSet::Instance()->getCardSkillByID(cardId);
	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int effectSize = cs->getEffectSet().size();
	int efIndex = 0;

	while (effectSize--)
	{

		int startRound = cs->getEffectSet().at(effectSize).getArgs().at(0);
		int continueRound = cs->getEffectSet().at(effectSize).getArgs().at(1);
		temp.cardId = cardId;
		temp.effectIndex = efIndex;
		while (continueRound--)
		{
			temp.level = 0;
			//若该效果是属于当前回合内执行
			if (startRound == 0)
			{
				temp.level += epq.getRoleEPQLevelMaxByRoundAndInterval(continueRound, EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Right) + 1;
				//若该效果属于角色战斗后执行
				if (cs->getEffectSet().at(efIndex).getArgs().size() == 2)
				{
					temp.level += EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left - EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Left;
				}
			}
			//若该效果是不属于当前回合执行
			else
			{
				temp.level += epq.getRoleEPQLevelMaxByRoundAndInterval(continueRound + 1, EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Right) + 1;
				//若该效果属于角色战斗后执行
				if (cs->getEffectSet().at(efIndex).getArgs().size() == 2)
				{
					temp.level += EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left - EffectAffixes::EffectLevelInterval_Before_Left;
				}
			}
			epq.pushRoleEffectAffixes(temp);
			efIndex++;
		}
		//当该效果是一个条件效果，则不添加该技能卡的剩余效果
		if (CardSet::Instance()->getCardSkillByID(temp.cardId)->getEffectSet().at(temp.effectIndex).getFunIndex() / EffectAffixes::conditionEffectDivision == 1)
		{
			break;
		}
	}

	while (epq.isRoleEffectPQEmpty() == false)
	{
		EffectAffixes ea = epq.getRoleEffectAffixesByInterval(EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			return;
		}
		//若该优先级所属的效果是在角色战斗后执行的，则在角色战斗时跳过该效果的执行
		if (ea.level / EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left == 1)
		{
			break;
		}
		//执行角色战斗时效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popRoleEffectAffixes(ea);
	}
	cocos2d::log(">>>>>>>>>>>>>>>退出角色战时前操作>>>>>>>>>>>>");
}

void CombatSystem::excuteRoleAfterCombatOperation()
{
	cocos2d::log("<<<<<<<<<<<<<<<进入角色战斗后操作<<<<<<<<<<<<");

	while (true)
	{
		EffectAffixes ea = epq.getRoleEffectAffixesByInterval(EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>退出角色战斗后操作>>>>>>>>>>>>");
			return;
		}
		//执行角色战斗后效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popRoleEffectAffixes(ea);
	}
	cocos2d::log(">>>>>>>>>>>>>>>退出角色战斗后操作>>>>>>>>>>>>");

}

void CombatSystem::executeMonsterBeforeTheCombatOperator()
{
	cocos2d::log("<<<<<<<<<<<<<<<进入怪物战斗前操作<<<<<<<<<<<<");
	while (true)
	{
		EffectAffixes ea = epq.getMonsterEffectAffixesByInterval(EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Left,EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>退出怪物战斗前操作>>>>>>>>>>>>");
			return;
		}
		//若该优先级所属的效果是在怪物战斗后执行的，则在怪物战斗前跳过该效果的执行
		if (ea.level / EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left == 1)
		{
			break;
		}
		//执行怪物战斗前的效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popMonsterEffectAffixes(ea);
	}
	cocos2d::log(">>>>>>>>>>>>>>>退出怪物战斗前操作>>>>>>>>>>>>");
	return;
}

void CombatSystem::excuteMonsterInCombatOperator(int cardId)
{
	cocos2d::log("<<<<<<<<<<<<<<<进入怪物战斗时操作<<<<<<<<<<<<");

	const CardSkill *cs = CardSet::Instance()->getCardSkillByID(cardId);
	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	int effectSize = cs->getEffectSet().size();
	int efIndex = 0;
	while (effectSize--)
	{
		int startRound = cs->getEffectSet().at(efIndex).getArgs().at(0);
		int continueRound = cs->getEffectSet().at(efIndex).getArgs().at(1);
		temp.cardId = cardId;
		temp.effectIndex = efIndex;
		Effect::Receiver effectRecv = CardSet::Instance()->getCardSkillByID(temp.cardId)->getEffectSet().at(temp.effectIndex).getReceiver();
		while (continueRound--)
		{
			temp.level = 0;
			//若该效果是属于当前回合内执行
			if (startRound == 0)
			{
				temp.level += epq.getMonsterEPQLevelMaxByRoundAndInterval(continueRound, EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Right) + 1;
				//若该效果属于怪物战斗后执行
				if (cs->getEffectSet().at(efIndex).getArgs().size() == 2)
				{
					temp.level += EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left - EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Left;
				}
			}
			//若该效果是不属于当前回合执行
			else
			{
				temp.level += epq.getMonsterEPQLevelMaxByRoundAndInterval(continueRound + 1, EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Right) + 1;
				//若该效果属于怪物战斗后执行
				if (cs->getEffectSet().at(efIndex).getArgs().size() == 2)
				{
					temp.level += EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left - EffectAffixes::EffectLevelInterval_Before_Left;
				}
			}
			if (effectRecv == Effect::Receiver::Receiver_Other)
			{
			}
			epq.pushMonsterEffectAffixes(temp);
			efIndex++;
		}
		
	}

	while (epq.isMonsterEffectPQEmpty() == false)
	{
		EffectAffixes ea = epq.getMonsterEffectAffixesByInterval(EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			return;
		}
		//若该优先级所属的效果是在怪物战斗后执行的，则在怪物战斗时跳过该效果的执行
		if (ea.level / EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left == 1)
		{
			break;
		}
		//执行怪物战斗时的效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popMonsterEffectAffixes(ea);
	}
	cocos2d::log(">>>>>>>>>>>>>>>退出怪物战斗前操作>>>>>>>>>>>>");
	return;
}
 
void CombatSystem::excuteMonsterAfterCombatOperator()
{
	cocos2d::log("<<<<<<<<<<<<<<<进入怪物战斗后操作<<<<<<<<<<<<");
	while (true)
	{
		EffectAffixes ea = epq.getMonsterEffectAffixesByInterval(EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>退出怪物战斗前操作>>>>>>>>>>>>");
			return;
		}
		//执行怪物战斗后的效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popMonsterEffectAffixes(ea);
	}
	cocos2d::log(">>>>>>>>>>>>>>>退出怪物战斗前操作>>>>>>>>>>>>");
	return;
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
	cocos2d::log("[warning] 第 %d 回合内，角色使用了： %d,怪物使用了：%d", round + 1, this->roleUseCardId, this->monsterUseCardId);
}

bool CombatSystem::judgeEndToCombat()
{
	return false;
}

void CombatSystem::test()
{
	cocos2d::log("[warning] 注意：即将进入战斗系统！");
	CombatSystem cs;
	for (int i = 0; i < 1;++i)
	{
		cs.setUseCardId(i+30034,i+30024);
		cs.excuteCombat();
		if (judgeEndToCombat())
		{
			break;
		}
		cocos2d::log("\n");
	}
	cocos2d::log("[warning] 注意：退出战斗系统！");
}
