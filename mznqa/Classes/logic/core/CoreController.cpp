/*!
 * \file	Classes\logic\core\CoreController.cpp
 *
 * \brief	∂®“Â¿‡ CoreController
 */

#pragma execution_character_set("utf-8")

#include "logic/core/CoreController.h"

CoreController::CoreController() :
fSM(ArKCa::FiniteStateMachine<CoreController>(this))
{
}

CoreController::~CoreController()
{
}

CoreController* CoreController::Instance()
{
	static CoreController instance;
	return &instance;
}

bool CoreController::update(double intervalTime)
{
	fSM.update(intervalTime);
	return true;
}