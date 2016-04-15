#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_RUNTIME_SCENELOADRESSTATE_H_
#define MZNQA_CLASSES_RUNTIME_SCENELOADRESSTATE_H_

#include "cocos2d.h"

#include "runtime/BaseSceneState.h"
#include "engine/SceneLoadRes.h"

class SceneLoadResState : public BaseSceneState<SceneLoadRes>
{
private:
	SceneLoadResState(){}
	SceneLoadResState(const SceneLoadResState &sceneLoadResState){}
	SceneLoadResState& operator=(const SceneLoadResState &sceneLoadResState){}
public:
	~SceneLoadResState();

	static SceneLoadResState* Instance();

	// ����״̬ǰ�Ĳ���
	bool  enter(SceneLoadRes *scene);
	// ״ִ̬��ʱ�Ĳ���
	bool update(SceneLoadRes *scene, double intervalTime);
	// �뿪״̬ǰ�Ĳ���
	bool exit(SceneLoadRes *Scene);
};

#endif