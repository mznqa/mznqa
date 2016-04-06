/*!
 * \file	Classes\map\MapNode.h
 *
 * \brief	定义类 MapNode
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MAP_MAPNODE_H_
#define MZNQA_CLASSES_MAP_MAPNODE_H_

/*!
 * \struct	MapNode
 *
 * \brief	地图的最小单元：地图节点
 *
 */
struct MapNode
{
	/*!
	 * \enum	NodeStyle
	 *
	 * \brief	该节点的风格（地貌）
	 */
	enum NodeStyle
	{
		NodeStyle_None = 0,	///< 无风格
		NodeStyle_Meadow	///< 草地
	};

	/*!
	 * \enum	RoadType
	 *
	 * \brief	道路类型
	 */
	enum RoadType
	{
		RoadType_None = 0,		///< 无道路
		RoadType_URDL = 1234,	///< 四方向道路
		RoadType_RDL = 234,		///< 三方向道路
		RoadType_UDL = 134,		///< 三方向道路
		RoadType_URL = 124,		///< 三方向道路
		RoadType_URD = 123,		///< 三方向道路
		RoadType_DL = 34,		///< 双方向道路
		RoadType_UL = 14,		///< 双方向道路
		RoadType_UR = 12,		///< 双方向道路
		RoadType_RL = 24,		///< 双方向道路
		RoadType_UD = 13,		///< 双方向道路
		RoadType_RD = 23,		///< 双方向道路
		RoadType_U = 1,			///< 单方向道路
		RoadType_R = 2,			///< 单方向道路
		RoadType_D = 3,			///< 单方向道路
		RoadType_L = 4			///< 单方向道路
	};

	/*! \brief	地图横向节点总个数 */
	static const int mapNodecountHorizontal = 640;
	/*! \brief	地图纵向节点总个数 */
	static const int mapNodecountVertical = 360;
	/*! \brief	标识无效的节点索引 */
	static const int invalidIndex = -1;
	/*! \brief	指向该图节点的索引 */
	const int index;
	/*! \brief	地图节点的横坐标 */
	const int x;
	/*! \brief	地图节点的纵坐标 */
	const int y;
	/*! \brief	标识地图节点是否已知 */
	bool known;
	/*! \brief	地图节点的道路类型 */
	RoadType roadType;
	/*! \brief	地图节点的风格 */
	NodeStyle nodeStyle;

	/*!
	 * \fn	MapNode ( int index, int x, int y, bool known, RoadType roadType, NodeStyle nodeStyle )
	 *
	 * \brief	构造函数
	 *
	 * \param	index	 	指定地图节点的索引
	 * \param	x		 	指定地图节点的横坐标
	 * \param	y		 	指定地图节点的纵坐标
	 * \param	known	 	指定地图节点是否已知
	 * \param	roadType 	指定地图节点的道路类型
	 * \param	nodeStyle	指定地图节点的风格
	 */
	MapNode
		(
		int index,
		int x,
		int y,
		bool known,
		RoadType roadType,
		NodeStyle nodeStyle
		) :
		index(index),
		x(x),
		y(y),
		known(known),
		roadType(roadType),
		nodeStyle(nodeStyle)
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
		roadType(mapNode.roadType),
		nodeStyle(mapNode.nodeStyle)

	{
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
		return 0 <= x && x < mapNodecountHorizontal;
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
		return 0 <= y && y < mapNodecountVertical;
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
			0 <= x && x < mapNodecountHorizontal &&
			0 <= y && y < mapNodecountVertical
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
			0 <= x && x < mapNodecountHorizontal &&
			0 <= y && y < mapNodecountVertical
			)
			return x + y * mapNodecountHorizontal;
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
		if (x + 1 >= mapNodecountHorizontal)
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
		if (y + 1 >= mapNodecountVertical)
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
