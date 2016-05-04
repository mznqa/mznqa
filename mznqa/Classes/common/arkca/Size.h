/*!
 * \file	Classes\common\arkca\Size.h
 *
 * \brief	������ ArKCa::Size
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMMON_ARKCA_SIZE_H_
#define MZNQA_CLASSES_COMMON_ARKCA_SIZE_H_

namespace ArKCa
{
	/*!
	 * \struct	Size
	 *
	 * \brief	�����ھ��εĳߴ�ṹ��
	 *
	 * \tparam	NumType	�ߴ糤��ֵ������
	 */
	template <typename NumType>
	struct Size
	{
		/*! \brief	��� */
		NumType width;
		/*! \brief	�߶� */
		NumType height;

		/*!
		 * \fn	Size(NumType width, NumType height)
		 *
		 * \brief	Ĭ�Ϲ��캯��
		 *
		 * \param	width 	ָ�����ֵ
		 * \param	height	ָ���߶�ֵ
		 */
		Size(NumType width, NumType height) :
			width(width),
			height(height)
		{
		}

		/*!
		 * \fn	Size(const Size &size)
		 *
		 * \brief	�������캯��
		 *
		 * \param	size	ָ��һ�� Size
		 */
		Size(const Size &size) :
			width(size.width),
			height(size.height)
		{
		}

		/*!
		 * \fn	Size& operator=(const Size &size)
		 *
		 * \brief	������ֵ�����
		 *
		 * \param	size	ָ��һ�� Size
		 *
		 */
		Size& operator=(const Size &size)
		{
			this->width = size.width;
			this->height = size.height;
			return *this;
		}

		/*!
		 * \fn	void set(NumType width, NumType height)
		 *
		 * \brief	���óߴ�
		 *
		 * \param	width 	ָ�����ֵ
		 * \param	height	ָ���߶�ֵ
		 */
		void set(NumType width, NumType height)
		{
			this->width = width;
			this->height = height;
		}
	};
}

#endif