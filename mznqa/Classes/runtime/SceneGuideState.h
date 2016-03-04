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

	// ����״̬ǰ�Ĳ���
	bool enter(cocos2d::Layer *scene);
	// ״ִ̬��ʱ�Ĳ���
	bool update(cocos2d::Layer *scene, double intervalTime);
	// �뿪״̬ǰ�Ĳ���
	bool exit(cocos2d::Layer *Scene);
};

#endif