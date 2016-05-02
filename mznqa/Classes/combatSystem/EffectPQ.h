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

	/* \brief	Ч�����ͷ��� */
	Effect::Releaser releaser;
	/* \brief	ָ���ܿ� cardId �е�Ч���Ľ����� */
	Effect::Receiver receiver;
	/* \brief	��ʶЧ�����ĸ��׶�ִ�� */
	Effect::ExcuteStyle excuteStyle;
	/* \brief	��ʶЧ���ڵڼ��غ�ִ�� */
	int efRound;

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

	/*!
	 * \fn	EffectAffixes(int level, int cardId, int effectIndex)
	 *
	 * \brief	���캯��
	 *
	 * \param	level	   	ָ�����ȼ�
	 * \param	cardId	   	ָ��ָ��ļ��ܿ�id
	 * \param	effectIndex	ָ��ָ���Ч������
	 */
	EffectAffixes(int level, int cardId, int effectIndex)
	{
		this->level = level;
		this->cardId = cardId;
		this->effectIndex = effectIndex;
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
		return ((this->level == rhs.level) && (this->cardId == rhs.cardId) && (this->effectIndex == rhs.effectIndex));
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
private:

	/*! \brief	Ԥ����Ŀ�Ч�� */
	const static EffectAffixes nullEffectAffixes;

	/*! \brief	�Ӷ��У���ɫ��Ч������ */
	std::priority_queue<EffectAffixes, std::vector<EffectAffixes>, std::greater<EffectAffixes>> rolePQ;
	/*! \brief	�Ӷ��У�������Ч������ */
	std::priority_queue<EffectAffixes, std::vector<EffectAffixes>, std::greater<EffectAffixes>> monsterPQ;

public:

	/*!
	 * \enum	EffectLevelInterval
	 *
	 * \brief	�ּ�����
	 */
	enum EffectLevelInterval
	{
		EffectLevelInterval_Global_Left = 0,	///< ȫ��-��˵�
		EffectLevelInterval_Global_Right = 99,	///< ȫ��-�Ҷ˵�
		EffectLevelInterval_Before_Left = 100,	///< ս��ǰ-��˵�
		EffectLevelInterval_Before_Right = 199,	///< ս��ǰ-�Ҷ˵�
		EffectLevelInterval_In_Left = 200,		///< ս��������-��˵�
		EffectLevelInterval_In_Right = 299,		///< ս��������-�Ҷ˵�
		EffectLevelInterval_After_Left = 300,	///< ս����-��˵�
		EffectLevelInterval_After_Right = 399	///< ս����-�Ҷ˵�
	};

	/*! \brief	��غ�Ч�����ȼ�����ֵ��ÿ�غ�Ч�������е����ȼ�Ӧ���ٸ�ֵ */
	static const int roundEffectLevel = 1000;

	/*!
	 * \fn	EffectPQ::EffectPQ();
	 *
	 * \brief	���캯��
	 *
	 */
	EffectPQ();

	/*!
	 * \fn	EffectPQ::~EffectPQ();
	 *
	 * \brief	��������
	 *
	 */
	~EffectPQ();

	/*!
	 * \fn	void EffectPQ::pushRoleEffectAffixes(EffectAffixes effectAffixes);
	 *
	 * \brief	���ɫ����������Ч��
	 *
	 * \param	effectAffixes	�����͵�Ч��ʵ��
	 */
	void pushRoleEffectAffixes(EffectAffixes effectAffixes);

	/*!
	 * \fn	bool EffectPQ::isRoleEffectPQEmpty();
	 *
	 * \brief	�жϽ�ɫЧ�������Ƿ�Ϊ��
	 *
	 * \return	���ؽ�ɫЧ�������Ƿ�Ϊ��
	 */
	bool isRoleEffectPQEmpty();

	/*!
	 * \fn	EffectAffixes EffectPQ::getRoleEffectAffixesByInterval(EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);
	 *
	 * \brief	�ӽ�ɫ���е����������ȼ������ڵ���С���ȼ�Ч��ʵ��
	 *
	 * \param	leftInterval 	�����ȼ�����
	 * \param	rightInterval	�����ȼ�����
	 *
	 * \return	������ɫ�����и������ȼ������ڵ���С���ȼ�Ч��ʵ��
	 */
	EffectAffixes getRoleEffectAffixesByInterval(EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);

	/*!
	 * \fn	void EffectPQ::decreaseRoleEffectLevel();
	 *
	 * \brief	��������ɫ�����е�Ԫ����һ�ݼ�һ�� roundEffectLevel
	 *
	 */
	void decreaseRoleEffectLevel();

	/*!
	 * \fn	int EffectPQ::getRoleEPQLevelMaxByRoundAndInterval(int relRound, EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);
	 *
	 * \brief	��ȡ������ԻغϺ����ȼ������ڵĵ�ǰ��ɫ�����е�������ȼ�ֵ
	 *
	 * \param	relRound	 	������Իغ�����0ָ����ǰ�غϣ�1��Ϊ�»غϣ��Դ�����
	 * \param	leftInterval	���ȼ���˵�
	 * \param	rightInterval	���ȼ��Ҷ˵�
	 *
	 * \return	���ظ�����ԻغϺ����ȼ������ڵĵ�ǰ��ɫ�����е�������ȼ�ֵ
	 */
	int getRoleEPQLevelMaxByRoundAndInterval(int relRound, EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);

	/*!
	 * \fn	void EffectPQ::popRoleEffectAffixes();
	 *
	 * \brief	����������ɫ���������ȼ���С��Ч��
	 *
	 */
	void popRoleEffectAffixes();

	/*!
	 * \fn	void EffectPQ::popRoleEffectAffixes(EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);
	 *
	 * \brief	������ɫ�����и������ȼ����������ȼ���С��Ч��
	 *
	 * \param	leftInterval 	���ȼ���˵�
	 * \param	rightInterval	���ȼ��Ҷ˵�
	 */
	void popRoleEffectAffixes(EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);

	/*!
	 * \fn	void EffectPQ::popRoleEffectAffixes(EffectAffixes effectAffixes);
	 *
	 * \brief	������ɫ�����е�ĳһЧ���������䵯��
	 *
	 * \param	effectAffixes	ָ����ɫ�����е�ĳһЧ��
	 */
	void popRoleEffectAffixes(EffectAffixes effectAffixes);

	/*!
	 * \fn	void EffectPQ::pushMonsterEffectAffixes(EffectAffixes effectAffixes);
	 *
	 * \brief	��������������Ч��
	 *
	 * \param	effectAffixes	�����͵�Ч��ʵ��
	 */
	void pushMonsterEffectAffixes(EffectAffixes effectAffixes);

	/*!
	 * \fn	bool EffectPQ::isMonsterEffectPQEmpty();
	 *
	 * \brief	�жϹ���Ч�������Ƿ�Ϊ��
	 *
	 * \return	���ع���Ч�������Ƿ�Ϊ��
	 */
	bool isMonsterEffectPQEmpty();

	/*!
	 * \fn	EffectAffixes EffectPQ::getMonsterEffectAffixesByInterval(EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);
	 *
	 * \brief	�ӹ�����е����������ȼ������ڵ���С���ȼ�Ч��ʵ��
	 *
	 * \param	leftInterval 	�����ȼ�����
	 * \param	rightInterval	�����ȼ�����
	 *
	 * \return	������ɫ�����и������ȼ������ڵ���С���ȼ�Ч��ʵ��
	 */
	EffectAffixes getMonsterEffectAffixesByInterval(EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);

	/*!
	 * \fn	void EffectPQ::decreaseMonsterEffectLevel();
	 *
	 * \brief	��������������е�Ԫ����һ�ݼ�һ�� roundEffectLevel
	 *
	 */
	void decreaseMonsterEffectLevel();

	/*!
	 * \fn	int EffectPQ::getMonsterEPQLevelMaxByRoundAndInterval(int relRound, EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);
	 *
	 * \brief	��ȡ������ԻغϺ����ȼ������ڵĵ�ǰ��������е�������ȼ�ֵ
	 *
	 * \param	relRound	 	������Իغ�����0ָ����ǰ�غϣ�1��Ϊ�»غϣ��Դ�����
	 * \param	leftInterval	���ȼ���˵�
	 * \param	rightInterval	���ȼ��Ҷ˵�
	 *
	 * \return	���ظ�����ԻغϺ����ȼ������ڵĵ�ǰ��������е�������ȼ�ֵ
	 */
	int getMonsterEPQLevelMaxByRoundAndInterval(int relRound, EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);

	/*!
	 * \fn	void EffectPQ::popMonsterEffectAffixes();
	 *
	 * \brief	����������ɫ���������ȼ���С��Ч��
	 *
	 */
	void popMonsterEffectAffixes();

	/*!
	 * \fn	void EffectPQ::popMonsterEffectAffixes(EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);
	 *
	 * \brief	������������и������ȼ����������ȼ���С��Ч��
	 *
	 * \param	leftInterval 	���ȼ���˵�
	 * \param	rightInterval	���ȼ��Ҷ˵�
	 */
	void popMonsterEffectAffixes(EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);

	/*!
	 * \fn	void EffectPQ::popMonsterEffectAffixes(EffectAffixes effectAffixes);
	 *
	 * \brief	������������е�ĳһЧ���������䵯��
	 *
	 * \param	effectAffixes	ָ����������е�ĳһЧ��
	 */
	void popMonsterEffectAffixes(EffectAffixes effectAffixes);
};

#endif
