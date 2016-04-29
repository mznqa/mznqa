#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_SPRITECARD_H_
#define MZNQA_CLASSES_ENGINE_SPRITECARD_H_

#include <string>

#include "cocos2d.h"

class SpriteCard : public cocos2d::Sprite
{
public:
	enum EventIndex
	{
		EventIndex_Invalid = 0
	};

	SpriteCard()
	{
	}

	~SpriteCard()
	{
	}

	static SpriteCard* create(/*const std::string &filename*/);

	void initialize();

	void addEventListener(const EventIndex &eventIndex);

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);

private:

	EventIndex eventIndex = EventIndex_Invalid;

	cocos2d::Sprite *background;
};

#endif
