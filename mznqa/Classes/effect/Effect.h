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
	 * \enum	Receiver
	 *
	 * \brief	枚举效果的接收者
	 */
	enum Receiver
	{
		Receiver_Other = 0,	///< 对方
		Receiver_Self = 1	///< 自身
	};

	/*!
	 * \fn	Effect::Effect ( const std::string &describe, Receiver receiver, int funIndex, const std::vector<int> &args )
	 *
	 * \brief	构造函数
	 *
	 * \param	describe	指定效果的描述
	 * \param	receiver	指定效果的接收者
	 * \param	funIndex	指定效果对应的函数索引
	 * \param	args		指向效果的参数表
	 */
	Effect
		(
		const std::string &describe,
		Receiver receiver,
		int funIndex,
		const std::vector<int> &args
		) :
		describe(describe),
		receiver(receiver),
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
	/*! \brief	效果的接收者 */
	Receiver receiver;
	/*! \brief	效果所对应的函数索引 */
	int funIndex;
	/*! \brief	效果的参数表 */
	std::vector<int> args;
	/*! \brief	效果的参数总数 */
	int argsCount;
};

#endif