/*!
 * \file	D:\Projects\mznqa\mznqa\Classes\logic\controller\CharacterController.h
 *
 * \brief	定义类 CharacterController
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_CONTROLLER_CHARACTERCONTROLLER_H_
#define MZNQA_CLASSES_LOGIC_CONTROLLER_CHARACTERCONTROLLER_H_

#include "logic/gameObject/character/Role.h"

/*!
 * \class	CharacterController
 *
 * \brief	角色控制器，用于控制游戏中的角色
 *
 */
class CharacterController
{
private:

	/*!
	 * \fn	CharacterController::CharacterController()
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	CharacterController() :
		role(nullptr)
	{
	}

	/*!
	 * \fn	CharacterController::CharacterController(const CharacterController &characterController);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 */
	CharacterController(const CharacterController &characterController);

	/*!
	 * \fn	CharacterController& CharacterController::operator=(const CharacterController &characterController);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 */
	CharacterController& operator=(const CharacterController &characterController);

	/*! \brief	角色实例 */
	Role *role;
public:

	/*!
	 * \fn	CharacterController::~CharacterController();
	 *
	 * \brief	析构函数
	 *
	 */
	~CharacterController();

	/*!
	 * \fn	static CharacterController* CharacterController::Instance();
	 *
	 * \brief	获取单例
	 *
	 */
	static CharacterController* Instance();

	/*!
	 * \fn	void CharacterController::createRole();
	 *
	 * \brief	创建角色
	 *
	 */
	void createRole();

	/*!
	 * \fn	Role* CharacterController::getRole();
	 *
	 * \brief	获取角色
	 *
	 */
	Role* getRole();
};

#endif
