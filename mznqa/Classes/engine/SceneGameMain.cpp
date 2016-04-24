#pragma execution_character_set("utf-8")

#include "engine/SceneGameMain.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "filePath/SceneFilePath.h"
#include "runtime/SceneGameMainState.h"
#include "staticData/MissionMapSet.h"
#include "define/GlobalDefine.h"
#include "gameobject/Role.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* SceneGameMain::createScene()
{
	auto scene = Scene::create();

	auto layer = SceneGameMain::create();

	scene->addChild(layer);

	return scene;
}

// ��������ʱ�ĳ�ʼ������
bool SceneGameMain::init()
{
	log("[information] ���� SceneGameMain ������...");

	if (!Layer::init())
	{
		return false;
	}

	MapController::Instance()->setEmptyMap();
	MapController::Instance()->loadMapNode(MissionMapSet::Instance()->getMainMissionMapByIndex(0));

	layerMap = LayerMap::create();

	layerMap->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);

	float dv = 1.0;

	layerMap->setScale(dv);

	layerMap->setPosition(Vec2(0, 0));// DESIGNRESOLUTIONSIZE_HEIGHT* dv));

	addChild(layerMap);

	auto ckx = Sprite::create("test_map_cell/cellx192.png");
	ckx->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
	ckx->setPosition(Vec2(0, DESIGNRESOLUTIONSIZE_HEIGHT));
	addChild(ckx);

	Role::Instance()->setPosition(10, 7);

	spriteRole = SpriteRole::create("test_map_cell/player.png");

	spriteRole->initialize();

	addChild(spriteRole);

	this->scheduleUpdate();

	log("[information] ���� SceneGameMain �����ɹ�");

	return true;
}

// ���볡��ʱ�Ĳ���
void SceneGameMain::onEnter()
{
	log("[information] ׼�����볡�� SceneGameMain ��...");
	// ���ȣ����û��෽��
	Layer::onEnter();
	// ���ó���״̬����
	SceneGameMainState::Instance()->enter(this);

	log("[information] ���볡�� SceneGameMain �ɹ�");
}

// �뿪����ʱ�Ĳ���
void SceneGameMain::onExit()
{
	log("[information] ׼���뿪���� SceneGameMain ��...");
	// ���ȣ����û��෽��
	Layer::onExit();
	// ���ó���״̬����
	SceneGameMainState::Instance()->exit(this);
	log("[information] �뿪���� SceneGameMain �ɹ�");
}

void SceneGameMain::update(float dt)
{
	SceneGameMainState::Instance()->update(this, TIME_INVALIDVALUE);
}