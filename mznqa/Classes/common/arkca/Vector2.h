/*!
 * \file	Classes\common\arkca\Vector2.h
 *
 * \brief	定义类 ArKCa::Vector2
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMMON_ARKCA_VECTOR2_H_
#define MZNQA_CLASSES_COMMON_ARKCA_VECTOR2_H_

namespace ArKCa
{
	/*!
	 * \struct	Vector2
	 *
	 * \brief	二维向量结构体
	 *
	 * \tparam	NumType		二维向量的横纵值类型
	 */
	template <typename NumType>
	struct Vector2
	{
		/*! \brief	横向量 */
		NumType x;
		/*! \brief	纵向量 */
		NumType y;

		/*!
		 * \fn	Vector2(const NumType &x, const NumType &y)
		 *
		 * \brief	构造函数
		 *
		 * \param	x	指定向量的横向值
		 * \param	y	指定向量的纵向值
		 */
		Vector2(const NumType &x, const NumType &y) :
			x(x),
			y(y)
		{}

		/*!
		 * \fn	Vector2(const Vector2 &vector2)
		 *
		 * \brief	拷贝构造函数
		 *
		 * \param	vector2	指定一个 Vector2
		 */
		Vector2(const Vector2 &vector2) :
			x(vector2.x),
			y(vector2.y)
		{}

		/*!
		 * \fn	Vector2& operator=(const Vector2 &vector2)
		 *
		 * \brief	拷贝赋值运算符
		 *
		 * \param	vector2	指定一个 Vector2
		 *
		 */
		Vector2& operator=(const Vector2 &vector2)
		{
			x = vector2.x;
			y = vector2.y;
			return *this;
		}

		/*!
		 * \fn	void set(const NumType &x, const NumType &y)
		 *
		 * \brief	设置向量的值
		 *
		 * \param	x	指定向量的横向量
		 * \param	y	指定向量的纵向量
		 */
		void set(const NumType &x, const NumType &y)
		{
			this->x = x;
			this->y = y;
		}

		/*!
		 * \fn	Vector2& operator+=(const Vector2 &rhs)
		 *
		 * \brief	加法运算
		 *
		 */
		Vector2& operator+=(const Vector2 &rhs)
		{
			this->x += rhs.x;
			this->y += rhs.y;
			return *this;
		}

		/*!
		 * \fn	Vector2& operator-=(const Vector2 &rhs)
		 *
		 * \brief	减法运算
		 *
		 */
		Vector2& operator-=(const Vector2 &rhs)
		{
			this->x -= rhs.x;
			this->y -= rhs.y;
			return *this;
		}

		/*!
		 * \fn	Vector2& operator*=(const NumType &rhs)
		 *
		 * \brief	数乘运算
		 *
		 */
		Vector2& operator*=(const NumType &rhs)
		{
			this->x *= rhs;
			this->y *= rhs;
			return *this;
		}

		/*!
		 * \fn	Vector2& operator/=(const NumType &rhs)
		 *
		 * \brief	数除运算
		 *
		 */
		Vector2& operator/=(const NumType &rhs)
		{
			this->x /= rhs;
			this->y /= rhs;
			return *this;
		}
	};

	/*!
	 * \fn	template <typename NumType> bool operator==(const Vector2<NumType> &lhs, const Vector2<NumType> &rhs)
	 *
	 * \brief	相等运算符
	 *
	 */
	template <typename NumType>
	bool operator==(const Vector2<NumType> &lhs, const Vector2<NumType> &rhs)
	{
		return (lhs.x == rhs.x && lhs.y == rhs.y);
	}

	/*!
	 * \fn	template <typename NumType> bool operator!=(const Vector2<NumType> &lhs, const Vector2<NumType> &rhs)
	 *
	 * \brief	不等运算符
	 *
	 */
	template <typename NumType>
	bool operator!=(const Vector2<NumType> &lhs, const Vector2<NumType> &rhs)
	{
		return (lhs.x != rhs.x || lhs.y != rhs.y);
	}

	/*!
	 * \fn	template <typename NumType> Vector2<NumType> operator+(const Vector2<NumType> &lhs, const Vector2<NumType> &rhs)
	 *
	 * \brief	加法运算
	 *
	 */
	template <typename NumType>
	Vector2<NumType> operator+(const Vector2<NumType> &lhs, const Vector2<NumType> &rhs)
	{
		Vector2<NumType> vector2 = lhs;
		vector2 += rhs;
		return vector2;
	}

	/*!
	 * \fn	template <typename NumType> Vector2<NumType> operator-(const Vector2<NumType> &lhs, const Vector2<NumType> &rhs)
	 *
	 * \brief	减法运算
	 *
	 */
	template <typename NumType>
	Vector2<NumType> operator-(const Vector2<NumType> &lhs, const Vector2<NumType> &rhs)
	{
		Vector2<NumType> vector2 = lhs;
		vector2 -= rhs;
		return vector2;
	}

	/*!
	 * \fn	template <typename NumType> Vector2<NumType> operator*(const Vector2<NumType> &lhs, const NumType &rhs)
	 *
	 * \brief	数乘运算
	 *
	 */
	template <typename NumType>
	Vector2<NumType> operator*(const Vector2<NumType> &lhs, const NumType &rhs)
	{
		Vector2<NumType> vector2 = lhs;
		vector2 *= rhs;
		return vector2;
	}

	/*!
	 * \fn	template <typename NumType> Vector2<NumType> operator*(const NumType &lhs, const Vector2<NumType> &rhs)
	 *
	 * \brief	数乘运算
	 *
	 */
	template <typename NumType>
	Vector2<NumType> operator*(const NumType &lhs, const Vector2<NumType> &rhs)
	{
		Vector2<NumType> vector2 = rhs;
		vector2 *= lhs;
		return vector2;
	}

	/*!
	 * \fn	template <typename NumType> Vector2<NumType> operator/(const Vector2<NumType> &lhs, const NumType &rhs)
	 *
	 * \brief	数除运算
	 *
	 */
	template <typename NumType>
	Vector2<NumType> operator/(const Vector2<NumType> &lhs, const NumType &rhs)
	{
		Vector2<NumType> vector2 = lhs;
		vector2 /= rhs;
		return vector2;
	}

	/*!
	 * \fn	template <typename NumType> Vector2<NumType> operator/(const NumType &lhs, const Vector2<NumType> &rhs)
	 *
	 * \brief	数除运算
	 *
	 */
	template <typename NumType>
	Vector2<NumType> operator/(const NumType &lhs, const Vector2<NumType> &rhs)
	{
		Vector2<NumType> vector2 = rhs;
		vector2 /= lhs;
		return vector2;
	}
}
#endif
