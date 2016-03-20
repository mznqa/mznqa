#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_BASECLASS_CARD_H_
#define MZNQA_CLASSES_BASECLASS_CARD_H_

class Card
{
public:
	enum CardType
	{
		CardType_None = 0,
		CardType_Road = 1,
		CardType_Treasure = 2,
		CardType_Monster = 3,
		CardType_Skill = 4
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
