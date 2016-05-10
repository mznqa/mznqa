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
	 * \fn	static ArKCa::Message<LogicMessagePQ::LogicMessageID> MessageInterpreter::interpret(const ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> &message);
	 *
	 * \brief	��һ����������Ϣת����߼�����Ϣ
	 *
	 * \param	message	ָ����ת���Ľ�������Ϣ
	 *
	 * \return	����ת�����߼�����Ϣ
	 */
	static ArKCa::Message<LogicMessagePQ::LogicMessageID> interpret(const ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> &message);

	/*!
	 * \fn	static ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> MessageInterpreter::interpret(const ArKCa::Message<LogicMessagePQ::LogicMessageID> &message);
	 *
	 * \brief	��һ���߼�����Ϣת��ɽ�������Ϣ
	 *
	 * \param	message	ָ����ת����߼�����Ϣ
	 *
	 * \return	����ת���Ľ�������Ϣ
	 */
	static ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> interpret(const ArKCa::Message<LogicMessagePQ::LogicMessageID> &message);
};

#endif
