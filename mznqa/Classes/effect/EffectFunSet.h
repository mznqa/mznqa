/*!
 * \file	Classes\effect\EffectFunSet.h
 *
 * \brief	������ EffectFunSet
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
 * \brief	Ч����Ӧ�ĺ�������
 *
 */
class EffectFunSet
{
public:
	// �յĺ���ָ��
	static const std::function<bool(EffectFunInterface*/*const std::vector<int>&*/)> nullFun;

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
	static const std::function<bool(EffectFunInterface*/*std::vector<int>&*/)>& getFunByIndex(int index)
	{
		auto it = funSet.find(index);
		if (it != funSet.end())
			return it->second;
		else
		{
			cocos2d::log("[warning] ���Ի�ȡ����Ϊ%d��Ч����������������������Ч", index);
			return nullFun;
		}
	}

	// �յ�Ч������ //////////////////////////////////////////////////////////////////////////
	static bool effectNullFun(EffectFunInterface* efi)
	{
		cocos2d::log("[error] ���Ե�����Ч��Ч��������effectNullFun");
		return true;
	}
	//////////////////////////////////////////////////////////////////////////
	
	//// ����Ч�� //////////////////////////////////////////////////////////////////////////
	//static bool effectBase0(EffectFunInterface* efi);
	//
	//static bool effectBase1(const std::vector<int> &args);
	//static bool effectBase2(const std::vector<int> &args);
	//static bool effectBase3(const std::vector<int> &args);
	//static bool effectBase4(const std::vector<int> &args);
	////////////////////////////////////////////////////////////////////////////

	//// ����Ч�� //////////////////////////////////////////////////////////////////////////
	//static bool effectSpecial0(const std::vector<int> &args);
	//static bool effectSpecial1(const std::vector<int> &args);
	//static bool effectSpecial2(const std::vector<int> &args);
	////////////////////////////////////////////////////////////////////////////

	//// ����(Ч��) //////////////////////////////////////////////////////////////////////////
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



	// ����Ч�� //////////////////////////////////////////////////////////////////////////
	static bool effectBase0(EffectFunInterface* efi);

	static bool effectBase1(EffectFunInterface* efi);
	static bool effectBase2(EffectFunInterface* efi);
	static bool effectBase3(EffectFunInterface* efi);
	static bool effectBase4(EffectFunInterface* efi);
	static bool effectBase5(EffectFunInterface* efi);
	//////////////////////////////////////////////////////////////////////////

	// ����Ч�� //////////////////////////////////////////////////////////////////////////
	static bool effectSpecial0(EffectFunInterface* efi);
	static bool effectSpecial1(EffectFunInterface* efi);
	static bool effectSpecial2(EffectFunInterface* efi);
	//////////////////////////////////////////////////////////////////////////

	// ����(Ч��) //////////////////////////////////////////////////////////////////////////
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
	//

	/*! \brief	���Ч�������ļ��� */
	static const std::map<int, std::function<bool(EffectFunInterface*/*const std::vector<int>&*/)>> funSet;
};

#endif
