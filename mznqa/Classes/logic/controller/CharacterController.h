/*!
 * \file	D:\Projects\mznqa\mznqa\Classes\logic\controller\CharacterController.h
 *
 * \brief	������ CharacterController
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_CONTROLLER_CHARACTERCONTROLLER_H_
#define MZNQA_CLASSES_LOGIC_CONTROLLER_CHARACTERCONTROLLER_H_

#include "logic/gameObject/character/Role.h"

/*!
 * \class	CharacterController
 *
 * \brief	��ɫ�����������ڿ�����Ϸ�еĽ�ɫ
 *
 */
class CharacterController
{
private:

	/*!
	 * \fn	CharacterController::CharacterController()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	CharacterController() :
		role(nullptr)
	{
	}

	/*!
	 * \fn	CharacterController::CharacterController(const CharacterController &characterController);
	 *
	 * \brief	���صĿ������캯��
	 *
	 */
	CharacterController(const CharacterController &characterController);

	/*!
	 * \fn	CharacterController& CharacterController::operator=(const CharacterController &characterController);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	CharacterController& operator=(const CharacterController &characterController);

	/*! \brief	��ɫʵ�� */
	Role *role;
public:

	/*!
	 * \fn	CharacterController::~CharacterController();
	 *
	 * \brief	��������
	 *
	 */
	~CharacterController();

	/*!
	 * \fn	static CharacterController* CharacterController::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 */
	static CharacterController* Instance();

	/*!
	 * \fn	void CharacterController::createRole();
	 *
	 * \brief	������ɫ
	 *
	 */
	void createRole();

	/*!
	 * \fn	Role* CharacterController::getRole();
	 *
	 * \brief	��ȡ��ɫ
	 *
	 */
	Role* getRole();
};

#endif
