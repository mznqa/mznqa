/*!
* \file	Classes\logic\gameObject\card\CardTreasure.h
*
* \brief	定义类 CardTreasure
*/

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARD_CARDTREASURE_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARD_CARDTREASURE_H_

#include "logic/gameobject/card/CardBase.h"

/*!
* \class	CardTreasure
*
* \brief	宝物卡
*
*/
class CardTreasure : public CardBase
{
private:
	/*! \brief	卡牌类型 */
	static const CardBase::CardType cardType;
public:

	/*!
	* \fn	CardTreasure::CardTreasure( int id, int sidName, int sidDescribe, CardBase::BelongTo belongTo )
	*
	* \brief	构造函数
	*
	* \param	id		   	指定宝物卡ID
	* \param	sidName	   	指定宝物卡名称SID
	* \param	sidDescribe	指定宝物卡描述SID
	* \param	belongTo   	指定宝物卡所属方
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
	* \brief	拷贝构造函数
	*
	*/
	CardTreasure(const CardTreasure &cardTreasure) :
		CardBase(cardTreasure)
	{
	}

	/*!
	* \fn	CardTreasure& CardTreasure::operator=(const CardTreasure &cardTreasure)
	*
	* \brief	拷贝赋值运算符
	*
	*/
	CardTreasure& operator=(const CardTreasure &cardTreasure)
	{
		CardBase::operator=(cardTreasure);
	}

	/*!
	* \fn	CardBase::CardType CardTreasure::getCardType()const
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
