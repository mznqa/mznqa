/*!
 * \file	Classes\logic\core\state\CoreStateGuide.h
 *
 * \brief	定义类 CoreStateGuide
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_CORE_STATE_CORESTATEGUIDE_H_
#define MZNQA_CLASSES_LOGIC_CORE_STATE_CORESTATEGUIDE_H_

#include "common/arkca/finiteStateMachine/State.h"
#include "logic/core/CoreController.h"

/*!
 * \class	CoreStateGuide
 *
 * \brief	[单例]核心状态，最为第一个载入的状态用于引导进入下一状态
 *
 */
class CoreStateGuide : public ArKCa::State<CoreController>
{
private:

	/*!
	 * \fn	CoreStateGuide::CoreStateGuide();
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	CoreStateGuide();

	/*!
	 * \fn	CoreStateGuide::CoreStateGuide(const CoreStateGuide &coreStateGuide);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 */
	CoreStateGuide(const CoreStateGuide &coreStateGuide);

	/*!
	 * \fn	CoreStateGuide& CoreStateGuide::operator=(const CoreStateGuide &coreStateGuide);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 */
	CoreStateGuide& operator=(const CoreStateGuide &coreStateGuide);
public:

	/*!
	 * \fn	CoreStateGuide::~CoreStateGuide();
	 *
	 * \brief	析构函数
	 *
	 */
	~CoreStateGuide();

	/*!
	 * \fn	static CoreStateGuide* CoreStateGuide::Instance();
	 *
	 * \brief	获取单例
	 *
	 */
	static CoreStateGuide* Instance();

	/*!
	 * \fn	bool CoreStateGuide::enter(CoreController *owner) override;
	 *
	 * \brief	进入状态时的操作
	 *
	 * \param [in,out]	owner	指定状态所有者
	 *
	 * \return	返回执行成功与否
	 */
	bool enter(CoreController *owner) override;

	/*!
	 * \fn	bool CoreStateGuide::update(CoreController *owner, double intervalTime) override;
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
	 * \fn	bool CoreStateGuide::exit(CoreController *owner) override;
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
