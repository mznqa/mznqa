/*!
 * \file	Classes\interactive\assets\scene\SceneGameMain.h
 *
 * \brief	定义类 SceneGameMain
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_ASSETS_SCENE_SCENEGAMEMAIN_H_
#define MZNQA_CLASSES_INTERACTIVE_ASSETS_SCENE_SCENEGAMEMAIN_H_

#include "cocos2d.h"

#include "helper/bridge/Bridge.h"
#include "interactive/assets/layer/LayerMap.h"
#include "interactive/message/InteractiveMessagePQ.h"
#include "logic/controller/MapController.h"

/*!
* \class	SceneGameMain
*
* \brief	游戏主场景
*
*/
class SceneGameMain : public cocos2d::Layer
{
private:
	// 单例别名 //////////////////////////////////////////////////////////////////////////
	/*! \brief	Bridge 单例别名 */
	Bridge *const BridgeInstance = Bridge::Instance();
	/*! \brief	InteractiveMessagePQ 单例别名 */
	InteractiveMessagePQ *const InteractiveMessagePQInstance = InteractiveMessagePQ::Instance();
	/*! \brief	MapController 单例别名 */
	MapController *const MapControllerInstance = MapController::Instance();
	//////////////////////////////////////////////////////////////////////////

	// 场景私有量 //////////////////////////////////////////////////////////////////////////
	/*! \brief	地图层 */
	LayerMap *layerMap;
	//////////////////////////////////////////////////////////////////////////

	// 调度器 //////////////////////////////////////////////////////////////////////////

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