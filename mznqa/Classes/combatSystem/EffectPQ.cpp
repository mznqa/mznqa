#pragma execution_character_set("utf-8")

#include "combatSystem/EffectPQ.h"

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
		return EffectEntity(-1,-1,-1);

	EffectEntity effect = rolePQ.top();
	//判断下一个效果是否可用
	if (effect.level / 100 == 0)
	{
		rolePQ.pop();
		cocos2d::log("[information] 成功获取下一个可用的技能！");
		return effect;
	}
	else if (effect.level / 100 == 1)
	{
		return effect;
	}
	cocos2d::log("[warning] 无下一个可用效果，返回空！");
	return EffectEntity(-1, -1, -1);
}

bool EffectPQ::isRoleEffectPQEmpty()
{
	return rolePQ.empty();
}

void EffectPQ::decreaseRoleEffectLevel()
{
	if (rolePQ.empty())
	{
		return;
	}

	std::priority_queue<EffectEntity, std::vector<EffectEntity>, std::less<EffectEntity>> temp;
	temp.swap(rolePQ);
	while (temp.empty() == false)
	{
		EffectEntity ee(temp.top());
		if (ee.level >= 200)
			ee.level -= 200;
		rolePQ.push(ee);
		temp.pop();
	}
}

int EffectPQ::getRoleEPQLevelMaxByRound(int relRound)
{
	if (relRound < 0)
	{
		return -1;
	}

	int levelMin = relRound * 200;
	int levelMax = (relRound + 1) * 200 - 1;
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

void EffectPQ::popRoleEffect()
{
	rolePQ.pop();
}

void EffectPQ::pushMonsterEffect(EffectEntity effect)
{
	monsterPQ.push(effect);
}

EffectEntity EffectPQ::getMonsterNextEffect()
{
	if (monsterPQ.empty())
		return EffectEntity(-1, -1, -1);

	EffectEntity effect = monsterPQ.top();
	if (effect.level / 100 == 0)
	{
		monsterPQ.pop();
		return effect;
	}else if (effect.level / 100 == 1)
	{
		return effect;
	}

	return EffectEntity(-1, -1, -1);
}

bool EffectPQ::isMonsterEffectPQEmpty()
{
	return monsterPQ.empty();
}

void EffectPQ::decreaseMonsterEffectLevel()
{
	if (monsterPQ.empty())
	{
		return;
	}

	std::priority_queue<EffectEntity, std::vector<EffectEntity>, std::less<EffectEntity>> temp;
	temp.swap(monsterPQ);
	while (temp.empty() == false)
	{
		EffectEntity ee(temp.top());
		if (ee.level >= 200)
			ee.level -= 200;
		monsterPQ.push(ee);
		temp.pop();
	}
}

int EffectPQ::getMonsterEPQLevelMaxByRound(int relRound)
{
	if (relRound < 0)
	{
		return -1;
	}

	int levelMin = relRound * 200;
	int levelMax = (relRound + 1) * 200 - 1;
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

void EffectPQ::popMonsterEffect()
{
	monsterPQ.pop();
}
