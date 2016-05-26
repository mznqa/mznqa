/*!
 * \file	Classes\logic\gameObject\map\GameMap.h
 *
 * \brief	������ GameMap
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_MAP_GAMEMAP_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_MAP_GAMEMAP_H_

#include <vector>

#include "common/arkca/Size.h"
#include "common/arkca/Direction.h"

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
	std::vector<std::vector<MapNode>> nodeSet;
public:

	/*!
	* \fn	GameMap::GameMap()
	*
	* \brief	Ĭ�Ϲ��캯��������һ���յĵ�ͼ
	*
	*/
	GameMap() :
		size(0, 0)
	{
	}

	/*!
	 * \fn	GameMap::GameMap(const ArKCa::Size<int> size)
	 *
	 * \brief	���캯��������һ���յĵ�ͼ
	 *
	 * \param	size	ָ����ͼ�ĳߴ���Ϣ
	 */
	GameMap(const ArKCa::Size<int> size) :
		size(size)
	{
	}

	/*!
	 * \fn	GameMap::GameMap(const ArKCa::Size<int> size, std::vector<std::vector<MapNode>> &mapNodeSet);
	 *
	 * \brief	���캯����ָ����ŵ�ͼ���������Դ�����ͼ
	 *
	 * \param	size		ָ����ͼ�ĳߴ���Ϣ
	 * \param	mapNodeSet	ָ��������е�ͼ�ڵ������
	 */
	GameMap(const ArKCa::Size<int> size, std::vector<std::vector<MapNode>> &mapNodeSet);

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
	 * \fn	bool GameMap::checkPosition(const ArKCa::Vector2<int> &position)
	 *
	 * \brief	��������Ƿ�Ϸ�
	 *
	 * \param	position	ָ������
	 *
	 */
	bool checkPosition(const ArKCa::Vector2<int> &position)
	{
		return (
			0 <= position.x && position.x < size.width &&
			0 <= position.y && position.y < size.height
			);
	}

	/*!
	 * \fn	void GameMap::loadMapNode(const ArKCa::Size<int> size, std::vector<std::vector<MapNode>> &mapNodeSet);
	 *
	 * \brief	�����ͼ�ڵ�
	 *
	 * \param	size		ָ����ͼ�ĳߴ���Ϣ
	 * \param	mapNodeSet	ָ��������е�ͼ�ڵ������
	 */
	void loadMapNode(const ArKCa::Size<int> size, std::vector<std::vector<MapNode>> &mapNodeSet);

	/*!
	 * \fn	const std::vector<std::vector<MapNode> >& GameMap::getMapNodeSet()const;
	 *
	 * \brief	��ȡ��ͼ�ڵ㼯��
	 *
	 */
	const std::vector<std::vector<MapNode> >& getMapNodeSet()const;

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

	/*!
	 * \fn	const MapNode *const GameMap::getMapNode(const ArKCa::Vector2<int> &position)const
	 *
	 * \brief	��ȡ��ͼ�ڵ�
	 *
	 * \param	position	ָ����ͼ�ڵ��λ��
	 *
	 */
	const MapNode *const getMapNode(const ArKCa::Vector2<int> &position)const
	{
		if (
			0 <= position.x && position.x < size.width &&
			0 <= position.y && position.y < size.height
			)
		{
			return &(nodeSet[position.y][position.x]);
		}
		else
			return nullptr;
	}

	/*!
	 * \fn	void GameMap::modifyMapNodeType(const ArKCa::Vector2<int> &position, MapNode::NodeType nodeType)
	 *
	 * \brief	�޸ĵ�ͼ�ڵ�Ľڵ�����
	 *
	 * \param	position	ָ�����޸ĵĽڵ��λ��
	 * \param	nodeType	ָ���µĽڵ�����
	 */
	void modifyMapNodeType(const ArKCa::Vector2<int> &position, MapNode::NodeType nodeType)
	{
		if (
			0 <= position.x && position.x < size.width &&
			0 <= position.y && position.y < size.height
			)
		{
			nodeSet[position.y][position.x].nodeType = nodeType;
		}
	};

	/*!
	 * \fn	std::vector<ArKCa::Vector2<int> > GameMap::getCanThroughNearPosition(const ArKCa::Vector2<int> &position)const;
	 *
	 * \brief	��ȡ������Ŀ�ͨ���ڽӵ�
	 *
	 * \param	position	ָ����ͼ�ϵĵ�
	 *
	 */
	std::vector<ArKCa::Vector2<int> > getCanThroughNearPosition(const ArKCa::Vector2<int> &position)const;

	/*!
	 * \fn	bool GameMap::getNeighborCanThrough(const ArKCa::Vector2<int> &position, ArKCa::Direction4 direction);
	 *
	 * \brief	��ȡ�ٽ����Ƿ����ͨ��
	 *
	 * \param	position 	ָ����ͼ����
	 * \param	direction	ָ������
	 *
	 */
	bool getNeighborCanThrough(const ArKCa::Vector2<int> &position, ArKCa::Direction4 direction);
};

#endif
