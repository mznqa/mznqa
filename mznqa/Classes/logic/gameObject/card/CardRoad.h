/*!
 * \file	Classes\logic\gameObject\card\CardRoad.h
 *
 * \brief	定义类 CardRoad
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARD_CARDROAD_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARD_CARDROAD_H_

#include "logic/gameObject/card/CardBase.h"
#include "logic/data/info/NumDefine.h"

/*!
 * \class	CardRoad
 *
 * \brief	地形卡
 *
 */
class CardRoad : public CardBase
{
private:
	/*! \brief	卡牌类型 */
	static CardBase::CardType cardType;

	/*! \brief	道路节点 */
	bool roadNode[MAPNODE_GROUPSIZE][MAPNODE_GROUPSIZE];

public:

	/*!
	 * \fn	CardRoad::~CardRoad()
	 *
	 * \brief	析构函数
	 *
	 */
	~CardRoad()
	{
	}

	/*!
	 * \fn	CardRoad::CardRoad(int id, int sidName, int sidDescribe, CardBase::BelongTo belongTo, const bool roadNode[MAPNODE_GROUPSIZE][MAPNODE_GROUPSIZE])
	 *
	 * \brief	构造函数
	 *
	 * \param	id			指定地形卡ID
	 * \param	sidName		指定地形卡的名称SID
	 * \param	sidDescribe	指定地形卡的描述SID
	 * \param	belongTo	指定地形卡的所属方
	 * \param	roadNode	指定地形卡的道路节点
	 */
	CardRoad(int id, int sidName, int sidDescribe, CardBase::BelongTo belongTo, const bool roadNode[MAPNODE_GROUPSIZE][MAPNODE_GROUPSIZE]) :
		CardBase(id, sidName, sidDescribe, belongTo)
	{
		for (int y = 0; y < MAPNODE_GROUPSIZE; ++y)
			for (int x = 0; x < MAPNODE_GROUPSIZE; ++x)
				this->roadNode[y][x] = roadNode[y][x];
	}

	/*!
	 * \fn	CardRoad::CardRoad(const CardRoad &cardRoad)
	 *
	 * \brief	拷贝构造函数
	 *
	 */
	CardRoad(const CardRoad &cardRoad) :
		CardBase(cardRoad.getID(), cardRoad.getSIDName(), cardRoad.getSIDDescribe(), cardRoad.getBelongTo())
	{
		for (int y = 0; y < MAPNODE_GROUPSIZE; ++y)
			for (int x = 0; x < MAPNODE_GROUPSIZE; ++x)
				this->roadNode[y][x] = cardRoad.isRoadNode(x, y);
	}

	/*!
	 * \fn	CardRoad& CardRoad::operator=(const CardRoad &cardRoad)
	 *
	 * \brief	拷贝赋值运算符
	 *
	 */
	CardRoad& operator=(const CardRoad &cardRoad)
	{
		CardBase::operator=(cardRoad);
		for (int y = 0; y < MAPNODE_GROUPSIZE; ++y)
			for (int x = 0; x < MAPNODE_GROUPSIZE; ++x)
				this->roadNode[y][x] = cardRoad.isRoadNode(x, y);
		return *this;
	}

	/*!
	 * \fn	CardBase::CardType CardRoad::getCardType()const override
	 *
	 * \brief	获取卡牌类型
	 *
	 */
	CardBase::CardType getCardType()const override
	{
		return cardType;
	}

	/*!
	 * \fn	bool CardRoad::isRoadNode(int x, int y)const
	 *
	 * \brief	获取指定卡牌内指定坐标节点是否为道路
	 *
	 * \param	x	指定横坐标
	 * \param	y	指定纵坐标
	 *
	 */
	bool isRoadNode(int x, int y)const
	{
		if (0 <= x && x < MAPNODE_GROUPSIZE && 0 <= y&&y < MAPNODE_GROUPSIZE)
			return roadNode[y][x];
		return false;
	}
};

#endif
