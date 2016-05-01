/*!
 * \file	Classes\message\EngineMessagePQ.h
 *
 * \brief	定义类 EngineMessagePQ
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MESSAGE_ENGINEMESSAGEPQ_H_
#define MZNQA_CLASSES_MESSAGE_ENGINEMESSAGEPQ_H_

#include <queue>
#include <vector>
#include <functional>
#include "message/Message.h"

/*!
 * \class	EngineMessagePQ
 *
 * \brief	予引擎使用的消息队列
 *
 */
class EngineMessagePQ
{
public:

	/*!
	 * \enum	EMessage
	 *
	 * \brief	消息枚举
	 */
	enum EMessage
	{
		EMessage_None = 0,			///< 空消息
		EMessage_MapMoveUp = 1,		///< 上移地图
		EMessage_MapMoveRight = 2,	///< 右移地图
		EMessage_MapMoveDown = 3,	///< 下移地图
		EMessage_MapMoveLeft = 4,	///< 左移地图

		EMessage_RemoveHandCardByIndex_TIntT = 100,	///< 从手牌中移除指定卡
		EMessage_PutCardRoad_TGXYT = 101,			///< 放置地形卡

		EMessage_SpriteCard_TouchEvent_TouchBegan_TSpriteCardEventIndexT = 200,		///< 卡片触摸事件-began
		EMessage_SpriteCard_TouchEvent_TouchMoved_TSpriteCardEventIndexT = 201,		///< 卡片触摸事件-moved
		EMessage_SpriteCard_TouchEvent_TouchEnded_TSpriteCardEventIndexT = 202,		///< 卡片触摸事件-ended

		EMessage_SpriteHandCard_TouchEvent_TouchBegan_TSpriteHandCardEventIndexT = 300,		///< 手牌触摸事件-began
		EMessage_SpriteHandCard_TouchEvent_TouchMoved_TSpriteHandCardEventIndexT = 301,		///< 手牌触摸事件-moved
		EMessage_SpriteHandCard_TouchEvent_TouchEnded_TSpriteHandCardEventIndexT = 302,		///< 手牌触摸事件-ended

		EMessage_Information_DataLoading_StaticData_MapMainMissionSetLoadSuccess = 400,	///< 成功载入静态数据：主线任务地图集合
		EMessage_Information_DataLoading_StaticData_CardSkillSetLoadSuccess = 401,		///< 成功载入静态数据：技能卡集合
		EMessage_Information_DataLoading_StaticData_CardRoadSetLoadSuccess = 402,		///< 成功载入静态数据：地形卡集合

		EMessage_Error_DataLoading_StaticData_CardMapMainMissionSetSetLoadFailed = 500,	///< 载入静态数据时出错：地形卡集合
		EMessage_Error_DataLoading_StaticData_CardSkillSetLoadFailed = 501,				///< 载入静态数据时出错：地形卡集合
		EMessage_Error_DataLoading_StaticData_CardRoadSetLoadFailed = 502				///< 载入静态数据时出错：地形卡集合
	};

	/*!
	 * \fn	static EngineMessagePQ* EngineMessagePQ::Instance();
	 *
	 * \brief	获取实例
	 *
	 * \return	返回实例
	 */
	static EngineMessagePQ* Instance();

	/*!
	 * \fn	EngineMessagePQ::~EngineMessagePQ();
	 *
	 * \brief	析构函数
	 *
	 */
	~EngineMessagePQ();

	/*!
	 * \fn	void EngineMessagePQ::pushMessage(const Message<EMessage> &eMessage);
	 *
	 * \brief	向队列中推送一个引擎消息
	 *
	 * \param	eMessage	指定待推送的引擎消息
	 */
	void pushMessage(const Message<EMessage> &eMessage);

	/*!
	 * \fn	Message<EMessage> EngineMessagePQ::getNextMessage();
	 *
	 * \brief	获取并从队列中弹出当前优先级最高的消息
	 *
	 * \return	返回并从队列中弹出当前优先级最高的消息
	 */
	Message<EMessage> getNextMessage();

	/*!
	 * \fn	bool EngineMessagePQ::isEmpty();
	 *
	 * \brief	判断当前消息队列是否为空
	 *
	 * \return	返回当前消息队列是否为空
	 */
	bool isEmpty();

	/*!
	 * \fn	void EngineMessagePQ::clear();
	 *
	 * \brief	清空当前消息队列
	 *
	 */
	void clear();

	/*!
	 * \fn	int EngineMessagePQ::getMessageCount()
	 *
	 * \brief	获取队列中当前消息总数
	 *
	 * \return	返回队列中当前消息总数
	 */
	int getMessageCount()
	{
		return msgPQ.size();
	}

private:

	/*!
	 * \fn	EngineMessagePQ::EngineMessagePQ()
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	EngineMessagePQ(){}

	/*!
	 * \fn	EngineMessagePQ::EngineMessagePQ(const EngineMessagePQ &engineMessagePQ);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 * \param	engineMessagePQ	指定 EngineMessagePQ 实例
	 */
	EngineMessagePQ(const EngineMessagePQ &engineMessagePQ);

	/*!
	 * \fn	EngineMessagePQ& EngineMessagePQ::operator=(const EngineMessagePQ &engineMessagePQ);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 * \param	engineMessagePQ	指定 EngineMessagePQ 实例
	 *
	 * \return	返回 EngineMessagePQ 实例
	 */
	EngineMessagePQ& operator=(const EngineMessagePQ &engineMessagePQ);

	/*! \brief	引擎用消息队列 */
	std::priority_queue<Message<EMessage>, std::vector<Message<EMessage>>, std::less<Message<EMessage>>> msgPQ;
};

#endif