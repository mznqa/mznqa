/*!
 * \file	Classes\dataHandle\StaticDataLoader.cpp
 *
 * \brief	������ StaticDataLoader
 */

#pragma execution_character_set("utf-8")

#include "dataHandle/StaticDataLoader.h"

#include "cocos2d.h"

#include "engine/FileController.h"
#include "dataHandle/CharBufferArea.h"
#include "dataHandle/ParserCardSkill.h"
#include "filePath/DataFilePath.h"
#include "staticData/CardSet.h"
#include "dataHandle/ParserMapMissionMain.h"
#include "staticData/MissionMapSet.h"
#include "message/LogicMessagePQ.h"

void StaticDataLoader::loadStaticDataCardRoadSet()
{
	// �ֶ�������ο���̬���� //////////////////////////////////////////////////////////////////////////
	std::map<int, CardRoad> cardRoadSetTemp = {
		std::pair<int, CardRoad>(1234, CardRoad(1234, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_URDL)),
		std::pair<int, CardRoad>(234, CardRoad(234, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_RDL)),
		std::pair<int, CardRoad>(134, CardRoad(134, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_UDL)),
		std::pair<int, CardRoad>(124, CardRoad(124, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_URL)),
		std::pair<int, CardRoad>(123, CardRoad(123, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_URD)),
		std::pair<int, CardRoad>(34, CardRoad(34, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_DL)),
		std::pair<int, CardRoad>(14, CardRoad(14, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_UL)),
		std::pair<int, CardRoad>(12, CardRoad(12, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_UR)),
		std::pair<int, CardRoad>(24, CardRoad(24, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_RL)),
		std::pair<int, CardRoad>(13, CardRoad(13, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_UD)),
		std::pair<int, CardRoad>(23, CardRoad(23, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_RD)),
		std::pair<int, CardRoad>(1, CardRoad(1, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_U)),
		std::pair<int, CardRoad>(2, CardRoad(2, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_R)),
		std::pair<int, CardRoad>(3, CardRoad(3, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_D)),
		std::pair<int, CardRoad>(4, CardRoad(4, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_L))
	};
	//////////////////////////////////////////////////////////////////////////

	// �������� //////////////////////////////////////////////////////////////////////////
	// ������ת��������CardSet
	CardSet::Instance()->loadCardRoadSet(cardRoadSetTemp);

	// �ͷ���ʱ��
	cardRoadSetTemp.clear();
	//////////////////////////////////////////////////////////////////////////

	// ��֤���������� //////////////////////////////////////////////////////////////////////////
	// ������ο���̬��������ʧ��
	if (CardSet::Instance()->isCardRoadSetEmpty() == true)
		// ����ʧ����Ϣ
		LogicMessagePQ::Instance()->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardRoadSetLoadFailed));
	// ����
	else
		// ���ͳɹ���Ϣ
		LogicMessagePQ::Instance()->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_Information_DataLoading_StaticData_CardRoadSetLoadSuccess));
	//////////////////////////////////////////////////////////////////////////
}

void StaticDataLoader::loadStaticDataCardSkillSet()
{
	// ���ڴ������������ݻ���Ļ���������
	CharBufferArea::BufferIndex bufferIndex = CharBufferArea::BufferIndex_Static_CardSkillSet;

	// ������صľ�̬�����ļ� //////////////////////////////////////////////////////////////////////////
	// �������ĵĻ����������Լ����ܿ��������ݵ��ļ��������������������Դ�����
	CharBufferArea::Instance()->createBuffer(
		bufferIndex,
		FileController::Instance()->getCharBufferFromFile(STATIC_DATA_CARDSKILLSET)
		);
	// ����������Ļ���������ʧ��
	if (CharBufferArea::Instance()->getBufferByIndex(bufferIndex) == nullptr)
	{
		// ��ȫ�ͷŻ�����
		CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
		// ����ʧ����Ϣ
		LogicMessagePQ::Instance()->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardSkillSetLoadFailed));
		return;
	}
	//////////////////////////////////////////////////////////////////////////

	// ���� //////////////////////////////////////////////////////////////////////////
	// ���ܿ��������ݽ�����
	ParserCardSkill parserCardSkill;
	// ����
	parserCardSkill.parse();
	// �������ʧ��
	if (ParserCardSkill::cardSkillSetTemp.empty() == true)
	{
		// �ͷŻ��� //////////////////////////////////////////////////////////////////////////
		ParserCardSkill::cardSkillSetTemp.clear();
		CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
		//////////////////////////////////////////////////////////////////////////
		// ����ʧ����Ϣ
		LogicMessagePQ::Instance()->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardSkillSetLoadFailed));
		return;
	}
	// ����
	else
	{
		//  ������ת��������CardSet
		CardSet::Instance()->loadCardSkillSet(ParserCardSkill::cardSkillSetTemp);

		// ���ת��ʧ��
		if (CardSet::Instance()->isCardSkillSetEmpty() == true)
		{
			// �ͷŻ��� //////////////////////////////////////////////////////////////////////////
			ParserCardSkill::cardSkillSetTemp.clear();
			CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
			//////////////////////////////////////////////////////////////////////////
			// ����ʧ����Ϣ
			LogicMessagePQ::Instance()->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardSkillSetLoadFailed));
			return;
		}
		// ����
		else
			// ���ͳɹ���Ϣ
			LogicMessagePQ::Instance()->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_Information_DataLoading_StaticData_CardSkillSetLoadSuccess));
	}
	//////////////////////////////////////////////////////////////////////////

	// �ͷŻ��� //////////////////////////////////////////////////////////////////////////
	ParserCardSkill::cardSkillSetTemp.clear();
	CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
	//////////////////////////////////////////////////////////////////////////
}

void StaticDataLoader::loadStaticDataMainMissionMapSet()
{
	// ���ڴ������������ݻ���Ļ���������
	CharBufferArea::BufferIndex bufferIndex = CharBufferArea::BufferIndex_Static_MainMissionMap;

	// ������صľ�̬�����ļ� //////////////////////////////////////////////////////////////////////////
	// �������ĵĻ����������Լ����������ͼ�������ݵ��ļ��������������������Դ�����
	CharBufferArea::Instance()->createBuffer(
		bufferIndex,
		FileController::Instance()->getCharBufferFromFile(STATIC_DATA_MAINMISSIONMAP)
		);
	// ����������Ļ���������ʧ��
	if (CharBufferArea::Instance()->getBufferByIndex(bufferIndex) == nullptr)
	{
		// ��ȫ�ͷŻ�����
		CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
		// ����ʧ����Ϣ
		LogicMessagePQ::Instance()->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardMapMainMissionSetSetLoadFailed));
		return;
	}
	//////////////////////////////////////////////////////////////////////////

	// ���� //////////////////////////////////////////////////////////////////////////
	// ���������ͼ���Ͻ�����
	ParserMapMissionMain parserMapMissionMain;
	// ����
	parserMapMissionMain.parse();
	// �������ʧ��
	if (ParserMapMissionMain::mainMissionMapSetTemp.empty() == true)
	{
		// �ͷŻ��� //////////////////////////////////////////////////////////////////////////
		ParserMapMissionMain::mainMissionMapSetTemp.clear();
		CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
		//////////////////////////////////////////////////////////////////////////
		// ����ʧ����Ϣ
		LogicMessagePQ::Instance()->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardMapMainMissionSetSetLoadFailed));
		return;
	}
	// ����
	else
	{
		//  ������ת��������CardSet
		MissionMapSet::Instance()->loadMainMissionMapSet(ParserMapMissionMain::mainMissionMapSetTemp);

		// �������ת��ʧ��
		if (MissionMapSet::Instance()->isMainMissionMapSetEmpty() == true)
		{
			// �ͷŻ��� //////////////////////////////////////////////////////////////////////////
			ParserMapMissionMain::mainMissionMapSetTemp.clear();
			CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
			//////////////////////////////////////////////////////////////////////////
			// ����ʧ����Ϣ
			LogicMessagePQ::Instance()->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardMapMainMissionSetSetLoadFailed));
			return;
		}
		else
		{
			// ���ͳɹ���Ϣ
			LogicMessagePQ::Instance()->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_Information_DataLoading_StaticData_MapMainMissionSetLoadSuccess));
		}
	}

	//////////////////////////////////////////////////////////////////////////

	// �ͷŻ��� //////////////////////////////////////////////////////////////////////////
	ParserMapMissionMain::mainMissionMapSetTemp.clear();
	CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
	//////////////////////////////////////////////////////////////////////////
}