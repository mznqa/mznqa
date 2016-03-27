#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARD_CARDSKILL_H_
#define MZNQA_CLASSES_CARD_CARDSKILL_H_

#include "card/CardBase.h"

#include <string>

class CardSkill : public CardBase
{
public:
	CardSkill(
		int id,
		const std::string &name,
		const std::string &describe,
		BelongTo belongTo,
		int effectCount
		) :
		CardBase(
		id,
		CardBase::CardType_Skill,
		name,
		describe,
		belongTo
		),
		effectCount(effectCount)
	{
		if (!(0 <= this->belongTo && this->belongTo <= 2))
			cocos2d::log("[warning] 为技能卡%d设置所属方失败，提供的值为：%d", id, this->belongTo);
		if (this->effectCount < 0)
			cocos2d::log("[warning] 为技能卡%d设置包含技能数失败，提供的值为：%d", id, this->effectCount);
	}

	~CardSkill()
	{}

	// 获取包含的技能数
	int getEffectCount() const
	{
		return effectCount;
	}

private:
	// 卡牌包含技能数
	const int effectCount;
};

#endif
