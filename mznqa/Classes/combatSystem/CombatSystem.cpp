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
	// �������id��Ч
	if (cardSkillID == CardBase::invalidID)
		return;
	// ��ȡ��
	const CardSkill *cardSkill = CardSet::Instance()->getCardSkillByID(cardSkillID);

	// ����ÿ������ڽ�ɫ
	if (cardSkill->getBelongTo() != CardBase::BelongTo_RoleOnly && cardSkill->getBelongTo() != CardBase::BelongTo_RoleMonsterBoth)
		return;

	// ����ӵ�Ч��ʵ��
	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	// ��ȡ�����е�Ч������
	int effectSize = cardSkill->getEffectSet().size();
	// Ч������
	int efIndex = 0;
	//Ч�����ͷ���
	temp.releaser = Effect::Releaser::Releaser_Role;
	// �������п����е�Ч��
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

			//����Ч�������ڵ�ǰ�غ���ִ��
			if (startRound == 0)
			{
				//����Ч�����ڽ�ɫս����ִ��
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
			//����Ч���ǲ����ڵ�ǰ�غ�ִ��
			else
			{
				//����Ч�����ڽ�ɫս����ִ��
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
			//����Ч��������ִ�еģ������������ӵ�����Ч������
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
	// �������id��Ч
	if (cardSkillID == CardBase::invalidID)
		return;

	// ��ȡ��
	const CardSkill *cardSkill = CardSet::Instance()->getCardSkillByID(cardSkillID);

	// ����ÿ������ڹ���
	if (cardSkill->getBelongTo() != CardBase::BelongTo_MonsterOnly && cardSkill->getBelongTo() != CardBase::BelongTo_RoleMonsterBoth)
		return;

	// ����ӵ�Ч��ʵ��
	EffectAffixes temp(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	// ��ȡ�����е�Ч������
	int effectSize = cardSkill->getEffectSet().size();
	// Ч������
	int efIndex = 0;
	temp.releaser = Effect::Releaser::Releaser_Monster;
	// �������п����е�Ч��
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

			//����Ч�������ڵ�ǰ�غ���ִ��
			if (startRound == 0)
			{
				//����Ч�����ڹ���ս����ִ��
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
			//����Ч���ǲ����ڵ�ǰ�غ�ִ��
			else
			{
				//����Ч�����ڹ���ս����ִ��
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
			//����Ч��������ִ�еģ������������ӵ�����Ч������
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
	cocos2d::log("<<<<<<<<<<<<<<<����ȫ�ֲ���<<<<<<<<<<<<<<<<<");
	round++;

	epq.decreaseRoleEffectLevel();
	epq.decreaseMonsterEffectLevel();

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
		EffectAffixes ea = epq.getRoleEffectAffixesByInterval(EffectPQ::EffectLevelInterval::EffectLevelInterval_Before_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_Before_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>�˳���ɫս��ǰ����>>>>>>>>>>>>");
			return;
		}

		// �����Ч�������ڸ�λ��ִ�е�Ч��
		if (CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_Before)
			continue;
		
		
		ea.efRound = this->round;
		efAffixes = ea;
		
		//ִ�н�ɫս��ǰ��Ч��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popRoleEffectAffixes(ea);
		
	}
	cocos2d::log(">>>>>>>>>>>>>>>�˳���ɫս��ǰ����>>>>>>>>>>>>");
	return;
}

void CombatSystem::excuteRoleInCombatOperation()
{
	cocos2d::log("<<<<<<<<<<<<<<<�����ɫս��ʱ����<<<<<<<<<<<<");

	while (true)
	{
		EffectAffixes ea = epq.getRoleEffectAffixesByInterval(EffectPQ::EffectLevelInterval::EffectLevelInterval_In_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_In_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>�˳���ɫս��ʱ����>>>>>>>>>>>>");
			return;
		}
		// �����Ч�������ڸ�λ��ִ�е�Ч��
		if (CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_In)
			continue;

		
		ea.efRound = this->round;
		efAffixes = ea;

		//ִ�н�ɫս��ʱЧ��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popRoleEffectAffixes(ea);

	}
	cocos2d::log(">>>>>>>>>>>>>>>�˳���ɫս��ʱ����>>>>>>>>>>>>");
}

void CombatSystem::excuteRoleAfterCombatOperation()
{
	cocos2d::log("<<<<<<<<<<<<<<<�����ɫս�������<<<<<<<<<<<<");

	while (true)
	{
		EffectAffixes ea = epq.getRoleEffectAffixesByInterval(EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>�˳���ɫս�������>>>>>>>>>>>>");
			return;
		}
		// �����Ч�������ڸ�λ��ִ�е�Ч��
		if (CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_After)
			continue;

		
		ea.efRound = this->round;
		efAffixes = ea;

		//ִ�н�ɫս����Ч��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popRoleEffectAffixes(ea);
	}
	cocos2d::log(">>>>>>>>>>>>>>>�˳���ɫս�������>>>>>>>>>>>>");
	return;
}

void CombatSystem::executeMonsterBeforeTheCombatOperator()
{
	cocos2d::log("<<<<<<<<<<<<<<<�������ս��ǰ����<<<<<<<<<<<<");
	while (true)
	{
		EffectAffixes ea = epq.getMonsterEffectAffixesByInterval(EffectPQ::EffectLevelInterval::EffectLevelInterval_Before_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_Before_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>�˳�����ս��ǰ����>>>>>>>>>>>>");
			return;
		}
		// �����Ч�������ڸ�λ��ִ�е�Ч��
		if (CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_Before)
			continue;

		ea.efRound = this->round;
		efAffixes = ea;

		//ִ�й���ս��ǰ��Ч��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popMonsterEffectAffixes(ea);
	}
	cocos2d::log(">>>>>>>>>>>>>>>�˳�����ս��ǰ����>>>>>>>>>>>>");
	return;
}

void CombatSystem::excuteMonsterInCombatOperator()
{
	cocos2d::log("<<<<<<<<<<<<<<<�������ս��ʱ����<<<<<<<<<<<<");

	while (epq.isMonsterEffectPQEmpty() == false)
	{
		EffectAffixes ea = epq.getMonsterEffectAffixesByInterval(EffectPQ::EffectLevelInterval::EffectLevelInterval_In_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_In_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>�˳�����ս��ʱ����>>>>>>>>>>>>");
			return;
		}
		// �����Ч�������ڸ�λ��ִ�е�Ч��
		if (CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_In)
			continue;
				
		ea.efRound = this->round;
		efAffixes = ea;

		//ִ�й���ս��ʱ��Ч��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popMonsterEffectAffixes(ea);
	}
	cocos2d::log(">>>>>>>>>>>>>>>�˳�����ս��ʱ����>>>>>>>>>>>>");
	return;
}

void CombatSystem::excuteMonsterAfterCombatOperator()
{
	cocos2d::log("<<<<<<<<<<<<<<<�������ս�������<<<<<<<<<<<<");
	while (true)
	{
		EffectAffixes ea = epq.getMonsterEffectAffixesByInterval(EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Left, EffectPQ::EffectLevelInterval::EffectLevelInterval_After_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>�˳�����ս�������>>>>>>>>>>>>");
			return;
		}
		// �����Ч�������ڸ�λ��ִ�е�Ч��
		if (CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getExcuteStyle() != Effect::ExcuteStyle_After)
			continue;

		ea.efRound = this->round;
		efAffixes = ea;

		//ִ�й���ս�����Ч��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popMonsterEffectAffixes(ea);
	}
	cocos2d::log(">>>>>>>>>>>>>>>�˳�����ս�������>>>>>>>>>>>>");
	return;
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
	csi->getDeltaTableHistory().addTotalRoleHistory(round);
	csi->getDeltaTableHistory().addTotalMonsterHistory(round);
}

bool CombatSystem::judgeEndToCombat()
{
	return false;
}

void CombatSystem::test()
{
	cocos2d::log("[warning] ע�⣺��������ս��ϵͳ��");
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
	cocos2d::log("[warning] ע�⣺�˳�ս��ϵͳ��");
}