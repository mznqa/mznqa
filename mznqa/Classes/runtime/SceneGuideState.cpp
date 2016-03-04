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

// ����״̬ǰ�Ĳ���
bool SceneGuideState::enter(cocos2d::Layer *scene)
{
	cocos2d::log("++++ SceneGuideState::enter()");
	cocos2d::log("---- SceneGuideState::enter()");
	return true;
}

// ״ִ̬��ʱ�Ĳ���
bool SceneGuideState::update(cocos2d::Layer *scene, double intervalTime)
{
	cocos2d::log("++++ SceneGuideState::excute()");
	cocos2d::Director::getInstance()->replaceScene(SceneLoadRes::createScene());
	cocos2d::log("---- SceneGuideState::excute()");
	return true;
}

// �뿪״̬ǰ�Ĳ���
bool SceneGuideState::exit(cocos2d::Layer *Scene)
{
	cocos2d::log("++++ SceneGuideState::exit()");
	cocos2d::log("---- SceneGuideState::exit()");
	return true;
}