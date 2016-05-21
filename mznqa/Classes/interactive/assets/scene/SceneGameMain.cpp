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
#include "logic/gameObject/cardContainer/CardBox3.h"
#include <map>
#include "logic/gameObject/cardContainer/CardArray3.h"
#include "logic/controller/CharacterController.h"
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
	std::map<int, CardSkill> cardSkillSet = {
		std::pair<int, CardSkill>(1000, CardSkill(1000, 0, 0, CardBase::BelongTo_Both, std::vector<Effect>())),
		std::pair<int, CardSkill>(1001, CardSkill(1001, 0, 0, CardBase::BelongTo_Both, std::vector<Effect>())),
		std::pair<int, CardSkill>(1002, CardSkill(1002, 0, 0, CardBase::BelongTo_Both, std::vector<Effect>())),
		std::pair<int, CardSkill>(1003, CardSkill(1003, 0, 0, CardBase::BelongTo_Both, std::vector<Effect>())),
		std::pair<int, CardSkill>(1004, CardSkill(1004, 0, 0, CardBase::BelongTo_Both, std::vector<Effect>())),
		std::pair<int, CardSkill>(1005, CardSkill(1005, 0, 0, CardBase::BelongTo_Both, std::vector<Effect>())),
		std::pair<int, CardSkill>(1006, CardSkill(1006, 0, 0, CardBase::BelongTo_Both, std::vector<Effect>()))
	};
	CardSet::Instance()->loadCardSkillSet(cardSkillSet);
	std::map<int, CardMonster> cardMonsterSet = {
		std::pair<int, CardMonster>(2000, CardMonster(2000, 0, 0, CardBase::BelongTo_Both)),
		std::pair<int, CardMonster>(2001, CardMonster(2001, 0, 0, CardBase::BelongTo_Both)),
		std::pair<int, CardMonster>(2002, CardMonster(2002, 0, 0, CardBase::BelongTo_Both)),
		std::pair<int, CardMonster>(2003, CardMonster(2003, 0, 0, CardBase::BelongTo_Both)),
		std::pair<int, CardMonster>(2004, CardMonster(2004, 0, 0, CardBase::BelongTo_Both)),
		std::pair<int, CardMonster>(2005, CardMonster(2005, 0, 0, CardBase::BelongTo_Both)),
		std::pair<int, CardMonster>(2006, CardMonster(2006, 0, 0, CardBase::BelongTo_Both))
	};
	CardSet::Instance()->loadCardMonsterSet(cardMonsterSet);

	CharacterController::Instance()->createRole();
	CharacterController::Instance()->getRole()->getCardControllerExplore().addCardToPool(0);
	CharacterController::Instance()->getRole()->getCardControllerExplore().addCardToPool(1);
	CharacterController::Instance()->getRole()->getCardControllerExplore().addCardToPool(2);
	CharacterController::Instance()->getRole()->getCardControllerExplore().addCardToPool(3);
	CharacterController::Instance()->getRole()->getCardControllerExplore().addCardToPool(4);
	CharacterController::Instance()->getRole()->getCardControllerExplore().addCardToPool(5);
	CharacterController::Instance()->getRole()->getCardControllerExplore().addCardToPool(6);
	CharacterController::Instance()->getRole()->getCardControllerExplore().addCardToPool(7);
	CharacterController::Instance()->getRole()->getCardControllerExplore().drawCard();
	CharacterController::Instance()->getRole()->getCardControllerExplore().drawCard();
	CharacterController::Instance()->getRole()->getCardControllerExplore().drawCard();

	//////////////////////////////////////////////////////////////////////////
	// 显示地图 //////////////////////////////////////////////////////////////////////////
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
	//////////////////////////////////////////////////////////////////////////

	// 工作台 //////////////////////////////////////////////////////////////////////////
	layerWorkbench = LayerWorkbench::create();
	addChild(layerWorkbench);
	//////////////////////////////////////////////////////////////////////////

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
		case InteractiveMessagePQ::InteractiveMessageID_Explore_PutCard_Road_TintT:
			layerWorkbench->executeAddCard(msg->getExtras<int>());
			break;
		case InteractiveMessagePQ::InteractiveMessageID_Explore_PutCardFail_Road_CardPollEmpty:
			log("[warning] 探索场景下，抽牌失败，因为卡池为空！");
			break;
		case InteractiveMessagePQ::InteractiveMessageID_Explore_PutCardFail_Road_HandCardFull:
			log("[warning] 探索场景下，抽牌失败，因为手牌已满！");
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