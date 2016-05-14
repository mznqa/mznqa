/*!
 * \file	Classes\logic\core\state\CoreStateGuide.cpp
 *
 * \brief	¶¨ÒåÀà CoreStateGuide
 */

#pragma execution_character_set("utf-8")

#include "logic/core/state/CoreStateGuide.h"

#include "logic/core/state/CoreStateResLoading.h"
#include "logic/dataLoader/StaticDataLoader.h"

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
	StaticDataLoader::loadStringSet();
	StaticDataLoader::loadCardRoadSet();
	owner->fSM.changeState(CoreStateResLoading::Instance());
	return true;
}
bool CoreStateGuide::exit(CoreController *owner)
{
	return true;
}