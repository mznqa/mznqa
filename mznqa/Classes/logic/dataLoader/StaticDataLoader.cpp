/*!
 * \file	Classes\logic\dataLoader\StaticDataLoader.cpp
 *
 * \brief	定义类 StaticDataLoader
 */

#pragma execution_character_set("utf-8")

#include "logic/dataLoader/StaticDataLoader.h"

#include "logic/data/info/DataFilePath.h"
#include "helper/fileManager/FileManager.h"
#include "helper/bridge/Bridge.h"
#include "logic/message/LogicMessagePQ.h"
#include "helper/dataLoader/ParseStringSet.h"
#include "logic/data/static/StringSet/StringSet.h"

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
				LogicMessagePQ::LogicMessageID_FileLoadingSucc_String_zh_Json
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

	ParseStringSet::parse(buffer);
	StringSet::Instance()->init(ParseStringSet::bufferStringSet);

	free(buffer);
	buffer = nullptr;
	return true;
}