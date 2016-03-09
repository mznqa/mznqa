#ifndef MZNQA_CLASSES_RUNTIME_SCENELOADRESSTATE_H_
#define MZNQA_CLASSES_RUNTIME_SCENELOADRESSTATE_H_

#include "runtime/BaseSceneState.h"
#include "cocos2d.h"
#include "engine/SceneLoadRes.h"

class SceneLoadResState : public BaseSceneState<SceneLoadRes>
{
private:
	static SceneLoadResState *instance;

	SceneLoadResState(){}
	SceneLoadResState(const SceneLoadResState &SceneLoadResState){}
	SceneLoadResState* operator=(const SceneLoadResState &SceneLoadResState){}
public:
	~SceneLoadResState();

	static SceneLoadResState* Instance();

	// 进入状态前的操作
	bool  enter(SceneLoadRes *scene);
	// 状态执行时的操作
	bool update(SceneLoadRes *scene, double intervalTime);
	// 离开状态前的操作
	bool exit(SceneLoadRes *Scene);
};

#endif