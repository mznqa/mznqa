#ifndef MZNQA_CLASSES_ENGINE_SCENEGUIDE_H_
#define MZNQA_CLASSES_ENGINE_SCENEGUIDE_H_

#include "cocos2d.h"

// 该场景用于引导并正确初始化场景配套的状态机，暂时不需要其他内容，勿修改！
class SceneGuide : public cocos2d::Layer
{
private:
	// 用于存放外部场景文件载入的资源
	cocos2d::Node *rootNode;

	void updateOnce(float dt);
protected:

public:
	static cocos2d::Scene* createScene();

	// 重写场景的初始化方法
	virtual bool init();

	// 重写场景的进入方法
	virtual void onEnter();

	// 重写场景的离开方法
	virtual void onExit();

	CREATE_FUNC(SceneGuide);
};

#endif	// MZNQA_CLASSES_ENGINE_SCENEGUIDE_H_