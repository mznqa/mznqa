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
	log("++++ SceneGuide.init()");

	// 首先，调用基类方法
	if (!Layer::init())
	{
		return false;
	}

	// TODO{
	// 后续将此处载入的场景文件改为特定的场景文件
	rootNode = CSLoader::createNode(FILE_PATH_SCENE_DEBUG);
	// }TODO

	addChild(rootNode);

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