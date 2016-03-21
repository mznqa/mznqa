#pragma execution_character_set("utf-8")

#include "combatSystem/DeltaTableHistory.h"

#include <vector>

#include "cocos2d.h"

#include "combatSystem/DeltaTable.h"

DeltaTableHistory::DeltaTableHistory()
{

}

DeltaTableHistory::~DeltaTableHistory()
{

}

bool DeltaTableHistory::addRoleHistory(int round,DeltaTable dt)
{
	if (round <= 0)
	{
		cocos2d::log("警告： 添加角色表失败，指定回合数为%d", round);
		return false;
	}

	tableRoleHistory[round].push_back(dt);

	cocos2d::log("提示： 添加角色历史表成功！");
	return true;
}

const std::vector<DeltaTable>& DeltaTableHistory::getRoundAllRoleTable(int round)
{
	if (round > 0 && round <= tableRoleHistory.size())
	{
		cocos2d::log("提示： 成功获取角色第 %d 回合内的所有表！", round);
		return tableRoleHistory[round];
	}

	return nullVector;
}

bool DeltaTableHistory::addMonsterHistory(int round, DeltaTable dt)
{
	if (round <= 0)
	{
		cocos2d::log("警告： 添加怪物表失败，指定回合数为%d", round);
		return false;
	};

	tableMonsterHistory[round].push_back(dt);

	cocos2d::log("提示： 添加怪物表成功！");
	return true;
}

const std::vector<DeltaTable>& DeltaTableHistory::getRoundAllMonsterTable(int round)
{
	if (round > 0 && round <= tableMonsterHistory.size())
	{
		cocos2d::log("提示： 成功获取怪物第 %d 回合内的所有表！", round);
		return tableMonsterHistory[round];
	}

	return nullVector;
}

void DeltaTableHistory::test()
{
	cocos2d::log("+++++++EffectHistory.test()+++++++++");

	DeltaTable dt;
	dt.recver = DeltaTable::GameObject_Monster;
	dt.releaser = DeltaTable::GameObject_Role;
	dt.effectTable[0][1] = -1;
	addRoleHistory(1, dt);
	std::vector<DeltaTable> vtd;
	vtd=getRoundAllRoleTable(1);
	std::vector<DeltaTable>::iterator it;
	for (it = vtd.begin();it != vtd.end();it++)
	{
			for (int i = 0;i < 5;i++)
			{
				for (int j = 0;j < 2;j++)
				{
					cocos2d::log("\t%d", it->effectTable[i][j]);
				}
			}
		
	}
	cocos2d::log("--------EffectHistory.test()--------");
}
