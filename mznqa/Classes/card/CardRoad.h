#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARD_CARDROAD_H_
#define MZNQA_CLASSES_CARD_CARDROAD_H_

#include "card/CardBase.h"

// 地形卡
class CardRoad : public CardBase
{
public:
	// 卡类型
	static CardBase::CardType CARDTYPE;
	// 地形类型枚举
	static enum RoadType
	{
		RoadType_None = 0,
		RoadType_URDL = 1234,
		RoadType_RDL = 234,
		RoadType_UDL = 134,
		RoadType_URL = 124,
		RoadType_URD = 123,
		RoadType_DL = 34,
		RoadType_UL = 14,
		RoadType_UR = 12,
		RoadType_RL = 24,
		RoadType_UD = 13,
		RoadType_RD = 23,
		RoadType_U = 1,
		RoadType_R = 2,
		RoadType_D = 3,
		RoadType_L = 4
	};

	CardRoad(int id, RoadType roadType) :
		CardBase(id, CARDTYPE),
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
			cocos2d::log("[warning] 指定的 RoadType = %d 不合法，将被指定为 RoadType_None，请确认是否为有意行为", roadType);
			roadType = RoadType_None;
		}
	}
	~CardRoad()
	{
	}

private:
	// 这些作为静态数据不应修改它们 //////////////////////////////////////////////////////////////////////////
	// 道路类型
	RoadType roadType;
	//////////////////////////////////////////////////////////////////////////
};

#endif
