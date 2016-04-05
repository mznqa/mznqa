/*!
 * \file	Classes\effect\Effect.h
 *
 * \brief	������ Effect
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
 * \brief	��ɼ��ܿ���Ч��
 *
 */

class Effect
{
public:

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

	/*!
	 * \fn	Effect::Effect ( const std::string &describe, Receiver receiver, int funIndex, const std::vector<int> &args )
	 *
	 * \brief	���캯��
	 *
	 * \param	describe	ָ��Ч��������
	 * \param	receiver	ָ��Ч���Ľ�����
	 * \param	funIndex	ָ��Ч����Ӧ�ĺ�������
	 * \param	args		ָ��Ч���Ĳ�����
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
	 * \brief	��������
	 */
	~Effect()
	{}

	/*!
	 * \fn	const std::string& Effect::getDescribe() const
	 *
	 * \brief	��ȡЧ��������
	 *
	 * \return	����Ч��������
	 */
	const std::string& getDescribe() const
	{
		return describe;
	}

	/*!
	 * \fn	Receiver Effect::getReceiver() const
	 *
	 * \brief	��ȡЧ���Ľ�����
	 *
	 * \return	����Ч���Ľ�����
	 */
	Receiver getReceiver() const
	{
		return receiver;
	}

	/*!
	 * \fn	int Effect::getFunIndex() const
	 *
	 * \brief	��ȡЧ����Ӧ�ĺ�������
	 *
	 * \return	����Ч����Ӧ�ĺ�������
	 */
	int getFunIndex() const
	{
		return funIndex;
	}

	/*!
	 * \fn	const std::vector<int>& Effect::getArgs() const
	 *
	 * \brief	��ȡЧ���Ĳ�����
	 *
	 * \return	����Ч���Ĳ�����
	 */
	const std::vector<int>& getArgs() const
	{
		return args;
	}

	/*!
	 * \fn	int Effect::getArgsCount() const
	 *
	 * \brief	��ȡЧ������Ĳ�������
	 *
	 * \return	����Ч������Ĳ�������
	 */
	int getArgsCount() const
	{
		return argsCount;
	}

private:
	/*! \brief	Ч�������� */
	std::string describe;
	/*! \brief	Ч���Ľ����� */
	Receiver receiver;
	/*! \brief	Ч������Ӧ�ĺ������� */
	int funIndex;
	/*! \brief	Ч���Ĳ����� */
	std::vector<int> args;
	/*! \brief	Ч���Ĳ������� */
	int argsCount;
};

#endif