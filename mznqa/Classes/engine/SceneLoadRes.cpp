#pragma execution_character_set("utf-8")

#include "engine/SceneLoadRes.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "filePath/SceneFilePath.h"
#include "runtime/SceneLoadResState.h"

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