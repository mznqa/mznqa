#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MAP_MAPNODE_H_
#define MZNQA_CLASSES_MAP_MAPNODE_H_

struct MapNode
{
	// �ڵ���
	enum NodeStyle
	{
		NodeStyle_None = 0,
		// �ݵ�
		NodeStyle_Meadow
	};
	// ��·����
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
	// ��ͼ����ڵ���
	static const int mapNodecountHorizontal = 640;
	// ��ͼ����ڵ���
	static const int mapNodecountVertical = 360;
	// ��Ч����
	static const int invalidIndex = -1;
	// �ڵ�����
	const int index;
	// �ڵ������
	const int x;
	// �ڵ�������
	const int y;
	// �ڵ��Ƿ���֪
	bool known;
	// �ڵ��·����
	RoadType roadType;
	// �ڵ���
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

	// �������������Ƿ�Ϸ�
	static bool checkX(int x)
	{
		return 0 <= x && x < mapNodecountHorizontal;
	}

	// �������������Ƿ�Ϸ�
	static bool checkY(int y)
	{
		return 0 <= y && y < mapNodecountVertical;
	}

	// ���������������Ƿ�Ϸ�
	static bool checkXY(int x, int y)
	{
		return (
			0 <= x && x < mapNodecountHorizontal &&
			0 <= y && y < mapNodecountVertical
			);
	}

	// ��������ֵ��ȡ��Ӧ����
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

	// ��ȡ��ǰ�ڵ��Ϸ�������
	int getUpIndex()const
	{
		return getIndexByXY(getUpX(), getUpY());
	}
	// ��ȡ��ǰ�ڵ��Ϸ��ĺ�����
	int getUpX()const
	{
		return x;
	}
	// ��ȡ��ǰ�ڵ��Ϸ���������
	int getUpY()const
	{
		if (y - 1 < 0)
			return invalidIndex;
		else
			return y - 1;
	}

	// ��ȡ��ǰ�ڵ��ҷ�������
	int getRightIndex()const
	{
		return getIndexByXY(getRightX(), getRightY());
	}
	// ��ȡ��ǰ�ڵ��ҷ��ĺ�����
	int getRightX()const
	{
		if (x + 1 >= mapNodecountHorizontal)
			return invalidIndex;
		else
			return x + 1;
	}
	// ��ȡ��ǰ�ڵ��ҷ���������
	int getRightY()const
	{
		return y;
	}

	// ��ȡ��ǰ�ڵ��·�������
	int getDownIndex()const
	{
		return getIndexByXY(getDownX(), getDownY());
	}
	// ��ȡ��ǰ�ڵ��·��ĺ�����
	int getDownX()const
	{
		return x;
	}
	// ��ȡ��ǰ�ڵ��·���������
	int getDownY()const
	{
		if (y + 1 >= mapNodecountVertical)
			return invalidIndex;
		else
			return y + 1;
	}

	// ��ȡ��ǰ�ڵ��󷽵�����
	int getLeftIndex()const
	{
		return getIndexByXY(getLeftX(), getLeftY());
	}
	// ��ȡ��ǰ�ڵ��󷽵ĺ�����
	int getLeftX()const
	{
		if (x - 1 < 0)
			return invalidIndex;
		else
			return x - 1;
	}
	// ��ȡ��ǰ�ڵ��󷽵�������
	int getLeftY()const
	{
		return y;
	}
};

#endif
