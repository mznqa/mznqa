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
	cocos2d::log("[information] ִ�� ��ɫս��ǰ �Ĳ�������ǰ�غ�Ϊ %d ", round);
	while (true)
	{
		EffectAffixes ea = epq.getRoleEffectAffixesByInterval(EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log("[information] ��ɫս��ǰ���Ѿ�û�п�ִ�е�Ч���ˣ�");
			return;
		}
		//�������ȼ�������Ч�����ڽ�ɫս����ִ�еģ����ڽ�ɫս��ǰ������Ч����ִ��
		if (ea.level / EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left == 1)
		{
			break;
		}
		//ִ�н�ɫս��ǰ��Ч��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popRoleEffectAffixes();
	}

}

void CombatSystem::excuteRoleInCombatOperation(int cardId)
{
	cocos2d::log("[information] ִ�� ��ɫս��ʱ �Ĳ�������ǰ�غ�Ϊ %d ", round);
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
			//����Ч�������ڵ�ǰ�غ���ִ��
			if (startRound == 0)
			{
				temp.level += epq.getRoleEPQLevelMaxByRoundAndInterval(continueRound, EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Right) + 1;
				//����Ч�����ڽ�ɫս����ִ��
				if (cs->getEffectSet().at(effectSize).getArgs().size() == 2)
				{
					temp.level += EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left - EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Left;
				}
			}
			//����Ч���ǲ����ڵ�ǰ�غ�ִ��
			else
			{
				temp.level += epq.getRoleEPQLevelMaxByRoundAndInterval(continueRound, EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Right) + 1;
				//����Ч�����ڽ�ɫս����ִ��
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
			cocos2d::log("[information] ��ɫս��ʱ���Ѿ�û�п�ִ�е�Ч����!");
			return;
		}
		//�������ȼ�������Ч�����ڽ�ɫս����ִ�еģ����ڽ�ɫս��ʱ������Ч����ִ��
		if (ea.level / EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left == 1)
		{
			break;
		}
		//ִ�н�ɫս��ʱЧ��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popRoleEffectAffixes();
	}
}

void CombatSystem::excuteRoleAfterCombatOperation()
{
	cocos2d::log("[information] ִ�� ��ɫս���� �Ĳ�������ǰ�غ�Ϊ %d ", round);
	while (true)
	{
		EffectAffixes ea = epq.getRoleEffectAffixesByInterval(EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log("[information] ��ɫս�����Ѿ�û�п�ִ�е�Ч����!");
			return;
		}
		//ִ�н�ɫս����Ч��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popRoleEffectAffixes();
	}
}

void CombatSystem::executeMonsterBeforeTheCombatOperator()
{
	cocos2d::log("[information] ִ�� ����ս��ǰ �Ĳ�������ǰ�غ�Ϊ %d ", round);
	while (true)
	{
		EffectAffixes ea = epq.getMonsterEffectAffixesByInterval(EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Left,EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log("[information] ����ս��ǰ���Ѿ�û�п�ִ�е�Ч����!");
			return;
		}
		//�������ȼ�������Ч�����ڹ���ս����ִ�еģ����ڹ���ս��ǰ������Ч����ִ��
		if (ea.level / EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left == 1)
		{
			break;
		}
		//ִ�й���ս��ǰ��Ч��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popMonsterEffectAffixes();
	}

}

void CombatSystem::excuteMonsterInCombatOperator(int cardId)
{
	cocos2d::log("[information] ִ�� ����ս��ʱ �Ĳ�������ǰ�غ�Ϊ %d ", round);
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
			//����Ч�������ڵ�ǰ�غ���ִ��
			if (startRound == 0)
			{
				temp.level += epq.getMonsterEPQLevelMaxByRoundAndInterval(continueRound, EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Right) + 1;
				//����Ч�����ڹ���ս����ִ��
				if (cs->getEffectSet().at(effectSize).getArgs().size() == 2)
				{
					temp.level += EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left - EffectAffixes::EffectLevelInterval::EffectLevelInterval_In_Left;
				}
			}
			//����Ч���ǲ����ڵ�ǰ�غ�ִ��
			else
			{
				temp.level += epq.getMonsterEPQLevelMaxByRoundAndInterval(continueRound, EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_Before_Right) + 1;
				//����Ч�����ڹ���ս����ִ��
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
			cocos2d::log("[information] ����ս��ʱ���Ѿ�û�п�ִ�е�Ч����!");
			return;
		}
		//�������ȼ�������Ч�����ڹ���ս����ִ�еģ����ڹ���ս��ʱ������Ч����ִ��
		if (ea.level / EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left == 1)
		{
			break;
		}
		//ִ�й���ս��ʱ��Ч��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popMonsterEffectAffixes();
	}

}
 
void CombatSystem::excuteMonsterAfterCombatOperator()
{
	cocos2d::log("[information] ִ�� ����ս���� �Ĳ�������ǰ�غ�Ϊ %d ", round);

	while (true)
	{
		EffectAffixes ea = epq.getMonsterEffectAffixesByInterval(EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Left, EffectAffixes::EffectLevelInterval::EffectLevelInterval_After_Right);
		if (ea.cardId == EffectAffixes::invalidCardIdValue)
		{
			cocos2d::log("[information] ����ս�����Ѿ�û�п�ִ�е�Ч����!");
			return;
		}
		//ִ�й���ս�����Ч��
		EffectFunSet::getFunByIndex(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getFunIndex())(CardSet::Instance()->getCardSkillByID(ea.cardId)->getEffectSet().at(ea.effectIndex).getArgs());
		epq.popMonsterEffectAffixes();
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
}



bool CombatSystem::judgeEndToCombat()
{
	return false;
}

void CombatSystem::test()
{
	cocos2d::log("[warning] ע�⣺��������ս��ϵͳ��");
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
	cocos2d::log("[warning] ע�⣺�˳�ս��ϵͳ��");
}
