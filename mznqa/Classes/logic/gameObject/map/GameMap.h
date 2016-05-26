/*!
 * \file	Classes\logic\gameObject\map\GameMap.h
 *
 * \brief	定义类 GameMap
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
 * \brief	地图
 *
 */
class GameMap
{
private:
	/*! \brief	尺寸信息，地图整体宽高值 */
	ArKCa::Size<int> size;
	/*! \brief	存放所有地图节点 */
	std::vector<std::vector<MapNode>> nodeSet;
public:

	/*!
	* \fn	GameMap::GameMap()
	*
	* \brief	默认构造函数，创建一个空的地图
	*
	*/
	GameMap() :
		size(0, 0)
	{
	}

	/*!
	 * \fn	GameMap::GameMap(const ArKCa::Size<int> size)
	 *
	 * \brief	构造函数，创建一个空的地图
	 *
	 * \param	size	指定地图的尺寸信息
	 */
	GameMap(const ArKCa::Size<int> size) :
		size(size)
	{
	}

	/*!
	 * \fn	GameMap::GameMap(const ArKCa::Size<int> size, std::vector<std::vector<MapNode>> &mapNodeSet);
	 *
	 * \brief	构造函数，指定存放地图数据容器以创建地图
	 *
	 * \param	size		指定地图的尺寸信息
	 * \param	mapNodeSet	指定存放所有地图节点的容器
	 */
	GameMap(const ArKCa::Size<int> size, std::vector<std::vector<MapNode>> &mapNodeSet);

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
	 * \fn	bool GameMap::checkPosition(const ArKCa::Vector2<int> &position)
	 *
	 * \brief	检查坐标是否合法
	 *
	 * \param	position	指定坐标
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
	 * \brief	载入地图节点
	 *
	 * \param	size		指定地图的尺寸信息
	 * \param	mapNodeSet	指定存放所有地图节点的容器
	 */
	void loadMapNode(const ArKCa::Size<int> size, std::vector<std::vector<MapNode>> &mapNodeSet);

	/*!
	 * \fn	const std::vector<std::vector<MapNode> >& GameMap::getMapNodeSet()const;
	 *
	 * \brief	获取地图节点集合
	 *
	 */
	const std::vector<std::vector<MapNode> >& getMapNodeSet()const;

	/*!
	 * \fn	void GameMap::clear();
	 *
	 * \brief	清空地图
	 *
	 */
	void clear();

	/*!
	 * \fn	const ArKCa::Size<int>& GameMap::getSize()const;
	 *
	 * \brief	获取地图的尺寸信息
	 *
	 */
	const ArKCa::Size<int>& getSize()const;

	/*!
	 * \fn	const MapNode *const GameMap::getMapNode(const ArKCa::Vector2<int> &position)const
	 *
	 * \brief	获取地图节点
	 *
	 * \param	position	指定地图节点的位置
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
	 * \brief	修改地图节点的节点类型
	 *
	 * \param	position	指定待修改的节点的位置
	 * \param	nodeType	指定新的节点类型
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
	 * \brief	获取给定点的可通过邻接点
	 *
	 * \param	position	指定地图上的点
	 *
	 */
	std::vector<ArKCa::Vector2<int> > getCanThroughNearPosition(const ArKCa::Vector2<int> &position)const;

	/*!
	 * \fn	bool GameMap::getNeighborCanThrough(const ArKCa::Vector2<int> &position, ArKCa::Direction4 direction);
	 *
	 * \brief	获取临界点的是否可以通过
	 *
	 * \param	position 	指定地图坐标
	 * \param	direction	指定方向
	 *
	 */
	bool getNeighborCanThrough(const ArKCa::Vector2<int> &position, ArKCa::Direction4 direction);
};

#endif
