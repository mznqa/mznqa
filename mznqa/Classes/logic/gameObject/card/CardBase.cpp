/*!
 * \file	Classes\logic\gameObject\card\CardBase.cpp
 *
 * \brief	¶¨ÒåÀà CardBase
 */
#pragma execution_character_set("utf-8")

#include "logic/gameObject/card/CardBase.h"

#include "logic/data/static/StringSet/StringSet.h"

const std::string *const CardBase::getName()const
{
	return StringSet::Instance()->getString((StringSet::StringID)sidName);
}

const std::string *const CardBase::getDescribe()const
{
	return StringSet::Instance()->getString((StringSet::StringID)sidName);
}