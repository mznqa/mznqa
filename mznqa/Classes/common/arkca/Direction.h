/*!
 * \file	Classes\common\arkca\Direction.h
 *
 * \brief	定义枚举 Direction4
 */

#pragma execution_character_set("utf-8")

#ifndef  MZNQA_CLASSES_COMMON_ARKCA_DIRECTION_H_
#define MZNQA_CLASSES_COMMON_ARKCA_DIRECTION_H_

namespace ArKCa
{
	/*!
	 * \enum	Direction4
	 *
	 * \brief	四方向枚举值
	 */
	enum Direction4
	{
		Direction4_None,	///< 无效方向
		Direction4_Up,		///< 上方向
		Direction4_Right,	///< 右方向
		Direction4_Down,	///< 下方向
		Direction4_Left		///< 左方向
	};
}

#endif