#pragma execution_character_set("utf-8")

#include "combatSystem/EffectHistory.h"
#include "combatSystem/DeltaTable.h"
#include <vector>
#include "cocos2d.h"

EffectHistory::EffectHistory()
{

}

EffectHistory::~EffectHistory()
{

}

bool EffectHistory::addRoleHistory(int round,DeltaTable dt)
{
	std::vector<DeltaTable> vecTemp;
	vecTemp.push_back(dt);
	tableRoleHistory.insert(std::make_pair(round, vecTemp));
	cocos2d::log("提示： 添加角色效果历史成功！");
	return true;
}

std::vector<DeltaTable> EffectHistory::getRoundAllRoleTable(int round)
{
	if (round > 0 && round <= tableRoleHistory.size())
	{
		cocos2d::log("提示： 成功获取角色第 %d 回合内的所有技能效果列表！", round);
		return tableRoleHistory.find(round)->second;
	}
}

bool EffectHistory::addMonsterHistory(int round, DeltaTable dt)
{
	std::vector<DeltaTable> vecTemp;
	vecTemp.push_back(dt);
	tableMonsterHistory.insert(std::make_pair(round, vecTemp));
	cocos2d::log("提示： 添加怪物效果历史成功！");
	return true;
}

std::vector<DeltaTable> EffectHistory::getRoundAllMonsterTable(int round)
{
	if (round > 0 && round <= tableMonsterHistory.size())
	{
		cocos2d::log("提示： 成功获取怪物第 %d 回合内的所有技能效果列表！", round);
		return tableMonsterHistory.find(round)->second;
	}
}

void EffectHistory::test()
{
	cocos2d::log("+++++++EffectHistory.test()+++++++++");

	DeltaTable dt;
	dt.recver = DeltaTable::Monster;
	dt.releaser = DeltaTable::Role;
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
