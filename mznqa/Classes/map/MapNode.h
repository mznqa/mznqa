/*!
 * \file	Classes\map\MapNode.h
 *
 * \brief	定义类 MapNode
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MAP_MAPNODE_H_
#define MZNQA_CLASSES_MAP_MAPNODE_H_

#include "map/MapController.h"

#include "card/CardBase.h"

/*!
 * \struct	MapNode
 *
 * \brief	地图的最小单元：地图节点
 *
 */
struct MapNode
{
	/*!
	 * \enum	NodeType
	 *
	 * \brief	节点类型
	 */
	enum NodeType
	{
		NodeType_None = 0,		///< 无特定类型
		NodeType_Wall = 1,		///< 墙
		NodeType_Road = 2,		///< 道路
		NodeType_Door = 3,		///< 门（入口）
		NodeType_Exit = 4		///< 出口
	};

	/*! \brief	标识无效的节点索引 */
	static const int invalidIndex = -1;
	/*! \brief	标志无效的横纵坐标值 */
	static const int invalidXOrY = -1;
	/*! \brief	指向该图节点的索引 */
	int index;
	/*! \brief	地图节点的横坐标 */
	int x;
	/*! \brief	地图节点的纵坐标 */
	int y;
	/*! \brief	标识地图节点是否已知 */
	bool known;
	/*! \brief	节点类型 */
	NodeType nodeType;
	/*! \brief	附加的卡牌id */
	int extraCardID;

	/*!
	 * \fn	MapNode() : index(invalidIndex), x(invalidXOrY), y(invalidXOrY), known(false), nodeType(NodeType_None), extraCardID(CardBase::invalidID)
	 *
	 * \brief	默认构造函数，将构造一个无意义的地图节点
	 *
	 */
	MapNode() :
		index(invalidIndex),
		x(invalidXOrY),
		y(invalidXOrY),
		known(false),
		nodeType(NodeType_None),
		extraCardID(CardBase::invalidID)
	{
	}

	/*!
	 * \fn	MapNode ( int index, int x, int y, bool known, NodeType nodeType, int extraCardID)
	 *
	 * \brief	构造函数
	 *
	 * \param	index	 	指定地图节点的索引
	 * \param	x		 	指定地图节点的横坐标
	 * \param	y		 	指定地图节点的纵坐标
	 * \param	known	 	指定地图节点是否已知
	 * \param	nodeType 	指定地图节点的类型
	 * \param	extraCardID	指定地图节点的附加卡牌id
	 */
	MapNode
		(
		int index,
		int x,
		int y,
		bool known,
		NodeType nodeType,
		int extraCardID
		) :
		index(index),
		x(x),
		y(y),
		known(known),
		nodeType(nodeType),
		extraCardID(extraCardID)
	{
	}

	/*!
	 * \fn	MapNode(const MapNode &mapNode)
	 *
	 * \brief	拷贝构造函数
	 *
	 * \param	mapNode	MapNode 实例
	 */
	MapNode(const MapNode &mapNode) :
		index(mapNode.index),
		x(mapNode.x),
		y(mapNode.y),
		known(mapNode.known),
		nodeType(mapNode.nodeType),
		extraCardID(mapNode.extraCardID)
	{
	}

	/*!
	* \fn	MapNode& operator=(const MapNode &mapNode);
	*
	* \brief	赋值运算符
	*
	* \param	mapNode	MapNode 实例
	*
	* \return	MapNode 实例
	*/
	MapNode& operator=(const MapNode &mapNode)
	{
		this->index = mapNode.index;
		this->x = mapNode.x;
		this->y = mapNode.y;
		this->known = mapNode.known;
		this->nodeType = mapNode.nodeType;
		this->extraCardID = mapNode.extraCardID;
		return *this;
	}

	/*!
	 * \fn	void copyIncomplete(const MapNode &mapNode)
	 *
	 * \brief	从一个 MapNode 实例中拷贝 known , nodeType , extraCardID 属性
	 *
	 * \param	mapNode	MapNode 实例
	 */
	void copyIncomplete(const MapNode &mapNode)
	{
		this->known = mapNode.known;
		this->nodeType = mapNode.nodeType;
		this->extraCardID = mapNode.extraCardID;
	}

	/*!
	 * \fn	~MapNode()
	 *
	 * \brief	析构函数
	 *
	 */
	~MapNode()
	{
	}

	/*!
	 * \fn	static bool checkX(int x)
	 *
	 * \brief	检查给定的横坐标是否合法
	 *
	 * \param	x	指定待检查的横坐标值
	 *
	 * \return	返回给定的横坐标值是否合法
	 */
	static bool checkX(int x)
	{
		return 0 <= x && x < MapController::mapNodecountHorizontal;
	}

	/*!
	 * \fn	static bool checkY(int y)
	 *
	 * \brief	检查给定的纵坐标值是否合法
	 *
	 * \param	y	指定待检查的纵坐标值
	 *
	 * \return	返回给定的纵坐标值是否合法
	 */
	static bool checkY(int y)
	{
		return 0 <= y && y < MapController::mapNodecountVertical;
	}

	/*!
	 * \fn	static bool checkXY(int x, int y)
	 *
	 * \brief	检查给定的横纵坐标值是否合法
	 *
	 * \param	x	指定待检查的横坐标值
	 * \param	y	指定带检查的纵坐标值
	 *
	 * \return	返回给定的横纵坐标值是否合法
	 */
	static bool checkXY(int x, int y)
	{
		return (
			0 <= x && x < MapController::mapNodecountHorizontal &&
			0 <= y && y < MapController::mapNodecountVertical
			);
	}

	/*!
	 * \fn	static int getIndexByXY(int x, int y)
	 *
	 * \brief	获取给定的横纵坐标对应的地图节点索引
	 *
	 * \param	x	指定横坐标值
	 * \param	y	指定纵坐标值
	 *
	 * \return	返回给定的横纵坐标对应的地图节点的索引
	 */
	static int getIndexByXY(int x, int y)
	{
		if (
			0 <= x && x < MapController::mapNodecountHorizontal &&
			0 <= y && y < MapController::mapNodecountVertical
			)
			return x + y * MapController::mapNodecountHorizontal;
		else
			return invalidIndex;
	}

	/*!
	 * \fn	int getUpIndex()const
	 *
	 * \brief	获取当前节点上方的节点的索引
	 *
	 * \return	返回当前节点上方的节点的索引
	 */
	int getUpIndex()const
	{
		return getIndexByXY(getUpX(), getUpY());
	}

	/*!
	 * \fn	int getUpX()const
	 *
	 * \brief	获取当前节点上方的节点的横坐标
	 *
	 * \return	返回当前节点上方的节点的横坐标
	 */
	int getUpX()const
	{
		return x;
	}

	/*!
	 * \fn	int getUpY()const
	 *
	 * \brief	获取当前节点上方的节点的纵坐标
	 *
	 * \return	返回当前节点上方的节点的纵坐标
	 */
	int getUpY()const
	{
		if (y - 1 < 0)
			return invalidIndex;
		else
			return y - 1;
	}

	/*!
	 * \fn	int getRightIndex()const
	 *
	 * \brief	获取当前节点右方的节点的索引
	 *
	 * \return	返回当前节点右方的节点的索引
	 */
	int getRightIndex()const
	{
		return getIndexByXY(getRightX(), getRightY());
	}

	/*!
	 * \fn	int getRightX()const
	 *
	 * \brief	获取当前节点右方的节点的横坐标
	 *
	 * \return	返回当前节点右方的节点的横坐标
	 */
	int getRightX()const
	{
		if (x + 1 >= MapController::mapNodecountHorizontal)
			return invalidIndex;
		else
			return x + 1;
	}

	/*!
	 * \fn	int getRightY()const
	 *
	 * \brief	获取当前节点右方的节点的纵坐标
	 *
	 * \return	返回当前节点右方的节点的纵坐标
	 */
	int getRightY()const
	{
		return y;
	}

	/*!
	 * \fn	int getDownIndex()const
	 *
	 * \brief	获取当前节点下方的节点的索引
	 *
	 * \return	返回当前节点下方的节点的索引
	 */
	int getDownIndex()const
	{
		return getIndexByXY(getDownX(), getDownY());
	}

	/*!
	 * \fn	int getDownX()const
	 *
	 * \brief	获取当前节点下方的节点的横坐标
	 *
	 * \return	获取当前节点下方的节点的横坐标
	 */
	int getDownX()const
	{
		return x;
	}

	/*!
	 * \fn	int getDownY()const
	 *
	 * \brief	获取当前节点下方的节点的纵坐标
	 *
	 * \return	返回当前节点下方的节点的纵坐标
	 */
	int getDownY()const
	{
		if (y + 1 >= MapController::mapNodecountVertical)
			return invalidIndex;
		else
			return y + 1;
	}

	/*!
	 * \fn	int getLeftIndex()const
	 *
	 * \brief	获取当前节点左方的节点的索引
	 *
	 * \return	返回当前节点左方的节点的索引
	 */
	int getLeftIndex()const
	{
		return getIndexByXY(getLeftX(), getLeftY());
	}

	/*!
	 * \fn	int getLeftX()const
	 *
	 * \brief	获取当前节点左方的节点的横坐标
	 *
	 * \return	返回当前节点左方的节点的横坐标
	 */
	int getLeftX()const
	{
		if (x - 1 < 0)
			return invalidIndex;
		else
			return x - 1;
	}

	/*!
	 * \fn	int getLeftY()const
	 *
	 * \brief	获取当前节点左方的节点的纵坐标
	 *
	 * \return	返回当前节点左方的节点的纵坐标
	 */
	int getLeftY()const
	{
		return y;
	}
};

#endif
