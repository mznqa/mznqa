/*!
 * \file	Classes\logic\message\LogicMessagePQ.cpp
 *
 * \brief	∂®“Â¿‡ LogicMessagePQ
 */

#pragma execution_character_set("utf-8")

#include "logic/message/LogicMessagePQ.h"

LogicMessagePQ::LogicMessagePQ()
{
}

LogicMessagePQ::~LogicMessagePQ()
{
}

LogicMessagePQ* LogicMessagePQ::Instance()
{
	static LogicMessagePQ instance;
	return &instance;
}

void LogicMessagePQ::pushMessage(const ArKCa::Message<LogicMessageID> &message)
{
	msgPQ.pushMessage(message);
}

const ArKCa::Message<LogicMessagePQ::LogicMessageID> *const LogicMessagePQ::getTopMessage()const
{
	return msgPQ.getTopMessage();
}

bool LogicMessagePQ::isEmpty()const
{
	return msgPQ.isEmpty();
}

void LogicMessagePQ::clear()
{
	msgPQ.clear();
}

int LogicMessagePQ::getMessageCount()const
{
	return msgPQ.getMessageCount();
}