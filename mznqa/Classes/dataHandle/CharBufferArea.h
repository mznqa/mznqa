#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_DATAHANDLE_CHARBUFFERAREA_H_
#define MZNQA_CLASSES_DATAHANDLE_CHARBUFFERAREA_H_

#include <map>

// 单例，存放字符缓存，可来自文件等等
class CharBufferArea
{
private:
	CharBufferArea(){}
	CharBufferArea(const CharBufferArea&);
	CharBufferArea& operator=(const CharBufferArea&);

	// 按索引记录字符缓冲
	std::map<int, char*> bufferSet;

public:
	// 枚举字符缓冲索引
	enum BufferIndex
	{
		// 静态数据-卡牌 //////////////////////////////////////////////////////////////////////////
		BufferIndex_CardSkill = 0,
		//////////////////////////////////////////////////////////////////////////

		// 存档-地图 //////////////////////////////////////////////////////////////////////////
		BufferIndex_MapArchives = 1
		//////////////////////////////////////////////////////////////////////////
	};

	static CharBufferArea* Instance();
	~CharBufferArea();

	// 创建缓冲区，注意传入的缓存仅由 free() 做释放
	bool createBuffer(BufferIndex bufferIndex, char *buffer);
	// 释放指定索引的缓冲区，使用 free() 释放
	bool releaseBufferByIndex(BufferIndex bufferIndex);

	// 释放所有缓冲区，使用 free() 释放
	void releaseAllBuffer();

	// 获取指定索引对应的缓冲区（只读），暂定仅允许在该类中保存只读字符缓存
	const char* getBufferByIndex(BufferIndex bufferIndex);

	// 单元测试
	void test();
};

#endif
