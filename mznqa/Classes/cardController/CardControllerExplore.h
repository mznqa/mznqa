#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARDCONTROLLER_CARDCONTROLLEREXPLORE_H_
#define MZNQA_CLASSES_CARDCONTROLLER_CARDCONTROLLEREXPLORE_H_

#include <list>

#include "cardController/CardBox.h"

class CardControllerExplore
{
private:
	CardControllerExplore(){}
	CardControllerExplore(const CardControllerExplore& cardControllerExplore);
	CardControllerExplore& operator=(const CardControllerExplore& cardControllerExplore);

	// 卡池 //////////////////////////////////////////////////////////////////////////
	CardBox<CardRoad> cardPoolCardRoad;
	CardBox<CardTreasure> cardPoolCardTreasure;
	CardBox<CardMonster> cardPoolCardMonster;
	//////////////////////////////////////////////////////////////////////////

	// 手牌 //////////////////////////////////////////////////////////////////////////
	CardBox<CardRoad> handCardCardRoad;
	CardBox<CardTreasure> handCardCardTreasure;
	CardBox<CardMonster> handCardCardMonster;
	//////////////////////////////////////////////////////////////////////////

	// 回收 //////////////////////////////////////////////////////////////////////////
	CardBox<CardRoad> recycleCardCardRoad;
	CardBox<CardTreasure> recycleCardCardTreasure;
	CardBox<CardMonster> recycleCardCardMonster;
	//////////////////////////////////////////////////////////////////////////

public:
	static CardControllerExplore* Instance();
	~CardControllerExplore();

	// 向卡池中添加一张卡
	void addToCardPool(int id)
	{
		CardBase::CardType cType = CardBase::judgeCardTypeByID(id);
		if (
			cType == CardBase::CardType_Road &&
			CardSet::Instance()->getCardRoadByID(id) != nullptr
			)
			cardPoolCardRoad.addCard(id);
		else if (
			cType == CardBase::CardType_Treasure &&
			CardSet::Instance()->getCardTreasureByID(id) != nullptr
			)
			cardPoolCardTreasure.addCard(id);
		else if (
			cType == CardBase::CardType_Monster &&
			CardSet::Instance()->getCardMonsterByID(id) != nullptr
			)
			cardPoolCardMonster.addCard(id);
		else
		{
			cocos2d::log("[warning] 向探索场景的卡池中添加卡牌失败，给定的id有误，或卡牌类型有误");
		}
	}

	// 抽卡（暂定全随机）
	void drawACard()
	{
	}
};

#endif
