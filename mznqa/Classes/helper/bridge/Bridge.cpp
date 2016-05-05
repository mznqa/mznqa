/*!
 * \file	Classes\helper\bridge\Bridge.cpp
 *
 * \brief	∂®“Â¿‡ Bridge
 */

#pragma execution_character_set("utf-8")

#include "helper/bridge/Bridge.h"

#include "helper/bridge/MessageInterpreter.h"

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

void Bridge::pushMessage2Logic(const ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> &message)
{
	LogicMessagePQInstance->pushMessage(MessageInterpreter::interpret(message));
}
void Bridge::pushMessage2Interactive(const ArKCa::Message<LogicMessagePQ::LogicMessageID> &message)
{
	InteractiveMessagePQInstance->pushMessage(MessageInterpreter::interpret(message));
}