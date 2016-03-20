#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_BASECLASS_CARD_H_
#define MZNQA_CLASSES_BASECLASS_CARD_H_

class Card
{
public:
	enum CardType
	{
		CardType_None,
		CardType_Road,
		CardType_Treasure,
		CardType_Monster,
		CardType_Skill
	};
	Card(int id, CardType cardType)
	{
		this->id = id;
		this->cardType = cardType;
	}
	Card(const Card&card)
	{
		this->id = card.getID();
		this->cardType = card.getCardType();
	}
	~Card(){}
	// ��ȡid
	int getID() const
	{
		return id;
	}
	// ��ȡ��������
	CardType getCardType() const
	{
		return cardType;
	}

protected:
	// ����ID
	int id;

	// ��������
	CardType cardType;
};

#endif
