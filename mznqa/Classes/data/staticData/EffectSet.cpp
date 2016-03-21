#pragma execution_character_set("utf-8")

#include "cocos2d.h"

#include "data/staticData/EffectSet.h"

std::map<int, std::function<bool(int*, int)>> EffectSet::effectMap = std::map<int, std::function<bool(int*, int)>>{
	{ 0, EffectSet::effectBase0 },
	{ 1, EffectSet::effectBase1 },
	{ 2, EffectSet::effectBase2 },
	{ 3, EffectSet::effectBase3 },
	{ 4, EffectSet::effectBase4 },

	{ 100, EffectSet::effectSpecial0 },
	{ 101, EffectSet::effectSpecial1 },
	{ 102, EffectSet::effectSpecial2 },

	{ 200, EffectSet::effectCondition0 },
	{ 201, EffectSet::effectCondition1 },
	{ 202, EffectSet::effectCondition2 },
	{ 203, EffectSet::effectCondition3 },
	{ 204, EffectSet::effectCondition4 },
	{ 205, EffectSet::effectCondition5 },
	{ 206, EffectSet::effectCondition6 },
	{ 207, EffectSet::effectCondition7 },
	{ 208, EffectSet::effectCondition8 },
	{ 209, EffectSet::effectCondition9 },
	{ 210, EffectSet::effectCondition10 },
	{ 211, EffectSet::effectCondition11 },
	{ 212, EffectSet::effectCondition12 },
	{ 213, EffectSet::effectCondition13 }
};

EffectSet::~EffectSet()
{
}

EffectSet::EffectSet()
{
}

std::function<bool(int*, int)> EffectSet::getFunByEffectID(int id)
{
	return effectMap.at(id);
}

bool EffectSet::effectBase0(int *arr, int size)
{
	cocos2d::log("使用了基础技能0：");
	for (int i = 0; i < size; ++i)
		cocos2d::log("\targ-%d : %d", i, arr[i]);

	delete[] arr;
	arr = nullptr;
	return true;
}

bool EffectSet::effectBase1(int *arr, int size)
{
	cocos2d::log("使用了基础技能1：");
	for (int i = 0; i < size; ++i)
		cocos2d::log("\targ-%d : %d", i, arr[i]);
	delete[] arr;
	arr = nullptr;
	return true;
}

bool EffectSet::effectBase2(int *arr, int size)
{
	return true;
}

bool EffectSet::effectBase3(int *arr, int size)
{
	return true;
}

bool EffectSet::effectBase4(int *arr, int size)
{
	return true;
}

bool EffectSet::effectSpecial0(int *arr, int size)
{
	return true;
}

bool EffectSet::effectSpecial1(int *arr, int size)
{
	return true;
}

bool EffectSet::effectSpecial2(int *arr, int size)
{
	return true;
}

bool EffectSet::effectCondition0(int *arr, int size)
{
	return true;
}

bool EffectSet::effectCondition1(int *arr, int size)
{
	return true;
}

bool EffectSet::effectCondition2(int *arr, int size)
{
	return true;
}

bool EffectSet::effectCondition3(int *arr, int size)
{
	return true;
}

bool EffectSet::effectCondition4(int *arr, int size)
{
	return true;
}

bool EffectSet::effectCondition5(int *arr, int size)
{
	return true;
}

bool EffectSet::effectCondition6(int *arr, int size)
{
	return true;
}

bool EffectSet::effectCondition7(int *arr, int size)
{
	return true;
}

bool EffectSet::effectCondition8(int *arr, int size)
{
	return true;
}

bool EffectSet::effectCondition9(int *arr, int size)
{
	return true;
}

bool EffectSet::effectCondition10(int *arr, int size)
{
	return true;
}

bool EffectSet::effectCondition11(int *arr, int size)
{
	return true;
}

bool EffectSet::effectCondition12(int *arr, int size)
{
	return true;
}

bool EffectSet::effectCondition13(int *arr, int size)
{
	return true;
}