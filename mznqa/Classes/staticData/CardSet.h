/*!
 * \file	Classes\staticData\CardSet.h
 *
 * \brief	定义类 CardSet
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_STATICDATA_CARDSET_H_
#define MZNQA_CLASSES_STATICDATA_CARDSET_H_

#include <map>

#include "cocos2d.h"

#include "card/CardRoad.h"
#include "card/CardTreasure.h"
#include "card/CardMonster.h"
#include "card/CardSkill.h"

/*!
 * \class	CardSet
 *
 * \brief	单例。包含所有卡牌的集合
 *
 */
class CardSet
{
private:

	/*!
	 * \fn	CardSet::CardSet()
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	CardSet(){}

	/*!
	 * \fn	CardSet::CardSet(const CardSet &cardSet);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 * \param	cardSet	CardSet 实例
	 */
	CardSet(const CardSet &cardSet);

	/*!
	 * \fn	CardSet& CardSet::operator=(const CardSet &cardSet);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 * \param	cardSet	CardSet 实例
	 *
	 * \return	CardSet 实例
	 */
	CardSet& operator=(const CardSet &cardSet);

	/*! \brief	地形卡子集 */
	std::map<int, CardRoad> cardRoadSet;
	/*! \brief	宝物卡子集 */
	std::map<int, CardTreasure> cardTreasureSet;
	/*! \brief	怪物卡子集 */
	std::map<int, CardMonster> cardMonsterSet;
	/*! \brief	技能卡子集 */
	std::map<int, CardSkill> cardSkillSet;

public:

	/*!
	 * \fn	static CardSet* CardSet::Instance();
	 *
	 * \brief	获取单例
	 *
	 * \return	返回单例
	 */
	static CardSet* Instance();

	/*!
	 * \fn	CardSet::~CardSet();
	 *
	 * \brief	析构函数
	 *
	 */
	~CardSet();

	/*!
	 * \fn	void CardSet::loadCardRoadSet(std::map<int, CardRoad> &cardRoadSet)
	 *
	 * \brief	载入地形卡集合，用于初始化
	 *
	 * \param [in,out]	cardRoadSet	地形卡集合
	 */
	void loadCardRoadSet(std::map<int, CardRoad> &cardRoadSet)
	{
		this->cardRoadSet.swap(cardRoadSet);
	}

	/*!
	 * \fn	void CardSet::loadCardTreasureSet(std::map<int, CardTreasure> &cardTreasureSet)
	 *
	 * \brief	载入宝物卡集合，用于初始化
	 *
	 * \param [in,out]	cardTreasureSet	宝物卡集合
	 */
	void loadCardTreasureSet(std::map<int, CardTreasure> &cardTreasureSet)
	{
		this->cardTreasureSet.swap(cardTreasureSet);
	}

	/*!
	 * \fn	void CardSet::loadCardMonsterSet(std::map<int, CardMonster> &cardMonsterSet)
	 *
	 * \brief	载入怪物卡集合，用于初始化
	 *
	 * \param [in,out]	cardMonsterSet	怪物卡集合
	 */

	void loadCardMonsterSet(std::map<int, CardMonster> &cardMonsterSet)
	{
		this->cardMonsterSet.swap(cardMonsterSet);
	}

	/*!
	 * \fn	void CardSet::loadCardSkillSet(std::map<int, CardSkill> &cardSkillSet)
	 *
	 * \brief	载入技能卡集合，用于初始化
	 *
	 * \param [in,out]	cardSkillSet	技能卡集合
	 */
	void loadCardSkillSet(std::map<int, CardSkill> &cardSkillSet)
	{
		this->cardSkillSet.swap(cardSkillSet);
	}

	/*!
	 * \fn	const CardRoad* CardSet::getCardRoadByID(int id)
	 *
	 * \brief	根据给定 id 获取地形卡
	 *
	 * \param	id	指定地形卡 id
	 *
	 * \return	成功返回指向目标地形卡的指针，失败返回 nullptr
	 */
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

	/*!
	 * \fn	const CardTreasure* CardSet::getCardTreasureByID(int id)
	 *
	 * \brief	根据给定 id 获取宝物卡
	 *
	 * \param	id	指定宝物卡 id
	 *
	 * \return	成功返回指向目标宝物卡的指针，失败返回 nullptr
	 */
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

	/*!
	 * \fn	const CardMonster* CardSet::getCardMonsterByID(int id)
	 *
	 * \brief	根据给定 id 获取怪物卡
	 *
	 * \param	id	指定怪物卡 id
	 *
	 * \return	成功返回指向目标怪物卡的指针，失败返回 nullptr
	 */
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

	/*!
	 * \fn	const CardSkill* CardSet::getCardSkillByID(int id)
	 *
	 * \brief	根据给定 id 获取技能卡
	 *
	 * \param	id	指定技能卡 id
	 *
	 * \return	成功返回指向目标技能卡的指针，失败返回 nullptr
	 */
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
