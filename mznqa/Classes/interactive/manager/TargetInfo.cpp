/*!
 * \file	Classes\interactive\manager\TargetInfo.cpp
 *
 * \brief	∂®“Â¿‡ TargetInfo
 */

#pragma execution_character_set("utf-8")

#include "interactive/manager/TargetInfo.h"

TargetInfo::TargetInfo()
{
}

TargetInfo::~TargetInfo()
{
}

TargetInfo* TargetInfo::Instance()
{
	static TargetInfo instance;
	return &instance;
}