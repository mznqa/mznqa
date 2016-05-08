#pragma execution_character_set("utf-8")

#include "combatSystem/CombatSystem.h"
#include "staticData/CardSet.h"
#include "card/CardSkill.h"
#include "effect/EffectFunSet.h"
#include "cocos2d.h"

CombatSystemInterface *const csi = CombatSystemInterface::Instance();

int CombatSystem::round = 0;

EffectPQ CombatSystem::epq;

EffectAffixes CombatSystem::currentEffectAffixes;

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
	//效果的优先级	
	int level = EffectAffixes::invalidLevelValue;
	// 获取卡牌中的效果总数
	int effectSize = cardSkill->getEffectSet().size();
	// 效果索引
	int efIndex = 0;
	//角色效果队列的索引
	int queueIndex = -1;
	//相对回合数
	int relRound = -1;
	// 遍历所有卡牌中的效果
	while (effectSize--)
	{
		int startRound = cardSkill->getEffectSet().at(efIndex).getArgs().at(0);
		int continueRound = cardSkill->getEffectSet().at(efIndex).getArgs().at(1);
		
		Effect::ExcuteStyle excuteStyle = cardSkill->getEffectSet().at(efIndex).getExcuteStyle();
		Effect::Receiver receiver = cardSkill->getEffectSet().at(efIndex).getReceiver();				
		while (continueRound--)
		{
			level = 0;			
			//若该效果是属于当前回合内执行
			if (startRound == 0)
			{
				relRound = continueRound;
				//若该效果属于角色战斗后执行
				if (excuteStyle == Effect::ExcuteStyle_After)
				{
					queueIndex = EffectPQ::EffectQueueIndex_After;
					level += epq.getEPQLevelMaxRoleByRoundAndIndex(relRound, queueIndex) + 1;
				}
				else if (excuteStyle == Effect::ExcuteStyle_In)
				{
					queueIndex = EffectPQ::EffectQueueIndex_In;
					level += epq.getEPQLevelMaxRoleByRoundAndIndex(relRound, queueIndex) + 1;
				}
				else if (excuteStyle == Effect::ExcuteStyle_Before)
				{
					queueIndex = EffectPQ::EffectQueueIndex_Before;
					level += epq.getEPQLevelMaxRoleByRoundAndIndex(relRound, queueIndex) + 1;
				}
			}
			//若该效果是不属于当前回合执行
			else
			{
				relRound = continueRound + 1;
				//若该效果属于角色战斗后执行
				if (excuteStyle == Effect::ExcuteStyle_After)
				{
					queueIndex = EffectPQ::EffectQueueIndex_After;
					level += epq.getEPQLevelMaxRoleByRoundAndIndex(relRound, queueIndex) + 1;
				}
				else if (excuteStyle == Effect::ExcuteStyle_In)
				{
					queueIndex = EffectPQ::EffectQueueIndex_In;
					level += epq.getEPQLevelMaxRoleByRoundAndIndex(relRound, queueIndex) + 1;
				}
				else if (excuteStyle == Effect::ExcuteStyle_Before)
				{
					queueIndex = EffectPQ::EffectQueueIndex_Before;
					level += epq.getEPQLevelMaxRoleByRoundAndIndex(relRound, queueIndex) + 1;
				}
			}

			// 待入队的效果实体
			EffectAffixes temp(level, cardSkillID, efIndex, EffectAffixes::Releaser::Releaser_Role, receiver, excuteStyle, this->round + continueRound);

			//若该效果是主动执行的，则添加立即添加到怪物效果队列
			if (CardSet::Instance()->getCardSkillByID(temp.cardId)->getEffectSet().at(temp.effectIndex).getBehavior() == Effect::Behavior::Behavior_Active)
			{				
				epq.pushEffectAffixesRole(temp, relRound, queueIndex);
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
	//效果优先级
	int level = EffectAffixes::invalidLevelValue;
	// 获取卡牌中的效果总数
	int effectSize = cardSkill->getEffectSet().size();
	// 效果索引
	int efIndex = 0;
	//怪物效果队列的下标索引
	int queueIndex = -1;
	//相对回合数
	int relRound = -1;
	// 遍历所有卡牌中的效果
	while (effectSize--)
	{
		int startRound = cardSkill->getEffectSet().at(efIndex).getArgs().at(0);
		int continueRound = cardSkill->getEffectSet().at(efIndex).getArgs().at(1);

		Effect::ExcuteStyle excuteStyle = cardSkill->getEffectSet().at(efIndex).getExcuteStyle();
		Effect::Receiver receiver = cardSkill->getEffectSet().at(efIndex).getReceiver();
		while (continueRound--)
		{
			level = 0;			
			//若该效果是属于当前回合内执行
			if (startRound == 0)
			{
				relRound = continueRound;
				//若该效果属于怪物战斗后执行
				if (excuteStyle == Effect::ExcuteStyle_After)
				{
					queueIndex = EffectPQ::EffectQueueIndex_After;
					level += epq.getEPQLevelMaxMonsterByRoundAndIndex(relRound, queueIndex) + 1;
				}
				else if (excuteStyle == Effect::ExcuteStyle_In)
				{
					queueIndex = EffectPQ::EffectQueueIndex_In;
					level += epq.getEPQLevelMaxMonsterByRoundAndIndex(relRound, queueIndex) + 1;
				}
				else if (excuteStyle == Effect::ExcuteStyle_Before)
				{
					queueIndex = EffectPQ::EffectQueueIndex_Before;
					level += epq.getEPQLevelMaxMonsterByRoundAndIndex(relRound, queueIndex) + 1;
				}
			}
			//若该效果是不属于当前回合执行
			else
			{
				relRound = continueRound + 1;
				//若该效果属于怪物战斗后执行
				if (excuteStyle == Effect::ExcuteStyle_After)
				{
					queueIndex = EffectPQ::EffectQueueIndex_After;
					level += epq.getEPQLevelMaxMonsterByRoundAndIndex(relRound, queueIndex) + 1;
				}
				else if (excuteStyle == Effect::ExcuteStyle_In)
				{
					queueIndex = EffectPQ::EffectQueueIndex_In;
					level += epq.getEPQLevelMaxMonsterByRoundAndIndex(relRound, queueIndex) + 1;
				}
				else if (excuteStyle == Effect::ExcuteStyle_Before)
				{
					queueIndex = EffectPQ::EffectQueueIndex_Before;
					level += epq.getEPQLevelMaxMonsterByRoundAndIndex(relRound, queueIndex) + 1;
				}
			}

			// 待入队的效果实体
			EffectAffixes temp(level, cardSkillID, efIndex, EffectAffixes::Releaser::Releaser_Monster, receiver, excuteStyle, this->round + continueRound);

			//若该效果是主动执行的，则添加立即添加到怪物效果队列
			if (CardSet::Instance()->getCardSkillByID(temp.cardId)->getEffectSet().at(temp.effectIndex).getBehavior() == Effect::Behavior::Behavior_Active)
			{
				epq.pushEffectAffixesMonster(temp, relRound, queueIndex);
			}
		}
		efIndex++;
	}
}

void CombatSystem::executeGlobalOperation()
{
	cocos2d::log("<<<<<<<<<<<<<<<进入全局操作<<<<<<<<<<<<<<<<<");
	round++;
	
	epq.decreaseRoundEffectRole();
	epq.decreaseRoundEffectMonster();

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
		EffectAffixes effectAffixes = epq.getEffectAffixesRole(EffectPQ::EffectQueueIndex::EffectQueueIndex_Before);
		if (effectAffixes.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>退出角色战斗前操作>>>>>>>>>>>>");
			return;
		}

		// 如果该效果不是在该位置执行的效果
		if (CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_Before)
			continue;
		
		effectAffixes.efRound = this->round;
		currentEffectAffixes = effectAffixes;
		
		//执行角色战斗前的效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getArgs());
		epq.popEffectAffixesRole(0, EffectPQ::EffectQueueIndex::EffectQueueIndex_Before);
		
	}
}

void CombatSystem::excuteRoleInCombatOperation()
{
	cocos2d::log("<<<<<<<<<<<<<<<进入角色战斗时操作<<<<<<<<<<<<");

	while (true)
	{
		EffectAffixes effectAffixes = epq.getEffectAffixesRole(EffectPQ::EffectQueueIndex::EffectQueueIndex_In);
		if (effectAffixes.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>退出角色战斗时操作>>>>>>>>>>>>");
			return;
		}
		// 如果该效果不是在该位置执行的效果
		if (CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_In)
			continue;
		
		effectAffixes.efRound = this->round;
		currentEffectAffixes = effectAffixes;

		//执行角色战斗时效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getArgs());
		epq.popEffectAffixesRole(0,EffectPQ::EffectQueueIndex::EffectQueueIndex_In);
	}
}

void CombatSystem::excuteRoleAfterCombatOperation()
{
	cocos2d::log("<<<<<<<<<<<<<<<进入角色战斗后操作<<<<<<<<<<<<");

	while (true)
	{
		EffectAffixes effectAffixes = epq.getEffectAffixesRole(EffectPQ::EffectQueueIndex::EffectQueueIndex_After);
		if (effectAffixes.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>退出角色战斗后操作>>>>>>>>>>>>");
			return;
		}
		// 如果该效果不是在该位置执行的效果
		if (CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_After)
			continue;

		
		effectAffixes.efRound = this->round;
		currentEffectAffixes = effectAffixes;

		//执行角色战斗后效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getArgs());
		epq.popEffectAffixesRole(0,EffectPQ::EffectQueueIndex::EffectQueueIndex_After);
	}
}

void CombatSystem::executeMonsterBeforeTheCombatOperator()
{
	cocos2d::log("<<<<<<<<<<<<<<<进入怪物战斗前操作<<<<<<<<<<<<");
	while (true)
	{
		EffectAffixes effectAffixes = epq.getEffectAffixesMonster(EffectPQ::EffectQueueIndex::EffectQueueIndex_Before);
		if (effectAffixes.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>退出怪物战斗前操作>>>>>>>>>>>>");
			return;
		}
		// 如果该效果不是在该位置执行的效果
		if (CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_Before)
			continue;

		effectAffixes.efRound = this->round;
		currentEffectAffixes = effectAffixes;

		//执行怪物战斗前的效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getArgs());
		epq.popEffectAffixesMonster(0, EffectPQ::EffectQueueIndex::EffectQueueIndex_Before);
	}
}

void CombatSystem::excuteMonsterInCombatOperator()
{
	cocos2d::log("<<<<<<<<<<<<<<<进入怪物战斗时操作<<<<<<<<<<<<");

	while (true)
	{
		EffectAffixes effectAffixes = epq.getEffectAffixesMonster(EffectPQ::EffectQueueIndex::EffectQueueIndex_In);
		if (effectAffixes.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>退出怪物战斗时操作>>>>>>>>>>>>");
			return;
		}
		// 如果该效果不是在该位置执行的效果
		if (CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_In)
			continue;
				
		effectAffixes.efRound = this->round;
		currentEffectAffixes = effectAffixes;

		//执行怪物战斗时的效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getArgs());
		epq.popEffectAffixesMonster(0,EffectPQ::EffectQueueIndex::EffectQueueIndex_In);
	}
}

void CombatSystem::excuteMonsterAfterCombatOperator()
{
	cocos2d::log("<<<<<<<<<<<<<<<进入怪物战斗后操作<<<<<<<<<<<<");
	while (true)
	{
		EffectAffixes effectAffixes = epq.getEffectAffixesMonster(EffectPQ::EffectQueueIndex::EffectQueueIndex_After);
		if (effectAffixes.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>退出怪物战斗后操作>>>>>>>>>>>>");
			return;
		}
		// 如果该效果不是在该位置执行的效果
		if (CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_After)
			continue;

		effectAffixes.efRound = this->round;
		currentEffectAffixes = effectAffixes;

		//执行怪物战斗后的效果
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getArgs());
		epq.popEffectAffixesMonster(0,EffectPQ::EffectQueueIndex::EffectQueueIndex_After);
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
	csi->getDeltaTableHistory().addTotalTableHistoryRole(round);
	csi->getDeltaTableHistory().addTotalTableHistoryMonster(round);
}

bool CombatSystem::judgeEndToCombat()
{
	return false;
}

void CombatSystem::test()
{
	cocos2d::log("[warning] 注意：即将进入战斗系统！");
	CombatSystem cs;
	for (int i = 0; i < 11; ++i)
	{
		cs.setUseCardId(i + 30026, i + 30015);
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