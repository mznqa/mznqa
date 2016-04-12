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
	cocos2d::log("<<<<<<<<<<<<<<<����ȫ�ֲ���<<<<<<<<<<<<<<<<<");
	round++;
	epq.decreaseRoleEffectLevel();
	epq.decreaseMonsterEffectLevel();
	cocos2d::log(">>>>>>>>>>>>>>>�˳�ȫ�ֲ���>>>>>>>>>>>>>>>>>");

}

void CombatSystem::executeRoleBeforeTheCombatOperation()
{
	cocos2d::log("<<<<<<<<<<<<<<<�����ɫս��ǰ����<<<<<<<<<<<<");
	while (true)
	{
		EffectAffixes ea = epq.getRoleEffectAffixesByInterval(EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>�˳���ɫս��ǰ����>>>>>>>>>>>>");
			return;
		}
		//�������ȼ�������Ч�����ڽ�ɫս����ִ�еģ����ڽ�ɫս��ǰ������Ч����ִ��
		if (ea.level / EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left == 1)
		{
			break;
		}
		//ִ�н�ɫս��ǰ��Ч��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popRoleEffectAffixes(ea);
	}
	cocos2d::log(">>>>>>>>>>>>>>>�˳���ɫս��ǰ����>>>>>>>>>>>>");
	return;
}

void CombatSystem::excuteRoleInCombatOperation(int cardId)
{
	cocos2d::log("<<<<<<<<<<<<<<<�����ɫս��ʱ����<<<<<<<<<<<<");

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
			//����Ч�������ڵ�ǰ�غ���ִ��
			if (startRound == 0)
			{
				temp.level += epq.getRoleEPQLevelMaxByRoundAndInterval(continueRound, EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Right) + 1;
				//����Ч�����ڽ�ɫս����ִ��
				if (cs->getEffectSet().at(efIndex).getArgs().size() == 2)
				{
					temp.level += EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left - EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Left;
				}
			}
			//����Ч���ǲ����ڵ�ǰ�غ�ִ��
			else
			{
				temp.level += epq.getRoleEPQLevelMaxByRoundAndInterval(continueRound + 1, EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Right) + 1;
				//����Ч�����ڽ�ɫս����ִ��
				if (cs->getEffectSet().at(efIndex).getArgs().size() == 2)
				{
					temp.level += EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left - EffectAffixes::EffectLevelInterval_Before_Left;
				}
			}
			epq.pushRoleEffectAffixes(temp);
			efIndex++;
		}
		//����Ч����һ������Ч��������Ӹü��ܿ���ʣ��Ч��
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
		//�������ȼ�������Ч�����ڽ�ɫս����ִ�еģ����ڽ�ɫս��ʱ������Ч����ִ��
		if (ea.level / EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left == 1)
		{
			break;
		}
		//ִ�н�ɫս��ʱЧ��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popRoleEffectAffixes(ea);
	}
	cocos2d::log(">>>>>>>>>>>>>>>�˳���ɫսʱǰ����>>>>>>>>>>>>");
}

void CombatSystem::excuteRoleAfterCombatOperation()
{
	cocos2d::log("<<<<<<<<<<<<<<<�����ɫս�������<<<<<<<<<<<<");

	while (true)
	{
		EffectAffixes ea = epq.getRoleEffectAffixesByInterval(EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>�˳���ɫս�������>>>>>>>>>>>>");
			return;
		}
		//ִ�н�ɫս����Ч��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popRoleEffectAffixes(ea);
	}
	cocos2d::log(">>>>>>>>>>>>>>>�˳���ɫս�������>>>>>>>>>>>>");

}

void CombatSystem::executeMonsterBeforeTheCombatOperator()
{
	cocos2d::log("<<<<<<<<<<<<<<<�������ս��ǰ����<<<<<<<<<<<<");
	while (true)
	{
		EffectAffixes ea = epq.getMonsterEffectAffixesByInterval(EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Left,EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>�˳�����ս��ǰ����>>>>>>>>>>>>");
			return;
		}
		//�������ȼ�������Ч�����ڹ���ս����ִ�еģ����ڹ���ս��ǰ������Ч����ִ��
		if (ea.level / EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left == 1)
		{
			break;
		}
		//ִ�й���ս��ǰ��Ч��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popMonsterEffectAffixes(ea);
	}
	cocos2d::log(">>>>>>>>>>>>>>>�˳�����ս��ǰ����>>>>>>>>>>>>");
	return;
}

void CombatSystem::excuteMonsterInCombatOperator(int cardId)
{
	cocos2d::log("<<<<<<<<<<<<<<<�������ս��ʱ����<<<<<<<<<<<<");

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
			//����Ч�������ڵ�ǰ�غ���ִ��
			if (startRound == 0)
			{
				temp.level += epq.getMonsterEPQLevelMaxByRoundAndInterval(continueRound, EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Right) + 1;
				//����Ч�����ڹ���ս����ִ��
				if (cs->getEffectSet().at(efIndex).getArgs().size() == 2)
				{
					temp.level += EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left - EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Left;
				}
			}
			//����Ч���ǲ����ڵ�ǰ�غ�ִ��
			else
			{
				temp.level += epq.getMonsterEPQLevelMaxByRoundAndInterval(continueRound + 1, EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Right) + 1;
				//����Ч�����ڹ���ս����ִ��
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
		//�������ȼ�������Ч�����ڹ���ս����ִ�еģ����ڹ���ս��ʱ������Ч����ִ��
		if (ea.level / EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left == 1)
		{
			break;
		}
		//ִ�й���ս��ʱ��Ч��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popMonsterEffectAffixes(ea);
	}
	cocos2d::log(">>>>>>>>>>>>>>>�˳�����ս��ǰ����>>>>>>>>>>>>");
	return;
}
 
void CombatSystem::excuteMonsterAfterCombatOperator()
{
	cocos2d::log("<<<<<<<<<<<<<<<�������ս�������<<<<<<<<<<<<");
	while (true)
	{
		EffectAffixes ea = epq.getMonsterEffectAffixesByInterval(EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log(">>>>>>>>>>>>>>>�˳�����ս��ǰ����>>>>>>>>>>>>");
			return;
		}
		//ִ�й���ս�����Ч��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popMonsterEffectAffixes(ea);
	}
	cocos2d::log(">>>>>>>>>>>>>>>�˳�����ս��ǰ����>>>>>>>>>>>>");
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
	excuteRoleInCombatOperation(roleUseCardId);
	excuteMonsterInCombatOperator(monsterUseCardId);
	
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

bool CombatSystem::judgeEndToCombat()
{
	return false;
}

void CombatSystem::test()
{
	cocos2d::log("[warning] ע�⣺��������ս��ϵͳ��");
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
	cocos2d::log("[warning] ע�⣺�˳�ս��ϵͳ��");
}
