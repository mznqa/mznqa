/*!
 * \file	Classes\interactive\assets\scene\SceneGameMain.cpp
 *
 * \brief	������ SceneGameMain
 */

#pragma execution_character_set("utf-8")

#include "interactive/assets/scene/SceneGameMain.h"
#include "interactive/manager/TargetInfo.h"
#include "helper/bridge/Bridge.h"

// �������� //////////////////////////////////////////////////////////////////////////
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
#include "interactive/assets/sprite/SpriteRole.h"
#include "logic/controller/PathController.h"
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
	// ��ʾ��ͼ //////////////////////////////////////////////////////////////////////////
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
	layerMap->loadSpriteRole();
	addChild(layerMap);
	// ���� //////////////////////////////////////////////////////////////////////////
	PathController::Instance()->ready(
		ArKCa::Vector2<int>(10, 10),
		ArKCa::Vector2<int>(8, 3)
		);
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////

	// ����̨ //////////////////////////////////////////////////////////////////////////
	layerWorkbench = LayerWorkbench::create();
	addChild(layerWorkbench);
	//////////////////////////////////////////////////////////////////////////

	addKeyboardEventListener();

	// �����֡������
	this->scheduleUpdate();

	// �����Ϣ����ѭ��
	this->schedule(schedule_selector(SceneGameMain::messagePushLoop), 0.5f, kRepeatForever, 0);

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
	// �������� //////////////////////////////////////////////////////////////////////////
	if (
		PathController::Instance()->getCurrentState() == PathController::State_Ready ||
		PathController::Instance()->getCurrentState() == PathController::State_Working
		)
	{
		PathController::Instance()->planning();
	}
	if (PathController::Instance()->getCurrentState() == PathController::State_Done)
	{
		CharacterController::Instance()->getRole()->setPosition(
			PathController::Instance()->getNextStepByCurrentPosition(
			CharacterController::Instance()->getRole()->getPosition()
			)
			);
		layerMap->getSpriteRole()->updatePosition();
	}
	//////////////////////////////////////////////////////////////////////////
	// ��Ϣ����ģ�� //////////////////////////////////////////////////////////////////////////
	auto msg = InteractiveMessagePQ::Instance()->getTopMessage();
	if (msg != nullptr)
	{
		switch (msg->getID())
		{
		case InteractiveMessagePQ::InteractiveMessageID_Update_LayerMapPosition:
			layerMap->updateGlobalMapPositionByAction();
			break;
		case InteractiveMessagePQ::InteractiveMessageID_Explore_PutCard_Road_TintT:
			layerWorkbench->executeAddCard(msg->getExtras<int>());
			break;
		case InteractiveMessagePQ::InteractiveMessageID_Explore_PutCardFail_Road_CardPollEmpty:
			log("[warning] ̽�������£�����ʧ�ܣ���Ϊ����Ϊ�գ�");
			break;
		case InteractiveMessagePQ::InteractiveMessageID_Explore_PutCardFail_Road_HandCardFull:
			log("[warning] ̽�������£�����ʧ�ܣ���Ϊ����������");
			break;
		default:
			break;
		}
		InteractiveMessagePQ::Instance()->popTopMessage();
	}
	//////////////////////////////////////////////////////////////////////////
	Bridge::Instance()->update(dt);
	//log("[information] �뿪 SceneGameMain ��������֡������");
}

void SceneGameMain::messagePushLoop(float dt)
{
	if (loopMessage != InteractiveMessagePQ::InteractiveMessageID_ValidID)
		Bridge::Instance()->pushMessage2Logic(loopMessage);
}

void SceneGameMain::addKeyboardEventListener()
{
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(SceneGameMain::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(SceneGameMain::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void SceneGameMain::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_W:
		loopMessage = InteractiveMessagePQ::InteractiveMessageID_OP_DragMap_Down;
		break;
	case EventKeyboard::KeyCode::KEY_S:
		loopMessage = InteractiveMessagePQ::InteractiveMessageID_OP_DragMap_Up;
		break;
	case EventKeyboard::KeyCode::KEY_A:
		loopMessage = InteractiveMessagePQ::InteractiveMessageID_OP_DragMap_Right;
		break;
	case EventKeyboard::KeyCode::KEY_D:
		loopMessage = InteractiveMessagePQ::InteractiveMessageID_OP_DragMap_Left;
		break;
	default:
		break;
	}
}

void SceneGameMain::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_W:
		if (loopMessage == InteractiveMessagePQ::InteractiveMessageID_OP_DragMap_Down)
			loopMessage = InteractiveMessagePQ::InteractiveMessageID_ValidID;
		break;
	case EventKeyboard::KeyCode::KEY_S:
		if (loopMessage == InteractiveMessagePQ::InteractiveMessageID_OP_DragMap_Up)
			loopMessage = InteractiveMessagePQ::InteractiveMessageID_ValidID;
		break;
	case EventKeyboard::KeyCode::KEY_A:
		if (loopMessage == InteractiveMessagePQ::InteractiveMessageID_OP_DragMap_Right)
			loopMessage = InteractiveMessagePQ::InteractiveMessageID_ValidID;
		break;
	case EventKeyboard::KeyCode::KEY_D:
		if (loopMessage == InteractiveMessagePQ::InteractiveMessageID_OP_DragMap_Left)
			loopMessage = InteractiveMessagePQ::InteractiveMessageID_ValidID;
		break;
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		Director::getInstance()->end();
		break;
	default:
		break;
	}
}