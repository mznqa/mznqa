#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_
#define MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_

//#include <memory.h>
//#include <vector>

//struct DeltaTable
//{
//	enum GameObject { GameObject_Role, GameObject_Monster };
//
//	//技能接收者
//	GameObject recver;
//
//	//技能释放者
//	GameObject releaser;
//
//	//技能影响的基础效果
//	int effectTable[5][2];
//
//	DeltaTable()
//	{
//		memset(effectTable, 0, sizeof(effectTable));
//	}
//};
//

//声明：角色表的结构体
struct DeltaRoleTable
{
	//卡牌编号
	int ID = 0;

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
	int roundNumberRole = invalid;

	//记录表的数量
	//int tableNumberRole = 1;

	//技能影响的基础效果
	static const int row = 5,  col = 2;
	int effectTable[row][col];

	DeltaRoleTable()
	{
		resetEffecTable();
	}

	~DeltaRoleTable()
	{

	}

	void resetEffecTable()
	{
		for (int y = 0; y < row; ++y)
			for (int x = 0; x < col; ++x)
				effectTable[y][x] = 0;
	}
};

//声明：角色回合的结构体
struct DeltaRoleRound
{
	static const int invalIndex = -1;

	int before = invalIndex;

	int in = invalIndex;

	int after = invalIndex;

	int total = invalIndex;

	int roundNumberRole = 1;
};

//声明：怪物表的结构体
struct DeltaMonsterTable
{
	//卡牌编号
	int ID;

	enum RoundLevel
	{
		RoundLevel_Global = 0,
		RoundLevel_Before = 1,
		RoundLevel_In = 2,
		RoundLevel_After = 3,
		RoundLevel_Total = 4
	};

	RoundLevel roundLevel = RoundLevel_Global;

	//记录回合数
	int roundNumberRole = 1;

	//技能影响的基础效果
	static const int row = 5, col = 2;
	int effectTable[row][col];

	DeltaMonsterTable()
	{
		for (int y = 0; y < row; ++y)
			for (int x = 0; x < col; ++x)
				effectTable[y][x] = 0;
	}

	~DeltaMonsterTable()
	{

	}
};

//声明：怪物回合的结构体
struct DeltaMonsterRound
{
	int beg;

	int before;

	int in;

	int after;

	int total;

	int end;

	int roundNumberRole = 1;
};

#endif