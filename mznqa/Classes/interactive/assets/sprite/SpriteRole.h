/*!
 * \file	Classes\interactive\assets\sprite\SpriteRole.h
 *
 * \brief	������ SpriteRole
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_ASSETS_SPRITE_SPRITEROLE_H_
#define MZNQA_CLASSES_INTERACTIVE_ASSETS_SPRITE_SPRITEROLE_H_

#include "cocos2d.h"

#include "interactive/manager/LightArea.h"

/*!
 * \class	SpriteRole
 *
 * \brief	��ɫ����
 *
 */
class SpriteRole : public cocos2d::Sprite
{
private:
	/*! \brief	�ƶ�������tag */
	static const int moveActionTag = 1;

	/*! \brief	�ƹ����� */
	LightArea lightArea;

public:

	/*!
	 * \fn	static SpriteRole* SpriteRole::create();
	 *
	 * \brief	��������
	 *
	 */
	static SpriteRole* create();

	/*!
	 * \fn	bool SpriteRole::updatePosition();
	 *
	 * \brief	����λ��
	 *
	 */
	bool updatePosition();

	/*!
	 * \fn	void SpriteRole::createLightArea();
	 *
	 * \brief	�����ƹ�����
	 *
	 */
	void createLightArea();

	/*!
	 * \fn	LightArea& SpriteRole::getLightArea();
	 *
	 * \brief	��ȡ�ƹ�����
	 *
	 */
	LightArea& getLightArea();
};

#endif