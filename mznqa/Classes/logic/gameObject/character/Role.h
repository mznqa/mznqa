/*!
 * \file	Classes\logic\gameObject\character\Role.h
 *
 * \brief	定义类 Role
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_CHARACTER_ROLE_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_CHARACTER_ROLE_H_

#include "logic/gameObject/cardController/CardControllerExplore.h"

/*!
 * \class	Role
 *
 * \brief	游戏对象：角色
 *
 */
class Role
{
private:
	/*! \brief	探索场景下的卡牌控制器 */
	CardControllerExplore cardControllerExplore;

public:

	/*!
	 * \fn	Role::Role()
	 *
	 * \brief	构造函数
	 *
	 */
	Role() :
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
