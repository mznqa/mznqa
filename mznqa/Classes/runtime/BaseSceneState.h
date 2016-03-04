#ifndef MZNQA_CLASSES_RUNTIME_BASESCENESTATE_H_
#define MZNQA_CLASSES_RUNTIME_BASESCENESTATE_H_

// 场景状态的基类
// 所有派生类均应重写：enter()、update()和exit()三个方法
template <typename SceneType>
class BaseSceneState
{
public:
	BaseSceneState(){}
	virtual ~BaseSceneState(){}
	// 进入状态前的操作
	virtual bool enter(SceneType *scene) = 0;
	// 状态执行时的操作
	virtual bool update(SceneType *scene, double intervalTime) = 0;
	// 离开状态前的操作
	virtual bool exit(SceneType *Scene) = 0;
};

#endif