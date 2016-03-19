#pragma execution_character_set("utf-8")

#include "runtime/SceneLoadResState.h"
#include "fileio/JsonParser.h"
#include "combatSystem/EffectPQ.h"

SceneLoadResState::~SceneLoadResState()
{
}

SceneLoadResState* SceneLoadResState::Instance()
{
	static SceneLoadResState instance;
	return &instance;
}

// ����״̬ǰ�Ĳ���
bool SceneLoadResState::enter(SceneLoadRes *scene)
{
	cocos2d::log("++++ SceneLoadResState.enter()");
	EffectPQ epq;
	epq.test();
	cocos2d::log("---- SceneLoadResState.enter()");
	return true;
}

// ״ִ̬��ʱ�Ĳ���
bool SceneLoadResState::update(SceneLoadRes *scene, double intervalTime)
{
	cocos2d::log("++++ SceneLoadResState.excute()");
	cocos2d::log("---- SceneLoadResState.excute()");
	return true;
}

// �뿪״̬ǰ�Ĳ���
bool SceneLoadResState::exit(SceneLoadRes *Scene)
{
	cocos2d::log("++++ SceneLoadResState.exit()");
	cocos2d::log("---- SceneLoadResState.exit()");
	return true;
}