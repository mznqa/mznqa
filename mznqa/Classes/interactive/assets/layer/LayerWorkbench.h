#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_ASSETS_LAYER_LAYERWORKBENCH_H_
#define MZNQA_CLASSES_INTERACTIVE_ASSETS_LAYER_LAYERWORKBENCH_H_

#include "cocos2d.h"
#include "ui/UIButton.h"

class LayerWorkbench : public cocos2d::Layer
{
private:
	cocos2d::Sprite *background;
	cocos2d::ui::Button *buttonDraw;
public:
	CREATE_FUNC(LayerWorkbench);

	virtual bool init();

	void build();
};

#endif
