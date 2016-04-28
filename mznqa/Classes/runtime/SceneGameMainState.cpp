/*!
 * \file	Classes\runtime\SceneGameMainState.cpp
 *
 * \brief	������ SceneGameMainState
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
	cocos2d::log("[information] ׼�����볡�� SceneGameMain ��Ӧ״̬��...");

	// װ�ص�ͼ
	MapControllerInstance->setEmptyMap();
	MapControllerInstance->loadMapNode(MissionMapSetInstance->getMainMissionMapByIndex(0));

	// ���ý�ɫλ��
	RoleInstance->setPosition(10, 7);

	// ���Ƶ�ͼ //////////////////////////////////////////////////////////////////////////
	scene->layerMap = LayerMap::create();
	scene->layerMap->initialize();
	scene->addChild(scene->layerMap);
	//////////////////////////////////////////////////////////////////////////

	// ���ƽ�ɫ //////////////////////////////////////////////////////////////////////////
	scene->spriteRole = SpriteRole::createWithSpriteFrameName(FILE_PATH_SPRITE_GAME_OBJECT_ROLE);
	scene->spriteRole->initialize();
	scene->addChild(scene->spriteRole);
	//////////////////////////////////////////////////////////////////////////

	// ���Ʋο��� //////////////////////////////////////////////////////////////////////////
	auto ckx = cocos2d::Sprite::createWithSpriteFrameName(FILE_PATH_SPRITE_OTHER_REFERENCE_LINE);
	ckx->setAnchorPoint(cocos2d::Vec2::ANCHOR_TOP_LEFT);
	ckx->setPosition(cocos2d::Vec2(0, DESIGNRESOLUTIONSIZE_HEIGHT));
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

	cocos2d::log("[information] ���볡�� SceneGameMain ��Ӧ״̬���ɹ�");
	return true;
}

// ״ִ̬��ʱ�Ĳ���
bool SceneGameMainState::update(SceneGameMain *scene, double intervalTime)
{
	//cocos2d::log("[information] ��ʼִ�г��� SceneGameMain ��Ӧ��״̬��...");
	// ��Ϣ����ģ�� //////////////////////////////////////////////////////////////////////////
	// ת����Ϣ
	LogicMessagePQInstance->pushMessage(MsgInterpreterInstance->translation(EngineMessagePQInstance->getNextMessage()));

	// ��ȡ��Ϣ
	Message<LogicMessagePQ::LMessage> msg = LogicMessagePQInstance->getNextMessage();
	// ������Ϣ
	if (msg.messageID == LogicMessagePQ::LMessage_MapViewMoveUp)
	{
		MapViewInstance->moveUp();
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_MapViewMoveRight)
	{
		MapViewInstance->moveRight();
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_MapViewMoveDown)
	{
		MapViewInstance->moveDown();
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_MapViewMoveLeft)
	{
		MapViewInstance->moveLeft();
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_RefreshMapPosition)
	{
		scene->layerMap->refreshPosition();
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_RefreshRolePosition)
	{
		scene->spriteRole->refreshPosition();
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_RefreshMapCellSpriteByGPointSet_TGPointSetT)
	{
		scene->layerMap->refreshMapCellWithGPointSet(*((GPointSet*)(msg.extras)));
		GPointSet *p = (GPointSet*)(msg.extras);
		delete p;
		p = nullptr;
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_SpriteCard_TouchEvent_TouchBegan_TSpriteCardEventIndexT)
	{
		scene->layerWorkbench->showHandCardByIndex(*((SpriteCard::EventIndex*)(msg.extras)));
		SpriteCard::EventIndex *p = (SpriteCard::EventIndex*)(msg.extras);
		delete p;
		p = nullptr;
	}
	// δ��ִ������
	else
	{
		LogicMessagePQInstance->pushMessage(msg);
	}
	//////////////////////////////////////////////////////////////////////////

	//cocos2d::log("[information] ���� SceneGameMain ��Ӧ��״̬��ִ�����");
	return true;
}

// �뿪״̬ǰ�Ĳ���
bool SceneGameMainState::exit(SceneGameMain *Scene)
{
	cocos2d::log("[information] ׼���뿪���� SceneGameMain ��Ӧ״̬��...");
	cocos2d::log("[information] �뿪���� SceneGameMain ��Ӧ״̬���ɹ�");
	return true;
}