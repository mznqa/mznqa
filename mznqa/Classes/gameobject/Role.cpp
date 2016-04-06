/*!
 * \file	Classes\gameobject\Role.cpp
 *
 * \brief	定义类 Role
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
	// 当等级值正常且未达到等级上限，即还可以升级
	if (1 <= levelValue  && levelValue < levelValueMax)
	{
		// 当经验达到升级要求的经验值
		if (exprienceValue >= experienceTable[levelValue - 1])
		{
			// 扣去经验值
			exprienceValue -= experienceTable[levelValue - 1];
			updateLevelValue(1);
			// TODO 发送升级消息
			cocos2d::log("[information] 角色升级，当前等级：%d", levelValue);
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
		// 根据当前经验判断还可以升级几次，就进行几次升级判断
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
		// 根据当前经验判断还可以升级几次，就进行几次升级判断
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