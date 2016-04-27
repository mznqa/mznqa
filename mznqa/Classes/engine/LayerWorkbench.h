#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_LAYERWORKBENCH_H_
#define MZNQA_CLASSES_ENGINE_LAYERWORKBENCH_H_

#include <list>
#include <array>

#include "cocos2d.h"

#include "cardController/CardControllerExplore.h"
#include "engine/SpriteCard.h"

class LayerWorkbench : public cocos2d::Layer
{
private:
	cocos2d::Node *rootNode;

	std::list<SpriteCard*> handCardSet;
	static const std::array<float, 5> handCardPositionXSet;
	static const float handCardPositionY;

	// 单例别名 //////////////////////////////////////////////////////////////////////////
	/*! \brief	保存 CardControllerExplore::Instance() 的常量指针 */
	CardControllerExplore *const cardControllerExploreInstance = CardControllerExplore::Instance();
	//////////////////////////////////////////////////////////////////////////
public:
	LayerWorkbench(){}
	~LayerWorkbench(){}

	CREATE_FUNC(LayerWorkbench);

	virtual bool init() override;

	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;

	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;

	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;

	void addGlobalEventListener();

	void test();
};

#endif
