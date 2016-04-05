/*!
 * \file	Classes\cardController\CardControllerExplore.cpp
 *
 * \brief	������ CardControllerExplore
 */

#pragma execution_character_set("utf-8")

#include "cardController/CardControllerExplore.h"

CardControllerExplore* CardControllerExplore::Instance()
{
	static CardControllerExplore instance;
	return &instance;
}

int CardControllerExplore::drawACard()
{
	cocos2d::log("[information] ���ڴ�̽�������Ŀ����г�ȡһ�ſ�...");

	if (cardPool->getCardCount() <= 0)
	{
		cocos2d::log("[warning] ��̽�������Ŀ����г�ȡ��ʧ�ܣ���ǰ����Ϊ��");
		return CardBase::invalidID;
	}
	if (handCard->isFull())
	{
		cocos2d::log("[warning] ��̽�������Ŀ����г�ȡ��ʧ�ܣ���ǰ��������");
		return CardBase::invalidID;
	}

	// �ӿ������Ƴ�һ�ſ�
	int id = cardPool->removeCardByRandom();

	// ����������Ӹÿ�
	handCard->addCardByID(id);

	cocos2d::log("[information] �ɹ���̽�������Ŀ����г�ȡһ��idΪ%d�Ŀ�", id);
	return id;
}

void CardControllerExplore::shuffle()
{
	auto it = recycleCard->getCardSet().cbegin();
	auto itEnd = recycleCard->getCardSet().cend();
	while (it != itEnd)
	{
		cardPool->addCardByID(it->second);
		++it;
	}

	recycleCard->clear();
	cocos2d::log("[information] �ɹ����̽��������ϴ��");
}