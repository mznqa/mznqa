#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CORESTATEMACHINE_BASESTATE_H_
#define MZNQA_CLASSES_CORESTATEMACHINE_BASESTATE_H_

template<typename Entity>
class BaseState
{
public:
	virtual ~BaseState(){};
	// 进入状态前的操作
	virtual bool enter(Entity *owner) = 0;
	// 状态执行时的操作
	virtual bool update(Entity *owner, double intervalTime) = 0;
	// 离开状态前的操作
	virtual bool exit(Entity *owner) = 0;
};

#endif