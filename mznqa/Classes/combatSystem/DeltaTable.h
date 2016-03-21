#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_
#define MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_


enum EffectObject { Role, Monster };

struct DeltaTable
{

	//���ܽ�����
	EffectObject recver;

	//�����ͷ���
	EffectObject releaser;
	
	//�ͷŸü������ڵĻغ�
	int round;

	//����ID
	int effectId;

	//����Ӱ��Ļ���Ч��
	int effectTable[5][2] = { 0 };

};

struct TableRound 
{
	//���ڻغ�
	int round;

	//���غ��ڵ�Ч���仯��
	int deltaTableRound[5][2];
};


#endif
