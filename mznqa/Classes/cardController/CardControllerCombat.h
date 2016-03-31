#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARDCONTROLLER_CARDCONTROLLERCOMBAT_H_
#define MZNQA_CLASSES_CARDCONTROLLER_CARDCONTROLLERCOMBAT_H_

#include "cardController/CardBox.h"
#include "card/CardSkill.h"

class CardControllerCombat
{
private:
	CardBox<CardSkill> *cardPool = new CardBox<CardSkill>();
	CardBox<CardSkill> *handCard = new CardBox<CardSkill>(5);
	CardBox<CardSkill> *recycleCard = new CardBox<CardSkill>();
public:
	CardControllerCombat()
	{}
	~CardControllerCombat()
	{}

	void addCardToCardPool(int id)
	{
		cocos2d::log("[information] ������ս�������Ŀ����м���һ��idΪ%d�Ŀ�...", id);
		int result = cardPool->addCard(id);
		if (result != -1)
			cocos2d::log("[information] �ɹ���ս�������Ŀ����м���һ��idΪ%d�Ŀ�", id);
		else
			cocos2d::log("[information] ��ս�������Ŀ����м���һ��idΪ%d�Ŀ�ʧ��");
	}

	// �鿨���ݶ�ȫ�����
	int drawACard()
	{
		cocos2d::log("[information] ���ڴ�ս�������Ŀ����г�ȡһ�ſ�...");

		if (cardPool->getCardCount() <= 0)
		{
			cocos2d::log("[warning] ��ս�������Ŀ����г�ȡ��ʧ�ܣ���ǰ����Ϊ��");
			return -1;
		}
		if (handCard->isFull())
		{
			cocos2d::log("[warning] ��ս�������Ŀ����г�ȡ��ʧ�ܣ���ǰ��������");
			return -1;
		}

		int id = cardPool->removeCardByRandom();

		handCard->addCard(id);

		cocos2d::log("[information] �ɹ���ս�������Ŀ����г�ȡһ��idΪ%d�Ŀ�", id);
		return id;
	}

	// ���ƣ�ָ��id
	int playCardByID(int id)
	{
		cocos2d::log("[information] ���ڴ�ս��������������ʹ��һ��idΪ%d�Ŀ�...", id);
		int result = handCard->removeCardByID(id);
		if (result == id)
			cocos2d::log("[information] �ɹ���ս��������������ʹ��һ��idΪ%d��", id);
		else
			cocos2d::log("[warning] ��ս��������������ʹ��һ��idΪ%d��ʧ��", id);
		recycleCard->addCard(result);
		return result;
	}

	// ���ƣ�ָ������
	int playCardByIndex(int index)
	{
		cocos2d::log("[information] ���ڴ�ս��������������ʹ��һ������Ϊ%d�Ŀ�...", index);
		int id = handCard->removeCardByIndex(index);
		if (id != -1)
			cocos2d::log("[information] �ɹ���ս��������������ʹ��һ������Ϊ%d,idΪ%d�Ŀ�", index, id);
		else
			cocos2d::log("[warning] ��ս��������������ʹ��һ������Ϊ%d��ʧ��", index);
		recycleCard->addCard(id);
		return id;
	}

	// ϴ��
	void shuffle()
	{
		auto it = recycleCard->getCardSet().cbegin();
		auto itEnd = recycleCard->getCardSet().cend();
		while (it != itEnd)
		{
			cardPool->addCard(*it);
			++it;
		}

		recycleCard->clear();
		cocos2d::log("[information] �ɹ����ս��������ϴ��");
	}

	// ���
	void clear()
	{
		cardPool->clear();
		handCard->clear();
		recycleCard->clear();
	}
};

#endif
