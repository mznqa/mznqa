#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_BASECLASS_EXPLORECARDPOOL_H_
#define MZNQA_CLASSES_BASECLASS_EXPLORECARDPOOL_H_

#include <list>

#include "baseClass/Card.h"
#include "baseClass/CardRoad.h"
#include "baseClass/CardTreasure.h"
#include "baseClass/CardMonster.h"

class ExploreCardPool
{
private:
	// �ӿ��أ���ŵ��ο�
	std::list<CardRoad> cardRoadSet;
	// �ӿ��أ���ű��￨
	std::list<CardTreasure> cardTreasureSet;
	// �ӿ��أ���Ź��￨
	std::list<CardMonster> cardMonsterSet;

	// ����վ
	std::list<Card> recycleBin;
public:
	ExploreCardPool();
	~ExploreCardPool();

	// �򿨳������һ�ſ�
	void AddACard(const Card &card);
	// �ӿ����г�ȡһ�ſ�
	Card DrawACard();
	// ��տ���
	void clear();
	// ϴ��
	void shuffle();

	// ���Ʒ��õ�������
	void pushRecycleBin(const Card &card);
	// ���������
	void clearRecycleBin();
	// ��ȡ����ȥ�Ŀ�����
	int getRecycleBinCardCount();

	// ��ȡ��ǰ�����п��Ƹ���
	int getCardCount();
	// ��ȡ��ǰ�����еĵ��ο�����
	int getCardRoadCount();
	// ��ȡ��ǰ�����еı��￨����
	int getCardTreasureCount();
	// ��ȡ��ǰ�����й��￨�ĸ���
	int getCardMonsterCount();

	void test();
};

#endif
