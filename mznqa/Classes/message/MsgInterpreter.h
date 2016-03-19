#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MESSAGE_MSGINTERPRETER_H_
#define MZNQA_CLASSES_MESSAGE_MSGINTERPRETER_H_

#include "message/Message.h"
#include <map>

class MsgInterpreter
{
private:
	MsgInterpreter();
	MsgInterpreter(const MsgInterpreter &msgInterpreter);
	MsgInterpreter& operator=(const MsgInterpreter &msgInterpreter);

	// 消息映射表<EngineMessage, LogicMessage>
	std::map<int, int> msgMap;
public:
	// 获取MsgInterpreter单例
	static MsgInterpreter* Instance();
	~MsgInterpreter();

	// 转译消息
	Message translation(const Message &eMessage);
};

#endif