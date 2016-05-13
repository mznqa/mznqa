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

void CardSet::loadCardRoadSet(std::map<int, CardRoad> &cardRoadSet)
{
	this->cardRoadSet.clear();
	this->cardRoadSet.swap(cardRoadSet);
}

const CardRoad *const CardSet::getCardRoadByID(int id)const
{
	auto it = cardRoadSet.find(id);
	if (it == cardRoadSet.end())
		return nullptr;
	else
		return &(it->second);
}