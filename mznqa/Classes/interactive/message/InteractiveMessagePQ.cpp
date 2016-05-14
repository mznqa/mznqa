/*!
 * \file	Classes\interactive\message\InteractiveMessagePQ.cpp
 *
 * \brief	∂®“Â¿‡ InteractiveMessagePQ
 */

#pragma execution_character_set("utf-8")

#include "interactive/message/InteractiveMessagePQ.h"

InteractiveMessagePQ::InteractiveMessagePQ()
{
}

InteractiveMessagePQ::~InteractiveMessagePQ()
{
}

InteractiveMessagePQ* InteractiveMessagePQ::Instance()
{
	static InteractiveMessagePQ instance;
	return &instance;
}

void InteractiveMessagePQ::pushMessage(const ArKCa::Message<InteractiveMessageID> &message)
{
	msgPQ.pushMessage(message);
}

const ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> *const InteractiveMessagePQ::getTopMessage()const
{
	return msgPQ.getTopMessage();
}

bool InteractiveMessagePQ::isEmpty()const
{
	return msgPQ.isEmpty();
}

void InteractiveMessagePQ::clear()
{
	msgPQ.clear();
}

int InteractiveMessagePQ::getMessageCount()const
{
	return msgPQ.getMessageCount();
}