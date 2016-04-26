/*!
 * \file	Classes\engine\SceneGameMain.cpp
 *
 * \brief	������ SceneGameMain
 */

#pragma execution_character_set("utf-8")

#include "engine/SceneGameMain.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "runtime/SceneGameMainState.h"
// ������ //////////////////////////////////////////////////////////////////////////
#include "staticData/CardSet.h"
//////////////////////////////////////////////////////////////////////////

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

	// ���������� //////////////////////////////////////////////////////////////////////////
	eventListenerKeyboard = cocos2d::EventListenerKeyboard::create();
	eventListenerKeyboard->onKeyPressed = CC_CALLBACK_2(SceneGameMain::onKeyPressed, this);
	eventListenerKeyboard->onKeyReleased = CC_CALLBACK_2(SceneGameMain::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListenerKeyboard, this);
	//////////////////////////////////////////////////////////////////////////

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

// ���������� //////////////////////////////////////////////////////////////////////////
void SceneGameMain::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	log("[warning] Key with keycode %d pressed", keyCode);
	if (keyCode == EventKeyboard::KeyCode::KEY_A)
	{
		MapController::Instance()->putCardRoad(*(CardSet::Instance()->getCardRoadByID(134)), GRect(3, 3, 5, 5));
	}
}

void SceneGameMain::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	log("[warning] Key with keycode %d released", keyCode);
}
//////////////////////////////////////////////////////////////////////////