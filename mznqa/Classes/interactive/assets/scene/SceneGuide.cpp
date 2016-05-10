/*!
* \file		Classes\interactive\assets\scene\SceneGuide.cpp
*
* \brief	定义类 SceneGuide
*/
#pragma execution_character_set("utf-8")

#include "interactive/assets/scene/SceneGuide.h"
#include "interactive/assets/scene/SceneResLoading.h"

// TODO 测试用 //////////////////////////////////////////////////////////////////////////
#include "logic/dataLoader/StaticDataLoader.h"
#include "logic/message/LogicMessagePQ.h"
#include "logic/data/static/StringSet/StringSet.h"
//////////////////////////////////////////////////////////////////////////

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
	// TODO 测试用 //////////////////////////////////////////////////////////////////////////
	StaticDataLoader::loadStringSet();
	auto aaa = LogicMessagePQ::Instance()->getNextMessage();
	auto bbb = StringSet::Instance()->getString(StringSet::StringID_Null);
	auto ccc = StringSet::Instance()->getString(StringSet::StringID_GameName);
	//////////////////////////////////////////////////////////////////////////
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
	CoreControllerInstance->update(dt);
	log("[information] 离开 SceneGuide 场景的逐帧调度器");
}

void SceneGuide::replaceSceneResLoading()
{
	log("[information] 准备从 SceneGuide 场景切换到 SceneResLoading 场景...");
	Director::getInstance()->replaceScene(SceneResLoading::createScene());
	log("[information] 从 SceneGuide 场景切换到 SceneResLoading 场景准备成功");
}