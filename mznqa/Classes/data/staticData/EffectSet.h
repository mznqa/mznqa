#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_DATA_STATICDATA_EFFECTSET_H_
#define MZNQA_CLASSES_DATA_STATICDATA_EFFECTSET_H_

#include <map>
#include <functional>

class EffectSet
{
private:
	std::map<int, std::function<bool(int*, int)>> effectMap;
public:
	EffectSet();
	~EffectSet();

	static std::function<bool(int*, int)> getFunByEffectID(int id);

	// 基础效果区 //////////////////////////////////////////////////////////////////////////
	// 基础效果 - 影响血量
	// 参数：期望血量变化量
	static bool effectBase1(int *arr, int size);

	// 基础效果 - 影响护甲
	// 参数：期望护甲变化量
	static bool effectBase2(int *arr, int size);

	// 基础效果 - 影响手牌数
	// 参数：期望手牌变化量
	static bool effectBase3(int *arr, int size);

	// 基础效果 - 影响回合抽牌数
	// 参数：期望回合抽牌数变化量
	static bool effectBase4(int *arr, int size);

	// 基础效果 - 影响回合出牌数
	// 参数：期望回合出牌数变化量
	static bool effectBase5(int *arr, int size);
	//////////////////////////////////////////////////////////////////////////

	// 特殊效果区域 //////////////////////////////////////////////////////////////////////////
	// 特殊效果 - 攻击无效
	static bool effectSpecial1(int *arr, int size);

	// 特殊效果 - 回血无效
	static bool effectSpecial2(int *arr, int size);

	// 特殊效果 - 回甲无效
	static bool effectSpecial3(int *arr, int size);
	//////////////////////////////////////////////////////////////////////////

	// 条件效果区 //////////////////////////////////////////////////////////////////////////
	// 条件效果 - 当前的血量是否处于[A]~[B]
	// 参数：范围下限，范围上限
	static bool effectCondition1(int *arr, int size);

	// 条件效果 - 当前的血量是否小于等于[A] ==> 1~[A]
	// 参数：范围上限
	static bool effectCondition2(int *arr, int size);

	// 条件效果 - 当前的血量是否等于[A]
	// 参数：给定值
	static bool effectCondition3(int *arr, int size);

	// 条件效果 - 当前的血量是否大于等于[A] ==> [A]~(血量上限)
	// 参数：范围下限
	static bool effectCondition4(int *arr, int size);

	// 条件效果 - 当前的护甲是否处于[A]~[B]
	// 参数：范围下限，范围上限
	static bool effectCondition5(int *arr, int size);

	// 条件效果 - 当前的护甲是否小于等于[A] ==> 1~[A]
	// 参数：范围上限
	static bool effectCondition6(int *arr, int size);

	// 条件效果 - 当前的护甲是否等于[A]
	// 参数：给定值
	static bool effectCondition7(int *arr, int size);

	// 条件效果 - 当前的护甲是否大于等于[A] ==> [A]~(护甲上限)
	// 参数：范围下限
	static bool effectCondition8(int *arr, int size);

	// 条件效果 - 当前的手牌数是否处于[A]~[B]
	// 参数：范围下限，范围上限
	static bool effectCondition9(int *arr, int size);

	// 条件效果 - 当前的手牌数是否小于等于[A] ==> 1~[A]
	// 参数：范围上限
	static bool effectCondition10(int *arr, int size);

	// 条件效果 - 当前的手牌数是否等于[A]
	// 参数：给定值
	static bool effectCondition11(int *arr, int size);

	// 条件效果 - 当前的手牌数是否大于等于[A] ==> [A]~(手牌数上限)
	// 参数：范围下限
	static bool effectCondition12(int *arr, int size);

	// 条件效果 - 开局起第一次血量处于1~[A]
	// 参数：范围上限
	static bool effectCondition13(int *arr, int size);

	// 条件效果 - 当前回合内乙方使得甲方血量减少
	static bool effectCondition14(int *arr, int size);
	//////////////////////////////////////////////////////////////////////////
};

#endif
