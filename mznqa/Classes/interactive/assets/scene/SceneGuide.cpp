/*!
* \file		Classes\interactive\assets\scene\SceneGuide.cpp
*
* \brief	������ SceneGuide
*/
#pragma execution_character_set("utf-8")

#include "interactive/assets/scene/SceneGuide.h"
#include "interactive/assets/scene/SceneResLoading.h"

// TODO ������ //////////////////////////////////////////////////////////////////////////
#include "logic/dataLoader/StaticDataLoader.h"
#include "logic/message/LogicMessagePQ.h"
#include "logic/data/static/StringSet/StringSet.h"
//////////////////////////////////////////////////////////////////////////

USING_NS_CC;

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

	// �����֡������
	this->scheduleUpdate();

	log("[information] ���� SceneGuide �����ɹ�");
	return true;
}

void SceneGuide::onEnter()
{
	log("[information] ׼������ SceneGuide ����...");
	// ���ȣ����û��෽��
	Layer::onEnter();
	// TODO ������ //////////////////////////////////////////////////////////////////////////
	StaticDataLoader::loadStringSet();
	auto aaa = LogicMessagePQ::Instance()->getNextMessage();
	auto bbb = StringSet::Instance()->getString(StringSet::StringID_Null);
	auto ccc = StringSet::Instance()->getString(StringSet::StringID_GameName);
	//////////////////////////////////////////////////////////////////////////
	log("[information] �ɹ����� SceneGuide ����");
}

void SceneGuide::onExit()
{
	log("[information] ׼���뿪 SceneGuide ����...");
	// ���ȣ����û��෽��
	Layer::onExit();
	log("[information] �ɹ��뿪 SceneGuide ����");
}

void SceneGuide::update(float dt)
{
	log("[information] ���� SceneGuide ��������֡������...");
	CoreControllerInstance->update(dt);
	log("[information] �뿪 SceneGuide ��������֡������");
}

void SceneGuide::replaceSceneResLoading()
{
	log("[information] ׼���� SceneGuide �����л��� SceneResLoading ����...");
	Director::getInstance()->replaceScene(SceneResLoading::createScene());
	log("[information] �� SceneGuide �����л��� SceneResLoading ����׼���ɹ�");
}