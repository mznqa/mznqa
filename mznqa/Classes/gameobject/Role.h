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
	// 基础血量上限
	int baseBloodValueMax;
	// 基础护甲上限
	int baseArmorValueMax;
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
	// 血量上限附加值
	int additionalBloodlValueMax;
	// 护甲上限附加值
	int additionalArmorValueMax;
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

	// 获取基础血量上限
	int getBaseBloodValueMax()const
	{
		return baseBloodValueMax;
	}

	// 获取基础护甲上限
	int getBaseArmorValueMax()const
	{
		return baseArmorValueMax;
	}

	// 获取当前血量上限
	int getBloodValueMax()const
	{
		return baseBloodValueMax + additionalBloodlValueMax;
	}

	// 获取当前护甲上限
	int getArmorValueMax()const
	{
		return baseArmorValueMax + additionalArmorValueMax;
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
		if (0 <= bloodValue && bloodValue <= getBloodValueMax())
			this->bloodValue = bloodValue;
		else
		{
			cocos2d::log("[warning] 尝试为角色设置越界血量");
		}
	}
	// 更新血量
	void updateBloodValue(int delta)
	{
		int temp = bloodValue + delta;
		if (0 <= bloodValue && bloodValue <= getBloodValueMax())
			bloodValue = temp;
		else
		{
			cocos2d::log("[waring] 尝试更改血量以至血量越界");
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
		if (0 <= armorValue && armorValue <= getArmorValueMax())
			this->armorValue = armorValue;
		else
			cocos2d::log("[warning] 尝试为角色设置越界护甲");
	}
	// 更新护甲
	void updateArmorValue(int delta)
	{
		int temp = armorValue + delta;
		if (0 <= armorValue && armorValue <= getArmorValueMax())
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

	// 获取附加的血量上限值
	int getAdditionalBloodlValueMax()const
	{
		return additionalBloodlValueMax;
	}
	// 设置附加的血量上限值值
	void setAdditionalBloodValueMax(int additionalBloodValueMax)
	{
		if (baseBloodValueMax + additionalBloodlValueMax >= 0)
			this->additionalBloodlValueMax = additionalBloodValueMax;
		else
		{
			cocos2d::log("[warning] 尝试设置附加的血量上限为%d，这将会导致实际血量上限为不合法的值", additionalBloodValueMax);
		}
	}
	// 更新附加的血量上限
	void updateAdditionalBloodValueMax(int delta)
	{
		if (baseBloodValueMax + additionalBloodlValueMax + delta >= 0)
			this->additionalBloodlValueMax += delta;
		else
		{
			cocos2d::log("[warning] 尝试设置附加的血量上限为%d，这将会导致实际血量上限为不合法的值", additionalBloodlValueMax + delta);
		}
	}

	// 获取附加的护甲上限
	int getAdditionalArmorValueMax()const
	{
		return additionalArmorValueMax;
	}
	// 设置附加的护甲上限
	void setAdditionalAromrValueMax(int additionalArmorValueMax)
	{
		if (baseArmorValueMax + additionalArmorValueMax >= 0)
			this->additionalArmorValueMax = additionalArmorValueMax;
		else
		{
			cocos2d::log("[warning] 尝试设置附加的护甲上限为%d，这将会导致实际的护甲上限为不合法的值", additionalArmorValueMax);
		}
	}
	// 更新附加的花甲上限
	void updateAdditionalArmorValueMax(int delta)
	{
		if (baseArmorValueMax + additionalArmorValueMax + delta >= 0)
			this->additionalArmorValueMax += delta;
		else
		{
			cocos2d::log("[warning] 尝试设置附加的护甲上限为%d，这将会导致实际的护甲上限为合法的值", additionalArmorValueMax + delta);
		}
	}

	void test();
};

#endif
