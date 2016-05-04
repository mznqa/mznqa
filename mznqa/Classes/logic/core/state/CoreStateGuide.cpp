/*!
 * \file	Classes\logic\core\state\CoreStateGuide.cpp
 *
 * \brief	∂®“Â¿‡ CoreStateGuide
 */

#pragma execution_character_set("utf-8")

#include "logic/core/state/CoreStateGuide.h"

CoreStateGuide::CoreStateGuide()
{
}

CoreStateGuide::~CoreStateGuide()
{
}

CoreStateGuide* CoreStateGuide::Instance()
{
	static CoreStateGuide instance;
	return &instance;
}

bool CoreStateGuide::enter(CoreController *owner)
{
	return true;
}
bool CoreStateGuide::update(CoreController *owner, double intervalTime)
{
	return true;
}
bool CoreStateGuide::exit(CoreController *owner)
{
	return true;
}