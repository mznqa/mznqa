/*!
 * \file	Classes\logic\gameObject\cardController\CardControllerCombat.cpp
 *
 * \brief	∂®“Â¿‡ CardControllerCombat
 */

#pragma execution_character_set("utf-8")

#include "logic/gameObject/cardController/CardControllerCombat.h"

CardControllerCombat::CardControllerCombat() :
pool(),
recycleBin(),
holder()
{
}
CardControllerCombat::CardControllerCombat(const std::list<int> &poolCardIDSet, const std::list<int> &recycleBinCardIDSet, const std::array<int, EXPLORE_CARDHOLDERSIZE> &holderCardIDSet) :
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
CardControllerCombat::CardControllerCombat(const CardControllerCombat &cardControllerCombat)
{
	auto it0 = cardControllerCombat.getPoolCardIDSet().cbegin();
	auto itEnd0 = cardControllerCombat.getPoolCardIDSet().cend();
	while (it0 != itEnd0)
	{
		pool.add(*it0);
		++it0;
	}
	auto it1 = cardControllerCombat.getRecycleBinCardIDSet().cbegin();
	auto itEnd1 = cardControllerCombat.getRecycleBinCardIDSet().cend();
	while (it1 != itEnd1)
	{
		recycleBin.add(*it1);
		++it1;
	}
	auto it2 = cardControllerCombat.getHolderCardIDSet().cbegin();
	auto itEnd2 = cardControllerCombat.getHolderCardIDSet().cend();
	while (it2 != itEnd2)
	{
		holder.add(*it2);
		++it2;
	}
}
CardControllerCombat& CardControllerCombat::operator=(const CardControllerCombat &cardControllerCombat)
{
	this->clear();
	auto it0 = cardControllerCombat.getPoolCardIDSet().cbegin();
	auto itEnd0 = cardControllerCombat.getPoolCardIDSet().cend();
	while (it0 != itEnd0)
	{
		this->pool.add(*it0);
		++it0;
	}
	auto it1 = cardControllerCombat.getRecycleBinCardIDSet().cbegin();
	auto itEnd1 = cardControllerCombat.getRecycleBinCardIDSet().cend();
	while (it1 != itEnd1)
	{
		this->recycleBin.add(*it1);
		++it1;
	}
	auto it2 = cardControllerCombat.getHolderCardIDSet().cbegin();
	auto itEnd2 = cardControllerCombat.getHolderCardIDSet().cend();
	while (it2 != itEnd2)
	{
		this->holder.add(*it2);
		++it2;
	}
	return *this;
}
CardControllerCombat::~CardControllerCombat()
{
}

void CardControllerCombat::reset()
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

void CardControllerCombat::reset(const std::list<int> &poolCardIDSet, const std::list<int> &recycleBinCardIDSet, const std::array<int, EXPLORE_CARDHOLDERSIZE> &holderCardIDSet)
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

void CardControllerCombat::addCardToPool(int cardID)
{
	pool.add(cardID);
}

int CardControllerCombat::drawCard()
{
	if (holder.isFull())
		return CardBase::invalidCardID;

	int cardID = pool.popByRandom();
	if (cardID != CardBase::invalidCardID)
	{
		holder.add(cardID);
	}

	return cardID;
}

int CardControllerCombat::discard(int index)
{
	int cardID = holder.removeByIndex(index);
	if (cardID != CardBase::invalidCardID)
		recycleBin.add(cardID);
	return cardID;
}

void CardControllerCombat::shuffle()
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

void CardControllerCombat::clear()
{
	pool.clear();
	recycleBin.clear();
	holder.clear();
}

bool CardControllerCombat::isEmptyPool()const
{
	return pool.isEmpty();
}

bool CardControllerCombat::isEmptyRecycleBin()const
{
	return recycleBin.isEmpty();
}

bool CardControllerCombat::isEmptyHolder()const
{
	return holder.isEmpty();
}

bool CardControllerCombat::isFullHolder()const
{
	return holder.isFull();
}

const std::list<int>& CardControllerCombat::getPoolCardIDSet()const
{
	return pool.getCardIDSet();
}

const std::list<int>& CardControllerCombat::getRecycleBinCardIDSet()const
{
	return recycleBin.getCardIDSet();
}

const std::array<int, EXPLORE_CARDHOLDERSIZE>& CardControllerCombat::getHolderCardIDSet()const
{
	return holder.getCardIDArray();
}