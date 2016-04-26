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
	// ���þ���ê��Ϊ���Ͻ�
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	// ���ý�ɫ����ĳ�ʼλ�� //////////////////////////////////////////////////////////////////////////
	int x = 0, y = 0;
	x = RoleInstance->getPositionX();
	y = RoleInstance->getPositionY();
	this->setPosition(Vec2(gX2CartesianX(x) + MAP_CELL_SIZE_HALF, gY2CartesianY(y) - MAP_CELL_SIZE_HALF));
	//////////////////////////////////////////////////////////////////////////
}

void SpriteRole::refreshPosition()
{
	// ��ȡ��ɫ������Ӧ�ڵ�λ�� //////////////////////////////////////////////////////////////////////////
	int x = 0, y = 0;
	x = RoleInstance->getPositionX();
	y = RoleInstance->getPositionY();
	//////////////////////////////////////////////////////////////////////////

	// ͣ������ͬFlag����
	this->stopActionsByFlags(ActionFlags_MoveTo);
	// ��������
	auto action = MoveTo::create(
		TimeSpriteMoveByMap,
		Vec2(
		gX2CartesianX(x) + MAP_CELL_SIZE_HALF,
		gY2CartesianY(y) - MAP_CELL_SIZE_HALF
		)
		);
	// ���� Flags
	action->setFlags(ActionFlags_MoveTo);
	// ִ�ж���
	this->runAction(action);
}