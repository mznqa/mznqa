/*!
 * \file	Classes\interactive\assets\sprite\SpriteCard.h
 *
 * \brief	������ SpriteCard
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_ASSETS_SPRITE_SPRITECARD_H_
#define MZNQA_CLASSES_INTERACTIVE_ASSETS_SPRITE_SPRITECARD_H_

#include "cocos2d.h"

/*!
 * \class	SpriteCard
 *
 * \brief	���ƾ���
 *
 */
class SpriteCard : public cocos2d::Sprite
{
public:

	/*!
	 * \enum	EventIndex
	 *
	 * \brief	�����¼�����
	 */
	enum EventIndex
	{
		EventIndex_Invalid = 9999,	///< ��Ч���¼�����
		EventIndex_HandCard_0 = 0,	///< ����Ϊ0�Ŀ����¼�����
		EventIndex_HandCard_1 = 1,	///< ����Ϊ1�Ŀ����¼�����
		EventIndex_HandCard_2 = 2,	///< ����Ϊ2�Ŀ����¼�����
		EventIndex_HandCard_3 = 3,	///< ����Ϊ3�Ŀ����¼�����
		EventIndex_HandCard_4 = 4	///< ����Ϊ4�Ŀ����¼�����
	};

	/*!
	 * \fn	static SpriteCard* SpriteCard::create(int cardID);
	 *
	 * \brief	�������ƾ���
	 *
	 * \param	cardID	ָ������ID
	 *
	 */
	static SpriteCard* create(int cardID);

	/*!
	 * \fn	void SpriteCard::addEventListener(EventIndex eventIndex);
	 *
	 * \brief	��Ӵ����¼�����
	 *
	 * \param	eventIndex	ָ���¼�����
	 */
	void addEventListener(EventIndex eventIndex);

	/*!
	 * \fn	bool SpriteCard::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	 *
	 * \brief	���������¼�
	 *
	 */
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	/*!
	 * \fn	void SpriteCard::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	 *
	 * \brief	���������¼�
	 *
	 */
	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	/*!
	 * \fn	void SpriteCard::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	 *
	 * \brief	���������¼�
	 *
	 */
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
private:
	/*! \brief	�¼��������� */
	EventIndex eventIndex;
};

#endif
