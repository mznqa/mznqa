/*!
 * \file	Classes\engine\SceneGameMain.cpp
 *
 * \brief	������ SceneGameMain
 */

#pragma execution_character_set("utf-8")

#include "engine/SceneGameMain.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "filePath/SceneFilePath.h"
#include "runtime/SceneGameMainState.h"
#include "define/GlobalDefine.h"
#include "gameobject/Role.h"

USING_NS_CC;

using namespace cocostudio::timeline;

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

	// ���ȣ�ִ�л��෽��
	if (!Layer::init())
	{
		return false;
	}

	// ������֡��ʱ��
	this->scheduleUpdate();

	log("[information] ���� SceneGameMain �����ɹ�");

	return true;
}

void SceneGameMain::onEnter()
{
	log("[information] ׼�����볡�� SceneGameMain ��...");
	// ���ȣ����û��෽��
	Layer::onEnter();
	// ���ó���״̬����
	SceneGameMainState::Instance()->enter(this);
	log("[information] ���볡�� SceneGameMain �ɹ�");
}

void SceneGameMain::onExit()
{
	log("[information] ׼���뿪���� SceneGameMain ��...");
	// ���ȣ����û��෽��
	Layer::onExit();
	// ���ó���״̬����
	SceneGameMainState::Instance()->exit(this);
	log("[information] �뿪���� SceneGameMain �ɹ�");
}

void SceneGameMain::update(float dt)
{
	SceneGameMainState::Instance()->update(this, dt);
}