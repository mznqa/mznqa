/*!
 * \file	Classes\interactive\manager\GlobalManager.cpp
 *
 * \brief	∂®“Â¿‡ GlobalManager
 */

#pragma execution_character_set("utf-8")

#include "interactive/manager/GlobalManager.h"

GlobalManager* GlobalManager::Instance()
{
	static GlobalManager instance;
	return &instance;
}

ArKCa::LineSegment<float> GlobalManager::getMapCellEdgeByDirection(
	const ArKCa::Vector2<int> &mapCellPosition,
	ArKCa::Direction4 direction
	)
{
	ArKCa::LineSegment<float> result(
		ArKCa::Vector2<float>(0.0f, 0.0f),
		ArKCa::Vector2<float>(0.0f, 0.0f)
		);

	auto screenPosition = cocos2d::Vec2(
		mapCellPosition.x * MAPCELL_SIZE,
		-mapCellPosition.y * MAPCELL_SIZE
		);
	ArKCa::Vector2<float> position0(0.0f, 0.0f);
	ArKCa::Vector2<float> position1(0.0f, 0.0f);

	switch (direction)
	{
	case ArKCa::Direction4_None:
		break;
	case ArKCa::Direction4_Up:
		position0.set(screenPosition.x, screenPosition.y);
		position1.set(
			screenPosition.x + MAPCELL_SIZE,
			screenPosition.y
			);
		result.set(position0, position1);
		break;
	case ArKCa::Direction4_Right:
		position0.set(
			screenPosition.x + MAPCELL_SIZE,
			screenPosition.y
			);
		position1.set(
			screenPosition.x + MAPCELL_SIZE,
			screenPosition.y - MAPCELL_SIZE
			);
		result.set(position0, position1);
		break;
	case ArKCa::Direction4_Down:
		position0.set(
			screenPosition.x + MAPCELL_SIZE,
			screenPosition.y - MAPCELL_SIZE
			);
		position1.set(
			screenPosition.x,
			screenPosition.y - MAPCELL_SIZE
			);
		result.set(position0, position1);
		break;
	case ArKCa::Direction4_Left:
		position0.set(
			screenPosition.x,
			screenPosition.y - MAPCELL_SIZE
			);
		position1.set(screenPosition.x, screenPosition.y);
		result.set(position0, position1);
		break;
	default:
		break;
	}
	return result;
}