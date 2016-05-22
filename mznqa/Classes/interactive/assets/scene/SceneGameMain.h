/*!
 * \file	Classes\interactive\assets\scene\SceneGameMain.h
 *
 * \brief	定义类 SceneGameMain
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_ASSETS_SCENE_SCENEGAMEMAIN_H_
#define MZNQA_CLASSES_INTERACTIVE_ASSETS_SCENE_SCENEGAMEMAIN_H_

#include "cocos2d.h"

#include "interactive/assets/layer/LayerMap.h"
#include "interactive/assets/layer/LayerWorkbench.h"
#include "interactive/message/InteractiveMessagePQ.h"

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
	/*! \brief	地图层 */
	LayerMap *layerMap;
	/*! \brief	工作区 */
	LayerWorkbench *layerWorkbench;

	/*! \brief	持续推送的消息 */
	InteractiveMessagePQ::InteractiveMessageID loopMessage;
	//////////////////////////////////////////////////////////////////////////

	// 时间监听器 //////////////////////////////////////////////////////////////////////////

	/*!
	 * \fn	void SceneGameMain::addKeyboardEventListener();
	 *
	 * \brief	添加按键监听事件
	 *
	 */
	void addKeyboardEventListener();

	/*!
	 * \fn	void SceneGameMain::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	 *
	 * \brief	重写按键按下事件
	 *
	 */
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	/*!
	 * \fn	void SceneGameMain::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	 *
	 * \brief	重写按键释放事件
	 *
	 */
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	//////////////////////////////////////////////////////////////////////////

	// 调度器 //////////////////////////////////////////////////////////////////////////

	/*!
	 * \fn	void SceneGameMain::messagePushLoop(float dt);
	 *
	 * \brief	用于持续推送消息
	 *
	 */
	void messagePushLoop(float dt);
	/*!
	* \fn	void SceneGameMain::update(float dt);
	*
	* \brief	逐帧调度器
	*
	*/
	void update(float dt);
	//////////////////////////////////////////////////////////////////////////
public:
	CREATE_FUNC(SceneGameMain);
	static cocos2d::Scene* createScene();

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

	// 接口 //////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
};

#endif