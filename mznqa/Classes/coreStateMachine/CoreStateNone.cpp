#pragma execution_character_set("utf-8")

#include "coreStateMachine/CoreStateNone.h"

bool CoreStateNone::enter(SceneGameMain *owner)
{
	return true;
}

bool CoreStateNone::update(SceneGameMain *owner, double intervalTime)
{
	return true;
}

bool CoreStateNone::exit(SceneGameMain *owner)
{
	return true;
}