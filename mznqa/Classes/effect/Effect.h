#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_EFFECT_EFFECT_H_
#define MZNQA_CLASSES_EFFECT_EFFECT_H_

#include <string>
#include <queue>
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
		int id,
		const std::string &describe,
		Receiver receiver,
		int funIndex,
		const std::queue<int> &args
		) :
		id(id),
		describe(describe),
		receiver(receiver),
		funIndex(funIndex),
		args(args),
		argsCount(args.size())
	{
	}
	~Effect()
	{}

	// ��ȡID
	int getID() const
	{
		return id;
	}

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
	const std::queue<int>& getArgs() const
	{
		return args;
	}

	// ��ȡ��������
	int getArgsCount() const
	{
		return argsCount;
	}

private:
	// Ч��id
	const int id;
	// Ч������
	const std::string describe;
	// Ч���Ľ�����
	const Receiver receiver;
	// ��Ӧ����ָ������
	int funIndex;
	// ������
	const std::queue<int> args;
	// ��������
	const int argsCount;
};

#endif