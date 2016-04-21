#pragma execution_character_set("utf-8")

#include "engine/SpriteRole.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "gameobject/Role.h"
#include "engine/GlobalFun.h"
#include "map/MapController.h"
#include "define/GlobalDefine.h"
#include "map/MapView.h"

USING_NS_CC;
using namespace cocostudio::timeline;

SpriteRole * SpriteRole::create(const std::string &filename)
{
	SpriteRole *sprite = new SpriteRole();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void SpriteRole::initialize()
{
	this->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
	int x = 0, y = 0;
	x = Role::Instance()->getPositionX();
	y = Role::Instance()->getPositionY();
	this->setPosition(Vec2(gX2CartesianX(x), gY2CartesianY(y)));
}

void SpriteRole::refreshPosition()
{
	int x = 0, y = 0;
	x = Role::Instance()->getPositionX();
	y = Role::Instance()->getPositionY();
	this->stopActionsByFlags(1);
	auto ac = MoveTo::create(0.3,
		Vec2(
			gX2CartesianX(x),
			gY2CartesianY(y)
			)
		);
	ac->setFlags(1);
	this->runAction(ac);
	cocos2d::log("[information] 角色当前坐标：（%f,%f）", 0.0 - MapView::Instance()->getLeftTopGX()*MAP_CELL_SIZE + gX2CartesianX(x), DESIGNRESOLUTIONSIZE_HEIGHT + MapView::Instance()->getLeftTopGY()*MAP_CELL_SIZE + gY2CartesianY(y));
}