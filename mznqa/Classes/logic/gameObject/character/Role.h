/*!
 * \file	Classes\logic\gameObject\character\Role.h
 *
 * \brief	������ Role
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_CHARACTER_ROLE_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_CHARACTER_ROLE_H_

#include "logic/gameObject/cardController/CardControllerExplore.h"
#include "common/arkca/Vector2.h"
#include "common/arkca/Rectangle.h"
#include "common/arkca/Direction.h"
#include "logic/controller/MapController.h"

/*!
 * \class	Role
 *
 * \brief	��Ϸ���󣺽�ɫ
 *
 */
class Role
{
private:
	/*! \brief	�ڵ�ͼ�е����� */
	ArKCa::Vector2<int> position;

	/*! \brief	��������ķ�Χ���� */
	ArKCa::Rectangle<int> positionRange;

	/*! \brief	̽�������µĿ��ƿ����� */
	CardControllerExplore cardControllerExplore;

public:

	/*!
	 * \fn	Role::Role( const ArKCa::Vector2<int> &position, const ArKCa::Rectangle<int> &positionRange )
	 *
	 * \brief	���캯��
	 *
	 * \param	position	 	ָ�����ڵ�λ��
	 * \param	positionRange	ָ�����������ֵ����
	 */
	Role(
		const ArKCa::Vector2<int> &position,
		const ArKCa::Rectangle<int> &positionRange
		) :
		position(position),
		positionRange(positionRange),
		cardControllerExplore()
	{
	}

	/*!
	 * \fn	Role::Role(const Role &role)
	 *
	 * \brief	�������캯��
	 *
	 */

	Role(const Role &role);

	/*!
	 * \fn	Role& Role::operator=(const Role &role);
	 *
	 * \brief	������ֵ�����
	 *
	 */
	Role& operator=(const Role &role);

	/*!
	 * \fn	Role::~Role()
	 *
	 * \brief	��������
	 *
	 */
	~Role()
	{
	}

	/*!
	 * \fn	void Role::setPosition(ArKCa::Vector2<int> position)
	 *
	 * \brief	���ý�ɫ��λ��
	 *
	 */
	void setPosition(ArKCa::Vector2<int> position)
	{
		if (positionRange.isContains(position))
			this->position = position;
	}

	/*!
	 * \fn	const ArKCa::Vector2<int>& Role::getPosition()const
	 *
	 * \brief	��ȡ��ɫ��λ��
	 *
	 */
	const ArKCa::Vector2<int>& getPosition()const
	{
		return position;
	}

	/*!
	 * \fn	bool Role::moveUp(int step = 1)
	 *
	 * \brief	�����ƶ���ɫ
	 *
	 * \param	step	ָ���ƶ��Ĳ�����Ĭ��Ϊ 1
	 *
	 * \return	�����Ƿ��ƶ��ɹ�
	 */
	bool moveUp(int step = 1)
	{
		if (step > 0 && positionRange.isContainsY(position.y - step))
		{
			if (MapController::Instance()->getMap().getNeighborCanThrough(
				position,
				ArKCa::Direction4::Direction4_Up
				))
			{
				this->position.y -= step;
				return true;
			}
		}
		return false;
	}

	/*!
	 * \fn	bool Role::moveDown(int step = 1)
	 *
	 * \brief	�����ƶ���ɫ
	 *
	 * \return	�����Ƿ��ƶ��ɹ�
	 */
	bool moveDown(int step = 1)
	{
		if (step > 0 && positionRange.isContainsY(position.y + step))
		{
			if (MapController::Instance()->getMap().getNeighborCanThrough(
				position,
				ArKCa::Direction4::Direction4_Down
				))
			{
				this->position.y += step;
				return true;
			}
		}
		return false;
	}

	/*!
	 * \fn	bool Role::moveLeft(int step = 1)
	 *
	 * \brief	�����ƶ���ɫ
	 *
	 * \return	�����Ƿ��ƶ��ɹ�
	 */
	bool moveLeft(int step = 1)
	{
		if (step > 0 && positionRange.isContainsX(position.x - step))
		{
			if (MapController::Instance()->getMap().getNeighborCanThrough(
				position,
				ArKCa::Direction4::Direction4_Left
				))
			{
				this->position.x -= step;
				return true;
			}
		}
		return false;
	}

	/*!
	 * \fn	bool Role::moveRight(int step = 1)
	 *
	 * \brief	�����ƶ���ɫ
	 *
	 * \return	�����Ƿ��ƶ��ɹ�
	 */
	bool moveRight(int step = 1)
	{
		if (step > 0 && positionRange.isContainsX(position.x + step))
		{
			if (MapController::Instance()->getMap().getNeighborCanThrough(
				position,
				ArKCa::Direction4::Direction4_Right
				))
			{
				this->position.x += step;
				return true;
			}
		}
		return false;
	}

	/*!
	 * \fn	bool Role::drawCard();
	 *
	 * \brief	����
	 *
	 * \return	���س����Ƿ�ɹ�
	 */
	bool drawCard();

	/*!
	 * \fn	CardControllerExplore& Role::getCardControllerExplore();
	 *
	 * \brief	��ȡ̽�������µĿ��ƿ���
	 *
	 */
	CardControllerExplore& getCardControllerExplore();
};

#endif
