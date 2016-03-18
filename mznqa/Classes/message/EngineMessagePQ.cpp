#pragma execution_character_set("utf-8")

#include "message/EngineMessagePQ.h"

EngineMessagePQ* EngineMessagePQ::instance = nullptr;

EngineMessagePQ* EngineMessagePQ::Instance()
{
	if (instance == nullptr)
		instance = new EngineMessagePQ();

	return instance;
}

EngineMessagePQ::~EngineMessagePQ()
{
	delete instance;
}

void EngineMessagePQ::pushMessage(const Message &eMessage)
{
	msgPQ.push(eMessage);
}

Message EngineMessagePQ::getNextMessage()
{
	if (msgPQ.empty())
		return Message(EMessage_None, nullptr);

	Message msg = msgPQ.top();
	msgPQ.pop();
	return msg;
}

bool EngineMessagePQ::isEmpty()
{
	return msgPQ.empty();
}

void EngineMessagePQ::clear()
{
	while (msgPQ.empty() == false)
		msgPQ.pop();
}