#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MAP_MAPNODE_H_
#define MZNQA_CLASSES_MAP_MAPNODE_H_

#include "map/MapDefine.h"

struct MapNode
{
	// ��ͼ�ڵ�����
	enum MapNodeType
	{
		// �ݵ�
		MapType_Meadow = 0
	};

	// ��ͼ��·��־
	enum RoadSign
	{
		RoadSign_URDL = 1234,
		RoadSign_RDL = 234,
		RoadSign_UDL = 134,
		RoadSign_URL = 124,
		RoadSign_URD = 123,
		RoadSign_DL = 34,
		RoadSign_RL = 24,
		RoadSign_RD = 23,
		RoadSign_UL = 14,
		RoadSign_UD = 13,
		RoadSign_UR = 12,
		RoadSign_U = 1,
		RoadSign_R = 2,
		RoadSign_D = 3,
		RoadSign_L = 4,
	};

	// ���� index = x + y * MAP_NODECOUNT_VERTICAL
	int index;

	// ����
	int x, y;

	// ��ͼ���ͣ���ò��
	MapNodeType type;

	// ��ͼ��·��ʶ
	RoadSign roadSign;

	int up;
	int right;
	int down;
	int left;

	MapNode() :
		index(-1),
		x(-1),
		y(-1),
		type(MapNodeType(-1)),
		roadSign(RoadSign(-1)),
		up(-1),
		right(-1),
		down(-1),
		left(-1)
	{
	}

	MapNode(int index, int x, int y, MapNodeType type, RoadSign roadSign, int up, int right, int down, int left) :
		index(index),
		x(x),
		y(y),
		type(type),
		roadSign(roadSign),
		up(up),
		right(right),
		down(down),
		left(left)
	{
	}
};

#endif