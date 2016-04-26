#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_TOOLS_GRECT_H_
#define MZNQA_CLASSES_TOOLS_GRECT_H_

struct GRect
{
	int leftTopGX;
	int leftTopGY;
	int rightBottomGX;
	int rightBottomGY;

	GRect(
		int leftTopGX,
		int leftTopGY,
		int rightBottomGX,
		int rightBottomGY
		) :
		leftTopGX(leftTopGX),
		leftTopGY(leftTopGY),
		rightBottomGX(rightBottomGX),
		rightBottomGY(rightBottomGY)
	{}
	~GRect()
	{}
};

#endif
