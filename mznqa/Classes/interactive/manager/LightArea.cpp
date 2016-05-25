/*!
 * \file	Classes\interactive\manager\LightArea.cpp
 *
 * \brief	∂®“Â¿‡ LightArea
 */

#pragma execution_character_set("utf-8")

#include "interactive/manager/LightArea.h"

#include <cmath>

#include "common/arkca/Range.h"
#include "common/arkca/Ray.h"
#include "interactive/manager/GlobalManager.h"
#include "logic/controller/MapController.h"

LightArea::LightArea(
	const ArKCa::Vector2<int> &lightPosition,
	int lightScopeRadius
	) :
	lightPosition(lightPosition),
	lightScopeRadius(lightScopeRadius),
	lightScope()
{
	buildLightScope();
	buildLightBorderList();
}

void LightArea::setLightPosition(const ArKCa::Vector2<int> &lightPosition)
{
	this->lightPosition = lightPosition;
	buildLightBorderList();
}
void LightArea::setLightScopeRadius(int lightScopeRadius)
{
	this->lightScopeRadius = lightScopeRadius;
	buildLightScope();
	buildLightBorderList();
}

bool LightArea::isWithinLightScope(const ArKCa::Vector2<int> &position)
{
	auto pos = position - lightPosition;
	return (std::abs(pos.x) + std::abs(pos.y)) <= lightScopeRadius;
}

void LightArea::buildLightScope()
{
	if (lightScopeRadius <= 0)
		return;

	lightScope.clear();
	ArKCa::Vector2<int> position(0, 0);
	lightScope.push_back(position);

	for (int i = 1; i <= lightScopeRadius; ++i)
	{
		for (
			position.x = 0, position.y = -i;
			position.x <= i && position.y <= 0;
		++position.x, ++position.y
			)
			lightScope.push_back(position);
		for (
			position.x = i - 1, position.y = 1;
			position.x >= 1 && position.y <= i - 1;
		--position.x, ++position.y)
			lightScope.push_back(position);
		for (
			position.x = 0, position.y = i;
			position.x >= -i && position.y >= 0;
		--position.x, --position.y)
			lightScope.push_back(position);
		for (
			position.x = -(i - 1), position.y = -1;
			position.x <= -1 && position.y >= -(i - 1);
		++position.x, --position.y)
			lightScope.push_back(position);
	}
}

void LightArea::buildLightBorderList()
{
	lightBorderList.clear();
	ArKCa::Vector2<int> position(0, 0);
	ArKCa::LineSegment<float> lineSegment(
		ArKCa::Vector2<float>(0.0f, 0.0f),
		ArKCa::Vector2<float>(0.0f, 0.0f)
		);
	for (
		position.x = 0, position.y = -lightScopeRadius;
		position.x <= lightScopeRadius && position.y <= 0;
	++position.x, ++position.y
		)
	{
		lineSegment = GlobalManager::Instance()->getMapCellEdgeByDirection(
			position + lightPosition, ArKCa::Direction4::Direction4_Up
			);
		lightBorderList.push_back(lineSegment);
		lineSegment = GlobalManager::Instance()->getMapCellEdgeByDirection(
			position + lightPosition, ArKCa::Direction4::Direction4_Right
			);
		lightBorderList.push_back(lineSegment);
	}
	position.set(lightScopeRadius, 0);
	lineSegment = GlobalManager::Instance()->getMapCellEdgeByDirection(
		position + lightPosition, ArKCa::Direction4::Direction4_Down
		);
	lightBorderList.push_back(lineSegment);
	for (
		position.x = lightScopeRadius - 1, position.y = 1;
		position.x >= 1 && position.y <= lightScopeRadius - 1;
	--position.x, ++position.y)
	{
		lineSegment = GlobalManager::Instance()->getMapCellEdgeByDirection(
			position + lightPosition, ArKCa::Direction4::Direction4_Right
			);
		lightBorderList.push_back(lineSegment);
		lineSegment = GlobalManager::Instance()->getMapCellEdgeByDirection(
			position + lightPosition, ArKCa::Direction4::Direction4_Down
			);
		lightBorderList.push_back(lineSegment);
	}
	position.set(0, lightScopeRadius);
	lineSegment = GlobalManager::Instance()->getMapCellEdgeByDirection(
		position + lightPosition, ArKCa::Direction4::Direction4_Right
		);
	lightBorderList.push_back(lineSegment);
	for (
		position.x = 0, position.y = lightScopeRadius;
		position.x >= -lightScopeRadius && position.y >= 0;
	--position.x, --position.y)
	{
		lineSegment = GlobalManager::Instance()->getMapCellEdgeByDirection(
			position + lightPosition, ArKCa::Direction4::Direction4_Down
			);
		lightBorderList.push_back(lineSegment);
		lineSegment = GlobalManager::Instance()->getMapCellEdgeByDirection(
			position + lightPosition, ArKCa::Direction4::Direction4_Left
			);
		lightBorderList.push_back(lineSegment);
	}
	position.set(-lightScopeRadius, 0);
	lineSegment = GlobalManager::Instance()->getMapCellEdgeByDirection(
		position + lightPosition, ArKCa::Direction4::Direction4_Up
		);
	lightBorderList.push_back(lineSegment);
	for (
		position.x = -(lightScopeRadius - 1), position.y = -1;
		position.x <= -1 && position.y >= -(lightScopeRadius - 1);
	++position.x, --position.y)
	{
		lineSegment = GlobalManager::Instance()->getMapCellEdgeByDirection(
			position + lightPosition, ArKCa::Direction4::Direction4_Left
			);
		lightBorderList.push_back(lineSegment);
		lineSegment = GlobalManager::Instance()->getMapCellEdgeByDirection(
			position + lightPosition, ArKCa::Direction4::Direction4_Up
			);
		lightBorderList.push_back(lineSegment);
	}
	position.set(0, -lightScopeRadius);
	lineSegment = GlobalManager::Instance()->getMapCellEdgeByDirection(
		position + lightPosition, ArKCa::Direction4::Direction4_Left
		);
	lightBorderList.push_back(lineSegment);
}