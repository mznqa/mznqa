/*!
 * \file	Classes\logic\gameObject\card\CardMonster.h
 *
 * \brief	定义类 CardMonster
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARD_CARDMONSTER_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARD_CARDMONSTER_H_

#include "logic/gameobject/card/CardBase.h"

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
	/*! \brief	卡牌类型 */
	static const CardBase::CardType cardType;

	/*!
	 * \fn	CardMonster::CardMonster( int id, int sidName, int sidDescribe, CardBase::BelongTo belongTo )
	 *
	 * \brief	构造函数
	 *
	 * \param	id		   	指定怪物卡ID
	 * \param	sidName	   	指定怪物卡名称SID
	 * \param	sidDescribe	指定怪物卡描述SID
	 * \param	belongTo   	指定怪物卡所属方
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
	 * \brief	拷贝构造函数
	 *
	 */
	CardMonster(const CardMonster &cardMonster) :
		CardBase(cardMonster)
	{
	}

	/*!
	 * \fn	CardMonster& CardMonster::operator=(const CardMonster &cardMonster)
	 *
	 * \brief	拷贝赋值运算符
	 *
	 */
	CardMonster& operator=(const CardMonster &cardMonster)
	{
		CardBase::operator=(cardMonster);
	}

	/*!
	 * \fn	CardBase::CardType CardMonster::getCardType()const
	 *
	 * \brief	获取卡牌类型
	 *
	 */
	CardBase::CardType getCardType()const
	{
		return cardType;
	}
};

#endif
