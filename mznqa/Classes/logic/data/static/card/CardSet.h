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
	 * \fn	void CardSet::loadCardRoadSet(const std::vector<CardRoad> &cardRoadSet);
	 *
	 * \brief	载入地形卡集合数据
	 *
	 * \param	cardRoadSet	指定地形卡集合数据缓存
	 */
	void loadCardRoadSet(const std::vector<CardRoad> &cardRoadSet);

	/*!
	 * \fn	const CardRoad *const CardSet::getCardRoadByID(int id)const;
	 *
	 * \brief	根据给定ID以获取地形卡
	 *
	 * \param	id	指定地形卡ID
	 *
	 */
	const CardRoad *const getCardRoadByID(int id)const;
};

#endif
