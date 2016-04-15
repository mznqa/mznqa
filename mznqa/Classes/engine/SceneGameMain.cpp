#pragma execution_character_set("utf-8")

#include "engine/SceneGameMain.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "filePath/SceneFilePath.h"
#include "runtime/SceneGameMainState.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* SceneGameMain::createScene()
{
	auto scene = Scene::create();

	auto layer = SceneGameMain::create();

	scene->addChild(layer);

	return scene;
}

// ��������ʱ�ĳ�ʼ������
bool SceneGameMain::init()
{
	log("[information] ���� SceneGameMain ������...");

	if (!Layer::init())
	{
		return false;
	}

	rootNode = CSLoader::createNode(FILE_PATH_SCENE_GAMEMAIN);

	addChild(rootNode);

	log("[information] ���� SceneGameMain �����ɹ�");

	return true;
}

// ���볡��ʱ�Ĳ���
void SceneGameMain::onEnter()
{
	log("[information] ׼�����볡�� SceneGameMain ��...");
	// ���ȣ����û��෽��
	Layer::onEnter();
	// ���ó���״̬����
	SceneGameMainState::Instance()->enter(this);

	log("[information] ���볡�� SceneGameMain �ɹ�");
}

// �뿪����ʱ�Ĳ���
void SceneGameMain::onExit()
{
	log("[information] ׼���뿪���� SceneGameMain ��...");
	// ���ȣ����û��෽��
	Layer::onExit();
	// ���ó���״̬����
	SceneGameMainState::Instance()->exit(this);
	log("[information] �뿪���� SceneGameMain �ɹ�");
}