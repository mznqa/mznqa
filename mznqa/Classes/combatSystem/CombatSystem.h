#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEM_H_
#define MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEM_H_

#include "combatSystem/EffectPQ.h"


class CombatSystem
{
public:	
	CombatSystem();
	~CombatSystem();

	
	//执行每回合内的全局操作
	void executeGlobalOperation();


	//执行角色战斗前操作
	void executeRoleBeforeTheCombatOperation();
	//执行角色战斗时操作
	void excuteRoleInCombatOperation(int cardId);
	//执行角色战斗后操作
	void excuteRoleAfterCombatOperation();


	//执行怪物战斗前操作
	void executeMonsterBeforeTheCombatOperator();
	//执行怪物战斗时操作
	void excuteMonsterInCombatOperator(int cardId);
	//执行怪物战斗后操作
	void excuteMonsterAfterCombatOperator();

	//执行战斗
	void excuteCombat();

	//设置使用卡的id
	void setUseCardId(const int roleUseCardId, const int monsterUseCardId);

	//判断是否结束战斗
	bool judgeEndToCombat();

	//测试单元
	void test();

private:
	//战斗回合数
	static int round;

	//效果队列
	EffectPQ epq;

	//存放角色要使用的技能卡的id
	int roleUseCardId;

	//存放怪物要使用的技能卡id
	int monsterUseCardId;
};


#endif // !MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEM_H_

