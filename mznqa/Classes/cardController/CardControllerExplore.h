#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARDCONTROLLER_CARDCONTROLLEREXPLORE_H_
#define MZNQA_CLASSES_CARDCONTROLLER_CARDCONTROLLEREXPLORE_H_

#include <list>

#include "cardController/CardBox.h"

class CardControllerExplore
{
private:
	CardControllerExplore(){}
	CardControllerExplore(const CardControllerExplore& cardControllerExplore);
	CardControllerExplore& operator=(const CardControllerExplore& cardControllerExplore);

	// ���� //////////////////////////////////////////////////////////////////////////
	CardBox<CardRoad> cardPoolCardRoad;
	CardBox<CardTreasure> cardPoolCardTreasure;
	CardBox<CardMonster> cardPoolCardMonster;
	//////////////////////////////////////////////////////////////////////////

	// ���� //////////////////////////////////////////////////////////////////////////
	CardBox<CardRoad> handCardCardRoad;
	CardBox<CardTreasure> handCardCardTreasure;
	CardBox<CardMonster> handCardCardMonster;
	//////////////////////////////////////////////////////////////////////////

	// ���� //////////////////////////////////////////////////////////////////////////
	CardBox<CardRoad> recycleCardCardRoad;
	CardBox<CardTreasure> recycleCardCardTreasure;
	CardBox<CardMonster> recycleCardCardMonster;
	//////////////////////////////////////////////////////////////////////////

public:
	static CardControllerExplore* Instance();
	~CardControllerExplore();

	// �򿨳������һ�ſ�
	void addToCardPool(int id)
	{
		CardBase::CardType cType = CardBase::judgeCardTypeByID(id);
		if (
			cType == CardBase::CardType_Road &&
			CardSet::Instance()->getCardRoadByID(id) != nullptr
			)
			cardPoolCardRoad.addCard(id);
		else if (
			cType == CardBase::CardType_Treasure &&
			CardSet::Instance()->getCardTreasureByID(id) != nullptr
			)
			cardPoolCardTreasure.addCard(id);
		else if (
			cType == CardBase::CardType_Monster &&
			CardSet::Instance()->getCardMonsterByID(id) != nullptr
			)
			cardPoolCardMonster.addCard(id);
		else
		{
			cocos2d::log("[warning] ��̽�������Ŀ�������ӿ���ʧ�ܣ�������id���󣬻�����������");
		}
	}

	// �鿨���ݶ�ȫ�����
	void drawACard()
	{
	}
};

#endif
