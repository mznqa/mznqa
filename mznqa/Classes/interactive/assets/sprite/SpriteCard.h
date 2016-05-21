/*!
 * \file	Classes\interactive\assets\sprite\SpriteCard.h
 *
 * \brief	定义类 SpriteCard
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_ASSETS_SPRITE_SPRITECARD_H_
#define MZNQA_CLASSES_INTERACTIVE_ASSETS_SPRITE_SPRITECARD_H_

#include "cocos2d.h"

/*!
 * \class	SpriteCard
 *
 * \brief	卡牌精灵
 *
 */
class SpriteCard : public cocos2d::Sprite
{
public:

	/*!
	 * \enum	EventIndex
	 *
	 * \brief	卡牌事件索引
	 */
	enum EventIndex
	{
		EventIndex_Invalid = 9999,	///< 无效的事件索引
		EventIndex_HandCard_0 = 0,	///< 索引为0的卡牌事件索引
		EventIndex_HandCard_1 = 1,	///< 索引为1的卡牌事件索引
		EventIndex_HandCard_2 = 2,	///< 索引为2的卡牌事件索引
		EventIndex_HandCard_3 = 3,	///< 索引为3的卡牌事件索引
		EventIndex_HandCard_4 = 4	///< 索引为4的卡牌事件索引
	};

	/*!
	 * \fn	static SpriteCard* SpriteCard::create(int cardID);
	 *
	 * \brief	创建卡牌精灵
	 *
	 * \param	cardID	指定卡牌ID
	 *
	 */
	static SpriteCard* create(int cardID);

	/*!
	 * \fn	void SpriteCard::addEventListener(EventIndex eventIndex);
	 *
	 * \brief	添加触摸事件监听
	 *
	 * \param	eventIndex	指定事件索引
	 */
	void addEventListener(EventIndex eventIndex);

	/*!
	 * \fn	bool SpriteCard::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	 *
	 * \brief	触摸监听事件
	 *
	 */
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	/*!
	 * \fn	void SpriteCard::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	 *
	 * \brief	触摸监听事件
	 *
	 */
	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	/*!
	 * \fn	void SpriteCard::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	 *
	 * \brief	触摸监听事件
	 *
	 */
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
private:
	/*! \brief	事件监听索引 */
	EventIndex eventIndex;
};

#endif
