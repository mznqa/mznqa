/*!
 * \file	Classes\logic\data\static\card\CardSet.cpp
 *
 * \brief	∂®“Â¿‡ CardSet
 */

#pragma execution_character_set("utf-8")

#include "logic/data/static/card/CardSet.h"

CardSet* CardSet::Instance()
{
	static CardSet instance;
	return &instance;
}

void CardSet::loadCardRoadSet(const std::vector<CardRoad> &cardRoadSet)
{
	auto it = cardRoadSet.cbegin();
	auto itEnd = cardRoadSet.cend();
	while (it != itEnd)
	{
		this->cardRoadSet.insert(std::pair<int, CardRoad>(it->getID(), *it));
		++it;
	}
}

const CardRoad *const CardSet::getCardRoadByID(int id)const
{
	auto it = cardRoadSet.find(id);
	if (it == cardRoadSet.end())
		return nullptr;
	else
		return &(it->second);
}