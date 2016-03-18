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

int JsonParser::createBuffer(char *stream)
{
	// ��������Ч�ļ���ʱ����ֹ����
	if (stream == NULL)
		return -1;
	// ��û�п��õĻ�����ʱ����ֹ����
	int index = getNextBufferCount();
	if (index < 0)
		return -1;

	clearBuffer(index);
	if (index == 0)
	{
		ss0 = new rapidjson::StringStream(stream);
		jdom0 = new rapidjson::Document();
		jdom0->ParseStream(*ss0);
		if (jdom0->HasParseError())
		{
			// TODO ���ͽ���������Ϣ
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
		ss1 = new rapidjson::StringStream(stream);
		jdom1 = new rapidjson::Document();
		jdom1->ParseStream(*ss1);
		if (jdom0->HasParseError())
		{
			// TODO ���ͽ���������Ϣ

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
		ss2 = new rapidjson::StringStream(stream);
		jdom2 = new rapidjson::Document();
		jdom2->ParseStream(*ss2);
		if (jdom0->HasParseError())
		{
			// TODO ���ͽ���������Ϣ

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
		delete ss0;
		ss0 = nullptr;
		bufferCheck[bufferIndex] = false;
	}
	else if (bufferIndex = 1)
	{
		delete jdom0;
		jdom0 = nullptr;
		delete ss0;
		ss0 = nullptr;
		bufferCheck[bufferIndex] = false;
	}
	else if (bufferIndex = 2)
	{
		delete jdom0;
		jdom0 = nullptr;
		delete ss0;
		ss0 = nullptr;
		bufferCheck[bufferIndex] = false;
	}
	else
		;
}

void JsonParser::test()
{
	cocos2d::log("++++ JsonParser::test()");
	cocos2d::log("%s", cocos2d::CCFileUtils::sharedFileUtils()->getWritablePath().c_str());
	cocos2d::log("%s", cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename(STATIC_DATA_ROLE).c_str());
	// �����ļ�
	if (!FileCache::Instance()->loadRoleStaticDataFile(
		cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename(STATIC_DATA_ROLE).c_str(),
		"r"
		))
		return;
	// ����json������
	int bi = createBuffer(FileCache::Instance()->getRoleStaticDataFile());
	// ��������ɹ�
	if (bi != -1)
	{
		// ����json
		cocos2d::log("%s", (*getJsonDOMByBufferIndex(bi))["name"].GetString());
		cocos2d::log("%d", (*getJsonDOMByBufferIndex(bi))["bloodMax"].GetInt());
	}
	// ���ջ�����
	clearBuffer(bi);
	FileCache::Instance()->closeRoleStaticDataFile();
	cocos2d::log("---- JsonParser::test()");
}