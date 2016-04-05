/*!
 * \file	Classes\card\CardRoad.cpp
 *
 * \brief	定义类 CardRoad
 */
#pragma execution_character_set("utf-8")

#include "card/CardRoad.h"

CardRoad::CardRoad(
	int id,
	const std::string &name,
	const std::string describe,
	CardBase::BelongTo belongTo,
	RoadType roadType
	) :
	CardBase(
	id,
	CARDTYPE,
	name,
	describe,
	belongTo
	),
	roadType(roadType)
{
	if (
		roadType == RoadType_URDL ||
		roadType == RoadType_RDL ||
		roadType == RoadType_UDL ||
		roadType == RoadType_URL ||
		roadType == RoadType_URD ||
		roadType == RoadType_DL ||
		roadType == RoadType_UL ||
		roadType == RoadType_UR ||
		roadType == RoadType_RL ||
		roadType == RoadType_UD ||
		roadType == RoadType_RD ||
		roadType == RoadType_U ||
		roadType == RoadType_R ||
		roadType == RoadType_D ||
		roadType == RoadType_L
		)
	{
		return;
	}
	else
	{
		id = CardBase::invalidID;
		this->name = "";
		this->describe = "";

		cocos2d::log("[warning] 指定的 RoadType = %d 不合法，将被指定为 RoadType_None，请确认是否为有意行为", roadType);
		roadType = RoadType_None;
	}
}