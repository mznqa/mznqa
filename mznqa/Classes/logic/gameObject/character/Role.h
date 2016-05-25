/*!
 * \file	Classes\logic\gameObject\character\Role.h
 *
 * \brief	定义类 Role
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_CHARACTER_ROLE_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_CHARACTER_ROLE_H_

#include "logic/gameObject/cardController/CardControllerExplore.h"
#include "common/arkca/Vector2.h"
#include "common/arkca/Rectangle.h"
#include "common/arkca/Direction.h"
#include "logic/controller/MapController.h"

/*!
 * \class	Role
 *
 * \brief	游戏对象：角色
 *
 */
class Role
{
private:
	/*! \brief	在地图中的坐标 */
	ArKCa::Vector2<int> position;

	/*! \brief	坐标允许的范围区间 */
	ArKCa::Rectangle<int> positionRange;

	/*! \brief	探索场景下的卡牌控制器 */
	CardControllerExplore cardControllerExplore;

public:

	/*!
	 * \fn	Role::Role( const ArKCa::Vector2<int> &position, const ArKCa::Rectangle<int> &positionRange )
	 *
	 * \brief	构造函数
	 *
	 * \param	position	 	指定所在的位置
	 * \param	positionRange	指定允许的坐标值区间
	 */
	Role(
		const ArKCa::Vector2<int> &position,
		const ArKCa::Rectangle<int> &positionRange
		) :
		position(position),
		positionRange(positionRange),
		cardControllerExplore()
	{
	}

	/*!
	 * \fn	Role::Role(const Role &role)
	 *
	 * \brief	拷贝构造函数
	 *
	 */

	Role(const Role &role);

	/*!
	 * \fn	Role& Role::operator=(const Role &role);
	 *
	 * \brief	拷贝赋值运算符
	 *
	 */
	Role& operator=(const Role &role);

	/*!
	 * \fn	Role::~Role()
	 *
	 * \brief	析构函数
	 *
	 */
	~Role()
	{
	}

	/*!
	 * \fn	void Role::setPosition(ArKCa::Vector2<int> position)
	 *
	 * \brief	设置角色的位置
	 *
	 */
	void setPosition(ArKCa::Vector2<int> position)
	{
		if (positionRange.isContains(position))
			this->position = position;
	}

	/*!
	 * \fn	const ArKCa::Vector2<int>& Role::getPosition()const
	 *
	 * \brief	获取角色的位置
	 *
	 */
	const ArKCa::Vector2<int>& getPosition()const
	{
		return position;
	}

	/*!
	 * \fn	bool Role::moveUp(int step = 1)
	 *
	 * \brief	向上移动角色
	 *
	 * \param	step	指定移动的步数，默认为 1
	 *
	 * \return	返回是否移动成功
	 */
	bool moveUp(int step = 1)
	{
		if (step > 0 && positionRange.isContainsY(position.y - step))
		{
			if (MapController::Instance()->getMap().getNeighborCanThrough(
				position,
				ArKCa::Direction4::Direction4_Up
				))
			{
				this->position.y -= step;
				return true;
			}
		}
		return false;
	}

	/*!
	 * \fn	bool Role::moveDown(int step = 1)
	 *
	 * \brief	向下移动角色
	 *
	 * \return	返回是否移动成功
	 */
	bool moveDown(int step = 1)
	{
		if (step > 0 && positionRange.isContainsY(position.y + step))
		{
			if (MapController::Instance()->getMap().getNeighborCanThrough(
				position,
				ArKCa::Direction4::Direction4_Down
				))
			{
				this->position.y += step;
				return true;
			}
		}
		return false;
	}

	/*!
	 * \fn	bool Role::moveLeft(int step = 1)
	 *
	 * \brief	向左移动角色
	 *
	 * \return	返回是否移动成功
	 */
	bool moveLeft(int step = 1)
	{
		if (step > 0 && positionRange.isContainsX(position.x - step))
		{
			if (MapController::Instance()->getMap().getNeighborCanThrough(
				position,
				ArKCa::Direction4::Direction4_Left
				))
			{
				this->position.x -= step;
				return true;
			}
		}
		return false;
	}

	/*!
	 * \fn	bool Role::moveRight(int step = 1)
	 *
	 * \brief	向右移动角色
	 *
	 * \return	返回是否移动成功
	 */
	bool moveRight(int step = 1)
	{
		if (step > 0 && positionRange.isContainsX(position.x + step))
		{
			if (MapController::Instance()->getMap().getNeighborCanThrough(
				position,
				ArKCa::Direction4::Direction4_Right
				))
			{
				this->position.x += step;
				return true;
			}
		}
		return false;
	}

	/*!
	 * \fn	bool Role::drawCard();
	 *
	 * \brief	抽牌
	 *
	 * \return	返回抽牌是否成功
	 */
	bool drawCard();

	/*!
	 * \fn	CardControllerExplore& Role::getCardControllerExplore();
	 *
	 * \brief	获取探索场景下的卡牌控制
	 *
	 */
	CardControllerExplore& getCardControllerExplore();
};

#endif
