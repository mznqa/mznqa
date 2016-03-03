#include "engine/SceneGuide.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* SceneGuide::createScene()
{
	auto scene = Scene::create();

	auto layer = SceneGuide::create();

	scene->addChild(layer);

	return scene;
}

bool SceneGuide::init()
{
	log(">>>> SceneGuide.init()");

	if (!Layer::init())
	{
		return false;
	}

	// TODO{
	// �������˴�����ĳ����ļ���Ϊ�ض��ĳ����ļ�
	rootNode = CSLoader::createNode("SceneDebug.csb");
	// }TODO

	addChild(rootNode);

	log("<<<< SceneGuide.init()");

	return true;
}