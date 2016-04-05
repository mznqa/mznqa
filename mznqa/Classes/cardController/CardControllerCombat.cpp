/*!
 * \file	D:\Projects\mznqa\mznqa\Classes\cardController\CardControllerCombat.cpp
 *
 * \brief	������ CardControllerCombat
 */

#pragma execution_character_set("utf-8")

#include "cardController/CardControllerCombat.h"

int CardControllerCombat::drawACard()
{
	cocos2d::log("[information] ���ڴ�ս�������Ŀ����г�ȡһ�ſ�...");

	// �������Ϊ��
	if (cardPool->getCardCount() <= 0)
	{
		cocos2d::log("[warning] ��ս�������Ŀ����г�ȡ��ʧ�ܣ���ǰ����Ϊ��");
		return CardBase::invalidID;
	}
	// �����������
	if (handCard->isFull())
	{
		cocos2d::log("[warning] ��ս�������Ŀ����г�ȡ��ʧ�ܣ���ǰ��������");
		return CardBase::invalidID;
	}

	// �ӿ���������Ƴ�һ�ſ�
	int id = cardPool->removeCardByRandom();

	// ��������������ſ�
	if (id != CardBase::invalidID)
		handCard->addCardByID(id);

	cocos2d::log("[information] �ɹ���ս�������Ŀ����г�ȡһ��idΪ%d�Ŀ�", id);

	return id;
}

void CardControllerCombat::shuffle()
{
	auto it = recycleCard->getCardSet().cbegin();
	auto itEnd = recycleCard->getCardSet().cend();
	while (it != itEnd)
	{
		cardPool->addCardByID(*it);
		++it;
	}

	recycleCard->clear();
	cocos2d::log("[information] �ɹ����ս��������ϴ��");
}