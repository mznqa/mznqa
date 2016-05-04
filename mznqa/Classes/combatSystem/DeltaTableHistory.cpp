#pragma execution_character_set("utf-8")

#include "combatSystem/DeltaTableHistory.h"
#include <vector>
#include "combatSystem/DeltaTable.h"
#include "EffectPQ.h"
#include "cocos2d.h"

DeltaTableHistory::DeltaTableHistory()
{
}

DeltaTableHistory::~DeltaTableHistory()
{
}

bool DeltaTableHistory::addTableRoleHistory(const DeltaTable& dt)
{

	tableRoleHistory.push_back(dt);
	
	return true;
}

void DeltaTableHistory::addTotalRoleHistory(int round)
{
	//添加角色效果总表
	DeltaTable total;
	roundNumberRole = round;
	total.roundNumber = roundNumberRole;
	total.roundLevel = DeltaTable::RoundLevel_Total;
	tableRoleHistory.push_back(total);

	for (int n = tableRoleHistory.size() - 1; n > 0; --n)
	{
		for (int i = 0; i < total.row; ++i)
		{
			for (int j = 0; j < total.col; ++j)
			{
				total.effectTable[i][j] += tableRoleHistory[n - 1].effectTable[i][j];
			}
		}
	}

	//添加角色回合结构体
	DeltaRound dr;
	dr.total = tableRoleHistory.size() - 1;
	dr.roundNumber = round;
	roundRoleHistory.push_back(dr);

	for (int i = dr.total; i >= 0; --i)
	{
		switch (tableRoleHistory[i].roundLevel)
		{
		case DeltaTable::RoundLevel_Before:
			dr.before = i;
			break;
		case DeltaTable::RoundLevel_In:
			dr.in = i;
			break;
		case DeltaTable::RoundLevel_After:
			dr.after = i;
			break;
		case DeltaTable::RoundLevel_Total:
			dr.total = i;
			break;
		default:
			break;
		}
	}


}

const std::vector<DeltaTable>& DeltaTableHistory::getRoundAllRoleTable(int round)
{
	tableTemp.clear();
	//若存在指定的回合数
	if ( round <= roundNumberRole && round > 0)
	{
		auto it = tableRoleHistory.begin();
		int beginIt = roundRoleHistory[round].before;
		int endIt = roundRoleHistory[round].total;
		tableTemp.resize(endIt - beginIt + 1);
		copy(it + beginIt, it + endIt, tableTemp.begin());
	}
	return tableTemp;
}

const std::vector<DeltaTable>& DeltaTableHistory::getRoundRoleTable(int round, DeltaTable::RoundLevel index)
{
	tableTemp.clear();
	if (round <= roundNumberRole)
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
			return tableTemp;
			break;
		}
		tableTemp.resize(endIt - beginIt + 1);
		copy(it + beginIt, it + endIt, tableTemp.begin());		
	}
	return tableTemp;
}

const std::vector<DeltaTable>& DeltaTableHistory::getCurrentRoundRoleTable(int round)
{
	tableTemp.clear();
	if (round < 1)
	{
		return tableTemp;
	}
	int index = 0;
	//若指定的回合数不是第1回合
	if (round > 1)
	{
		//获取当前回合历史效果的初始下标
		index = roundRoleHistory.at(round - 2).total + 1;
	}
	auto itBegin = tableRoleHistory.begin() + index;
	auto itEnd = tableRoleHistory.end();
	for (; itBegin != itEnd; ++itBegin)
	{
		if (itBegin->roundNumber == round)
		{
			tableTemp.push_back(*itBegin);
			
		}
	}
	return tableTemp;
}

bool DeltaTableHistory::addTableMonsterHistory(DeltaTable dt)
{

	tableMonsterHistory.push_back(dt);
	return true;
}



void DeltaTableHistory::addTotalMonsterHistory(int round)
{
	//添加怪物效果总表
	DeltaTable total;
	roundNumberMonster = round;
	total.roundNumber = roundNumberMonster;
	total.roundLevel = DeltaTable::RoundLevel_Total;
	tableMonsterHistory.push_back(total);
	
	for (int n = tableMonsterHistory.size() - 1; n > 0; --n)
	{
		for (int i = 0; i < total.row; ++i)
		{
			for (int j = 0; j < total.col; ++j)
			{
				total.effectTable[i][j] += tableMonsterHistory[n - 1].effectTable[i][j];
			}
		}
	}

	//添加怪物回合结构体
	DeltaRound dr;
	dr.total = tableMonsterHistory.size() - 1;
	dr.roundNumber = round;
	roundMonsterHistory.push_back(dr);

	for (int i = dr.total; i >= 0; --i)
	{
		switch (tableRoleHistory[i].roundLevel)
		{
		case DeltaTable::RoundLevel_Before:
			dr.before = i;
			break;
		case DeltaTable::RoundLevel_In:
			dr.in = i;
			break;
		case DeltaTable::RoundLevel_After:
			dr.after = i;
			break;
		case DeltaTable::RoundLevel_Total:
			dr.total = i;
			break;
		default:
			break;
		}
	}
}

const std::vector<DeltaTable>& DeltaTableHistory::getRoundAllMonsterTable(int round)
{
	tableTemp.clear();
	//若存在指定的回合数
	if (round <= roundNumberMonster && round > 0)
	{
		std::vector<DeltaTable>::iterator it = tableMonsterHistory.begin();
		int beginIt = roundMonsterHistory[round].before;
		int endIt = roundMonsterHistory[round].total;
		tableTemp.resize(endIt - beginIt + 1);
		copy(it + beginIt, it + endIt, tableTemp.begin());
	}
	return tableTemp;
}

const std::vector<DeltaTable>& DeltaTableHistory::getRoundMonsterTable(int round, DeltaTable::RoundLevel index)
{
	tableTemp.clear();
	if (round <= roundNumberMonster && round > 0)
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
			return tableTemp;
			break;
		}
		tableTemp.resize(endIt - beginIt + 1);
		copy(it + beginIt, it + endIt, tableTemp.begin());
	}
	return tableTemp;
}

const std::vector<DeltaTable>& DeltaTableHistory::getCurrentRoundMonsterTable(int round)
{
	tableTemp.clear();
	if (round < 1)
	{
		return tableTemp;
	}
	int index = 0;
	//若指定的回合数不是第1回合
	if (round > 1)
	{
		//获取当前回合历史效果的初始下标
		index = roundMonsterHistory.at(round - 2).total + 1;
	}
	auto itBegin = tableMonsterHistory.begin() + index;
	auto itEnd = tableMonsterHistory.end();
	for (; itBegin != itEnd; ++itBegin)
	{
		if (itBegin->roundNumber == round)
		{
			tableTemp.push_back(*itBegin);
		}
	}
	return tableTemp;
}


void DeltaTableHistory::test()
{
	cocos2d::log("进入Text    *******************************************************");
	

	cocos2d::log("退出Text    ******************************************************");

}