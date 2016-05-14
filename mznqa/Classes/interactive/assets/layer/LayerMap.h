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

#include "interactive/manager/TargetInfo.h"
#include "logic/controller/MapController.h"
#include "logic/gameObject/map/MapNode.h"

/*!
 * \class	LayerMap
 *
 * \brief	��ͼ��
 *
 */
class LayerMap : public cocos2d::Layer
{
private:
	// �������� //////////////////////////////////////////////////////////////////////////
	/*! \brief	TargetInfo �������� */
	TargetInfo *const TargetInfoInstance = TargetInfo::Instance();
	/*! \brief	MapControllerInstance �������� */
	MapController *const MapControllerInstance = MapController::Instance();
	//////////////////////////////////////////////////////////////////////////

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
	 * \fn	void LayerMap::loadMap();
	 *
	 * \brief	�����ͼ
	 *
	 */
	void loadMap();
};

#endif
