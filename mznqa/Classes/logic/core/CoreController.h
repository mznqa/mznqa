/*!
 * \file	Classes\logic\core\CoreController.h
 *
 * \brief	������ CoreController
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_CORE_CORECONTROLLER_H_
#define MZNQA_CLASSES_LOGIC_CORE_CORECONTROLLER_H_

#include "common/arkca/finiteStateMachine/FiniteStateMachine.h"

/*!
 * \class	CoreController
 *
 * \brief	[����]������Ϸ�߼��ĺ��Ŀ�����
 *
 */
class CoreController
{
private:

	/*!
	 * \fn	CoreController::CoreController();
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	CoreController();

	/*!
	 * \fn	CoreController::CoreController(const CoreController &coreController);
	 *
	 * \brief	���صĿ������캯��
	 *
	 */
	CoreController(const CoreController &coreController);

	/*!
	 * \fn	CoreController& CoreController::operator=(const CoreController &coreController);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	CoreController& operator=(const CoreController &coreController);

	/*! \brief	����״̬�� */
	ArKCa::FiniteStateMachine<CoreController> fSM;
public:

	/*!
	 * \fn	CoreController::~CoreController();
	 *
	 * \brief	��������
	 *
	 */
	~CoreController();

	/*!
	 * \fn	static CoreController* CoreController::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 */
	static CoreController* Instance();

	/*!
	 * \fn	bool CoreController::update(double intervalTime);
	 *
	 * \brief	���������������ĸ��º���
	 *
	 * \param	intervalTime	���ϴβ���������������ʱ��
	 *
	 * \return	����ִ�гɹ����
	 */
	bool update(double intervalTime);
};

#endif
