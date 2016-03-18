#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MESSAGE_MESSAGE_H_
#define MZNQA_CLASSES_MESSAGE_MESSAGE_H_

// ��Ϣ�ṹ��
struct Message
{
	// ��ϢID������Ӧ����Ϣö��
	int messageID;
	// ���⸽����Ϣ
	void *extras;

	Message(int messageID, void *extras = nullptr)
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