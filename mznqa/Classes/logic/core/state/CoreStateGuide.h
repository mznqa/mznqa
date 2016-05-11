/*!
 * \file	Classes\logic\core\state\CoreStateGuide.h
 *
 * \brief	������ CoreStateGuide
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_CORE_STATE_CORESTATEGUIDE_H_
#define MZNQA_CLASSES_LOGIC_CORE_STATE_CORESTATEGUIDE_H_

#include "common/arkca/finiteStateMachine/State.h"
#include "logic/core/CoreController.h"

/*!
 * \class	CoreStateGuide
 *
 * \brief	[����]����״̬����Ϊ��һ�������״̬��������������һ״̬
 *
 */
class CoreStateGuide : public ArKCa::State<CoreController>
{
private:

	/*!
	 * \fn	CoreStateGuide::CoreStateGuide();
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	CoreStateGuide();

	/*!
	 * \fn	CoreStateGuide::CoreStateGuide(const CoreStateGuide &coreStateGuide);
	 *
	 * \brief	���صĿ������캯��
	 *
	 */
	CoreStateGuide(const CoreStateGuide &coreStateGuide);

	/*!
	 * \fn	CoreStateGuide& CoreStateGuide::operator=(const CoreStateGuide &coreStateGuide);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	CoreStateGuide& operator=(const CoreStateGuide &coreStateGuide);
public:

	/*!
	 * \fn	CoreStateGuide::~CoreStateGuide();
	 *
	 * \brief	��������
	 *
	 */
	~CoreStateGuide();

	/*!
	 * \fn	static CoreStateGuide* CoreStateGuide::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 */
	static CoreStateGuide* Instance();

	/*!
	 * \fn	bool CoreStateGuide::enter(CoreController *owner) override;
	 *
	 * \brief	����״̬ʱ�Ĳ���
	 *
	 * \param [in,out]	owner	ָ��״̬������
	 *
	 * \return	����ִ�гɹ����
	 */
	bool enter(CoreController *owner) override;

	/*!
	 * \fn	bool CoreStateGuide::update(CoreController *owner, double intervalTime) override;
	 *
	 * \brief	ִ��״̬
	 *
	 * \param [in,out]	owner	ָ��״̬��������
	 * \param	intervalTime 	���ϴβ���������������ʱ��
	 *
	 * \return	����ִ�гɹ����
	 */
	bool update(CoreController *owner, double intervalTime) override;

	/*!
	 * \fn	bool CoreStateGuide::exit(CoreController *owner) override;
	 *
	 * \brief	�뿪״̬�ǵĲ���
	 *
	 * \param [in,out]	owner	ָ��״̬��������
	 *
	 * \return	����ִ�гɹ����
	 */
	bool exit(CoreController *owner) override;
};

#endif
