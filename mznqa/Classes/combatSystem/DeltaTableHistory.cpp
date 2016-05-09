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
	int beginIndex, endIndex;
	getAllTableRoleByRound(roundNumberRole, beginIndex, endIndex);
	setTotalTableBaseValue(tableHistoryRole, totalTable,beginIndex,endIndex);
	tableHistoryRole.push_back(totalTable);

	//添加角色回合结构体
	DeltaRound deltaRound;
	deltaRound.total = tableHistoryRole.size() - 1;
	deltaRound.roundNumber = round;
	setRoundTableInfo(roundHistoryRole, tableHistoryRole, deltaRound);
	roundHistoryRole.push_back(deltaRound);
}

void DeltaTableHistory::syncRoundDeltaTableAndTableHistory(const int round)
{
	roundNumberRole = round;
	roundNumberMonster = round;
	DeltaTable::roundNumber = round;
	DeltaRound::roundNumber = round;
}

void DeltaTableHistory::setTotalTableBaseValue(std::vector<DeltaTable>& dtHistory, DeltaTable& totalTable,const int beginIndex,const int endIndex)
{
	auto itBegin = dtHistory.begin() + beginIndex;
	auto itEnd = dtHistory.begin() + endIndex;
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
	return;
}

void DeltaTableHistory::setRoundTableInfo(std::vector<DeltaRound>& roundHistory,std::vector<DeltaTable>& tableHistory, DeltaRound& deltaRound)
{
	int curFirstIndex = 0;
	if (deltaRound.roundNumber > 1)
	{
		curFirstIndex = roundHistory.back().total + 1;
	}
	for (int i = deltaRound.total; i >= curFirstIndex; --i)
	{
		switch (tableHistory[i].roundLevel)
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
}

int DeltaTableHistory::getSettleBaseValue(const int round, const int rowIndex, const int colIndex)
{
	if (!checkOutOfRange(rowIndex,colIndex) || round <= 0)
	{
		return DeltaTable::invalid;
	}	
	int beginIndex, endIndex;
	int baseValue = 0;
	//若指定回合属于当前回合
	if (round == roundNumberRole && round == roundNumberMonster)
	{
		getAllTableRoleByRound(roundNumberRole, beginIndex, endIndex);
		auto itRoleBegin = tableHistoryRole.begin() + beginIndex;
		auto itRoleEnd = tableHistoryRole.begin() + endIndex;
		for (; itRoleBegin != itRoleEnd; ++itRoleBegin)
		{
			baseValue += itRoleBegin->effectTable[rowIndex][colIndex];
		}
		getAllTableMonsterByRound(roundNumberMonster, beginIndex, endIndex);
		auto itMonsterBegin = tableHistoryMonster.begin() + beginIndex;
		auto itMonsterEnd = tableHistoryMonster.begin() + endIndex;
		for (; itMonsterBegin != itMonsterEnd; ++itMonsterBegin)
		{
			baseValue += itMonsterBegin->effectTable[rowIndex][colIndex];
		}
	}
	//若指定回合不是当前回合
	else
	{
		getTableMonsterByRoundAndIndex(round, DeltaTable::RoundLevel::RoundLevel_Total, beginIndex, endIndex);
		baseValue += (tableHistoryMonster.begin() + beginIndex)->effectTable[rowIndex][colIndex];
		getTableRoleByRoundAndIndex(round, DeltaTable::RoundLevel::RoundLevel_Total, beginIndex, endIndex);
		baseValue += (tableHistoryRole.begin() + beginIndex)->effectTable[rowIndex][colIndex];
	}
	return baseValue;
}

int DeltaTableHistory::getAttackValueMonster()
{
	int bloodTemp = 0;
	int deltaBlood = 0;
	int beginIndex, endIndex;
	getAllTableMonsterByRound(roundNumberMonster, beginIndex, endIndex);
	auto itMonsterBegin = tableHistoryMonster.begin() + beginIndex;
	auto itMonsterEnd = tableHistoryMonster.begin() + endIndex;
	for (; itMonsterBegin != itMonsterEnd; ++itMonsterBegin)
	{
		bloodTemp = itMonsterBegin->effectTable[0][0];
		if (bloodTemp < 0)
		{
			deltaBlood += bloodTemp;
		}
	}
	return -deltaBlood;
}

int DeltaTableHistory::getAttackValueRole()
{
	int bloodTemp = 0;
	int deltaBlood = 0;
	int beginIndex, endIndex;
	getAllTableRoleByRound(roundNumberRole, beginIndex, endIndex);
	auto itRoleBegin = tableHistoryRole.begin() + beginIndex;
	auto itRoleEnd = tableHistoryRole.begin() + endIndex;
	for (; itRoleBegin != itRoleEnd; ++itRoleBegin)
	{
		bloodTemp = itRoleBegin->effectTable[0][1];
		if (bloodTemp < 0)
		{
			deltaBlood += bloodTemp;
		}
	}
	return -deltaBlood;
}

int DeltaTableHistory::getBackBaseValue(const int rowIndex, const int colIndex)
{
	if (!checkOutOfRange(rowIndex, colIndex))
	{
		return DeltaTable::invalid;
	}
	int temp = 0;
	int delta = 0;
	int beginIndex, endIndex;
	getAllTableMonsterByRound(roundNumberMonster, beginIndex, endIndex);
	auto itMonsterBegin = tableHistoryMonster.begin() + beginIndex;
	auto itMonsterEnd = tableHistoryMonster.begin() + endIndex;
	for (; itMonsterBegin != itMonsterEnd; ++itMonsterBegin)
	{
		temp = itMonsterBegin->effectTable[rowIndex][colIndex];
		if (temp > 0)
		{
			delta += temp;
		}
	}
	getAllTableRoleByRound(roundNumberRole, beginIndex, endIndex);
	auto itRoleBegin = tableHistoryRole.begin() + beginIndex;
	auto itRoleEnd = tableHistoryRole.begin() + endIndex;
	for (; itRoleBegin != itRoleEnd; ++itRoleBegin)
	{
		temp = itRoleBegin->effectTable[rowIndex][colIndex];
		if (temp > 0)
		{
			delta += temp;
		}
	}
	
	return delta;
}

int DeltaTableHistory::getCountBaseValueInInterval(int round, const int baseValueMax, const int leftInterval, const int rightInterval, const int rowIndex, const int colIndex)
{
	int roundTemp = 1;
	int baseValueTemp = baseValueMax;
	int flag = 0;
	while (round > 1)
	{
		baseValueTemp += getSettleBaseValue(roundTemp, rowIndex, colIndex);
		if (baseValueTemp >= leftInterval && baseValueTemp <= rightInterval)
		{
			++flag;
			if (flag > 1)
			{
				break;
			}
		}
		if (baseValueTemp > baseValueMax)
		{
			baseValueTemp = baseValueMax;
		}
		++roundTemp;
		--round;
	}
	return flag;
}

bool DeltaTableHistory::checkOutOfRange(const int rowIndex, const int colIndex)
{
	if (rowIndex >= DeltaTable::row || rowIndex < 0)
	{
		return false;
	}
	if (colIndex >= DeltaTable::col || colIndex < 0)
	{
		return false;
	}
	return true;
}

void DeltaTableHistory::getAllTableRoleByRound(int round, int& beginIndex, int& endIndex)
{	
	//若存在指定的回合数
	if ( round > roundNumberRole || round < 0)
	{
		return;
	}	
	beginIndex = 0;
	endIndex = 0;
	//若指定的回合数是当前回合
	if (round == roundNumberRole)
	{
		if (roundNumberRole > 1)
		{
			beginIndex = roundHistoryRole.at(roundNumberRole - 2).total + 1;
		}
		endIndex = beginIndex;

		auto itBegin = tableHistoryRole.begin() + beginIndex;
		auto itEnd = tableHistoryRole.end();
		for (; itBegin != itEnd; ++itBegin)
		{
			++endIndex;
		}
	}
	else
	{
		beginIndex = roundHistoryRole[round - 1].before;
		endIndex = roundHistoryRole[round - 1].total;
	}
	return;
}

void DeltaTableHistory::getTableRoleByRoundAndIndex(int round, DeltaTable::RoundLevel index, int& beginIndex, int& endIndex)
{
	if (round <= roundNumberRole || round > 0)
	{
		switch (index)
		{
		case DeltaTable::RoundLevel_Before:
			beginIndex = roundHistoryRole[round - 1].before;
			endIndex = roundHistoryRole[round - 1].in;
			break;
		case DeltaTable::RoundLevel_In:
			beginIndex = roundHistoryRole[round - 1].in;
			endIndex = roundHistoryRole[round - 1].after;
			break;
		case DeltaTable::RoundLevel_After:
			beginIndex = roundHistoryRole[round - 1].after;
			endIndex = roundHistoryRole[round - 1].total;
			break;
		case DeltaTable::RoundLevel_Total:
			beginIndex = roundHistoryRole[round - 1].total;
			endIndex = roundHistoryRole[round - 1].total;
			break;
		default:			
			break;
		}			
	}
	return;
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
	int beginIndex, endIndex;
	getAllTableMonsterByRound(roundNumberMonster, beginIndex, endIndex);
	setTotalTableBaseValue(tableHistoryMonster, totalTable,beginIndex,endIndex);
	tableHistoryMonster.push_back(totalTable);

	//添加怪物回合结构体
	DeltaRound deltaRound;
	deltaRound.total = tableHistoryMonster.size() - 1;
	deltaRound.roundNumber = round;
	setRoundTableInfo(roundHistoryMonster, tableHistoryMonster, deltaRound);
	roundHistoryMonster.push_back(deltaRound);
}

void DeltaTableHistory::getAllTableMonsterByRound(int round,int& beginIndex,int& endIndex)
{
	//若存在指定的回合数
	if (round > roundNumberMonster || round < 0)
	{
		return;
	}
	beginIndex = 0;
	endIndex = 0;
	//若指定的回合数是当前回合
	if (round == roundNumberMonster)
	{
		if (roundNumberMonster > 1)
		{
			beginIndex = roundHistoryMonster.at(roundNumberMonster - 2).total + 1;
		}
		endIndex = beginIndex;
		auto itBegin = tableHistoryMonster.begin() + beginIndex;
		auto itEnd = tableHistoryMonster.end();
		for (; itBegin != itEnd; ++itBegin)
		{
			++endIndex;
		}
	}
	else
	{
		beginIndex = roundHistoryMonster.at(round - 1).before;
		endIndex = roundHistoryMonster.at(round - 1).total;
	}
	return;
}

void DeltaTableHistory::getTableMonsterByRoundAndIndex(int round, DeltaTable::RoundLevel index,int& beginIndex,int& endIndex)
{	
	if (round <= roundNumberMonster && round > 0)
	{
		std::vector<DeltaTable>::iterator it = tableHistoryMonster.begin();
		switch (index)
		{
		case DeltaTable::RoundLevel_Before:
			beginIndex = roundHistoryMonster[round - 1].before;
			endIndex = roundHistoryMonster[round - 1].in;
			break;
		case DeltaTable::RoundLevel_In:
			beginIndex = roundHistoryMonster[round - 1].in;
			endIndex = roundHistoryMonster[round - 1].after;
			break;
		case DeltaTable::RoundLevel_After:
			beginIndex = roundHistoryMonster[round - 1].after;
			endIndex = roundHistoryMonster[round - 1].total;
			break;
		case DeltaTable::RoundLevel_Total:
			beginIndex = roundHistoryMonster[round - 1].total;
			endIndex = roundHistoryMonster[round - 1].total;
			break;
		default:
			break;
		}	
	}
	return;
}

void DeltaTableHistory::getIndexByFlag(int& rowIndex, int& colIndex, DeltaTable::Flag flag)
{
	rowIndex = -1;
	colIndex = -1;
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