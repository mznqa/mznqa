/*!
 * \file	Classes\engine\SceneGameMain.h
 *
 * \brief	定义类 SceneGameMain
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_SCENEGAMEMAIN_H_
#define MZNQA_CLASSES_ENGINE_SCENEGAMEMAIN_H_

#include "cocos2d.h"

#include "engine/LayerMap.h"
#include "engine/SpriteRole.h"
#include "engine/LayerWorkbench.h"

/*!
 * \class	SceneGameMain
 *
 * \brief	游戏主场景
 *
 */
class SceneGameMain : public cocos2d::Layer
{
private:
	// 场景私有量 //////////////////////////////////////////////////////////////////////////
	/*! \brief	用于存放从外部载入的场景文件的资源 */
	cocos2d::Node *rootNode;
	//////////////////////////////////////////////////////////////////////////

	// 调度器 //////////////////////////////////////////////////////////////////////////

	/*!
	 * \fn	void SceneGameMain::update(float dt);
	 *
	 * \brief	重写逐帧调度器
	 *
	 */
	void update(float dt);
	//////////////////////////////////////////////////////////////////////////
public:
	CREATE_FUNC(SceneGameMain);
	static cocos2d::Scene* createScene();

	// 场景公有量 //////////////////////////////////////////////////////////////////////////
	/*! \brief	地图层 */
	LayerMap *layerMap;
	/*! \brief	角色精灵 */
	SpriteRole	*spriteRole;
	/*! \brief	手牌栏 */
	LayerWorkbench *layerWorkbench;
	//////////////////////////////////////////////////////////////////////////

	// 固有的场景生命周期方法 //////////////////////////////////////////////////////////////////////////

	/*!
	 * \fn	virtual bool SceneGameMain::init() override;
	 *
	 * \brief	重写场景初始化方法
	 *
	 */
	virtual bool init() override;

	/*!
	 * \fn	virtual void SceneGameMain::onEnter() override;
	 *
	 * \brief	重写场景进入方法
	 *
	 */
	virtual void onEnter() override;

	/*!
	 * \fn	virtual void SceneGameMain::onExit() override;
	 *
	 * \brief	重写场景离开方法
	 *
	 */
	virtual void onExit() override;
	//////////////////////////////////////////////////////////////////////////

	// 测试用区域 //////////////////////////////////////////////////////////////////////////
	cocos2d::EventListenerKeyboard *eventListenerKeyboard;
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	//////////////////////////////////////////////////////////////////////////
};

#endif	// MZNQA_CLASSES_ENGINE_SCENEGAMEMAIN_H_