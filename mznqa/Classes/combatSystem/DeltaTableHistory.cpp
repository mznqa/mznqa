#pragma execution_character_set("utf-8")

#include "combatSystem/DeltaTableHistory.h"

#include <vector>

#include "cocos2d.h"

#include "combatSystem/DeltaTable.h"

#include "EffectPQ.h"

DeltaTableHistory::DeltaTableHistory()
{
}

DeltaTableHistory::~DeltaTableHistory()
{
}

//bool DeltaTableHistory::addRoleHistory(int round, DeltaTable dt)
//{
//	if (round <= 0)
//	{
//		cocos2d::log("[error]： 添加角色表失败，指定回合数为%d", round);
//		return false;
//	}
//
//	tableRoleHistory[round].push_back(dt);
//
//	cocos2d::log("[information]： 添加角色历史表成功！");
//	return true;
//}
//
//const std::vector<DeltaTable>& DeltaTableHistory::getRoundAllRoleTable(int round)
//{
//	if (round > 0 && round <= tableRoleHistory.size())
//	{
//		cocos2d::log("[information]： 成功获取角色第 %d 回合内的所有表！", round);
//		return tableRoleHistory[round];
//	}
//
//	return nullVector;
//}
//
//bool DeltaTableHistory::addMonsterHistory(int round, DeltaTable dt)
//{
//	if (round <= 0)
//	{
//		cocos2d::log("[error]： 添加怪物表失败，指定回合数为%d", round);
//		return false;
//	};
//
//	tableMonsterHistory[round].push_back(dt);
//
//	cocos2d::log("[information]： 添加怪物表成功！");
//	return true;
//}
//
//const std::vector<DeltaTable>& DeltaTableHistory::getRoundAllMonsterTable(int round)
//{
//	if (round > 0 && round <= tableMonsterHistory.size())
//	{
//		cocos2d::log("[information]： 成功获取怪物第 %d 回合内的所有表！", round);
//		return tableMonsterHistory[round];
//	}
//	
//	return nullVector;
//}
//
//void DeltaTableHistory::test()
//{
//	DeltaTable dt;
//	dt.recver = DeltaTable::GameObject_Monster;
//	dt.releaser = DeltaTable::GameObject_Role;
//	dt.effectTable[0][1] = -1;
//	addRoleHistory(1, dt);
//	std::vector<DeltaTable> vtd;
//	vtd = getRoundAllRoleTable(1);
//	std::vector<DeltaTable>::iterator it;
//	for (it = vtd.begin(); it != vtd.end(); it++)
//	{
//		for (int i = 0; i < 5; i++)
//		{
//			for (int j = 0; j < 2; j++)
//			{
//				cocos2d::log("\t%d", it->effectTable[i][j]);
//			}
//		}
//
//	}
//}

//添加角色表
bool DeltaTableHistory::addTableRoleHistory(DeltaRoleRound dr, DeltaRoleTable dt)
{
	if (dt.roundNumberRole == dr.roundNumberRole)
	{
		tableRoleHistory.push_back(dt);

		if (tableRoleHistory.begin() != tableRoleHistory.end())
		{
			switch (dt.roundLevel)
			{
			case DeltaRoleTable::RoundLevel_Before:
				roundRoleHistory[deltaRoleRound.roundNumberRole - 1].before = tableRoleHistory.size() - 1;
				break;
			case DeltaRoleTable::RoundLevel_In:
				roundRoleHistory[deltaRoleRound.roundNumberRole - 1].in = tableRoleHistory.size() - 1;
				break;
			case DeltaRoleTable::RoundLevel_After:
				roundRoleHistory[deltaRoleRound.roundNumberRole - 1].after = tableRoleHistory.size() - 1;
				break;
			default:
				break;
			}
		}

		//++tableRoleHistory[tableRoleHistory.size() - 1].tableNumberRole;
		cocos2d::log("[information]:角色表添加成功！");
	}
	else if (dt.roundNumberRole == (dr.roundNumberRole + 1))
	{
		DeltaRoleTable total;

		tableRoleHistory.push_back(total);

		for (itRole = roundRoleHistory[deltaRoleRound.roundNumberRole - 1].before;
			itRole <= roundRoleHistory[deltaRoleRound.roundNumberRole - 1].after; ++itRole)
			for (int i = 0; i < total.row; ++i)
				for (int j = 0; j < total.col; ++j)
					tableRoleHistory[tableRoleHistory.size() - 1].effectTable[i][j] += tableRoleHistory[itRole].effectTable[i][j];
		
		roundRoleHistory[deltaRoleRound.roundNumberRole - 1].total = tableRoleHistory.size() - 1;

		//++tableRoleHistory[tableRoleHistory.size() - 1].tableNumberRole;
		cocos2d::log("[information]: 总表添加成功！");
	}

	return true;
}

//添加角色回合
bool DeltaTableHistory::addRoundRoleHistory(DeltaRoleRound dr)
{
	roundRoleHistory.push_back(dr);

	
	//++deltaRoleRound.roundNumberRole;

	cocos2d::log("[information]:角色回合添加成功! ");

	return true;
}

//获取某回合内角色所有的表
const void DeltaTableHistory::getRoundAllRoleTable(
	int beginIt,
	int endIt
	)
{
	if (roundRoleHistory.begin() != roundRoleHistory.end())
	{
		beginIt = roundRoleHistory[detaRoleTable.roundNumberRole].before;
		endIt = roundRoleHistory[detaRoleTable.roundNumberRole].total;

		cocos2d::log("[information]:成功返回角色某回合内所有的表！");
	}
}

void DeltaTableHistory::text()
{
	cocos2d::log("进入Text    *******************************************************");
	DeltaRoleTable dt0;
	dt0.ID = 1;
	dt0.roundLevel = DeltaRoleTable::RoundLevel_Before;
	dt0.roundNumberRole = 1;
	dt0.effectTable[0][0] = 1;
	dt0.effectTable[0][1] = 2;

	DeltaRoleTable dt1;
	dt1.ID = 2;
	dt1.roundLevel = DeltaRoleTable::RoundLevel_After;
	dt1.roundNumberRole = 1;
	dt1.effectTable[0][0] = 2;
	dt1.effectTable[0][1] = -5;

	DeltaRoleTable dt2;
	dt2.ID = 3;
	dt2.roundLevel = DeltaRoleTable::RoundLevel_Before;
	dt2.roundNumberRole = 2;
	dt2.effectTable[1][1] = 5;

	DeltaRoleRound dr1;

	DeltaRoleRound dr2;
	
	addRoundRoleHistory(dr1);
	
	addTableRoleHistory(dr1, dt0);
	
	addTableRoleHistory(dr1, dt1);

	addTableRoleHistory(dr1, dt2);

	auto text1 = tableRoleHistory[roundRoleHistory[deltaRoleRound.roundNumberRole - 1].before];
	auto text2 = tableRoleHistory[roundRoleHistory[deltaRoleRound.roundNumberRole - 1].after];
	auto text3 = tableRoleHistory[roundRoleHistory[deltaRoleRound.roundNumberRole - 1].total];

	auto text4 = tableRoleHistory[roundRoleHistory[deltaRoleRound.roundNumberRole - 1].total];
	auto text5 = text4;

	getRoundAllRoleTable(roundRoleHistory[detaRoleTable.roundNumberRole].before, roundRoleHistory[detaRoleTable.roundNumberRole].after);

	cocos2d::log("退出Text    ******************************************************");

}