/*!
 * \file	Classes\engine\SceneGameMain.cpp
 *
 * \brief	定义类 SceneGameMain
 */

#pragma execution_character_set("utf-8")

#include "engine/SceneGameMain.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "filePath/SceneFilePath.h"
#include "runtime/SceneGameMainState.h"
#include "define/GlobalDefine.h"
#include "gameobject/Role.h"

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