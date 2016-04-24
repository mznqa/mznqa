/*!
 * \file	Classes\message\LogicMessagePQ.h
 *
 * \brief	������ LogicMessagePQ
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
 * \brief	���߼���ʹ�õ���Ϣ����
 *
 */
class LogicMessagePQ
{
public:

	/*!
	 * \enum	LMessage
	 *
	 * \brief	��Ϣö��
	 */
	enum LMessage
	{
		LMessage_None = 0,				///< ����Ϣ
		LMessage_RefreshRolePosition,	///< ˢ�½�ɫ��ǰ��λ��
		LMessage_RefreshMapPosition,	///< ˢ�µ�ͼ��ǰ��λ��
		LMessage_MapViewMoveUp,			///< ���Ƶ�ͼ��Ұ
		LMessage_MapViewMoveRight,		///< ���Ƶ�ͼ��Ұ
		LMessage_MapViewMoveDown,		///< ���Ƶ�ͼ��Ұ
		LMessage_MapViewMoveLeft,		///< ���Ƶ�ͼ��Ұ

		LMessage_ReplaceScene_SceneLoadRes2SceneGameMain = 100,	///< ��ת�������� SceneLoadRes ��ת�� SceneGameMain

		LMessage_LoadData_StaticData_MapMainMissionSet = 200,	///< ��ʼ������ο�����
		LMessage_LoadData_StaticData_CardSkillSet = 201,		///< ��ʼ���뼼�ܿ�����
		LMessage_LoadData_StaticData_CardRoadSet = 202,			///< ��ʼ������ο�����

		LMessage_Information_DataLoading_StaticData_MapMainMissionSetLoadSuccess = 300,	///< �ɹ����뾲̬���ݣ����������ͼ����
		LMessage_Information_DataLoading_StaticData_CardSkillSetLoadSuccess = 301,		///< �ɹ����뾲̬���ݣ����ܿ�����
		LMessage_Information_DataLoading_StaticData_CardRoadSetLoadSuccess = 302,		///< �ɹ����뾲̬���ݣ����ο�����

		LMessage_Error_DataLoading_StaticData_CardMapMainMissionSetSetLoadFailed = 400,	///< ���뾲̬����ʱ�������ο�����
		LMessage_Error_DataLoading_StaticData_CardSkillSetLoadFailed = 401,				///< ���뾲̬����ʱ�������ο�����
		LMessage_Error_DataLoading_StaticData_CardRoadSetLoadFailed = 402				///< ���뾲̬����ʱ�������ο�����
	};

	/*!
	 * \fn	static LogicMessagePQ* LogicMessagePQ::Instance();
	 *
	 * \brief	��ȡʵ��
	 *
	 * \return	����ʵ��
	 */
	static LogicMessagePQ* Instance();

	/*!
	 * \fn	LogicMessagePQ::~LogicMessagePQ();
	 *
	 * \brief	��������
	 *
	 */
	~LogicMessagePQ();

	/*!
	 * \fn	void LogicMessagePQ::pushMessage(const Message<LMessage> &lMessage);
	 *
	 * \brief	�������������Ϣ
	 *
	 * \param	lMessage	һ���߼���Ϣ
	 */
	void pushMessage(const Message<LMessage> &lMessage);

	// ��ȡ��ǰ���ȼ���ߵ���Ϣ
	// ע�⣺������ EMessage_None ��ʾ��ǰ��Ϣ����������Ϣ

	/*!
	 * \fn	Message<LMessage> LogicMessagePQ::getNextMessage();
	 *
	 * \brief	��ȡ���Ӷ����е�����ǰ���ȼ���ߵ���Ϣ
	 *
	 * \return	���ص�ǰ���ȼ���ߵ�Ԫ��
	 */
	Message<LMessage> getNextMessage();

	/*!
	 * \fn	bool LogicMessagePQ::isEmpty();
	 *
	 * \brief	�жϵ�ǰ�����Ƿ�Ϊ��
	 *
	 * \return	���ص�ǰ�����Ƿ�Ϊ��
	 */
	bool isEmpty();

	/*!
	 * \fn	void LogicMessagePQ::clear();
	 *
	 * \brief	��յ�ǰ��Ϣ����
	 *
	 */
	void clear();

	/*!
	 * \fn	int LogicMessagePQ::getMessageCount()
	 *
	 * \brief	��ȡ��ǰ�����е���Ϣ����
	 *
	 * \return	���ص�ǰ�����е���Ϣ����
	 */
	int getMessageCount()
	{
		return msgPQ.size();
	}

private:

	/*!
	 * \fn	LogicMessagePQ::LogicMessagePQ()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	LogicMessagePQ(){}

	/*!
	 * \fn	LogicMessagePQ::LogicMessagePQ(const LogicMessagePQ &logicMessagePQ);
	 *
	 * \brief	���صĿ������캯��
	 *
	 * \param	logicMessagePQ	LogicMessagePQ ʵ��
	 */
	LogicMessagePQ(const LogicMessagePQ &logicMessagePQ);

	/*!
	 * \fn	LogicMessagePQ& LogicMessagePQ::operator=(const LogicMessagePQ &logicMessagePQ);
	 *
	 * \brief	���صĿ������������
	 *
	 * \param	logicMessagePQ	LogicMessagePQ ʵ��
	 *
	 * \return	���� LogicMessagePQ ʵ��
	 */
	LogicMessagePQ& operator=(const LogicMessagePQ &logicMessagePQ);

	/*! \brief	�߼�����Ϣ���� */
	std::priority_queue<Message<LMessage>, std::vector<Message<LMessage>>, std::less<Message<LMessage>>> msgPQ;
};

#endif