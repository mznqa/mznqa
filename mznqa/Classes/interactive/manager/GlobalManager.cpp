/*!
 * \file	Classes\interactive\manager\GlobalManager.cpp
 *
 * \brief	������ GlobalManager
 */

#pragma execution_character_set("utf-8")

#include "interactive/manager/GlobalManager.h"

GlobalManager* GlobalManager::Instance()
{
	static GlobalManager instance;
	return &instance;
}