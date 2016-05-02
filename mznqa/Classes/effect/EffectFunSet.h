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
#include "combatSystem/CombatSystemInterface.h"
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
	static const std::function<bool(CombatSystemInterface*/*const std::vector<int>&*/)> nullFun;

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
	static const std::function<bool(CombatSystemInterface*/*std::vector<int>&*/)>& getFunByIndex(int index)
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

	/*��
	 * \fn	static bool EffectFunSet::effectNullFun(CombatSystemInterface* csi)
	 *
	 * \brief	Ԥ����Ŀյ�Ч������
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectNullFun(CombatSystemInterface* csi)
	{
		cocos2d::log("[error] ���Ե�����Ч��Ч��������effectNullFun");
		return true;
	}

	/*��
	 * \fn	static bool EffectFunSet::effectBase0(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--Ѫ��
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectBase0(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectBase1(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--����
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectBase1(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectBase2(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--������
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectBase2(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectBase3(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--������
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectBase3(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectBase4(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--������
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectBase4(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectBase5(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--����Ѫ
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectBase5(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectSpecial0(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--������Ч
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectSpecial0(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectSpecial1(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--��Ѫ��Ч
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectSpecial1(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectSpecial2(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--�ؼ���Ч
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectSpecial2(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectCondition0(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--��ǰ��Ѫ���Ƿ���[A]~[B]
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectCondition0(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectCondition1(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--��ǰ��Ѫ���Ƿ�С�ڵ���[A] ==> 1~[A]
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectCondition1(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectCondition2(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--��ǰ��Ѫ���Ƿ����[A]
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectCondition2(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectCondition3(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--��ǰ��Ѫ���Ƿ���ڵ���[A] ==> [A]~(Ѫ������)
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectCondition3(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectCondition4(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--��ǰ�Ļ����Ƿ���[A]~[B]
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectCondition4(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectCondition5(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--��ǰ�Ļ����Ƿ�С�ڵ���[A] ==> 1~[A]
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectCondition5(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectCondition6(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--��ǰ�Ļ����Ƿ����[A]
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectCondition6(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectCondition7(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--��ǰ�Ļ����Ƿ���ڵ���[A] ==> [A]~(��������)
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectCondition7(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectCondition8(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--��ǰ���������Ƿ���[A]~[B]
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectCondition8(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectCondition9(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--��ǰ���������Ƿ�С�ڵ���[A] ==> 1~[A]
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectCondition9(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectCondition10(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--��ǰ���������Ƿ����[A]
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectCondition10(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectCondition11(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--��ǰ���������Ƿ���ڵ���[A] ==> [A]~(��������)
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectCondition11(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectCondition12(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--�������һ��Ѫ������[A]~[B]
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectCondition12(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectCondition13(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--�������һ��Ѫ��С�ڵ���0
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectCondition13(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectCondition14(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--�������һ��Ѫ�����ڵ���[A] ==> [A]~(Ѫ������)
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectCondition14(CombatSystemInterface* csi);

	/*��
	 * \fn	static bool EffectFunSet::effectCondition15(CombatSystemInterface* csi);
	 *
	 * \brief	����Ч������--��ǰ�غ����ҷ�ʹ�ü׷�Ѫ������
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����ִ�и�Ч���Ƿ�ɹ�
	 */
	static bool effectCondition15(CombatSystemInterface* csi);
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
	static const std::map<int, std::function<bool(CombatSystemInterface*/*const std::vector<int>&*/)>> funSet;
};

#endif
