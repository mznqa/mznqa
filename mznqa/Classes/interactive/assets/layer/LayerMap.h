/*!
 * \file	Classes\interactive\assets\layer\LayerMap.h
 *
 * \brief	������ LayerMap
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_ASSETS_LAYER_LAYERMAP_H_
#define MZNQA_CLASSES_INTERACTIVE_ASSETS_LAYER_LAYERMAP_H_

#include <vector>

#include "cocos2d.h"

#include "logic/controller/MapController.h"

/*!
 * \class	LayerMap
 *
 * \brief	��ͼ��
 *
 */
class LayerMap : public cocos2d::Layer
{
private:
	/*! \brief	��ͼ�ڵ��ZOrder */
	static const int mapNodeZOrder = 1;
	/*! \brief	��ʶ��ͼ�ڵ� */
	static const int mapNodeFlag = 1;

	/*! \brief	�������ZOrder */
	static const int extraZOrder = 2;
	/*! \brief	��ʶ��ͼ������ */
	static const int extarFlag = 2;

	/*! \brief	��ͼ�ڵ㼯�� */
	std::vector<std::vector<cocos2d::Sprite*>> mapNodeSet;
	/*! \brief	��ͼ�����Ｏ�� */
	std::vector<std::vector<cocos2d::Sprite*>> extraSet;

	/*! \brief	����ʹ�ã����津���� */
	cocos2d::Vec2 touchPoint;

	/*!
	 * \fn	static cocos2d::Sprite* LayerMap::createMapNodeByNodeType(MapNode::NodeType nodeType);
	 *
	 * \brief	���ݽڵ����ʹ�����Ӧ�ĵ�ͼ����
	 *
	 * \param	nodeType	ָ���ڵ�����
	 *
	 */
	static cocos2d::Sprite* createMapNodeByNodeType(MapNode::NodeType nodeType);

	/*!
	 * \fn	static cocos2d::Sprite* LayerMap::createExtraByExtraType(MapNode::ExtraType extraType);
	 *
	 * \brief	���ݸ��������ʹ�����Ӧ�ľ���
	 *
	 * \param	extraType	ָ������������
	 *
	 */
	static cocos2d::Sprite* createExtraByExtraType(MapNode::ExtraType extraType);

public:
	CREATE_FUNC(LayerMap);

	/*!
	 * \fn	virtual bool LayerMap::init();
	 *
	 * \brief	��ʼ����
	 *
	 */
	virtual bool init();

	/*!
	* \fn	virtual bool LayerMap::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;
	*
	* \brief	�����¼���д��������Ļ
	*
	*/
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;

	/*!
	* \fn	virtual void LayerMap::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;
	*
	* \brief	�����¼���д���ƶ�����
	*
	*/
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;

	/*!
	* \fn	virtual void LayerMap::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;
	*
	* \brief	�����¼���д���뿪��Ļ
	*
	*/
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;

	/*!
	* \fn	void LayerMap::addGlobalEventListener();
	*
	* \brief	����ȫ���¼�����
	*
	*/
	void addGlobalEventListener();

	/*!
	 * \fn	void LayerMap::loadMap();
	 *
	 * \brief	�����ͼ
	 *
	 */
	void loadMap();

	/*!
	 * \fn	const ArKCa::Vector2<float> LayerMap::getMapViewOrigin()const;
	 *
	 * \brief	��ȡ��ͼ��Ұ�����
	 *
	 */
	const ArKCa::Vector2<float> getMapViewOrigin()const;

	/*!
	 * \fn	const ArKCa::Size<float> LayerMap::getMapViewSize()const;
	 *
	 * \brief	��ȡ��ͼ��Ұ��С
	 *
	 *
	 */
	const ArKCa::Size<float> getMapViewSize()const;

	/*!
	* \fn	void LayerMap::updateGlobalMapPosition();
	*
	* \brief	����ȫ�ֵ�ͼ��λ��
	*
	*/
	void updateGlobalMapPosition();
};

#endif