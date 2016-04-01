/*!
 * \file	Classes\card\CardBase.cpp
 *
 * \brief	定义类 CardBase
 */

#pragma execution_character_set("utf-8")

#include "card/CardBase.h"

CardBase::CardBase(
	int id,
	CardType type,
	const std::string &name,
	const std::string &describe,
	BelongTo belongTo
	) :
	id(id),
	type(type),
	name(name),
	describe(describe),
	belongTo(belongTo)
{
	// 如果指定的id无效或指定的卡牌类型无效
	if (judgeCardTypeByID(id) == CardType_Invalid || checkCardType(type) == false)
	{
		id = invalidID;
		this->type = CardType_Invalid;
		cocos2d::log("[warning] 构造卡牌时有不确定行为，给定id为%d,type为CardType_Invalid，此时将被声明为无效卡,请确定是否为有意行为", id);
		return;
	}

	// 如果id和类型不符
	if (judgeCardTypeByID(id) != type)
	{
		id = -1;
		type = CardType_Invalid;
		cocos2d::log("[warning] 构造卡牌失败，给定的id与给定卡牌类型不符，id=%d，type=%d", id, type);
		return;
	}

	// 如果卡牌所属对象不合法
	if (
		belongTo != BelongTo_MonsterOnly &&
		belongTo != BelongTo_RoleMonsterBoth &&
		belongTo != BelongTo_RoleOnly
		)
	{
		id = -1;
		type = CardType_Invalid;
		cocos2d::log("[warning] 构造卡牌失败，给定的卡牌所属对象不合法（%d），将被修改为默认值0", belongTo);
		belongTo = BelongTo_RoleMonsterBoth;
		return;
	}

	cocos2d::log("[information] 成功创建一张卡牌，id=%d，type=%d", id, type);
}