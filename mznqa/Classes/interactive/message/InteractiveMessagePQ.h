/*!
 * \file	Classes\interactive\message\InteractiveMessagePQ.h
 *
 * \brief	������ InteractiveMessagePQ
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_MESSAGE_INTERACTIVEMESSAGEPQ_H_
#define MZNQA_CLASSES_INTERACTIVE_MESSAGE_INTERACTIVEMESSAGEPQ_H_

#include "common/arkca/message/MessagePQ.h"
#include "common/arkca/message/Message.h"

/*!
 * \class	InteractiveMessagePQ
 *
 * \brief	���������Ϣ����
 *
 */
class InteractiveMessagePQ
{
public:

	/*!
	 * \fn	InteractiveMessagePQ::~InteractiveMessagePQ();
	 *
	 * \brief	��������
	 *
	 */
	~InteractiveMessagePQ();

	/*!
	 * \fn	static InteractiveMessagePQ* InteractiveMessagePQ::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 */
	static InteractiveMessagePQ* Instance();

	/*!
	 * \enum	InteractiveMessageID
	 *
	 * \brief	ö�ٽ��������ϢID
	 */
	enum InteractiveMessageID
	{
		InteractiveMessageID_ValidID
	};

	/*!
	 * \fn	void InteractiveMessagePQ::pushMessage(const ArKCa::Message<InteractiveMessageID> &message);
	 *
	 * \brief	������Ϣ��������
	 *
	 * \param	message	ָ��һ�������͵Ľ�������Ϣ
	 */
	void pushMessage(const ArKCa::Message<InteractiveMessageID> &message);

	/*!
	 * \fn	ArKCa::Message<InteractiveMessageID> InteractiveMessagePQ::getNextMessage();
	 *
	 * \brief	��ȡ��������һ�����ȼ���ߵĽ�������Ϣ
	 *
	 */
	ArKCa::Message<InteractiveMessageID> getNextMessage();

	/*!
	 * \fn	bool InteractiveMessagePQ::isEmpty()const;
	 *
	 * \brief	�жϵ�ǰ���������Ϣ�����Ƿ�Ϊ��
	 *
	 */
	bool isEmpty()const;

	/*!
	 * \fn	void InteractiveMessagePQ::clear();
	 *
	 * \brief	��ս��������Ϣ����
	 *
	 */
	void clear();

	/*!
	 * \fn	int InteractiveMessagePQ::getMessageCount()const;
	 *
	 * \brief	��ȡ��ǰ���������Ϣ�����е���Ϣ����
	 *
	 */
	int getMessageCount()const;
private:

	/*!
	 * \fn	InteractiveMessagePQ::InteractiveMessagePQ();
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	InteractiveMessagePQ();

	/*!
	 * \fn	InteractiveMessagePQ::InteractiveMessagePQ(const InteractiveMessagePQ &interactiveMessagePQ);
	 *
	 * \brief	���صĿ������캯��
	 *
	 */
	InteractiveMessagePQ(const InteractiveMessagePQ &interactiveMessagePQ);

	/*!
	 * \fn	InteractiveMessagePQ& InteractiveMessagePQ::operator=(const InteractiveMessagePQ &interactiveMessagePQ);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	InteractiveMessagePQ& operator=(const InteractiveMessagePQ &interactiveMessagePQ);

	/*! \brief	�ڽ���Ϣ���ȶ��� */
	ArKCa::MessagePQ<InteractiveMessageID, InteractiveMessageID_ValidID> msgPQ;
};

#endif
