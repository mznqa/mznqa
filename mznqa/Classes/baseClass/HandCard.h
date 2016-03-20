#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_BASECLASS_HANDCARD_H_
#define MZNQA_CLASSES_BASECLASS_HANDCARD_H_

#include <list>

#include "baseClass/Card.h"

class HandCard
{
protected:
	int handCardCount;

	std::list<Card> handCardSet;

	bool checkIndex(int index);

public:
	HandCard(int handCardCount);
	~HandCard();

	// �����������һ�ſ�
	void AddACard(const Card &card);
	// ������������ָ������
	Card getCardByIndex(int index);
	// ��������ɾ��ָ������
	Card removeCardByIndex(int index);
	// ��ȡ��ǰ�����п��Ƹ���
	int getCardCount();
	// �������
	void clear();

	// ��ȡ���ƵĴ�С
	int getSize();

	void test();
};

#endif
