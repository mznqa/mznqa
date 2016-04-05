/*!
 * \file	Classes\card\CardMonster.h
 *
 * \brief	定义类 CardMonster
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARD_CARDMONSTER_H_
#define MZNQA_CLASSES_CARD_CARDMONSTER_H_

#include "card/CardBase.h"

/*!
 * \class	CardMonster
 *
 * \brief	怪物卡
 *
 */
class CardMonster : public CardBase
{
private:

public:
	/*! \brief	卡类型 */
	static const CardBase::CardType CARDTYPE = CardBase::CardType_Monster;

	/*!
	 * \fn	CardMonster::CardMonster( int id, const std::string &name, const std::string &describe, CardBase::BelongTo belongTo )
	 *
	 * \brief	默认构造函数
	 *
	 * \param	id			卡牌id
	 * \param	name		卡牌名称
	 * \param	describe	卡牌描述
	 * \param	belongTo	卡牌所属
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
	 * \brief	析构函数
	 *
	 */
	~CardMonster()
	{}
};

#endif
