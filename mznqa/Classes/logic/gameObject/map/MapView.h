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
#include "common/arkca/Range.h"
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
		if (mapView.size.width < 0 || mapView.size.height < 0 || mapView.origin.x < 0 || mapView.origin.y < 0)
			return *this;

		this->size = mapView.size;
		this->origin = mapView.origin;
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

	/*!
	 * \fn	const ArKCa::Size<int>& MapView::getViewSize()const
	 *
	 * \brief	获取视野尺寸
	 *
	 */
	const ArKCa::Size<int>& getViewSize()const
	{
		return size;
	}

	/*!
	 * \fn	const ArKCa::Vector2<int>& MapView::getViewOrigin()const
	 *
	 * \brief	获取视野原点的地图坐标
	 *
	 */
	const ArKCa::Vector2<int>& getViewOrigin()const
	{
		return origin;
	}

	/*!
	 * \fn	void MapView::setViewOrigin(const ArKCa::Vector2<int> &origin)
	 *
	 * \brief	设置视野原点
	 *
	 */
	void setViewOrigin(const ArKCa::Vector2<int> &origin)
	{
		this->origin = origin;
	}

	/*!
	 * \fn	ArKCa::Range<int> MapView::getRangeX()const
	 *
	 * \brief	获取视野的横向区间
	 *
	 */
	ArKCa::Range<int> getRangeX()const
	{
		return ArKCa::Range<int>(origin.x, origin.x + size.width);
	}

	/*!
	 * \fn	ArKCa::Range<int> MapView::getRangeY()const
	 *
	 * \brief	获取视野的纵向区间
	 *
	 */
	ArKCa::Range<int> getRangeY()const
	{
		return ArKCa::Range<int>(origin.y, origin.y + size.height);
	}
};

#endif
