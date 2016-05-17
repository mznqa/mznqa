/*!
 * \file	Classes\common\arkca\Range.h
 *
 * \brief	����ṹ�� ArKCa::Range
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMMON_ARKCA_RANGE_H_
#define MZNQA_CLASSES_COMMON_ARKCA_RANGE_H_

namespace ArKCa
{
	/*!
	 * \struct	Range
	 *
	 * \brief	��Χ
	 *
	 * \tparam	NumType	ָ�������Сֵ����
	 */
	template <typename NumType>
	struct Range
	{
		/*! \brief	��Сֵ */
		NumType min;
		/*! \brief	���ֵ */
		NumType max;

		/*!
		 * \fn	Range(const NumType &min, const NumType &max)
		 *
		 * \brief	���캯��
		 *
		 * \param	min	ָ����Сֵ
		 * \param	max	ָ�����ֵ
		 */
		Range(const NumType &min, const NumType &max) :
			min(min),
			max(max)
		{
		}

		/*!
		 * \fn	Range(const Range &range)
		 *
		 * \brief	�������캯��
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
		 * \brief	������ֵ�����
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
		 * \brief	��������
		 *
		 */
		~Range()
		{
		}

		/*!
		 * \fn	void set(const NumType &min, const NumType &max)
		 *
		 * \brief	���÷�Χ����Сֵ�����ֵ
		 *
		 * \param	min	ָ����Сֵ
		 * \param	max	ָ�����ֵ
		 */
		void set(const NumType &min, const NumType &max)
		{
			this->min = min;
			this->max = max;
		}

		/*!
		 * \fn	bool isInclude(const NumType &num)const
		 *
		 * \brief	�ж��Ƿ��ڸ÷�Χ��
		 *
		 * \param	num	ָ�����жϵ���ֵ
		 *
		 */
		bool isInclude(const NumType &num)const
		{
			return (min <= num && num <= max);
		}
	};
}

#endif
