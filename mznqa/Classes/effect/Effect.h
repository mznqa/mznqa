/*!
 * \file	Classes\effect\Effect.h
 *
 * \brief	定义类 Effect
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_EFFECT_EFFECT_H_
#define MZNQA_CLASSES_EFFECT_EFFECT_H_

#include <string>
#include <vector>
#include <functional>

/*!
 * \class	Effect
 *
 * \brief	组成技能卡的效果
 *
 */

class Effect
{
public:

	/*!
	 * \enum	ExcuteStyle
	 *
	 * \brief	标识效果在哪个环节执行
	 */
	enum ExcuteStyle
	{
		ExcuteStyle_Before = 0,	///< 在战斗前执行
		ExcuteStyle_In = 1,		///< 在战斗过程中执行
		ExcuteStyle_After = 2	///< 在战斗结束后执行
	};

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

	/*！
	* \enum	Releaser
	*
	* \brief	枚举效果的释放者
	*/
	enum Releaser
	{
		Releaser_Monster = 0,	///< 怪物
		Releaser_Role = 1		///< 角色
	};

	/*!
	 * \fn	Effect::Effect ( const std::string &describe, Behavior behavior, Receiver receiver, ExcuteStyle excuteStyle, int funIndex, const std::vector<int> &args )
	 *
	 * \brief	构造函数
	 *
	 * \param	describe	指定效果的描述
	 * \param	behavior	指定效果的主动释放与否
	 * \param	receiver	指定效果的接收者
	 * \param	excuteStyle	指定效果的执行位置
	 * \param	funIndex	指定效果对应的函数索引
	 * \param	args		指向效果的参数表
	 */
	Effect
		(
		const std::string &describe,
		Behavior behavior,
		Receiver receiver,
		ExcuteStyle excuteStyle,
		int funIndex,
		const std::vector<int> &args
		) :
		describe(describe),
		behavior(behavior),
		receiver(receiver),
		excuteStyle(excuteStyle),
		funIndex(funIndex),
		args(args),
		argsCount(args.size())
	{
	}

	/*!
	 * \fn	Effect::~Effect()
	 *
	 * \brief	析构函数
	 */
	~Effect()
	{}

	/*!
	 * \fn	const std::string& Effect::getDescribe() const
	 *
	 * \brief	获取效果的描述
	 *
	 * \return	返回效果的描述
	 */
	const std::string& getDescribe() const
	{
		return describe;
	}

	/*!
	 * \fn	Behavior Effect::getBehavior()const
	 *
	 * \brief	获取效果的主动释放与否
	 *
	 * \return	返回效果的主动释放与否
	 */
	Behavior getBehavior()const
	{
		return behavior;
	}

	/*!
	 * \fn	Receiver Effect::getReceiver() const
	 *
	 * \brief	获取效果的接收者
	 *
	 * \return	返回效果的接收者
	 */
	Receiver getReceiver() const
	{
		return receiver;
	}

	/*!
	 * \fn	ExcuteStyle Effect::getExcuteStyle()const
	 *
	 * \brief	获取效果的执行位置
	 *
	 * \return	返回效果的执行位置
	 */
	ExcuteStyle getExcuteStyle()const
	{
		return excuteStyle;
	}

	/*!
	 * \fn	int Effect::getFunIndex() const
	 *
	 * \brief	获取效果对应的函数索引
	 *
	 * \return	返回效果对应的函数索引
	 */
	int getFunIndex() const
	{
		return funIndex;
	}

	/*!
	 * \fn	const std::vector<int>& Effect::getArgs() const
	 *
	 * \brief	获取效果的参数表
	 *
	 * \return	返回效果的参数表
	 */
	const std::vector<int>& getArgs() const
	{
		return args;
	}

	/*!
	 * \fn	int Effect::getArgsCount() const
	 *
	 * \brief	获取效果所需的参数个数
	 *
	 * \return	返回效果所需的参数个数
	 */
	int getArgsCount() const
	{
		return argsCount;
	}

private:
	/*! \brief	效果的描述 */
	std::string describe;
	/*! \brief	效果主动释放与否 */
	Behavior behavior;
	/*! \brief	效果的接收者 */
	Receiver receiver;
	/*! \brief	效果的执行位置 */
	ExcuteStyle excuteStyle;
	/*! \brief	效果所对应的函数索引 */
	int funIndex;
	/*! \brief	效果的参数表 */
	std::vector<int> args;
	/*! \brief	效果的参数总数 */
	int argsCount;
};

#endif