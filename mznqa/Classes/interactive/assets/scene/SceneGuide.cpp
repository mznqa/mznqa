/*!
* \file		Classes\interactive\assets\scene\SceneGuide.cpp
*
* \brief	定义类 SceneGuide
*/
#pragma execution_character_set("utf-8")

#include "interactive/assets/scene/SceneGuide.h"

#include "interactive/assets/scene/SceneResLoading.h"
#include "interactive/manager/ResFilePath.h"
#include "helper/bridge/Bridge.h"
#include "interactive/message/InteractiveMessagePQ.h"

USING_NS_CC;

Scene* SceneGuide::createScene()
{
	auto scene = Scene::create();

	auto layer = SceneGuide::create();

	scene->addChild(layer);

	return scene;
}

bool SceneGuide::init()
{
	log("[information] 场景 SceneGuide 启动中...");

	// 首先，调用基类方法
	if (!Layer::init())
	{
		return false;
	}
	// 载入精灵集 //////////////////////////////////////////////////////////////////////////
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(RESFILEPATH_IMAGESET_PLIST_01, RESFILEPATH_IMAGESET_PNG_01);
	//////////////////////////////////////////////////////////////////////////

	// 添加逐帧调度器
	this->scheduleUpdate();

	log("[information] 场景 SceneGuide 启动成功");
	return true;
}

void SceneGuide::onEnter()
{
	log("[information] 准备进入 SceneGuide 场景...");
	// 首先，调用基类方法
	Layer::onEnter();
	log("[information] 成功进入 SceneGuide 场景");
}

void SceneGuide::onExit()
{
	log("[information] 准备离开 SceneGuide 场景...");
	// 首先，调用基类方法
	Layer::onExit();
	log("[information] 成功离开 SceneGuide 场景");
}

void SceneGuide::update(float dt)
{
	log("[information] 进入 SceneGuide 场景的逐帧调度器...");
	// 消息处理模块 //////////////////////////////////////////////////////////////////////////
	auto msg = InteractiveMessagePQ::Instance()->getTopMessage();
	if (msg != nullptr)
	{
		switch (msg->getID())
		{
		case InteractiveMessagePQ::InteractiveMessageID_ChangeScene_SceneGuide_SceneResLoading:
			replaceSceneResLoading();
			break;
		default:
			break;
		}
		InteractiveMessagePQ::Instance()->popTopMessage();
	}
	//////////////////////////////////////////////////////////////////////////
	Bridge::Instance()->update(dt);
	log("[information] 离开 SceneGuide 场景的逐帧调度器");
}

void SceneGuide::replaceSceneResLoading()
{
	log("[information] 准备从 SceneGuide 场景切换到 SceneResLoading 场景...");
	Director::getInstance()->replaceScene(SceneResLoading::createScene());
	log("[information] 从 SceneGuide 场景切换到 SceneResLoading 场景准备成功");
}