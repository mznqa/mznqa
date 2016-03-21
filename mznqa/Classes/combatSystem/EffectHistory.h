#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_EFFECTHISTORY_H_
#define MZNQA_CLASSES_COMBATSYSTEM_EFFECTHISTORY_H_

#include "combatSystem/DeltaTable.h"
#include <vector>

class EffectHistory
{
public:

	EffectHistory();

	~EffectHistory();

	//������ʷ����
	bool effectIsRelease(int effectId);

	//��ӵ���Ч����ʷ����
	bool addDTHistory(DeltaTable dt);

	//��ӻغ��ܱ�
	bool addTRHiatory(TableRound tr);

	//��ȡĳ���غ��ڵĽ����ܱ�
	TableRound getTableRound(int round);

	//����غ��ܱ�
	TableRound calcTableRound(int round);

	void test();
	
private:

	//�洢����Ч�����
	std::vector <DeltaTable> tableHistory;

	//�洢ÿ���غ��ܵĽ�����
	std::vector <TableRound> tableRound;
};



#endif // !MZNQA_CLASSES_COMBATSYSTEM_EFFECTHISTORY_H_

