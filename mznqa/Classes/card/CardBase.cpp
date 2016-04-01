/*!
 * \file	Classes\card\CardBase.cpp
 *
 * \brief	������ CardBase
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
	// ���ָ����id��Ч��ָ���Ŀ���������Ч
	if (judgeCardTypeByID(id) == CardType_Invalid || checkCardType(type) == false)
	{
		id = invalidID;
		this->type = CardType_Invalid;
		cocos2d::log("[warning] ���쿨��ʱ�в�ȷ����Ϊ������idΪ%d,typeΪCardType_Invalid����ʱ��������Ϊ��Ч��,��ȷ���Ƿ�Ϊ������Ϊ", id);
		return;
	}

	// ���id�����Ͳ���
	if (judgeCardTypeByID(id) != type)
	{
		id = -1;
		type = CardType_Invalid;
		cocos2d::log("[warning] ���쿨��ʧ�ܣ�������id������������Ͳ�����id=%d��type=%d", id, type);
		return;
	}

	// ��������������󲻺Ϸ�
	if (
		belongTo != BelongTo_MonsterOnly &&
		belongTo != BelongTo_RoleMonsterBoth &&
		belongTo != BelongTo_RoleOnly
		)
	{
		id = -1;
		type = CardType_Invalid;
		cocos2d::log("[warning] ���쿨��ʧ�ܣ������Ŀ����������󲻺Ϸ���%d���������޸�ΪĬ��ֵ0", belongTo);
		belongTo = BelongTo_RoleMonsterBoth;
		return;
	}

	cocos2d::log("[information] �ɹ�����һ�ſ��ƣ�id=%d��type=%d", id, type);
}