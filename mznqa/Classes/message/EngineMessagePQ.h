#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MESSAGE_ENGINEMESSAGEPQ_H_
#define MZNQA_CLASSES_MESSAGE_ENGINEMESSAGEPQ_H_

#include <queue>
#include <vector>
#include <functional>
#include "message/Message.h"

// ������ʹ�õ���Ϣ����
class EngineMessagePQ
{
private:
	EngineMessagePQ(){}
	EngineMessagePQ(const EngineMessagePQ &engineMessagePQ);
	EngineMessagePQ& operator=(const EngineMessagePQ &engineMessagePQ);

	std::priority_queue<Message, std::vector<Message>, std::greater<Message>> msgPQ;
public:
	// ��Ϣö��
	enum EMessage
	{
		EMessage_None = 0,
		// TODO ����ʵ����Ϣö��
	};

	// ��ȡ EngineMessagePQ ʵ��
	static EngineMessagePQ* Instance();

	~EngineMessagePQ();

	// ������Ϣ
	void pushMessage(const Message &eMessage);

	// ��ȡ��ǰ���ȼ���ߵ���Ϣ
	// ע�⣺������ EMessage_None ��ʾ��ǰ��Ϣ����������Ϣ
	Message getNextMessage();

	// �жϵ�ǰ��Ϣ�����Ƿ�Ϊ��
	bool isEmpty();

	// ��յ�ǰ��Ϣ����
	void clear();
};

#endif