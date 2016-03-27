#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_EFFECT_EFFECT_H_
#define MZNQA_CLASSES_EFFECT_EFFECT_H_

#include <string>
#include <vector>
#include <functional>

class Effect
{
public:
	// Ч���Ľ�����
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

	// ��ȡ��������
	const std::string& getDescribe() const
	{
		return describe;
	}

	// ��ȡЧ���Ľ�����
	Receiver getReceiver() const
	{
		return receiver;
	}

	// ��ȡЧ������ָ������
	int getFunIndex() const
	{
		return funIndex;
	}

	// ��ȡ������
	const std::vector<int>& getArgs() const
	{
		return args;
	}

	// ��ȡ��������
	int getArgsCount() const
	{
		return argsCount;
	}

private:
	// Ч������
	std::string describe;
	// Ч���Ľ�����
	Receiver receiver;
	// ��Ӧ����ָ������
	int funIndex;
	// ������
	std::vector<int> args;
	// ��������
	int argsCount;
};

#endif