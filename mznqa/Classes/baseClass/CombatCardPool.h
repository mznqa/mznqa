#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_BASECLASS_COMBATCARDPOOL_H_
#define MZNQA_CLASSES_BASECLASS_COMBATCARDPOOL_H_

#include <list>

#include "baseClass/Card.h"
#include "baseClass/CardPool.h"
#include "baseClass/CardSkill.h"

class CombatCardPool : public CardPool
{
private:
	// ���ܿ�����
	std::list<CardSkill> cardSkillSet;

	// ����վ
	std::list<CardSkill> recycleBin;
public:
	CombatCardPool();
	~CombatCardPool();

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

	void test();
};

#endif
