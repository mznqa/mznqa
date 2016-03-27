#pragma execution_character_set("utf-8")

#include "runtime/SceneLoadResState.h"

#include <cstdio>

#include "json/filereadstream.h"
#include "json/document.h"

// ������ //////////////////////////////////////////////////////////////////////////
#include "engine/FileController.h"
#include "dataHandle/CharBufferArea.h"
#include "card/CardRoad.h"
#include "card/CardSkill.h"
#include <string>
#include "effect/Effect.h"
#include "effect/EffectFunSet.h"
//////////////////////////////////////////////////////////////////////////

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
	cocos2d::log("[information] ׼�����볡�� SceneLoadRes ��Ӧ��״̬����...");
	// ������ //////////////////////////////////////////////////////////////////////////
	Effect ef(0, "ȥ1Ѫ", Effect::Receiver_Other, 0, std::vector<int>());
	cocos2d::log("%d", ef.getID());
	cocos2d::log("%s", ef.getDescribe().c_str());
	cocos2d::log("%d", ef.getReceiver());
	cocos2d::log("%d", ef.getFunIndex());
	cocos2d::log("%d", ef.getArgsCount());
	(EffectFunSet::getFunByIndex(0))(std::vector<int>());

	//CharBufferArea::Instance()->test();
	//////////////////////////////////////////////////////////////////////////
	cocos2d::log("[information] ׼�����볡�� SceneLoadRes ��Ӧ��״̬���ɹ�");
	return true;
}

// ״ִ̬��ʱ�Ĳ���
bool SceneLoadResState::update(SceneLoadRes *scene, double intervalTime)
{
	cocos2d::log("[information] ��ʼִ�г��� SceneLoadRes ��Ӧ��״̬��...");
	cocos2d::log("[information] ִ�г��� SceneLoadRes ��Ӧ��״̬���ɹ�");
	return true;
}

// �뿪״̬ǰ�Ĳ���
bool SceneLoadResState::exit(SceneLoadRes *Scene)
{
	cocos2d::log("[information] ׼���뿪���� SceneLoadRes ��Ӧ��״̬��...");
	cocos2d::log("[information] �뿪���� SceneLoadRes ��Ӧ��״̬���ɹ�");
	return true;
}