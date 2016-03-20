#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_BASECLASS_CARDROAD_H_
#define MZNQA_CLASSES_BASECLASS_CARDROAD_H_

#include "baseClass/Card.h"

class CardRoad : public Card
{
public:
	CardRoad(int id) :
		Card(id, Card::CardType_Road)
	{
	}
	CardRoad(Card card) :
		Card(card.getID(), Card::CardType_Road)
	{
	}
	~CardRoad(){}
};

#endif
