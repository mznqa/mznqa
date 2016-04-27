/*!
 * \file	Classes\engine\SceneDebug.cpp
 *
 * \brief	������ SceneDebug
 */

#pragma execution_character_set("utf-8")

#include "engine/SceneDebug.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "filePath/FilePathScene.h"
#include "engine/SceneGuide.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* SceneDebug::createScene()
{
	auto scene = Scene::create();

	auto layer = SceneDebug::create();

	scene->addChild(layer);

	return scene;
}

bool SceneDebug::init()
{
	log("[information] ���� SceneDebug ������...");

	// ���ȣ����û��෽��
	if (!Layer::init())
	{
		return false;
	}

	// ���벢����ⲿ�����ļ�
	rootNode = CSLoader::createNode(FILE_PATH_SCENE_DEBUG);
	addChild(rootNode);

	log("[information] SceneDebug ���������ɹ�");

	return true;
}

void SceneDebug::onEnter()
{
	log("[information] ��ʼ׼������ SceneDebug ����...");

	// ���ȣ����û��෽��
	Layer::onEnter();

	// ����SceneDebug�����ڣ��������ã����
	// ���볡�� SceneDebug ��������ת������SceneGuide��
	log("[information] ׼���� SceneDebug ������ת�� SceneGuide ����...");
	Director::getInstance()->replaceScene(SceneGuide::createScene());

	log("[information] SceneDebug ��������ɹ�");
}

void SceneDebug::onExit()
{
	log("[information] ��ʼ׼���뿪 SceneDebug ����...");

	// ���ȣ����û��෽��
	Layer::onExit();

	log("[information] SceneDebug �뿪�ɹ�");
}