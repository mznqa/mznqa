#pragma execution_character_set("utf-8")

#include "engine/SpriteRole.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

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
	this->setPosition(Vec2(SizeControllerInstance->gX2CartesianX(x) + SizeControllerInstance->designMapCellSize / 2.0, SizeControllerInstance->gY2CartesianY(y) - SizeControllerInstance->designMapCellSize / 2.0));
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
		SizeControllerInstance->gX2CartesianX(x) + SizeControllerInstance->designMapCellSize / 2.0,
		SizeControllerInstance->gY2CartesianY(y) - SizeControllerInstance->designMapCellSize / 2.0
		)
		);
	// ���� Flags
	action->setFlags(ActionFlags_MoveTo);
	// ִ�ж���
	this->runAction(action);
}