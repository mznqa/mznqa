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

	static const MissionMap nullMissionMap;

public:
	static MissionMapSet* Instance();
	~MissionMapSet()
	{}

	void loadMainMissionMapSet(std::vector<MissionMap> &mainMissionMapSet);
	void loadSideMissionMapSet(std::vector<MissionMap> &sideMissionMapSet);

	const MissionMap& getMainMissionMapByIndex(int index)const
	{
		if (0 <= index && index < mainMissionMapSet.size())
			return mainMissionMapSet.at(index);
		else
			return nullMissionMap;
	}
	const MissionMap& getSideMissionMapByIndex(int index)const
	{
		if (0 <= index && index < sideMissionMapSet.size())
			return sideMissionMapSet.at(index);
		else
			return nullMissionMap;
	}
};

#endif
