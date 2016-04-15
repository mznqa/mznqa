#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_STATICDATA_MISSIONMAPSET_H_
#define MZNQA_CLASSES_STATICDATA_MISSIONMAPSET_H_

#include <vector>

#include "map/MissionMap.h"

class MissionMapSet
{
private:
	MissionMapSet()
	{}
	MissionMapSet(const MissionMapSet &missionMapSet);
	MissionMapSet& operator=(const MissionMapSet &missionMapSet);

	std::vector<MissionMap> mainMissionMapSet;
	std::vector<MissionMap> sideMissionMapSet;

public:
	static MissionMapSet* Instance();
	~MissionMapSet()
	{}

	void loadMainMissionMapSet(std::vector<MissionMap> &mainMissionMapSet);
	void loadSideMissionMapSet(std::vector<MissionMap> &sideMissionMapSet);
};

#endif
