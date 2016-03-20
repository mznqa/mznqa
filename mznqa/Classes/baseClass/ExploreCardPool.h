#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_BASECLASS_EXPLORECARDPOOL_H_
#define MZNQA_CLASSES_BASECLASS_EXPLORECARDPOOL_H_

#include <list>

#include "baseClass/Card.h"
#include "baseClass/CardRoad.h"
#include "baseClass/CardTreasure.h"
#include "baseClass/CardMonster.h"

class ExploreCardPool
{
private:
	// 子卡池：存放地形卡
	std::list<CardRoad> cardRoadSet;
	// 子卡池：存放宝物卡
	std::list<CardTreasure> cardTreasureSet;
	// 子卡池：存放怪物卡
	std::list<CardMonster> cardMonsterSet;

	// 回收站
	std::list<Card> recycleBin;
public:
	ExploreCardPool();
	~ExploreCardPool();

	// 向卡池中添加一张卡
	void AddACard(const Card &card);
	// 从卡池中抽取一张卡
	Card DrawACard();
	// 清空卡池
	void clear();
	// 洗牌
	void shuffle();

	// 将牌放置到弃牌区
	void pushRecycleBin(const Card &card);
	// 清空弃牌区
	void clearRecycleBin();
	// 获取弃牌去的卡牌数
	int getRecycleBinCardCount();

	// 获取当前卡池中卡牌个数
	int getCardCount();
	// 获取当前卡池中的地形卡个数
	int getCardRoadCount();
	// 获取当前卡池中的宝物卡个数
	int getCardTreasureCount();
	// 获取当前卡池中怪物卡的个数
	int getCardMonsterCount();

	void test();
};

#endif
