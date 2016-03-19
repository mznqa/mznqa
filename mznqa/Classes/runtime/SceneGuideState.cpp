#pragma execution_character_set("utf-8")

#include "runtime/SceneGuideState.h"

#include "engine/SceneLoadRes.h"
#include "runtime/SceneLoadResState.h"

SceneGuideState::~SceneGuideState()
{
}

SceneGuideState* SceneGuideState::Instance()
{
	static SceneGuideState instance;
	return &instance;
}

// 进入状态前的操作
bool SceneGuideState::enter(SceneGuide *scene)
{
	cocos2d::log("++++ SceneGuideState::enter()");
	cocos2d::log("---- SceneGuideState::enter()");
	return true;
}

// 状态执行时的操作
bool SceneGuideState::update(SceneGuide *scene, double intervalTime)
{
	cocos2d::log("++++ SceneGuideState::update()");
	// 调用场景API，跳转到指定场景
	scene->replaceSceneLoadRes();
	cocos2d::log("---- SceneGuideState::update()");
	return true;
}

// 离开状态前的操作
bool SceneGuideState::exit(SceneGuide *Scene)
{
	cocos2d::log("++++ SceneGuideState::exit()");
	cocos2d::log("---- SceneGuideState::exit()");
	return true;
}