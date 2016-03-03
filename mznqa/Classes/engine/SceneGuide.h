#ifndef MZNQA_CLASSES_ENGINE_SCENEGUIDE_H_
#define MZNQA_CLASSES_ENGINE_SCENEGUIDE_H_

#include "cocos2d.h"

// 该场景用于引导并正确初始化场景配套的状态机，暂时不需要其他内容，勿修改！
class SceneGuide : public cocos2d::Layer
{
private:
	cocos2d::Node *rootNode;
protected:

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(SceneGuide);
};

#endif	// MZNQA_CLASSES_ENGINE_SCENEGUIDE_H_