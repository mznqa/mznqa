#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_
#define MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_

#include "card/CardBase.h"
#include "effect/Effect.h"
#include "combatSystem/EffectPQ.h"

/*��
 * \struct	DeltaTable
 *
 * \brief	������ṹ�壬��¼��ʷЧ��
 *
 */
struct DeltaTable
{
	/* \brief	Ч�������Ŀ��Ʊ�� */
	int ID = CardBase::invalidID;
	
	/* \brief	��Чֵ */
	static const int invalid = -1;

	/*��
	 * \enum	RoundLevel
	 *
	 * \brief	ö��ÿ�غ���Ч����ִ�н׶�
	 */
	enum RoundLevel
	{ 
		RoundLevel_invalid = invalid,	///< ��Ч��Ч��ִ�ж�
		RoundLevel_Global = 0,			///< ȫ�ֵ�Ч��ִ�ж�
		RoundLevel_Before = 1,			///< ս��ǰ��Ч��ִ�ж�
		RoundLevel_In = 2,				///< ս��ʱ��Ч��ִ�ж�
		RoundLevel_After= 3,			///< ս�����Ч��ִ�ж�
		RoundLevel_Total = 4			///< �غϽ��������
	};

	/* \brief	��¼Ч����ִ�н׶� */
	RoundLevel roundLevel = RoundLevel_invalid;

	//Ч���ͷ���
	EffectAffixes::Releaser releaser;
	//Ч��������
	Effect::Receiver receiver;
	//������ʷЧ����Ϣ
	void setEffectHistoryInfo(const EffectAffixes& effectAffixes);
	//������ʷЧ������Ѫ��
	void setEffectTableBlood(const int deltaBlood);
	//������ʷЧ����������
	void setEffectTableArmor(const int deltaArmor);
	//������ʷЧ������������
	void setEffectTableHandCardCount(const int deltaHandCardCount);
	//������ʷЧ�������ɳ�����
	void setEffectTableDrawCardCount(const int deltaDrawCardCount);
	//������ʷЧ�������ɳ�����
	void setEffectTableDiscardCount(const int deltaDiscardCount);
	//�����ʷЧ��
	void addHistoryEffect();

	enum Flag
	{
		Flag_Invalid = -1,
		Flag_Blood_Role,
		Flag_Blood_Monster,
		Flag_Armor_Role,
		Flag_Armor_Monster,
		Flag_Hand_Role,
		Flag_Draw_Role,
		Flag_Discard_Role
	};
	Flag flag = Flag_Invalid;

	/* \brief	��¼Ч�����ͷŻغ��� */
	int roundNumber = EffectAffixes::invalidEffectRoundValue;

	static const int row = 5,  col = 2;
	/* \brief	��¼Ч��Ӱ��������ԵĶ�ά�� */
	int effectTable[row][col];

	/*��
	 * \fn	DeltaTable()
	 *
	 * \brief	���캯��
	 *
	 */
	DeltaTable()
	{
		memset(effectTable, 0, sizeof(int)*row*col);
	}

	/*��
	 * \fn	~DeltaTable()
	 *
	 * \brief	��������
	 *
	 */
	~DeltaTable()
	{

	}
};

/*��
 * \struct	DeltaRound
 *
 * \brief	�غϽṹ�壬��¼ÿ���غ��ڸ��׶ε�Ч����ʷ�±�����
 *
 */
struct DeltaRound
{
	/* \brief	��Ч������ֵ */
	static const int invalIndex = -1;

	/* \brief	ս��ǰ���±����� */
	int before = invalIndex;

	/* \brief	ս��ʱ���±����� */
	int in = invalIndex;

	/* \brief	ս������±����� */
	int after = invalIndex;

	/* \brief	 ÿ�غ��ܱ���±����� */
	int total = invalIndex;

	/* \brief	�غ��� */
	int roundNumber = EffectAffixes::invalidEffectRoundValue;
};



#endif