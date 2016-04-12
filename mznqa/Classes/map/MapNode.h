/*!
 * \file	Classes\map\MapNode.h
 *
 * \brief	������ MapNode
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MAP_MAPNODE_H_
#define MZNQA_CLASSES_MAP_MAPNODE_H_

#include "map/MapController.h"

/*!
 * \struct	MapNode
 *
 * \brief	��ͼ����С��Ԫ����ͼ�ڵ�
 *
 */
struct MapNode
{
	/*!
	 * \enum	NodeType
	 *
	 * \brief	�ڵ�����
	 */
	enum NodeType
	{
		NodeType_None = 0,		///< ���ض�����
		NodeType_Road = 1,		///< ��·
		NodeType_Wall = 2,		///< ǽ
	};

	/*! \brief	��ʶ��Ч�Ľڵ����� */
	static const int invalidIndex = -1;
	/*! \brief	ָ���ͼ�ڵ������ */
	const int index;
	/*! \brief	��ͼ�ڵ�ĺ����� */
	const int x;
	/*! \brief	��ͼ�ڵ�������� */
	const int y;
	/*! \brief	��ʶ��ͼ�ڵ��Ƿ���֪ */
	bool known;
	/*! \brief	�ڵ����� */
	NodeType nodeType;
	/*! \brief	�Ƿ��и����� */
	bool hasExtra;

	/*!
	 * \fn	MapNode ( int index, int x, int y, bool known, NodeType nodeType, bool hasExtra)
	 *
	 * \brief	���캯��
	 *
	 * \param	index	 	ָ����ͼ�ڵ������
	 * \param	x		 	ָ����ͼ�ڵ�ĺ�����
	 * \param	y		 	ָ����ͼ�ڵ��������
	 * \param	known	 	ָ����ͼ�ڵ��Ƿ���֪
	 * \param	nodeType 	ָ����ͼ�ڵ������
	 * \param	hasExtra	ָ����ͼ�ڵ���Ƿ����������
	 */
	MapNode
		(
		int index,
		int x,
		int y,
		bool known,
		NodeType nodeType,
		bool hasExtra
		) :
		index(index),
		x(x),
		y(y),
		known(known),
		nodeType(nodeType),
		hasExtra(hasExtra)
	{
	}

	/*!
	 * \fn	MapNode(const MapNode &mapNode)
	 *
	 * \brief	�������캯��
	 *
	 * \param	mapNode	MapNode ʵ��
	 */
	MapNode(const MapNode &mapNode) :
		index(mapNode.index),
		x(mapNode.x),
		y(mapNode.y),
		known(mapNode.known),
		nodeType(mapNode.nodeType),
		hasExtra(mapNode.hasExtra)

	{
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

	/*!
	 * \fn	static bool checkX(int x)
	 *
	 * \brief	�������ĺ������Ƿ�Ϸ�
	 *
	 * \param	x	ָ�������ĺ�����ֵ
	 *
	 * \return	���ظ����ĺ�����ֵ�Ƿ�Ϸ�
	 */
	static bool checkX(int x)
	{
		return 0 <= x && x < MapController::mapNodecountHorizontal;
	}

	/*!
	 * \fn	static bool checkY(int y)
	 *
	 * \brief	��������������ֵ�Ƿ�Ϸ�
	 *
	 * \param	y	ָ��������������ֵ
	 *
	 * \return	���ظ�����������ֵ�Ƿ�Ϸ�
	 */
	static bool checkY(int y)
	{
		return 0 <= y && y < MapController::mapNodecountVertical;
	}

	/*!
	 * \fn	static bool checkXY(int x, int y)
	 *
	 * \brief	�������ĺ�������ֵ�Ƿ�Ϸ�
	 *
	 * \param	x	ָ�������ĺ�����ֵ
	 * \param	y	ָ��������������ֵ
	 *
	 * \return	���ظ����ĺ�������ֵ�Ƿ�Ϸ�
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
	 * \brief	��ȡ�����ĺ��������Ӧ�ĵ�ͼ�ڵ�����
	 *
	 * \param	x	ָ��������ֵ
	 * \param	y	ָ��������ֵ
	 *
	 * \return	���ظ����ĺ��������Ӧ�ĵ�ͼ�ڵ������
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
	 * \brief	��ȡ��ǰ�ڵ��Ϸ��Ľڵ������
	 *
	 * \return	���ص�ǰ�ڵ��Ϸ��Ľڵ������
	 */
	int getUpIndex()const
	{
		return getIndexByXY(getUpX(), getUpY());
	}

	/*!
	 * \fn	int getUpX()const
	 *
	 * \brief	��ȡ��ǰ�ڵ��Ϸ��Ľڵ�ĺ�����
	 *
	 * \return	���ص�ǰ�ڵ��Ϸ��Ľڵ�ĺ�����
	 */
	int getUpX()const
	{
		return x;
	}

	/*!
	 * \fn	int getUpY()const
	 *
	 * \brief	��ȡ��ǰ�ڵ��Ϸ��Ľڵ��������
	 *
	 * \return	���ص�ǰ�ڵ��Ϸ��Ľڵ��������
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
	 * \brief	��ȡ��ǰ�ڵ��ҷ��Ľڵ������
	 *
	 * \return	���ص�ǰ�ڵ��ҷ��Ľڵ������
	 */
	int getRightIndex()const
	{
		return getIndexByXY(getRightX(), getRightY());
	}

	/*!
	 * \fn	int getRightX()const
	 *
	 * \brief	��ȡ��ǰ�ڵ��ҷ��Ľڵ�ĺ�����
	 *
	 * \return	���ص�ǰ�ڵ��ҷ��Ľڵ�ĺ�����
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
	 * \brief	��ȡ��ǰ�ڵ��ҷ��Ľڵ��������
	 *
	 * \return	���ص�ǰ�ڵ��ҷ��Ľڵ��������
	 */
	int getRightY()const
	{
		return y;
	}

	/*!
	 * \fn	int getDownIndex()const
	 *
	 * \brief	��ȡ��ǰ�ڵ��·��Ľڵ������
	 *
	 * \return	���ص�ǰ�ڵ��·��Ľڵ������
	 */
	int getDownIndex()const
	{
		return getIndexByXY(getDownX(), getDownY());
	}

	/*!
	 * \fn	int getDownX()const
	 *
	 * \brief	��ȡ��ǰ�ڵ��·��Ľڵ�ĺ�����
	 *
	 * \return	��ȡ��ǰ�ڵ��·��Ľڵ�ĺ�����
	 */
	int getDownX()const
	{
		return x;
	}

	/*!
	 * \fn	int getDownY()const
	 *
	 * \brief	��ȡ��ǰ�ڵ��·��Ľڵ��������
	 *
	 * \return	���ص�ǰ�ڵ��·��Ľڵ��������
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
	 * \brief	��ȡ��ǰ�ڵ��󷽵Ľڵ������
	 *
	 * \return	���ص�ǰ�ڵ��󷽵Ľڵ������
	 */
	int getLeftIndex()const
	{
		return getIndexByXY(getLeftX(), getLeftY());
	}

	/*!
	 * \fn	int getLeftX()const
	 *
	 * \brief	��ȡ��ǰ�ڵ��󷽵Ľڵ�ĺ�����
	 *
	 * \return	���ص�ǰ�ڵ��󷽵Ľڵ�ĺ�����
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
	 * \brief	��ȡ��ǰ�ڵ��󷽵Ľڵ��������
	 *
	 * \return	���ص�ǰ�ڵ��󷽵Ľڵ��������
	 */
	int getLeftY()const
	{
		return y;
	}
};

#endif
