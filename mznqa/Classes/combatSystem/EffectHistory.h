#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_EFFECTHISTORY_H_
#define MZNQA_CLASSES_COMBATSYSTEM_EFFECTHISTORY_H_

#include "combatSystem/DeltaTable.h"
#include <vector>
#include <map>

class EffectHistory
{
public:

	EffectHistory();

	~EffectHistory();


	//��ӵ���Ч����ʷ����
	bool addRoleHistory(int round,DeltaTable dt);

	//��ȡ��ɫĳ�غ������е���ʷЧ����
	std::vector<DeltaTable> getRoundAllRoleTable(int round);
	

	//��ӵ���Ч����ʷ����
	bool addMonsterHistory(int round, DeltaTable dt);

	//��ȡ����ĳ�غ������е���ʷЧ����
	std::vector<DeltaTable> getRoundAllMonsterTable(int round);

	void test();
	
private:

	//�洢��ɫ����Ч�����
	std::multimap <int,std::vector< DeltaTable >> tableRoleHistory;

	//�洢���ﵥ��Ч�����
	std::multimap<int, std::vector< DeltaTable >> tableMonsterHistory;

};



#endif // !MZNQA_CLASSES_COMBATSYSTEM_EFFECTHISTORY_H_

