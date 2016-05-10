/*!
 * \file	Classes\helper\messageInterpreter\MessageInterpreter.h
 *
 * \brief	定义类 MessageInterpreter
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
 * \brief	用于转译逻辑层和交互层之间的消息
 *
 */
class MessageInterpreter
{
public:

	/*!
	 * \fn	MessageInterpreter::MessageInterpreter();
	 *
	 * \brief	默认构造函数
	 *
	 */
	MessageInterpreter();

	/*!
	 * \fn	MessageInterpreter::~MessageInterpreter();
	 *
	 * \brief	析构函数
	 *
	 */
	~MessageInterpreter();

	/*!
	 * \fn	static ArKCa::Message<LogicMessagePQ::LogicMessageID> MessageInterpreter::interpret(const ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> &message);
	 *
	 * \brief	将一个交互层消息转译成逻辑层消息
	 *
	 * \param	message	指定待转换的交互层消息
	 *
	 * \return	返回转译后的逻辑层消息
	 */
	static ArKCa::Message<LogicMessagePQ::LogicMessageID> interpret(const ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> &message);

	/*!
	 * \fn	static ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> MessageInterpreter::interpret(const ArKCa::Message<LogicMessagePQ::LogicMessageID> &message);
	 *
	 * \brief	将一个逻辑层消息转译成交互层消息
	 *
	 * \param	message	指定待转译的逻辑层消息
	 *
	 * \return	返回转译后的交流层消息
	 */
	static ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> interpret(const ArKCa::Message<LogicMessagePQ::LogicMessageID> &message);
};

#endif
