/*!
 * \file	Classes\common\arkca\Vector2.h
 *
 * \brief	������ Vector2
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
	 * \tparam	NumType	��ά��������ֵ����
	 */
	template <typename NumType>
	struct Vector2
	{
		/*! \brief	������ */
		NumType x;
		/*! \brief	������ */
		NumType y;

		/*!
		 * \fn	Vector2(NumType x, NumType y)
		 *
		 * \brief	���캯��
		 *
		 * \param	x	ָ�������ĺ���ֵ
		 * \param	y	ָ������������ֵ
		 */
		Vector2(NumType x, NumType y) :
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
			return &this;
		}

		/*!
		 * \fn	void set(NumType x, NumType y)
		 *
		 * \brief	����������ֵ
		 *
		 * \param	x	ָ������������
		 * \param	y	ָ������������
		 */
		void set(NumType x, NumType y)
		{
			this->x = x;
			this->y = y;
		}
	};
}
#endif
