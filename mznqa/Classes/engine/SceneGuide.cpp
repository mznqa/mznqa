/*!
 * \file	Classes\engine\SceneGuide.cpp
 *
 * \brief	定义类 SceneGuide
 */

#pragma execution_character_set("utf-8")

#include "engine/SceneGuide.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "filePath/SceneFilePath.h"
#include "runtime/SceneGuideState.h"
#include "engine/SceneLoadRes.h"

USING_NS_CC;

using namespace cocostudio::timeline;

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

	// 载入并添加外部场景文件的内容
	rootNode = CSLoader::createNode(FILE_PATH_SCENE_GUIDE);
	addChild(rootNode);

	// 添加单次调度器
	this->scheduleOnce(schedule_selector(SceneGuide::updateOnce), 1.0f);

	log("[information] 场景 SceneGuide 启动成功");

	return true;
}

void SceneGuide::onEnter()
{
	log("[information] 准备进入 SceneGuide 场景...");
	// 首先，调用基类方法
	Layer::onEnter();
	// 调用场景状态方法
	SceneGuideState::Instance()->enter(this);
	log("[information] 成功进入 SceneGuide 场景");
}

void SceneGuide::onExit()
{
	log("[information] 准备离开 SceneGuide 场景...");
	// 首先，调用基类方法
	Layer::onExit();
	// 调用场景状态方法
	SceneGuideState::Instance()->exit(this);
	log("[information] 成功离开 SceneGuide 场景");
}

void SceneGuide::updateOnce(float dt)
{
	log("[information] 进入 SceneGuide 场景的单次调度器...");
	SceneGuideState::Instance()->update(this, dt);
	log("[information] 离开 SceneGuide 场景的单次调度器");
}

void SceneGuide::replaceSceneLoadRes()
{
	log("[information] 准备从 SceneGuide 场景切换到 SceneLoadRes 场景...");
	Director::getInstance()->replaceScene(SceneLoadRes::createScene());
	log("[information] 从 SceneGuide 场景切换到 SceneLoadRes 场景准备成功");
}