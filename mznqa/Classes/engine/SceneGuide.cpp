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

// 创建场景时的初始化操作
bool SceneGuide::init()
{
	log("[information] 场景 SceneGuide 启动中...");

	// 首先，调用基类方法
	if (!Layer::init())
	{
		return false;
	}

	rootNode = CSLoader::createNode(FILE_PATH_SCENE_GUIDE);

	addChild(rootNode);

	// 添加单次调度器，调度器均在 init() 方法中添加
	this->scheduleOnce(schedule_selector(SceneGuide::updateOnce), 1.0f);

	log("[information] 场景 SceneGuide 启动成功");

	return true;
}

// 进入场景时的操作
void SceneGuide::onEnter()
{
	log("[information] 准备进入 SceneGuide 场景...");
	// 首先，调用基类方法
	Layer::onEnter();
	// 调用场景状态方法
	SceneGuideState::Instance()->enter(this);

	log("[information] 成功进入 SceneGuide 场景");
}

// 离开场景时的操作
void SceneGuide::onExit()
{
	log("[information] 准备离开 SceneGuide 场景...");
	// 首先，调用基类方法
	Layer::onExit();
	// 调用场景状态方法
	SceneGuideState::Instance()->exit(this);

	log("[information] 成功离开 SceneGuide 场景");
}

// 单次调度器
void SceneGuide::updateOnce(float dt)
{
	log("[information] 进入 SceneGuide 场景的单次调度器...");
	// 调用场景状态方法，参数二是距离上次调用的间隔时间，这里由于是单次调度，所以随意传入1.0f。
	SceneGuideState::Instance()->update(this, 1.0f);
	log("[information] 离开 SceneGuide 场景的单次调度器");
}

// 切换到场景SceneLoadRes
void SceneGuide::replaceSceneLoadRes()
{
	log("[information] 准备从 SceneGuide 场景切换到 SceneLoadRes 场景...");
	Director::getInstance()->replaceScene(SceneLoadRes::createScene());
	log("[information] 从 SceneGuide 场景切换到 SceneLoadRes 场景准备成功");
}