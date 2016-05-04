/*!
 * \file	Classes\logic\core\state\CoreStateResLoading.cpp
 *
 * \brief	∂®“Â¿‡ CoreStateResLoading
 */

#pragma execution_character_set("utf-8")

#include "logic/core/state/CoreStateResLoading.h"

CoreStateResLoading::CoreStateResLoading()
{
}

CoreStateResLoading::~CoreStateResLoading()
{
}

CoreStateResLoading* CoreStateResLoading::Instance()
{
	static CoreStateResLoading instance;
	return &instance;
}

bool CoreStateResLoading::enter(CoreController *owner)
{
	return true;
}
bool CoreStateResLoading::update(CoreController *owner, double intervalTime)
{
	return true;
}
bool CoreStateResLoading::exit(CoreController *owner)
{
	return true;
}