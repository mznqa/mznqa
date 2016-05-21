/*!
 * \file	Classes\logic\gameObject\cardController\CardControllerExplore.cpp
 *
 * \brief	∂®“Â¿‡ CardControllerExplore
 */

#pragma execution_character_set("utf-8")

#include "logic/gameObject/cardController/CardControllerExplore.h"

CardControllerExplore::CardControllerExplore() :
pool(),
recycleBin(),
holder()
{
}
CardControllerExplore::CardControllerExplore(const std::list<int> &poolCardIDSet, const std::list<int> &recycleBinCardIDSet, const std::array<int, EXPLORE_CARDHOLDERSIZE> &holderCardIDSet) :
pool(),
recycleBin(),
holder()
{
	auto it0 = poolCardIDSet.cbegin();
	auto itEnd0 = poolCardIDSet.cend();
	while (it0 != itEnd0)
	{
		pool.add(*it0);
		++it0;
	}
	auto it1 = recycleBinCardIDSet.cbegin();
	auto itEnd1 = recycleBinCardIDSet.cend();
	while (it1 != itEnd1)
	{
		recycleBin.add(*it1);
		++it1;
	}
	auto it2 = holderCardIDSet.cbegin();
	auto itEnd2 = holderCardIDSet.cend();
	while (it2 != itEnd2)
	{
		holder.add(*it2);
		++it2;
	}
}
CardControllerExplore::CardControllerExplore(const CardControllerExplore &cardControllerExplore)
{
	auto it0 = cardControllerExplore.getPoolCardIDSet().cbegin();
	auto itEnd0 = cardControllerExplore.getPoolCardIDSet().cend();
	while (it0 != itEnd0)
	{
		pool.add(*it0);
		++it0;
	}
	auto it1 = cardControllerExplore.getRecycleBinCardIDSet().cbegin();
	auto itEnd1 = cardControllerExplore.getRecycleBinCardIDSet().cend();
	while (it1 != itEnd1)
	{
		recycleBin.add(*it1);
		++it1;
	}
	auto it2 = cardControllerExplore.getHolderCardIDSet().cbegin();
	auto itEnd2 = cardControllerExplore.getHolderCardIDSet().cend();
	while (it2 != itEnd2)
	{
		holder.add(*it2);
		++it2;
	}
}
CardControllerExplore& CardControllerExplore::operator=(const CardControllerExplore &cardControllerExplore)
{
	this->clear();
	auto it0 = cardControllerExplore.getPoolCardIDSet().cbegin();
	auto itEnd0 = cardControllerExplore.getPoolCardIDSet().cend();
	while (it0 != itEnd0)
	{
		this->pool.add(*it0);
		++it0;
	}
	auto it1 = cardControllerExplore.getRecycleBinCardIDSet().cbegin();
	auto itEnd1 = cardControllerExplore.getRecycleBinCardIDSet().cend();
	while (it1 != itEnd1)
	{
		this->recycleBin.add(*it1);
		++it1;
	}
	auto it2 = cardControllerExplore.getHolderCardIDSet().cbegin();
	auto itEnd2 = cardControllerExplore.getHolderCardIDSet().cend();
	while (it2 != itEnd2)
	{
		this->holder.add(*it2);
		++it2;
	}
	return *this;
}
CardControllerExplore::~CardControllerExplore()
{
}

void CardControllerExplore::reset()
{
	shuffle();
	auto it = holder.getCardIDArray().cbegin();
	auto itEnd = holder.getCardIDArray().cbegin();
	while (it != itEnd)
	{
		pool.add(*it);
		++it;
	}
	holder.clear();
}

void CardControllerExplore::reset(const std::list<int> &poolCardIDSet, const std::list<int> &recycleBinCardIDSet, const std::array<int, EXPLORE_CARDHOLDERSIZE> &holderCardIDSet)
{
	clear();
	auto it0 = poolCardIDSet.cbegin();
	auto itEnd0 = poolCardIDSet.cend();
	while (it0 != itEnd0)
	{
		pool.add(*it0);
		++it0;
	}
	auto it1 = recycleBinCardIDSet.cbegin();
	auto itEnd1 = recycleBinCardIDSet.cend();
	while (it1 != itEnd1)
	{
		recycleBin.add(*it1);
		++it1;
	}
	auto it2 = holderCardIDSet.cbegin();
	auto itEnd2 = holderCardIDSet.cend();
	while (it2 != itEnd2)
	{
		holder.add(*it2);
		++it2;
	}
}

void CardControllerExplore::addCardToPool(int cardID)
{
	pool.add(cardID);
}

void CardControllerExplore::drawCard()
{
	if (holder.isFull())
		return;

	int cardID = pool.popByRandom();
	if (cardID != CardBase::invalidCardID)
		holder.add(cardID);
}

int CardControllerExplore::drawCardAndReturnCardID()
{
	if (holder.isFull())
		return CardBase::invalidCardID;

	int cardID = pool.popByRandom();
	if (cardID != CardBase::invalidCardID)
		holder.add(cardID);

	return cardID;
}

int CardControllerExplore::drawCardAndReturnIndex()
{
	if (holder.isFull())
		return -1;

	int cardID = pool.popByRandom();
	if (cardID != CardBase::invalidCardID)
		return holder.add(cardID);

	return -1;
}

int CardControllerExplore::discard(int index)
{
	int cardID = holder.removeByIndex(index);
	if (cardID != CardBase::invalidCardID)
		recycleBin.add(cardID);
	return cardID;
}

void CardControllerExplore::shuffle()
{
	auto it = recycleBin.getCardIDSet().cbegin();
	auto itEnd = recycleBin.getCardIDSet().cbegin();
	while (it != itEnd)
	{
		pool.add(*it);
		++it;
	}
	recycleBin.clear();
}

void CardControllerExplore::clear()
{
	pool.clear();
	recycleBin.clear();
	holder.clear();
}

bool CardControllerExplore::isEmptyPool()const
{
	return pool.isEmpty();
}

bool CardControllerExplore::isEmptyRecycleBin()const
{
	return recycleBin.isEmpty();
}

bool CardControllerExplore::isEmptyHolder()const
{
	return holder.isEmpty();
}

bool CardControllerExplore::isFullHolder()const
{
	return holder.isFull();
}

const std::list<int>& CardControllerExplore::getPoolCardIDSet()const
{
	return pool.getCardIDSet();
}

const std::list<int>& CardControllerExplore::getRecycleBinCardIDSet()const
{
	return recycleBin.getCardIDSet();
}

const std::array<int, EXPLORE_CARDHOLDERSIZE>& CardControllerExplore::getHolderCardIDSet()const
{
	return holder.getCardIDArray();
}