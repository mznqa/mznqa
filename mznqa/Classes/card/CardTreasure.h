/*!
 * \file	Classes\card\CardTreasure.h
 *
 * \brief	������ CardTreasure
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARD_CARDTREASURE_H_
#define MZNQA_CLASSES_CARD_CARDTREASURE_H_

#include "card/CardBase.h"

/*!
 * \class	CardTreasure
 *
 * \brief	���￨
 *
 */
class CardTreasure : public CardBase
{
private:

public:
	/*! \brief	������ */
	static const CardBase::CardType CARDTYPE = CardBase::CardType_Treasure;

	/*!
	 * \fn	CardTreasure::CardTreasure( int id, const std::string &name, const std::string &describe, CardBase::BelongTo belongTo )
	 *
	 * \brief	���캯��
	 *
	 * \param	id			ָ�����￨�� id
	 * \param	name		ָ�����￨������
	 * \param	describe	ָ�����￨������
	 * \param	belongTo	ָ�����￨������
	 */
	CardTreasure(
		int id,
		const std::string &name,
		const std::string &describe,
		CardBase::BelongTo belongTo
		) :
		CardBase(
		id,
		CARDTYPE,
		name,
		describe,
		belongTo
		)
	{}

	/*!
	 * \fn	CardTreasure::~CardTreasure()
	 *
	 * \brief	��������
	 *
	 */
	~CardTreasure()
	{}
};

#endif
