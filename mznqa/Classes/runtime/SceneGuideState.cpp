/*!
 * \file	Classes\runtime\SceneGuideState.cpp
 *
 * \brief	������ SceneGuideState
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
	cocos2d::log("[information] ׼�����볡�� SceneGuide ��Ӧ״̬��...");
	cocos2d::log("[information] ���볡�� SceneGuide ��Ӧ״̬���ɹ�");
	return true;
}

bool SceneGuideState::update(SceneGuide *scene, double intervalTime)
{
	cocos2d::log("[information] ��ʼִ�г��� SceneGuide ��Ӧ��״̬��...");
	// ���ó���API����ת��ָ������
	scene->replaceSceneLoadRes();
	cocos2d::log("[information] ���� SceneGuide ��Ӧ��״̬��ִ�����");
	return true;
}

bool SceneGuideState::exit(SceneGuide *Scene)
{
	cocos2d::log("[information] ׼���뿪���� SceneGuide ��Ӧ״̬��...");
	cocos2d::log("[information] �뿪���� SceneGuide ��Ӧ״̬���ɹ�");
	return true;
}