#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARD_CARDSKILL_H_
#define MZNQA_CLASSES_CARD_CARDSKILL_H_

#include <string>
#include <vector>

#include "card/CardBase.h"
#include "effect/Effect.h"

// ���ܿ�
class CardSkill : public CardBase
{
public:
	// ������
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
			cocos2d::log("[warning] Ϊ���ܿ�%d����������ʧ�ܣ��ṩ��ֵΪ��%d", id, this->belongTo);
		if (this->effectSet.size() < 0)
			cocos2d::log("[warning] Ϊ���ܿ�%d���ð���������ʧ�ܣ��ṩ��ֵΪ��%d", id, this->effectSet.size());
	}

	~CardSkill()
	{}

	// ��ȡ�����ļ�����
	int getEffectCount() const
	{
		return effectSet.size();
	}

	// ��ȡЧ������
	const std::vector<Effect>& getEffectSet()const
	{
		return effectSet;
	}

private:
	// ��Щ��Ϊ��̬���ݣ���Ӧ�޸����� //////////////////////////////////////////////////////////////////////////
	// Ч������
	std::vector<Effect> effectSet;
	//////////////////////////////////////////////////////////////////////////
};

#endif
