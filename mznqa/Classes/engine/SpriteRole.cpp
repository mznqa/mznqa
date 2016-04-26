#pragma execution_character_set("utf-8")

#include "engine/SpriteRole.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "engine/GlobalFun.h"

USING_NS_CC;
using namespace cocostudio::timeline;

const float SpriteRole::TimeSpriteMoveByMap = 0.1f;

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

SpriteRole* SpriteRole::createWithSpriteFrameName(const std::string &spriteFrameName)
{
	SpriteRole *sprite = new SpriteRole();
	if (sprite && sprite->initWithSpriteFrameName(spriteFrameName))
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
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	// 设置角色精灵的初始位置 //////////////////////////////////////////////////////////////////////////
	int x = 0, y = 0;
	x = RoleInstance->getPositionX();
	y = RoleInstance->getPositionY();
	this->setPosition(Vec2(gX2CartesianX(x) + MAP_CELL_SIZE_HALF, gY2CartesianY(y) - MAP_CELL_SIZE_HALF));
	//////////////////////////////////////////////////////////////////////////
}

void SpriteRole::refreshPosition()
{
	// 获取角色精灵现应在的位置 //////////////////////////////////////////////////////////////////////////
	int x = 0, y = 0;
	x = RoleInstance->getPositionX();
	y = RoleInstance->getPositionY();
	//////////////////////////////////////////////////////////////////////////

	// 停下所有同Flag动作
	this->stopActionsByFlags(ActionFlags_MoveTo);
	// 创建动作
	auto action = MoveTo::create(
		TimeSpriteMoveByMap,
		Vec2(
		gX2CartesianX(x) + MAP_CELL_SIZE_HALF,
		gY2CartesianY(y) - MAP_CELL_SIZE_HALF
		)
		);
	// 设置 Flags
	action->setFlags(ActionFlags_MoveTo);
	// 执行动作
	this->runAction(action);
}