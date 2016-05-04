/*!
 * \file	Classes\common\arkca\Any.h
 *
 * \brief	������ ArKCa::AnyTypeBase , ArKCa::AnyType , ArKCa::Any
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMMON_ARKCA_ANY_H_
#define MZNQA_CLASSES_COMMON_ARKCA_ANY_H_

#include <memory>

namespace ArKCa
{
	/*!
	 * \class	AnyTypeBase
	 *
	 * \brief	���ڸ���ʵ�� ArKCa::Any
	 *
	 */
	class AnyTypeBase
	{
	private:

		/*!
		 * \fn	AnyTypeBase::AnyTypeBase(const AnyTypeBase &AnyTypeBase) = delete;
		 *
		 * \brief	���صĿ������캯��
		 *
		 */
		AnyTypeBase(const AnyTypeBase &AnyTypeBase) = delete;

		/*!
		 * \fn	AnyTypeBase& AnyTypeBase::operator=(const AnyTypeBase &AnyTypeBase) = delete;
		 *
		 * \brief	���صĿ�����ֵ�����
		 *
		 */
		AnyTypeBase& operator=(const AnyTypeBase &AnyTypeBase) = delete;
	public:

		/*!
		 * \fn	AnyTypeBase::AnyTypeBase()
		 *
		 * \brief	Ĭ�Ϲ��캯��
		 *
		 */
		AnyTypeBase()
		{
		}

		/*!
		 * \fn	virtual AnyTypeBase::~AnyTypeBase()
		 *
		 * \brief	��������
		 *
		 */
		virtual ~AnyTypeBase()
		{
		}

		/*!
		 * \fn	virtual AnyTypeBase* AnyTypeBase::clone()const = 0;
		 *
		 * \brief	��������
		 *
		 * \return	��������Ŀ���
		 */
		virtual AnyTypeBase* clone()const = 0;
	};

	/*!
	 * \class	AnyType
	 *
	 * \brief	���ڸ���ʵ�� ArKCa::Any
	 *
	 * \tparam	T	��������
	 */
	template <typename T>
	class AnyType : public AnyTypeBase
	{
	private:

		/*!
		 * \fn	AnyType::AnyType() = delete;
		 *
		 * \brief	���ص�Ĭ�Ϲ��캯��
		 *
		 */
		AnyType() = delete;

		/*!
		 * \fn	AnyType::AnyType(const AnyType &anyType) = delete;
		 *
		 * \brief	���صĿ������캯��
		 *
		 */
		AnyType(const AnyType &anyType) = delete;

		/*!
		 * \fn	AnyType& AnyType::operator=(const AnyType &anyType) = delete;
		 *
		 * \brief	���صĿ�����ֵ�����
		 *
		 */
		AnyType& operator=(const AnyType &anyType) = delete;

		/*! \brief	�������������ֵ */
		T value;
	public:

		/*!
		 * \fn	AnyType::AnyType(const T &value)
		 *
		 * \brief	���캯��
		 *
		 * \param	value	��������ֵ
		 */
		AnyType(const T &value) :
			value(value)
		{
		}

		/*!
		 * \fn	virtual AnyType::~AnyType()
		 *
		 * \brief	��������
		 *
		 */
		virtual ~AnyType()
		{
		}

		/*!
		 * \fn	virtual AnyTypeBase* AnyType::clone()const override
		 *
		 * \brief	��������
		 *
		 * \return	��������Ŀ���
		 */

		virtual AnyTypeBase* clone()const override
		{
			return new AnyType(value);
		}

		/*!
		 * \fn	T* AnyType::Value()
		 *
		 * \brief	��ȡ��ŵ�ֵ
		 *
		 */
		T* Value()
		{
			return &value;
		}
	};

	/*!
	 * \class	Any
	 *
	 * \brief	���ڴ��һ���������͵�ֵ
	 *
	 */
	class Any
	{
	private:
		/*! \brief	ʵ�ʴ�ŵ�ֵ */
		AnyTypeBase *value;
	public:

		/*!
		 * \fn	Any::Any()
		 *
		 * \brief	Ĭ�Ϲ��캯��
		 *
		 */
		Any() :
			value(nullptr)
		{
		}

		/*!
		 * \fn	template<typename T> Any::Any(const T &value)
		 *
		 * \brief	���캯��
		 *
		 * \tparam	T	��������
		 * \param	value	��������ֵ
		 */
		template<typename T>
		Any(const T &value) :
			value(new AnyType<T>(value))
		{
		}

		/*!
		 * \fn	Any::Any(const Any& any)
		 *
		 * \brief	�������캯��
		 *
		 * \param	any	ָ��һ�� Any ����ֵ
		 */
		Any(const Any& any) :
			value(any.value ? any.value->clone() : nullptr)
		{
		}

		/*!
		 * \fn	Any& Any::operator=(const Any& any)
		 *
		 * \brief	������ֵ�����
		 *
		 * \param	any	ָ��һ�� Any ����ֵ
		 *
		 */

		Any& operator=(const Any& any)
		{
			this->value = (any.value ? any.value->clone() : nullptr);
			return *this;
		}

		/*!
		 * \fn	Any::~Any()
		 *
		 * \brief	��������
		 *
		 */
		~Any()
		{
			delete value;
		}

		/*!
		 * \fn	template<typename T> T* Any::Value()
		 *
		 * \brief	��ȡ��ŵ�ֵ
		 *
		 * \tparam	T	ֵ��Ŀ������
		 *
		 */
		template<typename T>
		T* Value()
		{
			if (value == nullptr)
				return nullptr;
			else
				return static_cast<AnyType<T>*>(value)->Value();
		}
	};
}

#endif
