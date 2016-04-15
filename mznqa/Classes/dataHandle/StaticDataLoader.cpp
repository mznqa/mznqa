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
#include "map/MapController.h"
#include "dataHandle/ParserMapArchives.h"
#include "dataHandle/ParserMapMissionMain.h"
#include "staticData/MissionMapSet.h"

void StaticDataLoader::loadStaticDataCardRoadSet()
{
	cocos2d::log("[information] ��ʼ���뾲̬���ݣ����ο�����...");

	std::map<int, CardRoad> cardRoadSetTemp;
	cardRoadSetTemp.insert(std::pair<int, CardRoad>(1234, CardRoad(1234, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_URDL)));
	cardRoadSetTemp.insert(std::pair<int, CardRoad>(234, CardRoad(234, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_RDL)));
	cardRoadSetTemp.insert(std::pair<int, CardRoad>(134, CardRoad(134, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_UDL)));
	cardRoadSetTemp.insert(std::pair<int, CardRoad>(124, CardRoad(124, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_URL)));
	cardRoadSetTemp.insert(std::pair<int, CardRoad>(123, CardRoad(123, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_URD)));
	cardRoadSetTemp.insert(std::pair<int, CardRoad>(34, CardRoad(34, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_DL)));
	cardRoadSetTemp.insert(std::pair<int, CardRoad>(14, CardRoad(14, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_UL)));
	cardRoadSetTemp.insert(std::pair<int, CardRoad>(12, CardRoad(12, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_UR)));
	cardRoadSetTemp.insert(std::pair<int, CardRoad>(24, CardRoad(24, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_RL)));
	cardRoadSetTemp.insert(std::pair<int, CardRoad>(13, CardRoad(13, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_UD)));
	cardRoadSetTemp.insert(std::pair<int, CardRoad>(23, CardRoad(23, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_RD)));
	cardRoadSetTemp.insert(std::pair<int, CardRoad>(1, CardRoad(1, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_U)));
	cardRoadSetTemp.insert(std::pair<int, CardRoad>(2, CardRoad(2, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_R)));
	cardRoadSetTemp.insert(std::pair<int, CardRoad>(3, CardRoad(3, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_D)));
	cardRoadSetTemp.insert(std::pair<int, CardRoad>(4, CardRoad(4, "", "", CardBase::BelongTo_RoleOnly, CardRoad::RoadType_L)));

	CardSet::Instance()->loadCardRoadSet(cardRoadSetTemp);

	cardRoadSetTemp.clear();

	cocos2d::log("[information] ��ɣ����뾲̬���ݣ����ο�����");
}

void StaticDataLoader::loadStaticDataCardSkillSet()
{
	CharBufferArea::BufferIndex bufferIndex = CharBufferArea::BufferIndex_Static_CardSkillSet;

	cocos2d::log("[information] ��ʼ�����ļ����ݣ���̬���ݣ����ܿ�����...");
	CharBufferArea::Instance()->createBuffer(
		bufferIndex,
		FileController::Instance()->getCharBufferFromFile(STATIC_DATA_CARDSKILLSET)
		);
	if (CharBufferArea::Instance()->getBufferByIndex(bufferIndex) == nullptr)
		cocos2d::log("[error] ����ʧ�ܣ���̬���ݣ����ܿ�����");
	else
		cocos2d::log("[information] �ɹ����棺��̬���ݣ����ܿ�����");

	//////////////////////////////////////////////////////////////////////////

	cocos2d::log("[information] ��ʼ��������̬���ݣ����ܿ�����...");
	ParserCardSkill parserCardSkill;
	parserCardSkill.parse();
	if (ParserCardSkill::cardSkillSetTemp.empty() == true)
		cocos2d::log("[error] ����ʧ�ܣ���̬���ݣ����ܿ�����");
	else
	{
		CardSet::Instance()->loadCardSkillSet(ParserCardSkill::cardSkillSetTemp);
		cocos2d::log("[information] ��ɽ�������̬���ݣ����ܿ�����");
	}

	//////////////////////////////////////////////////////////////////////////

	cocos2d::log("[information] ��ʼ�ͷŻ��棺��̬���ݣ����ܿ�����...");
	ParserCardSkill::cardSkillSetTemp.clear();
	CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
	cocos2d::log("[information] �ɹ��ͷŻ��棺��̬���ݣ����ܿ�����");
}

void StaticDataLoader::loadStaticDataMainMissionMapSet()
{
	CharBufferArea::BufferIndex bufferIndex = CharBufferArea::BufferIndex_Static_MainMissionMap;

	cocos2d::log("[information] ��ʼ�����ļ����ݣ���̬���ݣ����������ͼ����...");
	CharBufferArea::Instance()->createBuffer(
		bufferIndex,
		FileController::Instance()->getCharBufferFromFile(STATIC_DATA_MAINMISSIONMAP)
		);
	if (CharBufferArea::Instance()->getBufferByIndex(bufferIndex) == nullptr)
		cocos2d::log("[error] ����ʧ�ܣ���̬���ݣ����������ͼ����");
	else
		cocos2d::log("[information] �ɹ����棺��̬���ݣ����������ͼ����");

	//////////////////////////////////////////////////////////////////////////

	cocos2d::log("[information] ��ʼ��������̬���ݣ����������ͼ����...");
	ParserMapMissionMain parserMapMissionMain;
	parserMapMissionMain.parse();
	if (ParserMapMissionMain::mainMissionMapSetTemp.empty() == true)
		cocos2d::log("[error] ����ʧ�ܣ���̬���ݣ����������ͼ����");
	else
	{
		MissionMapSet::Instance()->loadMainMissionMapSet(ParserMapMissionMain::mainMissionMapSetTemp);
		cocos2d::log("[information] ��ɽ�������̬���ݣ����������ͼ����");
	}

	//////////////////////////////////////////////////////////////////////////

	cocos2d::log("[information] ��ʼ�ͷŻ��棺��̬���ݣ����������ͼ����...");
	ParserMapMissionMain::mainMissionMapSetTemp.clear();
	CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
	cocos2d::log("[information] �ɹ��ͷŻ��棺��̬���ݣ����������ͼ����");
}

void StaticDataLoader::loadArchivesDataGlobalMap()
{
	CharBufferArea::BufferIndex bufferIndex = CharBufferArea::BufferIndex_Archives_GlobalMap;

	cocos2d::log("[information] ��ʼ�����ļ����ݣ��浵��ȫ�ֵ�ͼ...");
	CharBufferArea::Instance()->createBuffer(
		bufferIndex,
		FileController::Instance()->getCharBufferFromFile(ARCHIVES_DATA_GLOBALMAP)
		);
	if (CharBufferArea::Instance()->getBufferByIndex(bufferIndex) == nullptr)
		cocos2d::log("[error] ����ʧ�ܣ��浵��ȫ�ֵ�ͼ");
	else
		cocos2d::log("[information] �ɹ����棺�浵��ȫ�ֵ�ͼ");

	//////////////////////////////////////////////////////////////////////////

	cocos2d::log("[information] ��ʼ�������浵��ȫ�ֵ�ͼ...");
	ParserMapArchives parserMapArchives;
	parserMapArchives.parse();
	if (ParserMapArchives::globalMapArchivesTemp.empty() == true)
		cocos2d::log("[error] ����ʧ�ܣ��浵��ȫ�ֵ�ͼ");
	else
	{
		MapController::Instance()->loadMapNode(ParserMapArchives::globalMapArchivesTemp);
		cocos2d::log("[information] ��ɽ������浵��ȫ�ֵ�ͼ");
	}

	//////////////////////////////////////////////////////////////////////////

	cocos2d::log("[information] ��ʼ�ͷŻ��棺�浵��ȫ�ֵ�ͼ...");
	ParserMapArchives::globalMapArchivesTemp.clear();
	CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
	cocos2d::log("[information] �ɹ��ͷŻ��棺�浵��ȫ�ֵ�ͼ");
}