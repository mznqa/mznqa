#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_RUNTIME_BASESCENESTATE_H_
#define MZNQA_CLASSES_RUNTIME_BASESCENESTATE_H_

// 场景状态机的基类
// 所有派生类均应重写：enter()、update()和exit()三个方法
// 每个场景都对应一个场景状态机用于操纵场景
template <typename SceneType>
class BaseSceneState
{
public:
	BaseSceneState(){}
	virtual ~BaseSceneState(){}
	// 进入状态前的操作
	virtual bool enter(SceneType *scene) = 0;
	// 状态执行时的操作，需提供距离上次改操作的时间间隔（毫秒）
	virtual bool update(SceneType *scene, double intervalTime) = 0;
	// 离开状态前的操作
	virtual bool exit(SceneType *Scene) = 0;
};

#endif