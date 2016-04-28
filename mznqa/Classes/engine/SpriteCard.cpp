#pragma execution_character_set("utf-8")

#include "engine/SpriteCard.h"

#include <memory>

#include "message/EngineMessagePQ.h"

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
	background->setPosition(Vec2(75.0, 100.0));
	this->addChild(background);

	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
}

void SpriteCard::addEventListener(const EventIndex &eventIndex)
{
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(SpriteCard::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(SpriteCard::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(SpriteCard::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	this->eventIndex = eventIndex;
}

bool SpriteCard::onTouchBegan(Touch *touch, Event *nused_event)
{
	// 获取事件所绑定的 target
	auto target = static_cast<SpriteCard*>(nused_event->getCurrentTarget());

	// 获取当前点击点所在相对按钮的位置坐标
	Point locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	// 点击范围判断检测
	if (!rect.containsPoint(locationInNode))
		return false;

	std::shared_ptr<EventIndex> ei = std::make_shared<EventIndex>(this->eventIndex);
	EngineMessagePQ::Instance()->pushMessage(Message < EngineMessagePQ::EMessage>(
		EngineMessagePQ::EMessage_SpriteCard_TouchEvent_TouchBegan_TSpriteCardEventIndexT,
		ei.get()
		));
	cocos2d::log("[warning] SpriteCard(%d)::onTouchBegan()", (int)(this->eventIndex));
	return true;
}

void SpriteCard::onTouchMoved(Touch *touch, Event *unused_event)
{
	std::shared_ptr<EventIndex> ei = std::make_shared<EventIndex>(this->eventIndex);
	EngineMessagePQ::Instance()->pushMessage(Message < EngineMessagePQ::EMessage>(
		EngineMessagePQ::EMessage_SpriteCard_TouchEvent_TouchMoved_TSpriteCardEventIndexT,
		ei.get()
		));
	cocos2d::log("[warning] SpriteCard(%d)::onTouchMoved()", (int)(this->eventIndex));
}

void SpriteCard::onTouchEnded(Touch *touch, Event *unused_event)
{
	std::shared_ptr<EventIndex> ei = std::make_shared<EventIndex>(this->eventIndex);
	EngineMessagePQ::Instance()->pushMessage(Message < EngineMessagePQ::EMessage>(
		EngineMessagePQ::EMessage_SpriteCard_TouchEvent_TouchEnded_TSpriteCardEventIndexT,
		ei.get()
		));
	cocos2d::log("[warning] SpriteCard(%d)::onTouchEnded()", (int)(this->eventIndex));
}