/*!
 * \file	Classes\interactive\assets\layer\LayerWorkbench.cpp
 *
 * \brief	定义类 LayerWorkbench
 */

#pragma execution_character_set("utf-8")

#include "interactive/assets/layer/LayerWorkbench.h"

#include "interactive/manager/TargetInfo.h"
#include "logic/controller/CharacterController.h"
#include "interactive/message/InteractiveMessagePQ.h"
#include "helper/bridge/Bridge.h"

USING_NS_CC;

std::array<Vec2, EXPLORE_CARDHOLDERSIZE> LayerWorkbench::cardPositionSet;

bool LayerWorkbench::init()
{
	if (!Layer::init())
	{
		return false;
	}

	buildBackground();
	buildButtonDraw();
	buildCardSet();
	addGlobalEventListener();

	return true;
}

void LayerWorkbench::addGlobalEventListener()
{
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(LayerWorkbench::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(LayerWorkbench::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(LayerWorkbench::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}

bool LayerWorkbench::onTouchBegan(Touch *touch, Event *unused_event)
{
	// 获取当前点击点所在相对精灵的位置坐标
	Point locationInNode = background->convertToNodeSpace(touch->getLocation());
	Size s = background->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	// 点击范围判断检测
	if (!rect.containsPoint(locationInNode))
	{
		disshowAllHandCard();
		return false;
	}

	// cocos2d::log("[warning] LayerWorkbench::onTouchBegan()");
	return true;
}

void LayerWorkbench::onTouchMoved(Touch *touch, Event *unused_event)
{
	// cocos2d::log("[warning] LayerWorkbench::onTouchMoved()");
}

void LayerWorkbench::onTouchEnded(Touch *touch, Event *unused_event)
{
	// cocos2d::log("[warning] LayerWorkbench::onTouchEnded()");
}

void LayerWorkbench::buildBackground()
{
	// TODO 待规整文件路径
	background = Sprite::createWithSpriteFrameName("workbench/background.png");
	background->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	// TODO 待规整坐标
	background->setPosition(Vec2(
		TargetInfo::Instance()->getScreenSize().width * 0.5,
		TargetInfo::Instance()->getScreenSize().height * 0.001
		));
	addChild(background);

	auto size = background->getContentSize();
	cardPositionSet[0] = Vec2(size.width * 0.26847, size.height * 0.53);
	cardPositionSet[1] = Vec2(size.width * 0.4277, size.height * 0.53);
	cardPositionSet[2] = Vec2(size.width * 0.586, size.height * 0.53);
	cardPositionSet[3] = Vec2(size.width * 0.7450, size.height * 0.53);
	cardPositionSet[4] = Vec2(size.width * 0.9043, size.height * 0.53);
}

void LayerWorkbench::buildButtonDraw()
{
	buttonDraw = ui::Button::create();
	// TODO 待规整的文件路径
	buttonDraw->loadTextureNormal("workbench/button_draw_normal.png", ui::Widget::TextureResType::PLIST);
	// TODO 待规整的文件路径
	buttonDraw->loadTexturePressed("workbench/button_draw_pressed.png", ui::Widget::TextureResType::PLIST);
	// TODO 待规整的文件路径
	buttonDraw->loadTextureDisabled("workbench/button_draw_disabled.png", ui::Widget::TextureResType::PLIST);
	buttonDraw->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	// TODO 待规整坐标
	buttonDraw->setPosition(Vec2(
		background->getContentSize().width * 0.0925,
		background->getContentSize().height * 0.457
		));
	buttonDraw->addClickEventListener([](Ref*){
		Bridge::Instance()->pushMessage2Logic(InteractiveMessagePQ::InteractiveMessageID_ButtonClicked_Explore_DrawCard);
	});
	background->addChild(buttonDraw);
}

void LayerWorkbench::buildCardSet()
{
	auto holderCardIDSet = CharacterController::Instance()->getRole()->getCardControllerExplore().getHolderCardIDSet();

	auto it = holderCardIDSet.cbegin();
	auto itEnd = holderCardIDSet.cend();
	int i = 0;
	while (it != itEnd)
	{
		if (*it == CardBase::invalidCardID)
			cardSet[i] = nullptr;
		else
		{
			cardSet[i] = SpriteCard::create(*it);
			cardSet[i]->addEventListener(SpriteCard::EventIndex(i));
			cardSet[i]->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
			cardSet[i]->setPosition(cardPositionSet[i]);
			background->addChild(cardSet[i], CardSpriteZOrder, cardSpriteTag);
			cardSetShowState[i] = false;
		}
		++i;
		++it;
	}
}

void LayerWorkbench::executeAddCard(int index)
{
	if (0 > index || index >= EXPLORE_CARDHOLDERSIZE)
		return;

	if (cardSet[index] != nullptr)
		return;

	int cardID = CharacterController::Instance()->getRole()->getCardControllerExplore().getHolderCardIDSet().at(index);

	cardSet[index] = SpriteCard::create(cardID);
	cardSet[index]->addEventListener(SpriteCard::EventIndex(index));
	cardSet[index]->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	cardSet[index]->setPosition(cardPositionSet[index]);
	background->addChild(cardSet[index], CardSpriteZOrder, cardSpriteTag);
	cardSetShowState[index] = false;
}

void LayerWorkbench::showHandCard(int cardIndex)
{
	if (0 <= cardIndex && cardIndex < EXPLORE_CARDHOLDERSIZE)
	{
		disshowAllHandCard();
		if (cardSet[cardIndex] != nullptr)
		{
			cardSet[cardIndex]->setPosition(
				cardSet[cardIndex]->getPosition().x,
				cardSet[cardIndex]->getPosition().y + cardSet[cardIndex]->getContentSize().width * 0.5
				);
			cardSet[cardIndex]->setScale(2.0);
			cardSet[cardIndex]->setZOrder(CardSpriteShowZOrder);
			cardSetShowState[cardIndex] = true;
		}
	}
}

void LayerWorkbench::disshowAllHandCard()
{
	for (int i = 0; i < EXPLORE_CARDHOLDERSIZE; ++i)
	{
		if (cardSet[i] != nullptr && cardSetShowState[i] == true)
		{
			cardSet[i]->setPosition(cardPositionSet[i]);
			cardSet[i]->setScale(1.0);
			cardSet[i]->setZOrder(CardSpriteZOrder);
			cardSetShowState[i] = false;
		}
	}
}