#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARDCONTROLLER_CARDBOX_H_
#define MZNQA_CLASSES_CARDCONTROLLER_CARDBOX_H_

#include <list>

#include "cocos2d.h"

#include "card/CardBase.h"
#include "staticData/CardSet.h"

template <typename CardType>
class CardBox
{
private:
	// 卡牌集合（id的集合)
	std::list<int> cardSet;

	// 容器大小
	const int size;
public:
	CardBox() :
		size(-1)
	{}
	CardBox(int size) :
		size(size)
	{
		if (this->size <= 0)
			this->size = -1;
	}
	~CardBox();

	// 获取卡牌数
	int getCardCount()const
	{
		return cardSet.size();
	}
	// 给定一张卡以添加
	void addCard(const CardType& card)
	{
		if (size != -1 && cardSet.size() >= size)
			return;
		cardSet.push_back(card.id);
	}
	// 给定一张卡的id以添加
	void addCard(int id)
	{
		if (size != -1 && cardSet.size() >= size)
			return;

		if (
			CardType::CARDTYPE == CardBase::CardType_Road &&
			CardSet::Instance()->getCardRoadByID(id) != nullptr
			)
			cardSet.push_back(id);
		else if (
			CardType::CARDTYPE == CardBase::CardType_Treasure &&
			CardSet::Instance()->getCardTreasureByID(id) != nullptr
			)
			cardSet.push_back(id);
		else if (
			CardType::CARDTYPE == CardBase::CardType_Monster &&
			CardSet::Instance()->getCardMonsterByID(id) != nullptr
			)
			cardSet.push_back(id);
		else if (
			CardType::CARDTYPE == CardBase::CardType_Skill &&
			CardSet::Instance()->getCardSkillByID(id) != nullptr
			)
			cardSet.push_back(id);
		else
		{
			cocos2d::log("[warning] 向 CardBox 添加卡牌失败，给定的id有误");
		}
	}
	// 根据id删除指定卡（注意：线性时间）
	bool removeCard(int id)
	{
		auto it = cardSet.begin();
		auto itEnd = cardSet.end();
		while (it != itEnd)
		{
			if (*it == id)
			{
				cardSet.erase(it);
				return true;
			}
			++it;
		}
		return false;
	}
	// 清空
	void clear()
	{
		cardSet.clear();
	}
	// 获取所有卡的id
	const std::list<int>& getCardSet()const
	{
		return cardSet;
	}
};

#endif