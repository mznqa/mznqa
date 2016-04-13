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
#include "cardController/CardControllerCombat.h"
#include "filePath/DataFilePath.h"
#include "dataHandle/StaticDataLoader.h"
#include "map/MapController.h"
#include "map/MapView.h"
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
	// ！！！ 不要在此写任何东西 ！！！ //////////////////////////////////////////////////////////////////////////
	// ！！！ 要写测试的话，写在下面那个函数内 ！！！ //////////////////////////////////////////////////////////////////////////
	cocos2d::log("[information] 准备进入场景 SceneLoadRes 对应的状态机成功");
	return true;
}

// 状态执行时的操作
bool SceneLoadResState::update(SceneLoadRes *scene, double intervalTime)
{
	cocos2d::log("[information] 开始执行场景 SceneLoadRes 对应的状态机...");

	// 此区域用于载入资源，勿动 //////////////////////////////////////////////////////////////////////////
	cocos2d::log("[information] 开始准备载入资源...");
	// 载入：静态数据：地形卡卡集合
	StaticDataLoader::loadStaticDataCardRoadSet();
	// 载入：静态数据：技能卡集合
	StaticDataLoader::loadStaticDataCardSkillSet();

	// 载入：存档：全局地图
	StaticDataLoader::loadArchivesDataGlobalMap();
	cocos2d::log("[information] 完成资源载入");
	//////////////////////////////////////////////////////////////////////////

	// 测试用区域 //////////////////////////////////////////////////////////////////////////
	// xxxx->text();
	int x0 = MapController::Instance()->mapView->getViewRangeXBegin();
	int x1 = MapController::Instance()->mapView->getViewRangeXEnd();
	int y0 = MapController::Instance()->mapView->getViewRangeYBegin();
	int y1 = MapController::Instance()->mapView->getViewRangeYEnd();
	for (int y = y0; y <= y1; ++y)
	{
		cocos2d::log("%5d, %5d, %5d, %5d, %5d, %5d, %5d, %5d, %5d, %5d, %5d, %5d, %5d, %5d, %5d",
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(0, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(1, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(2, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(3, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(4, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(5, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(6, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(7, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(8, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(9, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(10, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(11, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(12, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(13, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(14, y)).index
			);
	}
	//////////////////////////////////////////////////////////////////////////

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