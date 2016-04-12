#pragma execution_character_set("utf-8")

#include "combatSystem/EffectPQ.h"

#include "cocos2d.h"

const EffectAffixes EffectPQ::nullEffectAffixes = EffectAffixes(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);

EffectPQ::EffectPQ()
{
}

EffectPQ::~EffectPQ()
{
}

void EffectPQ::pushRoleEffectAffixes(EffectAffixes effectAffixes)
{
	rolePQ.push(effectAffixes);
}

bool EffectPQ::isRoleEffectPQEmpty()
{
	return rolePQ.empty();
}

EffectAffixes EffectPQ::getRoleEffectAffixesByInterval(EffectAffixes::EffectLevelInterval leftInterval, EffectAffixes::EffectLevelInterval rightInterval)
{
	if (rolePQ.empty())
	{
		return nullEffectAffixes;
	}

	std::priority_queue <EffectAffixes, std::vector<EffectAffixes>, std::greater<EffectAffixes>> temp = rolePQ;
	while (!temp.empty())
	{
		EffectAffixes effectAffixes = temp.top();
		temp.pop();
		if ((leftInterval <= effectAffixes.level) && (effectAffixes.level <= rightInterval))
		{
			cocos2d::log("[information] 成功获取一个角色效果附加属性(%d,%d)",effectAffixes.cardId,effectAffixes.effectIndex);
			return effectAffixes;
		}

	}
	return nullEffectAffixes;
}


void EffectPQ::decreaseRoleEffectLevel()
{
	if (rolePQ.empty())
	{
		return;
	}

	std::priority_queue <EffectAffixes, std::vector<EffectAffixes>, std::greater<EffectAffixes>> temp;
	temp.swap(rolePQ);
	while (temp.empty() == false)
	{
		EffectAffixes ea(temp.top());
		if (ea.level >= EffectAffixes::roundEffectLevel)
			ea.level -= EffectAffixes::roundEffectLevel;
		rolePQ.push(ea);
		temp.pop();
	}
}

int EffectPQ::getRoleEPQLevelMaxByRoundAndInterval(int relRound, EffectAffixes::EffectLevelInterval leftInterval, EffectAffixes::EffectLevelInterval rightInterval)
{
	if (relRound < 0)
	{
		cocos2d::log("[warning] 相对回合数 %d 指定有误，请检查！", relRound);
		return -1;
	}

	int levelMin = relRound * EffectAffixes::roundEffectLevel + leftInterval;
	int levelMax = relRound * EffectAffixes::roundEffectLevel + rightInterval - 1;
	int result = levelMin;
	int level;

	std::queue<EffectAffixes> temp;
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

void EffectPQ::popRoleEffectAffixes()
{
	rolePQ.pop();
}

void EffectPQ::popRoleEffectAffixes(EffectAffixes::EffectLevelInterval leftInterval, EffectAffixes::EffectLevelInterval rightInterval)
{
	if (rolePQ.empty())
	{
		return;
	}
	std::priority_queue <EffectAffixes, std::vector<EffectAffixes>, std::greater<EffectAffixes>> temp;
	bool flag = true;
	temp.swap(rolePQ);
	while (!temp.empty())
	{
		EffectAffixes ea(temp.top());
		temp.pop();
		if (ea.level <= leftInterval && ea.level <= rightInterval && flag)
		{
			flag = false;
			continue;
		}
		rolePQ.push(ea);
	}
}

void EffectPQ::popRoleEffectAffixes(EffectAffixes effectAffixes)
{
	if (rolePQ.empty())
	{
		return;
	}
	std::priority_queue <EffectAffixes, std::vector<EffectAffixes>, std::greater<EffectAffixes>> temp;
	temp.swap(rolePQ);
	while (!temp.empty())
	{
		EffectAffixes ea(temp.top());
		temp.pop();
		if (ea == effectAffixes)
		{
			continue;
		}
		rolePQ.push(ea);
	}
}

void EffectPQ::pushMonsterEffectAffixes(EffectAffixes effectAffixes)
{
	monsterPQ.push(effectAffixes);
}

bool EffectPQ::isMonsterEffectPQEmpty()
{
	return monsterPQ.empty();
}

EffectAffixes EffectPQ::getMonsterEffectAffixesByInterval(EffectAffixes::EffectLevelInterval leftInterval, EffectAffixes::EffectLevelInterval rightInterval)
{
	if (monsterPQ.empty())
	{
		return nullEffectAffixes;
	}
	std::priority_queue <EffectAffixes, std::vector<EffectAffixes>, std::greater<EffectAffixes>> temp = monsterPQ;
	while (!temp.empty())
	{
		EffectAffixes effectAffixes = temp.top();
		temp.pop();
		if ((leftInterval <= effectAffixes.level) && (effectAffixes.level <= rightInterval))
		{
			cocos2d::log("[information] 成功获取一个怪物效果附加属性(%d,%d)",effectAffixes.cardId,effectAffixes.effectIndex);
			return effectAffixes;
		}

	}
	return nullEffectAffixes;
}

void EffectPQ::decreaseMonsterEffectLevel()
{
	if (monsterPQ.empty())
	{
		return;
	}

	std::priority_queue<EffectAffixes, std::vector<EffectAffixes>, std::greater<EffectAffixes>> temp;
	temp.swap(monsterPQ);
	while (temp.empty() == false)
	{
		EffectAffixes ea(temp.top());
		if (ea.level >= EffectAffixes::roundEffectLevel)
			ea.level -= EffectAffixes::roundEffectLevel;
		monsterPQ.push(ea);
		temp.pop();
	}
}

int EffectPQ::getMonsterEPQLevelMaxByRoundAndInterval(int relRound, EffectAffixes::EffectLevelInterval leftInterval, EffectAffixes::EffectLevelInterval rightInterval)
{
	if (relRound < 0)
	{
		cocos2d::log("[warning] 相对回合数 %d 指定有误，请检查！", relRound);
		return -1;
	}

	int levelMin = relRound * EffectAffixes::roundEffectLevel + leftInterval;
	int levelMax = relRound * EffectAffixes::roundEffectLevel + rightInterval - 1;
	int result = levelMin;
	int level;

	std::queue<EffectAffixes> temp;
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

void EffectPQ::popMonsterEffectAffixes()
{
	monsterPQ.pop();
}

void EffectPQ::popMonsterEffectAffixes(EffectAffixes::EffectLevelInterval leftInterval, EffectAffixes::EffectLevelInterval rightInterval)
{
	if (monsterPQ.empty())
	{
		return;
	}
	std::priority_queue <EffectAffixes, std::vector<EffectAffixes>, std::greater<EffectAffixes>> temp;
	bool flag = true;
	temp.swap(monsterPQ);
	while (!temp.empty())
	{
		EffectAffixes ea(temp.top());
		temp.pop();
		if (ea.level <= leftInterval && ea.level <= rightInterval && flag)
		{
			flag = false;
			continue;
		}
		monsterPQ.push(ea);
	}
}

void EffectPQ::popMonsterEffectAffixes(EffectAffixes effectAffixes)
{
	if (monsterPQ.empty())
	{
		return;
	}
	std::priority_queue <EffectAffixes, std::vector<EffectAffixes>, std::greater<EffectAffixes>> temp;
	temp.swap(monsterPQ);
	while (!temp.empty())
	{
		EffectAffixes ea(temp.top());
		temp.pop();
		if (ea == effectAffixes)
		{
			continue;
		}
		monsterPQ.push(ea);
	}
}
