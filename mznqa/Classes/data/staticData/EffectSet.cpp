#pragma execution_character_set("utf-8")

#include "data/staticData/EffectSet.h"

EffectSet::EffectSet()
{
	effectMap.insert({ 1, EffectSet::effectBase1 });
	effectMap.insert({ 2, EffectSet::effectBase2 });
	effectMap.insert({ 3, EffectSet::effectBase3 });
	effectMap.insert({ 4, EffectSet::effectBase4 });
	effectMap.insert({ 5, EffectSet::effectBase5 });

	effectMap.insert({ 101, EffectSet::effectSpecial1 });
	effectMap.insert({ 102, EffectSet::effectSpecial2 });
	effectMap.insert({ 103, EffectSet::effectSpecial3 });

	effectMap.insert({ 201, EffectSet::effectCondition1 });
	effectMap.insert({ 202, EffectSet::effectCondition2 });
	effectMap.insert({ 203, EffectSet::effectCondition3 });
	effectMap.insert({ 204, EffectSet::effectCondition4 });
	effectMap.insert({ 205, EffectSet::effectCondition5 });
	effectMap.insert({ 206, EffectSet::effectCondition6 });
	effectMap.insert({ 207, EffectSet::effectCondition7 });
	effectMap.insert({ 208, EffectSet::effectCondition8 });
	effectMap.insert({ 209, EffectSet::effectCondition9 });
	effectMap.insert({ 210, EffectSet::effectCondition10 });
	effectMap.insert({ 211, EffectSet::effectCondition11 });
	effectMap.insert({ 212, EffectSet::effectCondition12 });
	effectMap.insert({ 213, EffectSet::effectCondition13 });
	effectMap.insert({ 214, EffectSet::effectCondition14 });
}

bool EffectSet::effectBase1(int *arr, int size)
{
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

bool EffectSet::effectBase5(int *arr, int size)
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

bool EffectSet::effectSpecial3(int *arr, int size)
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

bool EffectSet::effectCondition14(int *arr, int size)
{
	return true;
}