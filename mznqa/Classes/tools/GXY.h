#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_TOOLS_GXY_H_
#define MZNQA_CLASSES_TOOLS_GXY_H_

struct GXY
{
	int x;
	int y;

	GXY(int x, int y) :
		x(x), y(y)
	{}

	~GXY()
	{}
};

#endif