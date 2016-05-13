/*!
 * \file	Classes\logic\core\state\CoreStateGuide.cpp
 *
 * \brief	定义类 CoreStateGuide
 */

#pragma execution_character_set("utf-8")

#include "logic/core/state/CoreStateGuide.h"

// TODO 测试用 //////////////////////////////////////////////////////////////////////////
#include "logic/dataLoader/StaticDataLoader.h"
#include "logic/gameObject/card/CardBase.h"
#include "logic/gameObject/card/CardRoad.h"
#include "helper/dataLoader/ParseCardRoadSet.h"
#include "logic/data/static/card/CardSet.h"
#include "logic/message/LogicMessagePQ.h"
#include "helper/dataLoader/ParseMissionMapMain.h"
#include "helper/fileManager/FileManager.h"
#include "logic/data/info/DataFilePath.h"
#include "logic/data/static/missionMap/MissionMapSet.h"
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
	// TODO 测试用 //////////////////////////////////////////////////////////////////////////
	StaticDataLoader::loadMissionMapMain(MissionMapSet::MissionMapIDMain_0);
	MissionMapSet::Instance()->Instance();
	//////////////////////////////////////////////////////////////////////////
	return true;
}
bool CoreStateGuide::exit(CoreController *owner)
{
	return true;
}