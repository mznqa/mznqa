#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_
#define MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_

#include "card/CardBase.h"

//声明：角色表的结构体
struct DeltaTable
{
	//卡牌编号
	int ID = CardBase::invalidID;

	static const int invalid = -1;

	enum RoundLevel
	{ 
		RoundLevel_invalid = invalid,
		RoundLevel_Global = 0, 
		RoundLevel_Before = 1, 
		RoundLevel_In = 2, 
		RoundLevel_After= 3,
		RoundLevel_Total = 4
	};

	RoundLevel roundLevel = RoundLevel_invalid;

	//记录回合数
	int roundNumber = invalid;

	//技能影响的基础效果
	static const int row = 5,  col = 2;
	int effectTable[row][col];

	DeltaTable()
	{
		memset(effectTable, 0, sizeof(int)*row*col);
	}

	~DeltaTable()
	{

	}
};

//声明：角色回合的结构体
struct DeltaRound
{
	static const int invalIndex = -1;

	int before = invalIndex;

	int in = invalIndex;

	int after = invalIndex;

	int total = 0;

	int roundNumber = 1;
};

////声明：怪物表的结构体
//struct DeltaMonsterTable
//{
//	//卡牌编号
//	int ID;
//
//	static const int invalid = -1;
//
//	enum RoundLevel
//	{
//		RoundLevel_invalid = invalid,
//		RoundLevel_Global = 0,
//		RoundLevel_Before = 1,
//		RoundLevel_In = 2,
//		RoundLevel_After = 3,
//		RoundLevel_Total = 4
//	};
//
//	RoundLevel roundLevel = RoundLevel_invalid;
//
//	//记录回合数
//	int roundNumberMonster = invalid;
//
//	//技能影响的基础效果
//	static const int row = 5, col = 2;
//	int effectTable[row][col];
//
//	DeltaMonsterTable()
//	{
//		resetMonsterEffecTable();
//	}
//
//	~DeltaMonsterTable()
//	{
//
//	}
//
//	void resetMonsterEffecTable()
//	{
//		for (int y = 0; y < row; ++y)
//			for (int x = 0; x < col; ++x)
//				effectTable[y][x] = 0;
//	}
//};
//
////声明：怪物回合的结构体
//struct DeltaMonsterRound
//{
//	static const int invalIndex = -1;
//
//	int before = invalIndex;
//
//	int in = invalIndex;
//
//	int after = invalIndex;
//
//	int total = invalIndex;
//
//	int roundNumberMonster = 1;
//};

#endif