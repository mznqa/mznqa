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

	// ��Ϣӳ���<EngineMessage, LogicMessage>
	std::map<int, int> msgMap;
public:
	// ��ȡMsgInterpreter����
	static MsgInterpreter* Instance();
	~MsgInterpreter();

	// ת����Ϣ
	Message translation(const Message &eMessage);
};

#endif