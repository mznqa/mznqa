#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_RUNTIME_SCENEGAMEMAINSTATE_H_
#define MZNQA_CLASSES_RUNTIME_SCENEGAMEMAINSTATE_H_

#include "cocos2d.h"

#include "runtime/BaseSceneState.h"
#include "engine/SceneGameMain.h"
#include "message/EngineMessagePQ.h"
#include "message/LogicMessagePQ.h"
#include "message/MsgInterpreter.h"
#include "map/MapView.h"

class SceneGameMainState : public BaseSceneState<SceneGameMain>
{
private:
	SceneGameMainState(){}
	SceneGameMainState(const SceneGameMainState &sceneGameMainState){}
	SceneGameMainState& operator=(const SceneGameMainState &sceneGameMainState){}

	EngineMessagePQ *engineMessagePQInstance;
	LogicMessagePQ *logicMessagePQInstance;
	MsgInterpreter *msgInterpreterInstance;
	MapView *mapViewInstance;

public:
	~SceneGameMainState();

	static SceneGameMainState* Instance();

	// ����״̬ǰ�Ĳ���
	bool  enter(SceneGameMain *scene);
	// ״ִ̬��ʱ�Ĳ���
	bool update(SceneGameMain *scene, double intervalTime);
	// �뿪״̬ǰ�Ĳ���
	bool exit(SceneGameMain *Scene);
};

#endif