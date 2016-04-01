#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_GAMEOBJECT_MONSTER_H_
#define MZNQA_CLASSES_GAMEOBJECT_MONSTER_H_

#include <string>

#include "cocos2d.h"

#include "cardController/CardControllerCombat.h"

class Monster
{
private:
	// 静态量 //////////////////////////////////////////////////////////////////////////
	// 名称
	std::string name;
	// 描述
	std::string describe;
	// 血量上限
	int baseBloodValueMax;
	// 护甲上限
	int baseArmorValueMax;
	//////////////////////////////////////////////////////////////////////////

	// 实时量 //////////////////////////////////////////////////////////////////////////
	// 血量
	int bloodValue;
	// 护甲
	int armorValue;
	// 附加的血量上限值
	int additionalBloodValueMax;
	// 附加的护甲上限值
	int additionalArmorValueMax;
	//////////////////////////////////////////////////////////////////////////
public:
	Monster();
	~Monster();

	// 开牌管理器 //////////////////////////////////////////////////////////////////////////
	// 战斗场景下的卡牌管理器
	CardControllerCombat cardControllerCombat;
	//////////////////////////////////////////////////////////////////////////

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
		return baseBloodValueMax + additionalBloodValueMax;
	}

	// 获取当前护甲上限
	int getArmorValueMax()const
	{
		return baseArmorValueMax + additionalArmorValueMax;
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
			cocos2d::log("[warning] 尝试为怪物设置越界血量");
		}
	}
	// 更新血量
	void updateBloodValue(int delta)
	{
		int temp = bloodValue + delta;
		if (0 <= temp && temp <= getBloodValueMax())
			this->bloodValue = temp;
		else
		{
			cocos2d::log("[warning] 尝试更新怪物血量，以至血量越界，变化量为%d, 而当前血量为", delta, bloodValue);
		}
	}

	// 获取护甲值
	int getArmorValue()const
	{
		return armorValue;
	}
	// 设置护甲值
	void setArmorValue(int armorValue)
	{
		if (0 <= armorValue && armorValue <= getArmorValue())
			this->armorValue = armorValue;
		else
		{
			cocos2d::log("[warning] 尝试为怪物设置越界血量");
		}
	}
	// 更新护甲值
	void updateArmorValue(int delta)
	{
		int temp = armorValue + delta;
		if (0 <= temp && temp <= getArmorValue())
			this->armorValue = temp;
		else
		{
			cocos2d::log("[warning] 尝试更新怪物的护甲，以至护甲越界，变化量为%d，而当前护甲为%d", delta, armorValue);
		}
	}

	// 获取附加的血量上限值
	int getAdditionalBloodValueMax()const
	{
		return additionalBloodValueMax;
	}
	// 设置附加的血量上限值
	void getAdditionalBloodValueMax(int additionalBloodValueMax)
	{
		if (baseBloodValueMax + additionalBloodValueMax >= 0)
			this->additionalBloodValueMax = additionalBloodValueMax;
		else
		{
			cocos2d::log("[warning] 尝试为怪物设置附加血量上限失败，将导致血量上限不合法");
		}
	}
	// 更新附加的血量上限值
	void updateAdditionalBloodValueMax(int delta)
	{
		if (baseBloodValueMax + additionalBloodValueMax + delta >= 0)
			this->additionalBloodValueMax += delta;
		else
		{
			cocos2d::log("[warning] 尝试更新怪物的附加血量上限失败，将导致血量上限不合法");
		}
	}

	// 获取附加的护甲上限
	int getAdditionalArmorValueMax()const
	{
		return additionalBloodValueMax;
	}
	// 设置附加的护甲上限
	void getAdditionArmorValueMax(int additionalArmorValueMax)
	{
		if (baseArmorValueMax + additionalArmorValueMax >= 0)
			this->additionalArmorValueMax = additionalArmorValueMax;
		else
		{
			cocos2d::log("[warning] 尝试为怪物设置附加的护甲上限失败，将导致护甲上限不合法");
		}
	}
	// 更新附加的护甲上限
	void updateAdditionalArmorValueMax(int delta)
	{
		if (baseArmorValueMax + additionalArmorValueMax + delta >= 0)
			this->additionalArmorValueMax += delta;
		else
		{
			cocos2d::log("[warning] 尝试更新怪物的附加护甲上限失败，将导致护甲上限不合法");
		}
	}
};

#endif
