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
	CardSkill cs0(3001, std::string("name"), std::string("describe"), CardBase::BelongTo_RoleMonsterBoth, 10);
	cocos2d::log("%d", cs0.getID());
	cocos2d::log("%d", cs0.getType());
	cocos2d::log("%s", cs0.getName().c_str());
	cocos2d::log("%s", cs0.getDescride().c_str());
	cocos2d::log("%d", cs0.getBelongTo());
	cocos2d::log("%d", cs0.getEffectCount());
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