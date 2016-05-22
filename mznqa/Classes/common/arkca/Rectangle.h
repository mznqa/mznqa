/*!
 * \file	Classes\common\arkca\Rectangle.h
 *
 * \brief	定义结构体 ArKCa::Rectangle
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMMON_ARKCA_RECTANGLE_H_
#define MZNQA_CLASSES_COMMON_ARKCA_RECTANGLE_H_

#include "common/arkca/Vector2.h"
#include "common/arkca/Range.h"
#include "common/arkca/Size.h"

namespace ArKCa
{
	/*!
	 * \struct	Rectangle
	 *
	 * \brief	矩形
	 *
	 * \tparam	NumType	指定数值类型作为矩形内点坐标的类型
	 */
	template <typename NumType>
	struct Rectangle
	{
		/*! \brief	左上角的点坐标 */
		ArKCa::Vector2<NumType> leftTop;
		/*! \brief	右上角的店坐标 */
		ArKCa::Vector2<NumType> rightBottom;
		/*! \brief	矩形的尺寸信息 */
		ArKCa::Size<NumType> size;

		/*!
		 * \fn	Rectangle(const ArKCa::Vector2<NumType> &leftTop, const ArKCa::Vector2<NumType> &rightBottom)
		 *
		 * \brief	构造函数
		 *
		 * \param	leftTop	   	指定左上角点的坐标
		 * \param	rightBottom	指定右下角点的坐标
		 */
		Rectangle(const ArKCa::Vector2<NumType> &leftTop, const ArKCa::Vector2<NumType> &rightBottom) :
			leftTop(leftTop),
			rightBottom(rightBottom),
			size(rightBottom.x - leftTop.x, rightBottom.y - leftTop.y)
		{
		}

		/*!
		 * \fn	Rectangle(const ArKCa::Range<NumType> &xRange, const ArKCa::Range<NumType> &yRange)
		 *
		 * \brief	构造函数
		 *
		 * \param	xRange	指定横向的坐标值区间
		 * \param	yRange	指定纵向的坐标值区间
		 */
		Rectangle(const ArKCa::Range<NumType> &xRange, const ArKCa::Range<NumType> &yRange) :
			leftTop(xRange.min, yRange.min),
			rightBottom(xRange.max, yRange.max),
			size(xRange.max - xRange.min, yRange.max - yRange.min)
		{
		}

		/*!
		 * \fn	Rectangle(const Rectangle &rectangle)
		 *
		 * \brief	拷贝构造函数
		 *
		 */
		Rectangle(const Rectangle &rectangle) :
			leftTop(rectangle.leftTop),
			rightBottom(rectangle.rightBottom),
			size(rectangle.size)
		{
		}

		/*!
		 * \fn	Rectangle& operator=(const Rectangle &rectangle)
		 *
		 * \brief	拷贝赋值运算符
		 *
		 */
		Rectangle& operator=(const Rectangle &rectangle)
		{
			this->leftTop = rectangle.leftTop;
			this->rightBottom = rectangle.rightBottom;
			this->size = rectangle.size;
			return *this;
		}

		/*!
		 * \fn	bool isContainsX(const NumType &pointX)const
		 *
		 * \brief	判断给定横向坐标值是否包含在矩形中
		 *
		 * \param	pointX	指定待判断的横向坐标值
		 *
		 */
		bool isContainsX(const NumType &pointX)const
		{
			return (leftTop.x <= pointX && pointX <= rightBottom.x);
		}

		/*!
		 * \fn	bool isContainsY(const NumType &pointY)const
		 *
		 * \brief	判断给定的纵向坐标值是否包含在矩形中
		 *
		 * \param	pointY	指定待判断的纵向坐标值
		 *
		 */
		bool isContainsY(const NumType &pointY)const
		{
			return (leftTop.y <= pointY && pointY <= rightBottom.y);
		}

		/*!
		 * \fn	bool isContains(const ArKCa::Vector2<NumType> &point)const
		 *
		 * \brief	判断给定点是否包含在举行中
		 *
		 * \param	point	指定待判断的点的坐标
		 *
		 */
		bool isContains(const ArKCa::Vector2<NumType> &point)const
		{
			return (
				leftTop.x <= point.x && point.x <= rightBottom.x
				&&
				leftTop.y <= point.y && point.y <= rightBottom.y
				);
		}
	};
}

#endif