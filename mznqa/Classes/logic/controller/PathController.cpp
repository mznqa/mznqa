/*!
 * \file	Classes\logic\controller\PathController.cpp
 *
 * \brief	∂®“Â¿‡ PathController
 */

#pragma execution_character_set("utf-8")

#include "logic/controller/PathController.h"

#include "logic/controller/MapController.h"

const ArKCa::Vector2<int> PathController::invalidPosition = ArKCa::Vector2<int>(-1, -1);

PathController* PathController::Instance()
{
	static PathController instance;
	return &instance;
}

void PathController::reset()
{
	auto size = MapController::Instance()->getMap().getSize();

	originPosition = invalidPosition;
	targetPosition = invalidPosition;

	checkTable.clear();

	openList.clear();
	for (int y = 0; y < size.height; ++y)
		openList.push_back(std::vector<bool>(size.width, false));

	closeList.clear();
	for (int y = 0; y < size.height; ++y)
		closeList.push_back(std::vector<bool>(size.width, false));

	fScore.clear();
	for (int y = 0; y < size.height; ++y)
		fScore.push_back(std::vector<int>(size.width, 0));

	gScore.clear();
	for (int y = 0; y < size.height; ++y)
		gScore.push_back(std::vector<int>(size.width, 0));

	edgeForm.clear();
	for (int y = 0; y < size.height; ++y)
		edgeForm.push_back(std::vector<ArKCa::Vector2<int>>(size.width, invalidPosition));

	path.clear();
}

void PathController::ready(
	const ArKCa::Vector2<int> &startPosition,
	const ArKCa::Vector2<int> &goalPosition
	)
{
	reset();
	originPosition = startPosition;
	targetPosition = goalPosition;
	insertCheckPoint(originPosition);
	openList[originPosition.y][originPosition.x] = true;
	closeList[originPosition.y][originPosition.x] = false;
	gScore[originPosition.y][originPosition.x] = 0;
	fScore[originPosition.y][originPosition.x] =
		gScore[originPosition.y][originPosition.x] +
		getDist(originPosition, targetPosition);
	state = State_Ready;
}

void PathController::insertCheckPoint(const ArKCa::Vector2<int> &position)
{
	if (checkTable.size() > 1)
	{
		auto it = checkTable.begin();
		auto itEnd = checkTable.end();
		while (it != itEnd)
		{
			if (fScore[position.y][position.x] <= fScore[it->y][it->x])
			{
				checkTable.insert(it, position);
				return;
			}
			++it;
		}
		checkTable.push_back(position);
	}
	else if (checkTable.size() == 1)
	{
		if (fScore[checkTable.front().y][checkTable.front().x] < fScore[position.y][position.x])
			checkTable.push_back(position);
		else
			checkTable.push_front(position);
	}
	else if (checkTable.size() == 0)
		checkTable.push_back(position);
}

void PathController::updateCheckPoint(const ArKCa::Vector2<int> &position)
{
	auto it = checkTable.begin();
	auto itEnd = checkTable.end();
	while (it != itEnd)
	{
		if (*it == position)
		{
			checkTable.erase(it);
			insertCheckPoint(position);
			return;
		}

		++it;
	}
}
void PathController::planning()
{
	if (state == State_Ready)
		state = State_Working;

	if (state != State_Working)
		return;

	if (!checkTable.empty())
	{
		auto start = checkTable.front();
		checkTable.erase(checkTable.cbegin());

		if (start == targetPosition)
		{
			state = State_Done;
			generatePath();
			return;
		}

		openList[start.y][start.x] = false;
		closeList[start.y][start.x] = true;

		auto adj = MapController::Instance()->getMap().getCanThroughNearPosition(start);
		auto it = adj.cbegin();
		auto itEnd = adj.cend();
		for (; it != itEnd; ++it)
		{
			if (closeList[it->y][it->x] == true)
				continue;
			int gScoreTemp = gScore[start.y][start.x] + 1;
			int fScoreTemp = gScoreTemp + getDist(*it, targetPosition);

			edgeForm[it->y][it->x] = start;
			if (openList[it->y][it->x] == false)
			{
				openList[it->y][it->x] = true;
				insertCheckPoint(*it);
			}
			else if (fScoreTemp < fScore[it->y][it->x])
			{
				gScore[it->y][it->x] = gScoreTemp;
				fScore[it->y][it->x] = fScoreTemp;
				updateCheckPoint(*it);
			}
		}
	}
}

void PathController::generatePath()
{
	ArKCa::Vector2<int> temp = targetPosition;
	while (temp != originPosition)
	{
		path.push_front(temp);
		temp = edgeForm[temp.y][temp.x];
		if (temp == invalidPosition)
			break;
	}
	path.push_front(originPosition);
}

ArKCa::Vector2<int> PathController::getNextStepByCurrentPosition(const ArKCa::Vector2<int> &currentPosition)
{
	ArKCa::Vector2<int> result = invalidPosition;
	auto it = path.cbegin();
	auto itEnd = path.cend();
	while (it != itEnd)
	{
		if (*it == currentPosition)
		{
			++it;
			if (it == itEnd)
				path.clear();
			else
			{
				result = *it;
				path.erase(path.cbegin(), it);
			}
			return result;
		}
		++it;
	}
	return result;
}