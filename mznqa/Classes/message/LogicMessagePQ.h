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
	// 消息枚举
	enum LMessage
	{
		EMessage_None = 0,
		// TODO 加入实际消息枚举
	};

	// 获取 EngineMessagePQ 实例
	static LogicMessagePQ* Instance();

	~LogicMessagePQ();

	// 推送消息
	void pushMessage(const Message &lMessage);

	// 获取当前优先级最高的消息
	// 注意：当返回 EMessage_None 表示当前消息队列中无消息
	Message getNextMessage();

	// 判断当前消息队列是否为空
	bool isEmpty();

	// 清空当前消息队列
	void clear();
};

#endif