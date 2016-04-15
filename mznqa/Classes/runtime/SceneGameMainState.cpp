#pragma execution_character_set("utf-8")

#include "runtime/SceneGameMainState.h"

SceneGameMainState::~SceneGameMainState()
{
}

SceneGameMainState* SceneGameMainState::Instance()
{
	static SceneGameMainState instance;
	return &instance;
}

// 进入状态前的操作
bool SceneGameMainState::enter(SceneGameMain *scene)
{
	cocos2d::log("[information] 准备进入场景 SceneGameMain 对应状态机...");
	cocos2d::log("[information] 进入场景 SceneGameMain 对应状态机成功");
	return true;
}

// 状态执行时的操作
bool SceneGameMainState::update(SceneGameMain *scene, double intervalTime)
{
	cocos2d::log("[information] 开始执行场景 SceneGameMain 对应的状态机...");
	cocos2d::log("[information] 场景 SceneGameMain 对应的状态机执行完成");
	return true;
}

// 离开状态前的操作
bool SceneGameMainState::exit(SceneGameMain *Scene)
{
	cocos2d::log("[information] 准备离开场景 SceneGameMain 对应状态机...");
	cocos2d::log("[information] 离开场景 SceneGameMain 对应状态机成功");
	return true;
}