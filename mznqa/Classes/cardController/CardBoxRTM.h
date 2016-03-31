#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARDCONTROLLER_CARDBOXRTM_H_
#define MZNQA_CLASSES_CARDCONTROLLER_CARDBOXRTM_H_

#include <ctime>
#include <cstdlib>

#include <map>

#include "cardController/CardBox.h"
#include "card/CardRoad.h"
#include "card/CardTreasure.h"
#include "card/CardMonster.h"

class CardBoxRTM
{
private:
	CardBox<CardRoad> cardBoxRoad;
	CardBox<CardTreasure> cardBoxTreasure;
	CardBox<CardMonster> cardBoxMonster;

	std::map<int, int> index2ID;

	int size;

	void removeIndexByID(int id)
	{
		auto it = index2ID.begin();
		auto itEnd = index2ID.end();
		while (it != itEnd)
		{
			if (it->second == id)
			{
				index2ID.erase(it);
				return;
			}
			++it;
		}
	}
public:
	CardBoxRTM() :
		size(-1)
	{}

	CardBoxRTM(int size) :
		size(size)
	{
		if (this->size <= 0)
			this->size = -1;
	}
	~CardBoxRTM()
	{}

	// 获取总卡牌数
	int getCardCount()const
	{
		return cardBoxRoad.getCardCount() + cardBoxTreasure.getCardCount() + cardBoxMonster.getCardCount();
	}
	// 获取地形卡数
	int getCardRoadCount()const
	{
		return cardBoxRoad.getCardCount();
	}
	// 获取宝物卡数
	int getCardTreasureCount()const
	{
		return cardBoxTreasure.getCardCount();
	}
	// 获取怪物卡数
	int getCardMonsterCount()const
	{
		return cardBoxMonster.getCardCount();
	}

	// 给定一张地形卡以添加
	void addCard(const CardRoad& card)
	{
		if (size != -1 && getCardCount() >= size)
			return;
		cardBoxRoad.addCard(card);
		if (index2ID.size() <= 0)
			index2ID.insert(std::pair<int, int>(0, card.getID()));
		else
			index2ID.insert(std::pair<int, int>(index2ID.rbegin()->first + 1, card.getID()));
	}
	// 给定一张宝物卡以添加
	void addCard(const CardTreasure& card)
	{
		if (size != -1 && getCardCount() >= size)
			return;
		cardBoxTreasure.addCard(card);
		if (index2ID.size() <= 0)
			index2ID.insert(std::pair<int, int>(0, card.getID()));
		else
			index2ID.insert(std::pair<int, int>(index2ID.rbegin()->first + 1, card.getID()));
	}
	// 给定一张怪物卡以添加
	void addCard(const CardMonster& card)
	{
		if (size != -1 && getCardCount() >= size)
			return;
		cardBoxMonster.addCard(card);
		if (index2ID.size() <= 0)
			index2ID.insert(std::pair<int, int>(0, card.getID()));
		else
			index2ID.insert(std::pair<int, int>(index2ID.rbegin()->first + 1, card.getID()));
	}

	// 给定一张卡的id以添加
	void addCard(int id)
	{
		if (size != -1 && getCardCount() >= size)
			return;

		CardBase::CardType cType = CardBase::judgeCardTypeByID(id);
		if (
			cType == CardBase::CardType_Road &&
			CardSet::Instance()->getCardRoadByID(id) != nullptr
			)
		{
			cardBoxRoad.addCard(id);
			if (index2ID.size() <= 0)
				index2ID.insert(std::pair<int, int>(0, id));
			else
				index2ID.insert(std::pair<int, int>(index2ID.rbegin()->first + 1, id));
		}
		else if (
			cType == CardBase::CardType_Treasure &&
			CardSet::Instance()->getCardTreasureByID(id) != nullptr
			)
		{
			cardBoxTreasure.addCard(id);
			if (index2ID.size() <= 0)
				index2ID.insert(std::pair<int, int>(0, id));
			else
				index2ID.insert(std::pair<int, int>(index2ID.rbegin()->first + 1, id));
		}
		else if (
			cType == CardBase::CardType_Monster &&
			CardSet::Instance()->getCardMonsterByID(id) != nullptr
			)
		{
			cardBoxMonster.addCard(id);
			if (index2ID.size() <= 0)
				index2ID.insert(std::pair<int, int>(0, id));
			else
				index2ID.insert(std::pair<int, int>(index2ID.rbegin()->first + 1, id));
		}
		else
		{
			cocos2d::log("[warning] 向 CardBoxRTM 添加卡牌失败，给定的id=%d有误", id);
		}
	}

	// 根据id删除指定卡（注意：线性时间）
	int removeCardByID(int id)
	{
		CardBase::CardType cType = CardBase::judgeCardTypeByID(id);
		if (
			cType == CardBase::CardType_Road &&
			CardSet::Instance()->getCardRoadByID(id) != nullptr
			)
		{
			removeIndexByID(id);
			return cardBoxRoad.removeCardByID(id);
		}
		else if (
			cType == CardBase::CardType_Treasure &&
			CardSet::Instance()->getCardTreasureByID(id) != nullptr
			)
		{
			removeIndexByID(id);
			return cardBoxTreasure.removeCardByID(id);
		}
		else if (
			cType == CardBase::CardType_Monster &&
			CardSet::Instance()->getCardMonsterByID(id) != nullptr
			)
		{
			removeIndexByID(id);
			return cardBoxMonster.removeCardByID(id);
		}
		else
		{
			cocos2d::log("[warning] 向 CardBoxRTM 移除卡牌失败，给定的id有误");
			return -1;
		}
		return -1;
	}
	// 根据索引删除卡
	int removeCardByIndex(int index)
	{
		int sTemp = index2ID.size();
		if (!(0 <= index && index < sTemp))
			return -1;

		auto it = index2ID.begin();
		auto itEnd = index2ID.end();
		int i = 0;
		while (it != itEnd)
		{
			if (i == index)
			{
				int idResult = removeCardByID(it->second);
				return idResult;
			}
			++it;
			++i;
		}
		return -1;
	}
	// 随意移除一张卡
	int removeCardByRandom()
	{
		if (index2ID.size() <= 0)
			return -1;

		// TODO 暂放
		srand(unsigned(time(NULL)));

		int index = rand() % (index2ID.size());

		return removeCardByIndex(index);
	}
	// 随机移除一张地形卡
	int removeCardRoadByRandom()
	{
		int id = cardBoxRoad.removeCardByRandom();
		removeIndexByID(id);
		return id;
	}
	// 随机移除一张宝物卡
	int removeCardTreasureByRandom()
	{
		int id = cardBoxTreasure.removeCardByRandom();
		removeIndexByID(id);
		return id;
	}
	// 随机移除一张怪物卡
	int removeCardMonsterByRandom()
	{
		int id = cardBoxMonster.removeCardByRandom();
		removeIndexByID(id);
		return id;
	}

	// 清空
	void clear()
	{
		cardBoxRoad.clear();
		cardBoxTreasure.clear();
		cardBoxMonster.clear();
		index2ID.clear();
	}

	// 判断卡牌是否已满
	bool isFull()
	{
		if (size != -1 && getCardCount() >= size)
			return true;
		else
			return false;
	}

	// 获取所有地形卡的id
	const std::map<int, int>& getCardSet()const
	{
		return index2ID;
	}
};

#endif
