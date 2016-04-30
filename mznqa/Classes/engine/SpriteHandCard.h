#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_SPRITEHADNCARD_H_
#define MZNQA_CLASSES_ENGINE_SPRITEHADNCARD_H_

#include <string>

#include "cocos2d.h"

class SpriteHandCard : public cocos2d::Sprite
{
public:

	enum HandCardState
	{
		HandCardState_AtStateWorkBench,
		HandCardState_AtStateShow,
		HandCardState_AtEntity
	};

	enum EventIndex
	{
		EventIndex_Invalid = 9999,
		EventIndex_HandCard_0 = 0,
		EventIndex_HandCard_1 = 1,
		EventIndex_HandCard_2 = 2,
		EventIndex_HandCard_3 = 3,
		EventIndex_HandCard_4 = 4
	};

	SpriteHandCard()
	{
	}

	~SpriteHandCard()
	{
	}

	static SpriteHandCard* create(/*const std::string &filename*/);

	void initialize();

	void addEventListener(const EventIndex &eventIndex);

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	void changeState(HandCardState state);

	HandCardState getState();

	void makeEntity();

private:

	HandCardState state = HandCardState_AtStateWorkBench;

	EventIndex eventIndex = EventIndex_Invalid;

	cocos2d::Sprite *spriteBackground;

	cocos2d::Sprite *spriteEntity;
};

#endif
