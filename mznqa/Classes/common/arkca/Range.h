/*!
 * \file	Classes\common\arkca\Range.h
 *
 * \brief	定义结构体 ArKCa::Range
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMMON_ARKCA_RANGE_H_
#define MZNQA_CLASSES_COMMON_ARKCA_RANGE_H_

namespace ArKCa
{
	/*!
	 * \struct	Range
	 *
	 * \brief	范围
	 *
	 * \tparam	NumType	指定最大最小值类型
	 */
	template <typename NumType>
	struct Range
	{
		/*! \brief	最小值 */
		NumType min;
		/*! \brief	最大值 */
		NumType max;

		/*!
		 * \fn	Range(const NumType &min, const NumType &max)
		 *
		 * \brief	构造函数
		 *
		 * \param	min	指定最小值
		 * \param	max	指定最大值
		 */
		Range(const NumType &min, const NumType &max) :
			min(min),
			max(max)
		{
		}

		/*!
		 * \fn	Range(const Range &range)
		 *
		 * \brief	拷贝构造函数
		 *
		 */
		Range(const Range &range) :
			min(min),
			max(max)
		{
		}

		/*!
		 * \fn	Range& operator=(const Range &range)
		 *
		 * \brief	拷贝赋值运算符
		 *
		 */
		Range& operator=(const Range &range)
		{
			this->min = range.min;
			this->max = range.max;
			return *this;
		}

		/*!
		 * \fn	~Range()
		 *
		 * \brief	析构函数
		 *
		 */
		~Range()
		{
		}

		/*!
		 * \fn	void set(const NumType &min, const NumType &max)
		 *
		 * \brief	设置范围的最小值和最大值
		 *
		 * \param	min	指定最小值
		 * \param	max	指定最大值
		 */
		void set(const NumType &min, const NumType &max)
		{
			this->min = min;
			this->max = max;
		}

		/*!
		 * \fn	bool isInclude(const NumType &num)const
		 *
		 * \brief	判断是否在该范围内
		 *
		 * \param	num	指定待判断的数值
		 *
		 */
		bool isInclude(const NumType &num)const
		{
			return (min <= num && num <= max);
		}
	};
}

#endif
