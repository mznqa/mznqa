#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MESSAGE_LOGICMESSAGEPQ_H_
#define MZNQA_CLASSES_MESSAGE_LOGICMESSAGEPQ_H_

#include <queue>
#include <vector>
#include <functional>
#include "message/Message.h"

// 于逻辑使用的消息队列
class LogicMessagePQ
{
public:
	// 消息枚举
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

	// 获取 EngineMessagePQ 实例
	static LogicMessagePQ* Instance();

	~LogicMessagePQ();

	// 推送消息
	void pushMessage(const Message<LMessage> &lMessage);

	// 获取当前优先级最高的消息
	// 注意：当返回 EMessage_None 表示当前消息队列中无消息
	Message<LMessage> getNextMessage();

	// 判断当前消息队列是否为空
	bool isEmpty();

	// 清空当前消息队列
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