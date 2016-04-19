#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_GLOBALFUN_H_
#define MZNQA_CLASSES_ENGINE_GLOBALFUN_H_

#include "define/GlobalDefine.h"

float gX2CartesianX(int gX)
{
	return (gX * MAP_CELL_SIZE);
}

float gY2CartesianY(int gY)
{
	return (-gY * MAP_CELL_SIZE);
}

#endif
