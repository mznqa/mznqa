#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARD_CARDBASE_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARD_CARDBASE_H_

class CardBase
{
private:
	CardBase(const CardBase &cardBase);
	CardBase& operator=(const CardBase &cardBase);
public:
	CardBase();
	virtual ~CardBase();
};

#endif