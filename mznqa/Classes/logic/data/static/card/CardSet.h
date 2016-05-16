/*!
 * \file	Classes\logic\data\static\card\CardSet.h
 *
 * \brief	������ CardSet
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_DATA_STATIC_CARD_CARDSET_H_
#define MZNQA_CLASSES_LOGIC_DATA_STATIC_CARD_CARDSET_H_

#include <map>
#include <vector>

#include "logic/gameObject/card/CardRoad.h"
#include "logic/gameObject/card/CardSkill.h"
#include "logic/gameObject/card/CardMonster.h"
#include "logic/gameObject/card/CardTreasure.h"

/*!
 * \class	CardSet
 *
 * \brief	[����]������п���
 *
 */
class CardSet
{
private:

	/*!
	 * \fn	CardSet::CardSet()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	CardSet()
	{
	}

	/*!
	 * \fn	CardSet::CardSet(const CardSet &cardSet);
	 *
	 * \brief	���صĿ������캯��
	 *
	 */
	CardSet(const CardSet &cardSet);

	/*!
	 * \fn	CardSet& CardSet::operator=(const CardSet &cardSet);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	CardSet& operator=(const CardSet &cardSet);

	/*! \brief	���ο����� */
	std::map<int, CardRoad> cardRoadSet;
	/*! \brief	���ܿ����� */
	std::map<int, CardSkill> cardSkillSet;
	/*! \brief	���￨���� */
	std::map<int, CardMonster> cardMonsterSet;
	/*! \brief	���￨���� */
	std::map<int, CardTreasure> cardTreasureSet;
public:

	/*!
	 * \fn	CardSet::~CardSet()
	 *
	 * \brief	��������
	 *
	 */
	~CardSet()
	{
	}

	/*!
	 * \fn	static CardSet* CardSet::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 */
	static CardSet* Instance();

	/*!
	 * \fn	void CardSet::loadCardRoadSet(std::map<int, CardRoad> &cardRoadSet);
	 *
	 * \brief	������ο���������
	 *
	 * \param [in,out]	cardRoadSet	ָ�����ο��������ݻ���
	 */
	void loadCardRoadSet(std::map<int, CardRoad> &cardRoadSet);

	/*!
	 * \fn	void CardSet::loadCardSkillSet(std::map<int, CardSkill> &cardSkillSet);
	 *
	 * \brief	���뼼�ܿ���������
	 *
	 * \param [in,out]	cardSkillSet	ָ�����ܿ��������ݻ���
	 */
	void loadCardSkillSet(std::map<int, CardSkill> &cardSkillSet);

	/*!
	 * \fn	void CardSet::loadCardMonsterSet(std::map<int, CardMonster> &cardMonsterSet);
	 *
	 * \brief	������￨��������
	 *
	 * \param [in,out]	cardMonsterSet	ָ�����￨�������ݻ���
	 */
	void loadCardMonsterSet(std::map<int, CardMonster> &cardMonsterSet);

	/*!
	 * \fn	void CardSet::loadCardTreasureSet(std::map<int, CardTreasure> &cardTreasureSet);
	 *
	 * \brief	���뱦�￨��������
	 *
	 * \param [in,out]	cardTreasureSet	ָ�����￨�������ݻ���
	 */
	void loadCardTreasureSet(std::map<int, CardTreasure> &cardTreasureSet);

	/*!
	 * \fn	bool CardSet::isCardType(CardBase::CardType cardType, int id)const;
	 *
	 * \brief	�ж�ָ������ID�Ƿ�Ϊ�����Ŀ�������
	 *
	 * \param	cardType	ָ����������
	 * \param	id			ָ������ID
	 *
	 */
	bool isCardType(CardBase::CardType cardType, int id)const;

	/*!
	 * \fn	const CardRoad *const CardSet::getCardRoadByID(int id)const;
	 *
	 * \brief	���ݸ���ID�Ի�ȡ���ο�
	 *
	 * \param	id	ָ�����ο�ID
	 *
	 */
	const CardRoad *const getCardRoadByID(int id)const;

	/*!
	 * \fn	const CardSkill *const CardSet::getCardSkillByID(int id)const;
	 *
	 * \brief	���ݸ���ID�Ի�ȡ���ܿ�
	 *
	 * \param	id	ָ�����ܿ�ID
	 *
	 */
	const CardSkill *const getCardSkillByID(int id)const;

	/*!
	 * \fn	const CardMonster *const CardSet::getCardMonsterByID(int id)const;
	 *
	 * \brief	���ݸ���ID�Ի�ȡ���￨
	 *
	 * \param	id	ָ�����￨ID
	 *
	 */
	const CardMonster *const getCardMonsterByID(int id)const;

	/*!
	 * \fn	const CardTreasure *const CardSet::getCardTreasureByID(int id)const;
	 *
	 * \brief	���ݸ���ID�Ի�ȡ���￨
	 *
	 * \param	id	ָ�����￨ID
	 *
	 */
	const CardTreasure *const getCardTreasureByID(int id)const;
};

#endif
