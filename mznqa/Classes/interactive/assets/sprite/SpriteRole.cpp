/*!
 * \file	Classes\interactive\assets\sprite\SpriteRole.cpp
 *
 * \brief	定义类 SpriteRole
 */

#pragma execution_character_set("utf-8")

#include "interactive/assets/sprite/SpriteRole.h"

#include "logic/controller/CharacterController.h"
#include "interactive/manager/GlobalManager.h"

USING_NS_CC;

SpriteRole* SpriteRole::create()
{
	SpriteRole *sprite = new SpriteRole();
	// TODO 待规整文件路径
	if (sprite && sprite->initWithSpriteFrameName("game_object/role.png"))
	{
		sprite->autorelease();

		sprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE);

		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

bool SpriteRole::updatePosition()
{
	this->setPosition(Vec2(
		(CharacterController::Instance()->getRole()->getPosition().x*MAPCELL_SIZE + this->getContentSize().width * 0.5),
		-(CharacterController::Instance()->getRole()->getPosition().y*MAPCELL_SIZE + this->getContentSize().height * 0.5)
		));
	return true;
}

void SpriteRole::createLightArea()
{
	lightArea.setLightPosition(
		CharacterController::Instance()->getRole()->getPosition()
		);
	lightArea.setLightScopeRadius(5);
}

LightArea& SpriteRole::getLightArea()
{
	return lightArea;
}