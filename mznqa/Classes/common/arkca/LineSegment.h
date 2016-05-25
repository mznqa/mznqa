/*!
 * \file	D:\Projects\mznqa\mznqa\Classes\common\arkca\LineSegment.h
 *
 * \brief	定义结构体 ArKCa::LineSegment
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMMON_ARKCA_LINESEGMENT_H_
#define MZNQA_CLASSES_COMMON_ARKCA_LINESEGMENT_H_

#include "common/arkca/Vector2.h"

namespace ArKCa
{
	/*!
	 * \struct	LineSegment
	 *
	 * \brief	线段结构体
	 *
	 * \tparam	NumType	数值类型
	 */
	template <typename NumType>
	struct LineSegment
	{
		/*! \brief	第一个端点 */
		ArKCa::Vector2<NumType> firstEndingPoint;
		/*! \brief	第二个端点 */
		ArKCa::Vector2<NumType> secondEndingPoint;

		/*!
		 * \fn	LineSegment( const ArKCa::Vector2<NumType> &firstEndingPoint, const ArKCa::Vector2<NumType> &secondEndingPoint )
		 *
		 * \brief	构造函数
		 *
		 * \param	firstEndingPoint 	指定线段端点一
		 * \param	secondEndingPoint	指定线段端点二
		 */
		LineSegment(
			const ArKCa::Vector2<NumType> &firstEndingPoint,
			const ArKCa::Vector2<NumType> &secondEndingPoint
			) :
			firstEndingPoint(firstEndingPoint),
			secondEndingPoint(secondEndingPoint)
		{
		}

		/*!
		 * \fn	LineSegment(const LineSegment &lineSegment)
		 *
		 * \brief	拷贝构造函数
		 *
		 */
		LineSegment(const LineSegment &lineSegment) :
			firstEndingPoint(lineSegment.firstEndingPoint),
			secondEndingPoint(lineSegment.secondEndingPoint)
		{
		}

		/*!
		 * \fn	LineSegment& operator=(const LineSegment &lineSegment)
		 *
		 * \brief	拷贝赋值运算符
		 *
		 */
		LineSegment& operator=(const LineSegment &lineSegment)
		{
			this->firstEndingPoint = lineSegment.firstEndingPoint;
			this->secondEndingPoint = lineSegment.secondEndingPoint;
			return *this;
		}

		/*!
		 * \fn	void set( const ArKCa::Vector2<NumType> &firstEndingPoint, const ArKCa::Vector2<NumType> &secondEndingPoint )
		 *
		 * \brief	设置函数
		 *
		 * \param	firstEndingPoint 	指定线段端点一
		 * \param	secondEndingPoint	指定线段端点二
		 */
		void set(
			const ArKCa::Vector2<NumType> &firstEndingPoint,
			const ArKCa::Vector2<NumType> &secondEndingPoint
			)
		{
			this->firstEndingPoint = firstEndingPoint;
			this->secondEndingPoint = secondEndingPoint;
		}

		/*!
		 * \fn	bool isContains(const ArKCa::Vector2<NumType> &position)const
		 *
		 * \brief	判断指定点是否在线段上
		 *
		 */
		bool isContains(const ArKCa::Vector2<NumType> &position)const
		{
			if (this->firstEndingPoint.x == this->secondEndingPoint.x)
			{
				if (position.x != this->firstEndingPoint.x)
					return false;
				if (this->firstEndingPoint.y <= this->secondEndingPoint.y)
					return (
					firstEndingPoint.y <= position.y && position.y <= secondEndingPoint.y
					);
				else
					return (
					secondEndingPoint.y <= position.y && position.y <= firstEndingPoint.y
					);
			}
			else if (this->firstEndingPoint.y == this->secondEndingPoint.y)
			{
				if (position.y != this->firstEndingPoint.y)
					return false;
				if (this->firstEndingPoint.x <= this->secondEndingPoint.x)
					return (
					firstEndingPoint.x <= position.x && position.x <= secondEndingPoint.x
					);
				else
					return (
					secondEndingPoint.x <= position.x && position.x <= firstEndingPoint.x
					);
			}
			else
			{
				return (
					((this->firstEndingPoint.x - position.x) / (this->firstEndingPoint.y - position.y)) ==
					((this->secondEndingPoint.x - position.x) / (this->secondEndingPoint.y - position.y))
					);
			}
		}
	};
}

#endif
