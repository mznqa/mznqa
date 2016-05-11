/*!
 * \file	Classes\logic\core\state\CoreStateGuide.cpp
 *
 * \brief	������ CoreStateGuide
 */

#pragma execution_character_set("utf-8")

#include "logic/core/state/CoreStateGuide.h"

// TODO ������ //////////////////////////////////////////////////////////////////////////
#include "logic/dataLoader/StaticDataLoader.h"
#include "logic/gameObject/card/CardBase.h"
#include "logic/gameObject/card/CardRoad.h"
#include "helper/dataLoader/ParseCardRoadSet.h"
#include "logic/data/static/card/CardSet.h"
#include "logic/message/LogicMessagePQ.h"
//////////////////////////////////////////////////////////////////////////

CoreStateGuide::CoreStateGuide()
{
}

CoreStateGuide::~CoreStateGuide()
{
}

CoreStateGuide* CoreStateGuide::Instance()
{
	static CoreStateGuide instance;
	return &instance;
}

bool CoreStateGuide::enter(CoreController *owner)
{
	return true;
}
bool CoreStateGuide::update(CoreController *owner, double intervalTime)
{
	// TODO ������ //////////////////////////////////////////////////////////////////////////
	StaticDataLoader::loadStringSet();

	StaticDataLoader::loadCardRoadSet();
	auto xx = CardSet::Instance()->getCardRoadByID(11);
	auto msgC = LogicMessagePQ::Instance()->getMessageCount();
	//////////////////////////////////////////////////////////////////////////
	return true;
}
bool CoreStateGuide::exit(CoreController *owner)
{
	return true;
}