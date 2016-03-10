#ifndef MZNQA_CLASSES_MESSAGE_MSGINTERPRETER_H_
#define MZNQA_CLASSES_MESSAGE_MSGINTERPRETER_H_

#include "message/Message.h"
#include <map>

class MsgInterpreter
{
private:
	static MsgInterpreter *instance;
	// 消息映射表<EngineMessage, LogicMessage>
	std::map<int, int> msgMap;
protected:
	MsgInterpreter();
	MsgInterpreter(const MsgInterpreter &msgInterpreter);
	MsgInterpreter& operator=(const MsgInterpreter &msgInterpreter);
public:
	// 获取MsgInterpreter单例
	static MsgInterpreter* Instance();
	~MsgInterpreter();

	// 转译消息
	Message translation(const Message &eMessage);
};

#endif