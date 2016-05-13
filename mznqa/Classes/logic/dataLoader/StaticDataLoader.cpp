/*!
 * \file	Classes\logic\dataLoader\StaticDataLoader.cpp
 *
 * \brief	定义类 StaticDataLoader
 */

#pragma execution_character_set("utf-8")

#include "logic/dataLoader/StaticDataLoader.h"

#include <string>

#include "logic/data/info/DataFilePath.h"
#include "helper/fileManager/FileManager.h"
#include "helper/bridge/Bridge.h"
#include "logic/message/LogicMessagePQ.h"
#include "helper/dataLoader/ParseStringSet.h"
#include "logic/data/static/stringSet/StringSet.h"
#include "helper/dataLoader/ParseCardRoadSet.h"
#include "logic/data/static/card/CardSet.h"
#include "helper/dataLoader/ParseMissionMapMain.h"

bool StaticDataLoader::loadStringSet()
{
	// 获取当前语言
	auto language = Bridge::Instance()->getLanguage();

	// 保存文件缓存
	char *buffer = nullptr;

	// 根据文件载入对应的文件
	switch (language)
	{
	case Bridge::Language_Zh:
		buffer = FileManager::Instance()->getDataFromFile(DATAFILEPATH_STRINGSETZH);
		if (buffer == nullptr)
		{
			LogicMessagePQ::Instance()->pushMessage(
				ArKCa::Message<LogicMessagePQ::LogicMessageID>(
				LogicMessagePQ::LogicMessageID_FileLoadingFail_String_Zh_Json
				)
				);
			return false;
		}
		else
		{
			LogicMessagePQ::Instance()->pushMessage(
				ArKCa::Message<LogicMessagePQ::LogicMessageID>(
				LogicMessagePQ::LogicMessageID_FileLoadingSucc_String_Zh_Json
				)
				);
		}
		break;
	case Bridge::Language_En:
		buffer = FileManager::Instance()->getDataFromFile(DATAFILEPATH_STRINGSETEN);
		if (buffer == nullptr)
		{
			LogicMessagePQ::Instance()->pushMessage(
				ArKCa::Message<LogicMessagePQ::LogicMessageID>(
				LogicMessagePQ::LogicMessageID_FileLoadingFail_String_En_Json
				)
				);
			return false;
		}
		else
		{
			LogicMessagePQ::Instance()->pushMessage(
				ArKCa::Message<LogicMessagePQ::LogicMessageID>(
				LogicMessagePQ::LogicMessageID_FileLoadingSucc_String_En_Json
				)
				);
		}
		break;
	default:
		LogicMessagePQ::Instance()->pushMessage(
			ArKCa::Message<LogicMessagePQ::LogicMessageID>(
			LogicMessagePQ::LogicMessageID_FileLoadingFail_String_Set
			)
			);
		return false;
	}

	if (ParseStringSet::parse(buffer) == true)
	{
		LogicMessagePQ::Instance()->pushMessage(
			ArKCa::Message<LogicMessagePQ::LogicMessageID>(
			LogicMessagePQ::LogicMessageID_ParsingSucc_String_Set
			)
			);

		StringSet::Instance()->init(ParseStringSet::bufferStringSet);

		LogicMessagePQ::Instance()->pushMessage(
			ArKCa::Message<LogicMessagePQ::LogicMessageID>(
			LogicMessagePQ::LogicMessageID_DataLoadingSucc_String_Set
			)
			);
	}
	else
	{
		LogicMessagePQ::Instance()->pushMessage(
			ArKCa::Message<LogicMessagePQ::LogicMessageID>(
			LogicMessagePQ::LogicMessageID_ParsingFail_String_Set
			)
			);

		FileManager::releaseData(buffer);
		return false;
	}

	FileManager::releaseData(buffer);
	return true;
}

bool StaticDataLoader::loadCardRoadSet()
{
	char* buffer = FileManager::Instance()->getDataFromFile(DATAFILEPATH_CARDROADSET);
	if (buffer == nullptr)
	{
		LogicMessagePQ::Instance()->pushMessage(
			ArKCa::Message<LogicMessagePQ::LogicMessageID>(
			LogicMessagePQ::LogicMessageID_FileLoadingFail_Card_Road_Json
			)
			);
		return false;
	}
	else
	{
		LogicMessagePQ::Instance()->pushMessage(
			ArKCa::Message<LogicMessagePQ::LogicMessageID>(
			LogicMessagePQ::LogicMessageID_FileLoadingSucc_Card_Road_Json
			)
			);
	}

	if (ParseCardRoadSet::parse(buffer) == true)
	{
		LogicMessagePQ::Instance()->pushMessage(
			ArKCa::Message<LogicMessagePQ::LogicMessageID>(
			LogicMessagePQ::LogicMessageID_ParsingSucc_CardRoad_Set
			)
			);
		CardSet::Instance()->loadCardRoadSet(ParseCardRoadSet::bufferCardRoadSet);
		LogicMessagePQ::Instance()->pushMessage(
			ArKCa::Message<LogicMessagePQ::LogicMessageID>(
			LogicMessagePQ::LogicMessageID_DataLoadingSucc_CardRoad_Set
			)
			);
	}
	else
	{
		LogicMessagePQ::Instance()->pushMessage(
			ArKCa::Message<LogicMessagePQ::LogicMessageID>(
			LogicMessagePQ::LogicMessageID_ParsingFail_CardRoad_Set
			)
			);
		FileManager::releaseData(buffer);
		return false;
	}

	FileManager::releaseData(buffer);
	return true;
}

bool StaticDataLoader::loadMissionMapMain(MissionMapSet::MissionMapIDMain id)
{
	std::string fileName;
	switch (id)
	{
	case MissionMapSet::MissionMapIDMain_0:
		fileName = std::string(DATAFILEPATH_MISSIONMAP_MAIN_0);
		break;
	default:
		break;
	}

	char* buffer = FileManager::Instance()->getDataFromFile(fileName);
	if (buffer == nullptr)
	{
		LogicMessagePQ::Instance()->pushMessage(
			ArKCa::Message<LogicMessagePQ::LogicMessageID>(
			LogicMessagePQ::LogicMessageID_FileLoadingFail_MissionMap_Map_TMissionMapSet__MissionMapIDMainT,
			id
			)
			);
		return false;
	}
	else
	{
		LogicMessagePQ::Instance()->pushMessage(
			ArKCa::Message<LogicMessagePQ::LogicMessageID>(
			LogicMessagePQ::LogicMessageID_FileLoadingSucc_MissionMap_Map_TMissionMapSet__MissionMapIDMainT,
			id
			)
			);
	}

	if (ParseMissionMapMain::parse(buffer) == true)
	{
		LogicMessagePQ::Instance()->pushMessage(
			ArKCa::Message<LogicMessagePQ::LogicMessageID>(
			LogicMessagePQ::LogicMessageID_ParsingSucc_MissionMap_Map_TMissionMapSet__MissionMapIDMainT,
			id
			)
			);

		MissionMapSet::Instance()->loadMapMain(id, GameMap(ParseMissionMapMain::bufferMapNodeSet));

		LogicMessagePQ::Instance()->pushMessage(
			ArKCa::Message<LogicMessagePQ::LogicMessageID>(
			LogicMessagePQ::LogicMessageID_DataLoadingSucc_MissionMap_Map_TMissionMapSet__MissionMapIDMainT,
			id
			)
			);
	}
	else
	{
		LogicMessagePQ::Instance()->pushMessage(
			ArKCa::Message<LogicMessagePQ::LogicMessageID>(
			LogicMessagePQ::LogicMessageID_ParsingFail_MissionMap_Map_TMissionMapSet__MissionMapIDMainT
			)
			);
		FileManager::releaseData(buffer);
		return false;
	}

	FileManager::releaseData(buffer);
	return true;
}

bool StaticDataLoader::loadMissionMapSecondary(MissionMapSet::MissionMapIDSecondary id)
{
	std::string fileName;
	switch (id)
	{
	default:
		break;
	}
	return true;
}