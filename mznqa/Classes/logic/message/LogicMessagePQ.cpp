/*!
 * \file	Classes\logic\message\LogicMessagePQ.cpp
 *
 * \brief	������ LogicMessagePQ
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

ArKCa::Message<LogicMessagePQ::LogicMessageID> LogicMessagePQ::getNextMessage()
{
	return msgPQ.getNextMessage();
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