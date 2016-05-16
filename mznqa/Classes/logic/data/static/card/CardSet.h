/*!
 * \file	Classes\logic\data\static\card\CardSet.h
 *
 * \brief	定义类 CardSet
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_DATA_STATIC_CARD_CARDSET_H_
#define MZNQA_CLASSES_LOGIC_DATA_STATIC_CARD_CARDSET_H_

#include <map>
#include <vector>

#include "logic/gameObject/card/CardRoad.h"
#include "logic/gameObject/card/CardSkill.h"
#include "logic/gameObject/card/CardMonster.h"
#include "logic/gameObject/card/CardTreasure.h"

/*!
 * \class	CardSet
 *
 * \brief	[单例]存放所有卡牌
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
	CardSet()
	{
	}

	/*!
	 * \fn	CardSet::CardSet(const CardSet &cardSet);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 */
	CardSet(const CardSet &cardSet);

	/*!
	 * \fn	CardSet& CardSet::operator=(const CardSet &cardSet);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 */
	CardSet& operator=(const CardSet &cardSet);

	/*! \brief	地形卡集合 */
	std::map<int, CardRoad> cardRoadSet;
	/*! \brief	技能卡集合 */
	std::map<int, CardSkill> cardSkillSet;
	/*! \brief	怪物卡集合 */
	std::map<int, CardMonster> cardMonsterSet;
	/*! \brief	宝物卡集合 */
	std::map<int, CardTreasure> cardTreasureSet;
public:

	/*!
	 * \fn	CardSet::~CardSet()
	 *
	 * \brief	析构函数
	 *
	 */
	~CardSet()
	{
	}

	/*!
	 * \fn	static CardSet* CardSet::Instance();
	 *
	 * \brief	获取单例
	 *
	 */
	static CardSet* Instance();

	/*!
	 * \fn	void CardSet::loadCardRoadSet(std::map<int, CardRoad> &cardRoadSet);
	 *
	 * \brief	载入地形卡集合数据
	 *
	 * \param [in,out]	cardRoadSet	指定地形卡集合数据缓存
	 */
	void loadCardRoadSet(std::map<int, CardRoad> &cardRoadSet);

	/*!
	 * \fn	void CardSet::loadCardSkillSet(std::map<int, CardSkill> &cardSkillSet);
	 *
	 * \brief	载入技能卡集合数据
	 *
	 * \param [in,out]	cardSkillSet	指定技能卡集合数据缓存
	 */
	void loadCardSkillSet(std::map<int, CardSkill> &cardSkillSet);

	/*!
	 * \fn	void CardSet::loadCardMonsterSet(std::map<int, CardMonster> &cardMonsterSet);
	 *
	 * \brief	载入怪物卡集合数据
	 *
	 * \param [in,out]	cardMonsterSet	指定怪物卡集合数据缓存
	 */
	void loadCardMonsterSet(std::map<int, CardMonster> &cardMonsterSet);

	/*!
	 * \fn	void CardSet::loadCardTreasureSet(std::map<int, CardTreasure> &cardTreasureSet);
	 *
	 * \brief	载入宝物卡集合数据
	 *
	 * \param [in,out]	cardTreasureSet	指定宝物卡集合数据缓存
	 */
	void loadCardTreasureSet(std::map<int, CardTreasure> &cardTreasureSet);

	/*!
	 * \fn	bool CardSet::isCardType(CardBase::CardType cardType, int id)const;
	 *
	 * \brief	判断指定卡牌ID是否为给定的卡牌类型
	 *
	 * \param	cardType	指定卡牌类型
	 * \param	id			指定卡牌ID
	 *
	 */
	bool isCardType(CardBase::CardType cardType, int id)const;

	/*!
	 * \fn	const CardRoad *const CardSet::getCardRoadByID(int id)const;
	 *
	 * \brief	根据给定ID以获取地形卡
	 *
	 * \param	id	指定地形卡ID
	 *
	 */
	const CardRoad *const getCardRoadByID(int id)const;

	/*!
	 * \fn	const CardSkill *const CardSet::getCardSkillByID(int id)const;
	 *
	 * \brief	根据给定ID以获取技能卡
	 *
	 * \param	id	指定技能卡ID
	 *
	 */
	const CardSkill *const getCardSkillByID(int id)const;

	/*!
	 * \fn	const CardMonster *const CardSet::getCardMonsterByID(int id)const;
	 *
	 * \brief	根据给定ID以获取怪物卡
	 *
	 * \param	id	指定怪物卡ID
	 *
	 */
	const CardMonster *const getCardMonsterByID(int id)const;

	/*!
	 * \fn	const CardTreasure *const CardSet::getCardTreasureByID(int id)const;
	 *
	 * \brief	根据给定ID以获取宝物卡
	 *
	 * \param	id	指定宝物卡ID
	 *
	 */
	const CardTreasure *const getCardTreasureByID(int id)const;
};

#endif
