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

	// ���룺�浵��ȫ�ֵ�ͼ
	StaticDataLoader::loadArchivesDataGlobalMap();
	cocos2d::log("[information] �����Դ����");
	//////////////////////////////////////////////////////////////////////////

	// ���������� //////////////////////////////////////////////////////////////////////////
	// xxxx->text();
	int x0 = MapController::Instance()->mapView->getViewRangeXBegin();
	int x1 = MapController::Instance()->mapView->getViewRangeXEnd();
	int y0 = MapController::Instance()->mapView->getViewRangeYBegin();
	int y1 = MapController::Instance()->mapView->getViewRangeYEnd();
	for (int y = y0; y <= y1; ++y)
	{
		cocos2d::log("%5d, %5d, %5d, %5d, %5d, %5d, %5d, %5d, %5d, %5d, %5d, %5d, %5d, %5d, %5d",
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(0, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(1, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(2, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(3, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(4, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(5, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(6, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(7, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(8, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(9, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(10, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(11, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(12, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(13, y)).index,
			MapController::Instance()->getMapNodeSet().at(MapNode::getIndexByXY(14, y)).index
			);
	}
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