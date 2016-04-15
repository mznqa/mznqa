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

// ����״̬ǰ�Ĳ���
bool SceneGameMainState::enter(SceneGameMain *scene)
{
	cocos2d::log("[information] ׼�����볡�� SceneGameMain ��Ӧ״̬��...");
	cocos2d::log("[information] ���볡�� SceneGameMain ��Ӧ״̬���ɹ�");
	return true;
}

// ״ִ̬��ʱ�Ĳ���
bool SceneGameMainState::update(SceneGameMain *scene, double intervalTime)
{
	cocos2d::log("[information] ��ʼִ�г��� SceneGameMain ��Ӧ��״̬��...");
	cocos2d::log("[information] ���� SceneGameMain ��Ӧ��״̬��ִ�����");
	return true;
}

// �뿪״̬ǰ�Ĳ���
bool SceneGameMainState::exit(SceneGameMain *Scene)
{
	cocos2d::log("[information] ׼���뿪���� SceneGameMain ��Ӧ״̬��...");
	cocos2d::log("[information] �뿪���� SceneGameMain ��Ӧ״̬���ɹ�");
	return true;
}