/*!
 * \file	Classes\cardController\CardBoxRTM.cpp
 *
 * \brief	定义类 CardBoxRTM
 */

#pragma execution_character_set("utf-8")

#include "cardController/CardBoxRTM.h"

#include <iterator>

int CardBoxRTM::removeIndexByID(int id)
{
	auto it = index2ID.begin();
	auto itEnd = index2ID.end();
	while (it != itEnd)
	{
		if (it->second == id)
		{
			int index = std::distance(it, index2ID.begin());
			index2ID.erase(it);
			return index;
		}
		++it;
	}

	return -1;
}

int CardBoxRTM::addCardByCard(const CardRoad& card)
{
	// 如果容量不足
	if (size != CardBase::invalidID && getCardCount() >= size)
		return CardBase::invalidID;

	// 向地形卡子容器中添加地形卡
	int result = cardBoxRoad.addCardByCard(card);

	// 插入索引
	insertIndexByID(result);

	return result;
}

int CardBoxRTM::addCardByCard(const CardTreasure& card)
{
	// 如果容量不足
	if (size != CardBase::invalidID && getCardCount() >= size)
		return CardBase::invalidID;

	// 向宝物卡子容器中添加卡牌
	int result = cardBoxTreasure.addCardByCard(card);

	// 插入索引
	insertIndexByID(result);

	return result;
}

int CardBoxRTM::addCardByCard(const CardMonster& card)
{
	// 如果容量不足
	if (size != CardBase::invalidID && getCardCount() >= size)
		return CardBase::invalidID;

	// 向怪物子容器中添加卡牌
	int result = cardBoxMonster.addCardByCard(card);

	// 插入索引
	insertIndexByID(result);

	return result;
}

int CardBoxRTM::addCardByID(int id)
{
	// 如果容器不足
	if (size != CardBase::invalidID && getCardCount() >= size)
		return CardBase::invalidID;

	int result = CardBase::invalidID;
	// 判断给定id对应卡牌类型
	CardBase::CardType cType = CardBase::judgeCardTypeByID(id);
	// 如果是地形卡且在卡牌库中存在
	if (
		cType == CardBase::CardType_Road &&
		CardSet::Instance()->getCardRoadByID(id) != nullptr
		)
	{
		// 向地形卡子容器中添加卡牌
		result = cardBoxRoad.addCardByID(id);
		// 插入索引
		insertIndexByID(result);
	}
	// 如果是宝物卡且在卡牌库中存在
	else if (
		cType == CardBase::CardType_Treasure &&
		CardSet::Instance()->getCardTreasureByID(id) != nullptr
		)
	{
		// 向宝物卡子容器中添加卡牌
		result = cardBoxTreasure.addCardByID(id);
		// 插入索引
		insertIndexByID(result);
	}
	// 如果是怪物卡且在卡牌库中存在
	else if (
		cType == CardBase::CardType_Monster &&
		CardSet::Instance()->getCardMonsterByID(id) != nullptr
		)
	{
		// 向怪物卡子容器中添加卡牌
		result = cardBoxMonster.addCardByID(id);
		// 插入索引
		insertIndexByID(result);
	}
	// 此外...
	else
	{
		cocos2d::log("[warning] 向 CardBoxRTM 添加卡牌失败，给定的id=%d有误", id);
		return CardBase::invalidID;
	}

	return result;
}

int CardBoxRTM::removeCardByID(int id)
{
	// 判断给定id指向的卡牌类型
	CardBase::CardType cType = CardBase::judgeCardTypeByID(id);
	// 如果是地形卡且在卡牌库中
	if (
		cType == CardBase::CardType_Road &&
		CardSet::Instance()->getCardRoadByID(id) != nullptr
		)
	{
		removeIndexByID(id);
		return cardBoxRoad.removeCardByID(id);
	}
	// 如果是宝物卡且在卡牌库中
	else if (
		cType == CardBase::CardType_Treasure &&
		CardSet::Instance()->getCardTreasureByID(id) != nullptr
		)
	{
		removeIndexByID(id);
		return cardBoxTreasure.removeCardByID(id);
	}
	// 如果是怪物卡且在卡牌库中
	else if (
		cType == CardBase::CardType_Monster &&
		CardSet::Instance()->getCardMonsterByID(id) != nullptr
		)
	{
		removeIndexByID(id);
		return cardBoxMonster.removeCardByID(id);
	}
	// 此外...
	else
	{
		cocos2d::log("[warning] 向 CardBoxRTM 移除卡牌失败，给定的id有误");
		return CardBase::invalidID;
	}
	return CardBase::invalidID;
}

int CardBoxRTM::removeCardByIndex(int index)
{
	// 判断索引是否越界
	int sTemp = index2ID.size();
	if (!(0 <= index && index < sTemp))
		return CardBase::invalidID;

	// 遍历容器
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
	return CardBase::invalidID;
}