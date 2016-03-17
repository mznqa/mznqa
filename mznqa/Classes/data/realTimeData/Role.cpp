#include "data/realTimeData/Role.h"

// c.h

// c++.h

// cocos2d
#include "cocos2d.h"

// 自定义的

Role* Role::Instance()
{
	static Role instance;

	return &instance;
}

Role::~Role()
{
}

std::string Role::getName()
{
	return this->roleName;
}

int Role::getBloodValue()
{
	return this->bloodValue;
}

void Role::setBloodValue(int bloodValue)
{

	this->bloodValue = bloodValue;
	if (bloodValue > this->bloodMax)
	{
		this->bloodValue = this->bloodMax;
	}
	else if (bloodValue < 0)
	{
		this->bloodValue = 0;
	}

}

void Role::updateBloodValue(int delta)
{
	this->bloodValue += delta;
	if (this->bloodValue > this->bloodMax)
	{
		this->bloodValue = this->bloodMax;
	}
	else if (this->bloodValue < 0)
	{
		this->bloodValue = 0;
	}
}

int Role::getArmorValue()
{
	return this->armorValue;
}

void Role::setArmorValue(int armorValue)
{
	this->armorValue = armorValue;
	/*if (this->armorValue > this->armorMax)
	{
		this->armorValue = this->armorMax;
	}*/
	if (this->armorValue < 0)
	{
		this->armorValue = 0;
	}
}

void Role::updateArmorValue(int delta)
{
	this->armorValue += delta;
	//if (this->armorValue > this->armorMax)
	//{
	//	this->armorValue = this->armorMax;
	//}
	if (this->armorValue < 0)
	{
		this->armorValue = 0;
	}
}

int Role::getBloodMax()
{
	return this->bloodMax;
}

void Role::setBloodMax(int bloodMax)
{
	this->bloodMax = bloodMax;
	if (this->bloodMax <= 0)
	{
		this->bloodMax = 1;
	}
}

void Role::updateBloodMax(int delta)
{
	this->bloodMax += delta;
	if (this->bloodMax <= 0)
	{
		this->bloodMax = 1;
	}
}

//int Role::getArmorMax()
//{
//	return this->armorMax;
//}
//
//void Role::setArmorMax(int armorMax)
//{
//	this->armorMax = armorMax;
//	if (this->armorMax <= 0)
//	{
//		this->armorMax = 1;
//	}
//}
//
//void Role::updateArmorMax(int delta)
//{
//	this->armorMax += delta;
//	if (this->armorMax <= 0)
//	{
//		this->armorMax = 1;
//	}
//}

int Role::getLevel()
{
	return this->level;
}

void Role::setLevel(int level)
{
	this->level = level;
	if (this->level > this->levelMax)
	{
		this->level = this->levelMax;
	}
	else if (this->level < 0)
	{
		this->level = 0;
	}
}

void Role::updateLevel(int delta)
{
	this->level += delta;
	if (this->level > this->levelMax)
	{
		this->level = this->levelMax;
	}
	else if (this->level < 0)
	{
		this->level = 0;
	}
}

int Role::getLevelMax()
{
	return this->levelMax;
}

void Role::setLevelMax(int levelMax)
{
	this->levelMax = levelMax;
	if (this->levelMax <= 0)
	{
		this->levelMax = 1;
	}
}

void Role::updateLevelMax(int delta)
{
	this->levelMax += delta;
	if (this->levelMax <= 0)
	{
		this->levelMax = 1;
	}
}

int Role::geExperience()
{
	return this->exprienceValue;
}

void Role::setExperience(int experience)
{
	this->exprienceValue = experience;
	if (this->exprienceValue < 0)
	{
		this->exprienceValue = 0;
	}
}

void Role::updateExperience(int delta)
{
	this->exprienceValue += delta;
	if (this->exprienceValue < 0)
	{
		this->exprienceValue = 0;
	}
	else if (this->exprienceValue >= this->experienceUpgrade[this->level-1])
	{
		this->exprienceValue -= this->experienceUpgrade[this->level - 1];
		this->level++;
	}
}

void Role::test()
{
	cocos2d::log("hello");
}