#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_
#define MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_

#include <memory.h>

struct DeltaTable
{
	enum GameObject { GameObject_Role, GameObject_Monster };

	//���ܽ�����
	GameObject recver;

	//�����ͷ���
	GameObject releaser;

	//����Ӱ��Ļ���Ч��
	int effectTable[5][2];

	DeltaTable()
	{
		memset(effectTable, 0, sizeof(effectTable));
	}
};

#endif