#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_BASECLASS_CARDPOOL_H_
#define MZNQA_CLASSES_BASECLASS_CARDPOOL_H_

#include "baseClass/Card.h"

class CardPool
{
public:
	CardPool(){}
	~CardPool(){}

	// �򿨳������һ�ſ�
	virtual void AddACard(const Card &card) = 0;
	// �ӿ����г�ȡһ�ſ�
	virtual Card DrawACard() = 0;
	// ��տ���
	virtual void clear() = 0;
	// ϴ��
	virtual void shuffle() = 0;

	// ���Ʒ��õ�������
	virtual void pushRecycleBin(const Card &card) = 0;
	// ���������
	virtual void clearRecycleBin() = 0;
	// ��ȡ������������
	virtual int getRecycleBinCardCount() = 0;

	// ��ȡ��ǰ�����п��Ƹ���
	virtual int getCardCount() = 0;
};

#endif
