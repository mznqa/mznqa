/*!
 * \file	Classes\interactive\assets\layer\LayerWorkbench.h
 *
 * \brief	定义类 LayerWorkbench
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
 * \brief	手牌栏
 *
 */
class LayerWorkbench : public cocos2d::Layer
{
private:
	/*! \brief	手牌层的层级 */
	static const int CardSpriteZOrder = 1;
	/*! \brief	手牌的位置集合 */
	static std::array<cocos2d::Vec2, EXPLORE_CARDHOLDERSIZE> cardPositionSet;
	/*! \brief	手牌精灵的标签 */
	static const int cardSpriteTag = 1;

	/*! \brief	背景层 */
	cocos2d::Sprite *background;
	/*! \brief	抽牌按钮 */
	cocos2d::ui::Button *buttonDraw;

	/*! \brief	手牌精灵集 */
	std::array<SpriteCard*, EXPLORE_CARDHOLDERSIZE> cardSet;

public:
	CREATE_FUNC(LayerWorkbench);

	/*!
	 * \fn	virtual bool LayerWorkbench::init();
	 *
	 * \brief	重写启动函数
	 *
	 */
	virtual bool init();

	/*!
	 * \fn	void LayerWorkbench::addGlobalEventListener();
	 *
	 * \brief	设置全局监听事件
	 *
	 */
	void addGlobalEventListener();

	/*!
	 * \fn	virtual bool LayerWorkbench::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;
	 *
	 * \brief	重写触摸监听事件
	 *
	 */
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;

	/*!
	 * \fn	virtual void LayerWorkbench::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;
	 *
	 * \brief	重写触摸监听事件
	 *
	 */
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;

	/*!
	 * \fn	virtual void LayerWorkbench::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;
	 *
	 * \brief	重写触摸监听时间
	 *
	 */
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;

	/*!
	 * \fn	void LayerWorkbench::buildBackground();
	 *
	 * \brief	搭建背景层
	 *
	 */
	void buildBackground();

	/*!
	 * \fn	void LayerWorkbench::buildButtonDraw();
	 *
	 * \brief	搭建抽牌按钮
	 *
	 */
	void buildButtonDraw();

	/*!
	 * \fn	void LayerWorkbench::buildCardSet();
	 *
	 * \brief	搭建手牌精灵集合
	 *
	 */
	void buildCardSet();

	/*!
	 * \fn	void LayerWorkbench::executeAddCard(int index);
	 *
	 * \brief	执行添加手牌的操作
	 *
	 * \param	index	返回新添的手牌的索引
	 */
	void executeAddCard(int index);
};

#endif
