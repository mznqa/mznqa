#include "engine/SceneDebug.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

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
	if (!Layer::init())
	{
		return false;
	}

	rootNode = CSLoader::createNode("SceneDebug.csb");

	addChild(rootNode);

	return true;
}