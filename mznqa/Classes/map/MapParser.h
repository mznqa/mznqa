#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MAP_MAPPARSER_H_
#define MZNQA_CLASSES_MAP_MAPPARSER_H_

#include <map>

#include "map/MapNode.h"

class MapParser
{
private:

public:
	MapParser();
	~MapParser();

	std::map<int, MapNode> parseMap(int x0, int y0, int x1, int y1);
};

#endif
