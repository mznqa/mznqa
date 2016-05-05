/*!
 * \file	Classes\helper\bridge\MessageInterpreter.cpp
 *
 * \brief	¶¨ÒåÀà MessageInterpreter
 */

#pragma execution_character_set("utf-8")

#include "helper/bridge/MessageInterpreter.h"

MessageInterpreter::MessageInterpreter()
{
}

MessageInterpreter::~MessageInterpreter()
{
}

ArKCa::Message<LogicMessagePQ::LogicMessageID> MessageInterpreter::interpret(const ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> &message)
{
	return ArKCa::Message<LogicMessagePQ::LogicMessageID>(LogicMessagePQ::LogicMessageID_ValidID);
}
ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> MessageInterpreter::interpret(const ArKCa::Message<LogicMessagePQ::LogicMessageID> &message)
{
	return ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID>(InteractiveMessagePQ::InteractiveMessageID_ValidID);
}