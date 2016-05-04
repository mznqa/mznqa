/*!
 * \file	Classes\common\arkca\message\Message.h
 *
 * \brief	������ ArKCa::Message
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
	 * \brief	��Ϣʵ��
	 *
	 * \tparam	IDType	��ʶ��ϢID������
	 */
	template <typename IDType>
	class Message
	{
	private:
		/*! \brief	��ϢID */
		IDType id;
		/*! \brief	������Ϣ */
		Any extras;
	public:

		/*!
		 * \fn	Message::Message(const IDType &id)
		 *
		 * \brief	���캯��
		 *
		 * \param	id	ָ����ϢID
		 */
		Message(const IDType &id) :
			id(id)
		{
		}

		/*!
		 * \fn	template<typename ExtrasType> Message::Message(const IDType &id, const ExtrasType &extras)
		 *
		 * \brief	���캯��
		 *
		 * \tparam	ExtrasType	������Ϣ������
		 * \param	id	  	ָ����Ϣ��ID
		 * \param	extras	ָ����Ϣ�ĸ�����Ϣ
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
		 * \brief	��ȡ��Ϣ��ID
		 *
		 */
		const IDType& getID()const
		{
			return id;
		}

		/*!
		 * \fn	template<typename T> const T Message::getExtras()
		 *
		 * \brief	��ȡ��Ϣ�ĸ�����Ϣ
		 *
		 * \tparam	T	ָ����Ϣ������Ϣ������
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
		 * \brief	<�����
		 *
		 */
		bool operator<(const Message &rhs)const
		{
			return this->id < rhs.id;
		}

		/*!
		 * \fn	bool Message::operator>(const Message &rhs)const
		 *
		 * \brief	>�����
		 *
		 */
		bool operator>(const Message &rhs)const
		{
			return this->id > rhs.id;
		}

		/*!
		 * \fn	bool Message::operator==(const Message &rhs)const
		 *
		 * \brief	==�����
		 *
		 */
		bool operator==(const Message &rhs)const
		{
			return this->id == rhs.id;
		}
	};
}

#endif
