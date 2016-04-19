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
#include "map/MapController.h"

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

	/*! \brief	在地图上的位置，横坐标 */
	int x;
	/*! \brief	在地图上的位置，纵坐标 */
	int y;

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

	/*!
	 * \fn	int Role::getPositionX()const
	 *
	 * \brief	获取角色所在位置的横坐标值
	 *
	 * \return	返回角色所在位置的横坐标值
	 */
	int getPositionX()const
	{
		return x;
	}

	/*!
	 * \fn	int Role::getPositionY()const
	 *
	 * \brief	获取角色所在位置的纵坐标值
	 *
	 * \return	返回角色所在位置的纵坐标值
	 */
	int getPositionY()const
	{
		return y;
	}

	/*!
	 * \fn	void Role::setPositionX(int x)
	 *
	 * \brief	设置角色所在位置的横坐标
	 *
	 * \param	x	指定用于设置角色位置的横坐标
	 */
	void setPositionX(int x)
	{
		if (MapController::checkX(x))
			this->x = x;
		else
			this->x = 0;
	}

	/*!
	 * \fn	void Role::setPositionY(int y)
	 *
	 * \brief	设置角色所在位置的纵坐标
	 *
	 * \param	y	指定用于设置角色所在位置的纵坐标
	 */
	void setPositionY(int y)
	{
		if (MapController::checkY(y))
			this->y = y;
		else
			this->y = y;
	}

	/*!
	 * \fn	void Role::setPosition(int x, int y)
	 *
	 * \brief	设置角色当前的位置
	 *
	 * \param	x	指定用于设置角色位置的横坐标
	 * \param	y	指定用于设置角色位置的纵坐标
	 */
	void setPosition(int x, int y)
	{
		if (MapController::checkX(x))
			this->x = x;
		else
			this->x = 0;

		if (MapController::checkY(y))
			this->y = y;
		else
			this->y = 0;
	}

	/*!
	 * \fn	bool Role::updatePositionX(int delta)
	 *
	 * \brief	更新角色当前的横坐标值
	 *
	 * \param	delta	指定横坐标增减量
	 *
	 * \return	返回是否成功
	 */
	bool updatePositionX(int delta)
	{
		if (MapController::checkX(this->x + delta))
		{
			this->x += delta;
			return true;
		}
		return false;
	}

	/*!
	 * \fn	bool Role::updatePositionY(int delta)
	 *
	 * \brief	更行角色当前的纵坐标值
	 *
	 * \param	delta	指定纵坐标增减量
	 *
	 * \return	返回是否成功
	 */
	bool updatePositionY(int delta)
	{
		if (MapController::checkY(this->y + delta))
		{
			this->y += delta;
			return true;
		}
		return false;
	}

	/*!
	 * \fn	bool Role::updatePosition(int deltaX, int deltaY)
	 *
	 * \brief	更新角色当前的位置
	 *
	 * \param	deltaX	指定横坐标增减量
	 * \param	deltaY	指定纵坐标增减量
	 *
	 * \return	返回是否成功
	 */
	bool updatePosition(int deltaX, int deltaY)
	{
		if (MapController::checkX(this->x + deltaX) && MapController::checkY(this->y + deltaY))
		{
			this->x += deltaX;
			this->y += deltaY;
		}

		return false;
	}

	/*!
	 * \fn	bool Role::judgeMoveUp()const
	 *
	 * \brief	判断角色是否可以上移
	 *
	 * \return	返回角色是否可以上移
	 */
	bool judgeMoveUp()const
	{
		return MapController::checkY(this->y - 1);
	}

	/*!
	 * \fn	bool Role::judgeMoveDown()const
	 *
	 * \brief	判断角色是否可以下移
	 *
	 * \return	返回角色是否可以下移
	 */
	bool judgeMoveDown()const
	{
		return MapController::checkY(this->y + 1);
	}

	/*!
	 * \fn	bool Role::judgeMoveLeft()const
	 *
	 * \brief	判断角色是否可以左移
	 *
	 * \return	返回角色是否可以左移
	 */
	bool judgeMoveLeft()const
	{
		return MapController::checkX(this->x - 1);
	}

	/*!
	 * \fn	bool Role::judgeMoveRight()const
	 *
	 * \brief	判断角色是否可以右移
	 *
	 * \return	返回角色是否可以右移
	 */
	bool judgeMoveRight()const
	{
		return MapController::checkX(this->x + 1);
	}

	/*!
	 * \fn	void Role::moveUp()
	 *
	 * \brief	上移角色
	 *
	 */
	void moveUp()
	{
		updatePositionY(-1);
	}

	/*!
	 * \fn	void Role::moveDown()
	 *
	 * \brief	下移角色
	 *
	 */
	void moveDown()
	{
		updatePositionY(1);
	}

	/*!
	 * \fn	void Role::moveLeft()
	 *
	 * \brief	左移角色
	 *
	 */
	void moveLeft()
	{
		updatePositionX(-1);
	}

	/*!
	 * \fn	void Role::moveRight()
	 *
	 * \brief	右移角色
	 *
	 */
	void moveRight()
	{
		updatePositionX(1);
	}

	void test();
};

#endif
