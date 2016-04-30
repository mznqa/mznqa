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
		LMessage_MapViewMoveLeft,		///< 左移地图视野

		LMessage_SpriteCard_TouchEvent_TouchBegan_TSpriteCardEventIndexT = 100,		///< 卡片触摸事件-began
		LMessage_SpriteCard_TouchEvent_TouchMoved_TSpriteCardEventIndexT = 101,		///< 卡片触摸事件-moved
		LMessage_SpriteCard_TouchEvent_TouchEnded_TSpriteCardEventIndexT = 102,		///< 卡片触摸事件-ended

		LMessage_SpriteHandCard_TouchEvent_TouchBegan_TSpriteHandCardEventIndexT = 200,		///< 手牌触摸事件-began
		LMessage_SpriteHandCard_TouchEvent_TouchMoved_TSpriteHandCardEventIndexT = 201,		///< 手牌触摸事件-moved
		LMessage_SpriteHandCard_TouchEvent_TouchEnded_TSpriteHandCardEventIndexT = 202,		///< 手牌触摸事件-ended

		LMessage_RefreshMapCellSpriteByGPointSet_TGPointSetT = 300,	///< 刷新地图上指定矩形区域的图片

		LMessage_ReplaceScene_SceneLoadRes2SceneGameMain = 400,	///< 跳转场景：从 SceneLoadRes 跳转到 SceneGameMain

		LMessage_LoadData_StaticData_MapMainMissionSet = 500,	///< 开始载入地形卡集合
		LMessage_LoadData_StaticData_CardSkillSet = 501,		///< 开始载入技能卡集合
		LMessage_LoadData_StaticData_CardRoadSet = 502,			///< 开始载入地形卡集合

		LMessage_Information_DataLoading_StaticData_MapMainMissionSetLoadSuccess = 600,	///< 成功载入静态数据：主线任务地图集合
		LMessage_Information_DataLoading_StaticData_CardSkillSetLoadSuccess = 601,		///< 成功载入静态数据：技能卡集合
		LMessage_Information_DataLoading_StaticData_CardRoadSetLoadSuccess = 602,		///< 成功载入静态数据：地形卡集合

		LMessage_Error_DataLoading_StaticData_CardMapMainMissionSetSetLoadFailed = 700,	///< 载入静态数据时出错：地形卡集合
		LMessage_Error_DataLoading_StaticData_CardSkillSetLoadFailed = 701,				///< 载入静态数据时出错：地形卡集合
		LMessage_Error_DataLoading_StaticData_CardRoadSetLoadFailed = 702				///< 载入静态数据时出错：地形卡集合
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
	std::priority_queue<Message<LMessage>, std::vector<Message<LMessage>>, std::less<Message<LMessage>>> msgPQ;
};

#endif