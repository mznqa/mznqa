/*!
 * \file	Classes\logic\gameObject\map\MapNode.h
 *
 * \brief	����ṹ�� MapNode
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_MAP_MAPNODE_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_MAP_MAPNODE_H_

/*!
 * \struct	MapNode
 *
 * \brief	��ͼ�ڵ�
 *
 */
struct MapNode
{
	/*!
	 * \enum	NodeType
	 *
	 * \brief	ö�ٽڵ�����
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
	 * \brief	ö�ٸ���������
	 */
	enum ExtraType
	{
		ExtraType_None
	};

	/*! \brief	�ڵ�ID */
	int id;
	/*! \brief	�ڵ������ */
	int x;
	/*! \brief	�ڵ������� */
	int y;
	/*! \brief	�ڵ����� */
	NodeType nodeType;
	/*! \brief	���������� */
	ExtraType extraType;
	/*! \brief	�ڵ�ɼ��� */
	bool nodeVisible;
	/*! \brief	������ɼ��� */
	bool extraVisible;

	/*!
	 * \fn	MapNode(int id, int x, int y, NodeType nodeType, ExtraType extraType, bool nodeVisible, bool extraVisible)
	 *
	 * \brief	���캯��
	 *
	 * \param	id				ָ���ڵ�ID
	 * \param	x				ָ���ڵ������
	 * \param	y				ָ���ڵ�������
	 * \param	nodeType		ָ���ڵ�����
	 * \param	extraType   	ָ���ڵ㸽��������
	 * \param	nodeVisible 	ָ���ڵ�ɼ���
	 * \param	extraVisible	ָ���ڵ㸽����ɼ���
	 */
	MapNode(int id, int x, int y, NodeType nodeType, ExtraType extraType, bool nodeVisible, bool extraVisible) :
		id(id),
		x(x),
		y(y),
		nodeType(nodeType),
		extraType(extraType),
		nodeVisible(nodeVisible),
		extraVisible(extraVisible)
	{
	}

	/*!
	 * \fn	MapNode(const MapNode &mapNode)
	 *
	 * \brief	�������캯��
	 *
	 */
	MapNode(const MapNode &mapNode) :
		id(mapNode.id),
		x(mapNode.x),
		y(mapNode.y),
		nodeType(mapNode.nodeType),
		extraType(mapNode.extraType),
		nodeVisible(mapNode.nodeVisible),
		extraVisible(mapNode.extraVisible)
	{
	}

	/*!
	 * \fn	MapNode& operator=(const MapNode &mapNode)
	 *
	 * \brief	������ֵ�����
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
		return *this;
	}

	/*!
	 * \fn	~MapNode()
	 *
	 * \brief	��������
	 *
	 */
	~MapNode()
	{
	}
};

#endif
