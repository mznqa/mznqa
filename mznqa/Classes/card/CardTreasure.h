/*!
 * \file	Classes\card\CardTreasure.h
 *
 * \brief	定义类 CardTreasure
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARD_CARDTREASURE_H_
#define MZNQA_CLASSES_CARD_CARDTREASURE_H_

#include "card/CardBase.h"

/*!
 * \class	CardTreasure
 *
 * \brief	宝物卡
 *
 */
class CardTreasure : public CardBase
{
private:

public:
	/*! \brief	卡类型 */
	static const CardBase::CardType CARDTYPE = CardBase::CardType_Treasure;

	/*!
	 * \fn	CardTreasure::CardTreasure( int id, const std::string &name, const std::string &describe, CardBase::BelongTo belongTo )
	 *
	 * \brief	构造函数
	 *
	 * \param	id			指定宝物卡的 id
	 * \param	name		指定宝物卡的名称
	 * \param	describe	指定宝物卡的描述
	 * \param	belongTo	指定宝物卡的所属
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
	 * \brief	析构函数
	 *
	 */
	~CardTreasure()
	{}
};

#endif
