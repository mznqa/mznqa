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

		LMessage_SpriteCard_TouchEvent_TouchBegan_TSpriteCardEventIndexT = 100,		///< ��Ƭ�����¼�-began
		LMessage_SpriteCard_TouchEvent_TouchMoved_TSpriteCardEventIndexT = 101,		///< ��Ƭ�����¼�-moved
		LMessage_SpriteCard_TouchEvent_TouchEnded_TSpriteCardEventIndexT = 102,		///< ��Ƭ�����¼�-ended

		LMessage_SpriteHandCard_TouchEvent_TouchBegan_TSpriteHandCardEventIndexT = 200,		///< ���ƴ����¼�-began
		LMessage_SpriteHandCard_TouchEvent_TouchMoved_TSpriteHandCardEventIndexT = 201,		///< ���ƴ����¼�-moved
		LMessage_SpriteHandCard_TouchEvent_TouchEnded_TSpriteHandCardEventIndexT = 202,		///< ���ƴ����¼�-ended

		LMessage_RefreshMapCellSpriteByGPointSet_TGPointSetT = 300,	///< ˢ�µ�ͼ��ָ�����������ͼƬ

		LMessage_ReplaceScene_SceneLoadRes2SceneGameMain = 400,	///< ��ת�������� SceneLoadRes ��ת�� SceneGameMain

		LMessage_LoadData_StaticData_MapMainMissionSet = 500,	///< ��ʼ������ο�����
		LMessage_LoadData_StaticData_CardSkillSet = 501,		///< ��ʼ���뼼�ܿ�����
		LMessage_LoadData_StaticData_CardRoadSet = 502,			///< ��ʼ������ο�����

		LMessage_Information_DataLoading_StaticData_MapMainMissionSetLoadSuccess = 600,	///< �ɹ����뾲̬���ݣ����������ͼ����
		LMessage_Information_DataLoading_StaticData_CardSkillSetLoadSuccess = 601,		///< �ɹ����뾲̬���ݣ����ܿ�����
		LMessage_Information_DataLoading_StaticData_CardRoadSetLoadSuccess = 602,		///< �ɹ����뾲̬���ݣ����ο�����

		LMessage_Error_DataLoading_StaticData_CardMapMainMissionSetSetLoadFailed = 700,	///< ���뾲̬����ʱ�������ο�����
		LMessage_Error_DataLoading_StaticData_CardSkillSetLoadFailed = 701,				///< ���뾲̬����ʱ�������ο�����
		LMessage_Error_DataLoading_StaticData_CardRoadSetLoadFailed = 702				///< ���뾲̬����ʱ�������ο�����
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