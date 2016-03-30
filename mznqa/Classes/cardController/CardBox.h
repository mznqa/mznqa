#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARDCONTROLLER_CARDBOX_H_
#define MZNQA_CLASSES_CARDCONTROLLER_CARDBOX_H_

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
	const int size;
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
	~CardBox();

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
		cardSet.push_back(card.id);
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
	bool removeCard(int id)
	{
		auto it = cardSet.begin();
		auto itEnd = cardSet.end();
		while (it != itEnd)
		{
			if (*it == id)
			{
				cardSet.erase(it);
				return true;
			}
			++it;
		}
		return false;
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