/*!
 * \file	Classes\interactive\assets\scene\SceneResLoading.cpp
 *
 * \brief	������ SceneResLoading
 */

#pragma execution_character_set("utf-8")

#include "interactive/assets/scene/SceneResLoading.h"

USING_NS_CC;

Scene* SceneResLoading::createScene()
{
	auto scene = Scene::create();

	auto layer = SceneResLoading::create();

	scene->addChild(layer);

	return scene;
}

bool SceneResLoading::init()
{
	log("[information] ���� SceneResLoading ������...");

	// ���ȣ����û��෽��
	if (!Layer::init())
	{
		return false;
	}

	// �����֡������
	this->scheduleUpdate();

	log("[information] ���� SceneResLoading �����ɹ�");
	return true;
}

void SceneResLoading::onEnter()
{
	log("[information] ׼������ SceneResLoading ����...");
	// ���ȣ����û��෽��
	Layer::onEnter();
	log("[information] �ɹ����� SceneResLoading ����");
}

void SceneResLoading::onExit()
{
	log("[information] ׼���뿪 SceneResLoading ����...");
	// ���ȣ����û��෽��
	Layer::onExit();
	log("[information] �ɹ��뿪 SceneResLoading ����");
}

void SceneResLoading::update(float dt)
{
	log("[information] ���� SceneResLoading ��������֡������...");
	log("[information] �뿪 SceneResLoading ��������֡������");
}