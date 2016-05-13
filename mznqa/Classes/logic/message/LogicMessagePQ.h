/*!
 * \file	Classes\logic\message\LogicMessagePQ.h
 *
 * \brief	定义类 LogicMessagePQ
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_MESSAGE_LOGICMESSAGEPQ_H_
#define MZNQA_CLASSES_LOGIC_MESSAGE_LOGICMESSAGEPQ_H_

#include "common/arkca/message/MessagePQ.h"
#include "common/arkca/message/Message.h"

/*!
 * \class	LogicMessagePQ
 *
 * \brief	[单例]逻辑层消息队列
 *
 */
class LogicMessagePQ
{
public:

	/*!
	 * \fn	LogicMessagePQ::~LogicMessagePQ();
	 *
	 * \brief	析构函数
	 *
	 */
	~LogicMessagePQ();

	/*!
	 * \fn	static LogicMessagePQ* LogicMessagePQ::Instance();
	 *
	 * \brief	获取单例
	 *
	 */
	static LogicMessagePQ* Instance();

	/*!
	 * \enum	LogicMessageID
	 *
	 * \brief	枚举逻辑层的消息ID
	 */
	enum LogicMessageID
	{
		LogicMessageID_ValidID,
		LogicMessageID_FileLoadingFail_String_Zh_Json,
		LogicMessageID_FileLoadingFail_String_En_Json,
		LogicMessageID_FileLoadingFail_String_Set,
		LogicMessageID_FileLoadingFail_Card_Road_Json,
		LogicMessageID_FileLoadingFail_MissionMap_Map_TMissionMapSet__MissionMapIDMainT,
		LogicMessageID_ParsingFail_String_Set,
		LogicMessageID_ParsingFail_CardRoad_Set,
		LogicMessageID_ParsingFail_MissionMap_Map_TMissionMapSet__MissionMapIDMainT,
		LogicMessageID_DataLoadingFail_String_Set,
		LogicMessageID_DataLoadingFail_CardRoad_Set,
		LogicMessageID_DataLoadingFail_MissionMap_Map_TMissionMapSet__MissionMapIDMainT,
		LogicMessageID_FileLoadingSucc_String_Zh_Json,
		LogicMessageID_FileLoadingSucc_String_En_Json,
		LogicMessageID_FileLoadingSucc_Card_Road_Json,
		LogicMessageID_FileLoadingSucc_MissionMap_Map_TMissionMapSet__MissionMapIDMainT,
		LogicMessageID_ParsingSucc_String_Set,
		LogicMessageID_ParsingSucc_CardRoad_Set,
		LogicMessageID_ParsingSucc_MissionMap_Map_TMissionMapSet__MissionMapIDMainT,
		LogicMessageID_DataLoadingSucc_String_Set,
		LogicMessageID_DataLoadingSucc_CardRoad_Set,
		LogicMessageID_DataLoadingSucc_MissionMap_Map_TMissionMapSet__MissionMapIDMainT
	};

	/*!
	 * \fn	void LogicMessagePQ::pushMessage(const ArKCa::Message<LogicMessageID> &message);
	 *
	 * \brief	推送消息到逻辑层的消息队列中
	 *
	 * \param	message	指定待推送的逻辑层消息
	 */
	void pushMessage(const ArKCa::Message<LogicMessageID> &message);

	/*!
	 * \fn	ArKCa::Message<LogicMessageID> LogicMessagePQ::getNextMessage();
	 *
	 * \brief	获取并弹出下一个优先级最高的逻辑层消息
	 *
	 */
	ArKCa::Message<LogicMessageID> getNextMessage();

	/*!
	 * \fn	bool LogicMessagePQ::isEmpty()const;
	 *
	 * \brief	判断逻辑层消息队列是否为空
	 *
	 */
	bool isEmpty()const;

	/*!
	 * \fn	void LogicMessagePQ::clear();
	 *
	 * \brief	清空逻辑层消息队列
	 *
	 */
	void clear();

	/*!
	 * \fn	int LogicMessagePQ::getMessageCount()const;
	 *
	 * \brief	获取当前逻辑层消息队列中的消息总数
	 *
	 */
	int getMessageCount()const;
private:

	/*!
	 * \fn	LogicMessagePQ::LogicMessagePQ();
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	LogicMessagePQ();

	/*!
	 * \fn	LogicMessagePQ::LogicMessagePQ(const LogicMessagePQ &logicMessagePQ);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 */
	LogicMessagePQ(const LogicMessagePQ &logicMessagePQ);

	/*!
	 * \fn	LogicMessagePQ& LogicMessagePQ::operator=(const LogicMessagePQ &logicMessagePQ);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 */
	LogicMessagePQ& operator=(const LogicMessagePQ &logicMessagePQ);

	/*! \brief	内建消息优先队列 */
	ArKCa::MessagePQ<LogicMessageID, LogicMessageID_ValidID> msgPQ;
};

#endif
