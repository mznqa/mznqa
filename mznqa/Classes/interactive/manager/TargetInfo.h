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
 * \brief	[单例]有关窗口和设备等有关的尺寸、坐标以及语言等信息
 *
 */
class TargetInfo
{
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
	 * \enum	Language
	 *
	 * \brief	枚举目标设备的语言
	 */
	enum Language
	{
		Language_Other,	///< 除以下的任一语言
		Language_Zh,	///< 中文
		Language_En		///< 英文
	};

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

	/*!
	 * \fn	void TargetInfo::setScreenLeftTopOrigin(float x, float y)
	 *
	 * \brief	设置屏幕左上角在屏幕中的坐标
	 *
	 * \param	x	指定横坐标
	 * \param	y	指定纵坐标
	 */
	void setScreenLeftTopOrigin(float x, float y)
	{
		screenLeftTopOrigin.set(x, y);
	}

	/*!
	 * \fn	const ArKCa::Vector2<float>& TargetInfo::getScreenLeftTopOrigin()const
	 *
	 * \brief	获取屏幕左上角在屏幕中的坐标
	 *
	 */
	const ArKCa::Vector2<float>& getScreenLeftTopOrigin()const
	{
		return screenLeftTopOrigin;
	}

	/*!
	 * \fn	void TargetInfo::setScreenSize(float x, float y)
	 *
	 * \brief	设置屏幕实际分辨率
	 *
	 * \param	x	指定宽度
	 * \param	y	指定高度
	 */
	void setScreenSize(float x, float y)
	{
		screenSize.set(x, y);
	}

	/*!
	 * \fn	const ArKCa::Size<float>& TargetInfo::getScreenSize()const
	 *
	 * \brief	获取屏幕实际分辨率
	 *
	 */
	const ArKCa::Size<float>& getScreenSize()const
	{
		return screenSize;
	}

	/*!
	 * \fn	void TargetInfo::setLanguage(Language language)
	 *
	 * \brief	设置目标设备的语言
	 *
	 * \param	language	指定语言以设置目标设备的语言
	 */
	void setLanguage(Language language)
	{
		this->language = language;
	}

	/*!
	 * \fn	Language TargetInfo::getLanguage()const
	 *
	 * \brief	获取目标设备的语言
	 *
	 */
	Language getLanguage()const
	{
		return language;
	}

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
	/*! \brief	屏幕左上角的坐标在屏幕中的坐标 */
	ArKCa::Vector2<float> screenLeftTopOrigin = ArKCa::Vector2<float>(0.0f, 0.0f);
	/*! \brief	窗口实际分辨率尺寸 */
	ArKCa::Size<float> screenSize = ArKCa::Size<float>(0.0f, 0.0f);

	/*! \brief	目标设备的语言 */
	Language language = Language_Zh;
};

#endif