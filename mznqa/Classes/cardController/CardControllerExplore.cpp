/*!
 * \file	Classes\cardController\CardControllerExplore.cpp
 *
 * \brief	定义类 CardControllerExplore
 */

#pragma execution_character_set("utf-8")

#include "cardController/CardControllerExplore.h"

CardControllerExplore* CardControllerExplore::Instance()
{
	static CardControllerExplore instance;
	return &instance;
}

int CardControllerExplore::drawACard()
{
	cocos2d::log("[information] 正在从探索场景的卡池中抽取一张卡...");

	if (cardPool->getCardCount() <= 0)
	{
		cocos2d::log("[warning] 从探索场景的卡池中抽取卡失败，当前卡池为空");
		return CardBase::invalidID;
	}
	if (handCard->isFull())
	{
		cocos2d::log("[warning] 从探索场景的卡池中抽取卡失败，当前手牌已满");
		return CardBase::invalidID;
	}

	// 从卡池中移除一张卡
	int id = cardPool->removeCardByRandom();

	// 向手牌中添加该卡
	handCard->addCardByID(id);

	cocos2d::log("[information] 成功从探索场景的卡池中抽取一张id为%d的卡", id);
	return id;
}

void CardControllerExplore::shuffle()
{
	auto it = recycleCard->getCardSet().cbegin();
	auto itEnd = recycleCard->getCardSet().cend();
	while (it != itEnd)
	{
		cardPool->addCardByID(it->second);
		++it;
	}

	recycleCard->clear();
	cocos2d::log("[information] 成功完成探索场景的洗牌");
}