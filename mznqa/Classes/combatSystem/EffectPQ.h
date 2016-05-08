/*!
 * \file	Classes\combatSystem\EffectPQ.h
 *
 * \brief	������ EffectAffixes ���� EffectPQ
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_EFFECTPQ_H_
#define MZNQA_CLASSES_COMBATSYSTEM_EFFECTPQ_H_

#include <queue>
#include <functional>
#include <array>
#include <vector>
#include "effect/Effect.h"
#include "card/CardBase.h"

/*!
 * \struct	EffectAffixes
 *
 * \brief	�������뵽Ч�����е�Ԫ��
 *
 */
struct EffectAffixes
{
	/*! \brief	���ȼ� */
	int level;

	/*! \brief	��Ӧ�ļ��ܿ�id */
	int cardId;

	/*! \brief	ָ���ܿ� cardId �е�Ч�������� */
	int effectIndex;

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

	/* \brief	Ч�����ͷ��� */
	Releaser releaser;
	/* \brief	ָ���ܿ� cardId �е�Ч���Ľ����� */
	Effect::Receiver receiver;
	/* \brief	��ʶЧ�����ĸ��׶�ִ�� */
	Effect::ExcuteStyle excuteStyle;
	/* \brief	��ʶЧ���ڵڼ��غ�ִ�� */
	int efRound = invalidEffectRoundValue;
	
	/*��
	 * \fn	EffectAffixes()
	 *
	 * \brief	Ĭ�ϵĹ��캯��
	 */
	EffectAffixes()
	{

	}

	/*! \brief	��Ч�����ȼ� */
	static const int invalidLevelValue = -1;
	/*! \brief	��Ч�ļ��ܿ�id */
	static const int invalidCardIdValue = CardBase::invalidID;
	/*! \brief	��Ч��Ч������ */
	static const int invalidEffectIndexValue = -1;
	/* \brief	��Ч��Ч���غ��� */
	static const int invalidEffectRoundValue = -1;

	/*��
	 * \fn	EffectAffixes(int level, int cardId, int effectIndex, Releaser releaser, Effect::Receiver receiver, Effect::ExcuteStyle excuteStyle, int efRound)
	 *
	 * \brief	���캯��.
	 *
	 * \param	level	   	ָ�����ȼ�
	 * \param	cardId	   	ָ��ָ��ļ��ܿ�id
	 * \param	effectIndex	ָ��ָ���Ч������
	 * \param	releaser   	ָ��ָ���Ч���ͷ���
	 * \param	receiver   	ָ��ָ���Ч��������
	 * \param	excuteStyle	ָ��ָ���Ч��ִ�ж�
	 * \param	efRound	   	ָ��ָ���Ч���غ���
	 */
	EffectAffixes(int level, int cardId, int effectIndex, Releaser releaser, Effect::Receiver receiver, Effect::ExcuteStyle excuteStyle, int efRound)
	{
		this->level = level;
		this->cardId = cardId;
		this->effectIndex = effectIndex;
		this->releaser = releaser;
		this->receiver = receiver;
		this->excuteStyle = excuteStyle;
		this->efRound = efRound;
	}

	/*!
	 * \fn	bool operator<(const EffectAffixes &rhs) const
	 *
	 * \brief	<�����
	 *
	 * \param	rhs	EffectAffixes ʵ��
	 *
	 * \return	�������ȼ��ıȽϽ��
	 */
	bool operator<(const EffectAffixes &rhs) const
	{
		return this->level < rhs.level;
	}

	/*!
	 * \fn	bool operator>(const EffectAffixes &rhs) const
	 *
	 * \brief	>�����
	 *
	 * \param	rhs	EffectAffixes ʵ��
	 *
	 * \return	�������ȼ��ıȽϽ��
	 */
	bool operator>(const EffectAffixes &rhs) const
	{
		return this->level > rhs.level;
	}

	/*!
	 * \fn	bool operator== (const EffectAffixes &rhs) const
	 *
	 * \brief	==�����
	 *
	 * \param	rhs	EffectAffixes ʵ��
	 *
	 * \return	�����Ƿ����
	 */
	bool operator == (const EffectAffixes &rhs) const
	{
		return ((this->level == rhs.level) && 
				(this->cardId == rhs.cardId) && 
				(this->effectIndex == rhs.effectIndex) &&
				(this->releaser == rhs.releaser) && 
				(this->receiver == rhs.receiver) &&
				(this->excuteStyle == rhs.excuteStyle) &&
				(this->efRound == rhs.efRound));
	}
};

/*!
 * \class	EffectPQ
 *
 * \brief	����ս��ϵͳ�Ĵ�ִ�е�Ч���Ķ��еļ���
 *
 */
class EffectPQ
{
public:
	//Ч�������±�����
	enum EffectQueueIndex
	{
		EffectQueueIndex_Global = 0,
		EffectQueueIndex_Before = 1,
		EffectQueueIndex_In = 2,
		EffectQueueIndex_After = 3		
	};
	//ÿ�غ����Ķ��и���
	static const int queueSizeMax = 4;

	//���캯��
	EffectPQ();
	//��������
	~EffectPQ();
	//����ָ������Իغ������±����������ɫ�������Ч����������
	void pushEffectAffixesRole(EffectAffixes& effectAffixes, const int relRound, const int index);

	//����Ч����ִ�н׶Σ���ȡ��ɫ��ǰ�غϸý׶ε�Ч����������ʵ��
	const EffectAffixes& getEffectAffixesRole(EffectQueueIndex effectQueueIndex);

	//����ָ������Իغ������±���������ȡ��ɫָ�������ڵ��������ȼ�
	int getEPQLevelMaxRoleByRoundAndIndex(const int relRound, const int index);

	//����ָ������Իغ������±�������������ɫָ����������С���ȼ���Ч����������ʵ��
	void popEffectAffixesRole(const int relRound, const int index);

	//��ɫÿ�غϵ�Ч���������
	void decreaseRoundEffectRole();


	//����ָ������Իغ������±������������������Ч����������
	void pushEffectAffixesMonster(EffectAffixes& effectAffixes, const int relRound, const int index);
	//����Ч����ִ�н׶Σ���ȡ���ﵱǰ�غϸý׶ε�Ч����������ʵ��
	const EffectAffixes& getEffectAffixesMonster(EffectQueueIndex effectQueueIndex);
	//����ָ������Իغ������±���������ȡ����ָ�������ڵ��������ȼ�
	int getEPQLevelMaxMonsterByRoundAndIndex(const int relRound, const int index);

	//����ָ������Իغ������±���������������ָ����������С���ȼ���Ч����������ʵ��
	void popEffectAffixesMonster(const int relRound, const int index);

	//����ÿ�غϵ�Ч���������
	void decreaseRoundEffectMonster();
	
	//����ֱЧ����ִ�н׶Σ���ȡ���е�����
	const int getIndexByExcuteStyle(Effect::ExcuteStyle excuteStyle);

	//���ָ�������Ƿ�Խ��
	bool checkOutOfRange(const int& relRound, const int& index);
	
private:

	//��ɫЧ������
	std::vector<std::array<std::priority_queue<int, std::vector<EffectAffixes>, std::greater<EffectAffixes>>, queueSizeMax>> rolePQ;
	//����Ч������
	std::vector<std::array<std::priority_queue<int, std::vector<EffectAffixes>, std::greater<EffectAffixes>>, queueSizeMax>> monsterPQ;
	//Ԥ����Ŀ�Ч��
	const static EffectAffixes nullEffectAffixes;
};


#endif
