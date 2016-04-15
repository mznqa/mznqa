#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_RUNTIME_SCENEGAMEMAINSTATE_H_
#define MZNQA_CLASSES_RUNTIME_SCENEGAMEMAINSTATE_H_

#include "cocos2d.h"

#include "runtime/BaseSceneState.h"
#include "engine/SceneGameMain.h"

class SceneGameMainState : public BaseSceneState<SceneGameMain>
{
private:
	SceneGameMainState(){}
	SceneGameMainState(const SceneGameMainState &sceneGameMainState){}
	SceneGameMainState& operator=(const SceneGameMainState &sceneGameMainState){}
public:
	~SceneGameMainState();

	static SceneGameMainState* Instance();

	// 进入状态前的操作
	bool  enter(SceneGameMain *scene);
	// 状态执行时的操作
	bool update(SceneGameMain *scene, double intervalTime);
	// 离开状态前的操作
	bool exit(SceneGameMain *Scene);
};

#endif