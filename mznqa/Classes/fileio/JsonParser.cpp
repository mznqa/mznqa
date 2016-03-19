#pragma execution_character_set("utf-8")

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
		{
			cocos2d::log("提示：成功分配编号为%d的json缓冲区", i);
			return i;
		}

	cocos2d::log("错误：当前无可用的json缓冲区");
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

int JsonParser::createBuffer(const std::string *stream)
{
	// 当传入无效文件流时，中止操作
	if (stream == nullptr || stream->empty() == true)
	{
		cocos2d::log("错误：尝试载入空的或不存在的文件数据流，json缓冲区创建失败");
		return -1;
	}
	// 当没有可用的缓冲区时，中止操作
	int index = getNextBufferCount();
	if (index < 0)
	{
		cocos2d::log("错误：当前没有空余的json缓冲区可用，json缓冲区创建失败");
		return -1;
	}

	const char *str = stream->c_str();

	clearBuffer(index);
	if (index == 0)
	{
		ss0 = new rapidjson::StringStream(str);
		jdom0 = new rapidjson::Document();
		jdom0->ParseStream(*ss0);
		if (jdom0->HasParseError())
		{
			// TODO 发送解析错误消息
			cocos2d::log("错误：JSON解析出错");
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
		ss1 = new rapidjson::StringStream(str);
		jdom1 = new rapidjson::Document();
		jdom1->ParseStream(*ss1);
		if (jdom0->HasParseError())
		{
			// TODO 发送解析错误消息
			cocos2d::log("错误：JSON解析出错");
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
		ss2 = new rapidjson::StringStream(str);
		jdom2 = new rapidjson::Document();
		jdom2->ParseStream(*ss2);
		if (jdom0->HasParseError())
		{
			// TODO 发送解析错误消息
			cocos2d::log("错误：JSON解析出错");
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
	if (bufferIndex == 0)
	{
		delete jdom0;
		jdom0 = nullptr;
		delete ss0;
		ss0 = nullptr;
		bufferCheck[bufferIndex] = false;
		cocos2d::log("提示：json缓冲区（编号0）释放成功");
	}
	else if (bufferIndex == 1)
	{
		delete jdom0;
		jdom0 = nullptr;
		delete ss0;
		ss0 = nullptr;
		bufferCheck[bufferIndex] = false;
		cocos2d::log("提示：json缓冲区（编号1）释放成功");
	}
	else if (bufferIndex == 2)
	{
		delete jdom0;
		jdom0 = nullptr;
		delete ss0;
		ss0 = nullptr;
		bufferCheck[bufferIndex] = false;
		cocos2d::log("提示：json缓冲区（编号2）释放成功");
	}
	else
		;
}

void JsonParser::test()
{
	cocos2d::log("++++ JsonParser::test()");
	cocos2d::log("%s", cocos2d::CCFileUtils::sharedFileUtils()->getWritablePath().c_str());
	cocos2d::log("%s", cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename(STATIC_DATA_ROLE).c_str());
	// 缓存文件
	if (!FileCache::Instance()->loadRoleStaticDataFile(
		cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename(STATIC_DATA_ROLE).c_str(),
		"r"
		))
		return;
	// 创建json缓冲区
	int bi = createBuffer(FileCache::Instance()->getRoleStaticDataFile());
	// 如果创建成功
	if (bi != -1)
	{
		// 解析json
		cocos2d::log("%s", (*getJsonDOMByBufferIndex(bi))["name"].GetString());
		cocos2d::log("%d", (*getJsonDOMByBufferIndex(bi))["bloodMax"].GetInt());
	}
	// 回收缓冲区
	clearBuffer(bi);
	// 释放文件缓存
	FileCache::Instance()->closeRoleStaticDataFile();
	cocos2d::log("---- JsonParser::test()");
}