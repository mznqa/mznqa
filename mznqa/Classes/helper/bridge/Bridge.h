/*!
 * \file	Classes\helper\bridge\Bridge.h
 *
 * \brief	������ Bridge
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_HELPER_BRIDGE_BRIDGE__H_
#define MZNQA_CLASSES_HELPER_BRIDGE_BRIDGE__H_

#include "common/arkca/message/Message.h"
#include "logic/message/LogicMessagePQ.h"
#include "interactive/message/InteractiveMessagePQ.h"

/*!
 * \class	Bridge
 *
 * \brief	�����߼���ͽ�����֮��Ľ���
 *
 */
class Bridge
{
private:

	/*!
	 * \fn	Bridge::Bridge();
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	Bridge();

	/*!
	 * \fn	Bridge::Bridge(const Bridge &bridge);
	 *
	 * \brief	���صĿ������캯��
	 *
	 */
	Bridge(const Bridge &bridge);

	/*!
	 * \fn	Bridge& Bridge::operator=(const Bridge &bridge);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	Bridge& operator=(const Bridge &bridge);

	// �������� //////////////////////////////////////////////////////////////////////////
	/*! \brief	The logic message pq instance. */
	LogicMessagePQ *const LogicMessagePQInstance = LogicMessagePQ::Instance();
	InteractiveMessagePQ *const InteractiveMessagePQInstance = InteractiveMessagePQ::Instance();
	//////////////////////////////////////////////////////////////////////////

public:

	/*!
	 * \fn	Bridge::~Bridge();
	 *
	 * \brief	��������
	 *
	 */
	~Bridge();

	/*!
	 * \fn	static Bridge* Bridge::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 */
	static Bridge* Instance();

	/*!
	 * \fn	void Bridge::pushMessage2Logic(const ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> &message);
	 *
	 * \brief	������Ϣ���߼���
	 *
	 * \param	message	ָ��һ�����������Ϣ
	 */
	void pushMessage2Logic(const ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID> &message);

	/*!
	 * \fn	void Bridge::pushMessage2Interactive(const ArKCa::Message<LogicMessagePQ::LogicMessageID> &message);
	 *
	 * \brief	������Ϣ��������
	 *
	 * \param	message	ָ��һ���߼�����Ϣ
	 */
	void pushMessage2Interactive(const ArKCa::Message<LogicMessagePQ::LogicMessageID> &message);
};

#endif
