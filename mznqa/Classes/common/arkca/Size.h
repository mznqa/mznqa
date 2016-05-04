/*!
 * \file	Classes\common\arkca\Size.h
 *
 * \brief	定义类 ArKCa::Size
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMMON_ARKCA_SIZE_H_
#define MZNQA_CLASSES_COMMON_ARKCA_SIZE_H_

namespace ArKCa
{
	/*!
	 * \struct	Size
	 *
	 * \brief	适用于矩形的尺寸结构体
	 *
	 * \tparam	NumType	尺寸长宽值的类型
	 */
	template <typename NumType>
	struct Size
	{
		/*! \brief	宽度 */
		NumType width;
		/*! \brief	高度 */
		NumType height;

		/*!
		 * \fn	Size(NumType width, NumType height)
		 *
		 * \brief	默认构造函数
		 *
		 * \param	width 	指定宽度值
		 * \param	height	指定高度值
		 */
		Size(NumType width, NumType height) :
			width(width),
			height(height)
		{
		}

		/*!
		 * \fn	Size(const Size &size)
		 *
		 * \brief	拷贝构造函数
		 *
		 * \param	size	指定一个 Size
		 */
		Size(const Size &size) :
			width(size.width),
			height(size.height)
		{
		}

		/*!
		 * \fn	Size& operator=(const Size &size)
		 *
		 * \brief	拷贝赋值运算符
		 *
		 * \param	size	指定一个 Size
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
		 * \brief	设置尺寸
		 *
		 * \param	width 	指定宽度值
		 * \param	height	指定高度值
		 */
		void set(NumType width, NumType height)
		{
			this->width = width;
			this->height = height;
		}
	};
}

#endif