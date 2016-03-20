#pragma execution_character_set("utf-8")

#include <iterator>

#include "cocos2d.h"

#include "baseClass/HandCard.h"

HandCard::HandCard(int handCardCount)
{
	this->handCardCount = handCardCount;
}

HandCard::~HandCard()
{
}

bool HandCard::checkIndex(int index)
{
	return (0 <= index && index < handCardCount);
}

void HandCard::AddACard(const Card &card)
{
	if (handCardSet.size() >= handCardCount)
	{
		cocos2d::log("警告：尝试添加一张卡（id=%d, type=%d）到手牌失败, 当前手牌数%d", card.getID(), card.getCardType(), handCardSet.size());
		return;
	}
	if (card.getID() < 0)
	{
		cocos2d::log("警告：尝试添加一张卡（id=%d, type=%d）到手牌失败, 当前手牌数%d", card.getID(), card.getCardType(), handCardSet.size());
		return;
	}

	handCardSet.push_back(card);
	cocos2d::log("提示：已添加一张卡（id=%d, type=%d）到手牌", card.getID(), card.getCardType());
}

Card HandCard::getCardByIndex(int index)
{
	if (checkIndex(index) == false)
	{
		cocos2d::log("警告：尝试获取索引为%d的手牌失败, 当前手牌数%d", index, handCardSet.size());
		return Card(-1, Card::CardType_None);
	}

	auto it = handCardSet.begin();
	advance(it, index);
	return *it;

	cocos2d::log("提示：已获取索引为%d的手牌（id=%d, type=%d）", index, it->getID(), it->getCardType());
}

Card HandCard::removeCardByIndex(int index)
{
	if (checkIndex(index) == false)
	{
		cocos2d::log("警告：尝试删除索引为%d的手牌失败, 当前手牌数%d", index, handCardSet.size());
		return Card(-1, Card::CardType_None);
	}

	auto it = handCardSet.begin();
	advance(it, index);
	Card card(*it);
	handCardSet.erase(it);

	cocos2d::log("提示：已删除索引为%d的手牌（id=%d, type=%d）", index, card.getID(), card.getCardType());

	return card;
}

void HandCard::clear()
{
	handCardSet.clear();
	cocos2d::log("提示：已清除手牌");
}

int HandCard::getCardCount()
{
	return handCardSet.size();
}

int HandCard::getSize()
{
	return handCardCount;
}

void HandCard::test()
{
}