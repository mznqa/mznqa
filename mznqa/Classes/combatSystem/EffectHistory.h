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

	//查找历史技能
	bool effectIsRelease(int effectId);

	//添加单个效果历史技能
	bool addDTHistory(DeltaTable dt);

	//添加回合总表
	bool addTRHiatory(TableRound tr);

	//获取某个回合内的结算总表
	TableRound getTableRound(int round);

	//计算回合总表
	TableRound calcTableRound(int round);

	void test();
	
private:

	//存储单个效果表格
	std::vector <DeltaTable> tableHistory;

	//存储每个回合总的结算表格
	std::vector <TableRound> tableRound;
};



#endif // !MZNQA_CLASSES_COMBATSYSTEM_EFFECTHISTORY_H_

