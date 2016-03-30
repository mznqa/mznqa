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