#ifndef MZNQA_CLASSES_ENGINE_SCENELOADRES_H_
#define MZNQA_CLASSES_ENGINE_SCENELOADRES_H_

#include "cocos2d.h"

// 该场景在载入资源过程中显示
class SceneLoadRes : public cocos2d::Layer
{
private:
	// 场景私有量 //////////////////////////////////////////////////////////////////////////

	// 用于存放从外部载入的场景文件的资源
	cocos2d::Node *rootNode;
	//////////////////////////////////////////////////////////////////////////
protected:

public:
	CREATE_FUNC(SceneLoadRes);
	static cocos2d::Scene* createScene();

	// 固有的场景生命周期方法 //////////////////////////////////////////////////////////////////////////
	// 重写场景初始化方法
	virtual bool init();

	// 重写场景进入时的方法
	virtual void onEnter();

	// 重写场景离开时的方法
	virtual void onExit();
	//////////////////////////////////////////////////////////////////////////
};

#endif	// MZNQA_CLASSES_ENGINE_SCENELOADRES_H_