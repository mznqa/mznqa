#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARDCONTROLLER_CARDBOX_H_
#define MZNQA_CLASSES_CARDCONTROLLER_CARDBOX_H_

#include <ctime>
#include <cstdlib>

#include <list>

#include "cocos2d.h"

#include "card/CardBase.h"
#include "staticData/CardSet.h"

template <typename CardType>
class CardBox
{
private:
	// ���Ƽ��ϣ�id�ļ���)
	std::list<int> cardSet;

	// ������С
	int size;
public:
	CardBox() :
		size(-1)
	{}
	CardBox(int size) :
		size(size)
	{
		if (this->size <= 0)
			this->size = -1;
	}
	~CardBox()
	{}

	// ��ȡ������
	int getCardCount()const
	{
		return cardSet.size();
	}
	// ����һ�ſ������
	void addCard(const CardType& card)
	{
		if (size != -1 && cardSet.size() >= size)
			return;
		cardSet.push_back(card.getID());
	}
	// ����һ�ſ���id�����
	void addCard(int id)
	{
		if (size != -1 && cardSet.size() >= size)
			return;

		if (
			CardType::CARDTYPE == CardBase::CardType_Road &&
			CardSet::Instance()->getCardRoadByID(id) != nullptr
			)
			cardSet.push_back(id);
		else if (
			CardType::CARDTYPE == CardBase::CardType_Treasure &&
			CardSet::Instance()->getCardTreasureByID(id) != nullptr
			)
			cardSet.push_back(id);
		else if (
			CardType::CARDTYPE == CardBase::CardType_Monster &&
			CardSet::Instance()->getCardMonsterByID(id) != nullptr
			)
			cardSet.push_back(id);
		else if (
			CardType::CARDTYPE == CardBase::CardType_Skill &&
			CardSet::Instance()->getCardSkillByID(id) != nullptr
			)
			cardSet.push_back(id);
		else
		{
			cocos2d::log("[warning] �� CardBox ��ӿ���ʧ�ܣ�������id����");
		}
	}
	// ����idɾ��ָ������ע�⣺����ʱ�䣩
	int removeCardByID(int id)
	{
		auto it = cardSet.begin();
		auto itEnd = cardSet.end();
		while (it != itEnd)
		{
			if (*it == id)
			{
				cardSet.erase(it);
				return id;
			}
			++it;
		}
		return -1;
	}
	// ��������ɾ��ָ����
	int removeCardByIndex(int index)
	{
		int sTemp = cardSet.size();
		if (!(0 <= index && index < sTemp))
			return -1;

		auto it = cardSet.begin();
		auto itEnd = cardSet.end();
		int i = 0;
		while (it != itEnd)
		{
			if (i == index)
			{
				int result = *it;
				cardSet.erase(it);
				return result;
			}
			++it;
			++i;
		}

		return -1;
	}
	// ����Ƴ�һ�ſ�
	int removeCardByRandom()
	{
		if (cardSet.size() <= 0)
			return -1;

		// TODO �ݷ�
		srand(unsigned(time(NULL)));

		int index = rand() % (cardSet.size());

		return removeCardByIndex(index);
	}
	// ���
	void clear()
	{
		cardSet.clear();
	}
	// ��ȡ���п���id
	const std::list<int>& getCardSet()const
	{
		return cardSet;
	}
};

#endif