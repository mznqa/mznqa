/*!
 * \file	Classes\interactive\assets\scene\SceneGameMain.cpp
 *
 * \brief	������ SceneGameMain
 */

#pragma execution_character_set("utf-8")

#include "interactive/assets/scene/SceneGameMain.h"

// �������� //////////////////////////////////////////////////////////////////////////
#include "logic/controller/MapController.h"
#include "logic/dataLoader/StaticDataLoader.h"
//////////////////////////////////////////////////////////////////////////

USING_NS_CC;

Scene* SceneGameMain::createScene()
{
	auto scene = Scene::create();

	auto layer = SceneGameMain::create();

	scene->addChild(layer);

	return scene;
}

bool SceneGameMain::init()
{
	log("[information] ���� SceneGameMain ������...");

	// ���ȣ����û��෽��
	if (!Layer::init())
	{
		return false;
	}

	// �������� //////////////////////////////////////////////////////////////////////////
	StaticDataLoader::loadMissionMapMain(MissionMapSet::MissionMapIDMain_0);
	MapController::Instance()->build(MissionMapSet::MissionMapIDMain_0);
	LayerMap *lm = LayerMap::create();
	lm->loadMap();
	addChild(lm);
	//////////////////////////////////////////////////////////////////////////

	// �����֡������
	this->scheduleUpdate();

	log("[information] ���� SceneGameMain �����ɹ�");
	return true;
}

void SceneGameMain::onEnter()
{
	log("[information] ׼������ SceneGameMain ����...");
	// ���ȣ����û��෽��
	Layer::onEnter();
	log("[information] �ɹ����� SceneGameMain ����");
}

void SceneGameMain::onExit()
{
	log("[information] ׼���뿪 SceneGameMain ����...");
	// ���ȣ����û��෽��
	Layer::onExit();
	log("[information] �ɹ��뿪 SceneGameMain ����");
}

void SceneGameMain::update(float dt)
{
	log("[information] ���� SceneGameMain ��������֡������...");
	BridgeInstance->update(dt);
	log("[information] �뿪 SceneGameMain ��������֡������");
}