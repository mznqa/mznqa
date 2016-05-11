/*!
 * \file	Classes\logic\gameObject\map\GameMap.h
 *
 * \brief	定义类 GameMap
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_MAP_GAMEMAP_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_MAP_GAMEMAP_H_

#include <vector>

#include "logic/gameObject/map/MapNode.h"

/*!
 * \class	GameMap
 *
 * \brief	地图
 *
 */
class GameMap
{
private:
	/*! \brief	存放所有地图节点 */
	std::vector<MapNode> nodeSet;
	/*! \brief	组织图结构 */
	std::vector<std::vector<MapNode*>> graph;
public:

	/*!
	 * \fn	GameMap::GameMap(const std::vector<MapNode> &nodeSet, const std::vector<std::vector<MapNode*>> &graph)
	 *
	 * \brief	构造函数
	 *
	 * \param	nodeSet	指定所有地图节点
	 * \param	graph  	指定图结构
	 */
	GameMap(const std::vector<MapNode> &nodeSet, const std::vector<std::vector<MapNode*>> &graph) :
		nodeSet(nodeSet),
		graph(graph)
	{
	}

	/*!
	 * \fn	GameMap::GameMap(const GameMap &gameMap)
	 *
	 * \brief	拷贝构造函数
	 *
	 */
	GameMap(const GameMap &gameMap)
	{
	}

	/*!
	 * \fn	GameMap& GameMap::operator=(const GameMap &gameMap)
	 *
	 * \brief	拷贝赋值运算符
	 *
	 */
	GameMap& operator=(const GameMap &gameMap)
	{
	}

	/*!
	 * \fn	GameMap::~GameMap()
	 *
	 * \brief	析构函数
	 *
	 */
	~GameMap()
	{
	}
};

#endif
