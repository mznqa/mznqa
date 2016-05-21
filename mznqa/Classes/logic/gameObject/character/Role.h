/*!
 * \file	Classes\logic\gameObject\character\Role.h
 *
 * \brief	������ Role
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_CHARACTER_ROLE_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_CHARACTER_ROLE_H_

#include "logic/gameObject/cardController/CardControllerExplore.h"

/*!
 * \class	Role
 *
 * \brief	��Ϸ���󣺽�ɫ
 *
 */
class Role
{
private:
	/*! \brief	̽�������µĿ��ƿ����� */
	CardControllerExplore cardControllerExplore;

public:

	/*!
	 * \fn	Role::Role()
	 *
	 * \brief	���캯��
	 *
	 */
	Role() :
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
