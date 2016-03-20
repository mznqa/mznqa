#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_BASECLASS_HANDCARD_H_
#define MZNQA_CLASSES_BASECLASS_HANDCARD_H_

#include <list>

#include "baseClass/Card.h"

class HandCard
{
protected:
	int handCardCount;

	std::list<Card> handCardSet;

	bool checkIndex(int index);

public:
	HandCard(int handCardCount);
	~HandCard();

	// 向手牌中添加一张卡
	void AddACard(const Card &card);
	// 根据索引返回指定手牌
	Card getCardByIndex(int index);
	// 根据索引删除指定手牌
	Card removeCardByIndex(int index);
	// 获取当前手牌中卡牌个数
	int getCardCount();
	// 清空手牌
	void clear();

	// 获取手牌的大小
	int getSize();

	void test();
};

#endif
