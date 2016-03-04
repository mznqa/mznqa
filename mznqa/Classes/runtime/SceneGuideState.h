#ifndef MZNQA_CLASSES_RUNTIME_SCENEGUIDESTATE_H_
#define MZNQA_CLASSES_RUNTIME_SCENEGUIDESTATE_H_

#include "runtime/BaseSceneState.h"
#include "cocos2d.h"

class SceneGuideState : public BaseSceneState<cocos2d::Layer>
{
private:
	static SceneGuideState *instance;

	SceneGuideState(){}
	SceneGuideState(const SceneGuideState &sceneGuideState){}
	SceneGuideState* operator=(const SceneGuideState &sceneGuideState){}
public:
	~SceneGuideState();

	static SceneGuideState* Instance();

	// 进入状态前的操作
	bool enter(cocos2d::Layer *scene);
	// 状态执行时的操作
	bool update(cocos2d::Layer *scene, double intervalTime);
	// 离开状态前的操作
	bool exit(cocos2d::Layer *Scene);
};

#endif