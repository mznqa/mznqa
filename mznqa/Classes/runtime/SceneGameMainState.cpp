/*!
 * \file	Classes\runtime\SceneGameMainState.cpp
 *
 * \brief	定义类 SceneGameMainState
 */

#pragma execution_character_set("utf-8")

#include "runtime/SceneGameMainState.h"

#include "filePath/FilePathSprite.h"
#include "tools/GPointSet.h"

SceneGameMainState::~SceneGameMainState()
{
}

SceneGameMainState* SceneGameMainState::Instance()
{
	static SceneGameMainState instance;
	return &instance;
}

bool SceneGameMainState::enter(SceneGameMain *scene)
{
	cocos2d::log("[information] 准备进入场景 SceneGameMain 对应状态机...");

	// 装载地图
	MapControllerInstance->setEmptyMap();
	MapControllerInstance->loadMapNode(MissionMapSetInstance->getMainMissionMapByIndex(0));

	// 设置角色位置
	RoleInstance->setPosition(0, 0);

	// 绘制地图 //////////////////////////////////////////////////////////////////////////
	scene->layerMap = LayerMap::create();
	scene->layerMap->initialize();
	scene->addChild(scene->layerMap);
	//////////////////////////////////////////////////////////////////////////

	// 绘制角色 //////////////////////////////////////////////////////////////////////////
	scene->spriteRole = SpriteRole::createWithSpriteFrameName(FILE_PATH_SPRITE_GAME_OBJECT_ROLE);
	scene->spriteRole->initialize();
	scene->addChild(scene->spriteRole);
	//////////////////////////////////////////////////////////////////////////

	// 绘制参考线 //////////////////////////////////////////////////////////////////////////
	auto ckx = cocos2d::Sprite::createWithSpriteFrameName(FILE_PATH_SPRITE_OTHER_REFERENCE_LINE);
	ckx->setAnchorPoint(cocos2d::Vec2::ANCHOR_TOP_LEFT);
	ckx->setPosition(cocos2d::Vec2(VISIBLEORIGIN_X, DESIGNRESOLUTIONSIZE_HEIGHT));
	scene->addChild(ckx);
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////

	cardControllerExploreInstance->addCardToCardPool(1234);
	cardControllerExploreInstance->addCardToCardPool(1234);
	cardControllerExploreInstance->addCardToCardPool(1234);
	cardControllerExploreInstance->addCardToCardPool(1234);
	cardControllerExploreInstance->addCardToCardPool(1234);
	cardControllerExploreInstance->addCardToCardPool(1234);
	cardControllerExploreInstance->addCardToCardPool(1234);

	cardControllerExploreInstance->drawACard();
	cardControllerExploreInstance->drawACard();
	cardControllerExploreInstance->drawACard();
	cardControllerExploreInstance->drawACard();

	scene->layerWorkbench = LayerWorkbench::create();
	scene->layerWorkbench->setPosition(cocos2d::Vec2::ZERO);
	scene->layerWorkbench->test();
	scene->addChild(scene->layerWorkbench);
	//////////////////////////////////////////////////////////////////////////

	cocos2d::log("[information] 进入场景 SceneGameMain 对应状态机成功");
	return true;
}

// 状态执行时的操作
bool SceneGameMainState::update(SceneGameMain *scene, double intervalTime)
{
	//cocos2d::log("[information] 开始执行场景 SceneGameMain 对应的状态机...");
	// 消息处理模块 //////////////////////////////////////////////////////////////////////////
	// 转译消息
	LogicMessagePQInstance->pushMessage(MsgInterpreterInstance->translation(EngineMessagePQInstance->getNextMessage()));

	// 获取消息
	Message<LogicMessagePQ::LMessage> msg = LogicMessagePQInstance->getNextMessage();
	// 处理消息
	switch (msg.messageID)
	{
	case LogicMessagePQ::LMessage_MapViewMoveUp:
	{
		MapViewInstance->moveUp();
	}
	break;
	case LogicMessagePQ::LMessage_MapViewMoveRight:
	{
		MapViewInstance->moveRight();
	}
	break;
	case LogicMessagePQ::LMessage_MapViewMoveDown:
	{
		MapViewInstance->moveDown();
	}
	break;
	case LogicMessagePQ::LMessage_MapViewMoveLeft:
	{
		MapViewInstance->moveLeft();
	}
	break;
	case LogicMessagePQ::LMessage_RefreshMapPosition:
	{
		scene->layerMap->refreshPosition();
	}
	break;
	case LogicMessagePQ::LMessage_RefreshRolePosition:
	{
		scene->spriteRole->refreshPosition();
	}
	break;
	case LogicMessagePQ::LMessage_RefreshMapCellSpriteByGPointSet_TGPointSetT:
	{
		scene->layerMap->refreshMapCellWithGPointSet(*((GPointSet*)(msg.extras)));
		GPointSet *p = (GPointSet*)(msg.extras);
		delete p;
		p = nullptr;
	}
	break;
	case LogicMessagePQ::LMessage_SpriteCard_TouchEvent_TouchBegan_TSpriteCardEventIndexT:
	{
		// nothing
	}
	break;
	case LogicMessagePQ::LMessage_SpriteCard_TouchEvent_TouchMoved_TSpriteCardEventIndexT:
	{
		// nothing
	}
	break;
	case LogicMessagePQ::LMessage_SpriteCard_TouchEvent_TouchEnded_TSpriteCardEventIndexT:
	{
		// nothing
	}
	case LogicMessagePQ::LMessage_SpriteHandCard_TouchEvent_TouchBegan_TSpriteHandCardEventIndexT:
	{
		scene->layerWorkbench->showHandCardByIndex(*((SpriteHandCard::EventIndex*)(msg.extras)));
		SpriteHandCard::EventIndex *p = (SpriteHandCard::EventIndex*)(msg.extras);
		delete p;
		p = nullptr;
	}
	break;
	case LogicMessagePQ::LMessage_SpriteHandCard_TouchEvent_TouchMoved_TSpriteHandCardEventIndexT:
	{
		// nothing
	}
	break;
	case LogicMessagePQ::LMessage_SpriteHandCard_TouchEvent_TouchEnded_TSpriteHandCardEventIndexT:
	{
		// nothing
	}
	break;
	default:
	{
		// 未被执行则反推
		LogicMessagePQInstance->pushMessage(msg);
	}
	break;
	}
	//////////////////////////////////////////////////////////////////////////

	//cocos2d::log("[information] 场景 SceneGameMain 对应的状态机执行完成");
	return true;
}

// 离开状态前的操作
bool SceneGameMainState::exit(SceneGameMain *Scene)
{
	cocos2d::log("[information] 准备离开场景 SceneGameMain 对应状态机...");
	cocos2d::log("[information] 离开场景 SceneGameMain 对应状态机成功");
	return true;
}