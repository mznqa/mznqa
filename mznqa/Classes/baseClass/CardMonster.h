#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_BASECLASS_CARDMONSTER_H_
#define MZNQA_CLASSES_BASECLASS_CARDMONSTER_H_

#include "baseClass/Card.h"

class CardMonster : public Card
{
public:
	CardMonster(int id) :
		Card(id, Card::CardType_Monster)
	{
	}
	CardMonster(Card card) :
		Card(card.getID(), Card::CardType_Monster)
	{
	}
	~CardMonster(){}
};

#endif
