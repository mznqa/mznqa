/*!
 * \file	Classes\logic\controller\CharacterController.cpp
 *
 * \brief	∂®“Â¿‡ CharacterController
 */

#pragma execution_character_set("utf-8")

#include "logic/controller/CharacterController.h"

#include "common/arkca/Rectangle.h"

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
	role = new Role(
		ArKCa::Vector2<int>(10, 10),
		ArKCa::Rectangle<int>(ArKCa::Vector2<int>(0, 0), ArKCa::Vector2<int>(19, 19))
		);
}

Role* CharacterController::getRole()
{
	return role;
}