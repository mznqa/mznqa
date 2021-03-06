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

#include "logic/controller/MapController.h"

/*!
 * \class	LayerMap
 *
 * \brief	地图层
 *
 */
class LayerMap : public cocos2d::Layer
{
private:
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

	/*! \brief	触摸使用，保存触摸点 */
	cocos2d::Vec2 touchPoint;

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
	* \fn	virtual bool LayerMap::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;
	*
	* \brief	触屏事件重写：触碰屏幕
	*
	*/
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;

	/*!
	* \fn	virtual void LayerMap::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;
	*
	* \brief	触屏事件重写：移动焦点
	*
	*/
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;

	/*!
	* \fn	virtual void LayerMap::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;
	*
	* \brief	触屏事件重写：离开屏幕
	*
	*/
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;

	/*!
	* \fn	void LayerMap::addGlobalEventListener();
	*
	* \brief	添加全局事件监听
	*
	*/
	void addGlobalEventListener();

	/*!
	 * \fn	void LayerMap::loadMap();
	 *
	 * \brief	载入地图
	 *
	 */
	void loadMap();

	/*!
	 * \fn	const ArKCa::Vector2<float> LayerMap::getMapViewOrigin()const;
	 *
	 * \brief	获取地图视野的起点
	 *
	 */
	const ArKCa::Vector2<float> getMapViewOrigin()const;

	/*!
	 * \fn	const ArKCa::Size<float> LayerMap::getMapViewSize()const;
	 *
	 * \brief	获取地图视野大小
	 *
	 *
	 */
	const ArKCa::Size<float> getMapViewSize()const;

	/*!
	* \fn	void LayerMap::updateGlobalMapPosition();
	*
	* \brief	更新全局地图的位置
	*
	*/
	void updateGlobalMapPosition();
};

#endif
