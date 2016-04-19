#pragma execution_character_set("utf-8")

#include "engine/SceneGameMain.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "filePath/SceneFilePath.h"
#include "runtime/SceneGameMainState.h"
#include "engine/LayerMap.h"
#include "staticData/MissionMapSet.h"
#include "define/GlobalDefine.h"
#include "engine/LayerRole.h"
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

// 场景创建时的初始化操作
bool SceneGameMain::init()
{
	log("[information] 场景 SceneGameMain 启动中...");

	if (!Layer::init())
	{
		return false;
	}

	MapController::Instance()->setEmptyMap();
	MapController::Instance()->loadMapNode(MissionMapSet::Instance()->getMainMissionMapByIndex(0));

	LayerMap *lm = LayerMap::create();

	lm->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);

	float dv = 1.0;

	lm->setScale(dv);

	lm->setPosition(Vec2(0, DESIGNRESOLUTIONSIZE_HEIGHT* dv));

	addChild(lm);

	auto ckx = Sprite::create("test_map_cell/cellx192.png");
	ckx->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
	ckx->setPosition(Vec2(0, DESIGNRESOLUTIONSIZE_HEIGHT));
	addChild(ckx);

	Role::Instance()->setPosition(10, 7);
	layerRole = LayerRole::create();

	layerRole->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);

	layerRole->setPosition(Vec2(0, 0));

	addChild(layerRole);

	this->scheduleUpdate();

	log("[information] 场景 SceneGameMain 启动成功");

	return true;
}

// 进入场景时的操作
void SceneGameMain::onEnter()
{
	log("[information] 准备进入场景 SceneGameMain 中...");
	// 首先，调用基类方法
	Layer::onEnter();
	// 调用场景状态方法
	SceneGameMainState::Instance()->enter(this);

	log("[information] 进入场景 SceneGameMain 成功");
}

// 离开场景时的操作
void SceneGameMain::onExit()
{
	log("[information] 准备离开场景 SceneGameMain 中...");
	// 首先，调用基类方法
	Layer::onExit();
	// 调用场景状态方法
	SceneGameMainState::Instance()->exit(this);
	log("[information] 离开场景 SceneGameMain 成功");
}

void SceneGameMain::update(float dt)
{
	layerRole->refresh();
}