#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MESSAGE_MSGINTERPRETER_H_
#define MZNQA_CLASSES_MESSAGE_MSGINTERPRETER_H_

#include <map>

#include "message/Message.h"
#include "message/EngineMessagePQ.h"
#include "message/LogicMessagePQ.h"

class MsgInterpreter
{
private:
	MsgInterpreter();
	MsgInterpreter(const MsgInterpreter &msgInterpreter);
	MsgInterpreter& operator=(const MsgInterpreter &msgInterpreter);

	EngineMessagePQ *engineMessagePQInstance;
	LogicMessagePQ *logicMessagePQInstance;

	// 消息映射表<EngineMessage, LogicMessage>
	std::map<EngineMessagePQ::EMessage, LogicMessagePQ::LMessage> msgMap;
public:
	// 获取MsgInterpreter单例
	static MsgInterpreter* Instance();
	~MsgInterpreter();

	// 转译消息
	Message<LogicMessagePQ::LMessage> translation(const Message<EngineMessagePQ::EMessage> &eMessage);
};

#endif