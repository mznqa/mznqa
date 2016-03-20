#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_BASECLASS_COMBATCARDPOOL_H_
#define MZNQA_CLASSES_BASECLASS_COMBATCARDPOOL_H_

#include <list>

#include "baseClass/Card.h"
#include "baseClass/CardPool.h"
#include "baseClass/CardSkill.h"

class CombatCardPool : public CardPool
{
private:
	// 技能卡卡池
	std::list<CardSkill> cardSkillSet;

	// 回收站
	std::list<CardSkill> recycleBin;
public:
	CombatCardPool();
	~CombatCardPool();

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

	void test();
};

#endif
