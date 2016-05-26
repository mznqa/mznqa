/*!
 * \file	Classes\interactive\assets\sprite\SpriteCard.cpp
 *
 * \brief	定义类 SpriteCard
 */

#pragma execution_character_set("utf-8")

#include "interactive/assets/sprite/SpriteCard.h"

#include "interactive/message/InteractiveMessagePQ.h"

USING_NS_CC;

SpriteCard* SpriteCard::create(int cardID)
{
	SpriteCard *background = new SpriteCard();
	// TODO 待规整文件路径
	if (background && background->initWithSpriteFrameName("card/common/background.png"))
	{
		background->autorelease();

		background->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);

		// TODO 待规整文件路径
		Sprite *labelName = Sprite::createWithSpriteFrameName("card/common/label_card_road.png");
		labelName->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
		labelName->setPosition(Vec2(
			background->getContentSize().width * 0.0f,
			background->getContentSize().height * 1.0f
			));
		background->addChild(labelName);

		return background;
	}
	CC_SAFE_DELETE(background);
	return nullptr;
}

void SpriteCard::addEventListener(EventIndex eventIndex)
{
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(SpriteCard::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(SpriteCard::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(SpriteCard::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	this->eventIndex = eventIndex;
}

bool SpriteCard::onTouchBegan(Touch *touch, Event *unused_event)
{
	// 获取事件所绑定的 target
	auto target = static_cast<SpriteCard*>(unused_event->getCurrentTarget());

	// 获取当前点击点所在相对精灵的位置坐标
	Point locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	// 点击范围判断检测
	if (!rect.containsPoint(locationInNode))
		return false;

	InteractiveMessagePQ::Instance()->pushMessage(ArKCa::Message<InteractiveMessagePQ::InteractiveMessageID>(
		InteractiveMessagePQ::InteractiveMessageID_OP_ClickHandCard_AtLayerWorkbench_TintT,
		(int)eventIndex
		));

	cocos2d::log("[warning] SpriteCard(%d)::onTouchBegan()", (int)(this->eventIndex));
	return true;
}

void SpriteCard::onTouchMoved(Touch *touch, Event *unused_event)
{
	cocos2d::log("[warning] SpriteCard(%d)::onTouchMoved()", (int)(this->eventIndex));
}

void SpriteCard::onTouchEnded(Touch *touch, Event *unused_event)
{
	cocos2d::log("[warning] SpriteCard(%d)::onTouchEnded()", (int)(this->eventIndex));
}