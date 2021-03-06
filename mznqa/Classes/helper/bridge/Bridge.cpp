/*!
 * \file	Classes\helper\bridge\Bridge.cpp
 *
 * \brief	������ Bridge
 */

#pragma execution_character_set("utf-8")

#include "helper/bridge/Bridge.h"

#include "helper/messageInterpreter/MessageInterpreter.h"
#include "logic/core/CoreController.h"

Bridge::Bridge()
{
}

Bridge::~Bridge()
{
}

Bridge* Bridge::Instance()
{
	static Bridge instance;
	return &instance;
}

bool Bridge::update(double intervalTime)
{
	return CoreController::Instance()->update(intervalTime);
}

void Bridge::pushMessage2Logic(InteractiveMessagePQ::InteractiveMessageID messageID)
{
	LogicMessagePQ::Instance()->pushMessage(MessageInterpreter::interpret(messageID));
}
void Bridge::pushMessage2Interactive(LogicMessagePQ::LogicMessageID messageID)
{
	InteractiveMessagePQ::Instance()->pushMessage(MessageInterpreter::interpret(messageID));
}