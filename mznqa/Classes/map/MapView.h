#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MAP_MAPVIEW_H_
#define MZNQA_CLASSES_MAP_MAPVIEW_H_

#include "map/MapController.h"

class MapView
{
private:
	int centerGX;
	int centerGY;

	int hDelta;
	int vDelta;

	static const int hDeltaMin = 7;
	static const int vDeltaMin = 10;

public:
	static const int invalidXOrY = -1;

	MapView(
		int centerGX,
		int centerGY
		) :
		centerGX(centerGX),
		centerGY(centerGY),
		hDelta(hDeltaMin),
		vDelta(vDelta)
	{
	}
	~MapView();

	// 检查当前视窗中点是否合法
	bool checkCenter()
	{
		return (0 <= centerGX - hDelta &&
			centerGX + hDelta < MapController::mapNodecountHorizontal &&
			0 <= centerGY - vDelta &&
			centerGY + hDelta < MapController::mapNodecountVertical
			);
	}

	int getCenterGX()
	{
		return centerGX;
	}

	int getCenterGY()
	{
		return centerGY;
	}

	int getViewRangeXBegin()
	{
		if (checkCenter())
			return centerGX - hDelta;
		else
			return invalidXOrY;
	}

	int getViewRangeXEnd()
	{
		if (checkCenter())
			return centerGX + hDelta;
		else
			return invalidXOrY;
	}

	int getViewRangeYBegin()
	{
		if (checkCenter())
			return centerGY - vDelta;
		else
			return invalidXOrY;
	}

	int getViewRangeYEnd()
	{
		if (checkCenter())
			return centerGY + vDelta;
		else
			return invalidXOrY;
	}

	bool moveUp()
	{
		int temp = centerGY;
		--centerGY;
		if (checkCenter())
			return true;
		else
		{
			centerGY = temp;
			return false;
		}
	}

	bool moveDown()
	{
		int temp = centerGY;
		++centerGY;
		if (checkCenter())
			return true;
		else
		{
			centerGY = temp;
			return false;
		}
	}

	bool moveLeft()
	{
		int temp = centerGX;
		--centerGX;
		if (checkCenter())
			return true;
		else
		{
			centerGX = temp;
			return false;
		}
	}

	bool moveRight()
	{
		int temp = centerGX;
		++centerGX;
		if (checkCenter())
			return true;
		else
		{
			centerGX = temp;
			return false;
		}
	}
};

#endif
