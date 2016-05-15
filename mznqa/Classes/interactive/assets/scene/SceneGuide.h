/*!
 * \file	Classes\interactive\assets\scene\SceneGuide.h
 *
 * \brief	定义类 SceneGuide
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_ASSETS_SCENE_SCENEGUIDE_H_
#define MZNQA_CLASSES_INTERACTIVE_ASSETS_SCENE_SCENEGUIDE_H_

#include "cocos2d.h"

/*!
* \class	SceneGuide
*
* \brief	第一个场景，引导进入下一场景
*
*/
class SceneGuide : public cocos2d::Layer
{
private:
	// 场景私有量 //////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////

	// 调度器 //////////////////////////////////////////////////////////////////////////

	/*!
	 * \fn	void SceneGuide::update(float dt);
	 *
	 * \brief	逐帧调度器
	 *
	 */
	void update(float dt);
	//////////////////////////////////////////////////////////////////////////
public:
	CREATE_FUNC(SceneGuide);
	static cocos2d::Scene* createScene();

	// 固有的场景生命周期方法 //////////////////////////////////////////////////////////////////////////

	/*!
	* \fn	virtual bool SceneGuide::init() override;
	*
	* \brief	重写场景初始化方法
	*
	*/
	virtual bool init() override;

	/*!
	* \fn	virtual void SceneGuide::onEnter() override;
	*
	* \brief	重写场景进入方法
	*
	*/
	virtual void onEnter() override;

	/*!
	* \fn	virtual void SceneGuide::onExit() override;
	*
	* \brief	重写场景离开方法
	*
	*/
	virtual void onExit() override;
	//////////////////////////////////////////////////////////////////////////

	// 接口 //////////////////////////////////////////////////////////////////////////
	/*!
	* \fn	void SceneGuide::replaceSceneResLoading();
	*
	* \brief	用于从当前场景切换到 SceneResLoading
	*
	*/
	void replaceSceneResLoading();
	//////////////////////////////////////////////////////////////////////////
};

#endif