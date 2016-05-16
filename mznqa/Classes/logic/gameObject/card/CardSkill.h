/*!
 * \file	Classes\logic\gameObject\card\CardSkill.h
 *
 * \brief	定义类 CardSkill
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARD_CARDSKILL_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARD_CARDSKILL_H_

#include <vector>

#include "logic/gameObject/card/CardBase.h"
#include "logic/gameObject/effect/Effect.h"

/*!
 * \class	CardSkill
 *
 * \brief	技能卡
 *
 */
class CardSkill : public CardBase
{
private:
	/*! \brief	卡牌类型 */
	static const CardBase::CardType cardType;

	/*! \brief	效果集合 */
	std::vector<Effect> effectSet;
public:

	/*!
	 * \fn	CardSkill::CardSkill( int id, int sidName, int sidDescribe, CardBase::BelongTo belongTo, const std::vector<Effect> &effectSet )
	 *
	 * \brief	构造函数
	 *
	 * \param	id		   	指定技能卡ID
	 * \param	sidName	   	指定技能卡名称SID
	 * \param	sidDescribe	指定技能卡描述SID
	 * \param	belongTo   	指定技能卡所属
	 * \param	effectSet  	指定效果集合
	 */
	CardSkill(
		int id,
		int sidName,
		int sidDescribe,
		CardBase::BelongTo belongTo,
		const std::vector<Effect> &effectSet
		) :
		CardBase(id, sidName, sidDescribe, belongTo),
		effectSet(effectSet)
	{
	}

	/*!
	 * \fn	CardSkill::CardSkill(const CardSkill &cardSkill)
	 *
	 * \brief	拷贝构造函数
	 *
	 */
	CardSkill(const CardSkill &cardSkill) :
		CardBase(
		cardSkill.getID(),
		cardSkill.getSIDName(),
		cardSkill.getSIDDescribe(),
		cardSkill.getBelongTo()
		),
		effectSet(cardSkill.getEffectSet())
	{
	}

	/*!
	 * \fn	CardSkill& CardSkill::operator=(const CardSkill &cardSkill)
	 *
	 * \brief	拷贝赋值运算符
	 *
	 */
	CardSkill& operator=(const CardSkill &cardSkill)
	{
		CardBase::operator=(cardSkill);
		this->effectSet = effectSet;
		return *this;
	}

	/*!
	 * \fn	CardBase::CardType CardSkill::getCardType()const
	 *
	 * \brief	获取卡牌类型
	 *
	 */
	CardBase::CardType getCardType()const
	{
		return cardType;
	}

	/*!
	 * \fn	const std::vector<Effect>& CardSkill::getEffectSet()const
	 *
	 * \brief	获取效果集合
	 *
	 */
	const std::vector<Effect>& getEffectSet()const
	{
		return effectSet;
	}
};

#endif
