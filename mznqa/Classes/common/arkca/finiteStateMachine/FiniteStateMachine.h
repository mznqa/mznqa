/*!
 * \file	Classes\common\arkca\finiteStateMachine\FiniteStateMachine.h
 *
 * \brief	定义类 ArKCa::FiniteStateMachine
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMMON_ARKCA_FINITESTATEMACHINE_FINITESTATEMACHINE_H_
#define MZNQA_CLASSES_COMMON_ARKCA_FINITESTATEMACHINE_FINITESTATEMACHINE_H_

#include <typeinfo>

#include "common/arkca/finiteStateMachine/State.h"

namespace ArKCa
{
	/*!
	 * \class	FiniteStateMachine
	 *
	 * \brief	有限状态机
	 *
	 *
	 * \tparam	Entity	该状态机的持有者类型
	 */
	template<typename Entity>
	class FiniteStateMachine
	{
	private:

		/*!
		 * \fn	FiniteStateMachine::FiniteStateMachine();
		 *
		 * \brief	隐藏的默认构造函数
		 *
		 */
		FiniteStateMachine();

		/*! \brief	指向状态机的持有者 */
		Entity *owner;

		/*! \brief	指向全局状态 */
		State<Entity> *globalState;
		/*! \brief	指向当前的状态 */
		State<Entity> *currentState;
		/*! \brief	指向上一个的状态 */
		State<Entity> *previousState;

		/*! \brief	标识全局状态暂停与否 */
		bool isGlobalStatePaused = false;
		/*! \brief	标识当前状态暂停与否 */
		bool isCurrentStatePaused = false;

		/*!
		 * \fn	void FiniteStateMachine::setPreviousState(State<Entity> *state)
		 *
		 * \brief	设置上一个状态
		 *
		 * \param [in,out]	state	指定一个状态
		 *
		 */
		void setPreviousState(State<Entity> *state)
		{
			previousState = state;
		}
	public:
		/*!
		 * \fn	FiniteStateMachine::FiniteStateMachine(Entity *owner)
		 *
		 * \brief	默认构造函数
		 *
		 * \param [in,out]	owner	指定该状态机的持有者
		 */
		FiniteStateMachine(Entity *owner) :
			owner(owner),
			globalState(nullptr),
			currentState(nullptr),
			previousState(nullptr)
		{
		}

		/*!
		 * \fn	FiniteStateMachine::FiniteStateMachine(const FiniteStateMachine &finiteStateMachine)
		 *
		 * \brief	拷贝构造函数
		 *
		 */
		FiniteStateMachine(const FiniteStateMachine &finiteStateMachine) :
			owner(finiteStateMachine.owner),
			globalState(finiteStateMachine.globalState),
			currentState(finiteStateMachine.currentState),
			previousState(finiteStateMachine.previousState)
		{
		}

		/*!
		 * \fn	FiniteStateMachine& FiniteStateMachine::operator=(const FiniteStateMachine &finiteStateMachine) :
		 *
		 * \brief	拷贝赋值运算符
		 *
		 */
		FiniteStateMachine& operator=(const FiniteStateMachine &finiteStateMachine)
		{
			owner = finiteStateMachine.owner;
			globalState = finiteStateMachine.globalState;
			currentState = finiteStateMachine.currentState;
			previousState = finiteStateMachine.currentState;
			return *this;
		}

		/*!
		 * \fn	FiniteStateMachine::~FiniteStateMachine()
		 *
		 * \brief	析构函数。
		 *
		 */
		~FiniteStateMachine()
		{
			// 以下四个指针均置为空指针，而不应在此释放其所指对象
			owner = nullptr;
			globalState = nullptr;
			currentState = nullptr;
			previousState = nullptr;
		}

		/*!
		 * \fn	bool FiniteStateMachine::update(double intervalTime)
		 *
		 * \brief	执行状态机
		 *
		 * \return	返回执行成功与否
		 *
		 */
		bool update(double intervalTime)
		{
			bool result = true;
			if (globalState != nullptr && isGlobalStatePaused == false)
				result = globalState->update(owner, intervalTime);

			if (currentState != nullptr && isCurrentStatePaused == false)
				result = currentState->update(owner, intervalTime);

			return result;
		}

		/*!
		 * \fn	void FiniteStateMachine::setGlobalState(State<Entity> *state)
		 *
		 * \brief	设置全局状态
		 *
		 * \param [in,out]	state	指定一个状态
		 *
		 */
		void setGlobalState(State<Entity> *state)
		{
			globalState = state;
		}

		/*!
		 * \fn	void FiniteStateMachine::setCurrentState(State<Entity> *state)
		 *
		 * \brief	设置当前状态
		 *
		 * \param [in,out]	state	指定一个状态
		 *
		 */
		void setCurrentState(State<Entity> *state)
		{
			currentState = state;
		}

		/*!
		 * \fn	bool FiniteStateMachine::isGlobalState(State<Entity> *state)
		 *
		 * \brief	判断当前的全局状态是否为参数提供的状态
		 *
		 * \param [in,out]	state	指定用于判断的状态
		 *
		 */
		bool isGlobalState(State<Entity> *state)
		{
			if (globalState == nullptr && state == nullptr)
				return true;
			else if (globalState == nullptr)
				return false;
			else if (state == nullptr)
				return false;

			return (typeid(*globalState) == typeid(*state));
		}
		/*!
		 * \fn	bool FiniteStateMachine::isCurrentState(State<Entity> *state)
		 *
		 * \brief	判断当前状态是否为参数提供的状态
		 *
		 * \param [in,out]	state	指定用于判断的状态
		 *
		 */
		bool isCurrentState(State<Entity> *state)
		{
			if (currentState == nullptr && state == nullptr)
				return true;
			else if (currentState == nullptr)
				return false;
			else if (state == nullptr)
				return false;

			return (typeid(*currentState) == typeid(*state));
		}
		/*!
		 * \fn	bool FiniteStateMachine::isPreviousState(State<Entity> *state)
		 *
		 * \brief	判断当前FSM的上一个状态是否为参数提供的状态
		 *
		 * \param [in,out]	state	指定一个用于判断的状态
		 *
		 */
		bool isPreviousState(State<Entity> *state)
		{
			if (previousState == nullptr && state == nullptr)
				return true;
			else if (previousState == nullptr)
				return false;
			else if (state == nullptr)
				return false;

			return (typeid(*previousState) == typeid(*state));
		}

		/*!
		 * \fn	bool FiniteStateMachine::isGlobalStateActivated()
		 *
		 * \brief	判断全局状态是否激活
		 *
		 */
		bool isGlobalStateActivated()
		{
			return (isGlobalStatePaused == false);
		}

		/*!
		 * \fn	bool FiniteStateMachine::isCurrentStateActivated()
		 *
		 * \brief	判断当前状态是否激活
		 *
		 */
		bool isCurrentStateActivated()
		{
			return (isCurrentStatePaused == false);
		}

		/*!
		 * \fn	bool FiniteStateMachine::isGlobalStateNull()
		 *
		 * \brief	判断全局状态是否为空
		 *
		 */
		bool isGlobalStateNull()
		{
			return globalState == nullptr;
		}

		/*!
		 * \fn	bool FiniteStateMachine::isCurrentStateNull()
		 *
		 * \brief	判断当前状态是否为空
		 *
		 */
		bool isCurrentStateNull()
		{
			return currentState == nullptr;
		}

		/*!
		 * \fn	void FiniteStateMachine::resumeGlobalState()
		 *
		 * \brief	恢复全局状态为
		 *
		 */
		void resumeGlobalState()
		{
			isGlobalStatePaused = false;
		}

		/*!
		 * \fn	void FiniteStateMachine::pauseGlobalState()
		 *
		 * \brief	暂停全局状态
		 *
		 */
		void pauseGlobalState()
		{
			isGlobalStatePaused = true;
		}

		/*!
		 * \fn	void FiniteStateMachine::stopGlobalState()
		 *
		 * \brief	撤销全局状态
		 *
		 */
		void stopGlobalState()
		{
			globalState = nullptr;
		}

		/*!
		 * \fn	void FiniteStateMachine::resumeCurrentState()
		 *
		 * \brief	恢复当前状态
		 *
		 */
		void resumeCurrentState()
		{
			isCurrentStatePaused = false;
		}

		/*!
		 * \fn	void FiniteStateMachine::pauseCurrentState()
		 *
		 * \brief	暂停当前状态
		 *
		 */
		void pauseCurrentState()
		{
			isCurrentStatePaused = true;
		}

		/*!
		 * \fn	void FiniteStateMachine::stopCurrentState()
		 *
		 * \brief	撤销当前状态
		 *
		 */
		void stopCurrentState()
		{
			currentState = nullptr;
		}

		/*!
		 * \fn	void FiniteStateMachine::changeState(State<Entity> *state)
		 *
		 * \brief	更改当前状态
		 *
		 * \param [in,out]	state	指定一个状态用于更改当前状态
		 *
		 */
		void changeState(State<Entity> *state)
		{
			previousState = currentState;
			if (currentState != nullptr)
				currentState->exit(owner);
			currentState = state;
			if (currentState != nullptr)
				currentState->enter(owner);
		}

		/*!
		 * \fn	void FiniteStateMachine::revertToPrevious()
		 *
		 * \brief	返回上一个状态
		 *
		 */
		void revertToPrevious()
		{
			changeState(previousState);
		}
	};
}

#endif
