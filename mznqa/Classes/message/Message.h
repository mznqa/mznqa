#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MESSAGE_MESSAGE_H_
#define MZNQA_CLASSES_MESSAGE_MESSAGE_H_

// 消息结构体
template<typename MessageIDType>
struct Message
{
	// 消息ID，即对应的消息枚举
	MessageIDType messageID;
	// 任意附加信息
	void *extras;

	Message(MessageIDType messageID, void *extras = nullptr)
	{
		this->messageID = messageID;
		this->extras = extras;
	}

	bool operator<(const Message &rhs) const
	{
		return this->messageID < rhs.messageID;
	}

	bool operator>(const Message &rhs) const
	{
		return this->messageID > rhs.messageID;
	}
};

#endif