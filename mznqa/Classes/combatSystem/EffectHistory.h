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


	//添加单个效果历史技能
	bool addRoleHistory(int round,DeltaTable dt);

	//获取角色某回合内所有的历史效果表
	std::vector<DeltaTable> getRoundAllRoleTable(int round);
	

	//添加单个效果历史技能
	bool addMonsterHistory(int round, DeltaTable dt);

	//获取怪物某回合内所有的历史效果表
	std::vector<DeltaTable> getRoundAllMonsterTable(int round);

	void test();
	
private:

	//存储角色单个效果表格
	std::multimap <int,std::vector< DeltaTable >> tableRoleHistory;

	//存储怪物单个效果表格
	std::multimap<int, std::vector< DeltaTable >> tableMonsterHistory;

};



#endif // !MZNQA_CLASSES_COMBATSYSTEM_EFFECTHISTORY_H_

