#pragma execution_character_set("utf-8")

#include "engine/SpriteHandCard.h"

#include "message/EngineMessagePQ.h"

USING_NS_CC;

SpriteHandCard* SpriteHandCard::create(/*const std::string &filename*/)
{
	SpriteHandCard *sprite = new SpriteHandCard();
	if (sprite && sprite->initWithSpriteFrameName("temp/card_base.png"))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void SpriteHandCard::initialize()
{
	background = Sprite::createWithSpriteFrameName("temp/card_background_cardroad.png");
	background->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	background->setPosition(Vec2(75.0, 100.0));
	this->addChild(background);

	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
}

void SpriteHandCard::addEventListener(const EventIndex &eventIndex)
{
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(SpriteHandCard::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(SpriteHandCard::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(SpriteHandCard::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	this->eventIndex = eventIndex;
}

bool SpriteHandCard::onTouchBegan(Touch *touch, Event *nused_event)
{
	// 获取事件所绑定的 target
	auto target = static_cast<SpriteHandCard*>(nused_event->getCurrentTarget());

	// 获取当前点击点所在相对按钮的位置坐标
	Point locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	// 点击范围判断检测
	if (!rect.containsPoint(locationInNode))
		return false;

	EventIndex *ei = new EventIndex();
	*ei = this->eventIndex;
	EngineMessagePQ::Instance()->pushMessage(Message<EngineMessagePQ::EMessage>(
		EngineMessagePQ::EMessage_SpriteCard_TouchEvent_TouchBegan_TSpriteCardEventIndexT,
		ei
		));
	cocos2d::log("[warning] SpriteHandCard(%d)::onTouchBegan()", (int)(this->eventIndex));
	return true;
}

void SpriteHandCard::onTouchMoved(Touch *touch, Event *unused_event)
{
	EventIndex *ei = new EventIndex();
	*ei = this->eventIndex;
	EngineMessagePQ::Instance()->pushMessage(Message < EngineMessagePQ::EMessage>(
		EngineMessagePQ::EMessage_SpriteCard_TouchEvent_TouchMoved_TSpriteCardEventIndexT,
		ei
		));
	cocos2d::log("[warning] SpriteHandCard(%d)::onTouchMoved()", (int)(this->eventIndex));
}

void SpriteHandCard::onTouchEnded(Touch *touch, Event *unused_event)
{
	EventIndex *ei = new EventIndex();
	*ei = this->eventIndex;
	EngineMessagePQ::Instance()->pushMessage(Message < EngineMessagePQ::EMessage>(
		EngineMessagePQ::EMessage_SpriteCard_TouchEvent_TouchEnded_TSpriteCardEventIndexT,
		ei
		));
	cocos2d::log("[warning] SpriteHandCard(%d)::onTouchEnded()", (int)(this->eventIndex));
}