/*!
 * \file	Classes\engine\GlobalFun.h
 *
 * \brief	定义一些为全局使用的方法
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_GLOBALFUN_H_
#define MZNQA_CLASSES_ENGINE_GLOBALFUN_H_

#include "define/GlobalDefine.h"
#include "map/MapView.h"

/*!
 * \fn	static float gX2CartesianX(int gX)
 *
 * \brief	根据给定的地图横坐标计算其在屏幕的横坐标
 *
 * \param	gX	指定地图横坐标
 *
 * \return	屏幕横坐标
 */
static float gX2CartesianX(int gX)
{
	return ((gX - MapView::Instance()->getLeftTopGX())*MAP_CELL_SIZE);
}

/*!
 * \fn	static float gY2CartesianY(int gY)
 *
 * \brief	根据给定的地图纵坐标计算其在屏幕的纵坐标
 *
 * \param	gY	指定地图纵坐标
 *
 * \return	屏幕纵坐标
 */
static float gY2CartesianY(int gY)
{
	return (DESIGNRESOLUTIONSIZE_HEIGHT - ((gY - MapView::Instance()->getLeftTopGY())*MAP_CELL_SIZE));
}

#endif
