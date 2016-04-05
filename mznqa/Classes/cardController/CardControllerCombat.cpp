/*!
 * \file	D:\Projects\mznqa\mznqa\Classes\cardController\CardControllerCombat.cpp
 *
 * \brief	定义类 CardControllerCombat
 */

#pragma execution_character_set("utf-8")

#include "cardController/CardControllerCombat.h"

int CardControllerCombat::drawACard()
{
	cocos2d::log("[information] 正在从战斗场景的卡池中抽取一张卡...");

	// 如果卡池为空
	if (cardPool->getCardCount() <= 0)
	{
		cocos2d::log("[warning] 从战斗场景的卡池中抽取卡失败，当前卡池为空");
		return CardBase::invalidID;
	}
	// 如果手牌已满
	if (handCard->isFull())
	{
		cocos2d::log("[warning] 从战斗场景的卡池中抽取卡失败，当前手牌已满");
		return CardBase::invalidID;
	}

	// 从卡池中随机移除一张卡
	int id = cardPool->removeCardByRandom();

	// 向手牌中添加这张卡
	if (id != CardBase::invalidID)
		handCard->addCardByID(id);

	cocos2d::log("[information] 成功从战斗场景的卡池中抽取一张id为%d的卡", id);

	return id;
}

void CardControllerCombat::shuffle()
{
	auto it = recycleCard->getCardSet().cbegin();
	auto itEnd = recycleCard->getCardSet().cend();
	while (it != itEnd)
	{
		cardPool->addCardByID(*it);
		++it;
	}

	recycleCard->clear();
	cocos2d::log("[information] 成功完成战斗场景的洗牌");
}