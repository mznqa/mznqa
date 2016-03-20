#pragma execution_character_set("utf-8")

#include <ctime>
#include <cstdlib>

#include <iterator>

#include "cocos2d.h"

#include "baseClass/ExploreCardPool.h"

ExploreCardPool::ExploreCardPool()
{
}

ExploreCardPool::~ExploreCardPool()
{
}

void ExploreCardPool::AddACard(const Card &card)
{
	Card::CardType type = card.getCardType();
	if (!(
		card.getID() >= 0 && (
		type == Card::CardType_Road ||
		type == Card::CardType_Treasure ||
		type == Card::CardType_Monster
		)
		))
	{
		cocos2d::log("警告：尝试想探索场景中的卡池添加一张卡（id=%d, type=%d）失败", card.getID(), card.getCardType());
		return;
	}

	if (type == Card::CardType_Road)
	{
		cardRoadSet.push_back(card);
		cocos2d::log("提示：已添加一张【地形卡】（id=%d, type=%d）到探索场景中的卡池", card.getID(), card.getCardType());
	}
	else if (type == Card::CardType_Treasure)
	{
		cardTreasureSet.push_back(card);
		cocos2d::log("提示：已添加一张【宝物卡】（id=%d, type=%d）到探索场景中的卡池", card.getID(), card.getCardType());
	}
	else if (type == Card::CardType_Monster)
	{
		cardMonsterSet.push_back(card);
		cocos2d::log("提示：已添加一张【怪物卡】（id=%d, type=%d）到探索场景中的卡池", card.getID(), card.getCardType());
	}
	else
	{
		cocos2d::log("警告：尝试想探索场景中的卡池添加一张卡（id=%d, type=%d）失败，找不对应的容器以放置该卡", card.getID(), card.getCardType());
	}
}

Card ExploreCardPool::DrawACard()
{
	cocos2d::log("提示：在探索场景下，正尝试抽一张卡...");

	if (getCardCount() <= 0)
	{
		cocos2d::log("警告：在探索场景下，抽卡失败（当前卡池中剩余%d张卡）", getCardCount());
		return Card(-1, Card::CardType_None);
	}

	srand(unsigned(time(NULL)));

	Card::CardType type = Card::CardType_None;
	int index;
	Card card(-1, Card::CardType_None);
	while (true)
	{
		type = Card::CardType(rand() % 3 + 1);
		if (type == Card::CardType_Road && getCardRoadCount() > 0)
		{
			index = rand() % getCardRoadCount();
			auto it = cardRoadSet.begin();
			advance(it, index);
			card = *it;
			cardRoadSet.erase(it);
			cocos2d::log("提示：在探索场景下，抽到一张【地形卡】（id=%d, type=%d）", card.getID(), card.getCardType());
			break;
		}
		if (type == Card::CardType_Treasure && getCardTreasureCount() > 0)
		{
			index = rand() % getCardTreasureCount();
			auto it = cardTreasureSet.begin();
			advance(it, index);
			card = *it;
			cardTreasureSet.erase(it);
			cocos2d::log("提示：在探索场景下，抽到一张【宝物卡】（id=%d, type=%d）", card.getID(), card.getCardType());
			break;
		}
		if (type == Card::CardType_Monster && getCardMonsterCount() > 0)
		{
			index = rand() % getCardMonsterCount();
			auto it = cardMonsterSet.begin();
			advance(it, index);
			card = *it;
			cardMonsterSet.erase(it);
			cocos2d::log("提示：在探索场景下，抽到一张【怪物卡】（id=%d, type=%d）", card.getID(), card.getCardType());
			break;
		}
	}

	return card;
}

void ExploreCardPool::clear()
{
	cardRoadSet.clear();
	cardTreasureSet.clear();
	cardMonsterSet.clear();

	cocos2d::log("提示：已经清空卡池");
}

void ExploreCardPool::shuffle()
{
	while (recycleBin.empty() == false)
	{
		AddACard(recycleBin.back());
		recycleBin.pop_back();
	}

	cocos2d::log("提示：已完成洗牌");
}

void ExploreCardPool::pushRecycleBin(const Card &card)
{
	Card::CardType type = card.getCardType();
	if (!(
		card.getID() >= 0 && (
		type == Card::CardType_Road ||
		type == Card::CardType_Treasure ||
		type == Card::CardType_Monster
		)
		))
	{
		cocos2d::log("警告：尝试想探索场景中的弃牌区添加一张卡（id=%d, type=%d）失败", card.getID(), card.getCardType());
		return;
	}

	recycleBin.push_back(card);

	cocos2d::log("提示：已成功将一张卡（id=%d, type=%d），放入弃牌区", card.getID(), card.getCardType());
}

void ExploreCardPool::clearRecycleBin()
{
	recycleBin.clear();

	cocos2d::log("提示：已成功清空弃牌区");
}

int ExploreCardPool::getRecycleBinCardCount()
{
	return recycleBin.size();
}

int ExploreCardPool::getCardCount()
{
	return  cardRoadSet.size() + cardTreasureSet.size() + cardMonsterSet.size();
}

int ExploreCardPool::getCardRoadCount()
{
	return cardRoadSet.size();
}

int ExploreCardPool::getCardTreasureCount()
{
	return cardTreasureSet.size();
}

int ExploreCardPool::getCardMonsterCount()
{
	return cardMonsterSet.size();
}

void ExploreCardPool::test()
{
	AddACard(CardRoad(1));
	AddACard(CardTreasure(11));
	AddACard(CardMonster(21));

	AddACard(CardRoad(2));
	AddACard(CardTreasure(12));
	AddACard(CardMonster(22));

	AddACard(CardRoad(3));
	AddACard(CardTreasure(13));
	AddACard(CardMonster(23));

	AddACard(CardRoad(4));
	AddACard(CardTreasure(14));
	AddACard(CardMonster(24));

	AddACard(CardRoad(5));
	AddACard(CardTreasure(15));
	AddACard(CardMonster(25));

	Card card(-1, Card::CardType_None);
	for (int i = 0; i < 18; ++i)
	{
		card = DrawACard();
		pushRecycleBin(card);
		cocos2d::log("card-id:%d, card-type:%d", card.getID(), card.getCardType());
		cocos2d::log("\tcard-count:%d", getCardCount());
	}

	shuffle();

	return;
}