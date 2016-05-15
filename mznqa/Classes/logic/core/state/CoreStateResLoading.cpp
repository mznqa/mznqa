/*!
 * \file	Classes\logic\core\state\CoreStateResLoading.cpp
 *
 * \brief	¶¨ÒåÀà CoreStateResLoading
 */

#pragma execution_character_set("utf-8")

#include "logic/core/state/CoreStateResLoading.h"

#include "logic/core/state/CoreStateGameMain.h"
#include "helper/bridge/Bridge.h"

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
	// do something
	Bridge::Instance()->pushMessage2Interactive(LogicMessagePQ::LogicMessageID_StateChangeDone_CoreStateGuide_CoreStateResLoading);
	return true;
}
bool CoreStateResLoading::update(CoreController *owner, double intervalTime)
{
	owner->fSM.changeState(CoreStateGameMain::Instance());
	return true;
}
bool CoreStateResLoading::exit(CoreController *owner)
{
	return true;
}