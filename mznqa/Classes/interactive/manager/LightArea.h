/*!
 * \file	Classes\interactive\manager\LightArea.h
 *
 * \brief	������ LightArea
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
 * \brief	��������
 *
 */
class LightArea
{
private:

	/*!
	 * \fn	LightArea::LightArea(const LightArea &lightArea);
	 *
	 * \brief	���صĿ������캯��
	 *
	 * \param	lightArea	The light area.
	 */
	LightArea(const LightArea &lightArea);

	/*!
	 * \fn	LightArea& LightArea::operator=(const LightArea &lightArea);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	LightArea& operator=(const LightArea &lightArea);

	/*! \brief	��Դ���� */
	ArKCa::Vector2<int> lightPosition;
	/*! \brief	���߰뾶 */
	int lightScopeRadius;
	/*! \brief	�������������нڵ���Թ�Դ������ */
	std::vector<ArKCa::Vector2<int>> lightScope;
	/*! \brief	��������߽缯�� */
	std::list<ArKCa::LineSegment<float>> lightBorderList;

	/*!
	 * \fn	bool LightArea::isWithinLightScope(const ArKCa::Vector2<int> &position);
	 *
	 * \brief	�ж�ָ���Ƿ��ڹ�����
	 *
	 * \param	position	ָ����ͼ����
	 *
	 */
	bool isWithinLightScope(const ArKCa::Vector2<int> &position);

	/*!
	 * \fn	void LightArea::buildLightScope();
	 *
	 * \brief	������������
	 *
	 */
	void buildLightScope();

	/*!
	 * \fn	void LightArea::buildLightBorderList();
	 *
	 * \brief	�������߽߱�
	 *
	 */
	void buildLightBorderList();
public:

	/*!
	 * \fn	LightArea::LightArea()
	 *
	 * \brief	���캯��
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
	 * \brief	���캯��
	 *
	 * \param	lightPosition		ָ����Դ����
	 * \param	lightScopeRadius	ָ�����߰뾶
	 */
	LightArea(
		const ArKCa::Vector2<int> &lightPosition,
		int lightScopeRadius
		);

	/*!
	 * \fn	LightArea::~LightArea()
	 *
	 * \brief	��������
	 *
	 */
	~LightArea()
	{
	}

	/*!
	 * \fn	const ArKCa::Vector2<int>& LightArea::getLightMapPosition()
	 *
	 * \brief	��ȡ��Դ�ĵ�ͼ����
	 *
	 */
	const ArKCa::Vector2<int>& getLightMapPosition()
	{
		return lightPosition;
	}

	/*!
	 * \fn	void LightArea::setLightPosition(const ArKCa::Vector2<int> &lightPosition);
	 *
	 * \brief	���ù�Դ����
	 *
	 * \param	lightPosition	ָ����Դ�ĵ�ͼ����
	 */
	void setLightPosition(const ArKCa::Vector2<int> &lightPosition);

	/*!
	 * \fn	void LightArea::setLightScopeRadius(int lightScopeRadius);
	 *
	 * \brief	���ù�������İ뾶��С
	 *
	 * \param	lightScopeRadius	ָ����������İ뾶
	 */
	void setLightScopeRadius(int lightScopeRadius);

	/*!
	 * \fn	const std::list<ArKCa::LineSegment<float> >& LightArea::getLightBorderList()
	 *
	 * \brief	��ȡ��������ı߽缯��
	 *
	 */
	const std::list<ArKCa::LineSegment<float> >& getLightBorderList()
	{
		return lightBorderList;
	}
};

#endif
