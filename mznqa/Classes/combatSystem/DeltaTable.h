#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_
#define MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_

struct DeltaTable
{

	enum EffectObject { Role, Monster };

	//���ܽ�����
	EffectObject recver;

	//�����ͷ���
	EffectObject releaser;

	//����Ӱ��Ļ���Ч��
	int effectTable[5][2] = { 0 };
	 
};

#endif