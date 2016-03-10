#ifndef MZNQA_CLASSES_MESSAGE_MSGINTERPRETER_H_
#define MZNQA_CLASSES_MESSAGE_MSGINTERPRETER_H_

#include "message/Message.h"
#include <map>

class MsgInterpreter
{
private:
	static MsgInterpreter *instance;
	// ��Ϣӳ���<EngineMessage, LogicMessage>
	std::map<int, int> msgMap;
protected:
	MsgInterpreter();
	MsgInterpreter(const MsgInterpreter &msgInterpreter);
	MsgInterpreter& operator=(const MsgInterpreter &msgInterpreter);
public:
	// ��ȡMsgInterpreter����
	static MsgInterpreter* Instance();
	~MsgInterpreter();

	// ת����Ϣ
	Message translation(const Message &eMessage);
};

#endif