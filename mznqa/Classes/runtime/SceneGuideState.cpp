#include "runtime/SceneGuideState.h"

#include "engine/SceneLoadRes.h"
#include "runtime/SceneLoadResState.h"

SceneGuideState* SceneGuideState::instance = nullptr;

SceneGuideState::~SceneGuideState()
{
	delete instance;
}

SceneGuideState* SceneGuideState::Instance()
{
	if (instance == nullptr)
	{
		instance = new SceneGuideState();
	}

	return instance;
}

// 进入状态前的操作
bool SceneGuideState::enter(cocos2d::Layer *scene)
{
	cocos2d::log("++++ SceneGuideState::enter()");
	cocos2d::log("---- SceneGuideState::enter()");
	return true;
}

// 状态执行时的操作
bool SceneGuideState::update(cocos2d::Layer *scene, double intervalTime)
{
	cocos2d::log("++++ SceneGuideState::excute()");
	cocos2d::Director::getInstance()->replaceScene(SceneLoadRes::createScene());
	cocos2d::log("---- SceneGuideState::excute()");
	return true;
}

// 离开状态前的操作
bool SceneGuideState::exit(cocos2d::Layer *Scene)
{
	cocos2d::log("++++ SceneGuideState::exit()");
	cocos2d::log("---- SceneGuideState::exit()");
	return true;
}