/*!
 * \file	Classes\card\CardSkill.h
 *
 * \brief	������ CardSkill
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARD_CARDSKILL_H_
#define MZNQA_CLASSES_CARD_CARDSKILL_H_

#include <string>
#include <vector>

#include "card/CardBase.h"
#include "effect/Effect.h"

/*!
 * \class	CardSkill
 *
 * \brief	���ܿ�
 *
 */
class CardSkill : public CardBase
{
public:
	/*! \brief	������ */
	static const CardBase::CardType CARDTYPE = CardBase::CardType_Skill;

	/*!
	 * \fn	CardSkill::CardSkill( int id, const std::string &name, const std::string &describe, BelongTo belongTo, const std::vector<Effect> &effectSet )
	 *
	 * \brief	���캯��
	 *
	 * \param	id		 	ָ�����ܿ� id
	 * \param	name	 	ָ�����ܿ�����
	 * \param	describe 	ָ�����ܿ�����
	 * \param	belongTo 	ָ�����ܿ�������
	 * \param	effectSet	ִ��Ч������
	 */
	CardSkill(
		int id,
		const std::string &name,
		const std::string &describe,
		BelongTo belongTo,
		const std::vector<Effect> &effectSet
		) :
		CardBase(
		id,
		CARDTYPE,
		name,
		describe,
		belongTo
		),
		effectSet(effectSet)
	{
		if (!(0 <= this->belongTo && this->belongTo <= 2))
			cocos2d::log("[warning] Ϊ���ܿ�%d����������ʧ�ܣ��ṩ��ֵΪ��%d", id, this->belongTo);
		if (this->effectSet.size() < 0)
			cocos2d::log("[warning] Ϊ���ܿ�%d���ð���������ʧ�ܣ��ṩ��ֵΪ��%d", id, this->effectSet.size());
	}

	/*!
	 * \fn	CardSkill::~CardSkill()
	 *
	 * \brief	��������
	 *
	 */
	~CardSkill()
	{}

	/*!
	 * \fn	int CardSkill::getEffectCount() const
	 *
	 * \brief	��ȡ���ܿ��а�����Ч����
	 *
	 * \return	���ؼ��ܿ��а�����Ч����
	 */
	int getEffectCount() const
	{
		return effectSet.size();
	}

	/*!
	 * \fn	const std::vector<Effect>& CardSkill::getEffectSet()const
	 *
	 * \brief	��ȡ���ܿ��е�Ч������
	 *
	 * \return	���ؼ��ܿ��е�Ч������
	 */
	const std::vector<Effect>& getEffectSet()const
	{
		return effectSet;
	}

private:
	/*! \brief	Ч������ */
	std::vector<Effect> effectSet;
};

#endif
