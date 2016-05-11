/*!
 * \file	Classes\logic\core\CoreController.h
 *
 * \brief	定义类 CoreController
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_CORE_CORECONTROLLER_H_
#define MZNQA_CLASSES_LOGIC_CORE_CORECONTROLLER_H_

#include "common/arkca/finiteStateMachine/FiniteStateMachine.h"

/*!
 * \class	CoreController
 *
 * \brief	[单例]处理游戏逻辑的核心控制器
 *
 */
class CoreController
{
private:

	/*!
	 * \fn	CoreController::CoreController();
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	CoreController();

	/*!
	 * \fn	CoreController::CoreController(const CoreController &coreController);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 */
	CoreController(const CoreController &coreController);

	/*!
	 * \fn	CoreController& CoreController::operator=(const CoreController &coreController);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 */
	CoreController& operator=(const CoreController &coreController);

	/*! \brief	有限状态机 */
	ArKCa::FiniteStateMachine<CoreController> fSM;
public:

	/*!
	 * \fn	CoreController::~CoreController();
	 *
	 * \brief	析构函数
	 *
	 */
	~CoreController();

	/*!
	 * \fn	static CoreController* CoreController::Instance();
	 *
	 * \brief	获取单例
	 *
	 */
	static CoreController* Instance();

	/*!
	 * \fn	bool CoreController::update(double intervalTime);
	 *
	 * \brief	用于驱动控制器的更新函数
	 *
	 * \param	intervalTime	自上次操作以来所经历的时间
	 *
	 * \return	返回执行成功与否
	 */
	bool update(double intervalTime);
};

#endif
