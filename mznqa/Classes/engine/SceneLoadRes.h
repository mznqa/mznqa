/*!
 * \file	Classes\engine\SceneLoadRes.h
 *
 * \brief	定义类 SceneLoadRes
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_SCENELOADRES_H_
#define MZNQA_CLASSES_ENGINE_SCENELOADRES_H_

#include <string>

#include "cocos2d.h"
#include "ui/CocosGUI.h"

/*!
 * \class	SceneLoadRes
 *
 * \brief	用于执行资源载入的场景
 *
 */
class SceneLoadRes : public cocos2d::Layer
{
private:
	// 外部文件中的UI名称 //////////////////////////////////////////////////////////////////////////
	static const std::string UiNameTextOutput;
	//////////////////////////////////////////////////////////////////////////
	// 场景私有量 //////////////////////////////////////////////////////////////////////////
	/*! \brief	用于存放从外部载入的场景文件的资源 */
	cocos2d::Node *rootNode;
	//////////////////////////////////////////////////////////////////////////

	// 调度器 //////////////////////////////////////////////////////////////////////////

	/*!
	 * \fn	void SceneLoadRes::update(float dt);
	 *
	 * \brief	逐帧调度器重写
	 *
	 */
	void update(float dt);
	//////////////////////////////////////////////////////////////////////////

public:
	CREATE_FUNC(SceneLoadRes);
	static cocos2d::Scene* createScene();

	// 场景公共量 //////////////////////////////////////////////////////////////////////////
	/*! \brief	用于输出信息的文本框UI */
	cocos2d::ui::Text *uiTextOutput;
	//////////////////////////////////////////////////////////////////////////

	// 固有的场景生命周期方法 //////////////////////////////////////////////////////////////////////////
	/*!
	 * \fn	virtual bool SceneLoadRes::init() override;
	 *
	 * \brief	重写场景初始化方法
	 *
	 */
	virtual bool init() override;

	/*!
	 * \fn	virtual void SceneLoadRes::onEnter() override;
	 *
	 * \brief	重写场景进入方法
	 *
	 */
	virtual void onEnter() override;

	/*!
	 * \fn	virtual void SceneLoadRes::onExit() override;
	 *
	 * \brief	重写场景离开方法
	 *
	 */
	virtual void onExit() override;
	//////////////////////////////////////////////////////////////////////////

	// API //////////////////////////////////////////////////////////////////////////

	/*!
	 * \fn	void SceneLoadRes::replaceSceneGameMain();
	 *
	 * \brief	用于从当前场景切换到 SceneGameMain
	 *
	 */
	void replaceSceneGameMain();

	/*!
	 * \fn	void SceneLoadRes::showProgress(std::string log);
	 *
	 * \brief	输出资源载入的进度信息
	 *
	 * \param	log	待输出的信息
	 */
	void showProgress(std::string log);
	//////////////////////////////////////////////////////////////////////////
};

#endif	// MZNQA_CLASSES_ENGINE_SCENELOADRES_H_