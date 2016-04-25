/*!
 * \file	Classes\runtime\SceneGuideState.cpp
 *
 * \brief	定义类 SceneGuideState
 */

#pragma execution_character_set("utf-8")

#include "runtime/SceneGuideState.h"

SceneGuideState::~SceneGuideState()
{
}

SceneGuideState* SceneGuideState::Instance()
{
	static SceneGuideState instance;
	return &instance;
}

bool SceneGuideState::enter(SceneGuide *scene)
{
	cocos2d::log("[information] 准备进入场景 SceneGuide 对应状态机...");
	cocos2d::log("[information] 进入场景 SceneGuide 对应状态机成功");
	return true;
}

bool SceneGuideState::update(SceneGuide *scene, double intervalTime)
{
	cocos2d::log("[information] 开始执行场景 SceneGuide 对应的状态机...");
	// 调用场景API，跳转到指定场景
	scene->replaceSceneLoadRes();
	cocos2d::log("[information] 场景 SceneGuide 对应的状态机执行完成");
	return true;
}

bool SceneGuideState::exit(SceneGuide *Scene)
{
	cocos2d::log("[information] 准备离开场景 SceneGuide 对应状态机...");
	cocos2d::log("[information] 离开场景 SceneGuide 对应状态机成功");
	return true;
}