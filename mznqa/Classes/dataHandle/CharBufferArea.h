#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_DATAHANDLE_CHARBUFFERAREA_H_
#define MZNQA_CLASSES_DATAHANDLE_CHARBUFFERAREA_H_

#include <map>

class CharBufferArea
{
private:
	CharBufferArea(){}
	CharBufferArea(const CharBufferArea&);
	CharBufferArea& operator=(const CharBufferArea&);

	std::map<int, char*> bufferSet;

public:
	enum BufferIndex
	{
		BufferIndex_CardSkill = 0,
		BufferIndex_MapArchives = 1
	};
	static CharBufferArea* Instance();
	~CharBufferArea();

	// 创建缓冲区
	bool createBuffer(int bufferIndex, char *buffer);
	// 释放指定缩影的缓冲区
	bool releaseBufferByIndex(int bufferIndex);

	// 释放所有缓冲区
	void releaseAllBuffer();

	// 获取指定索引对应的缓冲区
	const char* getBufferByIndex(int bufferIndex);

	void test();
};

#endif
