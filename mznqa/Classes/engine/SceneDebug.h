#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_SCENEDEBUG_H_
#define MZNQA_CLASSES_ENGINE_SCENEDEBUG_H_

#include "cocos2d.h"

// Debug 场景。该场景用于游戏最初载入，即第一个载入的场景
// 该场景仅作下一个场景的引导作用，暂时不实现任何内容
// 请保持该场景干净，不再添加任何东西！
class SceneDebug : public cocos2d::Layer
{
private:
	// 场景私有量 //////////////////////////////////////////////////////////////////////////

	// 从外部文件载入的场景文件所存放的位置
	cocos2d::Node *rootNode;
	//////////////////////////////////////////////////////////////////////////
public:
	CREATE_FUNC(SceneDebug);
	static cocos2d::Scene* createScene();

	// 固有的场景生命周期方法 //////////////////////////////////////////////////////////////////////////

	// 重写场景的初始化操作
	virtual bool init() override;

	// 重写场景启动时的操作
	virtual void onEnter() override;

	// 重写场景离开时的操作
	virtual void onExit() override;
	//////////////////////////////////////////////////////////////////////////
};

#endif	// MZNQA_CLASSES_ENGINE_SCENEDEBUG_H_