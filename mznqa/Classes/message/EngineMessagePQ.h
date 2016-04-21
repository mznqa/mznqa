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
public:
	// ��Ϣö��
	enum EMessage
	{
		EMessage_None = 0,
		EMessage_MapMoveUp = 1,
		EMessage_MapMoveRight = 2,
		EMessage_MapMoveDown = 3,
		EMessage_MapMoveLeft = 4
	};

	// ��ȡ EngineMessagePQ ʵ��
	static EngineMessagePQ* Instance();

	~EngineMessagePQ();

	// ������Ϣ
	void pushMessage(const Message<EMessage> &eMessage);

	// ��ȡ��ǰ���ȼ���ߵ���Ϣ
	// ע�⣺������ EMessage_None ��ʾ��ǰ��Ϣ����������Ϣ
	Message<EMessage> getNextMessage();

	// �жϵ�ǰ��Ϣ�����Ƿ�Ϊ��
	bool isEmpty();

	// ��յ�ǰ��Ϣ����
	void clear();

	int getMessageCount()
	{
		return msgPQ.size();
	}

private:
	EngineMessagePQ(){}
	EngineMessagePQ(const EngineMessagePQ &engineMessagePQ);
	EngineMessagePQ& operator=(const EngineMessagePQ &engineMessagePQ);

	std::priority_queue<Message<EMessage>, std::vector<Message<EMessage>>, std::greater<Message<EMessage>>> msgPQ;
};

#endif