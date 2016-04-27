#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CORESTATEMACHINE_BASESTATE_H_
#define MZNQA_CLASSES_CORESTATEMACHINE_BASESTATE_H_

template<typename Entity>
class BaseState
{
public:
	virtual ~BaseState(){};
	// ����״̬ǰ�Ĳ���
	virtual bool enter(Entity *owner) = 0;
	// ״ִ̬��ʱ�Ĳ���
	virtual bool update(Entity *owner, double intervalTime) = 0;
	// �뿪״̬ǰ�Ĳ���
	virtual bool exit(Entity *owner) = 0;
};

#endif