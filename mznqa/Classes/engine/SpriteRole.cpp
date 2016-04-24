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

float SpriteRole::timeSpriteMoveByMap = 0.1;

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
	// 设置精灵锚点为左上角
	this->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
	// 设置角色精灵的初始位置 //////////////////////////////////////////////////////////////////////////
	int x = 0, y = 0;
	x = Role::Instance()->getPositionX();
	y = Role::Instance()->getPositionY();
	this->setPosition(Vec2(gX2CartesianX(x), gY2CartesianY(y)));
	//////////////////////////////////////////////////////////////////////////
}

void SpriteRole::refreshPosition()
{
	// 获取角色精灵现应在的位置 //////////////////////////////////////////////////////////////////////////
	int x = 0, y = 0;
	x = Role::Instance()->getPositionX();
	y = Role::Instance()->getPositionY();
	//////////////////////////////////////////////////////////////////////////

	// 停下所有同Flag动作
	this->stopActionsByFlags(ActionFlags_MoveTo);
	// 创建动作
	auto action = MoveTo::create(
		timeSpriteMoveByMap,
		Vec2(
		gX2CartesianX(x),
		gY2CartesianY(y)
		)
		);
	// 设置 Flags
	action->setFlags(ActionFlags_MoveTo);
	// 执行动作
	this->runAction(action);
}