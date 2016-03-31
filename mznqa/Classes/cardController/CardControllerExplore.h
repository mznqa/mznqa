#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARDCONTROLLER_CARDCONTROLLEREXPLORE_H_
#define MZNQA_CLASSES_CARDCONTROLLER_CARDCONTROLLEREXPLORE_H_

#include <list>

#include "cardController/CardBoxRTM.h"

class CardControllerExplore
{
private:
	CardControllerExplore(){}
	CardControllerExplore(const CardControllerExplore& cardControllerExplore);
	CardControllerExplore& operator=(const CardControllerExplore& cardControllerExplore);

	// 卡池
	CardBoxRTM *cardPool = new CardBoxRTM();
	// 手牌
	CardBoxRTM *handCard = new CardBoxRTM(5);
	// 弃牌
	CardBoxRTM *recycleCard = new CardBoxRTM();

public:
	static CardControllerExplore* Instance();
	~CardControllerExplore();

	// 向卡池中添加一张卡
	void addCardToCardPool(int id)
	{
		cocos2d::log("[information] 正在向索场景的卡池中加入一张id为%d的卡", id);
		cardPool->addCard(id);
	}

	// 抽卡（暂定全随机）
	int drawACard()
	{
		cocos2d::log("[information] 正在从索场景的卡池中抽取一张卡...");

		if (cardPool->getCardCount() <= 0)
		{
			cocos2d::log("[warning] 从探索场景的卡池中抽取卡失败，当前卡池为空");
			return -1;
		}
		if (handCard->isFull())
		{
			cocos2d::log("[warning] 从探索场景的卡池中抽取卡失败，当前手牌已满");
			return -1;
		}

		int id = cardPool->removeCardByRandom();

		handCard->addCard(id);

		cocos2d::log("[information] 成功从探索场景的卡池中抽取一张id为%d的卡", id);
		return id;
	}

	// 出牌：指定id
	int playCardByID(int id)
	{
		cocos2d::log("[information] 正在从探索场景的手牌中使用一张id为%d的卡...", id);
		int result = handCard->removeCardByID(id);
		if (result == id)
			cocos2d::log("[information] 成功从探索场景的手牌中使用一张id为%d卡", id);
		else
			cocos2d::log("[warning] 从探索场景的手牌中使用一张id为%d卡失败", id);
		recycleCard->addCard(result);
		return result;
	}

	// 出牌：指定索引
	int playCardByIndex(int index)
	{
		cocos2d::log("[information] 正在从探索场景的手牌中使用一张索引为%d的卡...", index);
		int id = handCard->removeCardByIndex(index);
		if (id != -1)
			cocos2d::log("[information] 成功从探索场景的手牌中使用一张索引为%d,id为%d的卡", index, id);
		else
			cocos2d::log("[warning] 从探索场景的手牌中使用一张索引为%d卡失败", index);
		recycleCard->addCard(id);
		return id;
	}

	// 洗牌
	void shuffle()
	{
		auto it = recycleCard->getCardSet().cbegin();
		auto itEnd = recycleCard->getCardSet().cend();
		while (it != itEnd)
		{
			cardPool->addCard(it->second);
			++it;
		}

		recycleCard->clear();
		cocos2d::log("[information] 成功完成探索场景的洗牌");
	}
};

#endif
