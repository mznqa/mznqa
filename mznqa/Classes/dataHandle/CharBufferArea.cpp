#pragma execution_character_set("utf-8")

#include "dataHandle/CharBufferArea.h"

#include "cocos2d.h"

#include "engine/FileController.h"

CharBufferArea* CharBufferArea::Instance()
{
	static CharBufferArea instance;
	return &instance;
}

CharBufferArea::~CharBufferArea()
{
}

bool CharBufferArea::createBuffer(int bufferIndex, char *buffer)
{
	cocos2d::log("[information] ���ڳ��Դ����ַ�������...");
	if (bufferIndex < 0)
	{
		cocos2d::log("[error] ����������ʧ�ܣ�����������ֵ���Ϸ�");
		return false;
	}
	if (buffer == nullptr)
	{
		cocos2d::log("[error] ����������ʧ�ܣ������Ļ���Ϊ��");
		return false;
	}
	if (bufferSet.empty() == false && bufferSet.find(bufferIndex) == bufferSet.end())
	{
		cocos2d::log("[error] ����������ʧ�ܣ������������Ļ������Ѵ���");
		return false;
	}

	bufferSet[bufferIndex] = buffer;

	cocos2d::log("[information] �����������ɹ�������������Ϊ%d", bufferIndex);
	return true;
}

bool CharBufferArea::releaseBufferByIndex(int bufferIndex)
{
	cocos2d::log("[information] ���ڳ����ͷ�ָ���ַ�������...");
	if (bufferSet.find(bufferIndex) == bufferSet.end())
	{
		cocos2d::log("[error] �������ͷ�ʧ�ܣ�δ�ҵ���������������Ӧ�Ļ�����");
		return false;
	}

	cocos2d::log("[information] ����Ϊ%d�Ļ������ͷųɹ�", bufferIndex);
	return true;
}

void CharBufferArea::releaseAllBuffer()
{
	auto it = bufferSet.begin();
	auto itEnd = bufferSet.end();
	while (it != itEnd)
	{
		delete it->second;
		it->second = nullptr;
	}
	cocos2d::log("[information] ���Ի����������ͷųɹ�");
}

const char* CharBufferArea::getBufferByIndex(int bufferIndex)
{
	if (bufferSet.find(bufferIndex) == bufferSet.end())
	{
		cocos2d::log("[error] ��ȡ������ʧ�ܣ�δ�ҵ���������������Ӧ�Ļ�����");
		return nullptr;
	}
	return bufferSet[bufferIndex];
}

void CharBufferArea::test()
{
	createBuffer(CharBufferArea::BufferIndex_CardSkill, FileController::Instance()->getCharBufferFromFile("data/static/card_skill.json"));
}