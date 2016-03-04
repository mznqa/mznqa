#ifndef MZNQA_CLASSES_RUNTIME_SCENELOADRESSTATE_H_
#define MZNQA_CLASSES_RUNTIME_SCENELOADRESSTATE_H_

#include "runtime/BaseSceneState.h"
#include "cocos2d.h"

class SceneLoadResState : public BaseSceneState<cocos2d::Layer>
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
	bool  enter(cocos2d::Layer *scene);
	// 状态执行时的操作
	bool update(cocos2d::Layer *scene, double intervalTime);
	// 离开状态前的操作
	bool exit(cocos2d::Layer *Scene);
};

#endif