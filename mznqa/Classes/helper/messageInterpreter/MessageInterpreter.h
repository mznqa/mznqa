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
	 * \fn	static ArKCa::Message<LogicMessagePQ::LogicMessageID> MessageInterpreter::interpret(InteractiveMessagePQ::InteractiveMessageID messageID);
	 *
	 * \brief	转译一个交互层消息为逻辑层消息
	 *
	 * \param	messageID	指定一个交互层消息ID
	 *
	 * \return	返回一个逻辑层消息
	 */
	static ArKCa::Message<LogicMessagePQ::LogicMessageID> interpret(InteractiveMessagePQ::InteractiveMessageID messageID);

	/*!
	 * \fn	template<typename ExtrasType> static ArKCa::Message<LogicMessagePQ::LogicMessageID> MessageInterpreter::interpret(InteractiveMessagePQ::InteractiveMessageID messageID, const ExtrasType &extras)
	 *
	 * \brief	转译一个交互层消息为逻辑层消息
	 *
	 * \param	messageID	指定一个交互层消息ID
	 * \param	extras   	指定附加值
	 *
	 * \return	返回一个逻辑层消息
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
	 * \brief	转译一个逻辑层消息为交互层消息
	 *
	 * \param	messageID	指定一个逻辑层消息ID
	 *
	 * \return	返回一个交互层消息
	 */
	static ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> interpret(LogicMessagePQ::LogicMessageID messageID);

	/*!
	 * \fn	template<typename ExtrasType> static ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> MessageInterpreter::interpret(LogicMessagePQ::LogicMessageID messageID, const ExtrasType &extras)
	 *
	 * \brief	转译一个逻辑层消息为交互层消息
	 *
	 * \param	messageID	指定一个逻辑层消息
	 * \param	extras   	指定一个附加值
	 *
	 * \return	返回一个交互层消息
	 */
	template<typename ExtrasType>
	static ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> interpret(LogicMessagePQ::LogicMessageID messageID, const ExtrasType &extras)
	{
		ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> message(interpret(messageID).getID(), extras);
		return message;
	}
};

#endif
