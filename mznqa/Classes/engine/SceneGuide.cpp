/*!
 * \file	Classes\engine\SceneGuide.cpp
 *
 * \brief	������ SceneGuide
 */

#pragma execution_character_set("utf-8")

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

bool SceneGuide::init()
{
	log("[information] ���� SceneGuide ������...");

	// ���ȣ����û��෽��
	if (!Layer::init())
	{
		return false;
	}

	// ���벢����ⲿ�����ļ�������
	rootNode = CSLoader::createNode(FILE_PATH_SCENE_GUIDE);
	addChild(rootNode);

	// ��ӵ��ε�����
	this->scheduleOnce(schedule_selector(SceneGuide::updateOnce), 1.0f);

	log("[information] ���� SceneGuide �����ɹ�");

	return true;
}

void SceneGuide::onEnter()
{
	log("[information] ׼������ SceneGuide ����...");
	// ���ȣ����û��෽��
	Layer::onEnter();
	// ���ó���״̬����
	SceneGuideState::Instance()->enter(this);
	log("[information] �ɹ����� SceneGuide ����");
}

void SceneGuide::onExit()
{
	log("[information] ׼���뿪 SceneGuide ����...");
	// ���ȣ����û��෽��
	Layer::onExit();
	// ���ó���״̬����
	SceneGuideState::Instance()->exit(this);
	log("[information] �ɹ��뿪 SceneGuide ����");
}

void SceneGuide::updateOnce(float dt)
{
	log("[information] ���� SceneGuide �����ĵ��ε�����...");
	SceneGuideState::Instance()->update(this, dt);
	log("[information] �뿪 SceneGuide �����ĵ��ε�����");
}

void SceneGuide::replaceSceneLoadRes()
{
	log("[information] ׼���� SceneGuide �����л��� SceneLoadRes ����...");
	Director::getInstance()->replaceScene(SceneLoadRes::createScene());
	log("[information] �� SceneGuide �����л��� SceneLoadRes ����׼���ɹ�");
}