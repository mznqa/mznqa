#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARD_CARDMONSTER_H_
#define MZNQA_CLASSES_CARD_CARDMONSTER_H_

#include "card/CardBase.h"

// ������
class CardMonster : public CardBase
{
private:
	// ������
	static CardBase::CardType CARDTYPE;

public:
	CardMonster(int id) :
		CardBase(id, CARDTYPE)
	{}

	~CardMonster()
	{}
};

#endif
