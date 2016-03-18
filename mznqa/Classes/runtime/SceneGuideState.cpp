#pragma execution_character_set("utf-8")

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
bool SceneGuideState::enter(SceneGuide *scene)
{
	cocos2d::log("++++ SceneGuideState::enter()");
	cocos2d::log("---- SceneGuideState::enter()");
	return true;
}

// ״ִ̬��ʱ�Ĳ���
bool SceneGuideState::update(SceneGuide *scene, double intervalTime)
{
	cocos2d::log("++++ SceneGuideState::update()");
	// ���ó���API����ת��ָ������
	scene->replaceSceneLoadRes();
	cocos2d::log("---- SceneGuideState::update()");
	return true;
}

// �뿪״̬ǰ�Ĳ���
bool SceneGuideState::exit(SceneGuide *Scene)
{
	cocos2d::log("++++ SceneGuideState::exit()");
	cocos2d::log("---- SceneGuideState::exit()");
	return true;
}