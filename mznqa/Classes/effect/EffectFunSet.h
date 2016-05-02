/*!
 * \file	Classes\effect\EffectFunSet.h
 *
 * \brief	定义类 EffectFunSet
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_EFFECT_EFFECTFUNSET_H_
#define MZNQA_CLASSES_EFFECT_EFFECTFUNSET_H_

#include <map>
#include <functional>
#include <vector>
#include "combatSystem/EffectFunInterface.h"
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
	// 空的函数指针
	static const std::function<bool(EffectFunInterface*/*const std::vector<int>&*/)> nullFun;

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
	static const std::function<bool(EffectFunInterface*/*std::vector<int>&*/)>& getFunByIndex(int index)
	{
		auto it = funSet.find(index);
		if (it != funSet.end())
			return it->second;
		else
		{
			cocos2d::log("[warning] 尝试获取索引为%d的效果函数，而给定的索引无效", index);
			return nullFun;
		}
	}

	// 空的效果函数 //////////////////////////////////////////////////////////////////////////
	static bool effectNullFun(EffectFunInterface* efi)
	{
		cocos2d::log("[error] 尝试调用无效的效果函数：effectNullFun");
		return true;
	}
	//////////////////////////////////////////////////////////////////////////
	
	//// 基础效果 //////////////////////////////////////////////////////////////////////////
	//static bool effectBase0(EffectFunInterface* efi);
	//
	//static bool effectBase1(const std::vector<int> &args);
	//static bool effectBase2(const std::vector<int> &args);
	//static bool effectBase3(const std::vector<int> &args);
	//static bool effectBase4(const std::vector<int> &args);
	////////////////////////////////////////////////////////////////////////////

	//// 特殊效果 //////////////////////////////////////////////////////////////////////////
	//static bool effectSpecial0(const std::vector<int> &args);
	//static bool effectSpecial1(const std::vector<int> &args);
	//static bool effectSpecial2(const std::vector<int> &args);
	////////////////////////////////////////////////////////////////////////////

	//// 条件(效果) //////////////////////////////////////////////////////////////////////////
	//static bool effectCondition0(const std::vector<int> &args);
	//static bool effectCondition1(const std::vector<int> &args);
	//static bool effectCondition2(const std::vector<int> &args);
	//static bool effectCondition3(const std::vector<int> &args);
	//static bool effectCondition4(const std::vector<int> &args);
	//static bool effectCondition5(const std::vector<int> &args);
	//static bool effectCondition6(const std::vector<int> &args);
	//static bool effectCondition7(const std::vector<int> &args);
	//static bool effectCondition8(const std::vector<int> &args);
	//static bool effectCondition9(const std::vector<int> &args);
	//static bool effectCondition10(const std::vector<int> &args);
	//static bool effectCondition11(const std::vector<int> &args);
	//static bool effectCondition12(const std::vector<int> &args);
	//static bool effectCondition13(const std::vector<int> &args);
	////////////////////////////////////////////////////////////////////////////
	//// 



	// 基础效果 //////////////////////////////////////////////////////////////////////////
	static bool effectBase0(EffectFunInterface* efi);

	static bool effectBase1(EffectFunInterface* efi);
	static bool effectBase2(EffectFunInterface* efi);
	static bool effectBase3(EffectFunInterface* efi);
	static bool effectBase4(EffectFunInterface* efi);
	static bool effectBase5(EffectFunInterface* efi);
	//////////////////////////////////////////////////////////////////////////

	// 特殊效果 //////////////////////////////////////////////////////////////////////////
	static bool effectSpecial0(EffectFunInterface* efi);
	static bool effectSpecial1(EffectFunInterface* efi);
	static bool effectSpecial2(EffectFunInterface* efi);
	//////////////////////////////////////////////////////////////////////////

	// 条件(效果) //////////////////////////////////////////////////////////////////////////
	static bool effectCondition0(EffectFunInterface* efi);
	static bool effectCondition1(EffectFunInterface* efi);
	static bool effectCondition2(EffectFunInterface* efi);
	static bool effectCondition3(EffectFunInterface* efi);
	static bool effectCondition4(EffectFunInterface* efi);
	static bool effectCondition5(EffectFunInterface* efi);
	static bool effectCondition6(EffectFunInterface* efi);
	static bool effectCondition7(EffectFunInterface* efi);
	static bool effectCondition8(EffectFunInterface* efi);
	static bool effectCondition9(EffectFunInterface* efi);
	static bool effectCondition10(EffectFunInterface* efi);
	static bool effectCondition11(EffectFunInterface* efi);
	static bool effectCondition12(EffectFunInterface* efi);
	static bool effectCondition13(EffectFunInterface* efi);
	static bool effectCondition14(EffectFunInterface* efi);
	static bool effectCondition15(EffectFunInterface* efi);
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
	//

	/*! \brief	存放效果函数的集合 */
	static const std::map<int, std::function<bool(EffectFunInterface*/*const std::vector<int>&*/)>> funSet;
};

#endif
