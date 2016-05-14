/*!
 * \file	Classes\logic\gameObject\map\MapView.h
 *
 * \brief	������ MapView
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
 * \brief	��ͼ��Ұ
 *
 */
class MapView
{
private:
	/*! \brief	��ͼ��Ұ�ĳߴ� */
	ArKCa::Size<int> size;
	/*! \brief	��ͼ��Ұ���Ͻ���� */
	ArKCa::Vector2<int> origin;

public:

	/*!
	 * \fn	MapView::MapView()
	 *
	 * \brief	���캯��
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
	 * \brief	���캯��
	 *
	 * \param	size  	ָ����ͼ��Ұ�Ĵ�С
	 * \param	origin	ָ����ͼ��Ұ���Ͻ���������
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
	 * \brief	�������캯��
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
	 * \brief	������ֵ�����
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
	 * \brief	��������
	 *
	 */
	~MapView()
	{
	}

	/*!
	 * \fn	std::vector<ArKCa::Vector2<int> > MapView::getMapGroupPositionSet(const ArKCa::Vector2<int> &position);
	 *
	 * \brief	���ݸ��������ȡ���ڵĵ�ͼ���ڵ����е�ͼ�ڵ������
	 *
	 * \param	position	ָ��һ����ͼ�ڵ�����
	 *
	 */
	std::vector<ArKCa::Vector2<int> > getMapGroupPositionSet(const ArKCa::Vector2<int> &position);
};

#endif
