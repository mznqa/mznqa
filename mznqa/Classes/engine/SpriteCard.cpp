#pragma execution_character_set("utf-8")

#include "engine/SpriteCard.h"

USING_NS_CC;

SpriteCard* SpriteCard::create(/*const std::string &filename*/)
{
	SpriteCard *sprite = new SpriteCard();
	if (sprite && sprite->initWithSpriteFrameName("temp/card_base.png"))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void SpriteCard::initialize()
{
	background = Sprite::createWithSpriteFrameName("temp/card_background_cardroad.png");
	background->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	background->setPosition(Vec2(96.0, 128.0));
	this->addChild(background);

	this->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
}