#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_
#define MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_

#include "card/CardBase.h"

//��������ɫ��Ľṹ��
struct DeltaTable
{
	//���Ʊ��
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

	//��¼�غ���
	int roundNumber = invalid;

	//����Ӱ��Ļ���Ч��
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

//��������ɫ�غϵĽṹ��
struct DeltaRound
{
	static const int invalIndex = -1;

	int before = invalIndex;

	int in = invalIndex;

	int after = invalIndex;

	int total = 0;

	int roundNumber = 1;
};

////�����������Ľṹ��
//struct DeltaMonsterTable
//{
//	//���Ʊ��
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
//	//��¼�غ���
//	int roundNumberMonster = invalid;
//
//	//����Ӱ��Ļ���Ч��
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
////����������غϵĽṹ��
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