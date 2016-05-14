/*!
 * \file	Classes\logic\core\state\CoreStateResLoading.h
 *
 * \brief	������ CoreStateResLoading
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_CORE_STATE_CORESTATERESLOADING_H_
#define MZNQA_CLASSES_LOGIC_CORE_STATE_CORESTATERESLOADING_H_

#include "common/arkca/finiteStateMachine/State.h"
#include "logic/core/CoreController.h"
#include "helper/bridge/Bridge.h"

/*!
 * \class	CoreStateResLoading
 *
 * \brief	[����]����״̬�����ڴ�����Դ����
 *
 */
class CoreStateResLoading : public ArKCa::State<CoreController>
{
private:
	// �������� //////////////////////////////////////////////////////////////////////////
	/*! \brief	BridgeInstance �������� */
	Bridge *const BridgeInstance = Bridge::Instance();
	//////////////////////////////////////////////////////////////////////////

	/*!
	 * \fn	CoreStateResLoading::CoreStateResLoading();
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	CoreStateResLoading();

	/*!
	 * \fn	CoreStateResLoading::CoreStateResLoading(const CoreStateResLoading &coreStateResLoading);
	 *
	 * \brief	���صĿ������캯��
	 *
	 */
	CoreStateResLoading(const CoreStateResLoading &coreStateResLoading);

	/*!
	 * \fn	CoreStateResLoading& CoreStateResLoading::operator=(const CoreStateResLoading &coreStateResLoading);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	CoreStateResLoading& operator=(const CoreStateResLoading &coreStateResLoading);
public:

	/*!
	 * \fn	CoreStateResLoading::~CoreStateResLoading();
	 *
	 * \brief	��������
	 *
	 */
	~CoreStateResLoading();

	/*!
	 * \fn	static CoreStateResLoading* CoreStateResLoading::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 */
	static CoreStateResLoading* Instance();

	/*!
	 * \fn	bool CoreStateResLoading::enter(CoreController *owner) override;
	 *
	 * \brief	����״̬ʱ�Ĳ���
	 *
	 * \param [in,out]	owner	ָ��״̬��������
	 *
	 * \return	����ִ�гɹ����
	 */
	bool enter(CoreController *owner) override;

	/*!
	 * \fn	bool CoreStateResLoading::update(CoreController *owner, double intervalTime) override;
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
	 * \fn	bool CoreStateResLoading::exit(CoreController *owner) override;
	 *
	 * \brief	�뿪״̬ʱ�Ĳ���
	 *
	 * \param [in,out]	owner	ָ��״̬��������
	 *
	 * \return	����ִ�гɹ����
	 */

	bool exit(CoreController *owner) override;
};

#endif
