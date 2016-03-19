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
			cocos2d::log("��ʾ���ɹ�������Ϊ%d��json������", i);
			return i;
		}

	cocos2d::log("���󣺵�ǰ�޿��õ�json������");
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
	// ��������Ч�ļ���ʱ����ֹ����
	if (stream == nullptr || stream->empty() == true)
	{
		cocos2d::log("���󣺳�������յĻ򲻴��ڵ��ļ���������json����������ʧ��");
		return -1;
	}
	// ��û�п��õĻ�����ʱ����ֹ����
	int index = getNextBufferCount();
	if (index < 0)
	{
		cocos2d::log("���󣺵�ǰû�п����json���������ã�json����������ʧ��");
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
			// TODO ���ͽ���������Ϣ
			cocos2d::log("����JSON��������");
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
			// TODO ���ͽ���������Ϣ
			cocos2d::log("����JSON��������");
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
			// TODO ���ͽ���������Ϣ
			cocos2d::log("����JSON��������");
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
		cocos2d::log("��ʾ��json�����������0���ͷųɹ�");
	}
	else if (bufferIndex == 1)
	{
		delete jdom0;
		jdom0 = nullptr;
		delete ss0;
		ss0 = nullptr;
		bufferCheck[bufferIndex] = false;
		cocos2d::log("��ʾ��json�����������1���ͷųɹ�");
	}
	else if (bufferIndex == 2)
	{
		delete jdom0;
		jdom0 = nullptr;
		delete ss0;
		ss0 = nullptr;
		bufferCheck[bufferIndex] = false;
		cocos2d::log("��ʾ��json�����������2���ͷųɹ�");
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
	// �ͷ��ļ�����
	FileCache::Instance()->closeRoleStaticDataFile();
	cocos2d::log("---- JsonParser::test()");
}