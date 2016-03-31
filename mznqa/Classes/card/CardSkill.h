#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARD_CARDSKILL_H_
#define MZNQA_CLASSES_CARD_CARDSKILL_H_

#include <string>
#include <vector>

#include "card/CardBase.h"
#include "effect/Effect.h"

// 技能卡
class CardSkill : public CardBase
{
public:
	// 卡类型
	static CardBase::CardType CARDTYPE;

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

	~CardSkill()
	{}

	// 获取包含的技能数
	int getEffectCount() const
	{
		return effectSet.size();
	}

	// 获取效果集合
	const std::vector<Effect>& getEffectSet()const
	{
		return effectSet;
	}

private:
	// 这些作为静态数据，不应修改它们 //////////////////////////////////////////////////////////////////////////
	// 效果集合
	std::vector<Effect> effectSet;
	//////////////////////////////////////////////////////////////////////////
};

#endif
