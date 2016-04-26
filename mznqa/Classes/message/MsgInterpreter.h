/*!
 * \file	Classes\message\MsgInterpreter.h
 *
 * \brief	������ MsgInterpreter
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MESSAGE_MSGINTERPRETER_H_
#define MZNQA_CLASSES_MESSAGE_MSGINTERPRETER_H_

#include <map>

#include "message/Message.h"
#include "message/EngineMessagePQ.h"
#include "message/LogicMessagePQ.h"

/*!
 * \class	MsgInterpreter
 *
 * \brief	��Ϣת����
 *
 */
class MsgInterpreter
{
private:

	/*!
	 * \fn	MsgInterpreter::MsgInterpreter();
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	MsgInterpreter();

	/*!
	 * \fn	MsgInterpreter::MsgInterpreter(const MsgInterpreter &msgInterpreter);
	 *
	 * \brief	���صĿ������캯��
	 *
	 * \param	msgInterpreter	MsgInterpreter ʵ��
	 */
	MsgInterpreter(const MsgInterpreter &msgInterpreter);

	/*!
	 * \fn	MsgInterpreter& MsgInterpreter::operator=(const MsgInterpreter &msgInterpreter);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 * \param	msgInterpreter	MsgInterpreter ʵ��
	 *
	 * \return	���� MsgInterpreter ʵ��
	 */
	MsgInterpreter& operator=(const MsgInterpreter &msgInterpreter);

	// �������� //////////////////////////////////////////////////////////////////////////
	/*! \brief	���� EngineMessagePQ::Instancet() �ĳ���ָ�� */
	EngineMessagePQ *EngineMessagePQInstance;
	/*! \brief	���� LogicMessagePQ::Instance() �ĳ���ָ�� */
	LogicMessagePQ *LogicMessagePQInstance;
	//////////////////////////////////////////////////////////////////////////

	/*! \brief	��Ϣӳ���������Ϣ->�߼���Ϣ */
	std::map<EngineMessagePQ::EMessage, LogicMessagePQ::LMessage> msgMap;
public:

	/*!
	 * \fn	static MsgInterpreter* MsgInterpreter::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 * \return	���ص���
	 */
	static MsgInterpreter* Instance();

	/*!
	 * \fn	MsgInterpreter::~MsgInterpreter();
	 *
	 * \brief	��������
	 *
	 */
	~MsgInterpreter();

	/*!
	 * \fn	Message<LogicMessagePQ::LMessage> MsgInterpreter::translation(const Message<EngineMessagePQ::EMessage> &eMessage);
	 *
	 * \brief	��������Ϣת����߼���Ϣ
	 *
	 * \param	eMessage	ָ��������Ϣ
	 *
	 * \return	����ת�����߼���Ϣ
	 */
	Message<LogicMessagePQ::LMessage> translation(const Message<EngineMessagePQ::EMessage> &eMessage);
};

#endif