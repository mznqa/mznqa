#pragma execution_character_set("utf-8")

#include "data/realTimeData/Role.h"

#include "cocos2d.h"

Role::Role()
{
}

Role* Role::Instance()
{
	static Role instance;

	return &instance;
}

Role::~Role()
{
	delete experienceUpgrade;
	experienceUpgrade = nullptr;
}

void Role::makeRole(int curLevel, int curExprience, int levelMax, int *experienceUpgrade)
{
	// do something

	setLevelMaxAndExperienceUpgrade(levelMax, experienceUpgrade);

	setLevel(curLevel);

	setExperience(curExprience);
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
	if (this->armorValue < 0)
	{
		this->armorValue = 0;
	}
}

void Role::updateArmorValue(int delta)
{
	this->armorValue += delta;
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
	else if (this->level < 1)
	{
		this->level = 1;
	}

	if (level >= levelMax)
	{
		exprienceValue = 0;
		return;
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

	if (level >= levelMax)
	{
		exprienceValue = 0;
		return;
	}
}

void Role::checkLevel()
{
	// ���ȼ�ֵ������δ�ﵽ�ȼ����ޣ�������������
	if (1 <= level  && level < levelMax)
	{
		// ������ﵽ����Ҫ��ľ���ֵ
		if (exprienceValue >= experienceUpgrade[level - 1])
		{
			// ��ȥ����ֵ
			exprienceValue -= experienceUpgrade[level - 1];
			updateLevel(1);
			// TODO ����������Ϣ
			cocos2d::log(">>>>>>>>>>>>>>>> ��ɫ�����ˣ�����");
		}
	}
}

int Role::getLevelMax()
{
	return this->levelMax;
}

//void Role::setLevelMax(int levelMax)
//{
//	this->levelMax = levelMax;
//	if (this->levelMax <= 0)
//	{
//		this->levelMax = 1;
//	}
//}

//void Role::updateLevelMax(int delta)
//{
//	this->levelMax += delta;
//	if (this->levelMax <= 0)
//	{
//		this->levelMax = 1;
//	}
//}

int Role::getExperience()
{
	return this->exprienceValue;
}

void Role::setExperience(int experience)
{
	if (level >= levelMax)
	{
		this->exprienceValue = 0;
		return;
	}
	this->exprienceValue = experience;
	if (this->exprienceValue < 0)
	{
		this->exprienceValue = 0;
	}
	else
	{
		// ���ݵ�ǰ�����жϻ������������Σ��ͽ��м��������ж�
		for (int i = level + 1; i <= levelMax; ++i)
			checkLevel();
	}
}

void Role::updateExperience(int delta)
{
	if (level >= levelMax)
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
		for (int i = level + 1; i <= levelMax; ++i)
			checkLevel();
	}
}

void Role::setLevelMaxAndExperienceUpgrade(int levelMax, int *experienceUpgrade)
{
	this->levelMax = levelMax;
	this->experienceUpgrade = new int[this->levelMax - 1];
	for (int i = 0; i < this->levelMax; ++i)
		this->experienceUpgrade[i] = experienceUpgrade[i];
}

void Role::test()
{
	//int eu[3] = { 50, 200, 400 };
	//makeRole(1, 0, 4, eu);

	//for (int i = 0; i < 100; ++i)
	//{
	//	cocos2d::log("%d) ��ɫ��", i);
	//	cocos2d::log("\t�ȼ���%d", getLevel());
	//	cocos2d::log("\t���飺%d", getExperience());
	//	cocos2d::log("\t�ȼ����ֵ��%d", getLevelMax());
	//	if (i == 0)
	//		cocos2d::log("\t�������飺%d,%d,%d", experienceUpgrade[0], experienceUpgrade[1], experienceUpgrade[2]);

	//	updateExperience(10);
	//}
}