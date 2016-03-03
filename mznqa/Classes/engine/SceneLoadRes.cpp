#include "engine/SceneLoadRes.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "filePath/SceneFilePath.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* SceneLoadRes::createScene()
{
	auto scene = Scene::create();

	auto layer = SceneLoadRes::create();

	scene->addChild(layer);

	return scene;
}

bool SceneLoadRes::init()
{
	log(">>>> SceneLoadRes.init()");

	if (!Layer::init())
	{
		return false;
	}

	// TODO{
	// 后续将此处载入的场景文件改为特定的场景文件
	rootNode = CSLoader::createNode(FILE_PATH_SCENE_DEBUG);
	// }TODO

	addChild(rootNode);

	log("<<<< SceneLoadRes.init()");

	return true;
}