/*!
* \file	Classes\logic\gameObject\card\CardTreasure.h
*
* \brief	������ CardTreasure
*/

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARD_CARDTREASURE_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARD_CARDTREASURE_H_

#include "logic/gameobject/card/CardBase.h"

/*!
* \class	CardTreasure
*
* \brief	���￨
*
*/
class CardTreasure : public CardBase
{
private:
	/*! \brief	�������� */
	static const CardBase::CardType cardType;
public:

	/*!
	* \fn	CardTreasure::CardTreasure( int id, int sidName, int sidDescribe, CardBase::BelongTo belongTo )
	*
	* \brief	���캯��
	*
	* \param	id		   	ָ�����￨ID
	* \param	sidName	   	ָ�����￨����SID
	* \param	sidDescribe	ָ�����￨����SID
	* \param	belongTo   	ָ�����￨������
	*/
	CardTreasure(
		int id,
		int sidName,
		int sidDescribe,
		CardBase::BelongTo belongTo
		) :
		CardBase(id, sidName, sidDescribe, belongTo)
	{
	}

	/*!
	* \fn	CardTreasure::CardTreasure(const CardTreasure &cardTreasure)
	*
	* \brief	�������캯��
	*
	*/
	CardTreasure(const CardTreasure &cardTreasure) :
		CardBase(cardTreasure)
	{
	}

	/*!
	* \fn	CardTreasure& CardTreasure::operator=(const CardTreasure &cardTreasure)
	*
	* \brief	������ֵ�����
	*
	*/
	CardTreasure& operator=(const CardTreasure &cardTreasure)
	{
		CardBase::operator=(cardTreasure);
	}

	/*!
	* \fn	CardBase::CardType CardTreasure::getCardType()const
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
