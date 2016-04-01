/*!
 * \file	Classes\cardController\CardBoxRTM.cpp
 *
 * \brief	������ CardBoxRTM
 */

#pragma execution_character_set("utf-8")

#include "cardController/CardBoxRTM.h"

#include <iterator>

int CardBoxRTM::removeIndexByID(int id)
{
	auto it = index2ID.begin();
	auto itEnd = index2ID.end();
	while (it != itEnd)
	{
		if (it->second == id)
		{
			int index = std::distance(it, index2ID.begin());
			index2ID.erase(it);
			return index;
		}
		++it;
	}

	return -1;
}

int CardBoxRTM::addCardByCard(const CardRoad& card)
{
	// �����������
	if (size != CardBase::invalidID && getCardCount() >= size)
		return CardBase::invalidID;

	// ����ο�����������ӵ��ο�
	int result = cardBoxRoad.addCardByCard(card);

	// ��������
	insertIndexByID(result);

	return result;
}

int CardBoxRTM::addCardByCard(const CardTreasure& card)
{
	// �����������
	if (size != CardBase::invalidID && getCardCount() >= size)
		return CardBase::invalidID;

	// ���￨����������ӿ���
	int result = cardBoxTreasure.addCardByCard(card);

	// ��������
	insertIndexByID(result);

	return result;
}

int CardBoxRTM::addCardByCard(const CardMonster& card)
{
	// �����������
	if (size != CardBase::invalidID && getCardCount() >= size)
		return CardBase::invalidID;

	// ���������������ӿ���
	int result = cardBoxMonster.addCardByCard(card);

	// ��������
	insertIndexByID(result);

	return result;
}

int CardBoxRTM::addCardByID(int id)
{
	// �����������
	if (size != CardBase::invalidID && getCardCount() >= size)
		return CardBase::invalidID;

	int result = CardBase::invalidID;
	// �жϸ���id��Ӧ��������
	CardBase::CardType cType = CardBase::judgeCardTypeByID(id);
	// ����ǵ��ο����ڿ��ƿ��д���
	if (
		cType == CardBase::CardType_Road &&
		CardSet::Instance()->getCardRoadByID(id) != nullptr
		)
	{
		// ����ο�����������ӿ���
		result = cardBoxRoad.addCardByID(id);
		// ��������
		insertIndexByID(result);
	}
	// ����Ǳ��￨���ڿ��ƿ��д���
	else if (
		cType == CardBase::CardType_Treasure &&
		CardSet::Instance()->getCardTreasureByID(id) != nullptr
		)
	{
		// ���￨����������ӿ���
		result = cardBoxTreasure.addCardByID(id);
		// ��������
		insertIndexByID(result);
	}
	// ����ǹ��￨���ڿ��ƿ��д���
	else if (
		cType == CardBase::CardType_Monster &&
		CardSet::Instance()->getCardMonsterByID(id) != nullptr
		)
	{
		// ����￨����������ӿ���
		result = cardBoxMonster.addCardByID(id);
		// ��������
		insertIndexByID(result);
	}
	// ����...
	else
	{
		cocos2d::log("[warning] �� CardBoxRTM ��ӿ���ʧ�ܣ�������id=%d����", id);
		return CardBase::invalidID;
	}

	return result;
}

int CardBoxRTM::removeCardByID(int id)
{
	// �жϸ���idָ��Ŀ�������
	CardBase::CardType cType = CardBase::judgeCardTypeByID(id);
	// ����ǵ��ο����ڿ��ƿ���
	if (
		cType == CardBase::CardType_Road &&
		CardSet::Instance()->getCardRoadByID(id) != nullptr
		)
	{
		removeIndexByID(id);
		return cardBoxRoad.removeCardByID(id);
	}
	// ����Ǳ��￨���ڿ��ƿ���
	else if (
		cType == CardBase::CardType_Treasure &&
		CardSet::Instance()->getCardTreasureByID(id) != nullptr
		)
	{
		removeIndexByID(id);
		return cardBoxTreasure.removeCardByID(id);
	}
	// ����ǹ��￨���ڿ��ƿ���
	else if (
		cType == CardBase::CardType_Monster &&
		CardSet::Instance()->getCardMonsterByID(id) != nullptr
		)
	{
		removeIndexByID(id);
		return cardBoxMonster.removeCardByID(id);
	}
	// ����...
	else
	{
		cocos2d::log("[warning] �� CardBoxRTM �Ƴ�����ʧ�ܣ�������id����");
		return CardBase::invalidID;
	}
	return CardBase::invalidID;
}

int CardBoxRTM::removeCardByIndex(int index)
{
	// �ж������Ƿ�Խ��
	int sTemp = index2ID.size();
	if (!(0 <= index && index < sTemp))
		return CardBase::invalidID;

	// ��������
	auto it = index2ID.begin();
	auto itEnd = index2ID.end();
	int i = 0;
	while (it != itEnd)
	{
		if (i == index)
		{
			int idResult = removeCardByID(it->second);
			return idResult;
		}
		++it;
		++i;
	}
	return CardBase::invalidID;
}