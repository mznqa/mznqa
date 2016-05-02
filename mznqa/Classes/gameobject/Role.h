/*!
 * \file	Classes\gameobject\Role.h
 *
 * \brief	定义类 Role
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_GAMEOBJECT_ROLE_H_
#define MZNQA_CLASSES_GAMEOBJECT_ROLE_H_

#include <string>
#include <vector>

#include "cocos2d.h"

#include "cardController/CardControllerCombat.h"

/*!
 * \class	Role
 *
 * \brief	单例。角色
 *
 */
class Role
{
private:

	/*!
	 * \fn	Role::Role()
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	Role(){}

	/*!
	 * \fn	Role::Role(const Role &role);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 * \param	role	Role 实例
	 */
	Role(const Role &role);

	/*!
	 * \fn	Role& Role::operator=(const Role &role);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 * \param	role	Role 实例
	 *
	 * \return	Role 实例
	 */
	Role& operator=(const Role &role);

	/*! \brief	角色的名称 */
	std::string name;
	/*! \brief	角色的描述 */
	std::string describe;
	/*! \brief	角色的基础血量上限 */
	int baseBloodValueMax;
	/*! \brief	角色的基础护甲上限 */
	int baseArmorValueMax;
	/*! \brief	角色的等级上限 */
	int levelValueMax;
	/*! \brief	角色升级经验表 */
	std::vector<int> experienceTable;

	/*! \brief	角色血量实时量 */
	int bloodValue;
	/*! \brief	角色护甲实时量 */
	int armorValue;
	/*! \brief	角色等级实时量 */
	int levelValue;
	/*! \brief	角色经验实时量 */
	int exprienceValue;
	/*! \brief	角色血量附加上限实时量 */
	int additionalBloodlValueMax;
	/*! \brief	角色护甲附加上限实时量 */
	int additionalArmorValueMax;
	/* \brief	角色实时手牌数 */
	int handCardCount;
	/* \brief	角色每回合内可抽牌数 */
	int drawCardCount;
	/* \brief	角色每回合内可出牌数 */
	int discardCount;
	/* \brief	角色每回合内可抽牌数上限 */
	int handCardCountMax;
	/*!
	 * \fn	void Role::checkLevelValue()
	 *
	 * \brief	根据当前的经验值更新级数
	 *
	 */
	void checkLevelValue();

public:

	/*!
	 * \fn	static Role* Role::Instance();
	 *
	 * \brief	获取单例
	 *
	 * \return	返回单例
	 */
	static Role* Instance();

	/*!
	 * \fn	Role::~Role();
	 *
	 * \brief	析构函数
	 *
	 */
	~Role();

	/*! \brief	战斗场景下的卡牌控制器 */
	CardControllerCombat cardControllerCombat;

	/*!
	 * \fn	const std::string& Role::getName()const
	 *
	 * \brief	获取角色名称
	 *
	 * \return	返回角色名称
	 */
	const std::string& getName()const
	{
		return name;
	}

	/*!
	 * \fn	const std::string& Role::getDescribe()const
	 *
	 * \brief	获取角色描述
	 *
	 * \return	返回角色描述
	 */
	const std::string& getDescribe()const
	{
		return describe;
	}

	/*!
	 * \fn	int Role::getBaseBloodValueMax()const
	 *
	 * \brief	获取角色基础血量上限
	 *
	 * \return	返回角色基础血量上限
	 */
	int getBaseBloodValueMax()const
	{
		return baseBloodValueMax;
	}

	/*!
	 * \fn	int Role::getBaseArmorValueMax()const
	 *
	 * \brief	获取角色基础护甲上限
	 *
	 * \return	返回角色基础护甲上限
	 */
	int getBaseArmorValueMax()const
	{
		return baseArmorValueMax;
	}

	/*!
	 * \fn	int Role::getBloodValueMax()const
	 *
	 * \brief	获取角色当前血量上限
	 *
	 * \return	返回角色当前血量上限
	 */
	int getBloodValueMax()const
	{
		return baseBloodValueMax + additionalBloodlValueMax;
	}

	/*!
	 * \fn	int Role::getArmorValueMax()const
	 *
	 * \brief	获取角色当前护甲上限
	 *
	 * \return	返回角色当前护甲上限
	 */
	int getArmorValueMax()const
	{
		return baseArmorValueMax + additionalArmorValueMax;
	}

	/*!
	 * \fn	int Role::getLevelValueMax()const
	 *
	 * \brief	获取角色等级上限
	 *
	 * \return	返回角色等级上限
	 */
	int getLevelValueMax()const
	{
		return levelValueMax;
	}

	/*!
	 * \fn	int Role::getNextLevelExprience()const
	 *
	 * \brief	获取角色升到下一级所需的经验
	 *
	 * \return	返回角色升到下一级所需的经验，若角色已达到等级上限则返回-1
	 */
	int getNextLevelExprience()const
	{
		if (1 <= levelValue && levelValue < levelValueMax)
			return experienceTable[levelValue - 2];
		else
			return -1;
	}

	/*!
	 * \fn	const std::vector<int>& Role::getExprienceTable()const
	 *
	 * \brief	获取角色升级经验表
	 *
	 * \return	返回角色升级经验表
	 */
	const std::vector<int>& getExprienceTable()const
	{
		return experienceTable;
	}

	/*!
	 * \fn	int Role::getBloodValue()const
	 *
	 * \brief	获取角色当前血量
	 *
	 * \return	返回角色当前血量
	 */
	int getBloodValue()const
	{
		return bloodValue;
	}

	/*!
	 * \fn	void Role::setBloodValue(int bloodValue)
	 *
	 * \brief	根据给定值为角色设置血量
	 *
	 * \param	bloodValue	指定将为角色的血量值
	 */
	void setBloodValue(int bloodValue)
	{
		if (0 <= bloodValue && bloodValue <= getBloodValueMax())
			this->bloodValue = bloodValue;
		else
		{
			cocos2d::log("[warning] 尝试为角色设置越界血量");
		}
	}

	/*!
	 * \fn	void Role::updateBloodValue(int delta)
	 *
	 * \brief	根据给定增减量更新角色血量
	 *
	 * \param	delta	指定将用于更新血量的增减量
	 */
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

	/*!
	 * \fn	int Role::getArmorValue()const
	 *
	 * \brief	获取角色当前护甲
	 *
	 * \return	返回角色当前护甲
	 */
	int getArmorValue()const
	{
		return armorValue;
	}

	/*!
	 * \fn	void Role::setArmorValue(int armorValue)
	 *
	 * \brief	根据指定值设置角色护甲
	 *
	 * \param	armorValue	指定用于设置角色护甲的值
	 */
	void setArmorValue(int armorValue)
	{
		if (0 <= armorValue && armorValue <= getArmorValueMax())
			this->armorValue = armorValue;
		else
			cocos2d::log("[warning] 尝试为角色设置越界护甲");
	}

	/*!
	 * \fn	void Role::updateArmorValue(int delta)
	 *
	 * \brief	根据给定增减量来更新角色护甲
	 *
	 * \param	delta	指定将用于更新护甲的增减量
	 */
	void updateArmorValue(int delta)
	{
		int temp = armorValue + delta;
		if (0 <= armorValue && armorValue <= getArmorValueMax())
			armorValue = temp;
		else
			cocos2d::log("[waring] 尝试更改护甲以至护甲越界");
	}

	/*!
	 * \fn	int Role::getLevleValue()const
	 *
	 * \brief	获取角色当前等级
	 *
	 * \return	返回角色当前等级
	 */
	int getLevleValue()const
	{
		return levelValue;
	}

	/*!
	 * \fn	void Role::setLevelValue(int levelValue)
	 *
	 * \brief	根据给定值来设置角色当前等级
	 *
	 * \param	levelValue	指定用于设置等级的量
	 */
	void setLevelValue(int levelValue)
	{
		if (1 <= levelValue && levelValue <= levelValueMax)
			this->levelValue = levelValueMax;
		else
			cocos2d::log("[warning] 尝试为角色设置越界等级");
	}

	/*!
	 * \fn	void Role::updateLevelValue(int delta)
	 *
	 * \brief	根据给定增减量来更新角色的等级
	 *
	 * \param	delta	指定用于更新等级的增减量
	 */
	void updateLevelValue(int delta)
	{
		int temp = this->levelValue + delta;
		if (1 <= temp && temp <= levelValueMax)
			this->levelValue = temp;
		else
			cocos2d::log("[warning] 尝试为角色设置越界等级");
	}

	/*!
	 * \fn	int Role::getExprienceValue()const
	 *
	 * \brief	获取角色经验
	 *
	 * \return	返回角色经验
	 */
	int getExprienceValue()const
	{
		return exprienceValue;
	}

	/*!
	 * \fn	void Role::setExprienceValue(int exprienceValue)
	 *
	 * \brief	根据给定值来设置角色当前的经验
	 *
	 * \param	exprienceValue	指定用于设置角色经验的值
	 */
	void setExprienceValue(int exprienceValue);

	/*!
	 * \fn	void Role::updateExprienceValue(int delta)
	 *
	 * \brief	根据给定的增减量来更新角色的
	 *
	 * \author	Yeshiyong
	 * \date	2016/4/6
	 *
	 * \param	delta	The delta.
	 */
	void updateExprienceValue(int delta);

	/*!
	 * \fn	int Role::getAdditionalBloodlValueMax()const
	 *
	 * \brief	获取角色的附加血量上限
	 *
	 * \return	返回角色的附加血量上限
	 */
	int getAdditionalBloodlValueMax()const
	{
		return additionalBloodlValueMax;
	}

	/*!
	 * \fn	void Role::setAdditionalBloodValueMax(int additionalBloodValueMax)
	 *
	 * \brief	根据给定值来设置角色的附加血量上限
	 *
	 * \param	additionalBloodValueMax	指定用于设置角色附加血量上限的值
	 */
	void setAdditionalBloodValueMax(int additionalBloodValueMax)
	{
		if (baseBloodValueMax + additionalBloodlValueMax >= 0)
			this->additionalBloodlValueMax = additionalBloodValueMax;
		else
		{
			cocos2d::log("[warning] 尝试设置附加的血量上限为%d，这将会导致实际血量上限为不合法的值", additionalBloodValueMax);
		}
	}

	/*!
	 * \fn	void Role::updateAdditionalBloodValueMax(int delta)
	 *
	 * \brief	根据给定增减量来更新角色的附加血量上限
	 *
	 * \param	delta	指定将用于更新角色的附加血量上限的增减量
	 */
	void updateAdditionalBloodValueMax(int delta)
	{
		if (baseBloodValueMax + additionalBloodlValueMax + delta >= 0)
			this->additionalBloodlValueMax += delta;
		else
		{
			cocos2d::log("[warning] 尝试设置附加的血量上限为%d，这将会导致实际血量上限为不合法的值", additionalBloodlValueMax + delta);
		}
	}

	/*!
	 * \fn	int Role::getAdditionalArmorValueMax()const
	 *
	 * \brief	获取角色附加的护甲上限
	 *
	 * \return	返回角色附加的护甲上限
	 */
	int getAdditionalArmorValueMax()const
	{
		return additionalArmorValueMax;
	}

	/*!
	 * \fn	void Role::setAdditionalAromrValueMax(int additionalArmorValueMax)
	 *
	 * \brief	根据给定的值来设置角色的附加护甲上限
	 *
	 * \param	additionalArmorValueMax	指定将用于设置角色的附加护甲上限的值
	 */

	void setAdditionalAromrValueMax(int additionalArmorValueMax)
	{
		if (baseArmorValueMax + additionalArmorValueMax >= 0)
			this->additionalArmorValueMax = additionalArmorValueMax;
		else
		{
			cocos2d::log("[warning] 尝试设置附加的护甲上限为%d，这将会导致实际的护甲上限为不合法的值", additionalArmorValueMax);
		}
	}

	/*!
	 * \fn	void Role::updateAdditionalArmorValueMax(int delta)
	 *
	 * \brief	根据给定的增减量来更新角色的附加附加上限
	 *
	 * \param	delta	指定将用于更新角色的附加护甲上限的值
	 */
	void updateAdditionalArmorValueMax(int delta)
	{
		if (baseArmorValueMax + additionalArmorValueMax + delta >= 0)
			this->additionalArmorValueMax += delta;
		else
		{
			cocos2d::log("[warning] 尝试设置附加的护甲上限为%d，这将会导致实际的护甲上限为合法的值", additionalArmorValueMax + delta);
		}
	}

	/*！
	 * \fn	int Role::getHandCardCount()
	 *
	 * \brief	获取角色当前手牌数
	 *
	 * \return	返回角色当前手牌数
	 */
	int getHandCardCount()
	{
		return handCardCount;
	}

	/*！
	 * \fn	void Role::setHandCardCount(int handCardCount)
	 *
	 * \brief	根据给定的值来设置角色手牌数
	 *
	 * \param	handCardCount	指定将用于设置角色手牌数的值
	 */

	void setHandCardCount(int handCardCount)
	{
		if (handCardCount < this->handCardCountMax && handCardCount >= 0)
		{
			this->handCardCount = handCardCount;
		}
		else
		{
			cocos2d::log("[warning] 尝试设置手牌数量为%d,这将导致实际的手牌数量为不合法的值", handCardCount);
		}
	}

	/*！
	 * \fn	void Role::updateHandCount(int delta)
	 *
	 * \brief	根据给定的增减量来更新角色的手牌数
	 *
	 * \param	delta	指定将用于更新角色的手牌数的值
	 */
	void updateHandCount(int delta)
	{
		int temp = this->handCardCount + delta;
		if (temp <= this->handCardCountMax )
		{
			this->handCardCount = temp;
		}
		else
		{
			cocos2d::log("[warning] 尝试设置手牌数量为%d,这将导致实际的手牌数量为不合法的值", handCardCount);
		}
	}

	/*！
	 * \fn	int Role::getHandCardCountMax()
	 *
	 * \brief	获取角色当前手牌数上限值
	 *
	 * \return	返回角色当前手牌数上限值
	 */
	int getHandCardCountMax()
	{
		return handCardCountMax;
	}

	/*！
	 * \fn	int Role::getDrawCardCount()
	 *
	 * \brief	获取角色每回合内可抽牌数
	 *
	 * \return	返回角色每回合内可抽牌数
	 */
	int getDrawCardCount()
	{
		return drawCardCount;
	}

	/*！
	 * \fn	void Role::setDrawCardCount(int drawCardCount)
	 *
	 * \brief	根据给定的值来设置角色每回合内的可抽牌数
	 *
	 * \param	drawCardCount	指定将用于设置角色每回合内的可抽牌数的值
	 */
	void setDrawCardCount(int drawCardCount)
	{
		if (drawCardCount >= 0)
		{
			this->drawCardCount = drawCardCount;
		}
		else
		{
			cocos2d::log("[warning] 尝试设置角色每回合内可抽牌数为%d,这将导致实际的可抽牌数量为不合法的值", drawCardCount);
		}
	}

	/*！
	 * \fn	void Role::updateDrawCardCount(int delta)
	 *
	 * \brief	根据给定的增减量来更新角色每回合内可抽牌数
	 *
	 * \param	delta	指定将用于更新角色每回合内可抽牌数的值
	 */
	void updateDrawCardCount(int delta)
	{
		int temp = this->drawCardCount + delta;
		if (temp >= 0)
		{
			this->drawCardCount = temp;
		}
		else
		{
			cocos2d::log("[warning] 尝试设置角色每回合内可抽牌数为%d,这将导致实际的可抽牌数量为不合法的值", drawCardCount);
		}
	}


	/*！
	 * \fn	int Role::getDiscardCount()
	 *
	 * \brief	获取角色每回合内可出牌数
	 *
	 * \return	返回角色每回合内可出牌数
	 */
	int getDiscardCount()
	{
		return discardCount;
	}

	/*！
	 * \fn	void Role::setDiscardCount(int discardCount)
	 *
	 * \brief	根据给定的值设置角色每回合内的可出牌数
	 *
	 * \param	discardCount	指定将用于设置角色每回合内的可出牌数的值
	 */
	void setDiscardCount(int discardCount)
	{
		if (discardCount >= 0)
		{
			this->discardCount = discardCount;
		}
		else
		{
			cocos2d::log("[warning] 尝试设置角色每回合内可出牌数为%d,这将导致实际的可出牌数量为不合法的值", discardCount);
		}
	}

	/*！
	 * \fn	void Role::updateDiscardCount(int delta)
	 *
	 * \brief	根据给定的增减量来更新角色每回合内可出牌数
	 *
	 * \param	delta	指定将用于更新角色每回合内可出牌数的值
	 */
	void updateDiscardCount(int delta)
	{
		int temp = this->discardCount + delta;
		if (temp >= 0)
		{
			this->discardCount = temp;
		}
		else
		{
			cocos2d::log("[warning] 尝试设置角色每回合内可出牌数为%d,这将导致实际的可出牌数量为不合法的值", discardCount);
		}
	}

	void test();
};

#endif
