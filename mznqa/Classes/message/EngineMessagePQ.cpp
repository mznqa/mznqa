/*!
 * \file	Classes\message\EngineMessagePQ.cpp
 *
 * \brief	∂®“Â¿‡ EngineMessagePQ
 */

#pragma execution_character_set("utf-8")

#include "message/EngineMessagePQ.h"

EngineMessagePQ* EngineMessagePQ::Instance()
{
	static EngineMessagePQ instance;
	return &instance;
}

EngineMessagePQ::~EngineMessagePQ()
{
}

void EngineMessagePQ::pushMessage(const Message<EMessage> &eMessage)
{
	if (eMessage.messageID == EMessage_None)
		return;

	msgPQ.push(eMessage);
}

Message<EngineMessagePQ::EMessage> EngineMessagePQ::getNextMessage()
{
	if (msgPQ.empty())
		return Message<EMessage>(EMessage_None, nullptr);

	Message<EMessage> msg = msgPQ.top();
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