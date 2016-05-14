/*!
 * \file	Classes\interactive\assets\scene\SceneResLoading.cpp
 *
 * \brief	定义类 SceneResLoading
 */

#pragma execution_character_set("utf-8")

#include "interactive/assets/scene/SceneResLoading.h"

#include "interactive/assets/scene/SceneGameMain.h"

USING_NS_CC;

Scene* SceneResLoading::createScene()
{
	auto scene = Scene::create();

	auto layer = SceneResLoading::create();

	scene->addChild(layer);

	return scene;
}

bool SceneResLoading::init()
{
	log("[information] 场景 SceneResLoading 启动中...");

	// 首先，调用基类方法
	if (!Layer::init())
	{
		return false;
	}

	// 添加逐帧调度器
	this->scheduleUpdate();

	log("[information] 场景 SceneResLoading 启动成功");
	return true;
}

void SceneResLoading::onEnter()
{
	log("[information] 准备进入 SceneResLoading 场景...");
	// 首先，调用基类方法
	Layer::onEnter();
	log("[information] 成功进入 SceneResLoading 场景");
}

void SceneResLoading::onExit()
{
	log("[information] 准备离开 SceneResLoading 场景...");
	// 首先，调用基类方法
	Layer::onExit();
	log("[information] 成功离开 SceneResLoading 场景");
}

void SceneResLoading::update(float dt)
{
	log("[information] 进入 SceneResLoading 场景的逐帧调度器...");
	// 消息处理模块 //////////////////////////////////////////////////////////////////////////
	auto msg = InteractiveMessagePQInstance->getTopMessage();
	if (msg != nullptr)
	{
		switch (msg->getID())
		{
		case InteractiveMessagePQ::InteractiveMessageID_ChangeScene_SceneResLoading_SceneGameMain:
			replaceSceneGameMain();
			break;
		default:
			break;
		}
		InteractiveMessagePQInstance->popTopMessage();
	}
	//////////////////////////////////////////////////////////////////////////
	BridgeInstance->update(dt);
	log("[information] 离开 SceneResLoading 场景的逐帧调度器");
}

void SceneResLoading::replaceSceneGameMain()
{
	log("[information] 准备从 SceneResLoading 场景切换到 SceneGameMain 场景...");
	Director::getInstance()->replaceScene(SceneGameMain::createScene());
	log("[information] 从 SceneResLoading 场景切换到 SceneGameMain 场景准备成功");
}