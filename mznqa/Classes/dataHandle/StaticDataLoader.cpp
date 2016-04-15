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
#include "map/MapController.h"
#include "dataHandle/ParserMapArchives.h"
#include "dataHandle/ParserMapMissionMain.h"
#include "staticData/MissionMapSet.h"

void StaticDataLoader::loadStaticDataCardRoadSet()
{
	cocos2d::log("[information] 开始载入静态数据：地形卡数据...");

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

	cocos2d::log("[information] 完成：载入静态数据：地形卡数据");
}

void StaticDataLoader::loadStaticDataCardSkillSet()
{
	CharBufferArea::BufferIndex bufferIndex = CharBufferArea::BufferIndex_Static_CardSkillSet;

	cocos2d::log("[information] 开始缓存文件数据：静态数据：技能卡集合...");
	CharBufferArea::Instance()->createBuffer(
		bufferIndex,
		FileController::Instance()->getCharBufferFromFile(STATIC_DATA_CARDSKILLSET)
		);
	if (CharBufferArea::Instance()->getBufferByIndex(bufferIndex) == nullptr)
		cocos2d::log("[error] 缓存失败：静态数据：技能卡集合");
	else
		cocos2d::log("[information] 成功缓存：静态数据：技能卡集合");

	//////////////////////////////////////////////////////////////////////////

	cocos2d::log("[information] 开始解析：静态数据：技能卡集合...");
	ParserCardSkill parserCardSkill;
	parserCardSkill.parse();
	if (ParserCardSkill::cardSkillSetTemp.empty() == true)
		cocos2d::log("[error] 解析失败：静态数据：技能卡集合");
	else
	{
		CardSet::Instance()->loadCardSkillSet(ParserCardSkill::cardSkillSetTemp);
		cocos2d::log("[information] 完成解析：静态数据：技能卡集合");
	}

	//////////////////////////////////////////////////////////////////////////

	cocos2d::log("[information] 开始释放缓存：静态数据：技能卡集合...");
	ParserCardSkill::cardSkillSetTemp.clear();
	CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
	cocos2d::log("[information] 成功释放缓存：静态数据：技能卡集合");
}

void StaticDataLoader::loadStaticDataMainMissionMapSet()
{
	CharBufferArea::BufferIndex bufferIndex = CharBufferArea::BufferIndex_Static_MainMissionMap;

	cocos2d::log("[information] 开始缓存文件数据：静态数据：主线任务地图集合...");
	CharBufferArea::Instance()->createBuffer(
		bufferIndex,
		FileController::Instance()->getCharBufferFromFile(STATIC_DATA_MAINMISSIONMAP)
		);
	if (CharBufferArea::Instance()->getBufferByIndex(bufferIndex) == nullptr)
		cocos2d::log("[error] 缓存失败：静态数据：主线任务地图集合");
	else
		cocos2d::log("[information] 成功缓存：静态数据：主线任务地图集合");

	//////////////////////////////////////////////////////////////////////////

	cocos2d::log("[information] 开始解析：静态数据：主线任务地图集合...");
	ParserMapMissionMain parserMapMissionMain;
	parserMapMissionMain.parse();
	if (ParserMapMissionMain::mainMissionMapSetTemp.empty() == true)
		cocos2d::log("[error] 解析失败：静态数据：主线任务地图集合");
	else
	{
		MissionMapSet::Instance()->loadMainMissionMapSet(ParserMapMissionMain::mainMissionMapSetTemp);
		cocos2d::log("[information] 完成解析：静态数据：主线任务地图集合");
	}

	//////////////////////////////////////////////////////////////////////////

	cocos2d::log("[information] 开始释放缓存：静态数据：主线任务地图集合...");
	ParserMapMissionMain::mainMissionMapSetTemp.clear();
	CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
	cocos2d::log("[information] 成功释放缓存：静态数据：主线任务地图集合");
}

void StaticDataLoader::loadArchivesDataGlobalMap()
{
	CharBufferArea::BufferIndex bufferIndex = CharBufferArea::BufferIndex_Archives_GlobalMap;

	cocos2d::log("[information] 开始缓存文件数据：存档：全局地图...");
	CharBufferArea::Instance()->createBuffer(
		bufferIndex,
		FileController::Instance()->getCharBufferFromFile(ARCHIVES_DATA_GLOBALMAP)
		);
	if (CharBufferArea::Instance()->getBufferByIndex(bufferIndex) == nullptr)
		cocos2d::log("[error] 缓存失败：存档：全局地图");
	else
		cocos2d::log("[information] 成功缓存：存档：全局地图");

	//////////////////////////////////////////////////////////////////////////

	cocos2d::log("[information] 开始解析：存档：全局地图...");
	ParserMapArchives parserMapArchives;
	parserMapArchives.parse();
	if (ParserMapArchives::globalMapArchivesTemp.empty() == true)
		cocos2d::log("[error] 解析失败：存档：全局地图");
	else
	{
		MapController::Instance()->loadMapNode(ParserMapArchives::globalMapArchivesTemp);
		cocos2d::log("[information] 完成解析：存档：全局地图");
	}

	//////////////////////////////////////////////////////////////////////////

	cocos2d::log("[information] 开始释放缓存：存档：全局地图...");
	ParserMapArchives::globalMapArchivesTemp.clear();
	CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
	cocos2d::log("[information] 成功释放缓存：存档：全局地图");
}