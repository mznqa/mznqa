/*!
 * \file	Classes\effect\EffectFunSet.h
 *
 * \brief	������ EffectFunSet
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
 * \brief	Ч����Ӧ�ĺ�������
 *
 */
class EffectFunSet
{
public:

	/*!
	 * \fn	EffectFunSet::~EffectFunSet();
	 *
	 * \brief	��������
	 *
	 */
	~EffectFunSet();

	/*!
	 * \fn	static const std::function<bool(const std::vector<int>&)>& getFunByIndex(int index)
	 *
	 * \brief	���ݸ���������ȡ��Ӧ��Ч������
	 *
	 * \param	index	ָ��Ч������������
	 *
	 * \return	����ָ��������Ӧ��Ч������
	 */
	static const std::function<bool(const std::vector<int>&)>& getFunByIndex(int index)
	{
		if (0 <= index && index < funCount)
			return funSet[index];
		else
		{
			cocos2d::log("[warning] ���Ի�ȡ����Ϊ%d��Ч������������ǰЧ����������Ϊ%d����Ϊ������������Ч", index, funCount);
			return nullFun;
		}
	}

	// ����Ч�� //////////////////////////////////////////////////////////////////////////
	static bool effectBase0(const std::vector<int> &args);
	static bool effectBase1(const std::vector<int> &args);
	static bool effectBase2(const std::vector<int> &args);
	static bool effectBase3(const std::vector<int> &args);
	static bool effectBase4(const std::vector<int> &args);
	//////////////////////////////////////////////////////////////////////////

	// ����Ч�� //////////////////////////////////////////////////////////////////////////
	static bool effectSpecial0(const std::vector<int> &args);
	static bool effectSpecial1(const std::vector<int> &args);
	static bool effectSpecial2(const std::vector<int> &args);
	//////////////////////////////////////////////////////////////////////////

	// ����(Ч��) //////////////////////////////////////////////////////////////////////////
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
	 * \brief	���صĹ��캯��
	 *
	 */
	EffectFunSet(){}

	/*!
	 * \fn	EffectFunSet::EffectFunSet(const EffectFunSet &effectFunSet);
	 *
	 * \brief	���صĿ������캯��
	 *
	 * \param	effectFunSet	EffectFunSet ʵ��
	 */
	EffectFunSet(const EffectFunSet &effectFunSet);

	/*!
	 * \fn	EffectFunSet& EffectFunSet::operator=(const EffectFunSet &effectFunSet);
	 *
	 * \brief	������ֵ�����
	 *
	 * \param	effectFunSet	EffectFunSet ʵ��
	 *
	 * \return	EffectFunSet ʵ��
	 */
	EffectFunSet& operator=(const EffectFunSet &effectFunSet);

	/*! \brief	һ���յĺ���ָ�� */
	static const std::function<bool(const std::vector<int>&)> nullFun;
	/*! \brief	Ч������ */
	static const int funCount = 22;
	/*! \brief	���Ч�������ļ��� */
	static const std::array<std::function<bool(const std::vector<int>&)>, funCount> funSet;
};

#endif
