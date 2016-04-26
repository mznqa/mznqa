/*!
 * \file	Classes\define\GlobalDefine.h
 *
 * \brief	����һЩȫ����
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_DEFINE_GLOBALDEFINE_H_
#define MZNQA_CLASSES_DEFINE_GLOBALDEFINE_H_

#include "cocos2d.h"

/*!
 * \def	SCREENSIZE_WIDTH
 *
 * \brief	��Ļ�ߴ�-���
 *
 */
#define SCREENSIZE_WIDTH (cocos2d::Director::getInstance()->getOpenGLView()->getFrameSize().width)

/*!
 * \def	SCREENSIZE_HEIGHT
 *
 * \brief	��Ļ�ߴ�-�߶�
 *
 */
#define SCREENSIZE_HEIGHT (cocos2d::Director::getInstance()->getOpenGLView()->getFrameSize().height)

/*!
 * \def	DESIGNRESOLUTIONSIZE_WIDTH
 *
 * \brief	��Ƴߴ�-���
 *
 */
#define DESIGNRESOLUTIONSIZE_WIDTH 1920.0f

/*!
 * \def	DESIGNRESOLUTIONSIZE_HEIGHT
 *
 * \brief	��Ƴߴ�-�߶�
 *
 */
#define DESIGNRESOLUTIONSIZE_HEIGHT 1080.0f

/*!
 * \def	DESIGNRESOLUTIONSIZE_SCREENCENTER_HORIZONTAL
 *
 * \brief	��Ƴߴ����Ļ���ĵĺ�����
 *
 */
#define DESIGNRESOLUTIONSIZE_SCREENCENTER_HORIZONTAL 960.0f

/*!
 * \def	DESIGNRESOLUTIONSIZE_SCREENCENTER_VERTICAL
 *
 * \brief	��Ƴߴ����Ļ���ĵ�������
 *
 */
#define DESIGNRESOLUTIONSIZE_SCREENCENTER_VERTICAL 540.0f

/*!
 * \def	MAP_CELL_SIZE
 *
 * \brief	��ͼ��Ĵ�С
 *
 */
#define MAP_CELL_SIZE 64.0f

/*!
 * \def	MAP_CELL_SIZE_HALF
 *
 * \brief	��ͼ���С��һ��
 *
 */
#define MAP_CELL_SIZE_HALF 32.0f

/*!
 * \def	TIME_INVALIDVALUE
 *
 * \brief	��Ч��ʱ��ֵ
 *
 */
#define TIME_INVALIDVALUE -1.0f

/*!
 * \def	TIME_GLOBALMAP_MOVE();
 *
 * \brief	ȫ�ֵ�ͼ�ƶ�һ�������ʱ��
 *
 */
#define TIME_GLOBALMAP_MOVE 0.1f

#endif
