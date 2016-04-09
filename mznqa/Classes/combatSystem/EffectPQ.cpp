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
	{
		cocos2d::log("[warning] ��ɫЧ������Ϊ�գ��ṹ���Աȫ������-1��");
		return EffectEntity(-1, -1, -1);
	}

	EffectEntity effect = rolePQ.top();
	//�ж���һ��Ч���Ƿ����
	if (effect.level / 100 == 0)
	{
		rolePQ.pop();
		cocos2d::log("[information] �ɹ���ȡ��һ�����õĽ�ɫ���ܣ�");
		return effect;
	}
	else if (effect.level / 100 == 1)
	{
		cocos2d::log("[warning] �ɹ���ȡ��һ�����õĽ�ɫ���ܣ������ڽ�ɫ������ִ�У�");
		return effect;
	}
	cocos2d::log("[warning] ����һ�����õĽ�ɫЧ�����ṹ���Աȫ������-1��");
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

	std::priority_queue<EffectEntity, std::vector<EffectEntity>, std::greater<EffectEntity>> temp;
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
		cocos2d::log("[error] ��Իغ��� %d ָ�����󣬽�����-1��", relRound);
		return -1;
	}

	int levelMin = relRound * 100;
	int levelMax = (relRound + 1) * 100 - 1;
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
	{
		cocos2d::log("[warning] ����Ч������Ϊ�գ��ṹ���Աȫ������-1��");
	}
		return EffectEntity(-1, -1, -1);

	EffectEntity effect = monsterPQ.top();
	if (effect.level / 100 == 0)
	{
		monsterPQ.pop();
		cocos2d::log("[information] �ɹ���ȡ��һ�����õĹ���Ч����");
		return effect;
	}else if (effect.level / 100 == 1)
	{
		cocos2d::log("warning] �ɹ���ȡ��һ�����õĹ���Ч�����������ڹ��������ִ�У�");
		return effect;
	}
	cocos2d::log("[warning] ����һ�����õĹ���Ч�����ṹ���Աȫ������-1��");

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

	std::priority_queue<EffectEntity, std::vector<EffectEntity>, std::greater<EffectEntity>> temp;
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

	int levelMin = relRound * 100;
	int levelMax = (relRound + 1) * 100 - 1;
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
