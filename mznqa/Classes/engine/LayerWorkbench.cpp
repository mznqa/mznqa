#pragma execution_character_set("utf-8")

#include "engine/LayerWorkbench.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "filePath/FilePathLayer.h"

USING_NS_CC;
using namespace cocostudio::timeline;

const std::array<float, 5> LayerWorkbench::handCardPositionXSet = { 684.0f, 874.0f, 1064.0f, 1254.0f, 1444.0f };
const float LayerWorkbench::handCardPositionY = 50.0f;

const std::array<float, 5> LayerWorkbench::handCardShowStatePositionXSet = { 684.0f, 874.0f, 1064.0f, 1254.0f, 1444.0f };
const float LayerWorkbench::handCardShowStatePositionY = 200.0f;

bool LayerWorkbench::init()
{
	if (!Layer::init())
	{
		return false;
	}

	rootNode = CSLoader::createNode(FILE_PATH_LAYER_WORKBENCH);
	addChild(rootNode);

	addGlobalEventListener();

	return true;
}

bool LayerWorkbench::onTouchBegan(Touch *touch, Event *unused_event)
{
	cocos2d::log("[warning] LayerWorkbench::onTouchBegan()");
	bool effective = restoreAllHandCard();
	return effective;
}

void LayerWorkbench::onTouchMoved(Touch *touch, Event *unused_event)
{
	cocos2d::log("[warning] LayerWorkbench::onTouchMoved()");
}

void LayerWorkbench::onTouchEnded(Touch *touch, Event *unused_event)
{
	cocos2d::log("[warning] LayerWorkbench::onTouchEnded()");
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

bool LayerWorkbench::restoreAllHandCard()
{
	auto it = handCardSet.begin();
	auto itEnd = handCardSet.end();
	int i = 0;
	bool state = false;
	while (it != itEnd)
	{
		if (*it != nullptr && (*it)->getState() != SpriteHandCard::HandCardState_AtStateWorkBench)
		{
			(*it)->stopAllActions();
			(*it)->setZOrder(i);
			//(*it)->setPosition(Vec2(handCardPositionXSet[i], handCardPositionY));
			//(*it)->setScale(1.0f);
			(*it)->runAction(MoveTo::create(0.05f, Vec2(handCardPositionXSet[i], handCardPositionY)));
			(*it)->runAction(ScaleTo::create(0.1f, 1.0f));
			(*it)->changeState(SpriteHandCard::HandCardState_AtStateWorkBench);
			state = true;
		}
		++i;
		++it;
	}
	return state;
}

void LayerWorkbench::showHandCardByIndex(int index)
{
	if (0 > index || index >= handCardSet.size())
		return;

	if (handCardSet[index] == nullptr)
		return;

	if (handCardSet[index]->getState() == SpriteHandCard::HandCardState_AtStateShow)
		return;

	restoreAllHandCard();

	handCardSet[index]->stopAllActions();
	handCardSet[index]->setZOrder(5);
	//handCardSet[index]->setPosition(Vec2(handCardShowStatePositionXSet[index], handCardShowStatePositionY));
	//handCardSet[index]->setScale(2.0f);
	handCardSet[index]->runAction(MoveTo::create(0.15f, Vec2(handCardShowStatePositionXSet[index], handCardShowStatePositionY)));
	handCardSet[index]->runAction(ScaleTo::create(0.2f, 2.0f));
	handCardSet[index]->changeState(SpriteHandCard::HandCardState_AtStateShow);
}

void LayerWorkbench::removeHandCardByIndex(int index)
{
	if (0 > index || index >= handCardSet.size())
		return;

	if (handCardSet[index] == nullptr)
		return;

	handCardSet[index]->removeFromParent();
	handCardSet[index] = nullptr;
}

void LayerWorkbench::test()
{
	handCardSet[0] = (SpriteHandCard::create());
	handCardSet[1] = (SpriteHandCard::create());
	handCardSet[2] = (SpriteHandCard::create());
	handCardSet[3] = (SpriteHandCard::create());
	handCardSet[4] = (SpriteHandCard::create());

	auto it = handCardSet.begin();
	auto itEnd = handCardSet.end();
	int i = 0;
	while (it != itEnd)
	{
		if (*it != nullptr)
		{
			(*it)->initialize();
			(*it)->setPosition(Vec2(handCardPositionXSet[i], handCardPositionY));
			addChild(*it, i);
			(*it)->addEventListener((SpriteHandCard::EventIndex)(i));
		}
		++i;
		++it;
	}
}