#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_SPRITEROLE_H_
#define MZNQA_CLASSES_ENGINE_SPRITEROLE_H_

#include <string>

#include "cocos2d.h"

class SpriteRole : public cocos2d::Sprite
{
private:
public:
	SpriteRole()
	{
	}
	~SpriteRole()
	{
	}

	static SpriteRole* create(const std::string &filename);

	void initialize();

	void refresh();
};

#endif
