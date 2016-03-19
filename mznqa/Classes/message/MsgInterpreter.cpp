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
	msgMap.insert(std::pair<int, int>(0, 0));
}

MsgInterpreter::~MsgInterpreter()
{
}

Message MsgInterpreter::translation(const Message &eMessage)
{
	Message msg(msgMap[eMessage.messageID], eMessage.extras);
	return msg;
}