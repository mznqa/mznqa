/*!
 * \file	Classes\interactive\message\InteractiveMessagePQ.h
 *
 * \brief	定义类 InteractiveMessagePQ
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_MESSAGE_INTERACTIVEMESSAGEPQ_H_
#define MZNQA_CLASSES_INTERACTIVE_MESSAGE_INTERACTIVEMESSAGEPQ_H_

#include "common/arkca/message/MessagePQ.h"
#include "common/arkca/message/Message.h"

/*!
 * \class	InteractiveMessagePQ
 *
 * \brief	[单例]交互层的消息队列
 *
 */
class InteractiveMessagePQ
{
public:

	/*!
	 * \fn	InteractiveMessagePQ::~InteractiveMessagePQ();
	 *
	 * \brief	析构函数
	 *
	 */
	~InteractiveMessagePQ();

	/*!
	 * \fn	static InteractiveMessagePQ* InteractiveMessagePQ::Instance();
	 *
	 * \brief	获取单例
	 *
	 */
	static InteractiveMessagePQ* Instance();

	/*!
	 * \enum	InteractiveMessageID
	 *
	 * \brief	枚举交互层的消息ID
	 */
	enum InteractiveMessageID
	{
		InteractiveMessageID_ValidID,
		InteractiveMessageID_ChangeScene_SceneGuide_SceneResLoading,
		InteractiveMessageID_ChangeScene_SceneResLoading_SceneGameMain,
		InteractiveMessageID_OP_DragMap_Up,
		InteractiveMessageID_OP_DragMap_Right,
		InteractiveMessageID_OP_DragMap_Down,
		InteractiveMessageID_OP_DragMap_Left,
		InteractiveMessageID_Update_LayerMapPosition,
		InteractiveMessageID_ButtonClicked_Explore_DrawCard,
		InteractiveMessageID_Explore_PutCard_Road_TintT,
		InteractiveMessageID_Explore_PutCardFail_Road_CardPollEmpty,
		InteractiveMessageID_Explore_PutCardFail_Road_HandCardFull,
		InteractiveMessageID_OP_ClickHandCard_AtLayerWorkbench_TintT
	};

	/*!
	 * \fn	void InteractiveMessagePQ::pushMessage(const ArKCa::Message<InteractiveMessageID> &message);
	 *
	 * \brief	推送消息到交互层
	 *
	 * \param	message	指定一个待推送的交互层消息
	 */
	void pushMessage(const ArKCa::Message<InteractiveMessageID> &message);

	/*!
	 * \fn	const ArKCa::Message<InteractiveMessageID> * const InteractiveMessagePQ::getTopMessage()const;
	 *
	 * \brief	获取优先级最高的交互层消息
	 *
	 */
	const ArKCa::Message<InteractiveMessageID> *const getTopMessage()const;

	/*!
	 * \fn	void InteractiveMessagePQ::popTopMessage()
	 *
	 * \brief	弹出优先级最高的交互层消息
	 *
	 */
	void popTopMessage()
	{
		msgPQ.popTopMessage();
	}

	/*!
	 * \fn	bool InteractiveMessagePQ::isEmpty()const;
	 *
	 * \brief	判断当前交互层的消息队列是否为空
	 *
	 */
	bool isEmpty()const;

	/*!
	 * \fn	void InteractiveMessagePQ::clear();
	 *
	 * \brief	清空交互层的消息队列
	 *
	 */
	void clear();

	/*!
	 * \fn	int InteractiveMessagePQ::getMessageCount()const;
	 *
	 * \brief	获取当前交互层的消息队列中的消息总数
	 *
	 */
	int getMessageCount()const;
private:

	/*!
	 * \fn	InteractiveMessagePQ::InteractiveMessagePQ();
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	InteractiveMessagePQ();

	/*!
	 * \fn	InteractiveMessagePQ::InteractiveMessagePQ(const InteractiveMessagePQ &interactiveMessagePQ);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 */
	InteractiveMessagePQ(const InteractiveMessagePQ &interactiveMessagePQ);

	/*!
	 * \fn	InteractiveMessagePQ& InteractiveMessagePQ::operator=(const InteractiveMessagePQ &interactiveMessagePQ);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 */
	InteractiveMessagePQ& operator=(const InteractiveMessagePQ &interactiveMessagePQ);

	/*! \brief	内建消息优先队列 */
	ArKCa::MessagePQ<InteractiveMessageID, InteractiveMessageID_ValidID> msgPQ;
};

#endif
