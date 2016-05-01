/*!
 * \file	Classes\engine\LayerMap.h
 *
 * \brief	定义类 LayerMap
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_LAYERMAP_H_
#define MZNQA_CLASSES_ENGINE_LAYERMAP_H_

#include <vector>

#include "cocos2d.h"

#include "map/MapView.h"
#include "define/GlobalDefine.h"
#include "tools/GPointSet.h"
#include "engine/SizeController.h"

/*!
 * \class	LayerMap
 *
 * \brief	地图层
 *
 */
class LayerMap : public cocos2d::Layer
{
private:
	SizeController *const SizeControllerInstance = SizeController::Instance();

	/*! \brief	存放地图节点精灵 */
	std::vector<std::vector<cocos2d::Sprite*>> mapCellSet;

	/*! \brief	地图视野中心点的屏幕坐标 */
	cocos2d::Vec2 mapViewCenterPoint = cocos2d::Vec2(
		SizeControllerInstance->realityScreenSizeWidth / 2.0,
		SizeControllerInstance->realityScreenSizeHeight / 2.0
		);

public:

	/*!
	 * \enum	ActionFlags
	 *
	 * \brief	层内的动作Flags
	 */
	enum ActionFlags
	{
		ActionFlags_LayerMove = 1	///< 移动整个层的动作
	};

	/*!
	 * \fn	LayerMap::LayerMap()
	 *
	 * \brief	构造函数
	 *
	 */
	LayerMap()
	{
	}

	/*!
	 * \fn	LayerMap::~LayerMap()
	 *
	 * \brief	析构函数
	 *
	 */
	~LayerMap()
	{
	}

	CREATE_FUNC(LayerMap);

	/*!
	 * \fn	virtual bool LayerMap::init() override;
	 *
	 * \brief	init 方法重写
	 *
	 */
	virtual bool init() override;

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
	 * \fn	void LayerMap::loadMapFromMapController();
	 *
	 * \brief	从地图控制器中载入全局地图
	 *
	 */
	void loadMapFromMapController();

	/*!
	 * \fn	void LayerMap::refreshPosition();
	 *
	 * \brief	更新整层的位置
	 *
	 */
	void refreshPosition();

	/*!
	 * \fn	void LayerMap::initialize();
	 *
	 * \brief	初始化地图层
	 *
	 */
	void initialize();

	void refreshMapCellWithGPointSet(const GPointSet &gPointSet);
};

#endif
