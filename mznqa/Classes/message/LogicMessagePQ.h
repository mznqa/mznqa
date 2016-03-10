#ifndef MZNQA_CLASSES_MESSAGE_LOGICMESSAGEPQ_H_
#define MZNQA_CLASSES_MESSAGE_LOGICMESSAGEPQ_H_

#include <queue>
#include <vector>
#include <functional>
#include "message/Message.h"

class LogicMessagePQ
{
private:
	static LogicMessagePQ *instance;
	std::priority_queue<Message, std::vector<Message>, std::greater<Message>> msgPQ;
protected:
	LogicMessagePQ(){}
	LogicMessagePQ(const LogicMessagePQ &logicMessagePQ);
	LogicMessagePQ& operator=(const LogicMessagePQ &logicMessagePQ);
public:
	// ��Ϣö��
	enum LMessage
	{
		EMessage_None = 0,
		// TODO ����ʵ����Ϣö��
	};

	// ��ȡ EngineMessagePQ ʵ��
	static LogicMessagePQ* Instance();

	~LogicMessagePQ();

	// ������Ϣ
	void pushMessage(const Message &lMessage);

	// ��ȡ��ǰ���ȼ���ߵ���Ϣ
	// ע�⣺������ EMessage_None ��ʾ��ǰ��Ϣ����������Ϣ
	Message getNextMessage();

	// �жϵ�ǰ��Ϣ�����Ƿ�Ϊ��
	bool isEmpty();

	// ��յ�ǰ��Ϣ����
	void clear();
};

#endif