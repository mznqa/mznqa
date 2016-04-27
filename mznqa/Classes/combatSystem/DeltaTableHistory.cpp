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
//bool DeltaTableHistory::addTableRoleHistory(DeltaRoleRound dr, DeltaRoleTable dt)
//{
//	if (dt.roundNumberRole == dr.roundNumberRole)
//	{
//		tableRoleHistory.push_back(dt);
//
//		if (tableRoleHistory.begin() != tableRoleHistory.end())
//		{
//			switch (dt.roundLevel)
//			{
//			case DeltaRoleTable::RoundLevel_Before:
//				roundRoleHistory[deltaRoleRound.roundNumberRole - 1].before = tableRoleHistory.size() - 1;
//				break;
//			case DeltaRoleTable::RoundLevel_In:
//				roundRoleHistory[deltaRoleRound.roundNumberRole - 1].in = tableRoleHistory.size() - 1;
//				break;
//			case DeltaRoleTable::RoundLevel_After:
//				roundRoleHistory[deltaRoleRound.roundNumberRole - 1].after = tableRoleHistory.size() - 1;
//				break;
//			default:
//				break;
//			}
//		}
//
//		//++tableRoleHistory[tableRoleHistory.size() - 1].tableNumberRole;
//		cocos2d::log("[information]:角色表添加成功！");
//	}
//	else if (dt.roundNumberRole == (dr.roundNumberRole + 1))
//	{
//		DeltaRoleTable total;
//
//		tableRoleHistory.push_back(total);
//
//		for (itRole = roundRoleHistory[deltaRoleRound.roundNumberRole - 1].before;
//			itRole <= roundRoleHistory[deltaRoleRound.roundNumberRole - 1].after; ++itRole)
//			for (int i = 0; i < total.row; ++i)
//				for (int j = 0; j < total.col; ++j)
//					tableRoleHistory[tableRoleHistory.size() - 1].effectTable[i][j] += tableRoleHistory[itRole].effectTable[i][j];
//		
//		roundRoleHistory[deltaRoleRound.roundNumberRole - 1].total = tableRoleHistory.size() - 1;
//
//		//++tableRoleHistory[tableRoleHistory.size() - 1].tableNumberRole;
//		cocos2d::log("[information]: 总表添加成功！");
//	}
//
//	return true;
//}

//添加角色表
bool DeltaTableHistory::addTableRoleHistory(DeltaRoleTable dt)
{
	if (dt.roundNumberRole == roundNumberRole)
	{
		//if (tableRoleHistory.begin() == tableRoleHistory.end())
		//{
		//	tableRoleHistory.push_back(dt);
		//	cocos2d::log("[information]: 角色表添加成功！");
		//}
		//else if (roundNumberRole == 1 && tableRoleHistory.begin() != tableRoleHistory.end()
		//	&& (tableRoleHistory[tableRoleHistory.size() - 1].roundLevel <= dt.roundLevel))
		//{
		//	tableRoleHistory.push_back(dt);
		//	cocos2d::log("[information]: 角色表添加成功！");
		//}
		//else if (roundNumberRole > 1 && (tableRoleHistory[tableRoleHistory.size() - 1].roundLevel > dt.roundLevel))
		//{
		//	tableRoleHistory.push_back(dt);
		//	cocos2d::log("[information]: 角色表添加成功！");
		//}
		//else if (roundNumberRole > 1 && (tableRoleHistory[tableRoleHistory.size() - 1].roundLevel <= dt.roundLevel))
		//{
		//	tableRoleHistory.push_back(dt);
		//	cocos2d::log("[information]: 角色表添加成功！");
		//}
		///*else if (roundNumberRole > 1 && (tableRoleHistory[tableRoleHistory.size() - 1].roundLevel <= dt.roundLevel))
		//{
		//	tableRoleHistory.push_back(dt);
		//	cocos2d::log("[information]: 角色表添加成功！");
		//}*/
		//else
		//{
		//	cocos2d::log("[information]: 角色表添加失败！");
		//	return false;
		//}
		tableRoleHistory.push_back(dt);
		cocos2d::log("[information]: 角色表添加成功！");
		
	}
	else if (dt.roundNumberRole == roundNumberRole + 1)
	{
		DeltaRoleTable total;

		total.ID = tableRoleHistory.size() + 1;
		total.roundNumberRole = roundNumberRole;
		total.roundLevel = DeltaRoleTable::RoundLevel_Total;
		
		tableRoleHistory.push_back(total);

		if (tableRoleHistory.begin() != tableRoleHistory.end())
		{
			if (roundNumberRole == 1)
			{
				for (int n = tableRoleHistory.size() - 1; n >= 0; --n)
				{
					for (int i = 0; i < total.row; ++i)
					{
						for (int j = 0; j < total.col; ++j)
						{
							tableRoleHistory[tableRoleHistory.size() - 1].effectTable[i][j] += tableRoleHistory[n].effectTable[i][j];
						}
					}
				}
			}
			else if (roundNumberRole > 1)
			{
				for (int n = tableRoleHistory.size() - 1; n > roundRoleHistory[roundNumberRole - 2].total; --n)
				{
					for (int i = 0; i < total.row; ++i)
					{
						for (int j = 0; j < total.col; ++j)
						{
							tableRoleHistory[tableRoleHistory.size() - 1].effectTable[i][j] += tableRoleHistory[n].effectTable[i][j];
						}
					}
				}
			}
		}

		DeltaRoleRound dr;
		roundRoleHistory.push_back(dr);

		if (tableRoleHistory.begin() != tableRoleHistory.end())
		{
			if (roundNumberRole == 1)
			{
				for (int i = tableRoleHistory.size() - 1; i >= 0; --i)
				{
					switch (tableRoleHistory[i].roundLevel)
					{
					case DeltaRoleTable::RoundLevel_Before:
						roundRoleHistory[roundNumberRole - 1].before = i;
						break;
					case DeltaRoleTable::RoundLevel_In:
						roundRoleHistory[roundNumberRole - 1].in = i;
						break;
					case DeltaRoleTable::RoundLevel_After:
						roundRoleHistory[roundNumberRole - 1].after = i;
						break;
					case DeltaRoleTable::RoundLevel_Total:
						roundRoleHistory[roundNumberRole - 1].total = i;
						break;
					default:
						break;
					}
				}
			}
			else if (roundNumberRole > 1)
			{
				for (int i = tableRoleHistory.size() - 1; i > roundRoleHistory[roundNumberRole - 2].total; --i)
				{
					switch (tableRoleHistory[i].roundLevel)
					{
					case DeltaRoleTable::RoundLevel_Before:
						roundRoleHistory[roundNumberRole - 1].before = i;
						break;
					case DeltaRoleTable::RoundLevel_In:
						roundRoleHistory[roundNumberRole - 1].in = i;
						break;
					case DeltaRoleTable::RoundLevel_After:
						roundRoleHistory[roundNumberRole - 1].after = i;
						break;
					case DeltaRoleTable::RoundLevel_Total:
						roundRoleHistory[roundNumberRole - 1].total = i;
						break;
					default:
						break;
					}
				}
			}
		}
		cocos2d::log("[information]: 总表添加成功！");
	}

	if (dt.roundNumberRole == roundNumberRole + 1)
	{
		++roundNumberRole;

		DeltaRoleTable dt5;
		dt5.ID = 7;
		dt5.roundLevel = DeltaRoleTable::RoundLevel_Before;
		dt5.roundNumberRole = 3;
		dt5.effectTable[1][1] = 5;

		addTableRoleHistory(dt5);
	}

	return true;
}

//获取某回合内角色所有的表
const void DeltaTableHistory::getRoundAllRoleTable(int roundNumberRole, int &beginIt, int &endIt)
{
	if (roundRoleHistory.begin() != roundRoleHistory.end())
	{
		beginIt = roundRoleHistory[roundNumberRole].before;
		endIt = roundRoleHistory[roundNumberRole].total;

		cocos2d::log("[information]:成功获取某回合内角色所有的表！");
	}
}

//添加怪物表（包括总表）
bool DeltaTableHistory::addTableMonsterHistory(DeltaMonsterTable dt)
{
	if (dt.roundNumberMonster == roundNumberMonster)
	{
		tableMonsterHistory.push_back(dt);
		cocos2d::log("[information]: 角色表添加成功！");
	}
	else if (dt.roundNumberMonster == roundNumberMonster + 1)
	{
		DeltaMonsterTable total;

		total.ID = tableMonsterHistory.size() + 1;
		total.roundNumberMonster = roundNumberMonster;
		total.roundLevel = DeltaMonsterTable::RoundLevel_Total;

		tableMonsterHistory.push_back(total);

		if (tableMonsterHistory.begin() != tableMonsterHistory.end())
		{
			if (roundNumberMonster == 1)
			{
				for (int n = tableMonsterHistory.size() - 1; n >= 0; --n)
				{
					for (int i = 0; i < total.row; ++i)
					{
						for (int j = 0; j < total.col; ++j)
						{
							tableMonsterHistory[tableMonsterHistory.size() - 1].effectTable[i][j] += tableMonsterHistory[n].effectTable[i][j];
						}
					}
				}
			}
			else if (roundNumberMonster > 1)
			{
				for (int n = tableMonsterHistory.size() - 1; n > roundMonsterHistory[roundNumberMonster - 2].total; --n)
				{
					for (int i = 0; i < total.row; ++i)
					{
						for (int j = 0; j < total.col; ++j)
						{
							tableMonsterHistory[tableMonsterHistory.size() - 1].effectTable[i][j] += tableMonsterHistory[n].effectTable[i][j];
						}
					}
				}
			}
		}

		DeltaMonsterRound dr;
		roundMonsterHistory.push_back(dr);

		if (tableMonsterHistory.begin() != tableMonsterHistory.end())
		{
			if (roundNumberMonster == 1)
			{
				for (int i = tableMonsterHistory.size() - 1; i >= 0; --i)
				{
					switch (tableMonsterHistory[i].roundLevel)
					{
					case DeltaMonsterTable::RoundLevel_Before:
						roundMonsterHistory[roundNumberMonster - 1].before = i;
						break;
					case DeltaMonsterTable::RoundLevel_In:
						roundMonsterHistory[roundNumberMonster - 1].in = i;
						break;
					case DeltaMonsterTable::RoundLevel_After:
						roundMonsterHistory[roundNumberMonster - 1].after = i;
						break;
					case DeltaMonsterTable::RoundLevel_Total:
						roundMonsterHistory[roundNumberMonster - 1].total = i;
						break;
					default:
						break;
					}
				}
			}
			else if (roundNumberMonster > 1)
			{
				for (int i = tableMonsterHistory.size() - 1; i > roundMonsterHistory[roundNumberMonster - 2].total; --i)
				{
					switch (tableMonsterHistory[i].roundLevel)
					{
					case DeltaMonsterTable::RoundLevel_Before:
						roundMonsterHistory[roundNumberMonster - 1].before = i;
						break;
					case DeltaMonsterTable::RoundLevel_In:
						roundMonsterHistory[roundNumberMonster - 1].in = i;
						break;
					case DeltaMonsterTable::RoundLevel_After:
						roundMonsterHistory[roundNumberMonster - 1].after = i;
						break;
					case DeltaMonsterTable::RoundLevel_Total:
						roundMonsterHistory[roundNumberMonster - 1].total = i;
						break;
					default:
						break;
					}
				}
			}
		}
		cocos2d::log("[information]: 总表添加成功！");
	}

	if (dt.roundNumberMonster == roundNumberMonster + 1)
	{
		++roundNumberMonster;

		DeltaMonsterTable dt05;
		dt05.ID = 4;
		dt05.roundLevel = DeltaMonsterTable::RoundLevel_Before;
		dt05.roundNumberMonster = 3;
		dt05.effectTable[0][0] = 1;

		addTableMonsterHistory(dt05);
	}

	return true;
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
	dt2.roundLevel = DeltaRoleTable::RoundLevel_In;
	dt2.roundNumberRole = 1;
	dt2.effectTable[0][0] = 1;
	dt2.effectTable[0][1] = 1;

	DeltaRoleTable dt3;
	dt3.ID = 5;
	dt3.roundLevel = DeltaRoleTable::RoundLevel_Before;
	dt3.roundNumberRole = 2;
	dt3.effectTable[1][1] = 5;

	DeltaRoleTable dt4;
	dt4.ID = 6;
	dt4.roundLevel = DeltaRoleTable::RoundLevel_In;
	dt4.roundNumberRole = 2;
	dt4.effectTable[1][1] = 5;

	DeltaRoleTable dt6;
	dt6.ID = 8;
	dt6.roundLevel = DeltaRoleTable::RoundLevel_Before;
	dt6.roundNumberRole = 2;
	dt6.effectTable[1][1] = 5;

	DeltaRoleTable dt5;
	dt5.ID = 7;
	dt5.roundLevel = DeltaRoleTable::RoundLevel_Before;
	dt5.roundNumberRole = 3;
	dt5.effectTable[1][1] = 5;


	//DeltaMonsterTable dt01;
	//dt01.ID = 1;
	//dt01.roundLevel = DeltaMonsterTable::RoundLevel_Before;
	//dt01.roundNumberMonster = 1;
	//dt01.effectTable[0][0] = 2;

	//DeltaMonsterTable dt02;
	//dt02.ID = 2;
	//dt02.roundLevel = DeltaMonsterTable::RoundLevel_Before;
	//dt02.roundNumberMonster = 1;
	//dt02.effectTable[0][0] = 1;

	//DeltaMonsterTable dt03;
	//dt03.ID = 3;
	//dt03.roundLevel = DeltaMonsterTable::RoundLevel_Before;
	//dt03.roundNumberMonster = 2;
	//dt03.effectTable[0][0] = 1;

	//DeltaMonsterTable dt04;
	//dt03.ID = 4;
	//dt03.roundLevel = DeltaMonsterTable::RoundLevel_Before;
	//dt03.roundNumberMonster = 2;
	//dt03.effectTable[0][0] = 1;

	//DeltaMonsterTable dt05;
	//dt05.ID = 4;
	//dt05.roundLevel = DeltaMonsterTable::RoundLevel_Before;
	//dt05.roundNumberMonster = 3;
	//dt05.effectTable[0][0] = 1;

	//addTableMonsterHistory(dt01);

	//addTableMonsterHistory(dt02);

	//addTableMonsterHistory(dt03);

	//addTableMonsterHistory(dt04);

	//addTableMonsterHistory(dt05);

	//auto text01 = tableMonsterHistory[roundMonsterHistory[0].before];

	//auto text02 = tableMonsterHistory[roundMonsterHistory[0].total];

	//auto text03 = tableMonsterHistory[roundMonsterHistory[1].before];

	//auto text04 = tableMonsterHistory[roundMonsterHistory[1].total];

	////auto text04 = tableMonsterHistory[3];

	//auto text05 = text01;

	addTableRoleHistory(dt0);

	addTableRoleHistory(dt1);

	addTableRoleHistory(dt2);

	addTableRoleHistory(dt3);

	addTableRoleHistory(dt4);

	addTableRoleHistory(dt6);

	addTableRoleHistory(dt5);

	//getRoundAllRoleTable(0, roundRoleHistory[0].before, roundRoleHistory[0].total);

	auto text1 = tableRoleHistory[roundRoleHistory[0].before];

	//auto text2 = tableRoleHistory[roundRoleHistory[0].after];

	auto text3 = tableRoleHistory[roundRoleHistory[0].total];

	auto text4 = tableRoleHistory[roundRoleHistory[1].before];

	auto text5 = tableRoleHistory[roundRoleHistory[1].total];

	auto text7 = tableRoleHistory[3];

	auto text6 = tableRoleHistory[0];

	/*DeltaRoleRound dr1;

	DeltaRoleRound dr2;*/
	
	/*addRoundRoleHistory(dr1);
	
	addTableRoleHistory(dr1, dt0);
	
	addTableRoleHistory(dr1, dt1);

	addTableRoleHistory(dr1, dt2);*/

	/*auto text1 = tableRoleHistory[roundRoleHistory[deltaRoleRound.roundNumberRole - 1].before];
	auto text2 = tableRoleHistory[roundRoleHistory[deltaRoleRound.roundNumberRole - 1].after];
	auto text3 = tableRoleHistory[roundRoleHistory[deltaRoleRound.roundNumberRole - 1].total];

	auto text4 = tableRoleHistory[roundRoleHistory[deltaRoleRound.roundNumberRole - 1].total];
	auto text5 = text4;

	getRoundAllRoleTable(roundRoleHistory[detaRoleTable.roundNumberRole].before, roundRoleHistory[detaRoleTable.roundNumberRole].after);
*/
	cocos2d::log("退出Text    ******************************************************");

}