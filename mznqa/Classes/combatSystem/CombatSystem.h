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
	void excuteCombat(int roleUseCardId, int monsterUseCardId);

	//添加角色使用的技能卡ID
	void pushRoleUseCardId(int useCardId);

	//添加怪物使用的技能卡ID
	void pushMonsterUseCardId(int useCardId);

	//删除角色使用的技能卡ID
	void popRoleUseCardId();

	//删除怪物使用的技能卡ID
	void popMonsterUseCardId();


	void test();

private:
	//战斗回合数
	static int round;

	//效果队列
	EffectPQ epq;

	//存放角色要使用的技能卡的id
	std::queue<int> roleUseCardId;

	//存放怪物要使用的技能卡id
	std::queue<int> monsterUseCardId;
};


#endif // !MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEM_H_

