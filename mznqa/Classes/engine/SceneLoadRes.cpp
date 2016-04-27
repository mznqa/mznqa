/*!
 * \file	Classes\engine\SceneLoadRes.cpp
 *
 * \brief	定义类 SceneLoadRes
 */

#pragma execution_character_set("utf-8")

#include "engine/SceneLoadRes.h"

#include "cocostudio/CocoStudio.h"

#include "filePath/FilePathScene.h"
#include "runtime/SceneLoadResState.h"
#include "engine/SceneGameMain.h"

USING_NS_CC;

using namespace cocostudio::timeline;

const std::string SceneLoadRes::UiNameTextOutput("Text_Output");

Scene* SceneLoadRes::createScene()
{
	auto scene = Scene::create();

	auto layer = SceneLoadRes::create();

	scene->addChild(layer);

	return scene;
}

bool SceneLoadRes::init()
{
	log("[information] 场景 SceneLoadRes 启动中...");

	// 执行基类方法
	if (!Layer::init())
	{
		return false;
	}

	// 载入并添加外部场景文件的内容
	rootNode = CSLoader::createNode(FILE_PATH_SCENE_LOADRES);
	addChild(rootNode);

	// 获取UI：用于输出信息的文本框
	uiTextOutput = (ui::Text*)(rootNode->getChildByName(UiNameTextOutput));

	// 加入逐帧调度器
	this->scheduleUpdate();

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

void SceneLoadRes::update(float dt)
{
	log("[information] 进入 SceneLoadRes 场景的逐帧调度器...");
	SceneLoadResState::Instance()->update(this, dt);
	log("[information] 离开 SceneLoadRes 场景的逐帧调度器");
}

void SceneLoadRes::replaceSceneGameMain()
{
	log("[information] 准备从 SceneLoadRes 场景切换到 SceneGameMain 场景...");
	Director::getInstance()->replaceScene(SceneGameMain::createScene());
	log("[information] 从 SceneLoadRes 场景切换到 SceneGameMain 场景准备成功");
}

void SceneLoadRes::showProgress(std::string log)
{
	uiTextOutput->setText(log);
}