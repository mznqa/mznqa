#pragma execution_character_set("utf-8")

#include "engine/SceneDebug.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "filePath/SceneFilePath.h"
#include "engine/SceneGuide.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* SceneDebug::createScene()
{
	auto scene = Scene::create();

	auto layer = SceneDebug::create();

	scene->addChild(layer);

	return scene;
}

// 场景创建时的初始化操作
bool SceneDebug::init()
{
	log("++++ SceneDebug.init()");

	// 首先，调用基类方法
	if (!Layer::init())
	{
		return false;
	}

	// 载入外部场景文件
	rootNode = CSLoader::createNode(FILE_PATH_SCENE_DEBUG);

	// 添加到场景中
	addChild(rootNode);

	log("---- SceneDebug.init()");

	return true;
}

// 进入场景时的操作
void SceneDebug::onEnter()
{
	log("++++ SceneDebug.onEnter()");

	// 首先，调用基类方法
	Layer::onEnter();

	// 场景SceneDebug仅用于，引导作用，因此
	// 载入场景 SceneDebug 后立即跳转到场景SceneGuide。
	Director::getInstance()->replaceScene(SceneGuide::createScene());

	log("---- SceneDebug.onEnter()");
}

// 离开场景时的操作
void SceneDebug::onExit()
{
	log("++++ SceneDebug.onExit()");

	// 首先，调用基类方法
	Layer::onExit();

	log("---- SceneDebug.onExit()");
}