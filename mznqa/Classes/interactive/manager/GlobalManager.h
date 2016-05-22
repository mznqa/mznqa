/*!
 * \file	Classes\interactive\manager\GlobalManager.h
 *
 * \brief	定义类 GlobalManager
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_MANAGER_GLOBALMANAGER_H_
#define MZNQA_CLASSES_INTERACTIVE_MANAGER_GLOBALMANAGER_H_

#include "cocos2d.h"

#include "common/arkca/Vector2.h"

#include "logic/controller/MapController.h"
#include "interactive/manager/TargetInfo.h"
#include "interactive/manager/SizeDefine.h"

/*!
 * \class	GlobalManager
 *
 * \brief	全局管理器
 *
 */
class GlobalManager
{
private:

	/*!
	 * \fn	GlobalManager::GlobalManager()
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	GlobalManager()
	{
	}

	/*!
	 * \fn	GlobalManager::GlobalManager(const GlobalManager &globalManager);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 */
	GlobalManager(const GlobalManager &globalManager);

	/*!
	 * \fn	GlobalManager& GlobalManager::operator=(const GlobalManager &globalManager);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 */
	GlobalManager& operator=(const GlobalManager &globalManager);
public:

	/*!
	 * \fn	GlobalManager::~GlobalManager()
	 *
	 * \brief	析构函数
	 *
	 */
	~GlobalManager()
	{
	}

	/*!
	 * \fn	static GlobalManager* GlobalManager::Instance();
	 *
	 * \brief	获取单例
	 *
	 */
	static GlobalManager* Instance();

	/*!
	 * \fn	cocos2d::Vec2 GlobalManager::mapPosition2ScreenPostion(const ArKCa::Vector2<int> &mapPosition)
	 *
	 * \brief	根据给定的地图坐标返回其在屏幕的坐标
	 *
	 * \param	mapPosition	指定地图坐标
	 *
	 */
	cocos2d::Vec2 mapPosition2ScreenPostion(const ArKCa::Vector2<int> &mapPosition)
	{
		auto origin = MapController::Instance()->getMapView().getViewOrigin();
		// TODO 待优化计算，此处应对实际屏幕宽度不是 MAPCELL_SIZE 的整数倍，而计算地图层的横向偏移量以使地图处于屏幕中心
		auto mVO = ArKCa::Vector2<float>(
			TargetInfo::Instance()->getScreenLeftTopOrigin().x + (
			TargetInfo::Instance()->getScreenSize().width -
			MapController::Instance()->getMapView().getViewSize().width * MAPCELL_SIZE
			) / 2.0,
			TargetInfo::Instance()->getScreenLeftTopOrigin().y
			);
		return cocos2d::Vec2(
			mVO.x - (origin.x - mapPosition.x) * MAPCELL_SIZE,
			mVO.y + (origin.y - mapPosition.y) * MAPCELL_SIZE
			);
	}
};

#endif
