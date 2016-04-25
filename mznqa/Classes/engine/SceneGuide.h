/*!
 * \file	Classes\engine\SceneGuide.h
 *
 * \brief	定义类 SceneGuide
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_SCENEGUIDE_H_
#define MZNQA_CLASSES_ENGINE_SCENEGUIDE_H_

#include "cocos2d.h"

/*!
 * \class	SceneGuide
 *
 * \brief	最为第一个场景，用于引导进入下一场景
 *
 */
class SceneGuide : public cocos2d::Layer
{
private:
	// 场景私有量 //////////////////////////////////////////////////////////////////////////
	/*! \brief	用于存放外部场景文件载入的资源 */
	cocos2d::Node *rootNode;
	//////////////////////////////////////////////////////////////////////////

	// 调度器 //////////////////////////////////////////////////////////////////////////
	/*!
	 * \fn	void SceneGuide::updateOnce(float dt);
	 *
	 * \brief	重写单次调度器
	 *
	 */
	void updateOnce(float dt);
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

	// API //////////////////////////////////////////////////////////////////////////

	/*!
	 * \fn	void SceneGuide::replaceSceneLoadRes();
	 *
	 * \brief	用于从当前场景切换到 SceneLoadRes
	 *
	 */
	void replaceSceneLoadRes();
	//////////////////////////////////////////////////////////////////////////
};

#endif	// MZNQA_CLASSES_ENGINE_SCENEGUIDE_H_