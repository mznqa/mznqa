/*!
 * \file	Classes\dataHandle\StaticDataLoader.cpp
 *
 * \brief	定义类 StaticDataLoader
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
	// 手动载入地形卡静态数据 //////////////////////////////////////////////////////////////////////////
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

	// 存入数据 //////////////////////////////////////////////////////////////////////////
	// 将数据转存至卡集CardSet
	CardSet::Instance()->loadCardRoadSet(cardRoadSetTemp);

	// 释放临时量
	cardRoadSetTemp.clear();
	//////////////////////////////////////////////////////////////////////////

	// 验证数据完整性 //////////////////////////////////////////////////////////////////////////
	// 如果地形卡静态数据载入失败
	if (CardSet::Instance()->isCardRoadSetEmpty() == true)
		// 推送失败消息
		LogicMessagePQ::Instance()->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardRoadSetLoadFailed));
	// 否则
	else
		// 推送成功消息
		LogicMessagePQ::Instance()->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_Information_DataLoading_StaticData_CardRoadSetLoadSuccess));
	//////////////////////////////////////////////////////////////////////////
}

void StaticDataLoader::loadStaticDataCardSkillSet()
{
	// 用于创建待解析数据缓存的缓冲区索引
	CharBufferArea::BufferIndex bufferIndex = CharBufferArea::BufferIndex_Static_CardSkillSet;

	// 缓冲相关的静态数据文件 //////////////////////////////////////////////////////////////////////////
	// 根据上文的缓冲区索引以及技能卡集合数据的文件缓存来创建缓冲区，以待解析
	CharBufferArea::Instance()->createBuffer(
		bufferIndex,
		FileController::Instance()->getCharBufferFromFile(STATIC_DATA_CARDSKILLSET)
		);
	// 如果待解析的缓冲区创建失败
	if (CharBufferArea::Instance()->getBufferByIndex(bufferIndex) == nullptr)
	{
		// 安全释放缓冲区
		CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
		// 推送失败消息
		LogicMessagePQ::Instance()->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardSkillSetLoadFailed));
		return;
	}
	//////////////////////////////////////////////////////////////////////////

	// 解析 //////////////////////////////////////////////////////////////////////////
	// 技能卡集合数据解析器
	ParserCardSkill parserCardSkill;
	// 解析
	parserCardSkill.parse();
	// 如果解析失败
	if (ParserCardSkill::cardSkillSetTemp.empty() == true)
	{
		// 释放缓存 //////////////////////////////////////////////////////////////////////////
		ParserCardSkill::cardSkillSetTemp.clear();
		CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
		//////////////////////////////////////////////////////////////////////////
		// 推送失败消息
		LogicMessagePQ::Instance()->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardSkillSetLoadFailed));
		return;
	}
	// 否则
	else
	{
		//  将数据转存至卡集CardSet
		CardSet::Instance()->loadCardSkillSet(ParserCardSkill::cardSkillSetTemp);

		// 如果转存失败
		if (CardSet::Instance()->isCardSkillSetEmpty() == true)
		{
			// 释放缓存 //////////////////////////////////////////////////////////////////////////
			ParserCardSkill::cardSkillSetTemp.clear();
			CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
			//////////////////////////////////////////////////////////////////////////
			// 推送失败消息
			LogicMessagePQ::Instance()->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardSkillSetLoadFailed));
			return;
		}
		// 否则
		else
			// 推送成功消息
			LogicMessagePQ::Instance()->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_Information_DataLoading_StaticData_CardSkillSetLoadSuccess));
	}
	//////////////////////////////////////////////////////////////////////////

	// 释放缓存 //////////////////////////////////////////////////////////////////////////
	ParserCardSkill::cardSkillSetTemp.clear();
	CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
	//////////////////////////////////////////////////////////////////////////
}

void StaticDataLoader::loadStaticDataMainMissionMapSet()
{
	// 用于创建待解析数据缓存的缓冲区索引
	CharBufferArea::BufferIndex bufferIndex = CharBufferArea::BufferIndex_Static_MainMissionMap;

	// 缓冲相关的静态数据文件 //////////////////////////////////////////////////////////////////////////
	// 根据上文的缓冲区索引以及主线任务地图集合数据的文件缓存来创建缓冲区，以待解析
	CharBufferArea::Instance()->createBuffer(
		bufferIndex,
		FileController::Instance()->getCharBufferFromFile(STATIC_DATA_MAINMISSIONMAP)
		);
	// 如果待解析的缓冲区创建失败
	if (CharBufferArea::Instance()->getBufferByIndex(bufferIndex) == nullptr)
	{
		// 安全释放缓冲区
		CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
		// 推送失败消息
		LogicMessagePQ::Instance()->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardMapMainMissionSetSetLoadFailed));
		return;
	}
	//////////////////////////////////////////////////////////////////////////

	// 解析 //////////////////////////////////////////////////////////////////////////
	// 主线任务地图集合解析器
	ParserMapMissionMain parserMapMissionMain;
	// 解析
	parserMapMissionMain.parse();
	// 如果解析失败
	if (ParserMapMissionMain::mainMissionMapSetTemp.empty() == true)
	{
		// 释放缓存 //////////////////////////////////////////////////////////////////////////
		ParserMapMissionMain::mainMissionMapSetTemp.clear();
		CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
		//////////////////////////////////////////////////////////////////////////
		// 推送失败消息
		LogicMessagePQ::Instance()->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardMapMainMissionSetSetLoadFailed));
		return;
	}
	// 否则
	else
	{
		//  将数据转存至卡集CardSet
		MissionMapSet::Instance()->loadMainMissionMapSet(ParserMapMissionMain::mainMissionMapSetTemp);

		// 如果数据转存失败
		if (MissionMapSet::Instance()->isMainMissionMapSetEmpty() == true)
		{
			// 释放缓存 //////////////////////////////////////////////////////////////////////////
			ParserMapMissionMain::mainMissionMapSetTemp.clear();
			CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
			//////////////////////////////////////////////////////////////////////////
			// 推送失败消息
			LogicMessagePQ::Instance()->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardMapMainMissionSetSetLoadFailed));
			return;
		}
		else
		{
			// 推送成功消息
			LogicMessagePQ::Instance()->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_Information_DataLoading_StaticData_MapMainMissionSetLoadSuccess));
		}
	}

	//////////////////////////////////////////////////////////////////////////

	// 释放缓存 //////////////////////////////////////////////////////////////////////////
	ParserMapMissionMain::mainMissionMapSetTemp.clear();
	CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
	//////////////////////////////////////////////////////////////////////////
}