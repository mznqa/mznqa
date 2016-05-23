/*!
 * \file	Classes\common\arkca\Vector2.h
 *
 * \brief	������ ArKCa::Vector2
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMMON_ARKCA_VECTOR2_H_
#define MZNQA_CLASSES_COMMON_ARKCA_VECTOR2_H_

namespace ArKCa
{
	/*!
	 * \struct	Vector2
	 *
	 * \brief	��ά�����ṹ��
	 *
	 * \tparam	NumType		��ά�����ĺ���ֵ����
	 */
	template <typename NumType>
	struct Vector2
	{
		/*! \brief	������ */
		NumType x;
		/*! \brief	������ */
		NumType y;

		/*!
		 * \fn	Vector2(const NumType &x, const NumType &y)
		 *
		 * \brief	���캯��
		 *
		 * \param	x	ָ�������ĺ���ֵ
		 * \param	y	ָ������������ֵ
		 */
		Vector2(const NumType &x, const NumType &y) :
			x(x),
			y(y)
		{}

		/*!
		 * \fn	Vector2(const Vector2 &vector2)
		 *
		 * \brief	�������캯��
		 *
		 * \param	vector2	ָ��һ�� Vector2
		 */
		Vector2(const Vector2 &vector2) :
			x(vector2.x),
			y(vector2.y)
		{}

		/*!
		 * \fn	Vector2& operator=(const Vector2 &vector2)
		 *
		 * \brief	������ֵ�����
		 *
		 * \param	vector2	ָ��һ�� Vector2
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
		 * \brief	����������ֵ
		 *
		 * \param	x	ָ�������ĺ�����
		 * \param	y	ָ��������������
		 */
		void set(const NumType &x, const NumType &y)
		{
			this->x = x;
			this->y = y;
		}

		/*!
		 * \fn	Vector2& operator+=(const Vector2 &rhs)
		 *
		 * \brief	�ӷ�����
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
		 * \brief	��������
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
		 * \brief	��������
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
		 * \brief	��������
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
	 * \brief	��������
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
	 * \brief	���������
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
	 * \brief	�ӷ�����
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
	 * \brief	��������
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
	 * \brief	��������
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
	 * \brief	��������
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
	 * \brief	��������
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
	 * \brief	��������
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
