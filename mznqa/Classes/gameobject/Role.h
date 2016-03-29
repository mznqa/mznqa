#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_GAMEOBJECT_ROLE_H_
#define MZNQA_CLASSES_GAMEOBJECT_ROLE_H_

#include <string>
#include <vector>

#include "cocos2d.h"

class Role
{
private:
	Role(){}
	Role(const Role &role);
	Role& operator=(const Role &role);

	// 静态量 //////////////////////////////////////////////////////////////////////////
	// 名称
	std::string name;
	// 描述
	std::string describe;
	// 血量上限
	int bloodValueMax;
	// 护甲上限
	int armorValueMax;
	// 等级上限
	int levelValueMax;
	// 升级经验表
	std::vector<int> experienceTable;
	//////////////////////////////////////////////////////////////////////////

	// 实时量 //////////////////////////////////////////////////////////////////////////
	// 血量
	int bloodValue;
	// 护甲
	int armorValue;
	// 级数
	int levelValue;
	// 经验
	int exprienceValue;
	//////////////////////////////////////////////////////////////////////////

	// 检查等级
	void checkLevelValue()
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

public:
	static Role* Instance();
	~Role();

	// 获取名称
	const std::string& getName()const
	{
		return name;
	}

	// 获取描述
	const std::string& getDescribe()const
	{
		return describe;
	}

	// 获取血量上限
	int getBloodValueMax()const
	{
		return bloodValueMax;
	}

	// 获取护甲上限
	int getArmorValueMax()const
	{
		return armorValueMax;
	}

	// 获取等级上限
	int getLevelValueMax()const
	{
		return levelValueMax;
	}

	// 获取升至下一级所需经验，当角色满级将返回-1
	int getNextLevelExprience()const
	{
		if (1 <= levelValue && levelValue < levelValueMax)
			return experienceTable[levelValue - 2];
		else
			return -1;
	}

	// 获取升级经验表
	const std::vector<int>& getExprienceTable()const
	{
		return experienceTable;
	}

	// 获取血量
	int getBloodValue()const
	{
		return bloodValue;
	}
	// 设置血量
	void setBloodValue(int bloodValue)
	{
		if (0 <= bloodValue && bloodValue <= bloodValueMax)
			this->bloodValue = bloodValue;
		else
		{
			cocos2d::log("[warning] 尝试为角色设置越界血量");
			bloodValue = 0;
		}
	}
	// 更新血量
	void updateBloodValue(int delta)
	{
		int temp = bloodValue + delta;
		if (0 <= bloodValue && bloodValue <= bloodValueMax)
			bloodValue = temp;
		else
		{
			cocos2d::log("[waring] 尝试更改血量以至血量越界");
			bloodValue = 0;
		}
	}

	// 获取护甲
	int getArmorValue()const
	{
		return armorValue;
	}
	// 设置护甲
	void setArmorValue(int armorValue)
	{
		if (0 <= armorValue && armorValue <= armorValueMax)
			this->armorValue = armorValue;
		else
			cocos2d::log("[warning] 尝试为角色设置越界护甲");
	}
	// 更新护甲
	void updateArmorValue(int delta)
	{
		int temp = armorValue + delta;
		if (0 <= armorValue && armorValue <= armorValueMax)
			armorValue = temp;
		else
			cocos2d::log("[waring] 尝试更改护甲以至护甲越界");
	}

	// 获取当前等级
	int getLevleValue()const
	{
		return levelValue;
	}
	// 设置经验值
	void setLevelValue(int levelValue)
	{
		if (1 <= levelValue && levelValue <= levelValueMax)
			this->levelValue = levelValueMax;
		else
			cocos2d::log("[warning] 尝试为角色设置越界等级");
	}
	// 更新经验值
	void updateLevelValue(int delta)
	{
		int temp = this->levelValue + delta;
		if (1 <= temp && temp <= levelValueMax)
			this->levelValue = temp;
		else
			cocos2d::log("[warning] 尝试为角色设置越界等级");
	}

	// 获取经验值
	int getExprienceValue()const
	{
		return exprienceValue;
	}
	// 设置经验值
	void setExprienceValue(int exprienceValue)
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
	// 更新经验值
	void updateExprienceValue(int delta)
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

	void test();
};

#endif
