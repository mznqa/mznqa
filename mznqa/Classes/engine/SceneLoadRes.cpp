#pragma execution_character_set("utf-8")

#include "engine/SceneLoadRes.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "filePath/SceneFilePath.h"
#include "runtime/SceneLoadResState.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* SceneLoadRes::createScene()
{
	auto scene = Scene::create();

	auto layer = SceneLoadRes::create();

	scene->addChild(layer);

	return scene;
}

// ��������ʱ�ĳ�ʼ������
bool SceneLoadRes::init()
{
	log("++++ SceneLoadRes.init()");

	if (!Layer::init())
	{
		return false;
	}

	rootNode = CSLoader::createNode(FILE_PATH_SCENE_LOADRES);

	addChild(rootNode);

	log("---- SceneLoadRes.init()");

	return true;
}

// ���볡��ʱ�Ĳ���
void SceneLoadRes::onEnter()
{
	log("++++ SceneLoadRes.onEnter()");
	// ���ȣ����û��෽��
	Layer::onEnter();
	// ���ó���״̬����
	SceneLoadResState::Instance()->enter(this);

	log("---- SceneLoadRes.onEnter()");
}

// �뿪����ʱ�Ĳ���
void SceneLoadRes::onExit()
{
	log("++++ SceneLoadRes.onExit()");
	// ���ȣ����û��෽��
	Layer::onExit();
	// ���ó���״̬����
	SceneLoadResState::Instance()->exit(this);
	log("---- SceneLoadRes.onExit()");
}