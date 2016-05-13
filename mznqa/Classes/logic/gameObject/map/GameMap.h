/*!
 * \file	Classes\logic\gameObject\map\GameMap.h
 *
 * \brief	定义类 GameMap
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_MAP_GAMEMAP_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_MAP_GAMEMAP_H_

#include <map>

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
	std::map<int, MapNode> nodeSet;
public:

	/*!
	 * \fn	GameMap::GameMap()
	 *
	 * \brief	默认构造函数，创建一个空的地图
	 *
	 */
	GameMap()
	{
	}

	/*!
	 * \fn	GameMap::GameMap(std::map<int, MapNode> &mapNodeSet);
	 *
	 * \brief	构造函数，指定存放地图数据容器以创建地图
	 *
	 * \param	mapNodeSet	指定存放所有地图节点的容器
	 */
	GameMap(std::map<int, MapNode> &mapNodeSet);

	/*!
	 * \fn	GameMap::GameMap(const GameMap &gameMap);
	 *
	 * \brief	拷贝构造函数
	 *
	 */
	GameMap(const GameMap &gameMap);

	/*!
	 * \fn	GameMap& GameMap::operator=(const GameMap &gameMap);
	 *
	 * \brief	拷贝赋值运算符
	 *
	 */
	GameMap& operator=(const GameMap &gameMap);

	/*!
	 * \fn	GameMap::~GameMap()
	 *
	 * \brief	析构函数
	 *
	 */
	~GameMap()
	{
	}

	/*!
	 * \fn	void GameMap::loadMapNode(std::map<int, MapNode> &mapNodeSet);
	 *
	 * \brief	载入地图节点
	 *
	 * \param	mapNodeSet	指定存放所有地图节点的容器
	 */
	void loadMapNode(std::map<int, MapNode> &mapNodeSet);

	/*!
	 * \fn	const std::map<int, MapNode>& GameMap::getMapNodeSet()const;
	 *
	 * \brief	获取地图节点集合
	 *
	 */
	const std::map<int, MapNode>& getMapNodeSet()const;
};

#endif
