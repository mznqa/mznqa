#pragma execution_character_set("utf-8")

#include "combatSystem/EffectPQ.h"
#include "combatSystem/DeltaTableHistory.h"
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
	if (effect.level/100 == 1)
	{
		rolePQ.pop();
		return effect;
	}
	return EffectEntity(0, nullptr, nullptr, 0);
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

int EffectPQ::getRoleEPQLevelMaxByRound(int roundIndex)
{
	if (roundIndex < 0)
	{
		cocos2d::log("提示：给定错误的相对回合数（%d）", roundIndex);
		return -1;
	}

	int levelMin = roundIndex * 100;
	int levelMax = (roundIndex + 1) * 100 - 1;
	int result = -1;
	int level;

	std::queue<EffectEntity> temp;
	while (rolePQ.empty() == false)
	{
		level = rolePQ.top().level;
		if (levelMin <= level && level <= levelMax)
			if (level > result)
				result = level;
		temp.push(rolePQ.top());
		rolePQ.pop();
	}

	while (temp.empty() == false)
	{
		rolePQ.push(temp.front());
		temp.pop();
	}

	return result;
}

void EffectPQ::decreaseRoleEffectLevel()
{
	if (rolePQ.empty())
	{
		return;
	}
	
	std::priority_queue<EffectEntity, std::vector<EffectEntity>, std::greater<EffectEntity>> temp;
	temp.swap(rolePQ);
	while (temp.empty() == false)
	{
		EffectEntity ee(temp.top());
		if (ee.level >= 100)
			ee.level -= 100;
		rolePQ.push(ee);
		temp.pop();
	}
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
	if (effect.level / 100 == 1)
	{
		monsterPQ.pop();
		return effect;
	}
	return EffectEntity(0, nullptr, nullptr, 0);
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

int EffectPQ::getMonsterEPQLevelMaxByRound(int roundIndex)
{
	if (roundIndex < 0)
	{
		cocos2d::log("提示：给定错误的相对回合数（%d）", roundIndex);
		return -1;
	}

	int levelMin = roundIndex * 100;
	int levelMax = (roundIndex + 1) * 100 - 1;
	int result = -1;
	int level;

	std::queue<EffectEntity> temp;
	while (monsterPQ.empty() == false)
	{
		level = monsterPQ.top().level;
		if (levelMin <= level && level <= levelMax)
			if (level > result)
				result = level;
		temp.push(monsterPQ.top());
		monsterPQ.pop();
	}

	while (temp.empty() == false)
	{
		monsterPQ.push(temp.front());
		temp.pop();
	}

	return result;
}

void EffectPQ::decreaseMonsterEffectLevel()
{
	if (rolePQ.empty())
	{
		return;
	}

	std::priority_queue<EffectEntity, std::vector<EffectEntity>, std::greater<EffectEntity>> temp;
	temp.swap(rolePQ);
	while (temp.empty() == false)
	{
		EffectEntity ee(temp.top());
		if (ee.level >= 100)
			ee.level -= 100;
		monsterPQ.push(ee);
		temp.pop();
	}
}

void EffectPQ::test()
{
	// 推送五个效果
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