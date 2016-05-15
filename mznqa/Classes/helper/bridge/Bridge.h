/*!
 * \file	Classes\helper\bridge\Bridge.h
 *
 * \brief	定义类 Bridge
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_HELPER_BRIDGE_BRIDGE_H_
#define MZNQA_CLASSES_HELPER_BRIDGE_BRIDGE_H_

#include "common/arkca/message/Message.h"
#include "logic/message/LogicMessagePQ.h"
#include "interactive/message/InteractiveMessagePQ.h"
#include "interactive/manager/TargetInfo.h"
#include "logic/core/CoreController.h"
#include "helper/messageInterpreter/MessageInterpreter.h"

/*!
 * \class	Bridge
 *
 * \brief	[单例]用于逻辑层和交互层之间的交流
 *
 */
class Bridge
{
private:

	/*!
	 * \fn	Bridge::Bridge();
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	Bridge();

	/*!
	 * \fn	Bridge::Bridge(const Bridge &bridge);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 */
	Bridge(const Bridge &bridge);

	/*!
	 * \fn	Bridge& Bridge::operator=(const Bridge &bridge);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 */
	Bridge& operator=(const Bridge &bridge);

	// 单例别名 //////////////////////////////////////////////////////////////////////////
	/*! \brief	LogicMessagePQ 单例别名 */
	LogicMessagePQ *const LogicMessagePQInstance = LogicMessagePQ::Instance();
	/*! \brief	InteractiveMessagePQ 单例别名 */
	InteractiveMessagePQ *const InteractiveMessagePQInstance = InteractiveMessagePQ::Instance();
	/*! \brief	TargetInfo 单例别名 */
	TargetInfo *const TargetInfoInstance = TargetInfo::Instance();
	/*! \brief	Controller 单例别名 */
	CoreController *const CoreControllerInstance = CoreController::Instance();
	//////////////////////////////////////////////////////////////////////////

public:

	/*!
	 * \fn	Bridge::~Bridge();
	 *
	 * \brief	析构函数
	 *
	 */
	~Bridge();

	/*!
	 * \fn	static Bridge* Bridge::Instance();
	 *
	 * \brief	获取单例
	 *
	 */
	static Bridge* Instance();

	/*!
	* \enum	Language
	*
	* \brief	枚举游戏中的语言
	*/
	enum Language
	{
		Language_Zh,	///< 中文
		Language_En		///< 英文
	};

	/*!
	 * \fn	bool Bridge::update(double intervalTime);
	 *
	 * \brief	用于驱动逻辑层
	 *
	 * \param	intervalTime	自上次调用以来所经历的时间
	 *
	 * \return	返回执行成功与否
	 */
	bool update(double intervalTime);

	/*!
	 * \fn	void Bridge::pushMessage2Logic(InteractiveMessagePQ::InteractiveMessageID messageID);
	 *
	 * \brief	推送消息到逻辑层
	 *
	 * \param	messageID	指定一个交互层消息ID
	 */
	void pushMessage2Logic(InteractiveMessagePQ::InteractiveMessageID messageID);

	/*!
	 * \fn	template <typename ExtrasType> void Bridge::pushMessage2Logic(InteractiveMessagePQ::InteractiveMessageID messageID, const ExtrasType &extras)
	 *
	 * \brief	推送消息到逻辑层
	 *
	 * \param	messageID	指定一个交互层消息ID
	 * \param	extras   	指定一个附加值
	 */
	template <typename ExtrasType>
	void pushMessage2Logic(InteractiveMessagePQ::InteractiveMessageID messageID, const ExtrasType &extras)
	{
		LogicMessagePQInstance->pushMessage(MessageInterpreter::interpret(messageID, extras));
	}

	/*!
	 * \fn	void Bridge::pushMessage2Interactive(LogicMessagePQ::LogicMessageID messageID);
	 *
	 * \brief	推送消息到交互层
	 *
	 * \param	messageID	指定一个逻辑层消息ID
	 */
	void pushMessage2Interactive(LogicMessagePQ::LogicMessageID messageID);

	/*!
	 * \fn	template <typename ExtrasType> void Bridge::pushMessage2Interactive(LogicMessagePQ::LogicMessageID messageID, const ExtrasType &extras)
	 *
	 * \brief	推送消息到交互层
	 *
	 * \param	messageID	指定一个逻辑层消息ID
	 * \param	extras	  	指定一个附加值
	 */
	template <typename ExtrasType>
	void pushMessage2Interactive(LogicMessagePQ::LogicMessageID messageID, const ExtrasType &extras)
	{
		InteractiveMessagePQInstance->pushMessage(MessageInterpreter::interpret(messageID, extras));
	}

	/*!
	 * \fn	Language Bridge::getLanguage()
	 *
	 * \brief	获取游戏中使用的语言
	 *
	 */
	Language getLanguage()
	{
		if (TargetInfoInstance->getLanguage() == TargetInfo::Language_Zh)
			return Language_Zh;
		else if (TargetInfoInstance->getLanguage() == TargetInfo::Language_En)
			return Language_En;
		else
			return Language_Zh;
	}
};

#endif
