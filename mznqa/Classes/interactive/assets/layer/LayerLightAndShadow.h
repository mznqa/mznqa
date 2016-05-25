/*!
 * \file	Classes\interactive\assets\layer\LayerLightAndShadow.h
 *
 * \brief	������ LayerLightAndShadow
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
 * \brief	��Ӱ��
 *
 */
class LayerLightAndShadow : public cocos2d::Layer
{
private:
	/*! \brief	����ģ�� */
	cocos2d::DrawNode *stencil;

	/*! \brief	����ڵ� */
	cocos2d::ClippingNode *clipperLight;
	/*! \brief	��Ӱ�ڵ� */
	cocos2d::ClippingNode *clipperShadow;

	/*! \brief	����װ� */
	cocos2d::Sprite *contentLight;
	/*! \brief	��Ӱ�װ� */
	cocos2d::LayerColor *contentShadow;

public:
	CREATE_FUNC(LayerLightAndShadow);

	/*!
	 * \fn	virtual bool LayerLightAndShadow::init();
	 *
	 * \brief	��ʼ����
	 *
	 */
	virtual bool init();

	/*!
	 * \fn	void LayerLightAndShadow::createStencil();
	 *
	 * \brief	��������ģ��
	 *
	 */
	void createStencil();

	/*!
	 * \fn	void LayerLightAndShadow::createLight();
	 *
	 * \brief	��������
	 *
	 */
	void createLight();

	/*!
	 * \fn	void LayerLightAndShadow::createShadow();
	 *
	 * \brief	������Ӱ
	 *
	 */
	void createShadow();

	/*!
	 * \fn	void LayerLightAndShadow::updateLightAndShadow( const ArKCa::Vector2<int> &lightPosition, const std::list<ArKCa::LineSegment<float>> &edge );
	 *
	 * \brief	���¹�Ӱ
	 *
	 * \param	lightPosition	ָ����Դ����
	 * \param	edge		 	ָ����������߽�
	 */
	void updateLightAndShadow(
		const ArKCa::Vector2<int> &lightPosition,
		const std::list<ArKCa::LineSegment<float>> &edge
		);
};

#endif
