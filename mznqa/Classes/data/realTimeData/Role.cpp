#include "data/realTimeData/Role.h"

Role* Role::Instance()
{
	static Role instance;

	return &instance;
}

Role::~Role()
{
}

int Role::getBloodValue()
{
	return this->bloodValue;
}

void Role::setBloodValue(int bloodValue)
{
	this->bloodValue = bloodValue;
}

void Role::updateBloodValue(int delta)
{
	this->bloodValue += delta;
}

int Role::getArmorValue()
{
	return this->armorValue;
}

void Role::setArmorValue(int armorValue)
{
	this->armorValue += armorValue;
}

void Role::updateArmorValue(int delta)
{
	this->armorValue += delta;
}

int Role::getBloodMax()
{
	return this->bloodMax;
}

void Role::setBloodMax(int bloodMax)
{
	this->bloodMax = bloodMax;
}

void Role::updateBloodMax(int delta)
{
	this->bloodMax += delta;
}

int Role::getArmorMax()
{
	return this->armorMax;
}

void Role::setArmorMax(int armorMax)
{
	this->armorMax = armorMax;
}

void Role::updateArmorMax(int delta)
{
	this->armorMax += delta;
}

void Role::test()
{
}