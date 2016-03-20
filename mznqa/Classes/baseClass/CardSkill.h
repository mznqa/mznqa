#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_BASECLASS_CARDSKILL_H_
#define MZNQA_CLASSES_BASECLASS_CARDSKILL_H_

#include "baseClass/Card.h"

class CardSkill : public Card
{
public:
	CardSkill(int id) :
		Card(id, Card::CardType_Skill)
	{
	}
	CardSkill(Card card) :
		Card(card.getID(), Card::CardType_Skill)
	{
	}
	~CardSkill(){}
};

#endif
