/*!
 * \file	Classes\logic\gameObject\card\CardRoad.h
 *
 * \brief	������ CardRoad
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARD_CARDROAD_H_
#define MZNQA_CLASSES_LOGIC_GAMEOBJECT_CARD_CARDROAD_H_

#include "logic/gameObject/card/CardBase.h"
#include "logic/data/info/NumDefine.h"

/*!
 * \class	CardRoad
 *
 * \brief	���ο�
 *
 */
class CardRoad : public CardBase
{
private:
	/*! \brief	�������� */
	static CardBase::CardType cardType;

	/*! \brief	��·�ڵ� */
	bool roadNode[MAPNODE_GROUPSIZE][MAPNODE_GROUPSIZE];

public:

	/*!
	 * \fn	CardRoad::~CardRoad()
	 *
	 * \brief	��������
	 *
	 */
	~CardRoad()
	{
	}

	/*!
	 * \fn	CardRoad::CardRoad(int id, int sidName, int sidDescribe, CardBase::BelongTo belongTo, const bool roadNode[MAPNODE_GROUPSIZE][MAPNODE_GROUPSIZE])
	 *
	 * \brief	���캯��
	 *
	 * \param	id			ָ�����ο�ID
	 * \param	sidName		ָ�����ο�������SID
	 * \param	sidDescribe	ָ�����ο�������SID
	 * \param	belongTo	ָ�����ο���������
	 * \param	roadNode	ָ�����ο��ĵ�·�ڵ�
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
	 * \brief	�������캯��
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
	 * \brief	������ֵ�����
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
	 * \brief	��ȡ��������
	 *
	 */
	CardBase::CardType getCardType()const override
	{
		return cardType;
	}

	/*!
	 * \fn	bool CardRoad::isRoadNode(int x, int y)const
	 *
	 * \brief	��ȡָ��������ָ������ڵ��Ƿ�Ϊ��·
	 *
	 * \param	x	ָ��������
	 * \param	y	ָ��������
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
