#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARD_CARDBASE_H_
#define MZNQA_CLASSES_CARD_CARDBASE_H_

#include <string>

#include "cocos2d.h"

class CardBase
{
public:
	// 用以区分卡的类型
	// idBaseNum*0 ~ idBaseNum*1-1 ==> CardRoad
	// idBaseNum*1 ~ idBaseNum*2-1 ==> CardTreasure
	// idBaseNum*2 ~ idBaseNum*3-1 ==> CardMonster
	// idBaseNum*3 ~ idBaseNum*4-1 ==> CardSkill
	static const int idBaseNum = 1000;
public:
	static const int invalidID = -1;
	enum CardType
	{
		CardType_None = -1,
		CardType_Road = idBaseNum * 0,
		CardType_Treasure = idBaseNum * 1,
		CardType_Monster = idBaseNum * 2,
		CardType_Skill = idBaseNum * 3
	};

	// 枚举卡牌所属方
	enum BelongTo
	{
		BelongTo_RoleOnly = -1,
		BelongTo_RoleMonsterBoth = 0,
		BelongTo_MonsterOnly = 1
	};

	// 构造一张无效的卡，id=-1,type=CardType_None
	CardBase(
		int id,
		CardType type
		) :
		id(id),
		type(type),
		name(""),
		describe(""),
		belongTo(BelongTo_RoleMonsterBoth)
	{
		cocos2d::log("[warning] 生成一张空卡（即无效的卡:id=-1,type=CardType_None）成功");
	}

	// 根据给定id和type构造一张卡
	CardBase(
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
		if (id == -1 && type == CardType_None)
		{
			cocos2d::log("[warning] 构造卡牌时有不确定行为，给定id为%d,type为CardType_None，此时将被声明为空卡（即无效的卡:id=-1,type=CardType_None），请确定是否为有意行为", id);
			return;
		}

		if (id <= invalidID)
		{
			cocos2d::log("[warning] 构造卡牌失败，给定id(=%d)不合法，将被声明为空卡（即无效的卡:id=-1,type=CardType_None）", id);
			id = -1;
			type = CardType_None;
			return;
		}

		if (type < CardType_None)
		{
			cocos2d::log("[warning] 构造卡牌失败，给定type(=%d)不合法，将被声明为空卡（即无效的卡:id=-1,type=CardType_None）", type);
			id = -1;
			type = CardType_None;
			return;
		}

		if (!(type <= id && id < type + idBaseNum))
		{
			cocos2d::log("[warning] 构造卡牌失败，给定的id与给定卡牌类型不符，id=%d，type=%d", id, type);
			id = -1;
			type = CardType_None;
			return;
		}

		cocos2d::log("[information] 成功创建一张卡牌，id=%d，type=%d", id, type);
	}

	virtual ~CardBase()
	{
	}

	// 获取卡id
	virtual int getID() const
	{
		return id;
	}

	// 获取卡type
	virtual CardType getType() const
	{
		return type;
	}

	// 获取卡牌名称
	virtual const std::string& getName() const
	{
		return name;
	}

	// 获取卡牌描述
	virtual const std::string& getDescride() const
	{
		return describe;
	}

	// 获取卡牌所属
	virtual const BelongTo getBelongTo() const
	{
		return belongTo;
	}

protected:
	// 卡牌ID
	const int id;
	// 卡牌类型
	const CardType type;
	// 卡牌名称
	const std::string name;
	// 卡牌描述
	const std::string describe;
	// 卡牌所属
	const BelongTo belongTo;
};

#endif
