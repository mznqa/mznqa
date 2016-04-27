#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CORESTATEMACHINE_CORESTATEMACHINE_H_
#define MZNQA_CLASSES_CORESTATEMACHINE_CORESTATEMACHINE_H_

#include <typeinfo>

#include "coreStateMachine/BaseState.h"

template <typename Entity>
class CoreStateMachine
{
private:
	CoreStateMachine(const CoreStateMachine &coreStateMachine);
	CoreStateMachine& operator=(const CoreStateMachine &coreStateMachine);

	Entity *owner;

	BaseState<Entity> *globalState;
	BaseState<Entity> *currentState;
	BaseState<Entity> *previousState;

	// 标识全局状态的暂停与否
	bool isGlobalStatePause = false;
	// 标识当前状态的暂停与否
	bool isCurrentStatePause = false;

	bool setPreviousState(BaseState<Entity> *state)
	{
		if (state == nullptr)
			return false;
		previousState = state;
		return true;
	}

public:
	CoreStateMachine(Entity* owner) :
		owner(owner),
		globalState(nullptr),
		currentState(nullptr),
		previousState(nullptr)
	{
	}

	~CoreStateMachine()
	{
		owner = nullptr;
		globalState = nullptr;
		currentState = nullptr;
		previousState = nullptr;
	}

	void update()
	{
		if (globalState != nullptr && isGlobalStatePause == false)
			globalState->update(owner);

		if (currentState != nullptr && isCurrentStatePause == false)
			currentState->update(owner);
	}

	bool setGlobalState(BaseState<Entity> *state)
	{
		if (state == nullptr)
			return false;

		if (globalState != nullptr)
			return false;

		globalState = state;
		return true;
	}

	bool setCurrentState(BaseState<Entity> *state)
	{
		if (state == nullptr)
			return false;

		if (currentState != nullptr)
			return false;

		currentState = state;
		return true;
	}

	bool isGlobalState(BaseState<Entity> *state)
	{
		if (globalState == nullptr && state == nullptr)
			return true;
		else if (globalState == nullptr)
			return false;
		else if (state == nullptr)
			return false;

		return (typeid(*globalState) == typeid(*state));
	}

	bool isCurrentState(BaseState<Entity> *state)
	{
		if (currentState == nullptr && state == nullptr)
			return true;
		else if (currentState == nullptr)
			return false;
		else if (state == nullptr)
			return false;

		return (typeid(*currentState) == typeid(*state));
	}

	bool isPreviousState(BaseState<Entity> *state)
	{
		if (previousState == nullptr && state == nullptr)
			return true;
		else if (previousState == nullptr)
			return false;
		else if (state == nullptr)
			return false;

		return (typeid(*previousState) == typeid(*state));
	}

	bool isGlobalStateActivated()
	{
		return (globalState != nullptr && isGlobalStatePause == false);
	}

	bool isCurrentStateActivated()
	{
		return (currentState != nullptr && isCurrentStatePause == false);
	}

	bool isGlobalStateNull()
	{
		return globalState == nullptr;
	}

	bool isCurrentStateNull()
	{
		return currentState == nullptr;
	}

	bool resumeGlobalState()
	{
		if (globalState == nullptr)
			return false;

		if (isGlobalStatePause == false)
			return false;

		isGlobalStatePause = false;
		return true;
	}

	bool pauseGlobalState()
	{
		if (globalState == nullptr)
			return false;

		if (isGlobalStatePause == true)
			return false;

		isGlobalStatePause = true;
		return true;
	}

	void stopGlobalState()
	{
		globalState = nullptr;
	}

	bool resumeCurrentState()
	{
		if (currentState == nullptr)
			return false;

		if (isCurrentStatePause == false)
			return false;

		isCurrentStatePause = false;
		return true;
	}

	bool pauseCurrentState()
	{
		if (currentState == nullptr)
			return false;

		if (isCurrentStatePause == true)
			return false;

		isCurrentStatePause = true;
		return true;
	}

	void stopCurrentState()
	{
		currentState = nullptr;
	}

	bool changeState(BaseState<Entity> *state)
	{
		if (currentState == nullptr)
			return false;

		if (isCurrentState(state))
			return false;

		previousState = currentState;
		currentState->exit(owner);
		currentState = state;
		currentState->enter(owner);
		return true;
	}

	bool revertToPrevious()
	{
		if (previousState == nullptr)
			return false;

		changeState(previousState);
		return true;
	}
};
#endif