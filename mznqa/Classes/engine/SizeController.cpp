#pragma execution_character_set("utf-8")

#include "engine/SizeController.h"

SizeController* SizeController::Instance()
{
	static SizeController instance;
	return &instance;
}