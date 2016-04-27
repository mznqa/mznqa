#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_SPRITECARD_H_
#define MZNQA_CLASSES_ENGINE_SPRITECARD_H_

#include <string>

#include "cocos2d.h"

class SpriteCard : public cocos2d::Sprite
{
private:

	cocos2d::Sprite *background;

public:

	SpriteCard()
	{
	}

	~SpriteCard()
	{
	}

	static SpriteCard* create(/*const std::string &filename*/);

	void initialize();
};

#endif
