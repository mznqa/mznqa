/*!
 * \file	Classes\map\MapView.h
 *
 * \brief	定义类 MapView
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MAP_MAPVIEW_H_
#define MZNQA_CLASSES_MAP_MAPVIEW_H_

#include "map/MapController.h"
#include "message/LogicMessagePQ.h"

/*!
 * \class	MapView
 *
 * \brief	用于辅助地图显示的地图视野区域
 *
 */
class MapView
{
private:
	MapView(){}
	MapView(const MapView &mapView);
	MapView& operator=(const MapView &mapView);
	/*! \brief	地图视野内左上角的地图格子的横坐标 */
	int leftTopGX;
	/*! \brief	地图视野内左上角的地图格子的纵坐标 */
	int leftTopGY;

	/*! \brief	地图视野的宽度 */
	int width;
	/*! \brief	地图视野的高度 */
	int height;

	LogicMessagePQ *logicMessagePQInstance = LogicMessagePQ::Instance();

public:
	static MapView* Instance();

	/*! \brief	标识无效横纵坐标值 */
	static const int invalidXOrY = -1;

	/*!
	 * \fn	void MapView::initialize( int leftTopGX, int leftTopGY, int width, int height )
	 *
	 * \brief	初始化
	 *
	 * \param	leftTopGX	指定地图视野内左上角的地图格子的横坐标
	 * \param	leftTopGY	指定地图视野内左上角的地图格子的纵坐标
	 * \param	width	 	指定地图视野的宽度
	 * \param	height   	指定地图视野的高度
	 */
	void initialize(
		int leftTopGX,
		int leftTopGY,
		int width,
		int height
		)
	{
		this->leftTopGX = leftTopGX;
		this->leftTopGY = leftTopGY;
		this->width = width;
		this->height = height;
	}

	/*!
	 * \fn	MapView::~MapView()
	 *
	 * \brief	析构函数
	 *
	 */
	~MapView(){}

	/*!
	 * \fn	int MapView::getLeftTopGX()const
	 *
	 * \brief	获取地图视野内左上角的地图格子的横坐标
	 *
	 * \return	返回地图视野内左上角的地图格子的横坐标
	 */
	int getLeftTopGX()const
	{
		return leftTopGX;
	}

	/*!
	 * \fn	int MapView::getLeftTopGY()const
	 *
	 * \brief	获取地图视野内左上角的地图格子的纵坐标
	 *
	 * \return	返回地图视野内左上角的地图格子的纵坐标
	 */
	int getLeftTopGY()const
	{
		return leftTopGY;
	}

	/*!
	 * \fn	int MapView::getWidht()const
	 *
	 * \brief	获取地图视野的宽度
	 *
	 * \return	返回地图视野的宽度
	 */
	int getWidht()const
	{
		return width;
	}

	/*!
	 * \fn	int MapView::getHeight()const
	 *
	 * \brief	获取地图视野的高度
	 *
	 * \return	返回地图视野的高度
	 */
	int getHeight()const
	{
		return height;
	}

	/*!
	 * \fn	int MapView::getViewRangeXBegin()const
	 *
	 * \brief	获取地图视野区域内的起始横坐标
	 *
	 * \return	返回地图视野区域内的起始横坐标
	 */
	int getViewRangeXBegin()const
	{
		return leftTopGX;
	}

	/*!
	 * \fn	int MapView::getViewRangeXEnd()const
	 *
	 * \brief	获取地图视野区域内的最终横坐标
	 *
	 * \return	返回地图视野区域内的最终横坐标
	 */
	int getViewRangeXEnd()const
	{
		return leftTopGX + width;
	}

	/*!
	 * \fn	int MapView::getViewRangeYBegin()const
	 *
	 * \brief	获取地图视野区域内的起始横坐标
	 *
	 * \return	返回地图视野区域内的起始横坐标
	 */
	int getViewRangeYBegin()const
	{
		return leftTopGY;
	}

	/*!
	 * \fn	int MapView::getViewRangeYEnd()const
	 *
	 * \brief	获取地图视野区域内的最终纵坐标
	 *
	 * \return	返回地图视野区域内的最终纵坐标
	 */
	int getViewRangeYEnd()const
	{
		return leftTopGY + height;
	}

	/*!
	 * \fn	bool MapView::judgeMoveUp()const
	 *
	 * \brief	判断是否允许上移视野
	 *
	 * \return	返回是否允许上移视野
	 */
	bool judgeMoveUp()const
	{
		return !(leftTopGY + 3 > MapController::mapNodecountVertical - height);
	}

	/*!
	 * \fn	bool MapView::judgeMoveDown()const
	 *
	 * \brief	判断是否允许下移视野
	 *
	 * \return	返回是否允许下移视野
	 */
	bool judgeMoveDown()const
	{
		return !(leftTopGY - 3 < 0);
	}

	/*!
	 * \fn	bool MapView::judgeMoveLeft()const
	 *
	 * \brief	判断是否允许左移视野
	 *
	 * \return	返回是否允许左移视野
	 */
	bool judgeMoveLeft()const
	{
		return !(leftTopGX + 3 > MapController::mapNodecountHorizontal - width);
	}

	/*!
	 * \fn	bool MapView::judgeMoveRight()const
	 *
	 * \brief	判断是否允许右移视野
	 *
	 * \return	返回是否允许右移视野
	 */
	bool judgeMoveRight()const
	{
		return !(leftTopGX - 3 < 0);
	}

	/*!
	 * \fn	void MapView::moveUp()
	 *
	 * \brief	上移视野
	 *
	 */
	void moveUp()
	{
		if (judgeMoveUp() == false)
			return;

		leftTopGY += 3;
		logicMessagePQInstance->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_RefreshMapPosition));
		logicMessagePQInstance->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_RefreshRolePosition));
	}

	/*!
	 * \fn	void MapView::moveDown()
	 *
	 * \brief	下移视野
	 *
	 */
	void moveDown()
	{
		if (judgeMoveDown() == false)
			return;

		leftTopGY -= 3;
		logicMessagePQInstance->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_RefreshMapPosition));
		logicMessagePQInstance->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_RefreshRolePosition));
	}

	/*!
	 * \fn	void MapView::moveLeft()
	 *
	 * \brief	左移视野
	 *
	 */
	void moveLeft()
	{
		if (judgeMoveLeft() == false)
			return;

		leftTopGX += 3;
		logicMessagePQInstance->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_RefreshMapPosition));
		logicMessagePQInstance->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_RefreshRolePosition));
	}

	/*!
	 * \fn	void MapView::moveRight()
	 *
	 * \brief	右移视野
	 *
	 */
	void moveRight()
	{
		if (judgeMoveRight() == false)
			return;

		leftTopGX -= 3;
		logicMessagePQInstance->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_RefreshMapPosition));
		logicMessagePQInstance->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_RefreshRolePosition));
	}
};

#endif
