/*!
 * \file	Classes\interactive\assets\layer\LayerLightAndShadow.h
 *
 * \brief	定义类 LayerLightAndShadow
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_ASSETS_LAYER_LAYERLIGHTANDSHADOW_H_
#define MZNQA_CLASSES_INTERACTIVE_ASSETS_LAYER_LAYERLIGHTANDSHADOW_H_

#include <list>

#include "cocos2d.h"

#include "common/arkca/LineSegment.h"
#include "common/arkca/Vector2.h"

/*!
 * \class	LayerLightAndShadow
 *
 * \brief	光影层
 *
 */
class LayerLightAndShadow : public cocos2d::Layer
{
private:
	/*! \brief	减裁模板 */
	cocos2d::DrawNode *stencil;

	/*! \brief	亮光节点 */
	cocos2d::ClippingNode *clipperLight;
	/*! \brief	黑影节点 */
	cocos2d::ClippingNode *clipperShadow;

	/*! \brief	亮光底板 */
	cocos2d::Sprite *contentLight;
	/*! \brief	黑影底板 */
	cocos2d::LayerColor *contentShadow;

public:
	CREATE_FUNC(LayerLightAndShadow);

	/*!
	 * \fn	virtual bool LayerLightAndShadow::init();
	 *
	 * \brief	初始化层
	 *
	 */
	virtual bool init();

	/*!
	 * \fn	void LayerLightAndShadow::createStencil();
	 *
	 * \brief	创建减裁模板
	 *
	 */
	void createStencil();

	/*!
	 * \fn	void LayerLightAndShadow::createLight();
	 *
	 * \brief	创建光线
	 *
	 */
	void createLight();

	/*!
	 * \fn	void LayerLightAndShadow::createShadow();
	 *
	 * \brief	创建黑影
	 *
	 */
	void createShadow();

	/*!
	 * \fn	void LayerLightAndShadow::updateLightAndShadow( const ArKCa::Vector2<int> &lightPosition, const std::list<ArKCa::LineSegment<float>> &edge );
	 *
	 * \brief	更新光影
	 *
	 * \param	lightPosition	指定灯源坐标
	 * \param	edge		 	指定亮光区域边界
	 */
	void updateLightAndShadow(
		const ArKCa::Vector2<int> &lightPosition,
		const std::list<ArKCa::LineSegment<float>> &edge
		);
};

#endif
