#pragma execution_character_set("utf-8")

#include "combatSystem/CombatSystem.h"

#include "cocos2d.h"

#include "staticData/CardSet.h"
#include "card/CardSkill.h"
#include "effect/EffectFunSet.h"


CombatSystemInterface *const csi = CombatSystemInterface::Instance();

int CombatSystem::round = 0;

EffectPQ CombatSystem::epq;

EffectAffixes CombatSystem::efAffixes;

CombatSystem::CombatSystem()
{
}

CombatSystem::~CombatSystem()
{
}

void CombatSystem::dispatchEffectFromCardSkillRole(int cardSkillID)
{
	// 如果给定id无效
	if (cardSkillID == CardBase::invalidID)
		return;
	// 获取卡
	const CardSkill *cardSkill = CardSet::Instance()->getCardSkillByID(cardSkillID);

	// 如果该卡不属于角色
	if (cardSkill->getBelongTo() != CardBase::BelongTo_RoleOnly && cardSkill->getBelongTo() != CardBase::BelongTo_RoleMonsterBoth)
		return;

	// 待入队的效果实体
	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	// 获取卡牌中的效果总数
	int effectSize = cardSkill->getEffectSet().size();
	// 效果索引
	int efIndex = 0;
	//效果的释放者
	temp.releaser = Effect::Releaser::Releaser_Role;
	// 遍历所有卡牌中的效果
	while (effectSize--)
	{
		int startRound = cardSkill->getEffectSet().at(efIndex).getArgs().at(0);
		int continueRound = cardSkill->getEffectSet().at(efIndex).getArgs().at(1);
		temp.cardId = cardSkillID;
		temp.effectIndex = efIndex;
		
		while (continueRound--)
		{
			temp.level = 0;

			Effect::ExcuteStyle excuteStyle = cardSkill->getEffectSet().at(efIndex).getExcuteStyle();
			temp.receiver = cardSkill->getEffectSet().at(efIndex).getReceiver();
			temp.excuteStyle = cardSkill->getEffectSet().at(efIndex).getExcuteStyle();

			//若该效果是属于当前回合内执行
			if (startRound == 0)
			{
				//若该效果属于角色战斗后执行
				if (excuteStyle == Effect::ExcuteStyle_After)
				{
					temp.level += epq.getRoleEPQLevelMaxByRoundAndInterval(continueRound, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
				}
				else if (excuteStyle == Effect::ExcuteStyle_In)
				{
					temp.level += epq.getRoleEPQLevelMaxByRoundAndInterval(continueRound, EffectPQ::EffectLevelInterval::EffectLevelInterval_In_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_In_Right) + 1;
				}
				else if (excuteStyle == Effect::ExcuteStyle_Before)
				{
					temp.level += epq.getRoleEPQLevelMaxByRoundAndInterval(continueRound, EffectPQ::EffectLevelInterval::EffectLevelInterval_Before_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_Before_Right) + 1;
				}
			}
			//若该效果是不属于当前回合执行
			else
			{
				//若该效果属于角色战斗后执行
				if (excuteStyle == Effect::ExcuteStyle_After)
				{
					temp.level += epq.getRoleEPQLevelMaxByRoundAndInterval(continueRound + 1, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
				}
				else if (excuteStyle == Effect::ExcuteStyle_In)
				{
					temp.level += epq.getRoleEPQLevelMaxByRoundAndInterval(continueRound + 1, EffectPQ::EffectLevelInterval::EffectLevelInterval_In_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_In_Right) + 1;
				}
				else if (excuteStyle == Effect::ExcuteStyle_Before)
				{
					temp.level += epq.getRoleEPQLevelMaxByRoundAndInterval(continueRound + 1, EffectPQ::EffectLevelInterval::EffectLevelInterval_Before_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_Before_Right) + 1;
				}
			}
			//若该效果是主动执行的，则添加立即添加到怪物效果队列
			if (CardSet::Instance()->getCardSkillByID(temp.cardId)->getEffectSet().at(temp.effectIndex).getBehavior() == Effect::Behavior::Behavior_Active)
			{
				epq.pushRoleEffectAffixes(temp);
			}
		}
		efIndex++;
	}
}

void CombatSystem::dispatchEffectFromCardSkillMonster(int cardSkillID)
{
	// 如果给定id无效
	if (cardSkillID == CardBase::invalidID)
		return;

	// 获取卡
	const CardSkill *cardSkill = CardSet::Instance()->getCardSkillByID(cardSkillID);

	// 如果该卡不属于怪物
	if (cardSkill->getBelongTo() != CardBase::BelongTo_MonsterOnly && cardSkill->getBelongTo() != CardBase::BelongTo_RoleMonsterBoth)
		return;

	// 待入队的效果实体
	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	// 获取卡牌中的效果总数
	int effectSize = cardSkill->getEffectSet().size();
	// 效果索引
	int efIndex = 0;
	temp.releaser = Effect::Releaser::Releaser_Monster;
	// 遍历所有卡牌中的效果
	while (effectSize--)
	{
		int startRound = cardSkill->getEffectSet().at(efIndex).getArgs().at(0);
		int continueRound = cardSkill->getEffectSet().at(efIndex).getArgs().at(1);
		temp.cardId = cardSkillID;
		temp.effectIndex = efIndex;
		while (continueRound--)
		{
			temp.level = 0;
			Effect::ExcuteStyle excuteStyle = cardSkill->getEffectSet().at(efIndex).getExcuteStyle();
			temp.receiver = cardSkill->getEffectSet().at(efIndex).getReceiver();
			temp.excuteStyle = excuteStyle;

			//若该效果是属于当前回合内执行
			if (startRound == 0)
			{
				//若该效果属于怪物战斗后执行
				if (excuteStyle == Effect::ExcuteStyle_After)
				{
					temp.level += epq.getMonsterEPQLevelMaxByRoundAndInterval(continueRound, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
				}
				else if (excuteStyle == Effect::ExcuteStyle_In)
				{
					temp.level += epq.getMonsterEPQLevelMaxByRoundAndInterval(continueRound, EffectPQ::EffectLevelInterval::EffectLevelInterval_In_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_In_Right) + 1;
				}
				else if (excuteStyle == Effect::ExcuteStyle_Before)
				{
					temp.level += epq.getMonsterEPQLevelMaxByRoundAndInterval(continueRound, EffectPQ::EffectLevelInterval::EffectLevelInterval_Before_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_Before_Right) + 1;
				}
			}
			//若该效果是不属于当前回合执行
			else
			{
				//若该效果属于怪物战斗后执行
				if (excuteStyle == Effect::ExcuteStyle_After)
				{
					temp.level += epq.getMonsterEPQLevelMaxByRoundAndInterval(continueRound + 1, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right) + 1;
				}
				else if (excuteStyle == Effect::ExcuteStyle_In)
				{
					temp.level += epq.getMonsterEPQLevelMaxByRoundAndInterval(continueRound + 1, EffectPQ::EffectLevelInterval::EffectLevelInterval_In_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_In_Right) + 1;
				}
				else if (excuteStyle == Effect::ExcuteStyle_Before)
				{
					temp.level += epq.getMonsterEPQLevelMaxByRoundAndInterval(continueRound + 1, EffectPQ::EffectLevelInterval::EffectLevelInterval_Before_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_Before_Right) + 1;
				}
			}
			//若该效果是主动执行的，则添加立即添加到怪物效果队列
			if (CardSet::Instance()->getCardSkillByID(temp.cardId)->getEffectSet().at(temp.effectIndex).getBehavior() == Effect::Behavior::Behavior_Active)
			{
				epq.pushMonsterEffectAffixes(temp);
			}
		}
		efIndex++;
	}
}

void CombatSystem::executeGlobalOperation()
{
	cocos2d::log("<<<<<<<<<<<<<<<进入全局操作<<<<<<<<<<<<<<<<<");
	round++;

	epq.decreaseRoleEffectLevel();
	epq.decreaseMonsterEffectLevel();

	// 分发卡牌中的效果
	dispatchEffectFromCardSkillRole(roleUseCardId);
	dispatchEffectFromCardSkillMonster(monsterUseCardId);
	// 清空已有卡
	roleUseCardId = CardBase::invalidID;
	monsterUseCardId = CardBase::invalidID;

	cocos2d::log(">>>>>>>>>>>>>>>退出全局操作>>>>>>>>>>>>>>>>>");
}

void CombatSystem::executeRoleBeforeTheCombatOperation()
{
	cocos2d::log("<<<<<<<<<<<<<<<进入角色战斗前操作<<<<<<<<<<<<");
	while (true)
	{
		EffectAffixes ea = epq.getRoleEffectAffixesByInterval(EffectPQ::EffectLevelInterval::EffectLevelInterval_Before_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_Before_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>退出角色战斗前操作>>>>>>>>>>>>");
			return;
		}

		// 如果该效果不是在该位置执行的效果
		if (CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_Before)
			continue;
		
		
		ea.efRound = this->round;
		efAffixes = ea;
		
		//执行角色战斗前的效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popRoleEffectAffixes(ea);
		
	}
	cocos2d::log(">>>>>>>>>>>>>>>退出角色战斗前操作>>>>>>>>>>>>");
	return;
}

void CombatSystem::excuteRoleInCombatOperation()
{
	cocos2d::log("<<<<<<<<<<<<<<<进入角色战斗时操作<<<<<<<<<<<<");

	while (true)
	{
		EffectAffixes ea = epq.getRoleEffectAffixesByInterval(EffectPQ::EffectLevelInterval::EffectLevelInterval_In_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_In_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>退出角色战斗时操作>>>>>>>>>>>>");
			return;
		}
		// 如果该效果不是在该位置执行的效果
		if (CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_In)
			continue;

		
		ea.efRound = this->round;
		efAffixes = ea;

		//执行角色战斗时效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popRoleEffectAffixes(ea);

	}
	cocos2d::log(">>>>>>>>>>>>>>>退出角色战斗时操作>>>>>>>>>>>>");
}

void CombatSystem::excuteRoleAfterCombatOperation()
{
	cocos2d::log("<<<<<<<<<<<<<<<进入角色战斗后操作<<<<<<<<<<<<");

	while (true)
	{
		EffectAffixes ea = epq.getRoleEffectAffixesByInterval(EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>退出角色战斗后操作>>>>>>>>>>>>");
			return;
		}
		// 如果该效果不是在该位置执行的效果
		if (CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_After)
			continue;

		
		ea.efRound = this->round;
		efAffixes = ea;

		//执行角色战斗后效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popRoleEffectAffixes(ea);
	}
	cocos2d::log(">>>>>>>>>>>>>>>退出角色战斗后操作>>>>>>>>>>>>");
	return;
}

void CombatSystem::executeMonsterBeforeTheCombatOperator()
{
	cocos2d::log("<<<<<<<<<<<<<<<进入怪物战斗前操作<<<<<<<<<<<<");
	while (true)
	{
		EffectAffixes ea = epq.getMonsterEffectAffixesByInterval(EffectPQ::EffectLevelInterval::EffectLevelInterval_Before_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_Before_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>退出怪物战斗前操作>>>>>>>>>>>>");
			return;
		}
		// 如果该效果不是在该位置执行的效果
		if (CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_Before)
			continue;

		ea.efRound = this->round;
		efAffixes = ea;

		//执行怪物战斗前的效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popMonsterEffectAffixes(ea);
	}
	cocos2d::log(">>>>>>>>>>>>>>>退出怪物战斗前操作>>>>>>>>>>>>");
	return;
}

void CombatSystem::excuteMonsterInCombatOperator()
{
	cocos2d::log("<<<<<<<<<<<<<<<进入怪物战斗时操作<<<<<<<<<<<<");

	while (epq.isMonsterEffectPQEmpty() == false)
	{
		EffectAffixes ea = epq.getMonsterEffectAffixesByInterval(EffectPQ::EffectLevelInterval::EffectLevelInterval_In_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_In_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>退出怪物战斗时操作>>>>>>>>>>>>");
			return;
		}
		// 如果该效果不是在该位置执行的效果
		if (CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_In)
			continue;
				
		ea.efRound = this->round;
		efAffixes = ea;

		//执行怪物战斗时的效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popMonsterEffectAffixes(ea);
	}
	cocos2d::log(">>>>>>>>>>>>>>>退出怪物战斗时操作>>>>>>>>>>>>");
	return;
}

void CombatSystem::excuteMonsterAfterCombatOperator()
{
	cocos2d::log("<<<<<<<<<<<<<<<进入怪物战斗后操作<<<<<<<<<<<<");
	while (true)
	{
		EffectAffixes ea = epq.getMonsterEffectAffixesByInterval(EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>退出怪物战斗后操作>>>>>>>>>>>>");
			return;
		}
		// 如果该效果不是在该位置执行的效果
		if (CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_After)
			continue;

		ea.efRound = this->round;
		efAffixes = ea;

		//执行怪物战斗后的效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popMonsterEffectAffixes(ea);
	}
	cocos2d::log(">>>>>>>>>>>>>>>退出怪物战斗后操作>>>>>>>>>>>>");
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
	excuteRoleInCombatOperation();
	excuteMonsterInCombatOperator();

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

void CombatSystem::setHistoryTotalTable()
{
	//添加当前回合的历史效果总表
	csi->getDeltaTableHistory().addTotalRoleHistory(round);
	csi->getDeltaTableHistory().addTotalMonsterHistory(round);
}

bool CombatSystem::judgeEndToCombat()
{
	return false;
}

void CombatSystem::test()
{
	cocos2d::log("[warning] 注意：即将进入战斗系统！");
	CombatSystem cs;
	for (int i = 0; i < 2; ++i)
	{
		cs.setUseCardId(i + 30026, i + 30016);
		cs.excuteCombat();
		cs.setHistoryTotalTable();
		if (judgeEndToCombat())
		{
			break;
		}
		cocos2d::log("\n");
	}
	cocos2d::log("[warning] 注意：退出战斗系统！");
}