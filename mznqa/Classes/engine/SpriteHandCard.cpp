#pragma execution_character_set("utf-8")

#include "engine/SpriteHandCard.h"

#include "message/EngineMessagePQ.h"
#include "tools/GXY.h"

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
	spriteBackground = Sprite::createWithSpriteFrameName("temp/card_background_cardroad.png");
	spriteBackground->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	spriteBackground->setPosition(Vec2(75.0, 100.0));
	this->addChild(spriteBackground);

	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);

	state = HandCardState_AtStateWorkBench;
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
		EngineMessagePQ::EMessage_SpriteHandCard_TouchEvent_TouchBegan_TSpriteHandCardEventIndexT,
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
		EngineMessagePQ::EMessage_SpriteHandCard_TouchEvent_TouchMoved_TSpriteHandCardEventIndexT,
		ei
		));

	if (touch->getDelta().x > 16.0 && touch->getDelta().y > 9.0)
	{
		if (state == HandCardState_AtStateShow)
		{
			state = HandCardState_AtEntity;
			makeEntity();
		}
	}
	if (state == HandCardState_AtEntity)
	{
		this->setPosition(touch->getLocation());
	}
	cocos2d::log("[warning] SpriteHandCard(%d)::onTouchMoved()", (int)(this->eventIndex));
}

void SpriteHandCard::onTouchEnded(Touch *touch, Event *unused_event)
{
	EventIndex *ei = new EventIndex();
	*ei = this->eventIndex;
	EngineMessagePQ::Instance()->pushMessage(Message < EngineMessagePQ::EMessage>(
		EngineMessagePQ::EMessage_SpriteHandCard_TouchEvent_TouchEnded_TSpriteHandCardEventIndexT,
		ei
		));

	if (state == HandCardState_AtEntity)
	{
		int *pIndex = new int(eventIndex);
		EngineMessagePQ::Instance()->pushMessage(Message<EngineMessagePQ::EMessage>(
			EngineMessagePQ::EMessage_RemoveHandCardByIndex_TIntT,
			pIndex
			));
		GXY *gPoint = new GXY(SizeControllerInstance->cartesianX2GX(touch->getLocation().x), SizeControllerInstance->cartesianY2GY(touch->getLocation().y));
		EngineMessagePQ::Instance()->pushMessage(Message<EngineMessagePQ::EMessage>(
			EngineMessagePQ::EMessage_PutCardRoad_TGXYT,
			gPoint
			));
	}
	cocos2d::log("[warning] SpriteHandCard(%d)::onTouchEnded()", (int)(this->eventIndex));
}

void SpriteHandCard::changeState(HandCardState state)
{
	this->state = state;
}

SpriteHandCard::HandCardState SpriteHandCard::getState()
{
	return state;
}

void SpriteHandCard::makeEntity()
{
	spriteBackground->setVisible(false);
	spriteEntity = Sprite::createWithSpriteFrameName("temp/map_cell_1234.png");
	spriteEntity->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	spriteEntity->setPosition(Vec2(75.0, 100.0));
	this->addChild(spriteEntity);
	this->setScaleX(60.0 / 100.0);
	this->setScaleY(50.0 / 100.0);
}