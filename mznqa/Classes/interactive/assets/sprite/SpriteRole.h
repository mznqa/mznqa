/*!
 * \file	Classes\interactive\assets\sprite\SpriteRole.h
 *
 * \brief	定义类 SpriteRole
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_ASSETS_SPRITE_SPRITEROLE_H_
#define MZNQA_CLASSES_INTERACTIVE_ASSETS_SPRITE_SPRITEROLE_H_

#include "cocos2d.h"

/*!
 * \class	SpriteRole
 *
 * \brief	角色精灵
 *
 */
class SpriteRole : public cocos2d::Sprite
{
private:
	/*! \brief	移动动作的tag */
	static const int moveActionTag = 1;
public:

	/*!
	 * \fn	static SpriteRole* SpriteRole::create();
	 *
	 * \brief	创建函数
	 *
	 */
	static SpriteRole* create();

	/*!
	 * \fn	bool SpriteRole::updatePosition();
	 *
	 * \brief	更新位置
	 *
	 */
	bool updatePosition();
};

#endif