#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_LAYERMAP_H_
#define MZNQA_CLASSES_ENGINE_LAYERMAP_H_

#include <vector>

#include "cocos2d.h"

class LayerMap : public cocos2d::Layer
{
private:
	std::vector<std::vector<cocos2d::Sprite*>> mapCellSet = std::vector<std::vector<cocos2d::Sprite*>>(7, std::vector<cocos2d::Sprite*>(6));
public:
	LayerMap()
	{
	}
	~LayerMap()
	{
	}

	CREATE_FUNC(LayerMap);

	virtual bool init() override;

	void loadMap();
};

#endif
