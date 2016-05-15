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
#include "interactive/manager/SizeDefine.h"
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
	MapControllerInstance->build(MissionMapSet::MissionMapIDMain_0);
	//////////////////////////////////////////////////////////////////////////
	MapControllerInstance->setMapView(
		ArKCa::Size<int>(
		TargetInfo::Instance()->getScreenSize().width / MAPCELL_SIZE,
		TargetInfo::Instance()->getScreenSize().height / MAPCELL_SIZE
		),
		ArKCa::Vector2<int>(
		0, 0
		)
		);
	layerMap = LayerMap::create();
	layerMap->loadMap();
	addChild(layerMap);

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
	//log("[information] ���� SceneGameMain ��������֡������...");
	// ��Ϣ����ģ�� //////////////////////////////////////////////////////////////////////////
	auto msg = InteractiveMessagePQInstance->getTopMessage();
	if (msg != nullptr)
	{
		switch (msg->getID())
		{
		case InteractiveMessagePQ::InteractiveMessageID_Update_LayerMapPosition:
			layerMap->updateGlobalMapPosition();
			break;
		default:
			break;
		}
		InteractiveMessagePQInstance->popTopMessage();
	}
	//////////////////////////////////////////////////////////////////////////
	BridgeInstance->update(dt);
	//log("[information] �뿪 SceneGameMain ��������֡������");
}