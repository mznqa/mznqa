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

void CardSet::loadCardSkillSet(std::map<int, CardSkill> &cardSkillSet)
{
	this->cardSkillSet.clear();
	this->cardSkillSet.swap(cardSkillSet);
}

void CardSet::loadCardMonsterSet(std::map<int, CardMonster> &cardMonsterSet)
{
	this->cardMonsterSet.clear();
	this->cardMonsterSet.swap(cardMonsterSet);
}

void CardSet::loadCardTreasureSet(std::map<int, CardTreasure> &cardTreasureSet)
{
	this->cardTreasureSet.clear();
	this->cardTreasureSet.swap(cardTreasureSet);
}

bool CardSet::isCardType(CardBase::CardType cardType, int id)const
{
	switch (cardType)
	{
	case CardBase::CardType_Road:
		return cardRoadSet.find(id) != cardRoadSet.end();
	case CardBase::CardType_Skill:
		return cardSkillSet.find(id) != cardSkillSet.end();
	case CardBase::CardType_Monster:
		return cardMonsterSet.find(id) != cardMonsterSet.end();
	case CardBase::CardType_Treasure:
		return cardTreasureSet.find(id) != cardTreasureSet.end();
	default:
		return false;
	}
	return false;
}

const CardRoad *const CardSet::getCardRoadByID(int id)const
{
	auto it = cardRoadSet.find(id);
	if (it == cardRoadSet.end())
		return nullptr;
	else
		return &(it->second);
}

const CardSkill *const CardSet::getCardSkillByID(int id)const
{
	auto it = cardSkillSet.find(id);
	if (it == cardSkillSet.end())
		return nullptr;
	else
		return &(it->second);
}

const CardMonster *const CardSet::getCardMonsterByID(int id)const
{
	auto it = cardMonsterSet.find(id);
	if (it == cardMonsterSet.end())
		return nullptr;
	else
		return &(it->second);
}

const CardTreasure *const CardSet::getCardTreasureByID(int id)const
{
	auto it = cardTreasureSet.find(id);
	if (it == cardTreasureSet.end())
		return nullptr;
	else
		return &(it->second);
}