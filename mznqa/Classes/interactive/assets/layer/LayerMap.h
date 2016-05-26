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
#include "interactive/assets/sprite/SpriteRole.h"
#include "interactive/assets/layer/LayerLightAndShadow.h"

/*!
 * \class	LayerMap
 *
 * \brief	地图层
 *
 */
class LayerMap : public cocos2d::Layer
{
private:
	/*! \brief	标识地图节点 */
	static const int mapNodeFlag = 1;

	/*! \brief	附加物的ZOrder */
	static const int extraZOrder = 11;
	/*! \brief	标识地图附加物 */
	static const int extarFlag = 2;

	/*! \brief	角色的ZOrder */
	static const int roleZOrder = 12;

	/*! \brief	光影层的ZOrder */
	static const int layerLightAndShadowZOrder = 10;

	/*! \brief	参考线的ZOrder */
	static const int guidesZOrder = 9;

	/*! \brief	地图节点集合 */
	std::vector<std::vector<cocos2d::Sprite*>> mapNodeSet;
	/*! \brief	地图附加物集合 */
	std::vector<std::vector<cocos2d::Sprite*>> extraSet;

	/*! \brief	触摸使用，保存触摸点 */
	cocos2d::Vec2 touchPoint;

	/*! \brief	全局移动动作的tag */
	static const int globalMoveActionTag = 1;

	/*! \brief	角色 */
	SpriteRole *spriteRole;

	/*! \brief	光影层 */
	LayerLightAndShadow *layerLightAndShadow;

	/*! \brief	参考线层 */
	cocos2d::DrawNode *guides;

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

	/*!
	 * \fn	int LayerMap::getZOrderByMapNodeType(MapNode::NodeType nodeType)
	 *
	 * \brief	根据地图节点类型获取ZOrder
	 *
	 * \param	nodeType	指定地图节点类型
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

	/*!
	 * \fn	void LayerMap::updateGlobalMapPositionByAction();
	 *
	 * \brief	通过动画更新全局地图的位置
	 *
	 */
	void updateGlobalMapPositionByAction();

	/*!
	 * \fn	void LayerMap::loadSpriteRole();
	 *
	 * \brief	载入角色层
	 *
	 */
	void loadSpriteRole();

	/*!
	 * \fn	SpriteRole* LayerMap::getSpriteRole()
	 *
	 * \brief	获取角色层
	 *
	 */
	SpriteRole* getSpriteRole()
	{
		return spriteRole;
	}

	/*!
	 * \fn	void LayerMap::buildLayerLightAndShadow();
	 *
	 * \brief	建立光影层
	 *
	 */
	void buildLayerLightAndShadow();

	/*!
	 * \fn	LayerLightAndShadow* LayerMap::getLayerLightAndShadow();
	 *
	 * \brief	获取光影层
	 *
	 */
	LayerLightAndShadow* getLayerLightAndShadow();

	/*!
	 * \fn	void LayerMap::updateMapGroup(const ArKCa::Vector2<int> &groupOrigin);
	 *
	 * \brief	更新地图组
	 *
	 * \param	groupOrigin	指定地图组的原点
	 */
	void updateMapGroup(const ArKCa::Vector2<int> &groupOrigin);

	/*!
	 * \fn	void LayerMap::buildGuides();
	 *
	 * \brief	创建参考线
	 *
	 */
	void buildGuides();

	/*!
	 * \fn	void LayerMap::showGuides();
	 *
	 * \brief	显示参考线
	 *
	 */
	void showGuides();

	/*!
	 * \fn	void LayerMap::eraseGuides();
	 *
	 * \brief	擦出参考线
	 *
	 */
	void eraseGuides();
};

#endif
