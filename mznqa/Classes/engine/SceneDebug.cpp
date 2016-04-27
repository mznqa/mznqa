/*!
 * \file	Classes\engine\SceneDebug.cpp
 *
 * \brief	定义类 SceneDebug
 */

#pragma execution_character_set("utf-8")

#include "engine/SceneDebug.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "filePath/FilePathScene.h"
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

bool SceneDebug::init()
{
	log("[information] 启动 SceneDebug 场景中...");

	// 首先，调用基类方法
	if (!Layer::init())
	{
		return false;
	}

	// 载入并添加外部场景文件
	rootNode = CSLoader::createNode(FILE_PATH_SCENE_DEBUG);
	addChild(rootNode);

	log("[information] SceneDebug 场景启动成功");

	return true;
}

void SceneDebug::onEnter()
{
	log("[information] 开始准备进入 SceneDebug 场景...");

	// 首先，调用基类方法
	Layer::onEnter();

	// 场景SceneDebug仅用于，引导作用，因此
	// 载入场景 SceneDebug 后立即跳转到场景SceneGuide。
	log("[information] 准备从 SceneDebug 场景跳转到 SceneGuide 场景...");
	Director::getInstance()->replaceScene(SceneGuide::createScene());

	log("[information] SceneDebug 场景进入成功");
}

void SceneDebug::onExit()
{
	log("[information] 开始准备离开 SceneDebug 场景...");

	// 首先，调用基类方法
	Layer::onExit();

	log("[information] SceneDebug 离开成功");
}