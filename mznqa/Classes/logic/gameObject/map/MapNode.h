/*!
 * \file	Classes\logic\gameObject\map\MapNode.h
 *
 * \brief	����ṹ�� MapNode
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_MAP_MAPNODE_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_MAP_MAPNODE_H_

#include "common/arkca/Vector2.h"

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
		NodeType_Wall_Const = 102,
		NodeType_Border_Const = 103
	};

	/*!
	 * \enum	ExtraType
	 *
	 * \brief	ö�ٸ���������
	 */
	enum ExtraType
	{
		ExtraType_None,
		ExtraType_Door_Mission_Main,
		ExtraType_Door_Mission_Secondary,
		ExtraType_Door_NextMap
	};

	/*! \brief	��Ч�Ľڵ�λ�� */
	static const ArKCa::Vector2<int> invalidPosition;

	/*! \brief	�ڵ�λ�� */
	ArKCa::Vector2<int> position;
	/*! \brief	�ڵ����� */
	NodeType nodeType;
	/*! \brief	���������� */
	ExtraType extraType;
	/*! \brief	�ڵ�ɼ��� */
	bool nodeVisible;
	/*! \brief	������ɼ��� */
	bool extraVisible;
	/*! \brief	���ڽӽڵ�ID */
	ArKCa::Vector2<int> adjacencyUp;
	/*! \brief	���ڽӽڵ�ID */
	ArKCa::Vector2<int> adjacencyRight;
	/*! \brief	���ڽӽڵ�ID */
	ArKCa::Vector2<int> adjacencyDown;
	/*! \brief	���ڽӽڵ�ID */
	ArKCa::Vector2<int> adjacencyLeft;

	/*!
	 * \fn	MapNode()
	 *
	 * \brief	Ĭ�Ϲ��캯��
	 *
	 */
	MapNode() :
		position(invalidPosition),
		nodeType(NodeType_None),
		extraType(ExtraType_None),
		nodeVisible(false),
		extraVisible(false),
		adjacencyUp(invalidPosition),
		adjacencyRight(invalidPosition),
		adjacencyDown(invalidPosition),
		adjacencyLeft(invalidPosition)
	{
	}

	/*!
	 * \fn	MapNode( const ArKCa::Vector2<int> &position, NodeType nodeType, ExtraType extraType, bool nodeVisible, bool extraVisible, const ArKCa::Vector2<int> &adjacencyUp, const ArKCa::Vector2<int> &adjacencyRight, const ArKCa::Vector2<int> &adjacencyDown, const ArKCa::Vector2<int> &adjacencyLeft )
	 *
	 * \brief	���캯��
	 *
	 * \param	position		ָ���ڵ������
	 * \param	nodeType		ָ���ڵ�����
	 * \param	extraType   	ָ���ڵ㸽��������
	 * \param	nodeVisible 	ָ���ڵ�ɼ���
	 * \param	extraVisible	ָ���ڵ㸽����ɼ���
	 * \param	adjacencyUp   	ָ���Ϸ����ڽӵ�ID
	 * \param	adjacencyRight	ָ���ҷ����ڽӵ�ID
	 * \param	adjacencyDown 	ָ���·����ڽӵ�ID
	 * \param	adjacencyLeft 	ָ�������ڽӵ�ID
	 */
	MapNode(
		const ArKCa::Vector2<int> &position,
		NodeType nodeType,
		ExtraType extraType,
		bool nodeVisible,
		bool extraVisible,
		const ArKCa::Vector2<int> &adjacencyUp,
		const ArKCa::Vector2<int> &adjacencyRight,
		const ArKCa::Vector2<int> &adjacencyDown,
		const ArKCa::Vector2<int> &adjacencyLeft
		) :
		position(position),
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
	 * \brief	�������캯��
	 *
	 */
	MapNode(const MapNode &mapNode) :
		position(mapNode.position),
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
	 * \brief	������ֵ�����
	 *
	 */
	MapNode& operator=(const MapNode &mapNode)
	{
		this->position = mapNode.position;
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
	 * \brief	��������
	 *
	 */
	~MapNode()
	{
	}
};

#endif
