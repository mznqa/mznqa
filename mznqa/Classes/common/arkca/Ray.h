/*!
 * \file	Classes\common\arkca\Ray.h
 *
 * \brief	定义结构体 ArKCa::Ray
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMMON_ARKCA_RAY_H_
#define MZNQA_CLASSES_COMMON_ARKCA_RAY_H_

#include "common/arkca/Vector2.h"
#include "common/arkca/LineSegment.h"

namespace ArKCa
{
	/*!
	 * \struct	Ray
	 *
	 * \brief	射线
	 *
	 */
	struct Ray
	{
		/*! \brief	起点坐标 */
		ArKCa::Vector2<double> origin;
		/*! \brief	方向向量 */
		ArKCa::Vector2<double> directionVector;

		/*!
		 * \fn	Ray( const ArKCa::Vector2<double> &origin, const ArKCa::Vector2<double> &directionVector )
		 *
		 * \brief	构造函数
		 *
		 * \param	origin		   	指定起点坐标
		 * \param	directionVector	指定方向向量
		 */
		Ray(
			const ArKCa::Vector2<double> &origin,
			const ArKCa::Vector2<double> &directionVector
			) :
			origin(origin),
			directionVector(directionVector)
		{
			this->directionVector.normalize();
		}

		/*!
		 * \fn	Ray(const Ray &ray)
		 *
		 * \brief	拷贝构造函数
		 *
		 */
		Ray(const Ray &ray) :
			origin(ray.origin),
			directionVector(ray.directionVector)
		{
			this->directionVector.normalize();
		}

		/*!
		 * \fn	Ray& operator=(const Ray &ray)
		 *
		 * \brief	拷贝复制运算符
		 *
		 */
		Ray& operator=(const Ray &ray)
		{
			this->origin = ray.origin;
			this->directionVector = ray.directionVector;
			this->directionVector.normalize();
			return *this;
		}

		/*!
		 * \fn	template <typename NumType> ArKCa::Vector2<double> getIntersection(const ArKCa::LineSegment<NumType> &lineSegment)const
		 *
		 * \brief	求与线段的交点
		 *
		 * \tparam	NumType	数值类型
		 * \param	lineSegment	指定线段
		 *
		 * \return	返回交点
		 */
		template <typename NumType>
		ArKCa::Vector2<double> getIntersection(const ArKCa::LineSegment<NumType> &lineSegment)const
		{
			Ray segment2Ray(
				ArKCa::Vector2<double>(lineSegment.firstEndingPoint.x, lineSegment.firstEndingPoint.y),
				ArKCa::Vector2<double>(
				lineSegment.secondEndingPoint.x - lineSegment.firstEndingPoint.x,
				lineSegment.secondEndingPoint.y - lineSegment.firstEndingPoint.x
				)
				);

			double tSeg = (
				this->directionVector.x*(segment2Ray.origin.y - this->origin.y) +
				this->directionVector.y*(this->origin.x - segment2Ray.origin.x)
				) / (
				segment2Ray.directionVector.x*this->directionVector.y -
				segment2Ray.directionVector.y*this->directionVector.x
				);

			auto result = segment2Ray.origin + segment2Ray.directionVector * tSeg;
			if (lineSegment.isContains(ArKCa::Vector2<NumType>(result.x, result.y)))
				return result;
			else
				return ArKCa::Vector2<double>(0.0, 0.0);
		}
	};
}

#endif
