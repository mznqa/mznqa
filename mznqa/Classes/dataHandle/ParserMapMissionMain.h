#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_DATAHANDLE_PARSERMAPMISSIONMAIN_H_
#define MZNQA_CLASSES_DATAHANDLE_PARSERMAPMISSIONMAIN_H_

#include <vector>

#include "map/MissionMap.h"

class ParserMapMissionMain
{
private:
public:
	ParserMapMissionMain()
	{
	}

	~ParserMapMissionMain()
	{
	}

	void parse();

	static std::vector<MissionMap> mainMissionMapSetTemp;
};

#endif
