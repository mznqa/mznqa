#pragma execution_character_set("utf-8")

#include "staticData/MissionMapSet.h"

const MissionMap MissionMapSet::nullMissionMap;

MissionMapSet* MissionMapSet::Instance()
{
	static MissionMapSet instance;
	return &instance;
}

void MissionMapSet::loadMainMissionMapSet(std::vector<MissionMap> &mainMissionMapSet)
{
	this->mainMissionMapSet.swap(mainMissionMapSet);
}

void MissionMapSet::loadSideMissionMapSet(std::vector<MissionMap> &sideMissionMapSet)
{
	this->sideMissionMapSet.swap(sideMissionMapSet);
}