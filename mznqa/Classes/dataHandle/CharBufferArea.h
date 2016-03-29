#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_DATAHANDLE_CHARBUFFERAREA_H_
#define MZNQA_CLASSES_DATAHANDLE_CHARBUFFERAREA_H_

#include <map>

// ����������ַ����棬�������ļ��ȵ�
class CharBufferArea
{
private:
	CharBufferArea(){}
	CharBufferArea(const CharBufferArea&);
	CharBufferArea& operator=(const CharBufferArea&);

	// ��������¼�ַ�����
	std::map<int, char*> bufferSet;

public:
	// ö���ַ���������
	enum BufferIndex
	{
		// ��̬����-���� //////////////////////////////////////////////////////////////////////////
		BufferIndex_CardSkill = 0,
		//////////////////////////////////////////////////////////////////////////

		// �浵-��ͼ //////////////////////////////////////////////////////////////////////////
		BufferIndex_MapArchives = 1
		//////////////////////////////////////////////////////////////////////////
	};

	static CharBufferArea* Instance();
	~CharBufferArea();

	// ������������ע�⴫��Ļ������ free() ���ͷ�
	bool createBuffer(BufferIndex bufferIndex, char *buffer);
	// �ͷ�ָ�������Ļ�������ʹ�� free() �ͷ�
	bool releaseBufferByIndex(BufferIndex bufferIndex);

	// �ͷ����л�������ʹ�� free() �ͷ�
	void releaseAllBuffer();

	// ��ȡָ��������Ӧ�Ļ�������ֻ�������ݶ��������ڸ����б���ֻ���ַ�����
	const char* getBufferByIndex(BufferIndex bufferIndex);

	// ��Ԫ����
	void test();
};

#endif
