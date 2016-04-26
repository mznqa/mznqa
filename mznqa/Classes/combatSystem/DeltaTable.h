#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_
#define MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_

//#include <memory.h>
//#include <vector>

//struct DeltaTable
//{
//	enum GameObject { GameObject_Role, GameObject_Monster };
//
//	//���ܽ�����
//	GameObject recver;
//
//	//�����ͷ���
//	GameObject releaser;
//
//	//����Ӱ��Ļ���Ч��
//	int effectTable[5][2];
//
//	DeltaTable()
//	{
//		memset(effectTable, 0, sizeof(effectTable));
//	}
//};
//

//��������ɫ��Ľṹ��
struct DeltaRoleTable
{
	//���Ʊ��
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

	//��¼�غ���
	int roundNumberRole = invalid;

	//��¼�������
	//int tableNumberRole = 1;

	//����Ӱ��Ļ���Ч��
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

//��������ɫ�غϵĽṹ��
struct DeltaRoleRound
{
	static const int invalIndex = -1;

	int before = invalIndex;

	int in = invalIndex;

	int after = invalIndex;

	int total = invalIndex;

	int roundNumberRole = 1;
};

//�����������Ľṹ��
struct DeltaMonsterTable
{
	//���Ʊ��
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

	//��¼�غ���
	int roundNumberRole = 1;

	//����Ӱ��Ļ���Ч��
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

//����������غϵĽṹ��
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