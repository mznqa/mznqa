/*!
 * \file	Classes\map\MapView.h
 *
 * \brief	������ MapView
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MAP_MAPVIEW_H_
#define MZNQA_CLASSES_MAP_MAPVIEW_H_

#include "map/MapController.h"

/*!
 * \class	MapView
 *
 * \brief	���ڸ�����ͼ��ʾ�ĵ�ͼ��Ұ����
 *
 */
class MapView
{
private:
	/*! \brief	��ͼ��Ұ�����Ͻǵĵ�ͼ���ӵĺ����� */
	int leftTopGX;
	/*! \brief	��ͼ��Ұ�����Ͻǵĵ�ͼ���ӵ������� */
	int leftTopGY;

	/*! \brief	��ͼ��Ұ�Ŀ�� */
	int width;
	/*! \brief	��ͼ��Ұ�ĸ߶� */
	int height;

public:
	/*! \brief	��ʶ��Ч��������ֵ */
	static const int invalidXOrY = -1;

	/*!
	 * \fn	MapView::MapView( int leftTopGX, int leftTopGY, int width, int height )
	 *
	 * \brief	���캯��
	 *
	 * \param	leftTopGX	ָ����ͼ��Ұ�����Ͻǵĵ�ͼ���ӵĺ�����
	 * \param	leftTopGY	ָ����ͼ��Ұ�����Ͻǵĵ�ͼ���ӵ�������
	 * \param	width	 	ָ����ͼ��Ұ�Ŀ��
	 * \param	height   	ָ����ͼ��Ұ�ĸ߶�
	 */
	MapView(
		int leftTopGX,
		int leftTopGY,
		int width,
		int height
		) :
		leftTopGX(leftTopGX),
		leftTopGY(leftTopGY),
		width(width),
		height(height)
	{
	}

	/*!
	 * \fn	MapView::~MapView()
	 *
	 * \brief	��������
	 *
	 */
	~MapView(){}

	/*!
	 * \fn	int MapView::getLeftTopGX()const
	 *
	 * \brief	��ȡ��ͼ��Ұ�����Ͻǵĵ�ͼ���ӵĺ�����
	 *
	 * \return	���ص�ͼ��Ұ�����Ͻǵĵ�ͼ���ӵĺ�����
	 */
	int getLeftTopGX()const
	{
		return leftTopGX;
	}

	/*!
	 * \fn	int MapView::getLeftTopGY()const
	 *
	 * \brief	��ȡ��ͼ��Ұ�����Ͻǵĵ�ͼ���ӵ�������
	 *
	 * \return	���ص�ͼ��Ұ�����Ͻǵĵ�ͼ���ӵ�������
	 */
	int getLeftTopGY()const
	{
		return leftTopGY;
	}

	/*!
	 * \fn	int MapView::getWidht()const
	 *
	 * \brief	��ȡ��ͼ��Ұ�Ŀ��
	 *
	 * \return	���ص�ͼ��Ұ�Ŀ��
	 */
	int getWidht()const
	{
		return width;
	}

	/*!
	 * \fn	int MapView::getHeight()const
	 *
	 * \brief	��ȡ��ͼ��Ұ�ĸ߶�
	 *
	 * \return	���ص�ͼ��Ұ�ĸ߶�
	 */
	int getHeight()const
	{
		return height;
	}

	/*!
	 * \fn	int MapView::getViewRangeXBegin()const
	 *
	 * \brief	��ȡ��ͼ��Ұ�����ڵ���ʼ������
	 *
	 * \return	���ص�ͼ��Ұ�����ڵ���ʼ������
	 */
	int getViewRangeXBegin()const
	{
		return leftTopGX;
	}

	/*!
	 * \fn	int MapView::getViewRangeXEnd()const
	 *
	 * \brief	��ȡ��ͼ��Ұ�����ڵ����պ�����
	 *
	 * \return	���ص�ͼ��Ұ�����ڵ����պ�����
	 */
	int getViewRangeXEnd()const
	{
		return leftTopGX + width;
	}

	/*!
	 * \fn	int MapView::getViewRangeYBegin()const
	 *
	 * \brief	��ȡ��ͼ��Ұ�����ڵ���ʼ������
	 *
	 * \return	���ص�ͼ��Ұ�����ڵ���ʼ������
	 */
	int getViewRangeYBegin()const
	{
		return leftTopGY;
	}

	/*!
	 * \fn	int MapView::getViewRangeYEnd()const
	 *
	 * \brief	��ȡ��ͼ��Ұ�����ڵ�����������
	 *
	 * \return	���ص�ͼ��Ұ�����ڵ�����������
	 */
	int getViewRangeYEnd()const
	{
		return leftTopGY + height;
	}

	/*!
	 * \fn	bool MapView::judgeMoveUp()const
	 *
	 * \brief	�ж��Ƿ�����������Ұ
	 *
	 * \return	�����Ƿ�����������Ұ
	 */
	bool judgeMoveUp()const
	{
		return !(leftTopGY + 3 > MapController::mapNodecountVertical - height);
	}

	/*!
	 * \fn	bool MapView::judgeMoveDown()const
	 *
	 * \brief	�ж��Ƿ�����������Ұ
	 *
	 * \return	�����Ƿ�����������Ұ
	 */
	bool judgeMoveDown()const
	{
		return !(leftTopGY - 3 < 0);
	}

	/*!
	 * \fn	bool MapView::judgeMoveLeft()const
	 *
	 * \brief	�ж��Ƿ�����������Ұ
	 *
	 * \return	�����Ƿ�����������Ұ
	 */
	bool judgeMoveLeft()const
	{
		return !(leftTopGX + 3 > MapController::mapNodecountHorizontal - width);
	}

	/*!
	 * \fn	bool MapView::judgeMoveRight()const
	 *
	 * \brief	�ж��Ƿ�����������Ұ
	 *
	 * \return	�����Ƿ�����������Ұ
	 */
	bool judgeMoveRight()const
	{
		return !(leftTopGX - 3 < 0);
	}

	/*!
	 * \fn	void MapView::moveUp()
	 *
	 * \brief	������Ұ
	 *
	 */
	void moveUp()
	{
		if (judgeMoveUp() == false)
			return;

		leftTopGY += 3;
	}

	/*!
	 * \fn	void MapView::moveDown()
	 *
	 * \brief	������Ұ
	 *
	 */
	void moveDown()
	{
		if (judgeMoveDown() == false)
			return;

		leftTopGY -= 3;
	}

	/*!
	 * \fn	void MapView::moveLeft()
	 *
	 * \brief	������Ұ
	 *
	 */
	void moveLeft()
	{
		if (judgeMoveLeft() == false)
			return;

		leftTopGX += 3;
	}

	/*!
	 * \fn	void MapView::moveRight()
	 *
	 * \brief	������Ұ
	 *
	 */
	void moveRight()
	{
		if (judgeMoveRight() == false)
			return;

		leftTopGX -= 3;
	}
};

#endif
