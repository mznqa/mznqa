#include "fileio/JsonParser.h"

#include <cstdio>

#include "cocos2d.h"

#include "fileio/FileCache.h"
#include "filePath/DataPath.h"

using rapidjson::FileReadStream;
using rapidjson::Document;

JsonParser* JsonParser::Instance()
{
	static JsonParser instance;
	return &instance;
}

JsonParser::~JsonParser()
{
	for (int i = 0; i < bufferCount; ++i)
		clearBuffer(i);
}

int JsonParser::getBufferCount()
{
	return bufferCount;
}

int JsonParser::getEmptyBufferCount()
{
	int result = 0;
	for (int i = 0; i < bufferCount; ++i)
		if (bufferCheck[i] == false)
			++result;

	return result;
}

int JsonParser::getNextBufferCount()
{
	for (int i = 0; i < bufferCount; ++i)
		if (bufferCheck[i] == false)
			return i;
	return -1;
}

rapidjson::Document* JsonParser::getJsonDOMByBufferIndex(int index)
{
	if (index == 0)
		return jdom0;
	else if (index == 1)
		return jdom1;
	else if (index == 2)
		return jdom2;
	else
		return nullptr;
}

int JsonParser::createBuffer(FILE *file, size_t bufferSize)
{
	// 当传入无效文件时，中止操作
	if (file == NULL)
		return -1;
	// 当指定缓冲区大小小于Rapidjson要求时，中止操作
	if (bufferSize < 4)
		return -1;
	// 当没有可用的缓冲区时，中止操作
	int index = getNextBufferCount();
	if (index < 0)
		return -1;

	clearBuffer(index);
	if (index == 0)
	{
		buffer0 = new char[bufferSize];
		frs0 = new rapidjson::FileReadStream(file, buffer0, bufferSize);
		jdom0 = new rapidjson::Document();
		jdom0->ParseStream(*frs0);
		if (jdom0->HasParseError())
		{
			// TODO 发送解析错误消息

			clearBuffer(index);
			return -1;
		}
		else
		{
			bufferCheck[index] = true;
			return index;
		}
	}
	else if (index == 1)
	{
		buffer1 = new char[bufferSize];
		frs1 = new rapidjson::FileReadStream(file, buffer1, bufferSize);
		jdom1 = new rapidjson::Document();
		jdom1->ParseStream(*frs1);
		if (jdom0->HasParseError())
		{
			// TODO 发送解析错误消息

			clearBuffer(index);
			return -1;
		}
		else
		{
			bufferCheck[index] = true;
			return index;
		}
	}
	else if (index == 2)
	{
		buffer2 = new char[bufferSize];
		frs2 = new rapidjson::FileReadStream(file, buffer2, bufferSize);
		jdom2 = new rapidjson::Document();
		jdom2->ParseStream(*frs2);
		if (jdom0->HasParseError())
		{
			// TODO 发送解析错误消息

			clearBuffer(index);
			return -1;
		}
		else
		{
			bufferCheck[index] = true;
			return index;
		}
	}
	else
		return -1;
}

void JsonParser::clearBuffer(int bufferIndex)
{
	if (bufferIndex = 0)
	{
		delete jdom0;
		jdom0 = nullptr;
		delete frs0;
		frs0 = nullptr;
		delete buffer0;
		buffer0 = nullptr;
		bufferCheck[bufferIndex] = false;
	}
	else if (bufferIndex = 1)
	{
		delete jdom0;
		jdom0 = nullptr;
		delete frs0;
		frs0 = nullptr;
		delete buffer0;
		buffer0 = nullptr;
		bufferCheck[bufferIndex] = false;
	}
	else if (bufferIndex = 2)
	{
		delete jdom0;
		jdom0 = nullptr;
		delete frs0;
		frs0 = nullptr;
		delete buffer0;
		buffer0 = nullptr;
		bufferCheck[bufferIndex] = false;
	}
	else
		;
}

void JsonParser::test()
{
	cocos2d::log("++++ JsonParser::test()");
	// 缓存文件
	if (!FileCache::Instance()->loadRoleStaticDataFile(
		cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename(STATIC_DATA_ROLE).c_str(),
		"r"
		))
		return;

	// 创建json缓冲区
	int bi = createBuffer(*(FileCache::Instance()->getRoleStaticDataFile()), 4096);
	// 如果常见成功
	if (bi != -1)
	{
		// 解析json
		cocos2d::log("%s", (*getJsonDOMByBufferIndex(bi))["name"].GetString());
		cocos2d::log("%d", (*getJsonDOMByBufferIndex(bi))["bloodMax"].GetInt());
	}
	// 回收缓冲区
	clearBuffer(bi);
	FileCache::Instance()->closeRoleStaticDataFile();
	cocos2d::log("---- JsonParser::test()");
}