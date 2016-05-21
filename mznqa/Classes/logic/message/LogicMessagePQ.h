/*!
 * \file	Classes\logic\message\LogicMessagePQ.h
 *
 * \brief	������ LogicMessagePQ
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_MESSAGE_LOGICMESSAGEPQ_H_
#define MZNQA_CLASSES_LOGIC_MESSAGE_LOGICMESSAGEPQ_H_

#include "common/arkca/message/MessagePQ.h"
#include "common/arkca/message/Message.h"

/*!
 * \class	LogicMessagePQ
 *
 * \brief	[����]�߼�����Ϣ����
 *
 */
class LogicMessagePQ
{
public:

	/*!
	 * \fn	LogicMessagePQ::~LogicMessagePQ();
	 *
	 * \brief	��������
	 *
	 */
	~LogicMessagePQ();

	/*!
	 * \fn	static LogicMessagePQ* LogicMessagePQ::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 */
	static LogicMessagePQ* Instance();

	/*!
	 * \enum	LogicMessageID
	 *
	 * \brief	ö���߼������ϢID
	 */
	enum LogicMessageID
	{
		LogicMessageID_ValidID,
		LogicMessageID_FileLoadingFail_String_Zh_Json,
		LogicMessageID_FileLoadingFail_String_En_Json,
		LogicMessageID_FileLoadingFail_String_Set,
		LogicMessageID_FileLoadingFail_Card_Road_Json,
		LogicMessageID_FileLoadingFail_MissionMap_Map_TMissionMapSet__MissionMapIDMainT,
		LogicMessageID_ParsingFail_String_Set,
		LogicMessageID_ParsingFail_CardRoad_Set,
		LogicMessageID_ParsingFail_MissionMap_Map_TMissionMapSet__MissionMapIDMainT,
		LogicMessageID_DataLoadingFail_String_Set,
		LogicMessageID_DataLoadingFail_CardRoad_Set,
		LogicMessageID_DataLoadingFail_MissionMap_Map_TMissionMapSet__MissionMapIDMainT,
		LogicMessageID_FileLoadingSucc_String_Zh_Json,
		LogicMessageID_FileLoadingSucc_String_En_Json,
		LogicMessageID_FileLoadingSucc_Card_Road_Json,
		LogicMessageID_FileLoadingSucc_MissionMap_Map_TMissionMapSet__MissionMapIDMainT,
		LogicMessageID_ParsingSucc_String_Set,
		LogicMessageID_ParsingSucc_CardRoad_Set,
		LogicMessageID_ParsingSucc_MissionMap_Map_TMissionMapSet__MissionMapIDMainT,
		LogicMessageID_DataLoadingSucc_String_Set,
		LogicMessageID_DataLoadingSucc_CardRoad_Set,
		LogicMessageID_DataLoadingSucc_MissionMap_Map_TMissionMapSet__MissionMapIDMainT,
		LogicMessageID_StateChangeDone_CoreStateGuide_CoreStateResLoading,
		LogicMessageID_StateChangeDone_CoreStateResLoading_CoreStateGameMain,
		LogicMessageID_MoveMapView_Down,
		LogicMessageID_MoveMapView_Left,
		LogicMessageID_MoveMapView_Up,
		LogicMessageID_MoveMapView_Right,
		LogicMessageID_Update_MapViewPosition,
		LogicMessageID_Explore_DrawCrad_Role,
		LogicMessageID_Explore_DrawCradSucc_Role_TintT,
		LogicMessageID_Explore_DrawCradFail_Role_CardPoolEmpty,
		LogicMessageID_Explore_DrawCradFail_Role_HandCardFull
	};

	/*!
	 * \fn	void LogicMessagePQ::pushMessage(const ArKCa::Message<LogicMessageID> &message);
	 *
	 * \brief	������Ϣ���߼������Ϣ������
	 *
	 * \param	message	ָ�������͵��߼�����Ϣ
	 */
	void pushMessage(const ArKCa::Message<LogicMessageID> &message);

	/*!
	 * \fn	const ArKCa::Message<LogicMessageID> *const LogicMessagePQ::getTopMessage()const;
	 *
	 * \brief	��ȡ���ȼ���ߵ��߼�����Ϣ
	 *
	 */
	const ArKCa::Message<LogicMessageID> *const getTopMessage()const;

	/*!
	 * \fn	void LogicMessagePQ::popTopMessage()
	 *
	 * \brief	�������ȼ���ߵ��߼�����Ϣ
	 *
	 */
	void popTopMessage()
	{
		msgPQ.popTopMessage();
	}

	/*!
	 * \fn	bool LogicMessagePQ::isEmpty()const;
	 *
	 * \brief	�ж��߼�����Ϣ�����Ƿ�Ϊ��
	 *
	 */
	bool isEmpty()const;

	/*!
	 * \fn	void LogicMessagePQ::clear();
	 *
	 * \brief	����߼�����Ϣ����
	 *
	 */
	void clear();

	/*!
	 * \fn	int LogicMessagePQ::getMessageCount()const;
	 *
	 * \brief	��ȡ��ǰ�߼�����Ϣ�����е���Ϣ����
	 *
	 */
	int getMessageCount()const;
private:

	/*!
	 * \fn	LogicMessagePQ::LogicMessagePQ();
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	LogicMessagePQ();

	/*!
	 * \fn	LogicMessagePQ::LogicMessagePQ(const LogicMessagePQ &logicMessagePQ);
	 *
	 * \brief	���صĿ������캯��
	 *
	 */
	LogicMessagePQ(const LogicMessagePQ &logicMessagePQ);

	/*!
	 * \fn	LogicMessagePQ& LogicMessagePQ::operator=(const LogicMessagePQ &logicMessagePQ);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	LogicMessagePQ& operator=(const LogicMessagePQ &logicMessagePQ);

	/*! \brief	�ڽ���Ϣ���ȶ��� */
	ArKCa::MessagePQ<LogicMessageID, LogicMessageID_ValidID> msgPQ;
};

#endif
