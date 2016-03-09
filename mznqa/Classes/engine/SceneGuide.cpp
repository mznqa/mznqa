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

	rootNode = CSLoader::createNode(FILE_PATH_SCENE_GUIDE);

	addChild(rootNode);

	// ��ӵ��ε����������������� init() ���������
	this->scheduleOnce(schedule_selector(SceneGuide::updateOnce), 1.0f);

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

// ���ε�����
void SceneGuide::updateOnce(float dt)
{
	log("++++ SceneGuide.updateOnce()");
	// ���ó���״̬�������������Ǿ����ϴε��õļ��ʱ�䣬���������ǵ��ε��ȣ��������⴫��1.0f��
	SceneGuideState::Instance()->update(this, 1.0f);
	log("---- SceneGuide.updateOnce()");
}

// �л�������SceneLoadRes
void SceneGuide::replaceSceneLoadRes()
{
	log("++++ SceneGuide.replaceSceneLoadRes()");
	Director::getInstance()->replaceScene(SceneLoadRes::createScene());
	log("---- SceneGuide.replaceSceneLoadRes()");
}