/*!
 * \file	Classes\common\arkca\Rectangle.h
 *
 * \brief	����ṹ�� ArKCa::Rectangle
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
	 * \brief	����
	 *
	 * \tparam	NumType	ָ����ֵ������Ϊ�����ڵ����������
	 */
	template <typename NumType>
	struct Rectangle
	{
		/*! \brief	���Ͻǵĵ����� */
		ArKCa::Vector2<NumType> leftTop;
		/*! \brief	���Ͻǵĵ����� */
		ArKCa::Vector2<NumType> rightBottom;
		/*! \brief	���εĳߴ���Ϣ */
		ArKCa::Size<NumType> size;

		/*!
		 * \fn	Rectangle(const ArKCa::Vector2<NumType> &leftTop, const ArKCa::Vector2<NumType> &rightBottom)
		 *
		 * \brief	���캯��
		 *
		 * \param	leftTop	   	ָ�����Ͻǵ������
		 * \param	rightBottom	ָ�����½ǵ������
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
		 * \brief	���캯��
		 *
		 * \param	xRange	ָ�����������ֵ����
		 * \param	yRange	ָ�����������ֵ����
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
		 * \brief	�������캯��
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
		 * \brief	������ֵ�����
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
		 * \brief	�жϸ�����������ֵ�Ƿ�����ھ�����
		 *
		 * \param	pointX	ָ�����жϵĺ�������ֵ
		 *
		 */
		bool isContainsX(const NumType &pointX)const
		{
			return (leftTop.x <= pointX && pointX <= rightBottom.x);
		}

		/*!
		 * \fn	bool isContainsY(const NumType &pointY)const
		 *
		 * \brief	�жϸ�������������ֵ�Ƿ�����ھ�����
		 *
		 * \param	pointY	ָ�����жϵ���������ֵ
		 *
		 */
		bool isContainsY(const NumType &pointY)const
		{
			return (leftTop.y <= pointY && pointY <= rightBottom.y);
		}

		/*!
		 * \fn	bool isContains(const ArKCa::Vector2<NumType> &point)const
		 *
		 * \brief	�жϸ������Ƿ�����ھ�����
		 *
		 * \param	point	ָ�����жϵĵ������
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