/*!
 * \file	Classes\logic\gameObject\map\MapView.cpp
 *
 * \brief	∂®“Â¿‡ MapView
 */

#pragma execution_character_set("utf-8")

#include "logic/gameObject/map/MapView.h"

#include "logic/data/info/NumDefine.h"

std::vector<ArKCa::Vector2<int>> MapView::getMapGroupPositionSet(const ArKCa::Vector2<int> &position)
{
	if (
		origin.x <= position.x &&
		position.x <= origin.x + size.width &&
		origin.y <= position.y &&
		position.y <= origin.y + size.height)
	{
		ArKCa::Vector2<int> basePostion = (position - origin) / MAPNODE_GROUPSIZE;
		std::vector<ArKCa::Vector2<int>> idSet;
		for (int y = 0; y < MAPNODE_GROUPSIZE; ++y)
			for (int x = 0; x < MAPNODE_GROUPSIZE; ++x)
				idSet.push_back(basePostion + ArKCa::Vector2<int>(x, y));
		return idSet;
	}
}