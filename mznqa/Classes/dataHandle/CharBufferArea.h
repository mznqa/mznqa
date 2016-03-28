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

	// ����������
	bool createBuffer(int bufferIndex, char *buffer);
	// �ͷ�ָ����Ӱ�Ļ�����
	bool releaseBufferByIndex(int bufferIndex);

	// �ͷ����л�����
	void releaseAllBuffer();

	// ��ȡָ��������Ӧ�Ļ�����
	const char* getBufferByIndex(int bufferIndex);

	void test();
};

#endif
