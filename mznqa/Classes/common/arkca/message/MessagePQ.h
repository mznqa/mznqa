/*!
* \file	Classes\common\arkca\message\MessagePQ.cpp
*
* \brief	������ ArKCa::MessagePQ
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
	 * \brief	��Ϣ���ȶ���
	 *
	 * \tparam	MessageIDType	��ϢID������
	 * \tparam	validID		 	ָ����ЧID
	 */
	template <typename MessageIDType, MessageIDType InvalidMessageID>
	class MessagePQ
	{
	private:

		/*!
		* \fn	MessagePQ(const MessagePQ &messagePQ);
		*
		* \brief	���صĿ������캯��
		*
		*/
		MessagePQ(const MessagePQ &messagePQ);

		/*!
		* \fn	MessagePQ& operator=(const MessagePQ &messagePQ);
		*
		* \brief	���صĿ�����ֵ�����
		*
		*/
		MessagePQ& operator=(const MessagePQ &messagePQ);

		/*! \brief	��Ч��ϢID */
		const MessageIDType InvalidID = InvalidMessageID;

		/*! \brief	�ڲ���Ϣ���� */
		std::priority_queue<
			Message<MessageIDType>,
			std::vector<Message<MessageIDType>>,
			std::less<Message<MessageIDType>>
		> msgPQ;

	public:

		/*!
		* \fn	MessagePQ()
		*
		* \brief	Ĭ�Ϲ��캯��
		*
		*/
		MessagePQ()
		{
		}

		/*!
		* \fn	~MessagePQ()
		*
		* \brief	��������
		*
		*/
		~MessagePQ()
		{
		}

		/*!
		* \fn	void pushMessage(const Message<MessageIDType> &message);
		*
		* \brief	����Ϣ������������Ϣ
		*
		* \param	message	ָ�������͵���Ϣ
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
		* \brief	��ȡ��������һ�����ȼ���ߵ���Ϣ
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
		* \brief	�ж���Ϣ�����Ƿ�Ϊ��
		*
		*/
		bool isEmpty()const
		{
			return msgPQ.empty();
		}

		/*!
		* \fn	void clear();
		*
		* \brief	�����Ϣ����
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
		* \brief	��ȡ��ǰ��Ϣ����
		*
		*/
		int getMessageCount()const
		{
			return msgPQ.size();
		}
	};
}

#endif