#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_LAYERROLE_H_
#define MZNQA_CLASSES_ENGINE_LAYERROLE_H_

#include "cocos2d.h"

class LayerRole : public cocos2d::Layer
{
private:
	cocos2d::Sprite *roleSprite;
public:
	LayerRole()
	{
	}
	~LayerRole()
	{
	}

	CREATE_FUNC(LayerRole);

	virtual bool init() override;

	void loadRole();

	void refresh();
};

#endif
