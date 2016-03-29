#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARD_CARDTREASURE_H_
#define MZNQA_CLASSES_CARD_CARDTREASURE_H_

#include "card/CardBase.h"

// ±¦Îï¿¨
class CardTreasure : public CardBase
{
private:

public:
	CardTreasure(int id) :
		CardBase(id, CardBase::CardType_Treasure)
	{}

	~CardTreasure()
	{}
};

#endif
