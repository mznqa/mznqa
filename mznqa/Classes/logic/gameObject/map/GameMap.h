/*!
 * \file	Classes\logic\gameObject\map\GameMap.h
 *
 * \brief	������ GameMap
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_MAP_GAMEMAP_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_MAP_GAMEMAP_H_

#include <map>

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
	std::map<int, MapNode> nodeSet;
public:

	/*!
	 * \fn	GameMap::GameMap()
	 *
	 * \brief	Ĭ�Ϲ��캯��������һ���յĵ�ͼ
	 *
	 */
	GameMap()
	{
	}

	/*!
	 * \fn	GameMap::GameMap(std::map<int, MapNode> &mapNodeSet);
	 *
	 * \brief	���캯����ָ����ŵ�ͼ���������Դ�����ͼ
	 *
	 * \param	mapNodeSet	ָ��������е�ͼ�ڵ������
	 */
	GameMap(std::map<int, MapNode> &mapNodeSet);

	/*!
	 * \fn	GameMap::GameMap(const GameMap &gameMap);
	 *
	 * \brief	�������캯��
	 *
	 */
	GameMap(const GameMap &gameMap);

	/*!
	 * \fn	GameMap& GameMap::operator=(const GameMap &gameMap);
	 *
	 * \brief	������ֵ�����
	 *
	 */
	GameMap& operator=(const GameMap &gameMap);

	/*!
	 * \fn	GameMap::~GameMap()
	 *
	 * \brief	��������
	 *
	 */
	~GameMap()
	{
	}

	/*!
	 * \fn	void GameMap::loadMapNode(std::map<int, MapNode> &mapNodeSet);
	 *
	 * \brief	�����ͼ�ڵ�
	 *
	 * \param	mapNodeSet	ָ��������е�ͼ�ڵ������
	 */
	void loadMapNode(std::map<int, MapNode> &mapNodeSet);

	/*!
	 * \fn	const std::map<int, MapNode>& GameMap::getMapNodeSet()const;
	 *
	 * \brief	��ȡ��ͼ�ڵ㼯��
	 *
	 */
	const std::map<int, MapNode>& getMapNodeSet()const;
};

#endif
