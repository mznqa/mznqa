/*!
 * \file	Classes\logic\gameObject\map\MapNode.h
 *
 * \brief	定义结构体 MapNode
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_MAP_MAPNODE_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_MAP_MAPNODE_H_

/*!
 * \struct	MapNode
 *
 * \brief	地图节点
 *
 */
struct MapNode
{
	/*!
	 * \enum	NodeType
	 *
	 * \brief	枚举节点类型
	 */
	enum NodeType
	{
		NodeType_None = 0,
		NodeType_Road = 1,
		NodeType_Wall = 2,

		NodeType_None_Const = 100,
		NodeType_Road_Const = 101,
		NodeType_Wall_Const = 102
	};

	/*!
	 * \enum	ExtraType
	 *
	 * \brief	枚举附加物类型
	 */
	enum ExtraType
	{
		ExtraType_None
	};

	/*! \brief	标识无效的地图节点ID */
	static const int mapNodeInvalidID = -1;

	/*! \brief	节点ID */
	int id;
	/*! \brief	节点横坐标 */
	int x;
	/*! \brief	节点纵坐标 */
	int y;
	/*! \brief	节点类型 */
	NodeType nodeType;
	/*! \brief	附加物类型 */
	ExtraType extraType;
	/*! \brief	节点可见性 */
	bool nodeVisible;
	/*! \brief	附加物可见性 */
	bool extraVisible;
	/*! \brief	上邻接节点ID */
	int adjacencyUp;
	/*! \brief	右邻接节点ID */
	int adjacencyRight;
	/*! \brief	下邻接节点ID */
	int adjacencyDown;
	/*! \brief	左邻接节点ID */
	int adjacencyLeft;

	/*!
	 * \fn	MapNode( int id, int x, int y, NodeType nodeType, ExtraType extraType, bool nodeVisible, bool extraVisible, int adjacencyUp, int adjacencyRight, int adjacencyDown, int adjacencyLeft )
	 *
	 * \brief	构造函数
	 *
	 * \param	id				指定节点ID
	 * \param	x				指定节点横坐标
	 * \param	y				指定节点纵坐标
	 * \param	nodeType		指定节点类型
	 * \param	extraType   	指定节点附加物类型
	 * \param	nodeVisible 	指定节点可见性
	 * \param	extraVisible	指定节点附加物可见性
	 * \param	adjacencyUp   	指定上方向邻接点ID
	 * \param	adjacencyRight	指定右方向邻接点ID
	 * \param	adjacencyDown 	指定下方向邻接点ID
	 * \param	adjacencyLeft 	指定左方向邻接点ID
	 */
	MapNode(
		int id,
		int x,
		int y,
		NodeType nodeType,
		ExtraType extraType,
		bool nodeVisible,
		bool extraVisible,
		int adjacencyUp,
		int adjacencyRight,
		int adjacencyDown,
		int adjacencyLeft
		) :
		id(id),
		x(x),
		y(y),
		nodeType(nodeType),
		extraType(extraType),
		nodeVisible(nodeVisible),
		extraVisible(extraVisible),
		adjacencyUp(adjacencyUp),
		adjacencyRight(adjacencyRight),
		adjacencyDown(adjacencyDown),
		adjacencyLeft(adjacencyLeft)
	{
	}

	/*!
	 * \fn	MapNode(const MapNode &mapNode)
	 *
	 * \brief	拷贝构造函数
	 *
	 */
	MapNode(const MapNode &mapNode) :
		id(mapNode.id),
		x(mapNode.x),
		y(mapNode.y),
		nodeType(mapNode.nodeType),
		extraType(mapNode.extraType),
		nodeVisible(mapNode.nodeVisible),
		extraVisible(mapNode.extraVisible),
		adjacencyUp(mapNode.adjacencyUp),
		adjacencyRight(mapNode.adjacencyRight),
		adjacencyDown(mapNode.adjacencyDown),
		adjacencyLeft(mapNode.adjacencyLeft)
	{
	}

	/*!
	 * \fn	MapNode& operator=(const MapNode &mapNode)
	 *
	 * \brief	拷贝赋值运算符
	 *
	 */
	MapNode& operator=(const MapNode &mapNode)
	{
		this->id = mapNode.id;
		this->x = mapNode.x;
		this->y = mapNode.y;
		this->nodeType = mapNode.nodeType;
		this->extraType = mapNode.extraType;
		this->nodeVisible = mapNode.nodeVisible;
		this->extraVisible = mapNode.extraVisible;
		this->adjacencyUp = mapNode.adjacencyUp;
		this->adjacencyRight = mapNode.adjacencyRight;
		this->adjacencyDown = mapNode.adjacencyDown;
		this->adjacencyLeft = mapNode.adjacencyLeft;
		return *this;
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
};

#endif
