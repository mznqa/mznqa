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

// ����״̬ǰ�Ĳ���
bool SceneGuideState::enter(SceneGuide *scene)
{
	cocos2d::log("[information] ׼�����볡�� SceneGuide ��Ӧ״̬��...");
	cocos2d::log("[information] ���볡�� SceneGuide ��Ӧ״̬���ɹ�");
	return true;
}

// ״ִ̬��ʱ�Ĳ���
bool SceneGuideState::update(SceneGuide *scene, double intervalTime)
{
	cocos2d::log("[information] ��ʼִ�г��� SceneGuide ��Ӧ��״̬��...");
	// ���ó���API����ת��ָ������
	scene->replaceSceneLoadRes();
	cocos2d::log("[information] ���� SceneGuide ��Ӧ��״̬��ִ�����");
	return true;
}

// �뿪״̬ǰ�Ĳ���
bool SceneGuideState::exit(SceneGuide *Scene)
{
	cocos2d::log("[information] ׼���뿪���� SceneGuide ��Ӧ״̬��...");
	cocos2d::log("[information] �뿪���� SceneGuide ��Ӧ״̬���ɹ�");
	return true;
}