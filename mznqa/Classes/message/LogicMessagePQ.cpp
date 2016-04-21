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

void LogicMessagePQ::pushMessage(const Message<LMessage> &lMessage)
{
	if (lMessage.messageID == LMessage_None)
		return;

	msgPQ.push(lMessage);
}

Message<LogicMessagePQ::LMessage>  LogicMessagePQ::getNextMessage()
{
	if (msgPQ.empty())
		return Message<LMessage>(LMessage_None, nullptr);

	Message<LMessage>  msg = msgPQ.top();
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