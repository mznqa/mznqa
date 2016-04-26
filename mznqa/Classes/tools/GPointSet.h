#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_TOOLS_GPOINTSET_H_
#define MZNQA_CLASSES_TOOLS_GPOINTSET_H_

#include <vector>

#include "tools/GXY.h"

struct GPointSet
{
	std::vector<GXY> pointSet;

	GPointSet()
	{
	}

	~GPointSet()
	{
	}

	void insert(int x, int y)
	{
		pointSet.push_back(GXY(x, y));
	}

	void insert(const GXY &gXY)
	{
		pointSet.push_back(gXY);
	}

	void clear()
	{
		pointSet.clear();
	}

	bool empty()
	{
		return pointSet.empty();
	}
};

#endif
