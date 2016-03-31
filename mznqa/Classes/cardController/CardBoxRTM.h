#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARDCONTROLLER_CARDBOXRTM_H_
#define MZNQA_CLASSES_CARDCONTROLLER_CARDBOXRTM_H_

#include <ctime>
#include <cstdlib>

#include <map>

#include "cardController/CardBox.h"
#include "card/CardRoad.h"
#include "card/CardTreasure.h"
#include "card/CardMonster.h"

class CardBoxRTM
{
private:
	CardBox<CardRoad> cardBoxRoad;
	CardBox<CardTreasure> cardBoxTreasure;
	CardBox<CardMonster> cardBoxMonster;

	std::map<int, int> index2ID;

	int size;

	void removeIndexByID(int id)
	{
		auto it = index2ID.begin();
		auto itEnd = index2ID.end();
		while (it != itEnd)
		{
			if (it->second == id)
			{
				index2ID.erase(it);
				return;
			}
			++it;
		}
	}
public:
	CardBoxRTM() :
		size(-1)
	{}

	CardBoxRTM(int size) :
		size(size)
	{
		if (this->size <= 0)
			this->size = -1;
	}
	~CardBoxRTM()
	{}

	// ��ȡ�ܿ�����
	int getCardCount()const
	{
		return cardBoxRoad.getCardCount() + cardBoxTreasure.getCardCount() + cardBoxMonster.getCardCount();
	}
	// ��ȡ���ο���
	int getCardRoadCount()const
	{
		return cardBoxRoad.getCardCount();
	}
	// ��ȡ���￨��
	int getCardTreasureCount()const
	{
		return cardBoxTreasure.getCardCount();
	}
	// ��ȡ���￨��
	int getCardMonsterCount()const
	{
		return cardBoxMonster.getCardCount();
	}

	// ����һ�ŵ��ο������
	void addCard(const CardRoad& card)
	{
		if (size != -1 && getCardCount() >= size)
			return;
		cardBoxRoad.addCard(card);
		if (index2ID.size() <= 0)
			index2ID.insert(std::pair<int, int>(0, card.getID()));
		else
			index2ID.insert(std::pair<int, int>(index2ID.rbegin()->first + 1, card.getID()));
	}
	// ����һ�ű��￨�����
	void addCard(const CardTreasure& card)
	{
		if (size != -1 && getCardCount() >= size)
			return;
		cardBoxTreasure.addCard(card);
		if (index2ID.size() <= 0)
			index2ID.insert(std::pair<int, int>(0, card.getID()));
		else
			index2ID.insert(std::pair<int, int>(index2ID.rbegin()->first + 1, card.getID()));
	}
	// ����һ�Ź��￨�����
	void addCard(const CardMonster& card)
	{
		if (size != -1 && getCardCount() >= size)
			return;
		cardBoxMonster.addCard(card);
		if (index2ID.size() <= 0)
			index2ID.insert(std::pair<int, int>(0, card.getID()));
		else
			index2ID.insert(std::pair<int, int>(index2ID.rbegin()->first + 1, card.getID()));
	}

	// ����һ�ſ���id�����
	void addCard(int id)
	{
		if (size != -1 && getCardCount() >= size)
			return;

		CardBase::CardType cType = CardBase::judgeCardTypeByID(id);
		if (
			cType == CardBase::CardType_Road &&
			CardSet::Instance()->getCardRoadByID(id) != nullptr
			)
		{
			cardBoxRoad.addCard(id);
			if (index2ID.size() <= 0)
				index2ID.insert(std::pair<int, int>(0, id));
			else
				index2ID.insert(std::pair<int, int>(index2ID.rbegin()->first + 1, id));
		}
		else if (
			cType == CardBase::CardType_Treasure &&
			CardSet::Instance()->getCardTreasureByID(id) != nullptr
			)
		{
			cardBoxTreasure.addCard(id);
			if (index2ID.size() <= 0)
				index2ID.insert(std::pair<int, int>(0, id));
			else
				index2ID.insert(std::pair<int, int>(index2ID.rbegin()->first + 1, id));
		}
		else if (
			cType == CardBase::CardType_Monster &&
			CardSet::Instance()->getCardMonsterByID(id) != nullptr
			)
		{
			cardBoxMonster.addCard(id);
			if (index2ID.size() <= 0)
				index2ID.insert(std::pair<int, int>(0, id));
			else
				index2ID.insert(std::pair<int, int>(index2ID.rbegin()->first + 1, id));
		}
		else
		{
			cocos2d::log("[warning] �� CardBoxRTM ��ӿ���ʧ�ܣ�������id=%d����", id);
		}
	}

	// ����idɾ��ָ������ע�⣺����ʱ�䣩
	int removeCardByID(int id)
	{
		CardBase::CardType cType = CardBase::judgeCardTypeByID(id);
		if (
			cType == CardBase::CardType_Road &&
			CardSet::Instance()->getCardRoadByID(id) != nullptr
			)
		{
			removeIndexByID(id);
			return cardBoxRoad.removeCardByID(id);
		}
		else if (
			cType == CardBase::CardType_Treasure &&
			CardSet::Instance()->getCardTreasureByID(id) != nullptr
			)
		{
			removeIndexByID(id);
			return cardBoxTreasure.removeCardByID(id);
		}
		else if (
			cType == CardBase::CardType_Monster &&
			CardSet::Instance()->getCardMonsterByID(id) != nullptr
			)
		{
			removeIndexByID(id);
			return cardBoxMonster.removeCardByID(id);
		}
		else
		{
			cocos2d::log("[warning] �� CardBoxRTM �Ƴ�����ʧ�ܣ�������id����");
			return -1;
		}
		return -1;
	}
	// ��������ɾ����
	int removeCardByIndex(int index)
	{
		int sTemp = index2ID.size();
		if (!(0 <= index && index < sTemp))
			return -1;

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
		return -1;
	}
	// �����Ƴ�һ�ſ�
	int removeCardByRandom()
	{
		if (index2ID.size() <= 0)
			return -1;

		// TODO �ݷ�
		srand(unsigned(time(NULL)));

		int index = rand() % (index2ID.size());

		return removeCardByIndex(index);
	}
	// ����Ƴ�һ�ŵ��ο�
	int removeCardRoadByRandom()
	{
		int id = cardBoxRoad.removeCardByRandom();
		removeIndexByID(id);
		return id;
	}
	// ����Ƴ�һ�ű��￨
	int removeCardTreasureByRandom()
	{
		int id = cardBoxTreasure.removeCardByRandom();
		removeIndexByID(id);
		return id;
	}
	// ����Ƴ�һ�Ź��￨
	int removeCardMonsterByRandom()
	{
		int id = cardBoxMonster.removeCardByRandom();
		removeIndexByID(id);
		return id;
	}

	// ���
	void clear()
	{
		cardBoxRoad.clear();
		cardBoxTreasure.clear();
		cardBoxMonster.clear();
		index2ID.clear();
	}

	// �жϿ����Ƿ�����
	bool isFull()
	{
		if (size != -1 && getCardCount() >= size)
			return true;
		else
			return false;
	}

	// ��ȡ���е��ο���id
	const std::map<int, int>& getCardSet()const
	{
		return index2ID;
	}
};

#endif
