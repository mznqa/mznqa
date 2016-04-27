#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CORESTATEMACHINE_STATE_CORESTATENONE_H_
#define MZNQA_CLASSES_CORESTATEMACHINE_STATE_CORESTATENONE_H_

#include "coreStateMachine/BaseState.h"
#include "engine/SceneGameMain.h"

class CoreStateNone : public BaseState<SceneGameMain>
{
private:
public:
	CoreStateNone()
	{
	}
	~CoreStateNone()
	{
	}

	bool enter(SceneGameMain *owner);
	bool update(SceneGameMain *owner, double intervalTime);
	bool exit(SceneGameMain *owner);
};

#endif
