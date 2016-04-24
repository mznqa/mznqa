/*!
 * \file	Classes\engine\GlobalFun.h
 *
 * \brief	����һЩΪȫ��ʹ�õķ���
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_GLOBALFUN_H_
#define MZNQA_CLASSES_ENGINE_GLOBALFUN_H_

#include "define/GlobalDefine.h"
#include "map/MapView.h"

/*!
 * \fn	static float gX2CartesianX(int gX)
 *
 * \brief	���ݸ����ĵ�ͼ���������������Ļ�ĺ�����
 *
 * \param	gX	ָ����ͼ������
 *
 * \return	��Ļ������
 */
static float gX2CartesianX(int gX)
{
	return (-MapView::Instance()->getLeftTopGX()*MAP_CELL_SIZE + gX * MAP_CELL_SIZE);
}

/*!
 * \fn	static float gY2CartesianY(int gY)
 *
 * \brief	���ݸ����ĵ�ͼ���������������Ļ��������
 *
 * \param	gY	ָ����ͼ������
 *
 * \return	��Ļ������
 */
static float gY2CartesianY(int gY)
{
	return (DESIGNRESOLUTIONSIZE_HEIGHT + MapView::Instance()->getLeftTopGY()*MAP_CELL_SIZE - gY*MAP_CELL_SIZE);
}

#endif
