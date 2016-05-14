/*!
 * \file	Classes\helper\bridge\Bridge.cpp
 *
 * \brief	¶¨ÒåÀà Bridge
 */

#pragma execution_character_set("utf-8")

#include "helper/bridge/Bridge.h"

#include "helper/messageInterpreter/MessageInterpreter.h"

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
	return CoreControllerInstance->update(intervalTime);
}

void Bridge::pushMessage2Logic(InteractiveMessagePQ::InteractiveMessageID messageID)
{
	LogicMessagePQInstance->pushMessage(MessageInterpreter::interpret(messageID));
}
void Bridge::pushMessage2Interactive(LogicMessagePQ::LogicMessageID messageID)
{
	InteractiveMessagePQInstance->pushMessage(MessageInterpreter::interpret(messageID));
}