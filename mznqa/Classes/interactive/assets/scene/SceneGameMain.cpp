/*!
 * \file	Classes\interactive\assets\scene\SceneGameMain.cpp
 *
 * \brief	������ SceneGameMain
 */

#pragma execution_character_set("utf-8")

#include "interactive/assets/scene/SceneGameMain.h"
#include "interactive/manager/TargetInfo.h"
#include "helper/bridge/Bridge.h"
#include "interactive/message/InteractiveMessagePQ.h"

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
	CardArray3<CardRoad, CardSkill, CardMonster, 10> ca;
	ca.add(0);
	ca.add(1);
	ca.add(2);
	ca.add(1000);
	ca.add(1001);
	ca.add(1002);
	ca.add(2000);
	ca.add(2001);
	ca.add(2002);
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
	//log("[information] �뿪 SceneGameMain ��������֡������");
}