/*!
 * \file	Classes\helper\messageInterpreter\MessageInterpreter.cpp
 *
 * \brief	∂®“Â¿‡ MessageInterpreter
 */

#pragma execution_character_set("utf-8")

#include "helper/messageInterpreter/MessageInterpreter.h"

MessageInterpreter::MessageInterpreter()
{
}

MessageInterpreter::~MessageInterpreter()
{
}

ArKCa::Message<LogicMessagePQ::LogicMessageID> MessageInterpreter::interpret(InteractiveMessagePQ::InteractiveMessageID messageID)
{
	switch (messageID)
	{
	case InteractiveMessagePQ::InteractiveMessageID_ValidID:
		return ArKCa::Message<LogicMessagePQ::LogicMessageID>(LogicMessagePQ::LogicMessageID_ValidID);
		break;
	default:
		return ArKCa::Message<LogicMessagePQ::LogicMessageID>(LogicMessagePQ::LogicMessageID_ValidID);
		break;
	}
}
ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> MessageInterpreter::interpret(LogicMessagePQ::LogicMessageID messageID)
{
	switch (messageID)
	{
	case LogicMessagePQ::LogicMessageID_ValidID:
		return ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID>(InteractiveMessagePQ::InteractiveMessageID_ValidID);
		break;
	case LogicMessagePQ::LogicMessageID_StateChangeDone_CoreStateGuide_CoreStateResLoading:
		return ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID>(InteractiveMessagePQ::InteractiveMessageID_ChangeScene_SceneGuide_SceneResLoading);
		break;
	case LogicMessagePQ::LogicMessageID_StateChangeDone_CoreStateResLoading_CoreStateGameMain:
		return ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID>(InteractiveMessagePQ::InteractiveMessageID_ChangeScene_SceneResLoading_SceneGameMain);
		break;
	default:
		return ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID>(InteractiveMessagePQ::InteractiveMessageID_ValidID);
		break;
	}
}