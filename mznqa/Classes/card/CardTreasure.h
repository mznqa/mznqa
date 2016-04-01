#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARD_CARDTREASURE_H_
#define MZNQA_CLASSES_CARD_CARDTREASURE_H_

#include "card/CardBase.h"

// ±¶ŒÔø®
class CardTreasure : public CardBase
{
private:

public:
	// ø®¿‡–Õ
	static CardBase::CardType CARDTYPE;

	CardTreasure(int id) :
		CardBase(id, CARDTYPE, "", "", CardBase::BelongTo_RoleMonsterBoth)
	{}

	~CardTreasure()
	{}
};

#endif
