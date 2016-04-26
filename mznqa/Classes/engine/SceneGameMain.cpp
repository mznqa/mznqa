/*!
 * \file	Classes\engine\SceneGameMain.cpp
 *
 * \brief	定义类 SceneGameMain
 */

#pragma execution_character_set("utf-8")

#include "engine/SceneGameMain.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "runtime/SceneGameMainState.h"
// 测试用 //////////////////////////////////////////////////////////////////////////
#include "staticData/CardSet.h"
//////////////////////////////////////////////////////////////////////////

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* SceneGameMain::createScene()
{
	auto scene = Scene::create();

	auto layer = SceneGameMain::create();

	scene->addChild(layer);

	return scene;
}

bool SceneGameMain::init()
{
	log("[information] 场景 SceneGameMain 启动中...");

	// 首先，执行基类方法
	if (!Layer::init())
	{
		return false;
	}

	// 加入逐帧计时器
	this->scheduleUpdate();

	// 测试用区域 //////////////////////////////////////////////////////////////////////////
	eventListenerKeyboard = cocos2d::EventListenerKeyboard::create();
	eventListenerKeyboard->onKeyPressed = CC_CALLBACK_2(SceneGameMain::onKeyPressed, this);
	eventListenerKeyboard->onKeyReleased = CC_CALLBACK_2(SceneGameMain::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListenerKeyboard, this);
	//////////////////////////////////////////////////////////////////////////

	log("[information] 场景 SceneGameMain 启动成功");

	return true;
}

void SceneGameMain::onEnter()
{
	log("[information] 准备进入场景 SceneGameMain 中...");
	// 首先，调用基类方法
	Layer::onEnter();
	// 调用场景状态方法
	SceneGameMainState::Instance()->enter(this);
	log("[information] 进入场景 SceneGameMain 成功");
}

void SceneGameMain::onExit()
{
	log("[information] 准备离开场景 SceneGameMain 中...");
	// 首先，调用基类方法
	Layer::onExit();
	// 调用场景状态方法
	SceneGameMainState::Instance()->exit(this);
	log("[information] 离开场景 SceneGameMain 成功");
}

void SceneGameMain::update(float dt)
{
	SceneGameMainState::Instance()->update(this, dt);
}

// 测试用区域 //////////////////////////////////////////////////////////////////////////
void SceneGameMain::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	log("[warning] Key with keycode %d pressed", keyCode);
	if (keyCode == EventKeyboard::KeyCode::KEY_A)
	{
		MapController::Instance()->putCardRoad(*(CardSet::Instance()->getCardRoadByID(134)), GRect(3, 3, 5, 5));
	}
}

void SceneGameMain::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	log("[warning] Key with keycode %d released", keyCode);
}
//////////////////////////////////////////////////////////////////////////