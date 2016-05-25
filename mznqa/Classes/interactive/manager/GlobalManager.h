/*!
 * \file	Classes\interactive\manager\GlobalManager.h
 *
 * \brief	������ GlobalManager
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_MANAGER_GLOBALMANAGER_H_
#define MZNQA_CLASSES_INTERACTIVE_MANAGER_GLOBALMANAGER_H_

#include "cocos2d.h"

#include "common/arkca/Vector2.h"
#include "common/arkca/Direction.h"
#include "common/arkca/LineSegment.h"

#include "logic/controller/MapController.h"
#include "interactive/manager/TargetInfo.h"
#include "interactive/manager/SizeDefine.h"

/*!
 * \class	GlobalManager
 *
 * \brief	ȫ�ֹ�����
 *
 */
class GlobalManager
{
private:

	/*!
	 * \fn	GlobalManager::GlobalManager()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	GlobalManager()
	{
	}

	/*!
	 * \fn	GlobalManager::GlobalManager(const GlobalManager &globalManager);
	 *
	 * \brief	���صĿ������캯��
	 *
	 */
	GlobalManager(const GlobalManager &globalManager);

	/*!
	 * \fn	GlobalManager& GlobalManager::operator=(const GlobalManager &globalManager);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	GlobalManager& operator=(const GlobalManager &globalManager);
public:

	/*!
	 * \fn	GlobalManager::~GlobalManager()
	 *
	 * \brief	��������
	 *
	 */
	~GlobalManager()
	{
	}

	/*!
	 * \fn	static GlobalManager* GlobalManager::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 */
	static GlobalManager* Instance();

	/*!
	 * \fn	cocos2d::Vec2 GlobalManager::mapPosition2ScreenPostion(const ArKCa::Vector2<int> &mapPosition)
	 *
	 * \brief	���ݸ����ĵ�ͼ���귵��������Ļ������
	 *
	 * \param	mapPosition	ָ����ͼ����
	 *
	 */
	cocos2d::Vec2 mapPosition2ScreenPostion(const ArKCa::Vector2<int> &mapPosition)
	{
		auto origin = MapController::Instance()->getMapView().getViewOrigin();
		// TODO ���Ż����㣬�˴�Ӧ��ʵ����Ļ��Ȳ��� MAPCELL_SIZE �����������������ͼ��ĺ���ƫ������ʹ��ͼ������Ļ����
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

	/*!
	 * \fn	cocos2d::Vec2 GlobalManager::mapPosition2LayerMapPosition(const ArKCa::Vector2<int> &mapPosition)
	 *
	 * \brief	��ȡ��ͼ��߶�Ӧ��ͼ���е�����
	 *
	 * \param	mapPosition	ָ����ͼ����
	 *
	 */
	cocos2d::Vec2 mapPosition2LayerMapPosition(const ArKCa::Vector2<int> &mapPosition)
	{
		return cocos2d::Vec2(
			mapPosition.x * MAPCELL_SIZE + MAPCELL_SIZE_HALF,
			-(mapPosition.y * MAPCELL_SIZE + MAPCELL_SIZE_HALF)
			);
	}

	/*!
	 * \fn	ArKCa::LineSegment<float> GlobalManager::getMapCellEdgeByDirection( const ArKCa::Vector2<int> &mapCellPosition, ArKCa::Direction4 direction );
	 *
	 * \brief	��ȡָ����ͼ�ڵ�ı�Ե�߶�
	 *
	 * \param	mapCellPosition	ָ����ͼ�ڵ�����
	 * \param	direction	   	ָ������
	 *
	 */
	ArKCa::LineSegment<float> getMapCellEdgeByDirection(
		const ArKCa::Vector2<int> &mapCellPosition,
		ArKCa::Direction4 direction
		);

	/*!
	 * \fn	template <typename T> static cocos2d::Vec2 GlobalManager::Vector22Vec2(const ArKCa::Vector2<T> &position)
	 *
	 * \brief	���ת��
	 *
	 */
	template <typename T>
	static cocos2d::Vec2 Vector22Vec2(const ArKCa::Vector2<T> &position)
	{
		return cocos2d::Vec2(position.x, position.y);
	}
};

#endif
