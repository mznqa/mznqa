/*!
 * \file	Classes\message\Message.h
 *
 * \brief	����ṹ�� Message
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MESSAGE_MESSAGE_H_
#define MZNQA_CLASSES_MESSAGE_MESSAGE_H_

/*!
 * \struct	Message
 *
 * \brief	��Ϣ�ṹ��
 *
 * \tparam	MessageIDType	ָ������ϢID������
 */

template<typename MessageIDType>
struct Message
{
	/*! \brief	��Ϣ��ΨһID������������Ϣ����Ϣ�����е��������� */
	MessageIDType messageID;
	/*! \brief	���⸽����Ϣ */
	void *extras;

	/*!
	 * \fn	Message(MessageIDType messageID, void *extras = nullptr)
	 *
	 * \brief	���캯��
	 *
	 * \param	messageID	  	ָ����Ϣ��ID
	 * \param [in,out]	extras	(Optional) ���⸽����Ϣ
	 */
	Message(MessageIDType messageID, void *extras = nullptr)
	{
		this->messageID = messageID;
		this->extras = extras;
	}

	/*!
	 * \fn	bool operator<(const Message &rhs) const
	 *
	 * \brief	< �����
	 *
	 * \param	rhs	Message ʵ��
	 *
	 * \return	���رȽϽ��
	 */
	bool operator<(const Message &rhs) const
	{
		return this->messageID < rhs.messageID;
	}

	/*!
	 * \fn	bool operator>(const Message &rhs) const
	 *
	 * \brief	> �����
	 *
	 * \param	rhs	Message ʵ��
	 *
	 * \return	���رȽϽ��
	 */
	bool operator>(const Message &rhs) const
	{
		return this->messageID > rhs.messageID;
	}
};

#endif