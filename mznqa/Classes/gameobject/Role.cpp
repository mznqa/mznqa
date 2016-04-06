/*!
 * \file	Classes\gameobject\Role.cpp
 *
 * \brief	������ Role
 */

#pragma execution_character_set("utf-8")

#include "gameobject/Role.h"

Role* Role::Instance()
{
	static Role instance;
	return &instance;
}

Role::~Role()
{
}

void Role::checkLevelValue()
{
	// ���ȼ�ֵ������δ�ﵽ�ȼ����ޣ�������������
	if (1 <= levelValue  && levelValue < levelValueMax)
	{
		// ������ﵽ����Ҫ��ľ���ֵ
		if (exprienceValue >= experienceTable[levelValue - 1])
		{
			// ��ȥ����ֵ
			exprienceValue -= experienceTable[levelValue - 1];
			updateLevelValue(1);
			// TODO ����������Ϣ
			cocos2d::log("[information] ��ɫ��������ǰ�ȼ���%d", levelValue);
		}
	}
}

void Role::setExprienceValue(int exprienceValue)
{
	if (levelValue >= levelValueMax)
	{
		this->exprienceValue = 0;
		return;
	}
	this->exprienceValue = exprienceValue;
	if (this->exprienceValue < 0)
	{
		this->exprienceValue = 0;
	}
	else
	{
		// ���ݵ�ǰ�����жϻ������������Σ��ͽ��м��������ж�
		for (int i = levelValue + 1; i <= levelValueMax; ++i)
			checkLevelValue();
	}
}

void Role::updateExprienceValue(int delta)
{
	if (levelValue >= levelValueMax)
	{
		this->exprienceValue = 0;
		return;
	}
	this->exprienceValue += delta;
	if (this->exprienceValue < 0)
	{
		this->exprienceValue = 0;
	}
	else
	{
		// ���ݵ�ǰ�����жϻ������������Σ��ͽ��м��������ж�
		for (int i = levelValue + 1; i <= levelValueMax; ++i)
			checkLevelValue();
	}
}

void Role::test()
{
	bloodValue = 8;
	baseBloodValueMax = 9;
	armorValue = 10;
	baseArmorValueMax = 11;
	levelValue = 1;
	levelValueMax = 10;
	exprienceValue = 20;
	experienceTable.push_back(10);
	experienceTable.push_back(10);
	experienceTable.push_back(10);
	experienceTable.push_back(10);
	experienceTable.push_back(10);
	experienceTable.push_back(10);
	experienceTable.push_back(10);
	experienceTable.push_back(10);
	experienceTable.push_back(10);
	for (int i = 0; i < 100; ++i)
	{
		updateExprienceValue(1);
		cocos2d::log("[information] %d,%d,%d,%d", bloodValue, armorValue, levelValue, exprienceValue);
	}
}