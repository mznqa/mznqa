#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_DELTATABLEHISTORY_H_
#define MZNQA_CLASSES_COMBATSYSTEM_DELTATABLEHISTORY_H_

#include <vector>
#include <map>

#include "combatSystem/DeltaTable.h"

class DeltaTableHistory
{
public:

	DeltaTableHistory();

	~DeltaTableHistory();


	//��ӽ�ɫ��
	bool addRoleHistory(int round,DeltaTable dt);

	//��ȡ��ɫĳ�غ������е���ʷ��
	const std::vector<DeltaTable>& getRoundAllRoleTable(int round);
	

	//��ӹ����
	bool addMonsterHistory(int round, DeltaTable dt);

	//��ȡ����ĳ�غ������е���ʷ��
	const std::vector<DeltaTable>& getRoundAllMonsterTable(int round);

	void test();
	
private:

	//�洢��ɫ��
	std::map <int,std::vector< DeltaTable >> tableRoleHistory;

	//�洢�����
	std::map<int, std::vector< DeltaTable >> tableMonsterHistory;

	std::vector<DeltaTable> nullVector;
};



#endif // !MZNQA_CLASSES_COMBATSYSTEM_DELTATABLEHISTORY_H_

