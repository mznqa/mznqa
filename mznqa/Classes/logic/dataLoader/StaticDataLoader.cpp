/*!
 * \file	Classes\logic\dataLoader\StaticDataLoader.cpp
 *
 * \brief	������ StaticDataLoader
 */

#pragma execution_character_set("utf-8")

#include "logic/dataLoader/StaticDataLoader.h"

#include "logic/data/info/DataFilePath.h"
#include "helper/fileManager/FileManager.h"
#include "helper/bridge/Bridge.h"
#include "logic/message/LogicMessagePQ.h"
#include "helper/dataLoader/ParseStringSet.h"
#include "logic/data/static/stringSet/StringSet.h"
#include "helper/dataLoader/ParseCardRoadSet.h"
#include "logic/data/static/card/CardSet.h"

bool StaticDataLoader::loadStringSet()
{
	// ��ȡ��ǰ����
	auto language = Bridge::Instance()->getLanguage();

	// �����ļ�����
	char *buffer = nullptr;

	// �����ļ������Ӧ���ļ�
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

		free(buffer);
		buffer = nullptr;
		return false;
	}

	free(buffer);
	buffer = nullptr;
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
		free(buffer);
		buffer = nullptr;
		return false;
	}

	free(buffer);
	buffer = nullptr;
	return true;
}