#pragma execution_character_set("utf-8")

#include "cardController/CardControllerExplore.h"

CardControllerExplore* CardControllerExplore::Instance()
{
	static CardControllerExplore instance;
	return &instance;
}

CardControllerExplore::~CardControllerExplore()
{
}