#pragma execution_character_set("utf-8")

#include "message/MsgInterpreter.h"

MsgInterpreter* MsgInterpreter::Instance()
{
	static MsgInterpreter instance;
	return &instance;
}

MsgInterpreter::MsgInterpreter()
{
	// ��Ϣӳ���<EngineMessage, LogicMessage>
	// TODO ����Ϣӳ���������
	engineMessagePQInstance = EngineMessagePQ::Instance();
	logicMessagePQInstance = LogicMessagePQ::Instance();

	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_None, LogicMessagePQ::LMessage_None
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_MapMoveUp, LogicMessagePQ::LMessage_MapViewMoveUp
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_MapMoveRight, LogicMessagePQ::LMessage_MapViewMoveRight
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_MapMoveDown, LogicMessagePQ::LMessage_MapViewMoveDown
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_MapMoveLeft, LogicMessagePQ::LMessage_MapViewMoveLeft
		));
}

MsgInterpreter::~MsgInterpreter()
{
}

Message<LogicMessagePQ::LMessage> MsgInterpreter::translation(const Message<EngineMessagePQ::EMessage> &eMessage)
{
	Message<LogicMessagePQ::LMessage> msg(msgMap[(EngineMessagePQ::EMessage)(eMessage.messageID)], eMessage.extras);
	return msg;
}