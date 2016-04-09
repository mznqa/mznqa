#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEM_H_
#define MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEM_H_

#include "combatSystem/EffectPQ.h"


class CombatSystem
{
public:	
	CombatSystem();
	~CombatSystem();

	
	//执行战斗回合内的全局属性
	void executeGlobalEffect();


	//执行角色持续效果
	void executeRoleBeforeTheCombatEffect();
	//执行角色战斗时效果
	void excuteRoleInCombatEffect(int cardId);
	//执行角色战斗后的效果
	void excuteRoleAfterCombatEffect();


	//执行怪物持续效果
	void executeMonsterBeforeTheCombatEffect();
	//执行怪物战斗时的效果
	void excuteMonsterInCombatEffect(int cardId);
	//执行怪物战斗后的效果
	void excuteMonsterAfterCombatEffect();


	//执行战斗
	void excuteCombat(int cardId);

	void test();

private:
	//战斗回合数
	static int round;

	//效果队列
	EffectPQ epq;
};


#endif // !MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEM_H_

