#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARD_CARDBASE_H_
#define MZNQA_CLASSES_CARD_CARDBASE_H_

#include <string>

#include "cocos2d.h"

class CardBase
{
public:
	// �������ֿ�������
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

	// ö�ٿ���������
	enum BelongTo
	{
		BelongTo_RoleOnly = -1,
		BelongTo_RoleMonsterBoth = 0,
		BelongTo_MonsterOnly = 1
	};

	// ����һ����Ч�Ŀ���id=-1,type=CardType_None
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
		cocos2d::log("[warning] ����һ�ſտ�������Ч�Ŀ�:id=-1,type=CardType_None���ɹ�");
	}

	// ���ݸ���id��type����һ�ſ�
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
			cocos2d::log("[warning] ���쿨��ʱ�в�ȷ����Ϊ������idΪ%d,typeΪCardType_None����ʱ��������Ϊ�տ�������Ч�Ŀ�:id=-1,type=CardType_None������ȷ���Ƿ�Ϊ������Ϊ", id);
			return;
		}

		if (id <= invalidID)
		{
			cocos2d::log("[warning] ���쿨��ʧ�ܣ�����id(=%d)���Ϸ�����������Ϊ�տ�������Ч�Ŀ�:id=-1,type=CardType_None��", id);
			id = -1;
			type = CardType_None;
			return;
		}

		if (type < CardType_None)
		{
			cocos2d::log("[warning] ���쿨��ʧ�ܣ�����type(=%d)���Ϸ�����������Ϊ�տ�������Ч�Ŀ�:id=-1,type=CardType_None��", type);
			id = -1;
			type = CardType_None;
			return;
		}

		if (!(type <= id && id < type + idBaseNum))
		{
			cocos2d::log("[warning] ���쿨��ʧ�ܣ�������id������������Ͳ�����id=%d��type=%d", id, type);
			id = -1;
			type = CardType_None;
			return;
		}

		cocos2d::log("[information] �ɹ�����һ�ſ��ƣ�id=%d��type=%d", id, type);
	}

	virtual ~CardBase()
	{
	}

	// ��ȡ��id
	virtual int getID() const
	{
		return id;
	}

	// ��ȡ��type
	virtual CardType getType() const
	{
		return type;
	}

	// ��ȡ��������
	virtual const std::string& getName() const
	{
		return name;
	}

	// ��ȡ��������
	virtual const std::string& getDescride() const
	{
		return describe;
	}

	// ��ȡ��������
	virtual const BelongTo getBelongTo() const
	{
		return belongTo;
	}

protected:
	// ����ID
	const int id;
	// ��������
	const CardType type;
	// ��������
	const std::string name;
	// ��������
	const std::string describe;
	// ��������
	const BelongTo belongTo;
};

#endif
