#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_STATICDATA_CARDSET_H_
#define MZNQA_CLASSES_STATICDATA_CARDSET_H_

#include <map>

#include "cocos2d.h"

#include "card/CardRoad.h"
#include "card/CardTreasure.h"
#include "card/CardMonster.h"
#include "card/CardSkill.h"

class CardSet
{
private:
	CardSet(){}
	CardSet(const CardSet &cardSet);
	CardSet& operator=(const CardSet &cardSet);

	// ���ο�����
	std::map<int, CardRoad> cardRoadSet;
	// ���￨����
	std::map<int, CardTreasure> cardTreasureSet;
	// ���￨����
	std::map<int, CardMonster> cardMonsterSet;
	// ���ܿ�����
	std::map<int, CardSkill> cardSkillSet;

public:
	static CardSet* Instance();
	~CardSet();

	// ������ο�����
	void loadCardRoadSet(std::map<int, CardRoad> &cardRoadSet)
	{
		this->cardRoadSet.swap(cardRoadSet);
	}
	// ���뱦�￨����
	void loadCardTreasureSet(std::map<int, CardTreasure> &cardTreasureSet)
	{
		this->cardTreasureSet.swap(cardTreasureSet);
	}
	// ������￨����
	void loadCardMonsterSet(std::map<int, CardMonster> &cardMonsterSet)
	{
		this->cardMonsterSet.swap(cardMonsterSet);
	}
	// ���뼼�ܿ�����
	void loadCardSkillSet(std::map<int, CardSkill> &cardSkillSet)
	{
		this->cardSkillSet.swap(cardSkillSet);
	}

	// ����id��ȡ���ο�
	const CardRoad* getCardRoadByID(int id)
	{
		auto it = cardRoadSet.find(id);
		if (it == cardRoadSet.end())
		{
			cocos2d::log("[warning] δ�ҵ�idΪ%d�ĵ��ο�");
			return nullptr;
		}
		else
		{
			return &(it->second);
		}
	}
	// ����id��ȡ���￨
	const CardTreasure* getCardTreasureByID(int id)
	{
		auto it = cardTreasureSet.find(id);
		if (it == cardTreasureSet.end())
		{
			cocos2d::log("[warning] δ�ҵ�idΪ%d�ı��￨");
			return nullptr;
		}
		else
		{
			return &(it->second);
		}
	}
	// ����id��ȡ���￨
	const CardMonster* getCardMonsterByID(int id)
	{
		auto it = cardMonsterSet.find(id);
		if (it == cardMonsterSet.end())
		{
			cocos2d::log("[warning] δ�ҵ�idΪ%d�Ĺ��￨");
			return nullptr;
		}
		else
		{
			return &(it->second);
		}
	}
	// ����id��ȡ���ܿ�
	const CardSkill* getCardSkillByID(int id)
	{
		auto it = cardSkillSet.find(id);
		if (it == cardSkillSet.end())
		{
			cocos2d::log("[warning] δ�ҵ�idΪ%d�ļ��ܿ�");
			return nullptr;
		}
		else
		{
			return &(it->second);
		}
	}

	void test();
};

#endif
