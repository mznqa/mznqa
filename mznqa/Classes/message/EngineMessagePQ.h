/*!
 * \file	Classes\message\EngineMessagePQ.h
 *
 * \brief	������ EngineMessagePQ
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
 * \brief	������ʹ�õ���Ϣ����
 *
 */
class EngineMessagePQ
{
public:

	/*!
	 * \enum	EMessage
	 *
	 * \brief	��Ϣö��
	 */
	enum EMessage
	{
		EMessage_None = 0,			///< ����Ϣ
		EMessage_MapMoveUp = 1,		///< ���Ƶ�ͼ
		EMessage_MapMoveRight = 2,	///< ���Ƶ�ͼ
		EMessage_MapMoveDown = 3,	///< ���Ƶ�ͼ
		EMessage_MapMoveLeft = 4,	///< ���Ƶ�ͼ

		EMessage_Information_DataLoading_StaticData_MapMainMissionSetLoadSuccess = 200,	///< �ɹ����뾲̬���ݣ����������ͼ����
		EMessage_Information_DataLoading_StaticData_CardSkillSetLoadSuccess = 201,		///< �ɹ����뾲̬���ݣ����ܿ�����
		EMessage_Information_DataLoading_StaticData_CardRoadSetLoadSuccess = 202,		///< �ɹ����뾲̬���ݣ����ο�����

		EMessage_Error_DataLoading_StaticData_CardMapMainMissionSetSetLoadFailed = 300,	///< ���뾲̬����ʱ�������ο�����
		EMessage_Error_DataLoading_StaticData_CardSkillSetLoadFailed = 301,				///< ���뾲̬����ʱ�������ο�����
		EMessage_Error_DataLoading_StaticData_CardRoadSetLoadFailed = 302				///< ���뾲̬����ʱ�������ο�����
	};

	/*!
	 * \fn	static EngineMessagePQ* EngineMessagePQ::Instance();
	 *
	 * \brief	��ȡʵ��
	 *
	 * \return	����ʵ��
	 */
	static EngineMessagePQ* Instance();

	/*!
	 * \fn	EngineMessagePQ::~EngineMessagePQ();
	 *
	 * \brief	��������
	 *
	 */
	~EngineMessagePQ();

	/*!
	 * \fn	void EngineMessagePQ::pushMessage(const Message<EMessage> &eMessage);
	 *
	 * \brief	�����������һ��������Ϣ
	 *
	 * \param	eMessage	ָ�������͵�������Ϣ
	 */
	void pushMessage(const Message<EMessage> &eMessage);

	/*!
	 * \fn	Message<EMessage> EngineMessagePQ::getNextMessage();
	 *
	 * \brief	��ȡ���Ӷ����е�����ǰ���ȼ���ߵ���Ϣ
	 *
	 * \return	���ز��Ӷ����е�����ǰ���ȼ���ߵ���Ϣ
	 */
	Message<EMessage> getNextMessage();

	/*!
	 * \fn	bool EngineMessagePQ::isEmpty();
	 *
	 * \brief	�жϵ�ǰ��Ϣ�����Ƿ�Ϊ��
	 *
	 * \return	���ص�ǰ��Ϣ�����Ƿ�Ϊ��
	 */
	bool isEmpty();

	/*!
	 * \fn	void EngineMessagePQ::clear();
	 *
	 * \brief	��յ�ǰ��Ϣ����
	 *
	 */
	void clear();

	/*!
	 * \fn	int EngineMessagePQ::getMessageCount()
	 *
	 * \brief	��ȡ�����е�ǰ��Ϣ����
	 *
	 * \return	���ض����е�ǰ��Ϣ����
	 */
	int getMessageCount()
	{
		return msgPQ.size();
	}

private:

	/*!
	 * \fn	EngineMessagePQ::EngineMessagePQ()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	EngineMessagePQ(){}

	/*!
	 * \fn	EngineMessagePQ::EngineMessagePQ(const EngineMessagePQ &engineMessagePQ);
	 *
	 * \brief	���صĿ������캯��
	 *
	 * \param	engineMessagePQ	ָ�� EngineMessagePQ ʵ��
	 */
	EngineMessagePQ(const EngineMessagePQ &engineMessagePQ);

	/*!
	 * \fn	EngineMessagePQ& EngineMessagePQ::operator=(const EngineMessagePQ &engineMessagePQ);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 * \param	engineMessagePQ	ָ�� EngineMessagePQ ʵ��
	 *
	 * \return	���� EngineMessagePQ ʵ��
	 */
	EngineMessagePQ& operator=(const EngineMessagePQ &engineMessagePQ);

	/*! \brief	��������Ϣ���� */
	std::priority_queue<Message<EMessage>, std::vector<Message<EMessage>>, std::less<Message<EMessage>>> msgPQ;
};

#endif