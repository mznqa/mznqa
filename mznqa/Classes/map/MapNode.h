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
	static const int MapNodecountHorizontal = 640;
	// 地图纵向节点数
	static const int MapNodecountVertival = 360;
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

	static int getIndexByXY(int x, int y)
	{
		if (
			0 <= x && x < MapNodecountHorizontal &&
			0 <= y && y < MapNodecountVertival
			)
			return x + y * MapNodecountHorizontal;
		else
			return -1;
	}

	int getUpIndex()const
	{
		return getIndexByXY(getUpX(), getUpY());
	}
	int getUpX()const
	{
		return x;
	}
	int getUpY()const
	{
		if (y - 1 < 0)
			return -1;
		else
			return y - 1;
	}

	int getRightIndex()const
	{
		return getIndexByXY(getRightX(), getRightY());
	}
	int getRightX()const
	{
		if (x + 1 >= MapNodecountHorizontal)
			return -1;
		else
			return x + 1;
	}
	int getRightY()const
	{
		return y;
	}

	int getDownIndex()const
	{
		return getIndexByXY(getDownX(), getDownY());
	}
	int getDownX()const
	{
		return x;
	}
	int getDownY()const
	{
		if (y + 1 >= MapNodecountVertival)
			return -1;
		else
			return y + 1;
	}

	int getLeftIndex()const
	{
		return getIndexByXY(getLeftX(), getLeftY());
	}
	int getLeftX()const
	{
		if (x - 1 < 0)
			return -1;
		else
			return x - 1;
	}
	int getLeftY()const
	{
		return y;
	}
};

#endif
