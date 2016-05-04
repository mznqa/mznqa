/*!
* \file	Classes\common\arkca\message\MessagePQ.cpp
*
* \brief	定义类 ArKCa::MessagePQ
*/

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMMON_ARKCA_MESSAGE_MESSAGEPQ_H_
#define MZNQA_CLASSES_COMMON_ARKCA_MESSAGE_MESSAGEPQ_H_

#include <queue>
#include <vector>
#include <functional>
#include "common/arkca/message/Message.h"

namespace ArKCa
{
	/*!
	 * \class	MessagePQ
	 *
	 * \brief	消息优先队列
	 *
	 * \tparam	MessageIDType	消息ID的类型
	 * \tparam	validID		 	指定无效ID
	 */
	template <typename MessageIDType, MessageIDType InvalidMessageID>
	class MessagePQ
	{
	private:

		/*!
		* \fn	MessagePQ(const MessagePQ &messagePQ);
		*
		* \brief	隐藏的拷贝构造函数
		*
		*/
		MessagePQ(const MessagePQ &messagePQ);

		/*!
		* \fn	MessagePQ& operator=(const MessagePQ &messagePQ);
		*
		* \brief	隐藏的拷贝赋值运算符
		*
		*/
		MessagePQ& operator=(const MessagePQ &messagePQ);

		/*! \brief	无效消息ID */
		const MessageIDType InvalidID = InvalidMessageID;

		/*! \brief	内部消息队列 */
		std::priority_queue<
			Message<MessageIDType>,
			std::vector<Message<MessageIDType>>,
			std::less<Message<MessageIDType>>
		> msgPQ;

	public:

		/*!
		* \fn	MessagePQ()
		*
		* \brief	默认构造函数
		*
		*/
		MessagePQ()
		{
		}

		/*!
		* \fn	~MessagePQ()
		*
		* \brief	析构函数
		*
		*/
		~MessagePQ()
		{
		}

		/*!
		* \fn	void pushMessage(const Message<MessageIDType> &message);
		*
		* \brief	向消息队列中推送消息
		*
		* \param	message	指定待推送的消息
		*/
		void pushMessage(const Message<MessageIDType> &message)
		{
			if (message.getID == InvalidID)
				return;

			msgPQ.push(message);
		}

		/*!
		* \fn	Message<MessageIDType> getNextMessage();
		*
		* \brief	获取并弹出下一个优先级最高的消息
		*
		*/
		Message<MessageIDType> getNextMessage()
		{
			if (msgPQ.empty())
				return Message<MessageIDType>(InvalidID);

			Message<MessageIDType>  msg = msgPQ.top();
			msgPQ.pop();
			return msg;
		}

		/*!
		* \fn	bool isEmpty()const;
		*
		* \brief	判断消息队列是否为空
		*
		*/
		bool isEmpty()const
		{
			return msgPQ.empty();
		}

		/*!
		* \fn	void clear();
		*
		* \brief	清空消息队列
		*
		*/
		void clear()
		{
			while (msgPQ.empty() == false)
			{
				msgPQ.pop();
			}
		}

		/*!
		* \fn	int getMessageCount()const;
		*
		* \brief	获取当前消息总数
		*
		*/
		int getMessageCount()const
		{
			return msgPQ.size();
		}
	};
}

#endif