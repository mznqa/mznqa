#pragma execution_character_set("utf-8")

#include "runtime/SceneLoadResState.h"

#include <cstdio>

#include "json/filereadstream.h"
#include "json/document.h"

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