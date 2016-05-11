/*!
 * \file	Classes\logic\gameObject\map\GameMap.h
 *
 * \brief	������ GameMap
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_MAP_GAMEMAP_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_MAP_GAMEMAP_H_

#include <vector>

#include "logic/gameObject/map/MapNode.h"

/*!
 * \class	GameMap
 *
 * \brief	��ͼ
 *
 */
class GameMap
{
private:
	/*! \brief	������е�ͼ�ڵ� */
	std::vector<MapNode> nodeSet;
	/*! \brief	��֯ͼ�ṹ */
	std::vector<std::vector<MapNode*>> graph;
public:

	/*!
	 * \fn	GameMap::GameMap(const std::vector<MapNode> &nodeSet, const std::vector<std::vector<MapNode*>> &graph)
	 *
	 * \brief	���캯��
	 *
	 * \param	nodeSet	ָ�����е�ͼ�ڵ�
	 * \param	graph  	ָ��ͼ�ṹ
	 */
	GameMap(const std::vector<MapNode> &nodeSet, const std::vector<std::vector<MapNode*>> &graph) :
		nodeSet(nodeSet),
		graph(graph)
	{
	}

	/*!
	 * \fn	GameMap::GameMap(const GameMap &gameMap)
	 *
	 * \brief	�������캯��
	 *
	 */
	GameMap(const GameMap &gameMap)
	{
	}

	/*!
	 * \fn	GameMap& GameMap::operator=(const GameMap &gameMap)
	 *
	 * \brief	������ֵ�����
	 *
	 */
	GameMap& operator=(const GameMap &gameMap)
	{
	}

	/*!
	 * \fn	GameMap::~GameMap()
	 *
	 * \brief	��������
	 *
	 */
	~GameMap()
	{
	}
};

#endif
