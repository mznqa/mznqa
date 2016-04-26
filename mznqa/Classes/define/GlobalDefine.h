/*!
 * \file	Classes\define\GlobalDefine.h
 *
 * \brief	定义一些全局量
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_DEFINE_GLOBALDEFINE_H_
#define MZNQA_CLASSES_DEFINE_GLOBALDEFINE_H_

#include "cocos2d.h"

/*!
 * \def	SCREENSIZE_WIDTH
 *
 * \brief	屏幕尺寸-宽度
 *
 */
#define SCREENSIZE_WIDTH (cocos2d::Director::getInstance()->getOpenGLView()->getFrameSize().width)

/*!
 * \def	SCREENSIZE_HEIGHT
 *
 * \brief	屏幕尺寸-高度
 *
 */
#define SCREENSIZE_HEIGHT (cocos2d::Director::getInstance()->getOpenGLView()->getFrameSize().height)

/*!
 * \def	DESIGNRESOLUTIONSIZE_WIDTH
 *
 * \brief	设计尺寸-宽度
 *
 */
#define DESIGNRESOLUTIONSIZE_WIDTH 1920.0f

/*!
 * \def	DESIGNRESOLUTIONSIZE_HEIGHT
 *
 * \brief	设计尺寸-高度
 *
 */
#define DESIGNRESOLUTIONSIZE_HEIGHT 1080.0f

/*!
 * \def	DESIGNRESOLUTIONSIZE_SCREENCENTER_HORIZONTAL
 *
 * \brief	设计尺寸的屏幕中心的横坐标
 *
 */
#define DESIGNRESOLUTIONSIZE_SCREENCENTER_HORIZONTAL 960.0f

/*!
 * \def	DESIGNRESOLUTIONSIZE_SCREENCENTER_VERTICAL
 *
 * \brief	设计尺寸的屏幕中心的纵坐标
 *
 */
#define DESIGNRESOLUTIONSIZE_SCREENCENTER_VERTICAL 540.0f

/*!
 * \def	MAP_CELL_SIZE
 *
 * \brief	地图块的大小
 *
 */
#define MAP_CELL_SIZE 64.0f

/*!
 * \def	MAP_CELL_SIZE_HALF
 *
 * \brief	地图块大小的一半
 *
 */
#define MAP_CELL_SIZE_HALF 32.0f

/*!
 * \def	TIME_INVALIDVALUE
 *
 * \brief	无效的时间值
 *
 */
#define TIME_INVALIDVALUE -1.0f

/*!
 * \def	TIME_GLOBALMAP_MOVE();
 *
 * \brief	全局地图移动一格所需的时间
 *
 */
#define TIME_GLOBALMAP_MOVE 0.1f

#endif
