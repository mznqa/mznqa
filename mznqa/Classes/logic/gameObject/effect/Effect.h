/*!
 * \file	Classes\logic\gameObject\effect\Effect.h
 *
 * \brief	����ṹ�� Effect
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_EFFECT_EFFECT_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_EFFECT_EFFECT_H_

#include <vector>

#include "logic/data/static/stringSet/StringSet.h"
#include "logic/data/static/effectSet/EffectFunSet.h"

/*!
 * \struct	Effect
 *
 * \brief	��ɼ��ܿ���Ч��
 *
 */
struct Effect
{
	/*!
	* \enum	Behavior
	*
	* \brief	ö�ٸ�Ч���������ͷ����
	*/
	enum Behavior
	{
		Behavior_Active = 0,	///< �����ͷŵ�Ч��
		Behavior_Passive = 1	///< �����ͷŵ�Ч��
	};

	/*!
	* \enum	Receiver
	*
	* \brief	ö��Ч���Ľ�����
	*/
	enum Receiver
	{
		Receiver_Other = 0,	///< �Է�
		Receiver_Self = 1	///< ����
	};

	/*! \brief	Ч������SID */
	int sidName;
	/*! \brief	Ч������SID */
	int sidDescribe;
	/*! \brief	Ч�������ͷ���� */
	Behavior behavior;
	/*! \brief	Ч���Ľ����� */
	Receiver receiver;
	/*! \brief	Ч������Ӧ�ĺ������� */
	int funIndex;
	/*! \brief	Ч���Ĳ����� */
	std::vector<int> args;

	/*!
	 * \fn	Effect() : sidName(StringSet::StringID_Null), sidDescribe(StringSet::StringID_Null), behavior(Behavior_Active), receiver(Receiver_Other), funIndex(EffectFunSet::nullEffectIndex), args()
	 *
	 * \brief	���캯��
	 *
	 */
	Effect() :
		sidName(StringSet::StringID_Null),
		sidDescribe(StringSet::StringID_Null),
		behavior(Behavior_Active),
		receiver(Receiver_Other),
		funIndex(EffectFunSet::nullEffectIndex),
		args()
	{
	}

	/*!
	 * \fn	Effect( int sidName, int sidDescribe, Behavior behavior, Receiver receiver, int funIndex, const std::vector<int> &args )
	 *
	 * \brief	���캯��
	 *
	 * \param	sidName	   	ָ��Ч������SID
	 * \param	sidDescribe	ָ��Ч������SID
	 * \param	behavior   	ָ��Ч���ͷ���Ϊ
	 * \param	receiver   	ָ��Ч��������
	 * \param	funIndex   	ָ��Ч����Ӧ��Ч����������
	 * \param	args	   	ָ��Ч������Ĳ���
	 */
	Effect(
		int sidName,
		int sidDescribe,
		Behavior behavior,
		Receiver receiver,
		int funIndex,
		const std::vector<int> &args
		) :
		sidName(sidName),
		sidDescribe(sidDescribe),
		behavior(behavior),
		receiver(receiver),
		funIndex(funIndex),
		args(args)
	{
	}

	/*!
	 * \fn	Effect(const Effect &effect);
	 *
	 * \brief	�������캯��
	 *
	 */
	Effect(const Effect &effect) :
		sidName(effect.sidName),
		sidDescribe(effect.sidDescribe),
		behavior(effect.behavior),
		receiver(effect.receiver),
		funIndex(effect.funIndex),
		args(effect.args)
	{
	}

	/*!
	 * \fn	Effect& operator=(const Effect &effect);
	 *
	 * \brief	������ֵ�����
	 *
	 */
	Effect& operator=(const Effect &effect)
	{
		this->sidName = effect.sidName;
		this->sidDescribe = effect.sidDescribe;
		this->behavior = effect.behavior;
		this->receiver = effect.receiver;
		this->funIndex = effect.funIndex;
		this->args = effect.args;
		return *this;
	}

	/*!
	 * \fn	~Effect()
	 *
	 * \brief	��������
	 *
	 */
	~Effect()
	{
	}
};

#endif
