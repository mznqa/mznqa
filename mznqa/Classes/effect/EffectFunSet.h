#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_EFFECT_EFFECTFUNSET_H_
#define MZNQA_CLASSES_EFFECT_EFFECTFUNSET_H_

#include <array>
#include <functional>
#include <vector>

class EffectFunSet
{
public:
	static const int funCount = 22;

	~EffectFunSet();

	//根据索引获取对应的效果函数指针
	static const std::function<bool(const std::vector<int>&)>& getFunByIndex(int index)
	{
		return funSet[index];
	}

	static bool effectBase0(const std::vector<int> &args);
	static bool effectBase1(const std::vector<int> &args);
	static bool effectBase2(const std::vector<int> &args);
	static bool effectBase3(const std::vector<int> &args);
	static bool effectBase4(const std::vector<int> &args);

	static bool effectSpecial0(const std::vector<int> &args);
	static bool effectSpecial1(const std::vector<int> &args);
	static bool effectSpecial2(const std::vector<int> &args);

	static bool effectCondition0(const std::vector<int> &args);
	static bool effectCondition1(const std::vector<int> &args);
	static bool effectCondition2(const std::vector<int> &args);
	static bool effectCondition3(const std::vector<int> &args);
	static bool effectCondition4(const std::vector<int> &args);
	static bool effectCondition5(const std::vector<int> &args);
	static bool effectCondition6(const std::vector<int> &args);
	static bool effectCondition7(const std::vector<int> &args);
	static bool effectCondition8(const std::vector<int> &args);
	static bool effectCondition9(const std::vector<int> &args);
	static bool effectCondition10(const std::vector<int> &args);
	static bool effectCondition11(const std::vector<int> &args);
	static bool effectCondition12(const std::vector<int> &args);
	static bool effectCondition13(const std::vector<int> &args);

private:
	EffectFunSet(){}
	EffectFunSet(const EffectFunSet &effectFunSet);
	EffectFunSet& operator=(const EffectFunSet &effectFunSet);

	static const std::array<std::function<bool(const std::vector<int>&)>, funCount> funSet;
};

#endif
