/*!
 * \file	Classes\interactive\manager\LightArea.h
 *
 * \brief	定义类 LightArea
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_MANAGER_LIGHTAREA_H_
#define MZNQA_CLASSES_INTERACTIVE_MANAGER_LIGHTAREA_H_

#include <vector>
#include <list>

#include "common/arkca/Vector2.h"
#include "common/arkca/LineSegment.h"

/*!
 * \class	LightArea
 *
 * \brief	光线区域
 *
 */
class LightArea
{
private:

	/*!
	 * \fn	LightArea::LightArea(const LightArea &lightArea);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 * \param	lightArea	The light area.
	 */
	LightArea(const LightArea &lightArea);

	/*!
	 * \fn	LightArea& LightArea::operator=(const LightArea &lightArea);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 */
	LightArea& operator=(const LightArea &lightArea);

	/*! \brief	光源坐标 */
	ArKCa::Vector2<int> lightPosition;
	/*! \brief	光线半径 */
	int lightScopeRadius;
	/*! \brief	光线区域中所有节点相对光源的坐标 */
	std::vector<ArKCa::Vector2<int>> lightScope;
	/*! \brief	光线区域边界集合 */
	std::list<ArKCa::LineSegment<float>> lightBorderList;

	/*!
	 * \fn	bool LightArea::isWithinLightScope(const ArKCa::Vector2<int> &position);
	 *
	 * \brief	判断指点是否处于光线中
	 *
	 * \param	position	指定地图坐标
	 *
	 */
	bool isWithinLightScope(const ArKCa::Vector2<int> &position);

	/*!
	 * \fn	void LightArea::buildLightScope();
	 *
	 * \brief	创建光线区域
	 *
	 */
	void buildLightScope();

	/*!
	 * \fn	void LightArea::buildLightBorderList();
	 *
	 * \brief	创建光线边界
	 *
	 */
	void buildLightBorderList();
public:

	/*!
	 * \fn	LightArea::LightArea()
	 *
	 * \brief	构造函数
	 *
	 */
	LightArea() :
		lightPosition(0, 0),
		lightScopeRadius(0),
		lightScope()
	{
	}

	/*!
	 * \fn	LightArea::LightArea( const ArKCa::Vector2<int> &lightPosition, int lightScopeRadius );
	 *
	 * \brief	构造函数
	 *
	 * \param	lightPosition		指定光源坐标
	 * \param	lightScopeRadius	指定光线半径
	 */
	LightArea(
		const ArKCa::Vector2<int> &lightPosition,
		int lightScopeRadius
		);

	/*!
	 * \fn	LightArea::~LightArea()
	 *
	 * \brief	析构函数
	 *
	 */
	~LightArea()
	{
	}

	/*!
	 * \fn	const ArKCa::Vector2<int>& LightArea::getLightMapPosition()
	 *
	 * \brief	获取光源的地图坐标
	 *
	 */
	const ArKCa::Vector2<int>& getLightMapPosition()
	{
		return lightPosition;
	}

	/*!
	 * \fn	void LightArea::setLightPosition(const ArKCa::Vector2<int> &lightPosition);
	 *
	 * \brief	设置光源坐标
	 *
	 * \param	lightPosition	指定光源的地图坐标
	 */
	void setLightPosition(const ArKCa::Vector2<int> &lightPosition);

	/*!
	 * \fn	void LightArea::setLightScopeRadius(int lightScopeRadius);
	 *
	 * \brief	设置光线区域的半径大小
	 *
	 * \param	lightScopeRadius	指定光线区域的半径
	 */
	void setLightScopeRadius(int lightScopeRadius);

	/*!
	 * \fn	const std::list<ArKCa::LineSegment<float> >& LightArea::getLightBorderList()
	 *
	 * \brief	获取光线区域的边界集合
	 *
	 */
	const std::list<ArKCa::LineSegment<float> >& getLightBorderList()
	{
		return lightBorderList;
	}
};

#endif
