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
#include "interactive/assets/sprite/SpriteRole.h"
#include "interactive/assets/layer/LayerLightAndShadow.h"

/*!
 * \class	LayerMap
 *
 * \brief	��ͼ��
 *
 */
class LayerMap : public cocos2d::Layer
{
private:
	/*! \brief	��ʶ��ͼ�ڵ� */
	static const int mapNodeFlag = 1;

	/*! \brief	�������ZOrder */
	static const int extraZOrder = 11;
	/*! \brief	��ʶ��ͼ������ */
	static const int extarFlag = 2;

	/*! \brief	��ɫ��ZOrder */
	static const int roleZOrder = 12;

	/*! \brief	��Ӱ���ZOrder */
	static const int layerLightAndShadowZOrder = 10;

	/*! \brief	�ο��ߵ�ZOrder */
	static const int guidesZOrder = 9;

	/*! \brief	��ͼ�ڵ㼯�� */
	std::vector<std::vector<cocos2d::Sprite*>> mapNodeSet;
	/*! \brief	��ͼ�����Ｏ�� */
	std::vector<std::vector<cocos2d::Sprite*>> extraSet;

	/*! \brief	����ʹ�ã����津���� */
	cocos2d::Vec2 touchPoint;

	/*! \brief	ȫ���ƶ�������tag */
	static const int globalMoveActionTag = 1;

	/*! \brief	��ɫ */
	SpriteRole *spriteRole;

	/*! \brief	��Ӱ�� */
	LayerLightAndShadow *layerLightAndShadow;

	/*! \brief	�ο��߲� */
	cocos2d::DrawNode *guides;

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

	/*!
	 * \fn	int LayerMap::getZOrderByMapNodeType(MapNode::NodeType nodeType)
	 *
	 * \brief	���ݵ�ͼ�ڵ����ͻ�ȡZOrder
	 *
	 * \param	nodeType	ָ����ͼ�ڵ�����
	 *
	 */
	int getZOrderByMapNodeType(MapNode::NodeType nodeType)
	{
		switch (nodeType)
		{
		case MapNode::NodeType_None:
		case MapNode::NodeType_None_Const:
			return 1;
		case MapNode::NodeType_Road:
		case MapNode::NodeType_Road_Const:
			return 2;
		case MapNode::NodeType_Wall:
		case MapNode::NodeType_Wall_Const:
			return 3;
		case MapNode::NodeType_Border_Const:
			return 4;
		default:
			return 8;
		}
	}

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
	* \brief	���ȫ���¼�����
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

	/*!
	 * \fn	void LayerMap::updateGlobalMapPositionByAction();
	 *
	 * \brief	ͨ����������ȫ�ֵ�ͼ��λ��
	 *
	 */
	void updateGlobalMapPositionByAction();

	/*!
	 * \fn	void LayerMap::loadSpriteRole();
	 *
	 * \brief	�����ɫ��
	 *
	 */
	void loadSpriteRole();

	/*!
	 * \fn	SpriteRole* LayerMap::getSpriteRole()
	 *
	 * \brief	��ȡ��ɫ��
	 *
	 */
	SpriteRole* getSpriteRole()
	{
		return spriteRole;
	}

	/*!
	 * \fn	void LayerMap::buildLayerLightAndShadow();
	 *
	 * \brief	������Ӱ��
	 *
	 */
	void buildLayerLightAndShadow();

	/*!
	 * \fn	LayerLightAndShadow* LayerMap::getLayerLightAndShadow();
	 *
	 * \brief	��ȡ��Ӱ��
	 *
	 */
	LayerLightAndShadow* getLayerLightAndShadow();

	/*!
	 * \fn	void LayerMap::updateMapGroup(const ArKCa::Vector2<int> &groupOrigin);
	 *
	 * \brief	���µ�ͼ��
	 *
	 * \param	groupOrigin	ָ����ͼ���ԭ��
	 */
	void updateMapGroup(const ArKCa::Vector2<int> &groupOrigin);

	/*!
	 * \fn	void LayerMap::buildGuides();
	 *
	 * \brief	�����ο���
	 *
	 */
	void buildGuides();

	/*!
	 * \fn	void LayerMap::showGuides();
	 *
	 * \brief	��ʾ�ο���
	 *
	 */
	void showGuides();

	/*!
	 * \fn	void LayerMap::eraseGuides();
	 *
	 * \brief	�����ο���
	 *
	 */
	void eraseGuides();
};

#endif
