#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_LAYERMAP_H_
#define MZNQA_CLASSES_ENGINE_LAYERMAP_H_

#include <vector>

#include "cocos2d.h"

#include "map/MapController.h"

class LayerMap : public cocos2d::Layer
{
private:
	std::vector<std::vector<cocos2d::Sprite*>> mapCellSet = std::vector<std::vector<cocos2d::Sprite*>>(MapController::mapNodecountVertical, std::vector<cocos2d::Sprite*>(MapController::mapNodecountHorizontal, nullptr));

	cocos2d::Vec2 mapGlobalCenterPoint = cocos2d::Vec2(1920.0 / 2.0, 1080.0 / 2.0);

	int leftTopGX = 0;
	int leftTopGY = 0;

public:
	static const float mapCellSize;
	static const float mapGroupSize;
	static const float globalMoveDuration;
	LayerMap()
	{
	}
	~LayerMap()
	{
	}

	CREATE_FUNC(LayerMap);

	virtual bool init() override;

	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;

	void loadMap();

	bool judgeMoveUp();
	bool judgeMoveDown();
	bool judgeMoveLeft();
	bool judgeMoveRight();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};

#endif
