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
#include "dataHandle/ParserCardSkill.h"
#include "dataHandle/ParserMapArchives.h"
#include "staticData/CardSet.h"
#include "cardController/CardBox.h"
#include "cardController/CardBoxRTM.h"
#include "cardController/CardControllerExplore.h"
#include "cardController/CardControllerCombat.h"
#include "filePath/DataFilePath.h"
#include "dataHandle/StaticDataLoader.h"
#include "map/MapController.h"
#include "map/MapView.h"
#include "dataHandle/ParserMapMissionMain.h"
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
	// ������ ��Ҫ�ڴ�д�κζ��� ������ //////////////////////////////////////////////////////////////////////////
	// ������ Ҫд���ԵĻ���д�������Ǹ������� ������ //////////////////////////////////////////////////////////////////////////
	cocos2d::log("[information] ׼�����볡�� SceneLoadRes ��Ӧ��״̬���ɹ�");
	return true;
}

// ״ִ̬��ʱ�Ĳ���
bool SceneLoadResState::update(SceneLoadRes *scene, double intervalTime)
{
	cocos2d::log("[information] ��ʼִ�г��� SceneLoadRes ��Ӧ��״̬��...");

	// ����������������Դ���� //////////////////////////////////////////////////////////////////////////
	cocos2d::log("[information] ��ʼ׼��������Դ...");
	// ���룺��̬���ݣ����ο�������
	StaticDataLoader::loadStaticDataCardRoadSet();
	// ���룺��̬���ݣ����ܿ�����
	StaticDataLoader::loadStaticDataCardSkillSet();
	// ���룺��̬���ݣ����������ͼ����
	StaticDataLoader::loadStaticDataMainMissionMapSet();

	//////////////////////////////////////////////////////////////////////////

	// ���������� //////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////

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