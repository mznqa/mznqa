#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MAP_MAPNODE_H_
#define MZNQA_CLASSES_MAP_MAPNODE_H_

struct MapNode
{
	// 节点风格
	enum NodeStyle
	{
		NodeStyle_None = 0,
		// 草地
		NodeStyle_Meadow
	};
	// 道路类型
	enum RoadType
	{
		RoadType_None = 0,
		RoadType_URDL = 1234,
		RoadType_RDL = 234,
		RoadType_UDL = 134,
		RoadType_URL = 124,
		RoadType_URD = 123,
		RoadType_DL = 34,
		RoadType_UL = 14,
		RoadType_UR = 12,
		RoadType_RL = 24,
		RoadType_UD = 13,
		RoadType_RD = 23,
		RoadType_U = 1,
		RoadType_R = 2,
		RoadType_D = 3,
		RoadType_L = 4
	};
	// 地图横向节点数
	static const int mapNodecountHorizontal = 640;
	// 地图纵向节点数
	static const int mapNodecountVertical = 360;
	// 无效索引
	static const int invalidIndex = -1;
	// 节点索引
	const int index;
	// 节点横坐标
	const int x;
	// 节点纵坐标
	const int y;
	// 节点是否已知
	bool known;
	// 节点道路类型
	RoadType roadType;
	// 节点风格
	NodeStyle nodeStyle;

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

	MapNode(const MapNode &mapNode) :
		index(mapNode.index),
		x(mapNode.x),
		y(mapNode.y),
		known(mapNode.known),
		roadType(mapNode.roadType),
		nodeStyle(mapNode.nodeStyle)

	{
	}

	~MapNode()
	{
	}

	// 检查给定横坐标是否合法
	static bool checkX(int x)
	{
		return 0 <= x && x < mapNodecountHorizontal;
	}

	// 检查给定纵坐标是否合法
	static bool checkY(int y)
	{
		return 0 <= y && y < mapNodecountVertical;
	}

	// 检查给定横纵坐标是否合法
	static bool checkXY(int x, int y)
	{
		return (
			0 <= x && x < mapNodecountHorizontal &&
			0 <= y && y < mapNodecountVertical
			);
	}

	// 根据坐标值获取对应索引
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

	// 获取当前节点上方的索引
	int getUpIndex()const
	{
		return getIndexByXY(getUpX(), getUpY());
	}
	// 获取当前节点上方的横坐标
	int getUpX()const
	{
		return x;
	}
	// 获取当前节点上方的纵坐标
	int getUpY()const
	{
		if (y - 1 < 0)
			return invalidIndex;
		else
			return y - 1;
	}

	// 获取当前节点右方的索引
	int getRightIndex()const
	{
		return getIndexByXY(getRightX(), getRightY());
	}
	// 获取当前节点右方的横坐标
	int getRightX()const
	{
		if (x + 1 >= mapNodecountHorizontal)
			return invalidIndex;
		else
			return x + 1;
	}
	// 获取当前节点右方的纵坐标
	int getRightY()const
	{
		return y;
	}

	// 获取当前节点下方的索引
	int getDownIndex()const
	{
		return getIndexByXY(getDownX(), getDownY());
	}
	// 获取当前节点下方的横坐标
	int getDownX()const
	{
		return x;
	}
	// 获取当前节点下方的纵坐标
	int getDownY()const
	{
		if (y + 1 >= mapNodecountVertical)
			return invalidIndex;
		else
			return y + 1;
	}

	// 获取当前节点左方的索引
	int getLeftIndex()const
	{
		return getIndexByXY(getLeftX(), getLeftY());
	}
	// 获取当前节点左方的横坐标
	int getLeftX()const
	{
		if (x - 1 < 0)
			return invalidIndex;
		else
			return x - 1;
	}
	// 获取当前节点左方的纵坐标
	int getLeftY()const
	{
		return y;
	}
};

#endif
