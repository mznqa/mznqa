/*!
* \file		Classes\logic\core\state\CoreStateGameMain.h
*
* \brief	������ CoreStateGameMain
*/

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_CORE_STATE_CORESTATEGAMEMAIN_H_
#define MZNQA_CLASSES_LOGIC_CORE_STATE_CORESTATEGAMEMAIN_H_

#include "common/arkca/finiteStateMachine/State.h"
#include "logic/core/CoreController.h"
#include "helper/bridge/Bridge.h"
#include "logic/message/LogicMessagePQ.h"
#include "logic/controller/MapController.h"

/*!
* \class	CoreStateGameMain
*
* \brief	[����]����״̬����Ϸ��״̬
*
*/
class CoreStateGameMain : public ArKCa::State<CoreController>
{
private:
	// �������� //////////////////////////////////////////////////////////////////////////
	/*! \brief	BridgeInstance �������� */
	Bridge *const BridgeInstance = Bridge::Instance();
	/*! \brief	LogicMessagePQ �������� */
	LogicMessagePQ *const LogicMessagePQInstance = LogicMessagePQ::Instance();
	/*! \brief	MapController �������� */
	MapController *const MapControllerInstance = MapController::Instance();
	//////////////////////////////////////////////////////////////////////////

	/*!
	* \fn	CoreStateGameMain::CoreStateGameMain();
	*
	* \brief	���صĹ��캯��
	*
	*/
	CoreStateGameMain();

	/*!
	* \fn	CoreStateGameMain::CoreStateGameMain(const CoreStateGameMain &coreStateGameMain);
	*
	* \brief	���صĿ������캯��
	*
	*/
	CoreStateGameMain(const CoreStateGameMain &coreStateGameMain);

	/*!
	* \fn	CoreStateGameMain& CoreStateGameMain::operator=(const CoreStateGameMain &coreStateGameMain);
	*
	* \brief	���صĿ�����ֵ�����
	*
	*/
	CoreStateGameMain& operator=(const CoreStateGameMain &coreStateGameMain);
public:

	/*!
	* \fn	CoreStateGameMain::~CoreStateGameMain();
	*
	* \brief	��������
	*
	*/
	~CoreStateGameMain();

	/*!
	* \fn	static CoreStateGameMain* CoreStateGameMain::Instance();
	*
	* \brief	��ȡ����
	*
	*/
	static CoreStateGameMain* Instance();

	/*!
	* \fn	bool CoreStateGameMain::enter(CoreController *owner) override;
	*
	* \brief	����״̬ʱ�Ĳ���
	*
	* \param [in,out]	owner	ָ��״̬������
	*
	* \return	����ִ�гɹ����
	*/
	bool enter(CoreController *owner) override;

	/*!
	* \fn	bool CoreStateGameMain::update(CoreController *owner, double intervalTime) override;
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
	* \fn	bool CoreStateGameMain::exit(CoreController *owner) override;
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
