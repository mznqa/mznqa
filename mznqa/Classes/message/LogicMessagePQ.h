#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MESSAGE_LOGICMESSAGEPQ_H_
#define MZNQA_CLASSES_MESSAGE_LOGICMESSAGEPQ_H_

#include <queue>
#include <vector>
#include <functional>
#include "message/Message.h"

// ���߼�ʹ�õ���Ϣ����
class LogicMessagePQ
{
public:
	// ��Ϣö��
	enum LMessage
	{
		LMessage_None = 0,
		LMessage_RefreshRolePosition,
		LMessage_RefreshMapPosition,
		LMessage_MapViewMoveUp,
		LMessage_MapViewMoveRight,
		LMessage_MapViewMoveDown,
		LMessage_MapViewMoveLeft 
	};

	// ��ȡ EngineMessagePQ ʵ��
	static LogicMessagePQ* Instance();

	~LogicMessagePQ();

	// ������Ϣ
	void pushMessage(const Message<LMessage> &lMessage);

	// ��ȡ��ǰ���ȼ���ߵ���Ϣ
	// ע�⣺������ EMessage_None ��ʾ��ǰ��Ϣ����������Ϣ
	Message<LMessage> getNextMessage();

	// �жϵ�ǰ��Ϣ�����Ƿ�Ϊ��
	bool isEmpty();

	// ��յ�ǰ��Ϣ����
	void clear();

	int getMessageCount()
	{
		return msgPQ.size();
	}

private:
	LogicMessagePQ(){}
	LogicMessagePQ(const LogicMessagePQ &logicMessagePQ);
	LogicMessagePQ& operator=(const LogicMessagePQ &logicMessagePQ);

	std::priority_queue<Message<LMessage>, std::vector<Message<LMessage>>, std::greater<Message<LMessage>>> msgPQ;
};

#endif