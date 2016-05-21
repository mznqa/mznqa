/*!
 * \file	Classes\interactive\assets\layer\LayerWorkbench.h
 *
 * \brief	������ LayerWorkbench
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_ASSETS_LAYER_LAYERWORKBENCH_H_
#define MZNQA_CLASSES_INTERACTIVE_ASSETS_LAYER_LAYERWORKBENCH_H_

#include <array>

#include "cocos2d.h"
#include "ui/UIButton.h"

#include "interactive/assets/sprite/SpriteCard.h"
#include "logic/data/info/NumDefine.h"

/*!
 * \class	LayerWorkbench
 *
 * \brief	������
 *
 */
class LayerWorkbench : public cocos2d::Layer
{
private:
	/*! \brief	���Ʋ�Ĳ㼶 */
	static const int CardSpriteZOrder = 1;
	/*! \brief	���Ƶ�λ�ü��� */
	static std::array<cocos2d::Vec2, EXPLORE_CARDHOLDERSIZE> cardPositionSet;
	/*! \brief	���ƾ���ı�ǩ */
	static const int cardSpriteTag = 1;

	/*! \brief	������ */
	cocos2d::Sprite *background;
	/*! \brief	���ư�ť */
	cocos2d::ui::Button *buttonDraw;

	/*! \brief	���ƾ��鼯 */
	std::array<SpriteCard*, EXPLORE_CARDHOLDERSIZE> cardSet;

public:
	CREATE_FUNC(LayerWorkbench);

	/*!
	 * \fn	virtual bool LayerWorkbench::init();
	 *
	 * \brief	��д��������
	 *
	 */
	virtual bool init();

	/*!
	 * \fn	void LayerWorkbench::addGlobalEventListener();
	 *
	 * \brief	����ȫ�ּ����¼�
	 *
	 */
	void addGlobalEventListener();

	/*!
	 * \fn	virtual bool LayerWorkbench::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;
	 *
	 * \brief	��д���������¼�
	 *
	 */
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;

	/*!
	 * \fn	virtual void LayerWorkbench::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;
	 *
	 * \brief	��д���������¼�
	 *
	 */
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;

	/*!
	 * \fn	virtual void LayerWorkbench::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;
	 *
	 * \brief	��д��������ʱ��
	 *
	 */
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;

	/*!
	 * \fn	void LayerWorkbench::buildBackground();
	 *
	 * \brief	�������
	 *
	 */
	void buildBackground();

	/*!
	 * \fn	void LayerWorkbench::buildButtonDraw();
	 *
	 * \brief	����ư�ť
	 *
	 */
	void buildButtonDraw();

	/*!
	 * \fn	void LayerWorkbench::buildCardSet();
	 *
	 * \brief	����ƾ��鼯��
	 *
	 */
	void buildCardSet();

	/*!
	 * \fn	void LayerWorkbench::executeAddCard(int index);
	 *
	 * \brief	ִ��������ƵĲ���
	 *
	 * \param	index	������������Ƶ�����
	 */
	void executeAddCard(int index);
};

#endif
