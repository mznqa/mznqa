/*!
 * \file	Classes\effect\EffectFunSet.h
 *
 * \brief	定义类 EffectFunSet
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_EFFECT_EFFECTFUNSET_H_
#define MZNQA_CLASSES_EFFECT_EFFECTFUNSET_H_

#include <array>
#include <functional>
#include <vector>

#include "cocos2d.h"

/*!
 * \class	EffectFunSet
 *
 * \brief	效果对应的函数集合
 *
 */
class EffectFunSet
{
public:

	/*!
	 * \fn	EffectFunSet::~EffectFunSet();
	 *
	 * \brief	析构函数
	 *
	 */
	~EffectFunSet();

	/*!
	 * \fn	static const std::function<bool(const std::vector<int>&)>& getFunByIndex(int index)
	 *
	 * \brief	根据给定索引获取对应的效果函数
	 *
	 * \param	index	指定效果函数的索引
	 *
	 * \return	返回指定索引对应的效果函数
	 */
	static const std::function<bool(const std::vector<int>&)>& getFunByIndex(int index)
	{
		if (0 <= index && index < funCount)
			return funSet[index];
		else
		{
			cocos2d::log("[warning] 尝试获取索引为%d的效果函数，而当前效果函数总数为%d，因为给定的索引无效", index, funCount);
			return nullFun;
		}
	}

	// 基础效果 //////////////////////////////////////////////////////////////////////////
	static bool effectBase0(const std::vector<int> &args);
	static bool effectBase1(const std::vector<int> &args);
	static bool effectBase2(const std::vector<int> &args);
	static bool effectBase3(const std::vector<int> &args);
	static bool effectBase4(const std::vector<int> &args);
	//////////////////////////////////////////////////////////////////////////

	// 特殊效果 //////////////////////////////////////////////////////////////////////////
	static bool effectSpecial0(const std::vector<int> &args);
	static bool effectSpecial1(const std::vector<int> &args);
	static bool effectSpecial2(const std::vector<int> &args);
	//////////////////////////////////////////////////////////////////////////

	// 条件(效果) //////////////////////////////////////////////////////////////////////////
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
	//////////////////////////////////////////////////////////////////////////

private:

	/*!
	 * \fn	EffectFunSet::EffectFunSet()
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	EffectFunSet(){}

	/*!
	 * \fn	EffectFunSet::EffectFunSet(const EffectFunSet &effectFunSet);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 * \param	effectFunSet	EffectFunSet 实例
	 */
	EffectFunSet(const EffectFunSet &effectFunSet);

	/*!
	 * \fn	EffectFunSet& EffectFunSet::operator=(const EffectFunSet &effectFunSet);
	 *
	 * \brief	拷贝赋值运算符
	 *
	 * \param	effectFunSet	EffectFunSet 实例
	 *
	 * \return	EffectFunSet 实例
	 */
	EffectFunSet& operator=(const EffectFunSet &effectFunSet);

	/*! \brief	一个空的函数指针 */
	static const std::function<bool(const std::vector<int>&)> nullFun;
	/*! \brief	效果总数 */
	static const int funCount = 22;
	/*! \brief	存放效果函数的集合 */
	static const std::array<std::function<bool(const std::vector<int>&)>, funCount> funSet;
};

#endif
