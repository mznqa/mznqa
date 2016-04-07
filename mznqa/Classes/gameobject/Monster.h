/*!
 * \file	Classes\gameobject\Monster.h
 *
 * \brief	定义类 Monster
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_GAMEOBJECT_MONSTER_H_
#define MZNQA_CLASSES_GAMEOBJECT_MONSTER_H_

#include <string>

#include "cocos2d.h"

#include "cardController/CardControllerCombat.h"

/*!
 * \class	Monster
 *
 * \brief	怪物
 *
 */
class Monster
{
private:
	/*! \brief	怪物的名称 */
	std::string name;
	/*! \brief	怪物的描述 */
	std::string describe;
	/*! \brief	怪物的基础血量上限 */
	int baseBloodValueMax;
	/*! \brief	怪物的基础护甲上限 */
	int baseArmorValueMax;

	/*! \brief	怪物的血量实时量 */
	int bloodValue;
	/*! \brief	怪物的护甲实时量 */
	int armorValue;
	/*! \brief	怪物的附加血量上限 */
	int additionalBloodValueMax;
	/*! \brief	怪物的附加护甲上限 */
	int additionalArmorValueMax;
public:

	/*!
	 * \fn	Monster::Monster();
	 *
	 * \brief	构造函数
	 *
	 */
	Monster();

	/*!
	 * \fn	Monster::~Monster();
	 *
	 * \brief	析构函数
	 *
	 */
	~Monster();

	/*! \brief	战斗场景下的卡牌管理器 */
	CardControllerCombat cardControllerCombat;

	/*!
	 * \fn	const std::string& Monster::getName()const
	 *
	 * \brief	获取怪物的名称
	 *
	 * \return	返回怪物的名称
	 */
	const std::string& getName()const
	{
		return name;
	}

	/*!
	 * \fn	const std::string& Monster::getDescribe()const
	 *
	 * \brief	获取怪物的描述
	 *
	 * \return	返回怪物的描述
	 */
	const std::string& getDescribe()const
	{
		return describe;
	}

	/*!
	 * \fn	int Monster::getBaseBloodValueMax()const
	 *
	 * \brief	获取怪物的基础血量上限
	 *
	 * \return	返回怪物的基础血量上限
	 */
	int getBaseBloodValueMax()const
	{
		return baseBloodValueMax;
	}

	/*!
	 * \fn	int Monster::getBaseArmorValueMax()const
	 *
	 * \brief	获取怪物的基础护甲上限
	 *
	 * \return	获取怪物的基础护甲上限
	 */
	int getBaseArmorValueMax()const
	{
		return baseArmorValueMax;
	}

	/*!
	 * \fn	int Monster::getBloodValueMax()const
	 *
	 * \brief	获取怪物当前的血量上限
	 *
	 * \return	返回怪物当前的血量上限
	 */
	int getBloodValueMax()const
	{
		return baseBloodValueMax + additionalBloodValueMax;
	}

	/*!
	 * \fn	int Monster::getArmorValueMax()const
	 *
	 * \brief	获取怪物当前的护甲上限
	 *
	 * \return	返回怪物当前的护甲上限
	 */
	int getArmorValueMax()const
	{
		return baseArmorValueMax + additionalArmorValueMax;
	}

	/*!
	 * \fn	int Monster::getBloodValue()const
	 *
	 * \brief	获取怪物当前的血量
	 *
	 * \return	返回怪物当前的血量
	 */
	int getBloodValue()const
	{
		return bloodValue;
	}

	/*!
	 * \fn	void Monster::setBloodValue(int bloodValue)
	 *
	 * \brief	根据给定值来设置怪物当前的血量
	 *
	 * \param	bloodValue	指定将用于设置怪物当前血量的值
	 */
	void setBloodValue(int bloodValue)
	{
		if (0 <= bloodValue && bloodValue <= getBloodValueMax())
			this->bloodValue = bloodValue;
		else
		{
			cocos2d::log("[warning] 尝试为怪物设置越界血量");
		}
	}

	/*!
	 * \fn	void Monster::updateBloodValue(int delta)
	 *
	 * \brief	根据给定增减量来更新怪物当前的血量
	 *
	 * \param	delta	指定将用于更新怪物当前血量的增减量
	 */
	void updateBloodValue(int delta)
	{
		int temp = bloodValue + delta;
		if (0 <= temp && temp <= getBloodValueMax())
			this->bloodValue = temp;
		else
		{
			cocos2d::log("[warning] 尝试更新怪物血量，以至血量越界，变化量为%d, 而当前血量为%d", delta, bloodValue);
		}
	}

	/*!
	 * \fn	int Monster::getArmorValue()const
	 *
	 * \brief	获取怪物当前护甲
	 *
	 * \return	返回怪物当前护甲
	 */
	int getArmorValue()const
	{
		return armorValue;
	}

	/*!
	 * \fn	void Monster::setArmorValue(int armorValue)
	 *
	 * \brief	根据给定的值来设置怪物当前的护甲
	 *
	 * \param	armorValue	指定将用于设置怪物当前护甲的值
	 */
	void setArmorValue(int armorValue)
	{
		if (0 <= armorValue && armorValue <= getArmorValue())
			this->armorValue = armorValue;
		else
		{
			cocos2d::log("[warning] 尝试为怪物设置越界血量");
		}
	}

	/*!
	 * \fn	void Monster::updateArmorValue(int delta)
	 *
	 * \brief	根据给定增减量来更新怪物当前的护甲
	 *
	 * \param	delta	指定将用于更新怪物当前护甲的增减量
	 */
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

	/*!
	 * \fn	int Monster::getAdditionalBloodValueMax()const
	 *
	 * \brief	获取怪物当前的附加血量上限
	 *
	 * \return	返回怪物当前的附加血量上限
	 */
	int getAdditionalBloodValueMax()const
	{
		return additionalBloodValueMax;
	}

	/*!
	 * \fn	void Monster::setAdditionalBloodValueMax(int additionalBloodValueMax)
	 *
	 * \brief	根据给定的值来设置怪物当前的附加血量上限
	 *
	 * \param	additionalBloodValueMax	指定将用设置怪物当前的附加血量上限
	 */
	void setAdditionalBloodValueMax(int additionalBloodValueMax)
	{
		if (baseBloodValueMax + additionalBloodValueMax >= 0)
			this->additionalBloodValueMax = additionalBloodValueMax;
		else
		{
			cocos2d::log("[warning] 尝试为怪物设置附加血量上限失败，将导致血量上限不合法");
		}
	}

	/*!
	 * \fn	void Monster::updateAdditionalBloodValueMax(int delta)
	 *
	 * \brief	根据给定的增减量来更新怪物当前的附加血量上限
	 *
	 * \param	delta	指定将用于设置怪物当前的附加血量上限的增减量
	 */
	void updateAdditionalBloodValueMax(int delta)
	{
		if (baseBloodValueMax + additionalBloodValueMax + delta >= 0)
			this->additionalBloodValueMax += delta;
		else
		{
			cocos2d::log("[warning] 尝试更新怪物的附加血量上限失败，将导致血量上限不合法");
		}
	}

	/*!
	 * \fn	int Monster::getAdditionalArmorValueMax()const
	 *
	 * \brief	获取怪物当前的附加护甲上限
	 *
	 * \return	返回怪物当前的附加护甲上限
	 */
	int getAdditionalArmorValueMax()const
	{
		return additionalBloodValueMax;
	}

	/*!
	 * \fn	void Monster::setAdditionArmorValueMax(int additionalArmorValueMax)
	 *
	 * \brief	根据给定的值来设置怪物当前的附加护甲上限
	 *
	 * \param	additionalArmorValueMax	指定将用于设置怪物当前的附加护甲上限的值
	 */
	void setAdditionArmorValueMax(int additionalArmorValueMax)
	{
		if (baseArmorValueMax + additionalArmorValueMax >= 0)
			this->additionalArmorValueMax = additionalArmorValueMax;
		else
		{
			cocos2d::log("[warning] 尝试为怪物设置附加的护甲上限失败，将导致护甲上限不合法");
		}
	}

	/*!
	 * \fn	void Monster::updateAdditionalArmorValueMax(int delta)
	 *
	 * \brief	根据给定的增减量来更新怪物当前的附加护甲上限
	 *
	 * \param	delta	指定将用于更新怪物当前的附加护甲上限的增减量
	 */
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
