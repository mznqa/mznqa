/*!
 * \file	Classes\message\MsgInterpreter.h
 *
 * \brief	定义类 MsgInterpreter
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MESSAGE_MSGINTERPRETER_H_
#define MZNQA_CLASSES_MESSAGE_MSGINTERPRETER_H_

#include <map>

#include "message/Message.h"
#include "message/EngineMessagePQ.h"
#include "message/LogicMessagePQ.h"

/*!
 * \class	MsgInterpreter
 *
 * \brief	消息转译器
 *
 */
class MsgInterpreter
{
private:

	/*!
	 * \fn	MsgInterpreter::MsgInterpreter();
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	MsgInterpreter();

	/*!
	 * \fn	MsgInterpreter::MsgInterpreter(const MsgInterpreter &msgInterpreter);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 * \param	msgInterpreter	MsgInterpreter 实例
	 */
	MsgInterpreter(const MsgInterpreter &msgInterpreter);

	/*!
	 * \fn	MsgInterpreter& MsgInterpreter::operator=(const MsgInterpreter &msgInterpreter);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 * \param	msgInterpreter	MsgInterpreter 实例
	 *
	 * \return	返回 MsgInterpreter 实例
	 */
	MsgInterpreter& operator=(const MsgInterpreter &msgInterpreter);

	// 单例别名 //////////////////////////////////////////////////////////////////////////
	/*! \brief	保存 EngineMessagePQ::Instancet() 的常量指针 */
	EngineMessagePQ *EngineMessagePQInstance;
	/*! \brief	保存 LogicMessagePQ::Instance() 的常量指针 */
	LogicMessagePQ *LogicMessagePQInstance;
	//////////////////////////////////////////////////////////////////////////

	/*! \brief	消息映射表：引擎消息->逻辑消息 */
	std::map<EngineMessagePQ::EMessage, LogicMessagePQ::LMessage> msgMap;
public:

	/*!
	 * \fn	static MsgInterpreter* MsgInterpreter::Instance();
	 *
	 * \brief	获取单例
	 *
	 * \return	返回单例
	 */
	static MsgInterpreter* Instance();

	/*!
	 * \fn	MsgInterpreter::~MsgInterpreter();
	 *
	 * \brief	析构函数
	 *
	 */
	~MsgInterpreter();

	/*!
	 * \fn	Message<LogicMessagePQ::LMessage> MsgInterpreter::translation(const Message<EngineMessagePQ::EMessage> &eMessage);
	 *
	 * \brief	将引擎消息转译成逻辑消息
	 *
	 * \param	eMessage	指定引擎消息
	 *
	 * \return	返回转译后的逻辑消息
	 */
	Message<LogicMessagePQ::LMessage> translation(const Message<EngineMessagePQ::EMessage> &eMessage);
};

#endif