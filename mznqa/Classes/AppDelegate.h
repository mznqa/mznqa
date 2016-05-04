#pragma execution_character_set("utf-8")

#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "cocos2d.h"

/**
@brief    The cocos2d Application.

The reason for implement as private inheritance is to hide some interface call by Director.
*/
class  AppDelegate : private cocos2d::Application
{
private:

	/*!
	 * \fn	void AppDelegate::setResolutionPolicy();
	 *
	 * \brief	设置多分辨率支持策略
	 *
	 */
	void setResolutionPolicy();
public:
	AppDelegate();
	virtual ~AppDelegate();

	virtual void initGLContextAttrs();

	/**
	@brief    Implement Director and Scene init code here.
	@return true    Initialize success, app continue.
	@return false   Initialize failed, app terminate.
	*/
	virtual bool applicationDidFinishLaunching();

	/**
	@brief  The function be called when the application enter background
	*/
	virtual void applicationDidEnterBackground();

	/**
	@brief  The function be called when the application enter foreground
	*/
	virtual void applicationWillEnterForeground();
};

#endif // _APP_DELEGATE_H_
