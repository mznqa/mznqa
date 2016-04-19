#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_LAYERMAP_H_
#define MZNQA_CLASSES_ENGINE_LAYERMAP_H_

#include <vector>

#include "cocos2d.h"

#include "map/MapView.h"
#include "define/GlobalDefine.h"

class LayerMap : public cocos2d::Layer
{
private:
	std::vector<std::vector<cocos2d::Sprite*>> mapCellSet;

	cocos2d::Vec2 mapGlobalCenterPoint = cocos2d::Vec2(
		DESIGNRESOLUTIONSIZE_SCREENCENTER_HORIZONTAL,
		DESIGNRESOLUTIONSIZE_SCREENCENTER_VERTICAL
		);

	int screenViewMapCellCountWidth;
	int screenViewMapCellCountHeight;

	MapView *mapView;

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

	void addGlobalEventListener();

	void loadMapFromMapController();
};

#endif
