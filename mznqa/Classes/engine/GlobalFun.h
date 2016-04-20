#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_GLOBALFUN_H_
#define MZNQA_CLASSES_ENGINE_GLOBALFUN_H_

#include "define/GlobalDefine.h"
#include "map/MapView.h"

float gX2CartesianX(int gX)
{
	return (-MapView::Instance()->getLeftTopGX()*MAP_CELL_SIZE + gX * MAP_CELL_SIZE);
}

float gY2CartesianY(int gY)
{
	return (DESIGNRESOLUTIONSIZE_HEIGHT + MapView::Instance()->getLeftTopGY()*MAP_CELL_SIZE - gY*MAP_CELL_SIZE);
}

#endif
