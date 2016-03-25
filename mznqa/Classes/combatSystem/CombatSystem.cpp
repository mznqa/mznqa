#pragma execution_character_set("utf-8")

#include "combatSystem/CombatSystem.h"
#include "cardParser/CardParserSkill.h"
#include "cocos2d.h"

int CombatSystem::round = 0;

CombatSystem::~CombatSystem()
{
	
}

CombatSystem* CombatSystem::getInstance()
{
	static	CombatSystem instance;
	return &instance;
}

void CombatSystem::executeGlobalEffect()
{
	cocos2d::log("++++++++CombatSystem.executeGlobalEffect()");
	round++;
	
	epq.decreaseRoleEffectLevel();
	epq.decreaseMonsterEffectLevel();


	cocos2d::log("--------CombatSystem.executeGlobalEffect()");

}

void CombatSystem::executeRoleBeforeTheCombatEffect()
{
	cocos2d::log("++++++++CombatSystem.executeRoleBeforeTheCombatEffect()");
	while (true)
	{
		EffectEntity ee = epq.getRoleNextEffect();
		if (!ee.fun)
		{
			cocos2d::log("提示： 当前回合的角色技能，已经没有可执行的效果了!");
			return;
		}
		(ee.fun)(ee.arr, ee.size);
	}
	cocos2d::log("--------CombatSystem.executeRoleBeforeTheCombatEffect()");
}

void CombatSystem::excuteRoleInCombatEffect(int cardId)
{
	cocos2d::log("++++++++CombatSystem.excuteRoleInCombatEffect()");
	CardParserSkill cps;
	int index = cps.createCardSkillJsonBuffer();
	if (index == -1)
	{
		return;
	}
	auto pq = cps.parseEffect(cardId);
	EffectEntity temp(-1, nullptr, nullptr, 0);
	int i = 0;
	int j = 0;
	int k = 0;
	while (pq.empty() == false)
	{
		temp = pq.top();
		if (temp.arr[0] == 0)
			temp.level = i++;
		else if (temp.arr[0] == 1)
			temp.level = (j++) + 100;
		else if (temp.arr[0] == 2)
			temp.level = (k++) + 200;
		epq.pushRoleEffect(temp);
		pq.pop();
	}

	while (epq.isRoleEffectPQEmpty() == false)
	{
		EffectEntity ee = epq.getRoleNextEffect();
		if (!ee.fun)
		{
			cocos2d::log("提示： 当前回合的角色技能，已经没有可执行的效果了!");
			return;
		}
		(ee.fun)(ee.arr, ee.size);
	}
	cocos2d::log("--------CombatSystem.excuteRoleInCombatEffect()");
}

void CombatSystem::excuteRoleAfterCombatEffect()
{
	cocos2d::log("++++++++CombatSystem.excuteRoleAfterCombatEffect()");
	while (true)
	{
		EffectEntity ee = epq.getRoleNextEffect();
		if (!ee.fun)
		{
			cocos2d::log("提示： 当前回合的角色技能，已经没有可执行的效果了!");
			return;
		}
		(ee.fun)(ee.arr, ee.size);
	}
	cocos2d::log("--------CombatSystem.excuteRoleAfterCombatEffect()");
}


void CombatSystem::executeMonsterBeforeTheCombatEffect()
{
	cocos2d::log("++++++++CombatSystem.executeMonsterBeforeTheCombatEffect()");
	while (true)
	{
		EffectEntity ee = epq.getMonsterNextEffect();
		if (!ee.fun)
		{
			cocos2d::log("提示： 当前回合的怪物技能，已经没有可执行的效果了!");
			return;
		}
		(ee.fun)(ee.arr, ee.size);
	}
	cocos2d::log("--------CombatSystem.executeMonsterBeforeTheCombatEffect()");
}

void CombatSystem::excuteMonsterInCombatEffect(int cardId)
{
	cocos2d::log("++++++++CombatSystem.excuteMonsterInCombatEffect()");
	CardParserSkill cps;
	int index = cps.createCardSkillJsonBuffer();
	if (index == -1)
	{
		return;
	}
	auto pq = cps.parseEffect(cardId);
	EffectEntity temp(-1, nullptr, nullptr, 0);
	int i = 0;
	int j = 0;
	int k = 0;
	while (pq.empty() == false)
	{
		temp = pq.top();
		if (temp.arr[0] == 0)
			temp.level = i++;
		else if (temp.arr[0] == 1)
			temp.level = (j++) + 100;
		else if (temp.arr[0] == 2)
			temp.level = (k++) + 200;
		epq.pushMonsterEffect(temp);
		pq.pop();
	}

	while (epq.isRoleEffectPQEmpty() == false)
	{
		EffectEntity ee = epq.getMonsterNextEffect();
		if (!ee.fun)
		{
			cocos2d::log("提示： 当前回合的怪物技能，已经没有可执行的效果了!");
			return;
		}
		(ee.fun)(ee.arr, ee.size);

	}
	cocos2d::log("--------CombatSystem.excuteMonsterInCombatEffect()");
}

void CombatSystem::excuteMonsterAfterCombatEffect()
{
	cocos2d::log("++++++++CombatSystem.excuteMonsterAfterCombatEffect()");
	while (true)
	{
		EffectEntity ee = epq.getMonsterNextEffect();
		if (!ee.fun)
		{
			cocos2d::log("提示： 当前回合的怪物技能，已经没有可执行的效果了!");
			cocos2d::log("--------CombatSystem.excuteMonsterAfterCombatEffect()");
			return;
		}
		(ee.fun)(ee.arr, ee.size);
	}
}

void CombatSystem::excuteCombat(int cardId)
{
	//执行全局效果
	executeGlobalEffect();

	//战斗前执行效果
	executeRoleBeforeTheCombatEffect();
	executeMonsterBeforeTheCombatEffect();
	
	//战斗时执行效果
	excuteRoleInCombatEffect(cardId);
	excuteMonsterInCombatEffect(cardId);
	
	//战斗后执行效果
	excuteRoleAfterCombatEffect();
	excuteMonsterAfterCombatEffect();
}

void CombatSystem::test()
{
	//std::vector<int> id = { 1,2,3,4,5 };
	//auto it = id.begin();
	//for (it; it != id.end();++it)
	//{
	//	excuteCombat(*it);
	//}
	//while (!id.empty())
	//{
	//	id.pop_back();
	//}

}
