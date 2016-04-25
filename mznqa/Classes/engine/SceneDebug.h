/*!
 * \file	Classes\engine\SceneDebug.h
 *
 * \brief	定义类 SceneDebug
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_SCENEDEBUG_H_
#define MZNQA_CLASSES_ENGINE_SCENEDEBUG_H_

#include "cocos2d.h"

/*!
 * \class	SceneDebug
 *
 * \brief	暂用的场景，用于引导进入 SceneGuide
 *
 */
class SceneDebug : public cocos2d::Layer
{
private:
	// 场景私有量 //////////////////////////////////////////////////////////////////////////
	/*! \brief	从外部文件载入的场景文件所存放的位置 */
	cocos2d::Node *rootNode;
	//////////////////////////////////////////////////////////////////////////
public:
	CREATE_FUNC(SceneDebug);
	static cocos2d::Scene* createScene();

	// 固有的场景生命周期方法 //////////////////////////////////////////////////////////////////////////

	/*!
	 * \fn	virtual bool SceneDebug::init() override;
	 *
	 * \brief	重写场景初始化方法
	 *
	 */
	virtual bool init() override;

	/*!
	 * \fn	virtual void SceneDebug::onEnter() override;
	 *
	 * \brief	重写场景进入方法
	 *
	 */
	virtual void onEnter() override;

	/*!
	 * \fn	virtual void SceneDebug::onExit() override;
	 *
	 * \brief	重写场景离开方法
	 *
	 */
	virtual void onExit() override;
	//////////////////////////////////////////////////////////////////////////
};

#endif	// MZNQA_CLASSES_ENGINE_SCENEDEBUG_H_