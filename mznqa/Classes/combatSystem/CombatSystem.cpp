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
	cocos2d::log("[information] ִ�� ��ɫǰ �ĳ���Ч������ǰ�غ�Ϊ %d ", round);
	while (true)
	{
		EffectEntity ee = epq.getRoleNextEffect();
		if (ee.cardId == -1)
		{
			cocos2d::log("[information] ��ǰ�غϵĽ�ɫ���ܣ��Ѿ�û�п�ִ�е�Ч����!");
			return;
		}
		//����Ч�����ڳ�����ִ�У������ȼ�������100
		if (ee.level / 100 == 1)
		{
			break;
		}
		//ִ��Ч��
		EffectFunSet::getFunByIndex(ee.effectIndex)(CardSet::Instance()->getCardSkillByID(ee.cardId)->getEffectSet().back().getArgs());
	}

}

void CombatSystem::excuteRoleInCombatEffect(int cardId)
{
	cocos2d::log("[information] ִ�� ��ɫ�� ��Ч������ǰ�غ�Ϊ %d ", round);
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
			cocos2d::log("[information] ��ǰ�غϵĽ�ɫ���ܣ��Ѿ�û�п�ִ�е�Ч����!");
			return;
		}
		//����Ч�����ڽ�ɫ������ִ�У���������Ч����ִ��
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
	cocos2d::log("[information] ִ�� ��ɫ�� �ĳ���Ч������ǰ�غ�Ϊ %d ", round);

	while (true)
	{
		EffectEntity ee = epq.getRoleNextEffect();
		if (ee.cardId == -1)
		{
			cocos2d::log("[information] ��ǰ�غϵĽ�ɫ���ܣ��Ѿ�û�п�ִ�е�Ч����!");
			return;
		}
		EffectFunSet::getFunByIndex(ee.effectIndex)(CardSet::Instance()->getCardSkillByID(ee.cardId)->getEffectSet().back().getArgs());
		epq.popRoleEffect();
	}
}


void CombatSystem::executeMonsterBeforeTheCombatEffect()
{
	cocos2d::log("[information] ִ�� ����ǰ �ĳ���Ч������ǰ�غ�Ϊ %d ", round);

	while (true)
	{
		EffectEntity ee = epq.getMonsterNextEffect();
		if (ee.cardId == -1)
		{
			cocos2d::log("[information] ��ǰ�غϵĹ��＼�ܣ��Ѿ�û�п�ִ�е�Ч����!");
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
	cocos2d::log("[information] ִ�� ������ ��Ч������ǰ�غ�Ϊ %d ", round);
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
			cocos2d::log("[information] ��ǰ�غϵĹ��＼�ܣ��Ѿ�û�п�ִ�е�Ч����!");
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
	cocos2d::log("[information] ִ�� ����� �ĳ���Ч������ǰ�غ�Ϊ %d ", round);

	while (true)
	{
		EffectEntity ee = epq.getMonsterNextEffect();

		if (ee.cardId == -1)
		{
			cocos2d::log("[information] ��ǰ�غϵĹ��＼�ܣ��Ѿ�û�п�ִ�е�Ч����!");
			return;
		}
	EffectFunSet::getFunByIndex(ee.effectIndex)(CardSet::Instance()->getCardSkillByID(ee.cardId)->getEffectSet().back().getArgs());
		epq.popMonsterEffect();
	}
}

void CombatSystem::excuteCombat(int roleUseCardId,int monsterUseCardId)
{
	//ִ��ȫ��Ч��
	executeGlobalEffect();

	//ս��ǰִ��Ч��
	executeRoleBeforeTheCombatEffect();
	executeMonsterBeforeTheCombatEffect();
	
	//ս��ʱִ��Ч��
	excuteRoleInCombatEffect(roleUseCardId);
	excuteMonsterInCombatEffect(monsterUseCardId);
	
	//ս����ִ��Ч��
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
	cocos2d::log("[warning] ע�⣺��������ս��ϵͳ��");
	
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
	
	cocos2d::log("[warning] ע�⣺�˳�ս��ϵͳ��");

}
