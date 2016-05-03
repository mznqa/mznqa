#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_FINITESTATEMACHINE_STATE_H_
#define MZNQA_CLASSES_FINITESTATEMACHINE_STATE_H_

template <typename EntityType>
class State
{
public:

	/*!
	 * \fn	virtual State::~State()
	 *
	 * \brief	Îö¹¹º¯Êý
	 *
	 */
	virtual ~State(){}
	virtual void enter(EntityType*) = 0;

	//this is the states normal update function
	virtual void Execute(EntityType*, double intervalTime) = 0;

	//this will execute when the state is exited.
	virtual void Exit(EntityType*) = 0;

	//this executes if the agent receives a message from the
	//message dispatcher
	virtual bool OnMessage(EntityType*, const Telegram&) = 0;
};

#endif