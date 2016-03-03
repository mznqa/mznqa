#ifndef MZNQA_CLASSES_ENGINE_SCENEDEBUG_H_
#define MZNQA_CLASSES_ENGINE_SCENEDEBUG_H_

#include "cocos2d.h"

// Debug 场景。该场景用于游戏最初载入，即第一个载入的场景
// 该场景仅作下一个场景的引导作用，暂时不实现任何内容
// 请保持该场景干净，不再添加任何东西！
class SceneDebug : public cocos2d::Layer
{
private:
	cocos2d::Node *rootNode;
protected:

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(SceneDebug);
};

#endif	// MZNQA_CLASSES_ENGINE_SCENEDEBUG_H_