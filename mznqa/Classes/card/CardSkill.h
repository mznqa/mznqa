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
			cocos2d::log("[warning] Ϊ���ܿ�%d����������ʧ�ܣ��ṩ��ֵΪ��%d", id, this->belongTo);
		if (this->effectCount < 0)
			cocos2d::log("[warning] Ϊ���ܿ�%d���ð���������ʧ�ܣ��ṩ��ֵΪ��%d", id, this->effectCount);
	}

	~CardSkill()
	{}

	// ��ȡ�����ļ�����
	int getEffectCount() const
	{
		return effectCount;
	}

private:
	// ���ư���������
	const int effectCount;
};

#endif
