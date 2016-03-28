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
	cocos2d::log("[information] 正在尝试创建字符缓冲区...");
	if (bufferIndex < 0)
	{
		cocos2d::log("[error] 缓冲区创建失败，给定的索引值不合法");
		return false;
	}
	if (buffer == nullptr)
	{
		cocos2d::log("[error] 缓冲区创建失败，给定的缓冲为空");
		return false;
	}
	if (bufferSet.empty() == false && bufferSet.find(bufferIndex) != bufferSet.end())
	{
		cocos2d::log("[error] 缓冲区创建失败，给定的索引的缓冲区已创建");
		return false;
	}

	bufferSet[bufferIndex] = buffer;

	cocos2d::log("[information] 缓冲区创建成功，缓冲区索引为%d", bufferIndex);
	return true;
}

bool CharBufferArea::releaseBufferByIndex(int bufferIndex)
{
	cocos2d::log("[information] 正在尝试释放指定字符缓冲区...");
	auto it = bufferSet.find(bufferIndex);
	if (it == bufferSet.end())
	{
		cocos2d::log("[error] 缓冲区释放失败，未找到给定的索引所对应的缓冲区");
		return false;
	}

	free(it->second);
	it->second = nullptr;
	cocos2d::log("[information] 索引为%d的缓冲区释放成功", bufferIndex);
	return true;
}

void CharBufferArea::releaseAllBuffer()
{
	auto it = bufferSet.begin();
	auto itEnd = bufferSet.end();
	while (it != itEnd)
	{
		free(it->second);
		it->second = nullptr;
	}
	cocos2d::log("[information] 所以缓冲区均已释放成功");
}

const char* CharBufferArea::getBufferByIndex(int bufferIndex)
{
	if (bufferSet.find(bufferIndex) == bufferSet.end())
	{
		cocos2d::log("[error] 获取缓冲区失败，未找到给定的索引所对应的缓冲区");
		return nullptr;
	}
	return bufferSet[bufferIndex];
}

void CharBufferArea::test()
{
	//createBuffer(CharBufferArea::BufferIndex_CardSkill, FileController::Instance()->getCharBufferFromFile("data/static/card_skill.json"));
	createBuffer(CharBufferArea::BufferIndex_MapArchives, FileController::Instance()->getCharBufferFromFile("data/archives/map.json"));
}