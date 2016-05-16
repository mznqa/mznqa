/*!
 * \file	Classes\logic\gameObject\effect\Effect.h
 *
 * \brief	定义结构体 Effect
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
 * \brief	组成技能卡的效果
 *
 */
struct Effect
{
	/*!
	* \enum	Behavior
	*
	* \brief	枚举该效果的主动释放与否
	*/
	enum Behavior
	{
		Behavior_Active = 0,	///< 主动释放的效果
		Behavior_Passive = 1	///< 被动释放的效果
	};

	/*!
	* \enum	Receiver
	*
	* \brief	枚举效果的接收者
	*/
	enum Receiver
	{
		Receiver_Other = 0,	///< 对方
		Receiver_Self = 1	///< 自身
	};

	/*! \brief	效果名称SID */
	int sidName;
	/*! \brief	效果描述SID */
	int sidDescribe;
	/*! \brief	效果主动释放与否 */
	Behavior behavior;
	/*! \brief	效果的接收者 */
	Receiver receiver;
	/*! \brief	效果所对应的函数索引 */
	int funIndex;
	/*! \brief	效果的参数表 */
	std::vector<int> args;

	/*!
	 * \fn	Effect() : sidName(StringSet::StringID_Null), sidDescribe(StringSet::StringID_Null), behavior(Behavior_Active), receiver(Receiver_Other), funIndex(EffectFunSet::nullEffectIndex), args()
	 *
	 * \brief	构造函数
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
	 * \brief	构造函数
	 *
	 * \param	sidName	   	指定效果名称SID
	 * \param	sidDescribe	指定效果描述SID
	 * \param	behavior   	指定效果释放行为
	 * \param	receiver   	指定效果接收者
	 * \param	funIndex   	指定效果对应的效果函数索引
	 * \param	args	   	指定效果所需的参数
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
	 * \brief	拷贝构造函数
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
	 * \brief	拷贝赋值运算符
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
	 * \brief	析构函数
	 *
	 */
	~Effect()
	{
	}
};

#endif
