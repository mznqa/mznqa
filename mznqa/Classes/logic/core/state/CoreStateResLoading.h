/*!
 * \file	Classes\logic\core\state\CoreStateResLoading.h
 *
 * \brief	定义类 CoreStateResLoading
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
 * \brief	[单例]核心状态，用于处理资源载入
 *
 */
class CoreStateResLoading : public ArKCa::State<CoreController>
{
private:
	// 单例别名 //////////////////////////////////////////////////////////////////////////
	/*! \brief	BridgeInstance 单例别名 */
	Bridge *const BridgeInstance = Bridge::Instance();
	//////////////////////////////////////////////////////////////////////////

	/*!
	 * \fn	CoreStateResLoading::CoreStateResLoading();
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	CoreStateResLoading();

	/*!
	 * \fn	CoreStateResLoading::CoreStateResLoading(const CoreStateResLoading &coreStateResLoading);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 */
	CoreStateResLoading(const CoreStateResLoading &coreStateResLoading);

	/*!
	 * \fn	CoreStateResLoading& CoreStateResLoading::operator=(const CoreStateResLoading &coreStateResLoading);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 */
	CoreStateResLoading& operator=(const CoreStateResLoading &coreStateResLoading);
public:

	/*!
	 * \fn	CoreStateResLoading::~CoreStateResLoading();
	 *
	 * \brief	析构函数
	 *
	 */
	~CoreStateResLoading();

	/*!
	 * \fn	static CoreStateResLoading* CoreStateResLoading::Instance();
	 *
	 * \brief	获取单例
	 *
	 */
	static CoreStateResLoading* Instance();

	/*!
	 * \fn	bool CoreStateResLoading::enter(CoreController *owner) override;
	 *
	 * \brief	进入状态时的操作
	 *
	 * \param [in,out]	owner	指定状态的所有者
	 *
	 * \return	返回执行成功与否
	 */
	bool enter(CoreController *owner) override;

	/*!
	 * \fn	bool CoreStateResLoading::update(CoreController *owner, double intervalTime) override;
	 *
	 * \brief	执行状态
	 *
	 * \param [in,out]	owner	指定状态的所有者
	 * \param	intervalTime 	自上次操作以来所经历的时间
	 *
	 * \return	返回执行成功与否
	 */
	bool update(CoreController *owner, double intervalTime) override;

	/*!
	 * \fn	bool CoreStateResLoading::exit(CoreController *owner) override;
	 *
	 * \brief	离开状态时的操作
	 *
	 * \param [in,out]	owner	指定状态的所有者
	 *
	 * \return	返回执行成功与否
	 */

	bool exit(CoreController *owner) override;
};

#endif
