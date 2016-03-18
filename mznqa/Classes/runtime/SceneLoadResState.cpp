#pragma execution_character_set("utf-8")

#include "runtime/SceneLoadResState.h"
#include "data/realTimeData/Role.h"

SceneLoadResState*SceneLoadResState::instance = nullptr;

SceneLoadResState::~SceneLoadResState()
{
	delete instance;
}

SceneLoadResState* SceneLoadResState::Instance()
{
	if (instance == nullptr)
	{
		instance = new SceneLoadResState();
	}

	return instance;
}

// 进入状态前的操作
bool SceneLoadResState::enter(SceneLoadRes *scene)
{
	cocos2d::log("++++ SceneLoadResState.enter()");
	Role::Instance()->test();
	cocos2d::log("---- SceneLoadResState.enter()");
	return true;
}

// 状态执行时的操作
bool SceneLoadResState::update(SceneLoadRes *scene, double intervalTime)
{
	cocos2d::log("++++ SceneLoadResState.excute()");
	cocos2d::log("---- SceneLoadResState.excute()");
	return true;
}

// 离开状态前的操作
bool SceneLoadResState::exit(SceneLoadRes *Scene)
{
	cocos2d::log("++++ SceneLoadResState.exit()");
	cocos2d::log("---- SceneLoadResState.exit()");
	return true;
}