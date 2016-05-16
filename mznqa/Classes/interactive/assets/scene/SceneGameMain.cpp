/*!
 * \file	Classes\interactive\assets\scene\SceneGameMain.cpp
 *
 * \brief	定义类 SceneGameMain
 */

#pragma execution_character_set("utf-8")

#include "interactive/assets/scene/SceneGameMain.h"
#include "interactive/manager/TargetInfo.h"
#include "helper/bridge/Bridge.h"
#include "interactive/message/InteractiveMessagePQ.h"

// 测试区域 //////////////////////////////////////////////////////////////////////////
#include "logic/controller/MapController.h"
#include "logic/dataLoader/StaticDataLoader.h"
#include "interactive/manager/SizeDefine.h"
#include "logic/data/static/card/CardSet.h"
#include "logic/gameObject/cardContainer/CardBox.h"
#include "logic/gameObject/cardContainer/CardArray.h"
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
	log("[information] 场景 SceneGameMain 启动中...");

	// 首先，调用基类方法
	if (!Layer::init())
	{
		return false;
	}

	// 测试区域 //////////////////////////////////////////////////////////////////////////
	StaticDataLoader::loadMissionMapMain(MissionMapSet::MissionMapIDMain_0);
	MapController::Instance()->build(MissionMapSet::MissionMapIDMain_0);
	CardArray<CardRoad, 5> ca;
	ca.set(1, 1);
	ca.set(2, 2);
	ca.set(3, 3);
	ca.set(4, 4);
	ca.removeByIndex(1);
	ca.removeByIndex(2);
	//////////////////////////////////////////////////////////////////////////
	MapController::Instance()->setMapView(
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

	// 添加逐帧调度器
	this->scheduleUpdate();

	log("[information] 场景 SceneGameMain 启动成功");
	return true;
}

void SceneGameMain::onEnter()
{
	log("[information] 准备进入 SceneGameMain 场景...");
	// 首先，调用基类方法
	Layer::onEnter();
	log("[information] 成功进入 SceneGameMain 场景");
}

void SceneGameMain::onExit()
{
	log("[information] 准备离开 SceneGameMain 场景...");
	// 首先，调用基类方法
	Layer::onExit();
	log("[information] 成功离开 SceneGameMain 场景");
}

void SceneGameMain::update(float dt)
{
	//log("[information] 进入 SceneGameMain 场景的逐帧调度器...");
	// 消息处理模块 //////////////////////////////////////////////////////////////////////////
	auto msg = InteractiveMessagePQ::Instance()->getTopMessage();
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
		InteractiveMessagePQ::Instance()->popTopMessage();
	}
	//////////////////////////////////////////////////////////////////////////
	Bridge::Instance()->update(dt);
	//log("[information] 离开 SceneGameMain 场景的逐帧调度器");
}