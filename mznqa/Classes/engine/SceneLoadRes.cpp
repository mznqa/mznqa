#pragma execution_character_set("utf-8")

#include "engine/SceneLoadRes.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "filePath/SceneFilePath.h"
#include "runtime/SceneLoadResState.h"
#include "engine/SceneGameMain.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* SceneLoadRes::createScene()
{
	auto scene = Scene::create();

	auto layer = SceneLoadRes::create();

	scene->addChild(layer);

	return scene;
}

// 场景创建时的初始化操作
bool SceneLoadRes::init()
{
	log("[information] 场景 SceneLoadRes 启动中...");

	if (!Layer::init())
	{
		return false;
	}

	rootNode = CSLoader::createNode(FILE_PATH_SCENE_LOADRES);

	addChild(rootNode);

	// 添加单次调度器，调度器均在 init() 方法中添加
	this->scheduleOnce(schedule_selector(SceneLoadRes::updateOnce), 1.0f);

	log("[information] 场景 SceneLoadRes 启动成功");

	return true;
}

// 进入场景时的操作
void SceneLoadRes::onEnter()
{
	log("[information] 准备进入场景 SceneLoadRes 中...");
	// 首先，调用基类方法
	Layer::onEnter();
	// 调用场景状态方法
	SceneLoadResState::Instance()->enter(this);

	log("[information] 进入场景 SceneLoadRes 成功");
}

// 离开场景时的操作
void SceneLoadRes::onExit()
{
	log("[information] 准备离开场景 SceneLoadRes 中...");
	// 首先，调用基类方法
	Layer::onExit();
	// 调用场景状态方法
	SceneLoadResState::Instance()->exit(this);
	log("[information] 离开场景 SceneLoadRes 成功");
}

// 单次调度器
void SceneLoadRes::updateOnce(float dt)
{
	log("[information] 进入 SceneLoadRes 场景的单次调度器...");
	// 调用场景状态方法，参数二是距离上次调用的间隔时间，这里由于是单次调度，所以随意传入1.0f。
	SceneLoadResState::Instance()->update(this, 1.0f);
	log("[information] 离开 SceneLoadRes 场景的单次调度器");
}

void SceneLoadRes::replaceSceneGameMain()
{
	log("[information] 准备从 SceneLoadRes 场景切换到 SceneGameMain 场景...");
	Director::getInstance()->replaceScene(SceneGameMain::createScene());
	log("[information] 从 SceneLoadRes 场景切换到 SceneGameMain 场景准备成功");
}