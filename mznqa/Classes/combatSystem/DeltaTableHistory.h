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

	//添加角色表(包括总表)
	bool addTableRoleHistory(const DeltaTable& dt);
	bool addTotalRoleHistory(int round);
	//根据给定的回合数，返回该回合内所有的表（包括总表）
	const std::vector<DeltaTable>& getRoundAllRoleTable(int round);
	//根据给定的回合数和索引，返回指定索引内的所有的表
	const std::vector<DeltaTable>& getRoundRoleTable(int round, DeltaTable::RoundLevel index);
	const std::vector<DeltaTable>& getCurrentRoundRoleTable(int round);

	//添加怪物表（包括总表）
	bool addTableMonsterHistory(DeltaTable dt);
	const std::vector<DeltaTable>& getRoundAllMonsterTable(int round);
	const std::vector<DeltaTable>& getRoundMonsterTable(int round, DeltaTable::RoundLevel index);
	const std::vector<DeltaTable>& getCurrentRoundMonsterTable(int round);
	bool addTotalMonsterHistory(int round);
	//void setRoundNumberMonster();
	void text();

private:

	//存储角色表
	std::vector<DeltaTable> tableRoleHistory;
	//存储角色回合
	std::vector<DeltaRound> roundRoleHistory;
	//记录角色的回合数
	int roundNumberRole = 1;

	//存储怪物表
	std::vector<DeltaTable> tableMonsterHistory;
	//存储怪物回合
	std::vector<DeltaRound> roundMonsterHistory;
	//记录怪物的回合数
	int roundNumberMonster = 1;

	//存放单回合内或其部分的表
	std::vector<DeltaTable> roundTemp;
};


#endif // !MZNQA_CLASSES_COMBATSYSTEM_DELTATABLEHISTORY_H_

