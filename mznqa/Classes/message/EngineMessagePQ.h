#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MESSAGE_ENGINEMESSAGEPQ_H_
#define MZNQA_CLASSES_MESSAGE_ENGINEMESSAGEPQ_H_

#include <queue>
#include <vector>
#include <functional>
#include "message/Message.h"

// 于引擎使用的消息队列
class EngineMessagePQ
{
public:
	// 消息枚举
	enum EMessage
	{
		EMessage_None = 0,
		EMessage_MapMoveUp = 1,
		EMessage_MapMoveRight = 2,
		EMessage_MapMoveDown = 3,
		EMessage_MapMoveLeft = 4
	};

	// 获取 EngineMessagePQ 实例
	static EngineMessagePQ* Instance();

	~EngineMessagePQ();

	// 推送消息
	void pushMessage(const Message<EMessage> &eMessage);

	// 获取当前优先级最高的消息
	// 注意：当返回 EMessage_None 表示当前消息队列中无消息
	Message<EMessage> getNextMessage();

	// 判断当前消息队列是否为空
	bool isEmpty();

	// 清空当前消息队列
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