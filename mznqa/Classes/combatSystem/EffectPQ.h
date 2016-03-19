#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_EFFECTPQ_H_
#define MZNQA_CLASSES_COMBATSYSTEM_EFFECTPQ_H_

#include <queue>

#include "combatSystem/EffectEntity.h"

class EffectPQ
{
private:

	// 角色用，效果队列
	std::priority_queue<EffectEntity, std::vector<EffectEntity>, std::less<EffectEntity>> rolePQ;

	// 怪物用，效果队列
	std::priority_queue<EffectEntity, std::vector<EffectEntity>, std::less<EffectEntity>> monsterPQ;

public:
	EffectPQ();
	~EffectPQ();

	// 向角色效果队列中推送新效果
	void pushRoleEffect(EffectEntity effect);
	// 获取一个角色待执行的效果
	EffectEntity getRoleNextEffect();
	// 判断角色效果队列是否为空
	bool isRoleEffectPQEmpty();
	// 清空角色效果队列
	void clearRoleEffectPQ();

	// 向怪物效果队列中推送新效果
	void pushMonsterEffect(EffectEntity effect);
	// 获取一个怪物待执行效果
	EffectEntity getMonsterNextEffect();
	// 判断怪物的效果队列是否为空
	bool isMonsterEffectPQEmpty();
	// 清空怪物消息队列
	void clearMonsterEffectPQ();

	void test();
};

#endif
