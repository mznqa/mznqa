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
#include "dataHandle/ParserMapMissionMain.h"
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
	// 载入：静态数据：主线任务地图集合
	StaticDataLoader::loadStaticDataMainMissionMapSet();

	//////////////////////////////////////////////////////////////////////////

	// 测试用区域 //////////////////////////////////////////////////////////////////////////
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