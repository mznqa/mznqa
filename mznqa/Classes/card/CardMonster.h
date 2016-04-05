/*!
 * \file	Classes\card\CardMonster.h
 *
 * \brief	������ CardMonster
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARD_CARDMONSTER_H_
#define MZNQA_CLASSES_CARD_CARDMONSTER_H_

#include "card/CardBase.h"

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
	/*! \brief	������ */
	static const CardBase::CardType CARDTYPE = CardBase::CardType_Monster;

	/*!
	 * \fn	CardMonster::CardMonster( int id, const std::string &name, const std::string &describe, CardBase::BelongTo belongTo )
	 *
	 * \brief	Ĭ�Ϲ��캯��
	 *
	 * \param	id			����id
	 * \param	name		��������
	 * \param	describe	��������
	 * \param	belongTo	��������
	 */
	CardMonster(
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
	 * \fn	CardMonster::~CardMonster()
	 *
	 * \brief	��������
	 *
	 */
	~CardMonster()
	{}
};

#endif
