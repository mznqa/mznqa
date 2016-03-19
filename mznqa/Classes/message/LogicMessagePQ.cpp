#pragma execution_character_set("utf-8")

#include "message/LogicMessagePQ.h"

LogicMessagePQ* LogicMessagePQ::Instance()
{
	static LogicMessagePQ instance;
	return &instance;
}

LogicMessagePQ::~LogicMessagePQ()
{
}

void LogicMessagePQ::pushMessage(const Message &lMessage)
{
	msgPQ.push(lMessage);
}

Message LogicMessagePQ::getNextMessage()
{
	if (msgPQ.empty())
		return Message(EMessage_None, nullptr);

	Message msg = msgPQ.top();
	msgPQ.pop();
	return msg;
}

bool LogicMessagePQ::isEmpty()
{
	return msgPQ.empty();
}

void LogicMessagePQ::clear()
{
	while (msgPQ.empty() == false)
		msgPQ.pop();
}