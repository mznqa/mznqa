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

// ��������ʱ�ĳ�ʼ������
bool SceneDebug::init()
{
	log("++++ SceneDebug.init()");

	// ���ȣ����û��෽��
	if (!Layer::init())
	{
		return false;
	}

	// �����ⲿ�����ļ�
	rootNode = CSLoader::createNode(FILE_PATH_SCENE_DEBUG);

	// ��ӵ�������
	addChild(rootNode);

	log("---- SceneDebug.init()");

	return true;
}

// ���볡��ʱ�Ĳ���
void SceneDebug::onEnter()
{
	log("++++ SceneDebug.onEnter()");

	// ���ȣ����û��෽��
	Layer::onEnter();

	// ����SceneDebug�����ڣ��������ã����
	// ���볡�� SceneDebug ��������ת������SceneGuide��
	Director::getInstance()->replaceScene(SceneGuide::createScene());

	log("---- SceneDebug.onEnter()");
}

// �뿪����ʱ�Ĳ���
void SceneDebug::onExit()
{
	log("++++ SceneDebug.onExit()");

	// ���ȣ����û��෽��
	Layer::onExit();

	log("---- SceneDebug.onExit()");
}