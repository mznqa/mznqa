#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_SIZECONTROLLER_H_
#define MZNQA_CLASSES_ENGINE_SIZECONTROLLER_H_

#include "map/MapView.h"

class SizeController
{
private:
	SizeController(){}
	SizeController(const SizeController &sizeController);
	SizeController& operator=(const SizeController &sizeController);

	MapView *MapViewInstance = MapView::Instance();

public:
	static SizeController* Instance();
	~SizeController(){}

	float designResolutionSizeWidth = 0.0f;
	float designResolutionSizeHeight = 0.0f;

	float realityScreenSizeWidth = 0.0f;
	float realityScreenSizeHeight = 0.0f;

	float realityVisibleOriginX = 0.0f;
	float realityVisibleOriginY = 0.0f;

	float designMapCellSize = 64.0f;

	float realityMapCellSize = 0.0f;

	/*!
	 * \fn	static float gX2CartesianX(int gX)
	 *
	 * \brief	根据给定的地图横坐标计算其在屏幕的横坐标
	 *
	 * \param	gX	指定地图横坐标
	 *
	 * \return	屏幕横坐标
	 */
	float gX2CartesianX(int gX)
	{
		return (realityVisibleOriginX + (gX - MapViewInstance->getLeftTopGX())*designMapCellSize);
	}

	/*!
	 * \fn	static float gY2CartesianY(int gY)
	 *
	 * \brief	根据给定的地图纵坐标计算其在屏幕的纵坐标
	 *
	 * \param	gY	指定地图纵坐标
	 *
	 * \return	屏幕纵坐标
	 */
	float gY2CartesianY(int gY)
	{
		return (designResolutionSizeHeight - ((gY - MapViewInstance->getLeftTopGY())*designMapCellSize));
	}

	int cartesianX2GX(float cartesianX)
	{
		return MapViewInstance->getLeftTopGX() + (cartesianX - gX2CartesianX(MapViewInstance->getLeftTopGX())) / (designMapCellSize * 3);
	}

	int cartesianY2GY(float cartesianY)
	{
		return MapViewInstance->getLeftTopGY() + (gY2CartesianY(MapViewInstance->getLeftTopGY()) - cartesianY) / (designMapCellSize * 3);
	}
};

#endif
