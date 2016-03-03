#include "engine/SceneDebug.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

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
	log(">>>> SceneDebug.init()");

	if (!Layer::init())
	{
		return false;
	}

	rootNode = CSLoader::createNode("SceneDebug.csb");

	addChild(rootNode);

	log("<<<< SceneDebug.init()");

	Director::getInstance()->replaceScene(SceneGuide::createScene());

	return true;
}