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
	// �������id��Ч
	if (cardSkillID == CardBase::invalidID)
		return;
	// ��ȡ��
	const CardSkill *cardSkill = CardSet::Instance()->getCardSkillByID(cardSkillID);

	// ����ÿ������ڽ�ɫ
	if (cardSkill->getBelongTo() != CardBase::BelongTo_RoleOnly && cardSkill->getBelongTo() != CardBase::BelongTo_RoleMonsterBoth)
		return;
	//Ч�������ȼ�	
	int level = EffectAffixes::invalidLevelValue;
	// ��ȡ�����е�Ч������
	int effectSize = cardSkill->getEffectSet().size();
	// Ч������
	int efIndex = 0;
	//��ɫЧ�����е�����
	int queueIndex = -1;
	//��Իغ���
	int relRound = -1;
	// �������п����е�Ч��
	while (effectSize--)
	{
		int startRound = cardSkill->getEffectSet().at(efIndex).getArgs().at(0);
		int continueRound = cardSkill->getEffectSet().at(efIndex).getArgs().at(1);
		
		Effect::ExcuteStyle excuteStyle = cardSkill->getEffectSet().at(efIndex).getExcuteStyle();
		Effect::Receiver receiver = cardSkill->getEffectSet().at(efIndex).getReceiver();				
		while (continueRound--)
		{
			level = 0;			
			//����Ч�������ڵ�ǰ�غ���ִ��
			if (startRound == 0)
			{
				relRound = continueRound;
				//����Ч�����ڽ�ɫս����ִ��
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
			//����Ч���ǲ����ڵ�ǰ�غ�ִ��
			else
			{
				relRound = continueRound + 1;
				//����Ч�����ڽ�ɫս����ִ��
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

			// ����ӵ�Ч��ʵ��
			EffectAffixes temp(level, cardSkillID, efIndex, EffectAffixes::Releaser::Releaser_Role, receiver, excuteStyle, this->round + continueRound);

			//����Ч��������ִ�еģ������������ӵ�����Ч������
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
	// �������id��Ч
	if (cardSkillID == CardBase::invalidID)
		return;

	// ��ȡ��
	const CardSkill *cardSkill = CardSet::Instance()->getCardSkillByID(cardSkillID);

	// ����ÿ������ڹ���
	if (cardSkill->getBelongTo() != CardBase::BelongTo_MonsterOnly && cardSkill->getBelongTo() != CardBase::BelongTo_RoleMonsterBoth)
		return;
	//Ч�����ȼ�
	int level = EffectAffixes::invalidLevelValue;
	// ��ȡ�����е�Ч������
	int effectSize = cardSkill->getEffectSet().size();
	// Ч������
	int efIndex = 0;
	//����Ч�����е��±�����
	int queueIndex = -1;
	//��Իغ���
	int relRound = -1;
	// �������п����е�Ч��
	while (effectSize--)
	{
		int startRound = cardSkill->getEffectSet().at(efIndex).getArgs().at(0);
		int continueRound = cardSkill->getEffectSet().at(efIndex).getArgs().at(1);

		Effect::ExcuteStyle excuteStyle = cardSkill->getEffectSet().at(efIndex).getExcuteStyle();
		Effect::Receiver receiver = cardSkill->getEffectSet().at(efIndex).getReceiver();
		while (continueRound--)
		{
			level = 0;			
			//����Ч�������ڵ�ǰ�غ���ִ��
			if (startRound == 0)
			{
				relRound = continueRound;
				//����Ч�����ڹ���ս����ִ��
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
			//����Ч���ǲ����ڵ�ǰ�غ�ִ��
			else
			{
				relRound = continueRound + 1;
				//����Ч�����ڹ���ս����ִ��
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

			// ����ӵ�Ч��ʵ��
			EffectAffixes temp(level, cardSkillID, efIndex, EffectAffixes::Releaser::Releaser_Monster, receiver, excuteStyle, this->round + continueRound);

			//����Ч��������ִ�еģ������������ӵ�����Ч������
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
	cocos2d::log("<<<<<<<<<<<<<<<����ȫ�ֲ���<<<<<<<<<<<<<<<<<");
	round++;
	
	epq.decreaseRoundEffectRole();
	epq.decreaseRoundEffectMonster();

	// �ַ������е�Ч��
	dispatchEffectFromCardSkillRole(roleUseCardId);
	dispatchEffectFromCardSkillMonster(monsterUseCardId);
	// ������п�
	roleUseCardId = CardBase::invalidID;
	monsterUseCardId = CardBase::invalidID;

	cocos2d::log(">>>>>>>>>>>>>>>�˳�ȫ�ֲ���>>>>>>>>>>>>>>>>>");
}

void CombatSystem::executeRoleBeforeTheCombatOperation()
{
	cocos2d::log("<<<<<<<<<<<<<<<�����ɫս��ǰ����<<<<<<<<<<<<");
	while (true)
	{
		EffectAffixes effectAffixes = epq.getEffectAffixesRole(EffectPQ::EffectQueueIndex::EffectQueueIndex_Before);
		if (effectAffixes.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>�˳���ɫս��ǰ����>>>>>>>>>>>>");
			return;
		}

		// �����Ч�������ڸ�λ��ִ�е�Ч��
		if (CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_Before)
			continue;
		
		effectAffixes.efRound = this->round;
		currentEffectAffixes = effectAffixes;
		
		//ִ�н�ɫս��ǰ��Ч��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getArgs());
		epq.popEffectAffixesRole(0, EffectPQ::EffectQueueIndex::EffectQueueIndex_Before);
		
	}
}

void CombatSystem::excuteRoleInCombatOperation()
{
	cocos2d::log("<<<<<<<<<<<<<<<�����ɫս��ʱ����<<<<<<<<<<<<");

	while (true)
	{
		EffectAffixes effectAffixes = epq.getEffectAffixesRole(EffectPQ::EffectQueueIndex::EffectQueueIndex_In);
		if (effectAffixes.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>�˳���ɫս��ʱ����>>>>>>>>>>>>");
			return;
		}
		// �����Ч�������ڸ�λ��ִ�е�Ч��
		if (CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_In)
			continue;
		
		effectAffixes.efRound = this->round;
		currentEffectAffixes = effectAffixes;

		//ִ�н�ɫս��ʱЧ��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getArgs());
		epq.popEffectAffixesRole(0,EffectPQ::EffectQueueIndex::EffectQueueIndex_In);
	}
}

void CombatSystem::excuteRoleAfterCombatOperation()
{
	cocos2d::log("<<<<<<<<<<<<<<<�����ɫս�������<<<<<<<<<<<<");

	while (true)
	{
		EffectAffixes effectAffixes = epq.getEffectAffixesRole(EffectPQ::EffectQueueIndex::EffectQueueIndex_After);
		if (effectAffixes.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>�˳���ɫս�������>>>>>>>>>>>>");
			return;
		}
		// �����Ч�������ڸ�λ��ִ�е�Ч��
		if (CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_After)
			continue;

		
		effectAffixes.efRound = this->round;
		currentEffectAffixes = effectAffixes;

		//ִ�н�ɫս����Ч��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getArgs());
		epq.popEffectAffixesRole(0,EffectPQ::EffectQueueIndex::EffectQueueIndex_After);
	}
}

void CombatSystem::executeMonsterBeforeTheCombatOperator()
{
	cocos2d::log("<<<<<<<<<<<<<<<�������ս��ǰ����<<<<<<<<<<<<");
	while (true)
	{
		EffectAffixes effectAffixes = epq.getEffectAffixesMonster(EffectPQ::EffectQueueIndex::EffectQueueIndex_Before);
		if (effectAffixes.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>�˳�����ս��ǰ����>>>>>>>>>>>>");
			return;
		}
		// �����Ч�������ڸ�λ��ִ�е�Ч��
		if (CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_Before)
			continue;

		effectAffixes.efRound = this->round;
		currentEffectAffixes = effectAffixes;

		//ִ�й���ս��ǰ��Ч��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getArgs());
		epq.popEffectAffixesMonster(0, EffectPQ::EffectQueueIndex::EffectQueueIndex_Before);
	}
}

void CombatSystem::excuteMonsterInCombatOperator()
{
	cocos2d::log("<<<<<<<<<<<<<<<�������ս��ʱ����<<<<<<<<<<<<");

	while (true)
	{
		EffectAffixes effectAffixes = epq.getEffectAffixesMonster(EffectPQ::EffectQueueIndex::EffectQueueIndex_In);
		if (effectAffixes.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>�˳�����ս��ʱ����>>>>>>>>>>>>");
			return;
		}
		// �����Ч�������ڸ�λ��ִ�е�Ч��
		if (CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_In)
			continue;
				
		effectAffixes.efRound = this->round;
		currentEffectAffixes = effectAffixes;

		//ִ�й���ս��ʱ��Ч��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getArgs());
		epq.popEffectAffixesMonster(0,EffectPQ::EffectQueueIndex::EffectQueueIndex_In);
	}
}

void CombatSystem::excuteMonsterAfterCombatOperator()
{
	cocos2d::log("<<<<<<<<<<<<<<<�������ս�������<<<<<<<<<<<<");
	while (true)
	{
		EffectAffixes effectAffixes = epq.getEffectAffixesMonster(EffectPQ::EffectQueueIndex::EffectQueueIndex_After);
		if (effectAffixes.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>�˳�����ս�������>>>>>>>>>>>>");
			return;
		}
		// �����Ч�������ڸ�λ��ִ�е�Ч��
		if (CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_After)
			continue;

		effectAffixes.efRound = this->round;
		currentEffectAffixes = effectAffixes;

		//ִ�й���ս�����Ч��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(effectAffixes.cardId)->getEffectSet().at(effectAffixes.effectIndex).getArgs());
		epq.popEffectAffixesMonster(0,EffectPQ::EffectQueueIndex::EffectQueueIndex_After);
	}
}

void CombatSystem::excuteCombat()
{
	//ȫ��
	executeGlobalOperation();

	//ս��ǰ
	executeRoleBeforeTheCombatOperation();
	executeMonsterBeforeTheCombatOperator();

	//ս��ʱ
	excuteRoleInCombatOperation();
	excuteMonsterInCombatOperator();

	//ս����
	excuteRoleAfterCombatOperation();
	excuteMonsterAfterCombatOperator();
}

void CombatSystem::setUseCardId(const int roleUseCardId, const int monsterUseCardId)
{
	this->roleUseCardId = roleUseCardId;
	this->monsterUseCardId = monsterUseCardId;
	cocos2d::log("[warning] �� %d �غ��ڣ���ɫʹ���ˣ� %d,����ʹ���ˣ�%d", round + 1, this->roleUseCardId, this->monsterUseCardId);
}

void CombatSystem::setHistoryTotalTable()
{
	//��ӵ�ǰ�غϵ���ʷЧ���ܱ�
	csi->getDeltaTableHistory().addTotalTableHistoryRole(round);
	csi->getDeltaTableHistory().addTotalTableHistoryMonster(round);
}

bool CombatSystem::judgeEndToCombat()
{
	return false;
}

void CombatSystem::test()
{
	cocos2d::log("[warning] ע�⣺��������ս��ϵͳ��");
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
	cocos2d::log("[warning] ע�⣺�˳�ս��ϵͳ��");
}