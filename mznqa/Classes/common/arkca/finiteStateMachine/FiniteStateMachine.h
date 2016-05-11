/*!
 * \file	Classes\common\arkca\finiteStateMachine\FiniteStateMachine.h
 *
 * \brief	������ ArKCa::FiniteStateMachine
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
	 * \brief	����״̬��
	 *
	 *
	 * \tparam	Entity	��״̬���ĳ���������
	 */
	template<typename Entity>
	class FiniteStateMachine
	{
	private:

		/*!
		 * \fn	FiniteStateMachine::FiniteStateMachine();
		 *
		 * \brief	���ص�Ĭ�Ϲ��캯��
		 *
		 */
		FiniteStateMachine();

		/*! \brief	ָ��״̬���ĳ����� */
		Entity *owner;

		/*! \brief	ָ��ȫ��״̬ */
		State<Entity> *globalState;
		/*! \brief	ָ��ǰ��״̬ */
		State<Entity> *currentState;
		/*! \brief	ָ����һ����״̬ */
		State<Entity> *previousState;

		/*! \brief	��ʶȫ��״̬��ͣ��� */
		bool isGlobalStatePaused = false;
		/*! \brief	��ʶ��ǰ״̬��ͣ��� */
		bool isCurrentStatePaused = false;

		/*!
		 * \fn	void FiniteStateMachine::setPreviousState(State<Entity> *state)
		 *
		 * \brief	������һ��״̬
		 *
		 * \param [in,out]	state	ָ��һ��״̬
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
		 * \brief	Ĭ�Ϲ��캯��
		 *
		 * \param [in,out]	owner	ָ����״̬���ĳ�����
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
		 * \brief	�������캯��
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
		 * \brief	������ֵ�����
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
		 * \brief	����������
		 *
		 */
		~FiniteStateMachine()
		{
			// �����ĸ�ָ�����Ϊ��ָ�룬����Ӧ�ڴ��ͷ�����ָ����
			owner = nullptr;
			globalState = nullptr;
			currentState = nullptr;
			previousState = nullptr;
		}

		/*!
		 * \fn	bool FiniteStateMachine::update(double intervalTime)
		 *
		 * \brief	ִ��״̬��
		 *
		 * \return	����ִ�гɹ����
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
		 * \brief	����ȫ��״̬
		 *
		 * \param [in,out]	state	ָ��һ��״̬
		 *
		 */
		void setGlobalState(State<Entity> *state)
		{
			globalState = state;
		}

		/*!
		 * \fn	void FiniteStateMachine::setCurrentState(State<Entity> *state)
		 *
		 * \brief	���õ�ǰ״̬
		 *
		 * \param [in,out]	state	ָ��һ��״̬
		 *
		 */
		void setCurrentState(State<Entity> *state)
		{
			currentState = state;
		}

		/*!
		 * \fn	bool FiniteStateMachine::isGlobalState(State<Entity> *state)
		 *
		 * \brief	�жϵ�ǰ��ȫ��״̬�Ƿ�Ϊ�����ṩ��״̬
		 *
		 * \param [in,out]	state	ָ�������жϵ�״̬
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
		 * \brief	�жϵ�ǰ״̬�Ƿ�Ϊ�����ṩ��״̬
		 *
		 * \param [in,out]	state	ָ�������жϵ�״̬
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
		 * \brief	�жϵ�ǰFSM����һ��״̬�Ƿ�Ϊ�����ṩ��״̬
		 *
		 * \param [in,out]	state	ָ��һ�������жϵ�״̬
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
		 * \brief	�ж�ȫ��״̬�Ƿ񼤻�
		 *
		 */
		bool isGlobalStateActivated()
		{
			return (isGlobalStatePaused == false);
		}

		/*!
		 * \fn	bool FiniteStateMachine::isCurrentStateActivated()
		 *
		 * \brief	�жϵ�ǰ״̬�Ƿ񼤻�
		 *
		 */
		bool isCurrentStateActivated()
		{
			return (isCurrentStatePaused == false);
		}

		/*!
		 * \fn	bool FiniteStateMachine::isGlobalStateNull()
		 *
		 * \brief	�ж�ȫ��״̬�Ƿ�Ϊ��
		 *
		 */
		bool isGlobalStateNull()
		{
			return globalState == nullptr;
		}

		/*!
		 * \fn	bool FiniteStateMachine::isCurrentStateNull()
		 *
		 * \brief	�жϵ�ǰ״̬�Ƿ�Ϊ��
		 *
		 */
		bool isCurrentStateNull()
		{
			return currentState == nullptr;
		}

		/*!
		 * \fn	void FiniteStateMachine::resumeGlobalState()
		 *
		 * \brief	�ָ�ȫ��״̬Ϊ
		 *
		 */
		void resumeGlobalState()
		{
			isGlobalStatePaused = false;
		}

		/*!
		 * \fn	void FiniteStateMachine::pauseGlobalState()
		 *
		 * \brief	��ͣȫ��״̬
		 *
		 */
		void pauseGlobalState()
		{
			isGlobalStatePaused = true;
		}

		/*!
		 * \fn	void FiniteStateMachine::stopGlobalState()
		 *
		 * \brief	����ȫ��״̬
		 *
		 */
		void stopGlobalState()
		{
			globalState = nullptr;
		}

		/*!
		 * \fn	void FiniteStateMachine::resumeCurrentState()
		 *
		 * \brief	�ָ���ǰ״̬
		 *
		 */
		void resumeCurrentState()
		{
			isCurrentStatePaused = false;
		}

		/*!
		 * \fn	void FiniteStateMachine::pauseCurrentState()
		 *
		 * \brief	��ͣ��ǰ״̬
		 *
		 */
		void pauseCurrentState()
		{
			isCurrentStatePaused = true;
		}

		/*!
		 * \fn	void FiniteStateMachine::stopCurrentState()
		 *
		 * \brief	������ǰ״̬
		 *
		 */
		void stopCurrentState()
		{
			currentState = nullptr;
		}

		/*!
		 * \fn	void FiniteStateMachine::changeState(State<Entity> *state)
		 *
		 * \brief	���ĵ�ǰ״̬
		 *
		 * \param [in,out]	state	ָ��һ��״̬���ڸ��ĵ�ǰ״̬
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
		 * \brief	������һ��״̬
		 *
		 */
		void revertToPrevious()
		{
			changeState(previousState);
		}
	};
}

#endif
