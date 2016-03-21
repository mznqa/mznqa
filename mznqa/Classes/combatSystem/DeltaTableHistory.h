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


	//添加角色表
	bool addRoleHistory(int round,DeltaTable dt);

	//获取角色某回合内所有的历史表
	const std::vector<DeltaTable>& getRoundAllRoleTable(int round);
	

	//添加怪物表
	bool addMonsterHistory(int round, DeltaTable dt);

	//获取怪物某回合内所有的历史表
	const std::vector<DeltaTable>& getRoundAllMonsterTable(int round);

	void test();
	
private:

	//存储角色表
	std::map <int,std::vector< DeltaTable >> tableRoleHistory;

	//存储怪物表
	std::map<int, std::vector< DeltaTable >> tableMonsterHistory;

	std::vector<DeltaTable> nullVector;
};



#endif // !MZNQA_CLASSES_COMBATSYSTEM_DELTATABLEHISTORY_H_

