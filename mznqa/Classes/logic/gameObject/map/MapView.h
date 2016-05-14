/*!
 * \file	Classes\logic\gameObject\map\MapView.h
 *
 * \brief	定义类 MapView
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_MAP_MAPVIEW_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_MAP_MAPVIEW_H_

#include <vector>

#include "common/arkca/Vector2.h"
#include "common/arkca/Size.h"
#include "logic/data/info/NumDefine.h"

/*!
 * \class	MapView
 *
 * \brief	地图视野
 *
 */
class MapView
{
private:
	/*! \brief	地图视野的尺寸 */
	ArKCa::Size<int> size;
	/*! \brief	地图视野左上角起点 */
	ArKCa::Vector2<int> origin;

public:

	/*!
	 * \fn	MapView::MapView()
	 *
	 * \brief	构造函数
	 *
	 */
	MapView() :
		size(0, 0),
		origin(0, 0)
	{
	}

	/*!
	 * \fn	MapView::MapView(const ArKCa::Size<int> &size, const ArKCa::Vector2<int> &origin)
	 *
	 * \brief	构造函数
	 *
	 * \param	size  	指定地图视野的大小
	 * \param	origin	指定地图视野左上角起点的坐标
	 */
	MapView(const ArKCa::Size<int> &size, const ArKCa::Vector2<int> &origin) :
		size(size),
		origin(origin)
	{
		if (size.width < 0 || size.height < 0 || origin.x < 0 || origin.y < 0)
		{
			this->size.set(0, 0);
			this->origin.set(0, 0);
		}
	}

	/*!
	 * \fn	MapView::MapView(const MapView &mapView)
	 *
	 * \brief	拷贝构造函数
	 *
	 */
	MapView(const MapView &mapView) :
		size(mapView.size),
		origin(mapView.origin)
	{
		if (size.width < 0 || size.height < 0 || origin.x < 0 || origin.y < 0)
		{
			this->size.set(0, 0);
			this->origin.set(0, 0);
		}
	}

	/*!
	 * \fn	MapView& MapView::operator=(const MapView &mapView)
	 *
	 * \brief	拷贝赋值运算符
	 *
	 */
	MapView& operator=(const MapView &mapView)
	{
		if (size.width < 0 || size.height < 0 || origin.x < 0 || origin.y < 0)
			return *this;

		this->size = size;
		this->origin = origin;
		return *this;
	}

	/*!
	 * \fn	MapView::~MapView()
	 *
	 * \brief	析构函数
	 *
	 */
	~MapView()
	{
	}

	/*!
	 * \fn	std::vector<ArKCa::Vector2<int> > MapView::getMapGroupPositionSet(const ArKCa::Vector2<int> &position);
	 *
	 * \brief	根据给定坐标获取所在的地图组内的所有地图节点的坐标
	 *
	 * \param	position	指定一个地图内的坐标
	 *
	 */
	std::vector<ArKCa::Vector2<int> > getMapGroupPositionSet(const ArKCa::Vector2<int> &position);
};

#endif
