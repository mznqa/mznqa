/*!
 * \file	Classes\logic\controller\CharacterController.cpp
 *
 * \brief	∂®“Â¿‡ CharacterController
 */

#pragma execution_character_set("utf-8")

#include "logic/controller/CharacterController.h"

CharacterController::~CharacterController()
{
	delete role;
	role = nullptr;
}

CharacterController* CharacterController::Instance()
{
	static CharacterController instance;
	return &instance;
}

void CharacterController::createRole()
{
	role = new Role();
}

Role* CharacterController::getRole()
{
	return role;
}