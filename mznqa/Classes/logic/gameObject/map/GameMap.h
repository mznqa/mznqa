/*!
 * \file	Classes\logic\gameObject\map\GameMap.h
 *
 * \brief	������ GameMap
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_MAP_GAMEMAP_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_MAP_GAMEMAP_H_

#include <map>

#include "common/arkca/Size.h"

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
	/*! \brief	�ߴ���Ϣ����ͼ������ֵ */
	ArKCa::Size<int> size;
	/*! \brief	������е�ͼ�ڵ� */
	std::map<int, MapNode> nodeSet;
public:

	/*!
	 * \fn	GameMap::GameMap(const ArKCa::Size<int> size)
	 *
	 * \brief	Ĭ�Ϲ��캯��������һ���յĵ�ͼ
	 *
	 * \param	size	ָ����ͼ�ĳߴ���Ϣ
	 */
	GameMap(const ArKCa::Size<int> size) :
		size(size)
	{
	}

	/*!
	 * \fn	GameMap::GameMap(const ArKCa::Size<int> size, std::map<int, MapNode> &mapNodeSet);
	 *
	 * \brief	���캯����ָ����ŵ�ͼ���������Դ�����ͼ
	 *
	 * \param	size		ָ����ͼ�ĳߴ���Ϣ
	 * \param	mapNodeSet	ָ��������е�ͼ�ڵ������
	 */
	GameMap(const ArKCa::Size<int> size, std::map<int, MapNode> &mapNodeSet);

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
	 * \fn	void GameMap::loadMapNode(const ArKCa::Size<int> size, std::map<int, MapNode> &mapNodeSet);
	 *
	 * \brief	�����ͼ�ڵ�
	 *
	 * \param	size		ָ����ͼ�ĳߴ���Ϣ
	 * \param	mapNodeSet	ָ��������е�ͼ�ڵ������
	 */
	void loadMapNode(const ArKCa::Size<int> size, std::map<int, MapNode> &mapNodeSet);

	/*!
	 * \fn	const std::map<int, MapNode>& GameMap::getMapNodeSet()const;
	 *
	 * \brief	��ȡ��ͼ�ڵ㼯��
	 *
	 */
	const std::map<int, MapNode>& getMapNodeSet()const;

	/*!
	 * \fn	void GameMap::clear();
	 *
	 * \brief	��յ�ͼ
	 *
	 */
	void clear();

	/*!
	 * \fn	const ArKCa::Size<int>& GameMap::getSize()const;
	 *
	 * \brief	��ȡ��ͼ�ĳߴ���Ϣ
	 *
	 */
	const ArKCa::Size<int>& getSize()const;
};

#endif
