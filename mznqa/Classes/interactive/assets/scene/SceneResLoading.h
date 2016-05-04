/*!
 * \file	Classes\interactive\assets\scene\SceneResLoading.h
 *
 * \brief	定义类 SceneResLoading
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_ASSETS_SCENERESLOADING_H_
#define MZNQA_CLASSES_INTERACTIVE_ASSETS_SCENERESLOADING_H_

#include "cocos2d.h"

/*!
 * \class	SceneResLoading
 *
 * \brief	用于载入资源的场景
 *
 */
class SceneResLoading : public cocos2d::Layer
{
private:
	// 场景私有量 //////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////

	// 调度器 //////////////////////////////////////////////////////////////////////////

	/*!
	* \fn	void SceneResLoading::update(float dt);
	*
	* \brief	逐帧调度器
	*
	*/
	void update(float dt);
	//////////////////////////////////////////////////////////////////////////
public:
	CREATE_FUNC(SceneResLoading);
	static cocos2d::Scene* createScene();

	// 固有的场景生命周期方法 //////////////////////////////////////////////////////////////////////////

	/*!
	* \fn	virtual bool SceneResLoading::init() override;
	*
	* \brief	重写场景初始化方法
	*
	*/
	virtual bool init() override;

	/*!
	* \fn	virtual void SceneResLoading::onEnter() override;
	*
	* \brief	重写场景进入方法
	*
	*/
	virtual void onEnter() override;

	/*!
	* \fn	virtual void SceneResLoading::onExit() override;
	*
	* \brief	重写场景离开方法
	*
	*/
	virtual void onExit() override;
	//////////////////////////////////////////////////////////////////////////

	// 接口 //////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
};

#endif