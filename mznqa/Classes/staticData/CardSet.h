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

	// 地形卡集合
	std::map<int, CardRoad> cardRoadSet;
	// 宝物卡集合
	std::map<int, CardTreasure> cardTreasureSet;
	// 怪物卡集合
	std::map<int, CardMonster> cardMonsterSet;
	// 技能卡集合
	std::map<int, CardSkill> cardSkillSet;

public:
	static CardSet* Instance();
	~CardSet();

	// 载入地形卡集合
	void loadCardRoadSet(std::map<int, CardRoad> &cardRoadSet)
	{
		this->cardRoadSet.swap(cardRoadSet);
	}
	// 载入宝物卡集合
	void loadCardTreasureSet(std::map<int, CardTreasure> &cardTreasureSet)
	{
		this->cardTreasureSet.swap(cardTreasureSet);
	}
	// 载入怪物卡集合
	void loadCardMonsterSet(std::map<int, CardMonster> &cardMonsterSet)
	{
		this->cardMonsterSet.swap(cardMonsterSet);
	}
	// 载入技能卡集合
	void loadCardSkillSet(std::map<int, CardSkill> &cardSkillSet)
	{
		this->cardSkillSet.swap(cardSkillSet);
	}

	// 根据id获取地形卡
	const CardRoad* getCardRoadByID(int id)
	{
		auto it = cardRoadSet.find(id);
		if (it == cardRoadSet.end())
		{
			cocos2d::log("[warning] 未找到id为%d的地形卡");
			return nullptr;
		}
		else
		{
			return &(it->second);
		}
	}
	// 根据id获取宝物卡
	const CardTreasure* getCardTreasureByID(int id)
	{
		auto it = cardTreasureSet.find(id);
		if (it == cardTreasureSet.end())
		{
			cocos2d::log("[warning] 未找到id为%d的宝物卡");
			return nullptr;
		}
		else
		{
			return &(it->second);
		}
	}
	// 根据id获取怪物卡
	const CardMonster* getCardMonsterByID(int id)
	{
		auto it = cardMonsterSet.find(id);
		if (it == cardMonsterSet.end())
		{
			cocos2d::log("[warning] 未找到id为%d的怪物卡");
			return nullptr;
		}
		else
		{
			return &(it->second);
		}
	}
	// 根据id获取技能卡
	const CardSkill* getCardSkillByID(int id)
	{
		auto it = cardSkillSet.find(id);
		if (it == cardSkillSet.end())
		{
			cocos2d::log("[warning] 未找到id为%d的技能卡");
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
