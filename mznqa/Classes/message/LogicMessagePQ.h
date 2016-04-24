/*!
 * \file	Classes\message\LogicMessagePQ.h
 *
 * \brief	定义类 LogicMessagePQ
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MESSAGE_LOGICMESSAGEPQ_H_
#define MZNQA_CLASSES_MESSAGE_LOGICMESSAGEPQ_H_

#include <queue>
#include <vector>
#include <functional>
#include "message/Message.h"

/*!
 * \class	LogicMessagePQ
 *
 * \brief	予逻辑层使用的消息队列
 *
 */
class LogicMessagePQ
{
public:

	/*!
	 * \enum	LMessage
	 *
	 * \brief	消息枚举
	 */
	enum LMessage
	{
		LMessage_None = 0,				///< 空消息
		LMessage_RefreshRolePosition,	///< 刷新角色当前的位置
		LMessage_RefreshMapPosition,	///< 刷新地图当前的位置
		LMessage_MapViewMoveUp,			///< 上移地图视野
		LMessage_MapViewMoveRight,		///< 右移地图视野
		LMessage_MapViewMoveDown,		///< 下移地图视野
		LMessage_MapViewMoveLeft		///< 左移地图视野
	};

	/*!
	 * \fn	static LogicMessagePQ* LogicMessagePQ::Instance();
	 *
	 * \brief	获取实例
	 *
	 * \return	返回实例
	 */
	static LogicMessagePQ* Instance();

	/*!
	 * \fn	LogicMessagePQ::~LogicMessagePQ();
	 *
	 * \brief	析构函数
	 *
	 */
	~LogicMessagePQ();

	/*!
	 * \fn	void LogicMessagePQ::pushMessage(const Message<LMessage> &lMessage);
	 *
	 * \brief	向队列中推送消息
	 *
	 * \param	lMessage	一个逻辑消息
	 */
	void pushMessage(const Message<LMessage> &lMessage);

	// 获取当前优先级最高的消息
	// 注意：当返回 EMessage_None 表示当前消息队列中无消息

	/*!
	 * \fn	Message<LMessage> LogicMessagePQ::getNextMessage();
	 *
	 * \brief	获取并从队列中弹出当前优先级最高的消息
	 *
	 * \return	返回当前优先级最高的元素
	 */
	Message<LMessage> getNextMessage();

	/*!
	 * \fn	bool LogicMessagePQ::isEmpty();
	 *
	 * \brief	判断当前队列是否为空
	 *
	 * \return	返回当前队列是否为空
	 */
	bool isEmpty();

	/*!
	 * \fn	void LogicMessagePQ::clear();
	 *
	 * \brief	清空当前消息队列
	 *
	 */
	void clear();

	/*!
	 * \fn	int LogicMessagePQ::getMessageCount()
	 *
	 * \brief	获取当前队列中的消息总数
	 *
	 * \return	返回当前队列中的消息总数
	 */
	int getMessageCount()
	{
		return msgPQ.size();
	}

private:

	/*!
	 * \fn	LogicMessagePQ::LogicMessagePQ()
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	LogicMessagePQ(){}

	/*!
	 * \fn	LogicMessagePQ::LogicMessagePQ(const LogicMessagePQ &logicMessagePQ);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 * \param	logicMessagePQ	LogicMessagePQ 实例
	 */
	LogicMessagePQ(const LogicMessagePQ &logicMessagePQ);

	/*!
	 * \fn	LogicMessagePQ& LogicMessagePQ::operator=(const LogicMessagePQ &logicMessagePQ);
	 *
	 * \brief	隐藏的拷贝复制运算符
	 *
	 * \param	logicMessagePQ	LogicMessagePQ 实例
	 *
	 * \return	返回 LogicMessagePQ 实例
	 */
	LogicMessagePQ& operator=(const LogicMessagePQ &logicMessagePQ);

	/*! \brief	逻辑用消息队列 */
	std::priority_queue<Message<LMessage>, std::vector<Message<LMessage>>, std::greater<Message<LMessage>>> msgPQ;
};

#endif