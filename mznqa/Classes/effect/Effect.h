#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_EFFECT_EFFECT_H_
#define MZNQA_CLASSES_EFFECT_EFFECT_H_

#include <string>
#include <vector>
#include <functional>

class Effect
{
public:
	// 效果的接收者
	enum Receiver
	{
		Receiver_Other = 0,
		Receiver_Self = 1
	};

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
	~Effect()
	{}

	// 获取卡牌描述
	const std::string& getDescribe() const
	{
		return describe;
	}

	// 获取效果的接收者
	Receiver getReceiver() const
	{
		return receiver;
	}

	// 获取效果函数指针索引
	int getFunIndex() const
	{
		return funIndex;
	}

	// 获取参数表
	const std::vector<int>& getArgs() const
	{
		return args;
	}

	// 获取参数总数
	int getArgsCount() const
	{
		return argsCount;
	}

private:
	// 效果描述
	std::string describe;
	// 效果的接收者
	Receiver receiver;
	// 对应函数指针索引
	int funIndex;
	// 参数表
	std::vector<int> args;
	// 参数总数
	int argsCount;
};

#endif