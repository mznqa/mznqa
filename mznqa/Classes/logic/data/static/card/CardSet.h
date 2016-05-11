/*!
 * \file	Classes\logic\data\static\card\CardSet.h
 *
 * \brief	������ CardSet
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
 * \brief	[����]������п���
 *
 */
class CardSet
{
private:

	/*!
	 * \fn	CardSet::CardSet()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	CardSet()
	{
	}

	/*!
	 * \fn	CardSet::CardSet(const CardSet &cardSet);
	 *
	 * \brief	���صĿ������캯��
	 *
	 */
	CardSet(const CardSet &cardSet);

	/*!
	 * \fn	CardSet& CardSet::operator=(const CardSet &cardSet);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	CardSet& operator=(const CardSet &cardSet);

	/*! \brief	���ο����� */
	std::map<int, CardRoad> cardRoadSet;
public:

	/*!
	 * \fn	CardSet::~CardSet()
	 *
	 * \brief	��������
	 *
	 */
	~CardSet()
	{
	}

	/*!
	 * \fn	static CardSet* CardSet::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 */
	static CardSet* Instance();

	/*!
	 * \fn	void CardSet::loadCardRoadSet(const std::vector<CardRoad> &cardRoadSet);
	 *
	 * \brief	������ο���������
	 *
	 * \param	cardRoadSet	ָ�����ο��������ݻ���
	 */
	void loadCardRoadSet(const std::vector<CardRoad> &cardRoadSet);

	/*!
	 * \fn	const CardRoad *const CardSet::getCardRoadByID(int id)const;
	 *
	 * \brief	���ݸ���ID�Ի�ȡ���ο�
	 *
	 * \param	id	ָ�����ο�ID
	 *
	 */
	const CardRoad *const getCardRoadByID(int id)const;
};

#endif
