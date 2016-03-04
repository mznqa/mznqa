#include "engine/SceneGuide.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "filePath/SceneFilePath.h"
#include "runtime/SceneGuideState.h"

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
	log("++++ SceneGuide.init()");

	// 首先，调用基类方法
	if (!Layer::init())
	{
		return false;
	}

	rootNode = CSLoader::createNode(FILE_PATH_SCENE_GUIDE);

	addChild(rootNode);

	// 添加单次调度器
	this->scheduleOnce(schedule_selector(SceneGuide::updateOnce), 1.0f);

	log("---- SceneGuide.init()");

	return true;
}

// 进入场景时的操作
void SceneGuide::onEnter()
{
	log("++++ SceneGuide.onEnter()");
	// 首先，调用基类方法
	Layer::onEnter();
	// 调用场景状态方法
	SceneGuideState::Instance()->enter(this);

	log("---- SceneGuide.onEnter()");
}

// 离开场景时的操作
void SceneGuide::onExit()
{
	log("++++ SceneGuide.onExit()");
	// 首先，调用基类方法
	Layer::onExit();
	// 调用场景状态方法
	SceneGuideState::Instance()->exit(this);

	log("---- SceneGuide.onExit()");
}

void SceneGuide::updateOnce(float dt)
{
	log("++++ SceneGuide.updateOnce()");
	SceneGuideState::Instance()->update(this, 1.0f);
	log("---- SceneGuide.updateOnce()");
}