/*!
 * \file	Classes\logic\data\static\effectSet\EffectFunSet.h
 *
 * \brief	定义类 EffectFunSet
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_DATA_STATIC_EFFECTSET_EFFECTFUNSET_H_
#define MZNQA_CLASSES_LOGIC_DATA_STATIC_EFFECTSET_EFFECTFUNSET_H_

#include <functional>
#include <vector>
#include <map>

/*!
 * \class	EffectFunSet
 *
 * \brief	静态效果函数库
 *
 */
class EffectFunSet
{
private:

	/*!
	 * \fn	EffectFunSet::EffectFunSet()
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	EffectFunSet()
	{
	}

	/*!
	 * \fn	EffectFunSet::EffectFunSet(const EffectFunSet &effectFunSet);
	 *
	 * \brief	隐藏的析构函数
	 *
	 */
	EffectFunSet(const EffectFunSet &effectFunSet);

	/*!
	 * \fn	EffectFunSet& EffectFunSet::operator=(const EffectFunSet &effectFunSet);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 */
	EffectFunSet& operator=(const EffectFunSet &effectFunSet);

	/*! \brief	一个空的函数指针 */
	static const std::function<bool(const std::vector<int>&)> nullFun;
	/*! \brief	存放效果函数的集合 */
	static const std::map<int, std::function<bool(const std::vector<int>&)>> funSet;
public:

	/*!
	 * \fn	EffectFunSet::~EffectFunSet();
	 *
	 * \brief	析构函数
	 *
	 */
	~EffectFunSet();

	/*! \brief	空的效果索引 */
	static const int nullEffectIndex = -1;

	/*!
	 * \fn	static const std::function<bool(const std::vector<int>&)>& getFunByIndex(int index)
	 *
	 * \brief	获取根据效果索引效果函数指针
	 *
	 * \param	index	指定效果索引
	 *
	 */
	static const std::function<bool(const std::vector<int>&)>& getFunByIndex(int index)
	{
		auto it = funSet.find(index);
		if (it != funSet.end())
			return it->second;
		else
		{
			return nullFun;
		}
	}

	/*!
	 * \fn	static bool EffectFunSet::effectNull(const std::vector<int> &args);
	 *
	 * \brief	空的无效的效果函数
	 *
	 * \param	args	指定参数表
	 *
	 * \return	返回效果执行成与否
	 */
	static bool effectNull(const std::vector<int> &args);

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
};

#endif
