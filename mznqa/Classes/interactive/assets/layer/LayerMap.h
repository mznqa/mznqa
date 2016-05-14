/*!
 * \file	Classes\interactive\assets\layer\LayerMap.h
 *
 * \brief	定义类 LayerMap
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
 * \brief	地图层
 *
 */
class LayerMap : public cocos2d::Layer
{
private:
	// 单例别名 //////////////////////////////////////////////////////////////////////////
	/*! \brief	TargetInfo 单例别名 */
	TargetInfo *const TargetInfoInstance = TargetInfo::Instance();
	/*! \brief	MapControllerInstance 单例别名 */
	MapController *const MapControllerInstance = MapController::Instance();
	//////////////////////////////////////////////////////////////////////////

	/*! \brief	地图节点的ZOrder */
	static const int mapNodeZOrder = 1;
	/*! \brief	标识地图节点 */
	static const int mapNodeFlag = 1;

	/*! \brief	附加物的ZOrder */
	static const int extraZOrder = 2;
	/*! \brief	标识地图附加物 */
	static const int extarFlag = 2;

	/*! \brief	地图节点集合 */
	std::vector<std::vector<cocos2d::Sprite*>> mapNodeSet;
	/*! \brief	地图附加物集合 */
	std::vector<std::vector<cocos2d::Sprite*>> extraSet;

	/*!
	 * \fn	static cocos2d::Sprite* LayerMap::createMapNodeByNodeType(MapNode::NodeType nodeType);
	 *
	 * \brief	根据节点类型创建对应的地图精灵
	 *
	 * \param	nodeType	指定节点类型
	 *
	 */
	static cocos2d::Sprite* createMapNodeByNodeType(MapNode::NodeType nodeType);

	/*!
	 * \fn	static cocos2d::Sprite* LayerMap::createExtraByExtraType(MapNode::ExtraType extraType);
	 *
	 * \brief	根据附加物类型创建对应的精灵
	 *
	 * \param	extraType	指定附加物类型
	 *
	 */
	static cocos2d::Sprite* createExtraByExtraType(MapNode::ExtraType extraType);
public:
	CREATE_FUNC(LayerMap);

	/*!
	 * \fn	virtual bool LayerMap::init();
	 *
	 * \brief	初始化层
	 *
	 */
	virtual bool init();

	/*!
	 * \fn	void LayerMap::loadMap();
	 *
	 * \brief	载入地图
	 *
	 */
	void loadMap();
};

#endif
