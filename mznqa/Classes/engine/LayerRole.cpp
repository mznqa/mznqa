#pragma execution_character_set("utf-8")

#include "engine/LayerRole.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "gameobject/Role.h"
#include "engine/GlobalFun.h"
#include "map/MapController.h"
#include "define/GlobalDefine.h"
#include "map/MapView.h"

USING_NS_CC;
using namespace cocostudio::timeline;

bool LayerRole::init()
{
	if (!Layer::init())
	{
		return false;
	}

	loadRole();

	return true;
}

void LayerRole::loadRole()
{
	roleSprite = Sprite::create("test_map_cell/player.png");
	roleSprite->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
	int x = 0, y = 0;
	x = Role::Instance()->getPositionX();
	y = Role::Instance()->getPositionY();
	roleSprite->setPosition(Vec2(gX2CartesianX(x), gY2CartesianY(y)));
	addChild(roleSprite);
}

void LayerRole::refresh()
{
	int x = 0, y = 0;
	x = Role::Instance()->getPositionX();
	y = Role::Instance()->getPositionY();
	//roleSprite->stopActionsByFlags(1);
	MapView *mapView = MapController::Instance()->mapView;
	auto ac = MoveTo::create(0.3,
		Vec2(0.0 - mapView->getLeftTopGX()*MAP_CELL_SIZE + gX2CartesianX(x), DESIGNRESOLUTIONSIZE_HEIGHT + mapView->getLeftTopGY()*MAP_CELL_SIZE + gY2CartesianY(y))
		);
	ac->setFlags(1);
	roleSprite->runAction(ac);
	cocos2d::log("[information] 角色当前坐标：（%f,%f）", 0.0 - mapView->getLeftTopGX()*MAP_CELL_SIZE + gX2CartesianX(x), DESIGNRESOLUTIONSIZE_HEIGHT + mapView->getLeftTopGY()*MAP_CELL_SIZE + gY2CartesianY(y));
}