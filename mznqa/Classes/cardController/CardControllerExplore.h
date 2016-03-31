#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARDCONTROLLER_CARDCONTROLLEREXPLORE_H_
#define MZNQA_CLASSES_CARDCONTROLLER_CARDCONTROLLEREXPLORE_H_

#include <list>

#include "cardController/CardBoxRTM.h"

class CardControllerExplore
{
private:
	CardControllerExplore(){}
	CardControllerExplore(const CardControllerExplore& cardControllerExplore);
	CardControllerExplore& operator=(const CardControllerExplore& cardControllerExplore);

	// ����
	CardBoxRTM *cardPool = new CardBoxRTM();
	// ����
	CardBoxRTM *handCard = new CardBoxRTM(5);
	// ����
	CardBoxRTM *recycleCard = new CardBoxRTM();

public:
	static CardControllerExplore* Instance();
	~CardControllerExplore();

	// �򿨳������һ�ſ�
	void addCardToCardPool(int id)
	{
		cocos2d::log("[information] �������������Ŀ����м���һ��idΪ%d�Ŀ�...", id);
		int result = cardPool->addCard(id);
		if (result != -1)
			cocos2d::log("[information] �ɹ����������Ŀ����м���һ��idΪ%d�Ŀ�", id);
		else
			cocos2d::log("[information] ���������Ŀ����м���һ��idΪ%d�Ŀ�ʧ��");
	}

	// �鿨���ݶ�ȫ�����
	int drawACard()
	{
		cocos2d::log("[information] ���ڴ��������Ŀ����г�ȡһ�ſ�...");

		if (cardPool->getCardCount() <= 0)
		{
			cocos2d::log("[warning] ��̽�������Ŀ����г�ȡ��ʧ�ܣ���ǰ����Ϊ��");
			return -1;
		}
		if (handCard->isFull())
		{
			cocos2d::log("[warning] ��̽�������Ŀ����г�ȡ��ʧ�ܣ���ǰ��������");
			return -1;
		}

		int id = cardPool->removeCardByRandom();

		handCard->addCard(id);

		cocos2d::log("[information] �ɹ���̽�������Ŀ����г�ȡһ��idΪ%d�Ŀ�", id);
		return id;
	}

	// ���ƣ�ָ��id
	int playCardByID(int id)
	{
		cocos2d::log("[information] ���ڴ�̽��������������ʹ��һ��idΪ%d�Ŀ�...", id);
		int result = handCard->removeCardByID(id);
		if (result == id)
			cocos2d::log("[information] �ɹ���̽��������������ʹ��һ��idΪ%d��", id);
		else
			cocos2d::log("[warning] ��̽��������������ʹ��һ��idΪ%d��ʧ��", id);
		recycleCard->addCard(result);
		return result;
	}

	// ���ƣ�ָ������
	int playCardByIndex(int index)
	{
		cocos2d::log("[information] ���ڴ�̽��������������ʹ��һ������Ϊ%d�Ŀ�...", index);
		int id = handCard->removeCardByIndex(index);
		if (id != -1)
			cocos2d::log("[information] �ɹ���̽��������������ʹ��һ������Ϊ%d,idΪ%d�Ŀ�", index, id);
		else
			cocos2d::log("[warning] ��̽��������������ʹ��һ������Ϊ%d��ʧ��", index);
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
			cardPool->addCard(it->second);
			++it;
		}

		recycleCard->clear();
		cocos2d::log("[information] �ɹ����̽��������ϴ��");
	}
};

#endif
