#pragma execution_character_set("utf-8")

#include "staticData/CardSet.h"

CardSet* CardSet::Instance()
{
	static CardSet instance;
	return &instance;
}

CardSet::~CardSet()
{
}