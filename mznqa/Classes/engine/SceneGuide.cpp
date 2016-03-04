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

// ��������ʱ�ĳ�ʼ������
bool SceneGuide::init()
{
	log("++++ SceneGuide.init()");

	// ���ȣ����û��෽��
	if (!Layer::init())
	{
		return false;
	}

	// TODO{
	// �������˴�����ĳ����ļ���Ϊ�ض��ĳ����ļ�
	rootNode = CSLoader::createNode(FILE_PATH_SCENE_DEBUG);
	// }TODO

	addChild(rootNode);

	log("---- SceneGuide.init()");

	return true;
}

// ���볡��ʱ�Ĳ���
void SceneGuide::onEnter()
{
	log("++++ SceneGuide.onEnter()");
	// ���ȣ����û��෽��
	Layer::onEnter();
	// ���ó���״̬����
	SceneGuideState::Instance()->enter(this);

	log("---- SceneGuide.onEnter()");
}

// �뿪����ʱ�Ĳ���
void SceneGuide::onExit()
{
	log("++++ SceneGuide.onExit()");
	// ���ȣ����û��෽��
	Layer::onExit();
	// ���ó���״̬����
	SceneGuideState::Instance()->exit(this);

	log("---- SceneGuide.onExit()");
}