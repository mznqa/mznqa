#pragma execution_character_set("utf-8")

#include "runtime/SceneLoadResState.h"

#include <cstdio>

#include "json/filereadstream.h"
#include "json/document.h"

// 测试用 //////////////////////////////////////////////////////////////////////////
#include "engine/FileController.h"
#include "dataHandle/CharBufferArea.h"
#include "card/CardRoad.h"
#include "card/CardSkill.h"
#include <string>
#include "effect/Effect.h"
#include "effect/EffectFunSet.h"
#include "dataHandle/ParserCardSkill.h"
#include "dataHandle/ParserMapArchives.h"
#include "staticData/CardSet.h"
#include "cardController/CardBox.h"
#include "cardController/CardBoxRTM.h"
#include "cardController/CardControllerExplore.h"
//////////////////////////////////////////////////////////////////////////

SceneLoadResState::~SceneLoadResState()
{
}

SceneLoadResState* SceneLoadResState::Instance()
{
	static SceneLoadResState instance;
	return &instance;
}

// 进入状态前的操作
bool SceneLoadResState::enter(SceneLoadRes *scene)
{
	cocos2d::log("[information] 准备进入场景 SceneLoadRes 对应的状态机中...");
	// 测试用 //////////////////////////////////////////////////////////////////////////
	std::map<int, CardRoad> rcs;
	rcs.insert(std::pair<int, CardRoad>(0, CardRoad(0, CardRoad::RoadType_URDL)));
	rcs.insert(std::pair<int, CardRoad>(1, CardRoad(1, CardRoad::RoadType_URDL)));
	rcs.insert(std::pair<int, CardRoad>(2, CardRoad(2, CardRoad::RoadType_URDL)));
	rcs.insert(std::pair<int, CardRoad>(3, CardRoad(3, CardRoad::RoadType_URDL)));
	rcs.insert(std::pair<int, CardRoad>(4, CardRoad(4, CardRoad::RoadType_URDL)));
	std::map<int, CardTreasure> tcs;
	tcs.insert(std::pair<int, CardTreasure>(10000, CardTreasure(10000)));
	tcs.insert(std::pair<int, CardTreasure>(10001, CardTreasure(10001)));
	tcs.insert(std::pair<int, CardTreasure>(10002, CardTreasure(10002)));
	tcs.insert(std::pair<int, CardTreasure>(10003, CardTreasure(10003)));
	tcs.insert(std::pair<int, CardTreasure>(10004, CardTreasure(10004)));
	std::map<int, CardMonster> mcs;
	mcs.insert(std::pair<int, CardMonster>(20000, CardMonster(20000)));
	mcs.insert(std::pair<int, CardMonster>(20001, CardMonster(20001)));
	mcs.insert(std::pair<int, CardMonster>(20002, CardMonster(20002)));
	mcs.insert(std::pair<int, CardMonster>(20003, CardMonster(20003)));
	mcs.insert(std::pair<int, CardMonster>(20004, CardMonster(20004)));
	CardSet::Instance()->loadCardRoadSet(rcs);
	CardSet::Instance()->loadCardTreasureSet(tcs);
	CardSet::Instance()->loadCardMonsterSet(mcs);

	CardControllerExplore::Instance()->addCardToCardPool(0);
	CardControllerExplore::Instance()->addCardToCardPool(1);
	CardControllerExplore::Instance()->addCardToCardPool(2);
	CardControllerExplore::Instance()->addCardToCardPool(3);
	CardControllerExplore::Instance()->addCardToCardPool(4);
	CardControllerExplore::Instance()->addCardToCardPool(10000);
	CardControllerExplore::Instance()->addCardToCardPool(10001);
	CardControllerExplore::Instance()->addCardToCardPool(10002);
	CardControllerExplore::Instance()->addCardToCardPool(10003);
	CardControllerExplore::Instance()->addCardToCardPool(10004);
	CardControllerExplore::Instance()->addCardToCardPool(20000);
	CardControllerExplore::Instance()->addCardToCardPool(20001);
	CardControllerExplore::Instance()->addCardToCardPool(20002);
	CardControllerExplore::Instance()->addCardToCardPool(20003);
	CardControllerExplore::Instance()->addCardToCardPool(20004);

	CardControllerExplore::Instance()->drawACard();
	CardControllerExplore::Instance()->drawACard();
	CardControllerExplore::Instance()->drawACard();
	CardControllerExplore::Instance()->drawACard();
	CardControllerExplore::Instance()->drawACard();

	CardControllerExplore::Instance()->playCardByIndex(0);
	CardControllerExplore::Instance()->playCardByIndex(0);
	CardControllerExplore::Instance()->playCardByIndex(0);
	CardControllerExplore::Instance()->playCardByIndex(0);
	CardControllerExplore::Instance()->playCardByIndex(0);

	//////////////////////////////////////////////////////////////////////////
	cocos2d::log("[information] 准备进入场景 SceneLoadRes 对应的状态机成功");
	return true;
}

// 状态执行时的操作
bool SceneLoadResState::update(SceneLoadRes *scene, double intervalTime)
{
	cocos2d::log("[information] 开始执行场景 SceneLoadRes 对应的状态机...");
	cocos2d::log("[information] 执行场景 SceneLoadRes 对应的状态机成功");
	return true;
}

// 离开状态前的操作
bool SceneLoadResState::exit(SceneLoadRes *Scene)
{
	cocos2d::log("[information] 准备离开场景 SceneLoadRes 对应的状态机...");
	cocos2d::log("[information] 离开场景 SceneLoadRes 对应的状态机成功");
	return true;
}