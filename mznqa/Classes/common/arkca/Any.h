/*!
 * \file	Classes\common\arkca\Any.h
 *
 * \brief	定义类 ArKCa::AnyTypeBase , ArKCa::AnyType , ArKCa::Any
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
	 * \brief	用于辅助实现 ArKCa::Any
	 *
	 */
	class AnyTypeBase
	{
	private:

		/*!
		 * \fn	AnyTypeBase::AnyTypeBase(const AnyTypeBase &AnyTypeBase);
		 *
		 * \brief	隐藏的拷贝构造函数
		 *
		 */
		AnyTypeBase(const AnyTypeBase &AnyTypeBase);

		/*!
		 * \fn	AnyTypeBase& AnyTypeBase::operator=(const AnyTypeBase &AnyTypeBase);
		 *
		 * \brief	隐藏的拷贝赋值运算符
		 *
		 */
		AnyTypeBase& operator=(const AnyTypeBase &AnyTypeBase);
	public:

		/*!
		 * \fn	AnyTypeBase::AnyTypeBase()
		 *
		 * \brief	默认构造函数
		 *
		 */
		AnyTypeBase()
		{
		}

		/*!
		 * \fn	virtual AnyTypeBase::~AnyTypeBase()
		 *
		 * \brief	析构函数
		 *
		 */
		virtual ~AnyTypeBase()
		{
		}

		/*!
		 * \fn	virtual AnyTypeBase* AnyTypeBase::clone()const = 0;
		 *
		 * \brief	拷贝自身
		 *
		 * \return	返回自身的拷贝
		 */
		virtual AnyTypeBase* clone()const = 0;
	};

	/*!
	 * \class	AnyType
	 *
	 * \brief	用于辅助实现 ArKCa::Any
	 *
	 * \tparam	T	任意类型
	 */
	template <typename T>
	class AnyType : public AnyTypeBase
	{
	private:

		/*!
		 * \fn	AnyType::AnyType();
		 *
		 * \brief	隐藏的默认构造函数
		 *
		 */
		AnyType();

		/*!
		 * \fn	AnyType::AnyType(const AnyType &anyType);
		 *
		 * \brief	隐藏的拷贝构造函数
		 *
		 */
		AnyType(const AnyType &anyType);

		/*!
		 * \fn	AnyType& AnyType::operator=(const AnyType &anyType);
		 *
		 * \brief	隐藏的拷贝赋值运算符
		 *
		 */
		AnyType& operator=(const AnyType &anyType);

		/*! \brief	保存的任意类型值 */
		T value;
	public:

		/*!
		 * \fn	AnyType::AnyType(const T &value)
		 *
		 * \brief	构造函数
		 *
		 * \param	value	任意类型值
		 */
		AnyType(const T &value) :
			value(value)
		{
		}

		/*!
		 * \fn	virtual AnyType::~AnyType()
		 *
		 * \brief	析构函数
		 *
		 */
		virtual ~AnyType()
		{
		}

		/*!
		 * \fn	virtual AnyTypeBase* AnyType::clone()const override
		 *
		 * \brief	拷贝自身
		 *
		 * \return	返回自身的拷贝
		 */

		virtual AnyTypeBase* clone()const override
		{
			return new AnyType(value);
		}

		/*!
		* \fn	T AnyType::Value()const
		*
		* \brief	获取所存放的值
		*
		*/
		T Value()const
		{
			return value;
		}

		/*!
		 * \fn	const T* AnyType::Ptr()const
		 *
		 * \brief	获取所存放的值的指针
		 *
		 */
		const T* Ptr()const
		{
			return &value;
		}

		/*!
		 * \fn	T* AnyType::Ptr()
		 *
		 * \brief	获取所存放的值的指针
		 *
		 */
		T* Ptr()
		{
			return &value;
		}
	};

	/*!
	 * \class	Any
	 *
	 * \brief	用于存放一个任意类型的值
	 *
	 */
	class Any
	{
	private:
		/*! \brief	实际存放的值 */
		AnyTypeBase *value;
	public:

		/*!
		 * \fn	Any::Any()
		 *
		 * \brief	默认构造函数
		 *
		 */
		Any() :
			value(nullptr)
		{
		}

		/*!
		 * \fn	template<typename T> Any::Any(const T &value)
		 *
		 * \brief	构造函数
		 *
		 * \tparam	T	任意类型
		 * \param	value	任意类型值
		 */
		template<typename T>
		Any(const T &value) :
			value(new AnyType<T>(value))
		{
		}

		/*!
		 * \fn	Any::Any(const Any& any)
		 *
		 * \brief	拷贝构造函数
		 *
		 * \param	any	指定一个 Any 类型值
		 */
		Any(const Any& any) :
			value(any.value ? any.value->clone() : nullptr)
		{
		}

		/*!
		 * \fn	Any& Any::operator=(const Any& any)
		 *
		 * \brief	拷贝赋值运算符
		 *
		 * \param	any	指定一个 Any 类型值
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
		 * \brief	析构函数
		 *
		 */
		~Any()
		{
			delete value;
		}

		/*!
		* \fn	template<typename T> T Any::Value()const
		*
		* \brief	获取存放的值，应留意空指针情况
		*
		* \tparam	T	值的目标类型
		*
		*/
		template<typename T>
		T Value()const
		{
			return *(static_cast<AnyType<T>*>(value)->Ptr());
		}

		/*!
		 * \fn	template<typename T> const T* Any::Ptr()const
		 *
		 * \brief	获取存放的值的指针
		 *
		 * \tparam	T	值的目标类型
		 *
		 */
		template<typename T>
		const T* Ptr()const
		{
			if (value == nullptr)
				return nullptr;
			else
				return static_cast<AnyType<T>*>(value)->Ptr();
		}

		/*!
		 * \fn	template<typename T> T* Any::Ptr()
		 *
		 * \brief	获取存放的值的指针
		 *
		 * \tparam	T	值的目标类型
		 *
		 */
		template<typename T>
		T* Ptr()
		{
			if (value == nullptr)
				return nullptr;
			else
				return static_cast<AnyType<T>*>(value)->Ptr();
		}
	};
}

#endif
