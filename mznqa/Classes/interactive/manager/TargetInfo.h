/*!
 * \file	Classes\interactive\manager\TargetInfo.h
 *
 * \brief	定义类 TargetInfo
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_MANAGER_TARGETINFO_H_
#define MZNQA_CLASSES_INTERACTIVE_MANAGER_TARGETINFO_H_

#include "common/arkca/Size.h"
#include "common/arkca/Vector2.h"

/*!
 * \class	TargetInfo
 *
 * \brief	有关窗口设备等有关尺寸和坐标信息
 *
 */
class TargetInfo
{
private:

	/*!
	 * \fn	TargetInfo::TargetInfo();
	 *
	 * \brief	隐藏的默认构造函数
	 *
	 */
	TargetInfo();

	/*!
	 * \fn	TargetInfo::TargetInfo(const TargetInfo &sizeManager);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 */
	TargetInfo(const TargetInfo &sizeManager);

	/*!
	 * \fn	TargetInfo& TargetInfo::operator=(const TargetInfo &sizeManager);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 */
	TargetInfo& operator=(const TargetInfo &sizeManager);

	/*! \brief	窗口（屏幕）尺寸 */
	ArKCa::Size<float> windowSize = ArKCa::Size<float>(0.0f, 0.0f);
	/*! \brief	预设的设计尺寸 */
	ArKCa::Size<float> defineDesignSize = ArKCa::Size<float>(0.0f, 0.0f);
	/*! \brief	经多分辨率支持策略匹配设备后经缩放的实际设计尺寸 */
	ArKCa::Size<float> realityDesignSize = ArKCa::Size<float>(0.0f, 0.0f);
	/*! \brief	实际设计尺寸的左上角点在屏幕中的坐标 */
	ArKCa::Vector2<float> realityDesignOrigin = ArKCa::Vector2<float>(0.0f, 0.0f);

public:

	/*!
	 * \fn	TargetInfo::~TargetInfo();
	 *
	 * \brief	析构函数
	 *
	 */
	~TargetInfo();

	/*!
	 * \fn	static TargetInfo* TargetInfo::Instance();
	 *
	 * \brief	获取单例
	 *
	 */
	static TargetInfo* Instance();

	/*!
	 * \fn	void TargetInfo::setWindowSize(float width, float height)
	 *
	 * \brief	设置窗口尺寸
	 *
	 * \param	width 	指定一个宽度值
	 * \param	height	指定一个高度值
	 */
	void setWindowSize(float width, float height)
	{
		windowSize.set(width, height);
	}

	/*!
	 * \fn	const ArKCa::Size<float>& TargetInfo::getWindowSize()const
	 *
	 * \brief	获取窗口尺寸
	 *
	 */
	const ArKCa::Size<float>& getWindowSize()const
	{
		return windowSize;
	}

	/*!
	 * \fn	void TargetInfo::setExpectedDesignSize(float width, float height)
	 *
	 * \brief	设置预设的设计尺寸
	 *
	 * \param	width 	指定一个宽度值
	 * \param	height	指定一个高度值
	 */
	void setExpectedDesignSize(float width, float height)
	{
		defineDesignSize.set(width, height);
	}

	/*!
	 * \fn	const ArKCa::Size<float>& TargetInfo::getExpectedDesignSize()const
	 *
	 * \brief	获取预设的设计尺寸
	 *
	 */
	const ArKCa::Size<float>& getExpectedDesignSize()const
	{
		return defineDesignSize;
	}

	/*!
	 * \fn	void TargetInfo::setRealityDesignSize(float width, float height)
	 *
	 * \brief	设置实际的设计尺寸
	 *
	 * \param	width 	指定一个宽度值
	 * \param	height	指定一个高度值
	 */
	void setRealityDesignSize(float width, float height)
	{
		realityDesignSize.set(width, height);
	}

	/*!
	 * \fn	const ArKCa::Size<float>& TargetInfo::getRealityDesignSize()const
	 *
	 * \brief	获取实际的设计尺寸
	 *
	 */
	const ArKCa::Size<float>& getRealityDesignSize()const
	{
		return realityDesignSize;
	}

	/*!
	 * \fn	void TargetInfo::setRealityDesignOrigin(float x, float y)
	 *
	 * \brief	设置实际设计尺寸的左上角点在屏幕中的坐标
	 *
	 * \param	x	指定横坐标
	 * \param	y	指定纵坐标
	 */
	void setRealityDesignOrigin(float x, float y)
	{
		realityDesignOrigin.set(x, y);
	}

	/*!
	 * \fn	const ArKCa::Vector2<float>& TargetInfo::getDesignOrigin()const
	 *
	 * \brief	获取实际设计尺寸的左上角点在屏幕中的坐标
	 *
	 */
	const ArKCa::Vector2<float>& getDesignOrigin()const
	{
		return realityDesignOrigin;
	}
};

#endif