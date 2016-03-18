#pragma execution_character_set("utf-8")

#include "data/realTimeData/Monster.h"

Monster::Monster()
{
}

Monster::~Monster()
{
}

std::string Monster::getName()
{
	return this->monsterName;
}

int Monster::getBloodValue()
{
	return this->bloodValue;
}

void Monster::setBloodValue(int bloodValue)
{
	this->bloodValue = bloodValue;
	if (this->bloodValue > this->bloodMax)
	{
		this->bloodValue = this->bloodMax;
	}
	else if (this->bloodValue < 0)
	{
		this->bloodValue = 0;
	}
}

void Monster::updateBloodValue(int delta)
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

int Monster::getArrmorValue()
{
	return this->armorValue;
}

void Monster::setArrmorValue(int arrmorValue)
{
	this->armorValue = armorValue;
	if (this->armorValue < 0)
	{
		this->armorValue = 0;
	}
}

void Monster::updateArrmorValue(int delta)
{
	this->armorValue += delta;
	if (this->armorValue < 0)
	{
		this->armorValue = 0;
	}
}

int Monster::getExperienceValue()
{
	return this->experienceValue;
}

void Monster::setExperienceValue(int experienceValue)
{
	this->experienceValue = experienceValue;
	if (this->experienceValue < 0)
	{
		this->experienceValue = 0;
	}
}

int Monster::getBloodMax()
{
	return this->bloodMax;
}

void Monster::setBloodMax(int bloodMax)
{
	this->bloodMax = bloodMax;
	if (this->bloodMax <= 0)
	{
		this->bloodMax = 1;
	}
}

void Monster::updateBloodMax(int delta)
{
	this->bloodMax += delta;
	if (this->bloodMax <= 0)
	{
		this->bloodMax = 1;
	}
}