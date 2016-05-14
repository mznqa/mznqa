/*!
 * \file	Classes\helper\messageInterpreter\MessageInterpreter.h
 *
 * \brief	������ MessageInterpreter
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_HELPER_MESSAGEINTERPRETER_MESSAGEINTERPRETER_H_
#define MZNQA_CLASSES_HELPER_MESSAGEINTERPRETER_MESSAGEINTERPRETER_H_

#include "common/arkca/message/Message.h"
#include "logic/message/LogicMessagePQ.h"
#include "interactive/message/InteractiveMessagePQ.h"

/*!
 * \class	MessageInterpreter
 *
 * \brief	����ת���߼���ͽ�����֮�����Ϣ
 *
 */
class MessageInterpreter
{
public:

	/*!
	 * \fn	MessageInterpreter::MessageInterpreter();
	 *
	 * \brief	Ĭ�Ϲ��캯��
	 *
	 */
	MessageInterpreter();

	/*!
	 * \fn	MessageInterpreter::~MessageInterpreter();
	 *
	 * \brief	��������
	 *
	 */
	~MessageInterpreter();

	/*!
	 * \fn	static ArKCa::Message<LogicMessagePQ::LogicMessageID> MessageInterpreter::interpret(InteractiveMessagePQ::InteractiveMessageID messageID);
	 *
	 * \brief	ת��һ����������ϢΪ�߼�����Ϣ
	 *
	 * \param	messageID	ָ��һ����������ϢID
	 *
	 * \return	����һ���߼�����Ϣ
	 */
	static ArKCa::Message<LogicMessagePQ::LogicMessageID> interpret(InteractiveMessagePQ::InteractiveMessageID messageID);

	/*!
	 * \fn	template<typename ExtrasType> static ArKCa::Message<LogicMessagePQ::LogicMessageID> MessageInterpreter::interpret(InteractiveMessagePQ::InteractiveMessageID messageID, const ExtrasType &extras)
	 *
	 * \brief	ת��һ����������ϢΪ�߼�����Ϣ
	 *
	 * \param	messageID	ָ��һ����������ϢID
	 * \param	extras   	ָ������ֵ
	 *
	 * \return	����һ���߼�����Ϣ
	 */
	template<typename ExtrasType>
	static ArKCa::Message<LogicMessagePQ::LogicMessageID> interpret(InteractiveMessagePQ::InteractiveMessageID messageID, const ExtrasType &extras)
	{
		ArKCa::Message<LogicMessagePQ::LogicMessageID> message(interpret(messageID).getID(), extras);
		return message;
	}

	/*!
	 * \fn	static ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> MessageInterpreter::interpret(LogicMessagePQ::LogicMessageID messageID);
	 *
	 * \brief	ת��һ���߼�����ϢΪ��������Ϣ
	 *
	 * \param	messageID	ָ��һ���߼�����ϢID
	 *
	 * \return	����һ����������Ϣ
	 */
	static ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> interpret(LogicMessagePQ::LogicMessageID messageID);

	/*!
	 * \fn	template<typename ExtrasType> static ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> MessageInterpreter::interpret(LogicMessagePQ::LogicMessageID messageID, const ExtrasType &extras)
	 *
	 * \brief	ת��һ���߼�����ϢΪ��������Ϣ
	 *
	 * \param	messageID	ָ��һ���߼�����Ϣ
	 * \param	extras   	ָ��һ������ֵ
	 *
	 * \return	����һ����������Ϣ
	 */
	template<typename ExtrasType>
	static ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> interpret(LogicMessagePQ::LogicMessageID messageID, const ExtrasType &extras)
	{
		ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> message(interpret(messageID).getID(), extras);
		return message;
	}
};

#endif
