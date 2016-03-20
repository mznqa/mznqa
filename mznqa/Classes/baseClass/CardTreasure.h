#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_BASECLASS_CARDTREASURE_H_
#define MZNQA_CLASSES_BASECLASS_CARDTREASURE_H_

#include "baseClass/Card.h"

class CardTreasure : public Card
{
public:
	CardTreasure(int id) :
		Card(id, Card::CardType_Treasure)
	{
	}
	CardTreasure(Card card) :
		Card(card.getID(), Card::CardType_Treasure)
	{
	}
	~CardTreasure(){}
};

#endif
