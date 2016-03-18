#pragma execution_character_set("utf-8")

#include "message/LogicMessagePQ.h"

LogicMessagePQ* LogicMessagePQ::instance = nullptr;

LogicMessagePQ* LogicMessagePQ::Instance()
{
	if (instance == nullptr)
		instance = new LogicMessagePQ();

	return instance;
}

LogicMessagePQ::~LogicMessagePQ()
{
	delete instance;
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