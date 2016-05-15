/*!
* \file		Classes\logic\core\state\CoreStateGameMain.h
*
* \brief	定义类 CoreStateGameMain
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
* \brief	[单例]核心状态，游戏主状态
*
*/
class CoreStateGameMain : public ArKCa::State<CoreController>
{
private:
	// 单例别名 //////////////////////////////////////////////////////////////////////////
	/*! \brief	BridgeInstance 单例别名 */
	Bridge *const BridgeInstance = Bridge::Instance();
	/*! \brief	LogicMessagePQ 单例别名 */
	LogicMessagePQ *const LogicMessagePQInstance = LogicMessagePQ::Instance();
	/*! \brief	MapController 单例别名 */
	MapController *const MapControllerInstance = MapController::Instance();
	//////////////////////////////////////////////////////////////////////////

	/*!
	* \fn	CoreStateGameMain::CoreStateGameMain();
	*
	* \brief	隐藏的构造函数
	*
	*/
	CoreStateGameMain();

	/*!
	* \fn	CoreStateGameMain::CoreStateGameMain(const CoreStateGameMain &coreStateGameMain);
	*
	* \brief	隐藏的拷贝构造函数
	*
	*/
	CoreStateGameMain(const CoreStateGameMain &coreStateGameMain);

	/*!
	* \fn	CoreStateGameMain& CoreStateGameMain::operator=(const CoreStateGameMain &coreStateGameMain);
	*
	* \brief	隐藏的拷贝赋值运算符
	*
	*/
	CoreStateGameMain& operator=(const CoreStateGameMain &coreStateGameMain);
public:

	/*!
	* \fn	CoreStateGameMain::~CoreStateGameMain();
	*
	* \brief	析构函数
	*
	*/
	~CoreStateGameMain();

	/*!
	* \fn	static CoreStateGameMain* CoreStateGameMain::Instance();
	*
	* \brief	获取单例
	*
	*/
	static CoreStateGameMain* Instance();

	/*!
	* \fn	bool CoreStateGameMain::enter(CoreController *owner) override;
	*
	* \brief	进入状态时的操作
	*
	* \param [in,out]	owner	指定状态所有者
	*
	* \return	返回执行成功与否
	*/
	bool enter(CoreController *owner) override;

	/*!
	* \fn	bool CoreStateGameMain::update(CoreController *owner, double intervalTime) override;
	*
	* \brief	执行状态
	*
	* \param [in,out]	owner	指定状态的所有者
	* \param	intervalTime 	自上次操作依赖所经历的时间
	*
	* \return	返回执行成功与否
	*/
	bool update(CoreController *owner, double intervalTime) override;

	/*!
	* \fn	bool CoreStateGameMain::exit(CoreController *owner) override;
	*
	* \brief	离开状态是的操作
	*
	* \param [in,out]	owner	指定状态的所有者
	*
	* \return	返回执行成功与否
	*/
	bool exit(CoreController *owner) override;
};

#endif
