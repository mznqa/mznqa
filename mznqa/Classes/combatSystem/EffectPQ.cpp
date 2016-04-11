#pragma execution_character_set("utf-8")

#include "combatSystem/EffectPQ.h"

#include "cocos2d.h"

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
		cocos2d::log("[information] ��ɫЧ������Ϊ�գ�������һ����Ч��Ч���������ԣ�");
		return EffectAffixes(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	}

	std::priority_queue <EffectAffixes, std::vector<EffectAffixes>, std::greater<EffectAffixes>> temp = rolePQ;
	if ((leftInterval <= temp.top().level) && (temp.top().level <=rightInterval))
	{
		EffectAffixes effectAffixes = temp.top();
		cocos2d::log("[information] �ɹ���ȡһ����ɫЧ���������ԣ�");
		return effectAffixes;
	}
	else
	{
		temp.pop();
	}

	cocos2d::log("[information] ��ָ������ %d ~ %d �ڣ�û���ҵ���ɫЧ���������ԣ�������һ����Ч��Ч���������ԣ�", leftInterval,rightInterval);
	return EffectAffixes(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);


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
		cocos2d::log("[warning] ��Իغ��� %d ָ���������飡", relRound);
		return -1;
	}

	int levelMin = relRound * EffectAffixes::roundEffectLevel + leftInterval;
	int levelMax = (relRound + 1) * EffectAffixes::roundEffectLevel + rightInterval - 1;
	int result = leftInterval - 1;
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
		cocos2d::log("[information] ����Ч������Ϊ�գ�������һ����Ч��Ч���������ԣ�");
		return EffectAffixes(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
	}
	
	std::priority_queue <EffectAffixes, std::vector<EffectAffixes>, std::greater<EffectAffixes>> temp = monsterPQ;
	if ((leftInterval <= temp.top().level) && (temp.top().level <= rightInterval))
	{
		EffectAffixes effectAffixes = temp.top();
		cocos2d::log("[information] �ɹ���ȡһ������Ч���������ԣ�");
		return effectAffixes;
	}
	else
	{
		temp.pop();
	}

	cocos2d::log("[information] ��ָ������ %d ~ %d �ڣ�û���ҵ�����Ч���������ԣ�������һ����Ч��Ч���������ԣ�", leftInterval, rightInterval);
	return EffectAffixes(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue);
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
		cocos2d::log("[warning] ��Իغ��� %d ָ���������飡", relRound);
		return -1;
	}

	int levelMin = relRound * EffectAffixes::roundEffectLevel + leftInterval;
	int levelMax = (relRound + 1) * EffectAffixes::roundEffectLevel + rightInterval - 1;
	int result = leftInterval - 1;
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
