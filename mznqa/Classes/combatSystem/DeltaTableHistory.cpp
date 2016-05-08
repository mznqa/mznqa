#pragma execution_character_set("utf-8")

#include "combatSystem/DeltaTableHistory.h"
#include <vector>
#include "cocos2d.h"

DeltaTableHistory::DeltaTableHistory()
{
}

DeltaTableHistory::~DeltaTableHistory()
{
}

bool DeltaTableHistory::addTableHistoryRole(const DeltaTable& deltaTable)
{
	if (deltaTable.ID == DeltaTable::invalid || deltaTable.roundLevel == DeltaTable::RoundLevel_invalid || deltaTable.roundNumber == EffectAffixes::invalidEffectRoundValue)
	{
		return false;
	}
	tableHistoryRole.push_back(deltaTable);
	return true;
}

void DeltaTableHistory::addTotalTableHistoryRole(int round)
{
	//添加角色效果总表
	DeltaTable totalTable;
	roundNumberRole = round;
	totalTable.roundNumber = roundNumberRole;
	totalTable.roundLevel = DeltaTable::RoundLevel_Total;
	auto itBegin = this->getTableRoleInCurrentRound().begin();
	auto itEnd = this->getTableRoleInCurrentRound().end();
	int rowIndex, colIndex;
	for (; itBegin != itEnd; ++itBegin)
	{
		if (itBegin->flag == DeltaTable::Flag_Invalid)
		{
			for (int i = 0; i < totalTable.row; ++i)
			{
				for (int j = 0; j < totalTable.col; ++j)
				{
					totalTable.effectTable[i][j] += itBegin->effectTable[i][j];
				}
			}
		}
		else
		{
			getIndexByFlag(rowIndex, colIndex, itBegin->flag);
			totalTable.effectTable[rowIndex][colIndex] += itBegin->effectTable[rowIndex][colIndex];
		}
		
	}
	tableHistoryRole.push_back(totalTable);

	//添加角色回合结构体
	DeltaRound deltaRound;
	deltaRound.total = tableHistoryRole.size() - 1;
	deltaRound.roundNumber = round;
	int curFirstIndex = 0;
	if (round > 1)
	{
		curFirstIndex = roundHistoryRole.back().total + 1;
	}
	for (int i = deltaRound.total; i >= curFirstIndex; --i)
	{
		switch (tableHistoryRole[i].roundLevel)
		{
		case DeltaTable::RoundLevel_Before:
			deltaRound.before = i;
			break;
		case DeltaTable::RoundLevel_In:
			deltaRound.in = i;
			break;
		case DeltaTable::RoundLevel_After:
			deltaRound.after = i;
			break;
		case DeltaTable::RoundLevel_Total:
			deltaRound.total = i;
			break;
		default:
			break;
		}
	}
	roundHistoryRole.push_back(deltaRound);
}

const std::vector<DeltaTable>& DeltaTableHistory::getAllTableRoleByRound(int round)
{
	tableTemp.clear();
	//若存在指定的回合数
	if ( round <= roundNumberRole && round > 0)
	{
		auto it = tableHistoryRole.begin();
		int beginIt = roundHistoryRole[round].before;
		int endIt = roundHistoryRole[round].total;
		tableTemp.resize(endIt - beginIt + 1);
		copy(it + beginIt, it + endIt + 1, tableTemp.begin());
	}
	return tableTemp;
}

const std::vector<DeltaTable>& DeltaTableHistory::getTableRoleByRoundAndIndex(int round, DeltaTable::RoundLevel index)
{
	tableTemp.clear();
	if (round <= roundNumberRole)
	{
		std::vector<DeltaTable>::iterator it = tableHistoryRole.begin();
		int beginIt;
		int endIt;
		switch (index)
		{
		case DeltaTable::RoundLevel_Before:
			beginIt = roundHistoryRole[round - 1].before;
			endIt = roundHistoryRole[round - 1].in;
			break;
		case DeltaTable::RoundLevel_In:
			beginIt = roundHistoryRole[round - 1].in;
			endIt = roundHistoryRole[round - 1].after;
			break;
		case DeltaTable::RoundLevel_After:
			beginIt = roundHistoryRole[round - 1].after;
			endIt = roundHistoryRole[round - 1].total;
			break;
		case DeltaTable::RoundLevel_Total:
			beginIt = roundHistoryRole[round - 1].total;
			endIt = roundHistoryRole[round - 1].total;
			break;
		default:
			return tableTemp;
			break;
		}
		tableTemp.resize(endIt - beginIt + 1);
		copy(it + beginIt, it + endIt + 1, tableTemp.begin());		
	}
	return tableTemp;
}

const std::vector<DeltaTable>& DeltaTableHistory::getTableRoleInCurrentRound()
{
	tableTemp.clear();
	if (roundNumberRole < 1)
	{
		return tableTemp;
	}
	int index = 0;
	//若指定的回合数不是第1回合
	if (roundNumberRole > 1)
	{
		//获取当前回合历史效果的初始下标
		index = roundHistoryRole.at(roundNumberRole - 2).total + 1;
	}
	auto itBegin = tableHistoryRole.begin() + index;
	auto itEnd = tableHistoryRole.end();
	for (; itBegin != itEnd; ++itBegin)
	{
		if (itBegin->roundNumber == roundNumberRole)
		{
			tableTemp.push_back(*itBegin);
			
		}
	}
	return tableTemp;
}

bool DeltaTableHistory::addTableHistoryMonster(const DeltaTable& deltaTable)
{
	if (deltaTable.ID == DeltaTable::invalid || deltaTable.roundLevel == DeltaTable::RoundLevel_invalid || deltaTable.roundNumber == EffectAffixes::invalidEffectRoundValue)
	{
		return false;
	}
	tableHistoryMonster.push_back(deltaTable);
	return true;
}

void DeltaTableHistory::addTotalTableHistoryMonster(int round)
{
	//添加怪物效果总表
	DeltaTable totalTable;
	roundNumberMonster = round;
	totalTable.roundNumber = roundNumberMonster;
	totalTable.roundLevel = DeltaTable::RoundLevel_Total;

	auto itBegin = this->getTableMonsterInCurrentRound().begin();
	auto itEnd = this->getTableMonsterInCurrentRound().end();
	int rowIndex, colIndex;

	for (; itBegin != itEnd;++itBegin)
	{
		if (itBegin->flag == DeltaTable::Flag_Invalid)
		{
			for (int i = 0; i < totalTable.row; ++i)
			{
				for (int j = 0; j < totalTable.col; ++j)
				{
					totalTable.effectTable[i][j] += itBegin->effectTable[i][j];
				}
			}
		}
		else
		{
			getIndexByFlag(rowIndex, colIndex, itBegin->flag);
			totalTable.effectTable[rowIndex][colIndex] += itBegin->effectTable[rowIndex][colIndex];
		}
		
	}

	tableHistoryMonster.push_back(totalTable);

	//添加怪物回合结构体
	DeltaRound deltaRound;
	deltaRound.total = tableHistoryMonster.size() - 1;
	deltaRound.roundNumber = round;
	int curFirstIndex = 0;
	if (round > 1)
	{
		curFirstIndex = roundHistoryMonster.back().total + 1;
	}
	for (int i = deltaRound.total; i >= curFirstIndex; --i)
	{
		switch (tableHistoryMonster[i].roundLevel)
		{
		case DeltaTable::RoundLevel_Before:
			deltaRound.before = i;
			break;
		case DeltaTable::RoundLevel_In:
			deltaRound.in = i;
			break;
		case DeltaTable::RoundLevel_After:
			deltaRound.after = i;
			break;
		case DeltaTable::RoundLevel_Total:
			deltaRound.total = i;
			break;
		default:
			break;
		}
	}
	roundHistoryMonster.push_back(deltaRound);
}

const std::vector<DeltaTable>& DeltaTableHistory::getAllTableMonsterByRound(int round)
{
	tableTemp.clear();
	//若存在指定的回合数
	if (round <= roundNumberMonster && round > 0)
	{
		std::vector<DeltaTable>::iterator it = tableHistoryMonster.begin();
		int beginIt = roundHistoryMonster[round].before;
		int endIt = roundHistoryMonster[round].total;
		tableTemp.resize(endIt - beginIt + 1);
		copy(it + beginIt, it + endIt + 1, tableTemp.begin());
	}
	return tableTemp;
}

const std::vector<DeltaTable>& DeltaTableHistory::getTableMonsterByRoundAndIndex(int round, DeltaTable::RoundLevel index)
{
	tableTemp.clear();
	if (round <= roundNumberMonster && round > 0)
	{
		std::vector<DeltaTable>::iterator it = tableHistoryMonster.begin();
		int beginIt;
		int endIt;
		switch (index)
		{
		case DeltaTable::RoundLevel_Before:
			beginIt = roundHistoryMonster[round - 1].before;
			endIt = roundHistoryRole[round - 1].in;
			break;
		case DeltaTable::RoundLevel_In:
			beginIt = roundHistoryMonster[round - 1].in;
			endIt = roundHistoryMonster[round - 1].after;
			break;
		case DeltaTable::RoundLevel_After:
			beginIt = roundHistoryMonster[round - 1].after;
			endIt = roundHistoryMonster[round - 1].total;
			break;
		case DeltaTable::RoundLevel_Total:
			beginIt = roundHistoryMonster[round - 1].total;
			endIt = roundHistoryMonster[round - 1].total;
			break;
		default:
			return tableTemp;
			break;
		}

		tableTemp.resize(endIt - beginIt + 1);
		copy(it + beginIt, it + endIt + 1, tableTemp.begin());
	}
	return tableTemp;
}

const std::vector<DeltaTable>& DeltaTableHistory::getTableMonsterInCurrentRound()
{
	tableTemp.clear();
	if (roundNumberMonster < 1)
	{
		return tableTemp;
	}
	int index = 0;
	//若指定的回合数不是第1回合
	if (roundNumberMonster > 1)
	{
		//获取当前回合历史效果的初始下标
		index = roundHistoryMonster.at(roundNumberMonster - 2).total + 1;
	}
	auto itBegin = tableHistoryMonster.begin() + index;
	auto itEnd = tableHistoryMonster.end();
	for (; itBegin != itEnd; ++itBegin)
	{
		if (itBegin->roundNumber == roundNumberMonster)
		{
			tableTemp.push_back(*itBegin);
		}
	}
	return tableTemp;
}


void DeltaTableHistory::getIndexByFlag(int& rowIndex, int& colIndex, DeltaTable::Flag flag)
{
	switch (flag)
	{
	case DeltaTable::Flag_Blood_Role:
		rowIndex = 0;
		colIndex = 0;
		break;
	case DeltaTable::Flag_Blood_Monster:
		rowIndex = 0;
		colIndex = 1;
		break;
	case DeltaTable::Flag_Armor_Role:
		rowIndex = 1;
		colIndex = 0;
		break;
	case DeltaTable::Flag_Armor_Monster:
		rowIndex = 1;
		colIndex = 1;
		break;
	case DeltaTable::Flag_Hand_Role:
		rowIndex = 2;
		colIndex = 0;
		break;
	case DeltaTable::Flag_Draw_Role:
		rowIndex = 3;
		colIndex = 0;
		break;
	case DeltaTable::Flag_Discard_Role:
		rowIndex = 4;
		colIndex = 0;
		break;
	default:
		break;
	}
}

void DeltaTableHistory::test()
{
	cocos2d::log("进入Text    *******************************************************");
	

	cocos2d::log("退出Text    ******************************************************");

}