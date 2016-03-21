#pragma execution_character_set("utf-8")

#include "combatSystem/EffectPQ.h"
#include "combatSystem/EffectHistory.h"
#include "cocos2d.h"

EffectPQ::EffectPQ()
{
}

EffectPQ::~EffectPQ()
{
}

void EffectPQ::pushRoleEffect(EffectEntity effect)
{
	rolePQ.push(effect);
}

EffectEntity EffectPQ::getRoleNextEffect()
{
	if (rolePQ.empty())
		return EffectEntity(0, nullptr, nullptr, 0);

	EffectEntity effect = rolePQ.top();
	rolePQ.pop();
	return effect;
}

bool EffectPQ::isRoleEffectPQEmpty()
{
	return rolePQ.empty();
}

void EffectPQ::clearRoleEffectPQ()
{
	while (rolePQ.empty() == false)
		rolePQ.pop();
}

void EffectPQ::pushMonsterEffect(EffectEntity effect)
{
	monsterPQ.push(effect);
}

EffectEntity EffectPQ::getMonsterNextEffect()
{
	if (monsterPQ.empty())
		return EffectEntity(0, nullptr, nullptr, 0);

	EffectEntity effect = monsterPQ.top();
	monsterPQ.pop();
	return effect;
}

bool EffectPQ::isMonsterEffectPQEmpty()
{
	return monsterPQ.empty();
}

void EffectPQ::clearMonsterEffectPQ()
{
	while (monsterPQ.empty() == false)
		monsterPQ.pop();
}

void EffectPQ::test()
{
	//// 推送五个效果
	//pushRoleEffect(EffectEntity(1, rf, new int[3]{1, 2, 3}, 3));
	//pushRoleEffect(EffectEntity(5, rf, new int[3]{11, 12, 13}, 3));
	//pushRoleEffect(EffectEntity(4, rf, new int[3]{21, 22, 23}, 3));
	//pushRoleEffect(EffectEntity(3, rf, new int[3]{31, 32, 33}, 3));
	//pushRoleEffect(EffectEntity(2, rf, new int[3]{41, 42, 43}, 3));

	//EffectEntity temp(0, nullptr, nullptr, 0);
	//for (int i = 0; i < 5; ++i)
	//{
	//	temp = getRoleNextEffect();
	//	cocos2d::log("role-effect-level : %d, isEmpty = %d", temp.level, rolePQ.empty());
	//	(temp.fun)(temp.arr, temp.size);
	//}
}