#pragma execution_character_set("utf-8")

#include "engine/SceneGameMain.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "filePath/SceneFilePath.h"
#include "runtime/SceneGameMainState.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* SceneGameMain::createScene()
{
	auto scene = Scene::create();

	auto layer = SceneGameMain::create();

	scene->addChild(layer);

	return scene;
}

// 场景创建时的初始化操作
bool SceneGameMain::init()
{
	log("[information] 场景 SceneGameMain 启动中...");

	if (!Layer::init())
	{
		return false;
	}

	rootNode = CSLoader::createNode(FILE_PATH_SCENE_GAMEMAIN);

	addChild(rootNode);

	log("[information] 场景 SceneGameMain 启动成功");

	return true;
}

// 进入场景时的操作
void SceneGameMain::onEnter()
{
	log("[information] 准备进入场景 SceneGameMain 中...");
	// 首先，调用基类方法
	Layer::onEnter();
	// 调用场景状态方法
	SceneGameMainState::Instance()->enter(this);

	log("[information] 进入场景 SceneGameMain 成功");
}

// 离开场景时的操作
void SceneGameMain::onExit()
{
	log("[information] 准备离开场景 SceneGameMain 中...");
	// 首先，调用基类方法
	Layer::onExit();
	// 调用场景状态方法
	SceneGameMainState::Instance()->exit(this);
	log("[information] 离开场景 SceneGameMain 成功");
}