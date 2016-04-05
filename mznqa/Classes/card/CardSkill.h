/*!
 * \file	Classes\card\CardSkill.h
 *
 * \brief	定义类 CardSkill
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
 * \brief	技能卡
 *
 */
class CardSkill : public CardBase
{
public:
	/*! \brief	卡类型 */
	static const CardBase::CardType CARDTYPE = CardBase::CardType_Skill;

	/*!
	 * \fn	CardSkill::CardSkill( int id, const std::string &name, const std::string &describe, BelongTo belongTo, const std::vector<Effect> &effectSet )
	 *
	 * \brief	构造函数
	 *
	 * \param	id		 	指定技能卡 id
	 * \param	name	 	指定技能卡名称
	 * \param	describe 	指定技能卡描述
	 * \param	belongTo 	指定技能卡所属方
	 * \param	effectSet	执行效果集合
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
			cocos2d::log("[warning] 为技能卡%d设置所属方失败，提供的值为：%d", id, this->belongTo);
		if (this->effectSet.size() < 0)
			cocos2d::log("[warning] 为技能卡%d设置包含技能数失败，提供的值为：%d", id, this->effectSet.size());
	}

	/*!
	 * \fn	CardSkill::~CardSkill()
	 *
	 * \brief	析构函数
	 *
	 */
	~CardSkill()
	{}

	/*!
	 * \fn	int CardSkill::getEffectCount() const
	 *
	 * \brief	获取技能卡中包含的效果数
	 *
	 * \return	返回技能卡中包含的效果数
	 */
	int getEffectCount() const
	{
		return effectSet.size();
	}

	/*!
	 * \fn	const std::vector<Effect>& CardSkill::getEffectSet()const
	 *
	 * \brief	获取技能卡中的效果集合
	 *
	 * \return	返回技能卡中的效果集合
	 */
	const std::vector<Effect>& getEffectSet()const
	{
		return effectSet;
	}

private:
	/*! \brief	效果集合 */
	std::vector<Effect> effectSet;
};

#endif
