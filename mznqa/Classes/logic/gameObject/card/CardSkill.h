/*!
 * \file	Classes\logic\gameObject\card\CardSkill.h
 *
 * \brief	������ CardSkill
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
 * \brief	���ܿ�
 *
 */
class CardSkill : public CardBase
{
private:
	/*! \brief	�������� */
	static const CardBase::CardType cardType;

	/*! \brief	Ч������ */
	std::vector<Effect> effectSet;
public:

	/*!
	 * \fn	CardSkill::CardSkill( int id, int sidName, int sidDescribe, CardBase::BelongTo belongTo, const std::vector<Effect> &effectSet )
	 *
	 * \brief	���캯��
	 *
	 * \param	id		   	ָ�����ܿ�ID
	 * \param	sidName	   	ָ�����ܿ�����SID
	 * \param	sidDescribe	ָ�����ܿ�����SID
	 * \param	belongTo   	ָ�����ܿ�����
	 * \param	effectSet  	ָ��Ч������
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
	 * \brief	�������캯��
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
	 * \brief	������ֵ�����
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
	 * \brief	��ȡ��������
	 *
	 */
	CardBase::CardType getCardType()const
	{
		return cardType;
	}

	/*!
	 * \fn	const std::vector<Effect>& CardSkill::getEffectSet()const
	 *
	 * \brief	��ȡЧ������
	 *
	 */
	const std::vector<Effect>& getEffectSet()const
	{
		return effectSet;
	}
};

#endif
