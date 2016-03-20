#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_BASECLASS_CARDPOOL_H_
#define MZNQA_CLASSES_BASECLASS_CARDPOOL_H_

#include "baseClass/Card.h"

class CardPool
{
public:
	CardPool(){}
	~CardPool(){}

	// 向卡池中添加一张卡
	virtual void AddACard(const Card &card) = 0;
	// 从卡池中抽取一张卡
	virtual Card DrawACard() = 0;
	// 清空卡池
	virtual void clear() = 0;
	// 洗牌
	virtual void shuffle() = 0;

	// 将牌放置到弃牌区
	virtual void pushRecycleBin(const Card &card) = 0;
	// 清空弃牌区
	virtual void clearRecycleBin() = 0;
	// 获取弃牌区卡牌数
	virtual int getRecycleBinCardCount() = 0;

	// 获取当前卡池中卡牌个数
	virtual int getCardCount() = 0;
};

#endif
