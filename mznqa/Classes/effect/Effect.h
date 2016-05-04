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
	 * \enum	ExcuteStyle
	 *
	 * \brief	��ʶЧ�����ĸ�����ִ��
	 */
	enum ExcuteStyle
	{
		ExcuteStyle_Before = 0,	///< ��ս��ǰִ��
		ExcuteStyle_In = 1,		///< ��ս��������ִ��
		ExcuteStyle_After = 2	///< ��ս��������ִ��
	};

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

	/*��
	* \enum	Releaser
	*
	* \brief	ö��Ч�����ͷ���
	*/
	enum Releaser
	{
		Releaser_Monster = 0,	///< ����
		Releaser_Role = 1		///< ��ɫ
	};

	/*!
	 * \fn	Effect::Effect ( const std::string &describe, Behavior behavior, Receiver receiver, ExcuteStyle excuteStyle, int funIndex, const std::vector<int> &args )
	 *
	 * \brief	���캯��
	 *
	 * \param	describe	ָ��Ч��������
	 * \param	behavior	ָ��Ч���������ͷ����
	 * \param	receiver	ָ��Ч���Ľ�����
	 * \param	excuteStyle	ָ��Ч����ִ��λ��
	 * \param	funIndex	ָ��Ч����Ӧ�ĺ�������
	 * \param	args		ָ��Ч���Ĳ�����
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
	 * \fn	Behavior Effect::getBehavior()const
	 *
	 * \brief	��ȡЧ���������ͷ����
	 *
	 * \return	����Ч���������ͷ����
	 */
	Behavior getBehavior()const
	{
		return behavior;
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
	 * \fn	ExcuteStyle Effect::getExcuteStyle()const
	 *
	 * \brief	��ȡЧ����ִ��λ��
	 *
	 * \return	����Ч����ִ��λ��
	 */
	ExcuteStyle getExcuteStyle()const
	{
		return excuteStyle;
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
	/*! \brief	Ч�������ͷ���� */
	Behavior behavior;
	/*! \brief	Ч���Ľ����� */
	Receiver receiver;
	/*! \brief	Ч����ִ��λ�� */
	ExcuteStyle excuteStyle;
	/*! \brief	Ч������Ӧ�ĺ������� */
	int funIndex;
	/*! \brief	Ч���Ĳ����� */
	std::vector<int> args;
	/*! \brief	Ч���Ĳ������� */
	int argsCount;
};

#endif