#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_DELTATABLEHISTORY_H_
#define MZNQA_CLASSES_COMBATSYSTEM_DELTATABLEHISTORY_H_

#include <vector>

#include "combatSystem/DeltaTable.h"


class DeltaTableHistory
{
public:

	DeltaTableHistory();

	~DeltaTableHistory();

	//��ӽ�ɫ��(�����ܱ�)
	bool addTableRoleHistory(const DeltaTable& dt);
	bool addTotalRoleHistory(int round);
	//���ݸ����Ļغ��������ظûغ������еı������ܱ�
	const std::vector<DeltaTable>& getRoundAllRoleTable(int round);
	//���ݸ����Ļغ���������������ָ�������ڵ����еı�
	const std::vector<DeltaTable>& getRoundRoleTable(int round, DeltaTable::RoundLevel index);
	const std::vector<DeltaTable>& getCurrentRoundRoleTable(int round);

	//��ӹ���������ܱ�
	bool addTableMonsterHistory(DeltaTable dt);
	const std::vector<DeltaTable>& getRoundAllMonsterTable(int round);
	const std::vector<DeltaTable>& getRoundMonsterTable(int round, DeltaTable::RoundLevel index);
	const std::vector<DeltaTable>& getCurrentRoundMonsterTable(int round);
	bool addTotalMonsterHistory(int round);
	//void setRoundNumberMonster();
	void text();

private:

	//�洢��ɫ��
	std::vector<DeltaTable> tableRoleHistory;
	//�洢��ɫ�غ�
	std::vector<DeltaRound> roundRoleHistory;
	//��¼��ɫ�Ļغ���
	int roundNumberRole = 1;

	//�洢�����
	std::vector<DeltaTable> tableMonsterHistory;
	//�洢����غ�
	std::vector<DeltaRound> roundMonsterHistory;
	//��¼����Ļغ���
	int roundNumberMonster = 1;

	//��ŵ��غ��ڻ��䲿�ֵı�
	std::vector<DeltaTable> roundTemp;
};


#endif // !MZNQA_CLASSES_COMBATSYSTEM_DELTATABLEHISTORY_H_

