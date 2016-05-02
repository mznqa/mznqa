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
#include "combatSystem/CombatSystemInterface.h"
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
	static const std::function<bool(CombatSystemInterface*/*const std::vector<int>&*/)> nullFun;

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
	static const std::function<bool(CombatSystemInterface*/*std::vector<int>&*/)>& getFunByIndex(int index)
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

	/*！
	 * \fn	static bool EffectFunSet::effectNullFun(CombatSystemInterface* csi)
	 *
	 * \brief	预定义的空的效果函数
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectNullFun(CombatSystemInterface* csi)
	{
		cocos2d::log("[error] 尝试调用无效的效果函数：effectNullFun");
		return true;
	}

	/*！
	 * \fn	static bool EffectFunSet::effectBase0(CombatSystemInterface* csi);
	 *
	 * \brief	基础效果函数--血量
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectBase0(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectBase1(CombatSystemInterface* csi);
	 *
	 * \brief	基础效果函数--护甲
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectBase1(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectBase2(CombatSystemInterface* csi);
	 *
	 * \brief	基础效果函数--手牌数
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectBase2(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectBase3(CombatSystemInterface* csi);
	 *
	 * \brief	基础效果函数--抽牌数
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectBase3(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectBase4(CombatSystemInterface* csi);
	 *
	 * \brief	基础效果函数--出牌数
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectBase4(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectBase5(CombatSystemInterface* csi);
	 *
	 * \brief	基础效果函数--回满血
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectBase5(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectSpecial0(CombatSystemInterface* csi);
	 *
	 * \brief	特殊效果函数--攻击无效
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectSpecial0(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectSpecial1(CombatSystemInterface* csi);
	 *
	 * \brief	特殊效果函数--回血无效
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectSpecial1(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectSpecial2(CombatSystemInterface* csi);
	 *
	 * \brief	特殊效果函数--回甲无效
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectSpecial2(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectCondition0(CombatSystemInterface* csi);
	 *
	 * \brief	条件效果函数--当前的血量是否处于[A]~[B]
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectCondition0(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectCondition1(CombatSystemInterface* csi);
	 *
	 * \brief	条件效果函数--当前的血量是否小于等于[A] ==> 1~[A]
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectCondition1(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectCondition2(CombatSystemInterface* csi);
	 *
	 * \brief	条件效果函数--当前的血量是否等于[A]
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectCondition2(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectCondition3(CombatSystemInterface* csi);
	 *
	 * \brief	条件效果函数--当前的血量是否大于等于[A] ==> [A]~(血量上限)
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectCondition3(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectCondition4(CombatSystemInterface* csi);
	 *
	 * \brief	条件效果函数--当前的护甲是否处于[A]~[B]
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectCondition4(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectCondition5(CombatSystemInterface* csi);
	 *
	 * \brief	条件效果函数--当前的护甲是否小于等于[A] ==> 1~[A]
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectCondition5(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectCondition6(CombatSystemInterface* csi);
	 *
	 * \brief	条件效果函数--当前的护甲是否等于[A]
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectCondition6(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectCondition7(CombatSystemInterface* csi);
	 *
	 * \brief	条件效果函数--当前的护甲是否大于等于[A] ==> [A]~(护甲上限)
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectCondition7(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectCondition8(CombatSystemInterface* csi);
	 *
	 * \brief	条件效果函数--当前的手牌数是否处于[A]~[B]
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectCondition8(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectCondition9(CombatSystemInterface* csi);
	 *
	 * \brief	条件效果函数--当前的手牌数是否小于等于[A] ==> 1~[A]
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectCondition9(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectCondition10(CombatSystemInterface* csi);
	 *
	 * \brief	条件效果函数--当前的手牌数是否等于[A]
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectCondition10(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectCondition11(CombatSystemInterface* csi);
	 *
	 * \brief	条件效果函数--当前的手牌数是否大于等于[A] ==> [A]~(手牌上限)
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectCondition11(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectCondition12(CombatSystemInterface* csi);
	 *
	 * \brief	条件效果函数--开局起第一次血量处于[A]~[B]
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectCondition12(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectCondition13(CombatSystemInterface* csi);
	 *
	 * \brief	条件效果函数--开局起第一次血量小于等于0
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectCondition13(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectCondition14(CombatSystemInterface* csi);
	 *
	 * \brief	条件效果函数--开局起第一次血量大于等于[A] ==> [A]~(血量上限)
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectCondition14(CombatSystemInterface* csi);

	/*！
	 * \fn	static bool EffectFunSet::effectCondition15(CombatSystemInterface* csi);
	 *
	 * \brief	条件效果函数--当前回合内乙方使得甲方血量减少
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回执行该效果是否成功
	 */
	static bool effectCondition15(CombatSystemInterface* csi);
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
	static const std::map<int, std::function<bool(CombatSystemInterface*/*const std::vector<int>&*/)>> funSet;
};

#endif
