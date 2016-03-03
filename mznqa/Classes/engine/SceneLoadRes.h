#ifndef MZNQA_CLASSES_ENGINE_SCENELOADRES_H_
#define MZNQA_CLASSES_ENGINE_SCENELOADRES_H_

#include "cocos2d.h"

// 该场景在载入资源过程中显示
class SceneLoadRes : public cocos2d::Layer
{
private:
	cocos2d::Node *rootNode;
protected:

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(SceneLoadRes);
};

#endif	// MZNQA_CLASSES_ENGINE_SCENELOADRES_H_