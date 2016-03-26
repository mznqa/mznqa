#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_RUNTIME_SCENEGUIDESTATE_H_
#define MZNQA_CLASSES_RUNTIME_SCENEGUIDESTATE_H_

#include "cocos2d.h"

#include "runtime/BaseSceneState.h"
#include "engine/SceneGuide.h"

class SceneGuideState : public BaseSceneState<SceneGuide>
{
private:
	SceneGuideState(){}
	SceneGuideState(const SceneGuideState &sceneGuideState){}
	SceneGuideState* operator=(const SceneGuideState &sceneGuideState){}
public:
	~SceneGuideState();

	static SceneGuideState* Instance();

	// 进入状态前的操作
	bool enter(SceneGuide *scene);
	// 状态执行时的操作
	bool update(SceneGuide *scene, double intervalTime);
	// 离开状态前的操作
	bool exit(SceneGuide *Scene);
};

#endif