/*!
 * \file	Classes\logic\data\static\effectSet\EffectFunSet.h
 *
 * \brief	������ EffectFunSet
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
 * \brief	��̬Ч��������
 *
 */
class EffectFunSet
{
private:

	/*!
	 * \fn	EffectFunSet::EffectFunSet()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	EffectFunSet()
	{
	}

	/*!
	 * \fn	EffectFunSet::EffectFunSet(const EffectFunSet &effectFunSet);
	 *
	 * \brief	���ص���������
	 *
	 */
	EffectFunSet(const EffectFunSet &effectFunSet);

	/*!
	 * \fn	EffectFunSet& EffectFunSet::operator=(const EffectFunSet &effectFunSet);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	EffectFunSet& operator=(const EffectFunSet &effectFunSet);

	/*! \brief	һ���յĺ���ָ�� */
	static const std::function<bool(const std::vector<int>&)> nullFun;
	/*! \brief	���Ч�������ļ��� */
	static const std::map<int, std::function<bool(const std::vector<int>&)>> funSet;
public:

	/*!
	 * \fn	EffectFunSet::~EffectFunSet();
	 *
	 * \brief	��������
	 *
	 */
	~EffectFunSet();

	/*! \brief	�յ�Ч������ */
	static const int nullEffectIndex = -1;

	/*!
	 * \fn	static const std::function<bool(const std::vector<int>&)>& getFunByIndex(int index)
	 *
	 * \brief	��ȡ����Ч������Ч������ָ��
	 *
	 * \param	index	ָ��Ч������
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
	 * \brief	�յ���Ч��Ч������
	 *
	 * \param	args	ָ��������
	 *
	 * \return	����Ч��ִ�г����
	 */
	static bool effectNull(const std::vector<int> &args);

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
};

#endif
