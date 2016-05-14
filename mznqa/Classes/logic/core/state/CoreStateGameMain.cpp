/*!
* \file		Classes\logic\core\state\CoreStateGameMain.cpp
*
* \brief	¶¨ÒåÀà CoreStateGameMain
*/

#pragma execution_character_set("utf-8")

#include "logic/core/state/CoreStateGameMain.h"

CoreStateGameMain::CoreStateGameMain()
{
}

CoreStateGameMain::~CoreStateGameMain()
{
}

CoreStateGameMain* CoreStateGameMain::Instance()
{
	static CoreStateGameMain instance;
	return &instance;
}

bool CoreStateGameMain::enter(CoreController *owner)
{
	BridgeInstance->pushMessage2Interactive(LogicMessagePQ::LogicMessageID_StateChangeDone_CoreStateResLoading_CoreStateGameMain);
	return true;
}
bool CoreStateGameMain::update(CoreController *owner, double intervalTime)
{
	return true;
}
bool CoreStateGameMain::exit(CoreController *owner)
{
	return true;
}