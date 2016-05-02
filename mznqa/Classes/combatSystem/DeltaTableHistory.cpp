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


//添加角色表
bool DeltaTableHistory::addTableRoleHistory(const DeltaTable& dt)
{
	auto itIndex = tableRoleHistory.begin() + roundRoleHistory[dt.roundNumber - 1].total;

	if (dt.roundNumber == roundNumberRole)
	{
		//tableRoleHistory.push_back(dt);
		tableRoleHistory.insert(itIndex, dt);

		int totalIndex = tableRoleHistory.size() - 1;

		if (roundNumberRole == 1)
		{
			for (int n = tableRoleHistory.size() - 1; n > 0; --n)
			{
				for (int i = 0; i < dt.row; ++i)
				{
					for (int j = 0; j < dt.col; ++j)
					{
						tableRoleHistory[totalIndex].effectTable[i][j] += tableRoleHistory[n - 1].effectTable[i][j];
					}
				}
			}


			for (int i = tableRoleHistory.size() - 1; i >= 0; --i)
			{
				switch (tableRoleHistory[i].roundLevel)
				{
				case DeltaTable::RoundLevel_Before:
					roundRoleHistory[roundNumberRole - 1].before = i;
					break;
				case DeltaTable::RoundLevel_In:
					roundRoleHistory[roundNumberRole - 1].in = i;
					break;
				case DeltaTable::RoundLevel_After:
					roundRoleHistory[roundNumberRole - 1].after = i;
					break;
				case DeltaTable::RoundLevel_Total:
					roundRoleHistory[roundNumberRole - 1].total = i;
					break;
				default:
					break;
				}
			}

		}
		else
		{
			for (int n = tableRoleHistory.size() - 1; n > roundRoleHistory[roundNumberRole - 2].total; --n)
			{
				for (int i = 0; i < dt.row; ++i)
				{
					for (int j = 0; j < dt.col; ++j)
					{
						tableRoleHistory[totalIndex].effectTable[i][j] += tableRoleHistory[n - 1].effectTable[i][j];
					}
				}
			}


			for (int i = tableRoleHistory.size() - 1; i > roundRoleHistory[roundNumberRole - 2].total; --i)
			{
				switch (tableRoleHistory[i].roundLevel)
				{
				case DeltaTable::RoundLevel_Before:
					roundRoleHistory[roundNumberRole - 1].before = i;
					break;
				case DeltaTable::RoundLevel_In:
					roundRoleHistory[roundNumberRole - 1].in = i;
					break;
				case DeltaTable::RoundLevel_After:
					roundRoleHistory[roundNumberRole - 1].after = i;
					break;
				case DeltaTable::RoundLevel_Total:
					roundRoleHistory[roundNumberRole - 1].total = i;
					break;
				default:
					break;
				}
			}

		}		
		return true;
	}
	else
	{
		while (roundNumberRole <= dt.roundNumber)
		{
			++roundNumberRole;
		}

		addTableRoleHistory(dt);
	}



	cocos2d::log("[information]: 角色表添加成功！");
	return true;


}


bool DeltaTableHistory::addTotalRoleHistory(int round)
{
	DeltaTable total;

	roundNumberRole = round;
	total.roundNumber = roundNumberRole;
	total.roundLevel = DeltaTable::RoundLevel_Total;
	tableRoleHistory.push_back(total);


	DeltaRound dr;
	dr.total = tableRoleHistory.size() - 1;
	roundRoleHistory.push_back(dr);
	
	cocos2d::log("[information]: 总表添加成功！");
	return true;
}

const std::vector<DeltaTable>& DeltaTableHistory::getRoundAllRoleTable(int round)
{
	roundTemp.clear();
	//存在指定回合的表
	if (!roundRoleHistory.empty() && round <= roundNumberRole)
	{
		std::vector<DeltaTable>::iterator it = tableRoleHistory.begin();
		int beginIt = roundRoleHistory[round].before;
		int endIt = roundRoleHistory[round].total;
		roundTemp.resize(endIt - beginIt + 1);
		copy(it + beginIt, it + endIt, roundTemp.begin());
		
		cocos2d::log("[information]:成功获取某回合内角色所有的表！");
	}
	return roundTemp;
}

const std::vector<DeltaTable>& DeltaTableHistory::getRoundRoleTable(int round, DeltaTable::RoundLevel index)
{
	roundTemp.clear();
	if (!roundRoleHistory.empty() && round <= roundNumberRole)
	{
		std::vector<DeltaTable>::iterator it = tableRoleHistory.begin();
		int beginIt;
		int endIt;
		switch (index)
		{
		case DeltaTable::RoundLevel_Before:
			beginIt = roundRoleHistory[round].before;
			endIt = roundRoleHistory[round].in;
			break;
		case DeltaTable::RoundLevel_In:
			beginIt = roundRoleHistory[round].in;
			endIt = roundRoleHistory[round].after;
			break;
		case DeltaTable::RoundLevel_After:
			beginIt = roundRoleHistory[round].after;
			endIt = roundRoleHistory[round].total;
			break;
		case DeltaTable::RoundLevel_Total:
			beginIt = roundRoleHistory[round].total;
			endIt = roundRoleHistory[round].total;
			break;
		default:
			return roundTemp;
			break;
		}
		roundTemp.resize(endIt - beginIt + 1);
		copy(it + beginIt, it + endIt, roundTemp.begin());		
	}
	return roundTemp;
}

const std::vector<DeltaTable>& DeltaTableHistory::getCurrentRoundRoleTable(int round)
{
	
	roundTemp.clear();
	if (round < 1)
	{
		return roundTemp;
	}
	int index = 0;
	if (round > 1)
	{
		index = roundRoleHistory.at(round - 2).total;
	}
	auto itBegin = tableRoleHistory.begin() + index + 1;
	auto itEnd = tableRoleHistory.end();
	for (; itBegin != itEnd; ++itBegin)
	{
		if (itBegin->roundNumber == round)
		{
			roundTemp.push_back(*itBegin);
			
		}
	}
	return roundTemp;
}

//添加怪物表（包括总表）
bool DeltaTableHistory::addTableMonsterHistory(DeltaTable dt)
{

	auto itIndex = tableMonsterHistory.begin() + roundMonsterHistory.at(dt.roundNumber - 1).total;

	if (dt.roundNumber == roundNumberMonster)
	{
		tableMonsterHistory.insert(itIndex, dt);

		int totalIndex = tableMonsterHistory.size() - 1;

		if (roundNumberMonster == 1)
		{
			for (int n = tableMonsterHistory.size() - 1; n > 0; --n)
			{
				for (int i = 0; i < dt.row; ++i)
				{
					for (int j = 0; j < dt.col; ++j)
					{
						tableMonsterHistory[totalIndex].effectTable[i][j] += tableMonsterHistory[n - 1].effectTable[i][j];
					}
				}
			}


			for (int i = tableMonsterHistory.size() - 1; i >= 0; --i)
			{
				switch (tableMonsterHistory[i].roundLevel)
				{
				case DeltaTable::RoundLevel_Before:
					roundMonsterHistory[roundNumberMonster - 1].before = i;
					break;
				case DeltaTable::RoundLevel_In:
					roundMonsterHistory[roundNumberMonster - 1].in = i;
					break;
				case DeltaTable::RoundLevel_After:
					roundMonsterHistory[roundNumberMonster - 1].after = i;
					break;
				case DeltaTable::RoundLevel_Total:
					roundMonsterHistory[roundNumberMonster - 1].total = i;
					break;
				default:
					break;
				}
			}

		}
		else
		{
			for (int n = tableMonsterHistory.size() - 1; n > roundMonsterHistory[roundNumberMonster - 2].total; --n)
			{
				for (int i = 0; i < dt.row; ++i)
				{
					for (int j = 0; j < dt.col; ++j)
					{
						tableMonsterHistory[totalIndex].effectTable[i][j] += tableMonsterHistory[n - 1].effectTable[i][j];
					}
				}
			}


			for (int i = tableMonsterHistory.size() - 1; i > roundMonsterHistory[roundNumberMonster - 2].total; --i)
			{
				switch (tableMonsterHistory[i].roundLevel)
				{
				case DeltaTable::RoundLevel_Before:
					roundMonsterHistory[roundNumberMonster - 1].before = i;
					break;
				case DeltaTable::RoundLevel_In:
					roundMonsterHistory[roundNumberMonster - 1].in = i;
					break;
				case DeltaTable::RoundLevel_After:
					roundMonsterHistory[roundNumberMonster - 1].after = i;
					break;
				case DeltaTable::RoundLevel_Total:
					roundMonsterHistory[roundNumberMonster - 1].total = i;
					break;
				default:
					break;
				}
			}

		}

	}
	else
	{
		while (roundNumberMonster <= dt.roundNumber)
		{
			++roundNumberMonster;
		}

		addTableMonsterHistory(dt);

	}
	return true;

	
}



const std::vector<DeltaTable>& DeltaTableHistory::getRoundAllMonsterTable(int round)
{
	roundTemp.clear();
	//存在指定回合的表
	if (!roundMonsterHistory.empty() && round <= roundNumberMonster)
	{
		std::vector<DeltaTable>::iterator it = tableMonsterHistory.begin();
		int beginIt = roundMonsterHistory[round].before;
		int endIt = roundMonsterHistory[round].total;
		roundTemp.resize(endIt - beginIt + 1);
		copy(it + beginIt, it + endIt, roundTemp.begin());

		cocos2d::log("[information]:成功获取某回合内怪物所有的表！");
	}
	return roundTemp;
}

const std::vector<DeltaTable>& DeltaTableHistory::getRoundMonsterTable(int round, DeltaTable::RoundLevel index)
{
	roundTemp.clear();
	if (!roundMonsterHistory.empty() && round <= roundNumberMonster)
	{
		std::vector<DeltaTable>::iterator it = tableMonsterHistory.begin();
		int beginIt;
		int endIt;
		switch (index)
		{
		case DeltaTable::RoundLevel_Before:
			beginIt = roundMonsterHistory[round].before;
			endIt = roundRoleHistory[round].in;
			break;
		case DeltaTable::RoundLevel_In:
			beginIt = roundMonsterHistory[round].in;
			endIt = roundMonsterHistory[round].after;
			break;
		case DeltaTable::RoundLevel_After:
			beginIt = roundMonsterHistory[round].after;
			endIt = roundMonsterHistory[round].total;
			break;
		case DeltaTable::RoundLevel_Total:
			beginIt = roundMonsterHistory[round].total;
			endIt = roundMonsterHistory[round].total;
			break;
		default:
			return roundTemp;
			break;
		}
		roundTemp.resize(endIt - beginIt + 1);
		copy(it + beginIt, it + endIt, roundTemp.begin());
	}
	return roundTemp;
}

const std::vector<DeltaTable>& DeltaTableHistory::getCurrentRoundMonsterTable(int round)
{
	roundTemp.clear();
	if (round < 1)
	{
		return roundTemp;
	}
	int index = 0;
	if (round > 1)
	{
		index = roundMonsterHistory.at(round - 2).total;
	}
	auto itBegin = tableMonsterHistory.begin() + index;
	auto itEnd = tableMonsterHistory.end();
	for (; itBegin != itEnd; ++itBegin)
	{
		if (itBegin->roundNumber == round)
		{
			roundTemp.push_back(*itBegin);
		}
	}
	return roundTemp;
}

bool DeltaTableHistory::addTotalMonsterHistory(int round)
{
	DeltaTable total;

	roundNumberMonster = round;
	total.roundNumber = roundNumberMonster;
	total.roundLevel = DeltaTable::RoundLevel_Total;
	tableMonsterHistory.push_back(total);


	DeltaRound dr;
	dr.total = tableMonsterHistory.size() - 1;
	roundMonsterHistory.push_back(dr);

	cocos2d::log("[information]: 总表添加成功！");
	return true;
}


void DeltaTableHistory::text()
{
	cocos2d::log("进入Text    *******************************************************");
	

	cocos2d::log("退出Text    ******************************************************");

}