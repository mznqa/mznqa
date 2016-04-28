#pragma execution_character_set("utf-8")

#include "engine/LayerWorkbench.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "filePath/FilePathLayer.h"

USING_NS_CC;
using namespace cocostudio::timeline;

const std::array<float, 5> LayerWorkbench::handCardPositionXSet = { 684.0f, 874.0f, 1064.0f, 1254.0f, 1444.0f };
const float LayerWorkbench::handCardPositionY = 50.0f;

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
	return true;
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

void LayerWorkbench::showHandCardByIndex(int index)
{
	if (0 > index || index >= handCardSet.size())
		return;

	auto it = handCardSet.begin();
	for (int i = 1; i <= index; ++i)
		++it;

	(*it)->setPosition(Vec2(100, 100));
}

void LayerWorkbench::test()
{
	handCardSet.push_back(SpriteCard::create());
	handCardSet.push_back(SpriteCard::create());
	handCardSet.push_back(SpriteCard::create());
	handCardSet.push_back(SpriteCard::create());
	handCardSet.push_back(SpriteCard::create());

	auto it = handCardSet.begin();
	auto itEnd = handCardSet.end();
	int i = 0;
	while (it != itEnd)
	{
		(*it)->initialize();
		(*it)->setPosition(Vec2(handCardPositionXSet[i], handCardPositionY));
		addChild(*it);
		(*it)->addEventListener((SpriteCard::EventIndex)(i));
		++i;
		++it;
	}
}