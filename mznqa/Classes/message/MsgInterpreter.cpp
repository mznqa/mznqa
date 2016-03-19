#pragma execution_character_set("utf-8")

#include "message/MsgInterpreter.h"

MsgInterpreter* MsgInterpreter::Instance()
{
	static MsgInterpreter instance;
	return &instance;
}

MsgInterpreter::MsgInterpreter()
{
	// 消息映射表<EngineMessage, LogicMessage>
	// TODO 将消息映射表补充完整
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