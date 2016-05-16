/*!
 * \file	Classes\logic\gameObject\card\CardMonster.h
 *
 * \brief	������ CardMonster
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARD_CARDMONSTER_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARD_CARDMONSTER_H_

#include "logic/gameobject/card/CardBase.h"

/*!
 * \class	CardMonster
 *
 * \brief	���￨
 *
 */
class CardMonster : public CardBase
{
private:
public:
	/*! \brief	�������� */
	static const CardBase::CardType cardType;

	/*!
	 * \fn	CardMonster::CardMonster( int id, int sidName, int sidDescribe, CardBase::BelongTo belongTo )
	 *
	 * \brief	���캯��
	 *
	 * \param	id		   	ָ�����￨ID
	 * \param	sidName	   	ָ�����￨����SID
	 * \param	sidDescribe	ָ�����￨����SID
	 * \param	belongTo   	ָ�����￨������
	 */
	CardMonster(
		int id,
		int sidName,
		int sidDescribe,
		CardBase::BelongTo belongTo
		) :
		CardBase(id, sidName, sidDescribe, belongTo)
	{
	}

	/*!
	 * \fn	CardMonster::CardMonster(const CardMonster &cardMonster)
	 *
	 * \brief	�������캯��
	 *
	 */
	CardMonster(const CardMonster &cardMonster) :
		CardBase(cardMonster)
	{
	}

	/*!
	 * \fn	CardMonster& CardMonster::operator=(const CardMonster &cardMonster)
	 *
	 * \brief	������ֵ�����
	 *
	 */
	CardMonster& operator=(const CardMonster &cardMonster)
	{
		CardBase::operator=(cardMonster);
	}

	/*!
	 * \fn	CardBase::CardType CardMonster::getCardType()const
	 *
	 * \brief	��ȡ��������
	 *
	 */
	CardBase::CardType getCardType()const
	{
		return cardType;
	}
};

#endif
