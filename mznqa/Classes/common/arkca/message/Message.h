/*!
 * \file	Classes\common\arkca\message\Message.h
 *
 * \brief	定义类 ArKCa::Message
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMMON_ARKCA_MESSAGE_MESSAGE_H_
#define MZNQA_CLASSES_COMMON_ARKCA_MESSAGE_MESSAGE_H_

#include <memory>

#include "common/arkca/Any.h"

namespace ArKCa
{
	/*!
	 * \class	Message
	 *
	 * \brief	消息实体
	 *
	 * \tparam	IDType	标识消息ID的类型
	 */
	template <typename IDType>
	class Message
	{
	private:
		/*! \brief	消息ID */
		IDType id;
		/*! \brief	附加信息 */
		Any extras;
	public:

		/*!
		 * \fn	Message::Message(const IDType &id)
		 *
		 * \brief	构造函数
		 *
		 * \param	id	指定消息ID
		 */
		Message(const IDType &id) :
			id(id)
		{
		}

		/*!
		 * \fn	template<typename ExtrasType> Message::Message(const IDType &id, const ExtrasType &extras)
		 *
		 * \brief	构造函数
		 *
		 * \tparam	ExtrasType	附加信息的类型
		 * \param	id	  	指定消息的ID
		 * \param	extras	指定消息的附加信息
		 */
		template<typename ExtrasType>
		Message(const IDType &id, const ExtrasType &extras) :
			id(id),
			extras(Any(extras))
		{
		}

		/*!
		 * \fn	const IDType& Message::getID()const
		 *
		 * \brief	获取消息的ID
		 *
		 */
		const IDType& getID()const
		{
			return id;
		}

		/*!
		 * \fn	template<typename T> const T Message::getExtras()
		 *
		 * \brief	获取消息的附加信息
		 *
		 * \tparam	T	指定消息附加信息的类型
		 *
		 */
		template<typename T>
		const T getExtras()
		{
			return extras.Value<T>();
		}

		/*!
		 * \fn	bool Message::operator<(const Message &rhs)const
		 *
		 * \brief	<运算符
		 *
		 */
		bool operator<(const Message &rhs)const
		{
			return this->id < rhs.id;
		}

		/*!
		 * \fn	bool Message::operator>(const Message &rhs)const
		 *
		 * \brief	>运算符
		 *
		 */
		bool operator>(const Message &rhs)const
		{
			return this->id > rhs.id;
		}

		/*!
		 * \fn	bool Message::operator==(const Message &rhs)const
		 *
		 * \brief	==运算符
		 *
		 */
		bool operator==(const Message &rhs)const
		{
			return this->id == rhs.id;
		}
	};
}

#endif
