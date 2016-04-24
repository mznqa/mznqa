/*!
 * \file	Classes\message\Message.h
 *
 * \brief	定义结构体 Message
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MESSAGE_MESSAGE_H_
#define MZNQA_CLASSES_MESSAGE_MESSAGE_H_

/*!
 * \struct	Message
 *
 * \brief	消息结构体
 *
 * \tparam	MessageIDType	指定的消息ID的类型
 */

template<typename MessageIDType>
struct Message
{
	/*! \brief	消息的唯一ID，用于区分消息和消息队列中的排序依据 */
	MessageIDType messageID;
	/*! \brief	任意附加信息 */
	void *extras;

	/*!
	 * \fn	Message(MessageIDType messageID, void *extras = nullptr)
	 *
	 * \brief	构造函数
	 *
	 * \param	messageID	  	指定消息的ID
	 * \param [in,out]	extras	(Optional) 任意附加信息
	 */
	Message(MessageIDType messageID, void *extras = nullptr)
	{
		this->messageID = messageID;
		this->extras = extras;
	}

	/*!
	 * \fn	bool operator<(const Message &rhs) const
	 *
	 * \brief	< 运算符
	 *
	 * \param	rhs	Message 实例
	 *
	 * \return	返回比较结果
	 */
	bool operator<(const Message &rhs) const
	{
		return this->messageID < rhs.messageID;
	}

	/*!
	 * \fn	bool operator>(const Message &rhs) const
	 *
	 * \brief	> 运算符
	 *
	 * \param	rhs	Message 实例
	 *
	 * \return	返回比较结果
	 */
	bool operator>(const Message &rhs) const
	{
		return this->messageID > rhs.messageID;
	}
};

#endif